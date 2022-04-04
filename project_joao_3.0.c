#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//struct com os dados
typedef struct{
	float nota1, nota2, nota3;
}Notas;

typedef struct{
	int mat;
	char nome[20];
	Notas notas;
}Cadastro;

//funcoes do programa
void cadastrar_aluno(Cadastro *pessoa);
int exibir_aluno(Cadastro *pessoa, FILE *parq);
void alterar_aluno(Cadastro *pessoa);
void excluir_aluno(Cadastro *pessoa);

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	FILE *parq;//variavel para usar o arquivo
	Cadastro *pessoa;//chamada da struct em vetor
  	//Cadastro *ppessoa;//struct como ponteiro
  	int op;

  	//ppessoa = pessoa;//apontando para o endereço de memoria da struct vetor principal

	//alocando a memoria 
	pessoa = (Cadastro *) malloc(2*(sizeof(Cadastro)));
	
	//abrindo o arquivo
	parq = fopen("Arquivo_Escola.txt","w");
	
	if(parq==NULL){
		printf("Erro na abertura do arquivo!");
		exit(1);
	}
	
	if(pessoa==NULL){
		printf("ERRO na memória!!\n");
		exit(1);
	}

  	//menu do programa
  	do{
    	printf("Digite uma opção:\n");
    	printf("\t[1]-Cadastrar\n");
		printf("\t[2]-Exibir:\n");
		printf("\t[3]-Alterar:\n");
		printf("\t[4]-Excluir:\n");
		printf("\t[5]-Sair:\n");
    	scanf("%d", &op);//lê a opcao desejada
    	setbuf(stdin, NULL);

		system("cls");
		
    	//chamada das funcoes
    	switch(op){
      		case 1:
        		cadastrar_aluno(pessoa);
      		break;
      		case 2:
        		exibir_aluno(pessoa, parq);
      		break;
      		case 3:
      			alterar_aluno(pessoa);
      		break;
      		case 4:
        		excluir_aluno(pessoa);
      		break;
      		case 5:
        		printf("Saindo\n...");
      		break;
    }
    
  	}while(op<=4);
	
	//liberando a memoria
	free(pessoa);
	//fazendo o EOF
	while(1){
		fprintf(parq,"\n");
		if(feof(parq)){
			break;
		}
	}
	fclose(parq);//fechando o arquivo
	
	return 0;
}

//funcao para cadastrar
void cadastrar_aluno(Cadastro *pessoa){

  	for(int i=0; i<2; i++){
 		printf("Digite sua matricula:\n");
		scanf("%d", &pessoa[i].mat);
		setbuf(stdin, NULL);
		
		printf("Digite seu nome:\n");
		scanf(" %[^\n]", pessoa[i].nome);
		setbuf(stdin, NULL);
		
		printf("Digite a primeira nota:\n");
		scanf("%f", &pessoa[i].notas.nota1);
		setbuf(stdin, NULL);
		
		printf("Digite a segunda nota:\n");
		scanf("%f", &pessoa[i].notas.nota2);
		setbuf(stdin, NULL);
		
		printf("Digite a primeira nota:\n");
		scanf("%f", &pessoa[i].notas.nota3);
		setbuf(stdin, NULL);
  	}
  	
  	system("cls");
}

//funcao para exibir e cadastrar no arquivo
int exibir_aluno(Cadastro *pessoa, FILE *parq){

  	printf("----Dados dos alunos:----\n");
  	
  	for(int i=0; i<2; i++){
   		printf("\n");
		printf("\tMatricula: %d\n", pessoa[i].mat);
		printf("\tNome: %s\n", pessoa[i].nome);
		printf("\tPrimeira nota: %.1f\n", pessoa[i].notas.nota1);
  		printf("\tSegunda nota: %.1f\n", pessoa[i].notas.nota2);
		printf("\tTerceira nota: %.1f\n", pessoa[i].notas.nota3);
  }
  
    fprintf(parq,"\t----Dados----\n");
  	for(int i=0; i<2; i++){
  		fprintf(parq,"Matricula: %d\n", pessoa[i].mat);
  		fprintf(parq,"Nome: %s\n", pessoa[i].nome);
  		fprintf(parq,"Nota 1: %.1f\n", pessoa[i].notas.nota1);
  		fprintf(parq,"Nota 2: %.1f\n", pessoa[i].notas.nota2);
  		fprintf(parq,"Nota 3: %.1f\n", pessoa[i].notas.nota3);
  		fprintf(parq,"\n");
	  }
  
}

//funcao para alterar
void alterar_aluno(Cadastro *pessoa){
	
	char altera[20];
	
	printf("Digite o nome do aluno para editar:\n");
	scanf("%s", altera);
	setbuf(stdin, NULL);
	
	for(int i=0;i<2;i++){
		if(strcmp(pessoa->nome,altera)==0){
			printf("Digite sua matricula:\n");
			scanf("%d", &pessoa[i].mat);
			setbuf(stdin, NULL);
		
			printf("Digite seu nome:\n");
			scanf(" %[^\n]", pessoa[i].nome);
			setbuf(stdin, NULL);
		
			printf("Digite a primeira nota:\n");
			scanf("%f", &pessoa[i].notas.nota1);
			setbuf(stdin, NULL);
		
			printf("Digite a segunda nota:\n");
			scanf("%f", &pessoa[i].notas.nota2);
			setbuf(stdin, NULL);
		
			printf("Digite a primeira nota:\n");
			scanf("%f", &pessoa[i].notas.nota3);
			setbuf(stdin, NULL);
		}
	}
	
}

//funcao para excluir
void excluir_aluno(Cadastro *pessoa){
	
  char nome_aluno[20];//variavel para escolher o aluno a ser exclcuido

  printf("Digite o nome do aluno para excluir:\n");
  scanf("%s", nome_aluno);//pegando o nome do aluno
  setbuf(stdin, NULL);
  
  for(int i=0; i<=2; i++){
  	/*
    	se o strcmp retornar 0 é por que as strings são iguais,
    	assim se a condição for verdadeira 
		entra na estrutura if e faz a excluão
    */
    if(strcmp(pessoa[i].nome,nome_aluno)==0){//funcao para comparar as strings
    	pessoa[i].mat = NULL;
    	strcpy(pessoa[i].nome,"0");//funcao para copiar string 
    	pessoa[i].notas.nota1 = NULL;
    	pessoa[i].notas.nota2 = NULL;
    	pessoa[i].notas.nota3 = NULL;
      }
  }
  
 }
