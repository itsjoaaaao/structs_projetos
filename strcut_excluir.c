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
int cadastrar_aluno(struct cadastro pessoa[2]);
void exibir_aluno(struct cadastro pessoa[2]);
void excluir_aluno(struct cadastro pessoa[2]);

int main(){

  //chamada da struct em vetor
  struct cadastro pessoa[2];
  int op;

  //menu do programa
  do{
    	printf("digite uma opcao:\n");
    	printf("[1]-cadastrar\n");
	printf("[2]-exibir:\n");
	printf("[3]-excluir:\n");
    	scanf("%d", &op);//le a opcao desejada

    	//chamada das funcoes
    	switch(op){
      	case 1:
        	cadastrar_aluno(pessoa);
      	break;
      	case 2:
        	exibir_aluno(pessoa);
      	break;
      	case 3:
        	excluir_aluno(pessoa);
      	break;
    }
    
  }while(op<=3);
	
	return 0;
}

//funcao para cadastrar
int cadastrar_aluno(struct cadastro pessoa[2]){

  for(int i=0; i<2; i++){
 	printf("Digite sua matricula:\n");
	scanf("%d", &pessoa[i].mat);
	
	printf("Digite seu nome:\n");
	scanf(" %[^\n]", pessoa[i].nome);
	
	printf("Digite a primeira nota:\n");
	scanf("%f", &pessoa[i].nota1);
	
	printf("Digite a segunda nota:\n");
	scanf("%f", &pessoa[i].nota2);
	
	printf("Digite a primeira nota:\n");
	scanf("%f", &pessoa[i].nota3);
  }
	
}

//funcao para exibir
void exibir_aluno(struct cadastro pessoa[2]){

  printf("----Dados dos alunos:----\n");
  for(int i=0; i<2; i++){
   	printf("\n");
	printf("\tMatricula: %d\n", pessoa[i].mat);
	printf("\tNome: %s\n", pessoa[i].nome);
	printf("\tPrimeira nota: %.1f\n", pessoa[i].nota1);
  	printf("\tSegunda nota: %.1f\n", pessoa[i].nota2);
	printf("\tTerceira nota: %.1f\n", pessoa[i].nota3);
  }
}

//funcao para excluir
void excluir_aluno(struct cadastro pessoa[2]){
  char nome_aluno[20];//variavel para escolher o aluno a ser exclcuido

  printf("Digite o nome do aluno para excluir:\n");
  scanf(" %[^\n]", nome_aluno);//pegando o nome do aluno

  for(int i=0; i<=2; i++){
    if(strcmp(pessoa[i].nome,nome_aluno)==0){//funcao para comparar as strings
        pessoa[i] = pessoa[i-1];//exclusao
      }
  }
 }
