#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char bairro[20];
	int num;
	char rua[20];
}Endereco;

typedef struct{
	char nome[20];
	char telefone[10];
	Endereco casa;
}Pessoa;

int main(){

	Pessoa dados[5];
	char aux[80];//para auxiliar na ordenação
	int ordem;//variavel para definir a comparação
	
	for(int i=0; i<5; i++){
		printf("Digite seu nome:\n");
		scanf("%s", dados[i].nome);
		
		printf("Digite o numero da sua casa:\n");
		scanf("%d", &dados[i].casa.num);
		
		printf("Digite a sua rua:\n");
		scanf("%s", dados[i].casa.rua);
		
		printf("Digite seu bairro:\n");
		scanf("%s", dados[i].casa.bairro);
		
		printf("Digite seu telefone:\n");
		scanf("%s", dados[i].telefone);
	}
	
  //ordenando as palavras
	for(int i=0; i<5; i++){
		for(int j=i+1; j<5; j++){//for para a "segunda" palavra
			ordem = strcmp(dados[i].nome, dados[j].nome);//comparando as duas strings
			if(ordem > 0){
				strcpy(aux, dados[i].nome);//função para copiar as strings
				strcpy(dados[i].nome, dados[j].nome);
				strcpy(dados[j].nome, aux);
			}
		}
	}
	printf("Em ordem alfabetica:\n");
	for(int i=0; i<5; i++){
		printf("\tNome: %s\n", dados[i].nome);
		printf("\tEndereço -- Numero: %d, Rua: %s, Bairro: %s\n", dados[i].casa.num, dados[i].casa.rua, dados[i].casa.bairro);
		printf("\tTelefone: %s\n", dados[i].telefone);
	}
		
	return 0;
}
