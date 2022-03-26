#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Lembrete: passar struct como ponteiro por referencia - (25/03)APRENDER URGENTE!! - APRENDIDO(26/03)
//struct com os dados
typedef struct{
	float nota1, nota2, nota3;
}Notas;

typedef struct{
	int mat;
	char nome[20];
	//float nota1, nota2, nota3;
	Notas notas;
}Cadastro;

/*
	-sem ponteiro-
	Cadastro pessoa[50];
	int numero_cadastro;
*/

//funcoes do programa
int cadastrar_aluno(Cadastro *ppessoa);
void exibir_aluno(Cadastro *ppessoa);
void alterar_aluno(Cadastro *ppessoa);
void excluir_aluno(Cadastro *ppessoa);

int main(){

  Cadastro pessoa[2];//chamada da struct em vetor
  Cadastro *ppessoa;//struct como ponteiro
  int op;

  ppessoa = pessoa;//apontando para o endereço de memoria da struct vetor principal

  //menu do programa
  do{
    	printf("Digite uma opcao:\n");
    	printf("\t[1]-Cadastrar\n");
		  printf("\t[2]-Exibir:\n");
		  printf("\t[3]-Alterar:\n");
		  printf("\t[4]-Excluir:\n");
		  printf("\t[5]-Sair:\n");
    	scanf("%d", &op);//le a opcao desejada

		  system("cls");
		
    	//chamada das funcoes
    	switch(op){
      		case 1:
        		cadastrar_aluno(pessoa);
      		break;
      		case 2:
        		exibir_aluno(pessoa);
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
	
	return 0;
}

//funcao para cadastrar
int cadastrar_aluno(Cadastro *ppessoa){

  	for(int i=0; i<2; i++){
 		  printf("Digite sua matricula:\n");
		  scanf("%d", &ppessoa->mat);
	
		  printf("Digite seu nome:\n");
		  scanf("%s", ppessoa->nome);
	
		  printf("Digite a primeira nota:\n");
		  scanf("%f", &ppessoa->notas.nota1);
	
		  printf("Digite a segunda nota:\n");
		  scanf("%f", &ppessoa->notas.nota2);
	
		  printf("Digite a primeira nota:\n");
		  scanf("%f", &ppessoa->notas.nota3);
  	}
  	
  	system("cls");
}

//funcao para exibir
void exibir_aluno(Cadastro *ppessoa){

  printf("----Dados dos alunos:----\n");
  for(int i=0; i<2; i++){
   	printf("\n");
	  printf("\tMatricula: %d\n", ppessoa->mat);
	  printf("\tNome: %s\n", ppessoa->nome);
	  printf("\tPrimeira nota: %.1f\n", ppessoa->notas.nota1);
  	printf("\tSegunda nota: %.1f\n", ppessoa->notas.nota2);
	  printf("\tTerceira nota: %.1f\n", ppessoa->notas.nota3);
  }
  
}

//funcao para alterar
void alterar_aluno(Cadastro *ppessoa){
	
	char altera[20];
	
	printf("Digite o nome do aluno para editar:\n");
	scanf("%s", altera);
	
	for(int i=0;i<2;i++){
		if(strcmp(ppessoa->nome,altera)==0){
			printf("Digite sua matricula:\n");
			scanf("%d", &ppessoa->mat);
	
			printf("Digite seu nome:\n");
			scanf("%s", ppessoa->nome);
	
			printf("Digite a primeira nota:\n");
			scanf("%f", &ppessoa->notas.nota1);
	
			printf("Digite a segunda nota:\n");
			scanf("%f", &ppessoa->notas.nota2);
	
			printf("Digite a primeira nota:\n");
			scanf("%f", &ppessoa->notas.nota3);
		}
	}
	
}

//funcao para excluir
void excluir_aluno(Cadastro *ppessoa){
	
  char nome_aluno[20];//variavel para escolher o aluno a ser exclcuido

  printf("Digite o nome do aluno para excluir:\n");
  scanf("%s", nome_aluno);//pegando o nome do aluno

  for(int i=0; i<=2; i++){
  	/*
    	se o strcmp retornar 0 é por que as strings são iguais,
    	assim se a condição for verdadeira 
		entra na estrutura if e faz a excluão
    */
    if(strcmp(ppessoa->nome,nome_aluno)==0){//funcao para comparar as strings
        ppessoa[i] = ppessoa[i-2];//exclusao
      }
  }
  
 }
