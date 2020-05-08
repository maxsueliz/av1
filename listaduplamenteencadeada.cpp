/**
 * Algoritmo realizado com base no livro:
 *  Estrutura de Dados:
 * Autoras: Ana Fernanda Gomes Ascencio,Graziela Santos de Araujo
 * Editora: Pearson, 2011
 * Autor: Andre Eppinghaus
 * Data Criacao: 13/08/2015
 **/
#include<iostream>
using namespace std;

struct Lista {
	int num;
	Lista *prox, *ant;
	nome e idade
};

// consulta para exibir os nomes com idade entre 15 e 20 anos.

int leiaValor() {
	int valor;
	cout<<"\n Valor:"<<endl;
	cin>>valor;
	return valor;
}
int main() {
		
	Lista *inicio = NULL, *fim=NULL, *aux = NULL;
	int op=0, numero=0, achou = 0;
	
	while(op != 7) {
		cout<<"\n\t 1-Inserir no inicio da lista";
		cout<<"\n\t 2-Inserir no fim da lista";
		cout<<"\n\t 3-Consultar lista do inicio ao fim";
		cout<<"\n\t 4-Consultar lista do fim ao inicio";
		cout<<"\n\t 5-Remover da lista";
		cout<<"\n\t 6-Esvaziar a lista";
		cout<<"\n\t 7-Sair";
		cout<<"\n\t Escolha Opcao:"<<endl;
		cin>>op;
		if (op==1) {
			Lista *novo = new Lista;
			novo->num = leiaValor();
			if (inicio == NULL) {
				inicio = novo;
				fim = novo;
				cout<< "novo"<<novo;
				novo->prox = NULL;
				novo->ant = NULL;
			}else {
				novo->prox = inicio;
				cout<<"+1 prox"<<inicio;
				inicio->ant=novo;
				cout<<"+1 ant"<<inicio;
				novo->ant=NULL;
				inicio=novo;
			}
		}//fim op=1
		if (op==2) {		
			Lista *novo = new Lista;
			novo->num = leiaValor();
			if (inicio == NULL) {
				inicio = novo;
				fim = novo;
				novo->prox = NULL;
				novo->ant = NULL;
			}else {
				fim->prox = novo;
				novo->ant=fim;
				novo->prox=NULL;
				fim=novo;
			}
		}//fim op=2
		
		if(op ==3 ) { //inicio/fim
			if (inicio == NULL) {
				cout<<"\nLista Vazia"<<endl;
			}else {
				aux = inicio;
				while (aux != NULL){
					cout<<"\n\tValor:"<< aux->num <<endl;
					aux=aux->prox;
				}
			}
		}//fim if op=3
		
		if (op==4) {
			if (inicio == NULL) {
				cout<<"\nLista Vazia"<<endl;
			}else {
				aux = fim;//*
				while (aux != NULL){
					cout<<"\n\tValor:"<< aux->num <<endl;
					aux=aux->ant;//*
				}
			}
		}//fim op=4
		if (op==5) {
			if (inicio==NULL) {
				cout<<"\nLista Vazia"<<endl;	
			}else{
				cout<<"\nDigite valor a ser removido"<<endl;
				numero = leiaValor();
				aux=inicio;
				achou=0;
				while (aux != NULL){
					if (aux->num==numero){
						achou++;
						if (aux==inicio) {
							inicio=aux->prox;
							if (inicio != NULL){
								inicio->ant = NULL;
							}
							delete(aux);
							aux=inicio;						
						}else if (aux==fim) {
							fim = fim->ant;
							fim->prox=NULL;
							delete(aux);
							aux=NULL;
						}else {
							aux->ant->prox = aux->prox;
							aux->prox->ant = aux->ant;
							Lista *aux2;
							aux2=aux->prox;
							delete(aux);
							aux = aux2;
						}
					}else {
						aux=aux->prox;
					}
				}//fim while
				
				if (achou==0) {
					cout<<"\nNumero nao encontrado"<<endl;
				}else {
					cout<<"\nNumero removido "<<achou<<" vezes"<<endl;
				}
			}//fim if
		}//fim op=5
		if (op==6) {
			if (inicio == NULL) {
				cout<<"\nLista Vazia"<<endl;
			}else {
				aux = inicio;
				while (aux != NULL){
					inicio=inicio->prox;
					delete(aux);
					aux=inicio;
					
				}
			}
		}
	}//fim while
	
	return 1;
}
