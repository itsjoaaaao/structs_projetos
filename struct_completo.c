#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct com os dados
struct cadastro{
	int mat;
	char nome[20];
	float nota1, nota2, nota3;
};

//funcoes do programa
int cadastrar_aluno(struct cadastro pessoa[3]);
void exibir_aluno(struct cadastro pessoa[3]);
void alterar_aluno(struct cadastro pessoa[3]);
void excluir_aluno(struct cadastro pessoa[3]);

int main(){

  //chamada da struct em vetor
  struct cadastro pessoa[3];
  int op;

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
int cadastrar_aluno(struct cadastro pessoa[3]){

  for(int i=0; i<3; i++){
 	  printf("Digite sua matricula:\n");
	  scanf("%d", &pessoa[i].mat);
	
	  printf("Digite seu nome:\n");
	  scanf("%s", pessoa[i].nome);
	
	  printf("Digite a primeira nota:\n");
	  scanf("%f", &pessoa[i].nota1);
	
	  printf("Digite a segunda nota:\n");
	  scanf("%f", &pessoa[i].nota2);
	
	  printf("Digite a primeira nota:\n");
	  scanf("%f", &pessoa[i].nota3);
  }
  	system("cls");
}

//funcao para exibir
void exibir_aluno(struct cadastro pessoa[3]){

  printf("----Dados dos alunos:----\n");
  for(int i=0; i<3; i++){
   	printf("\n");
	  printf("\tMatricula: %d\n", pessoa[i].mat);
	  printf("\tNome: %s\n", pessoa[i].nome);
	  printf("\tPrimeira nota: %.1f\n", pessoa[i].nota1);
  	printf("\tSegunda nota: %.1f\n", pessoa[i].nota2);
	  printf("\tTerceira nota: %.1f\n", pessoa[i].nota3);
  }
}

//funcao para alterar
void alterar_aluno(struct cadastro pessoa[3]){
	
	char altera[20];
	
	printf("Digite o nome do aluno para editar:\n");
	scanf("%s", altera);
	
	for(int i=0;i<3;i++){
		if(strcmp(pessoa[i].nome,altera)==0){
			printf("Digite sua matricula:\n");
			scanf("%d", &pessoa[i].mat);
	
			printf("Digite seu nome:\n");
			scanf("%s", pessoa[i].nome);
	
			printf("Digite a primeira nota:\n");
			scanf("%f", &pessoa[i].nota1);
	
			printf("Digite a segunda nota:\n");
			scanf("%f", &pessoa[i].nota2);
	
			printf("Digite a primeira nota:\n");
			scanf("%f", &pessoa[i].nota3);
		}
	}
}


//funcao para excluir
void excluir_aluno(struct cadastro pessoa[3]){
	
  char nome_aluno[20];//variavel para escolher o aluno a ser exclcuido

  printf("Digite o nome do aluno para excluir:\n");
  scanf("%s", nome_aluno);//pegando o nome do aluno

  for(int i=0; i<=3; i++){
  	/*
    	se o strcmp retornar 0 é por que as strings são iguais,
    	assim se a condição for verdadeira 
		  entra na estrutura if e faz a excluão
    */
    if(strcmp(pessoa[i].nome,nome_aluno)==0){//funcao para comparar as strings
        pessoa[i] = pessoa[i-3];//exclusao
      }
  }
  
 }
