#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Conta.h"
#include "Lista.h"

#include <math.h>
struct qsll{ no *first; no *cur;};
struct no{void *data; no *next;};

 ///aleatorio

struct conta{
    char *produto;
    int cod;
    float valor; ///corrente... 001 poupan�a... 013
};

///--------------------- compara�o ------------------
int CompCOD(void* a, void* b){
	int pa;
	conta* pb= (conta *) b;
	pa = (int)a;

	if(pa == pb->cod){
		return TRUE;
	}
	return FALSE;
}
int CompValor(void* a, void* b){ ///FALTA ISSO
    float pa;
    conta* pb = (conta *)b;


    pa =*(float*)a; ///convertendo o tipo
    if(fabsf(pa - pb->valor) < 1e-30){ ///comparando com epsilon
        return TRUE;
    }
    return FALSE;
}
int CompNome(void* a, void* b){
    char *pa = (char *)malloc(sizeof(char*)*100);
	conta* pb= (conta *) b;
	pa = (char *)a;

	if(strcmp(pa, pb->produto)==0){
		return TRUE;
	}
	return FALSE;
}
int NotNumeric(char *opc) //FUN�O Q FAZ A VERIFICA�O
{
    for(int i=0;i<strlen(opc);i++){
        if (!isdigit(opc[i])){
            return TRUE;
        }
    }
return FALSE;

}
/// ------------------ imprimindo e recebendo ----------------------

char *cMenu(){
    char *opc;
    opc=(char*)malloc(sizeof(char));
    system("cls");
    printf("[1]Criar Registro de produtos\n");
    printf("[2]Cadastrar Produto\n");
    printf("[3]Destruir Registro de produtos\n");
    printf("[4]Consultar Registro\n"); ///editar?
    printf("[5]Remover um tipo de produto\n");
    printf("[6]Listar todas os produtos \n\n");
    printf("**\t**\t**\t**\t[0]SAIR?\n");
    printf("\nDigite opcao -->  ");
    scanf("%s",opc);
    printf("\n");
    return opc;
}

conta *RecElem(char* prod, int codigo, float preco){
    conta *c1;
    ///conta- aleatoria

    c1=(conta*)malloc(sizeof(conta));

    c1->produto=prod;
    c1->cod=codigo;
    c1->valor=preco;
    return c1;
}

void sllPrint(qsll *l){
  no *aux;
  if(l!= NULL){
      if(l->first!= NULL){
          aux = l->first;
          Print((conta*)aux->data);
          while(aux->next != NULL){
            aux = aux->next;
            Print((conta *)aux->data);
          }
      }else{
          printf("A lista est� vazia ! \n\n\n");
      }
  }else{
    printf("ERRO! LISTA N�O ALOCADA !!! \n\n\n");
  }
}

void Print(conta* c){
  if(c != NULL){
    printf("======================================================\n");
    printf("CODIGO: %d\n", c->cod);
    printf("NOME: %s\n", c->produto);
    printf("VALOR: %.2f\n",c->valor);
    printf("======================================================\n");
  }
}

/// ------------------------- Busca -----------------------------------
void Achou( void* procura){
    conta* result;
    if(procura != NULL){ // se foi encontrado
           printf("\n\nProduto encontrado:\n\n");
           result = (conta*)procura; // result recebe o elemento encontrado
           printf("Dados:\n");
           printf("Nome: %s \n", result->produto);
           printf("Codigo: %d \n", result->cod);
           printf("Valor: R$ %.2f \n\n\n", result->valor);
    }else{
           printf("ERRO! PRODUTO NAO FOI ENCONTRADO! \n\n\n"); // caso pessoa nao esteja na lista
    }
}

/// � limpeza �


