#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define TAM 30
#define TAM2 7

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
	//int codigocarro;
	char placa[TAM2];
	struct pilhacarro *prox;
	//struct pilhacarro *topo;
}carro;

typedef struct listamodelo {
	char nome[TAM];
	int codigomodelo;
	struct listamodelo *prox;
	cliente *cabeca;
	carro *topo;
}modelo;

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
	printf("10 - Alterar modelo.\n");
	printf("11 - Alterar automovel.\n");
	printf("12 - Alterar cliente.\n");
	printf("13 - Fazer busca.\n");
	printf("0 - Sair.\n");
	printf("\n=================================================================\n");
}

void menuautomovel () {
	
}
//interfaces

//funcoes
//lista---------------------------------------------------
int listavazia(modelo *p) {
	
	if(p->codigomodelo==0) {
		return 1;
	}
	else {
		return 0;
	}
}

void listamodelo(modelo *p) {
	modelo *q;
	
	q=p;
	
	printf("\n=================================================================\n");
	printf("\nLista de Modelos: \n");
	printf("\n=================================================================\n");
	
	if(listavazia(q)) {
		printf("\nA lista esta vazia!\n");
	}
	else{
		while(q->prox!=NULL ) {
		printf("%i - %s\n",q->codigomodelo,q->nome);
		
		q=q->prox;
		}
		printf("%i - %s\n",q->codigomodelo,q->nome);
	}
	
	printf("\n=================================================================\n\n");
}

modelo *criamodelo(modelo *p, modelo *u) {
	modelo *q, *nova;
	int x;
	
	q=p;
	
	if(listavazia(q)) {
		fflush(stdin);
		printf("Digite o nome do modelo: ");
		gets(q->nome);
		q->codigomodelo=1;
		q->cabeca=NULL;
		q->topo=NULL;
		
		return q;
	}
	else {
		nova=(modelo*)malloc(sizeof(modelo));
		
		x=u->codigomodelo;
		fflush(stdin);
		printf("Digite o nome do modelo: ");
		gets(nova->nome);
		
		nova->codigomodelo=x+1;
		u->prox=nova;
		nova->prox=NULL;
		nova->cabeca=NULL;
		nova->topo=NULL;
		
		return nova;
	}	
}

void alteramodelo(modelo *p, int codigo) {
	modelo *q;
	int flag=0;
	
	q=p;
	
	if(listavazia(q)) {
		exit(0);
	}
	else {
		for(q;q->prox!=NULL;q=q->prox) {
			if(q->codigomodelo==codigo) {
				fflush(stdin);
				printf("\nDigite o novo nome do modelo: \n");
				gets(q->nome);
				flag++;
			}
		}
		if(flag==0){
			printf("\nNumero invalido!\n\n");
			system("pause");
		}
	}
}

void excluimodelo(modelo *p, int codigo){
	//verificar se a funcao excluir e necessaria, pois ela exige medidas de garantia de integridade de dados.	
}

modelo *buscamod(modelo *p) {
	modelo *aux;
	int x, flag=0;
	
	aux=p;
	
	printf("Escolha o modelo: ");
	scanf("%i",&x);
	
	while(aux != NULL && aux->codigomodelo != x) {
		aux = aux->prox;
	}
	if(aux->codigomodelo != x){
		printf("\n\nOpcao invalida!\n\n");
		return NULL;
	}
		
	return aux;
}
//lista----------------------------------------------------------------------------------------
//pilha----------------------------------------------------------------------------------------------------
int pilhavazia(modelo *p) {
	
	if(p->topo==NULL) {
		return 1;
	}
	else {
		return 0;
	}
}


void criacarro(modelo *mod) {
	modelo *q;
	carro *nova=(carro*)malloc(sizeof(carro));
	int x;
	
	q=mod;
	
	fflush(stdin);
	printf("Digite a placa: ");
	gets(nova->placa);
	
	nova->prox = q->topo->prox;
	mod->topo=nova;
	
}

void listacarro(carro *tp) {
	
	
	if(tp) {
		printf("\t%s\n",tp->placa);
		listacarro(tp->prox);
	}
}
//pilha-----------------------------------------------------------------------------------------


//funcoes

int main(){
	int Op=0, codigo;
	
	ponteiros *i=(ponteiros*)malloc(sizeof(ponteiros));//fila de clientes
	modelo *aux, *f, *p=(modelo*)malloc(sizeof(modelo));//lista de modelos
	carro *auxc, *c=(carro*)malloc(sizeof(carro));//pilha de carros
	
	//fila de clientes
	i->p=NULL;
	i->u=NULL;
	
	//lista de modelos
	p->prox=NULL;
	p->codigomodelo=0;
	f=p;
	
	//pilha de carros 
	//c->codigomodelo=0;
	c->prox=NULL;
	
	printf("\n=================================================================\n");
	printf("\nTRABALHO DE 2 VA\n");
	printf("\nALUNOS: \n");
	printf("LORENA BRAGA FEREIRA\n");
	printf("THIAGO\n");
	printf("STEPHANIE CHRISTINE MATEUS DA SILVA\n");
	printf("\n=================================================================\n");
	
	do {
		menuinicial();
		scanf("%i",&Op);
		system("cls");
		
		switch(Op) {
			case 1:
				f=criamodelo(p,f);
				system("pause");
				system("cls");
				break;
			case 2:
				printf("Escolha o modelo do carro: ");
				listamodelo(p);
				aux=buscamod(p);
				criacarro(aux);
				system("pause");
				system("cls");
				break;
			case 3:
				break;
			case 4:
				/*listamodelo(p);
				if(listavazia(p)) {
					system("pause");
					system("cls");
					break;
				}
				else {
					scanf("%i",&codigo);
					excluimodelo(p,codigo);	
				}
				system("pause");
				system("cls");*/
				break;
			case 5:
				printf("Escolha o modelo do carro: ");
				listamodelo(p);
				aux=buscamod(p);
				auxc=aux->topo->topo;
				listacarro(auxc);
				system("pause");
				system("cls");
				break;
			case 6:
				break;
			case 7:
				listamodelo(p);
				system("pause");
				system("cls");
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				printf("Escolha o modelo que deseja alterar:\n");
				listamodelo(p);
				if(listavazia(p)) {
					system("pause");
					system("cls");
					break;
				}
				else {
					scanf("%i",&codigo);
					alteramodelo(p,codigo);	
				}
				system("pause");
				system("cls");
				break;
			case 11:
				break;
			case 12:
				break;
			case 13:
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
