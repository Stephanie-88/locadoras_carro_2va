#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define TAM 30
#define TAM2 10


typedef struct listamodelo {
	char nome[TAM];
	int codigomodelo;
	struct listamodelo *prox;
}modelo;

typedef struct filacliente {
	char nome[TAM];
	int id;
	struct filacliente *prox;
}cliente;

typedef struct pont{
    cliente* p;
    cliente* u;
}ponteiros;

typedef struct pilhacarro {
	char modelo[TAM];
	int codigomodelo;
	char placa[TAM2];
	struct pilhacarro *prox;
}carro;

//interfaces
void menuinicial() {
	printf("\n=================================================================\n");
	printf("\nEscolha a operacao desejada: \n");
	printf("\n=================================================================\n");
	printf("1 - Cadastrar novo modelo.\n");
	printf("2 - Cadastrar novo automovel.\n");
	printf("3 - Cadastrar novo cliente.\n");
	printf("4 - Excluir modelo.\n");
	printf("5 - Excluir automovel.\n");
	printf("6 - Excuir cliente.\n");
	printf("7 - Listar modelos.\n");
	printf("8 - Listar carros.\n");
	printf("9 - Listar clientes.\n");
	printf("10 - Fazer busca.\n");
	printf("0 - Sair.\n");
	printf("\n=================================================================\n");
}

void menuautomovel () {
	
}
//interfaces

//funções
void listamodelo() {
	
}

modelo *criamodelo(modelo *p, modelo *u) {
	modelo *q, *nova;
	
	q=p;
	
	if(q->codigomodelo==0) {
		fflush(stdin);
		printf("Digite o nome do modelo: ");
		gets(q->nome);
		q->codigomodelo=1;
	}
	else {
		nova=(modelo*)malloc(sizeof(modelo));
		
		u->prox=nova;
		nova->codigomodelo=u->codigomodelo++;
		nova->prox=NULL;
		
		fflush(stdin);
		printf("Digite o nome do modelo: ");
		gets(q->nome);
	}
	
	return nova;
}


//funções

int main(){
	int Op=0, codigo;
	
	ponteiros *i=(ponteiros*)malloc(sizeof(ponteiros));//fila de clientes
	modelo *p, *f=(modelo*)malloc(sizeof(modelo));//lista de modelos
	carro *c=(carro*)malloc(sizeof(carro));//pilha de carros
	
	//fila de clientes
	i->p=NULL;
	i->u=NULL;
	
	//lista de modelos
	f->prox=NULL;
	f->codigomodelo=0;
	p=f;
	
	//pilha de carros
	c->codigomodelo=0;
	c->prox=NULL;
	
	printf("\n=================================================================\n");
	printf("\nTRABALHO DE 2 VA\n");
	printf("\nALUNOS: \n");
	printf("LORENA\n");
	printf("LUCAS\n");
	printf("STEPHANIE CHRISTINE MATEUS DA SILVA\n");
	printf("\n=================================================================\n");
	
	do {
		menuinicial();
		scanf("%i",&Op);
		system("cls");
		
		switch(Op) {
		case 1:
			f=criamodelo(p,f);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("\nOpcao invalida!\n\n");
			system("pause");
			system("cls");
			break;
	}
	}while(Op!=0);
	
	
	return 0;
}
