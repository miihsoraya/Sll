#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#define TRUE 1
#define FALSE 0


struct qsll{
    no *first;
    no *cur;
};
struct no{
    void *data;
    no *next;
};

///////////////////////////////////////////////
qsll *sllCreate(){
    qsll *q;
    q=(qsll*)malloc(sizeof(qsll));
    if(q!=NULL){
        q->first=NULL;
        q->cur=NULL;
        return q;
    }
    return NULL;
}
int sllDestroy(qsll *q){
    if(q!=NULL){
        if(q->first==NULL){
            free(q->first);
            free(q);
            return TRUE;
        }
        return FALSE;
    }
}

int sllInsertFirst(qsll *q,void *data){

    no *newnode;
    if(q!=NULL){
        newnode=(no*)malloc(sizeof(no));
        if(newnode!=NULL){
            newnode->data=data;
            //newnode->next=NULL;

            if(q->first == NULL){
				newnode->next=NULL;

			}else{
				//last = q->first;
				newnode->next = q->first;
            }
			q->first = newnode;

            return TRUE;
        }
    }return FALSE;
}
void *sllRemoveSpec(qsll *q, void *key, int (*cmp)(void *a, void *b)){
  no *spec; // item a ser removido
  no *prev; // anterior a ele
  void *data;
  int stat;
  if(q != NULL){
    if(q->first != NULL){
      prev = NULL;
      spec = q->first;
      stat = cmp(key, spec->data);
      while((stat != TRUE) && spec->next != NULL){
        prev = spec;
        spec = spec->next;             // itera a lista até achar
        stat = cmp(key, spec->data);
      }
      if(stat == TRUE){ // se achar
        if(prev == NULL){
          q->first = spec->next;
        }else{
          prev->next = spec->next; // emenda a lista
        }
        data = (void *)spec->data;
        free(spec); // desaloca o elemento removido
        return data;
      }
    }
  }
  return NULL;
}
void *sllQuery(qsll *q,void *key,int(*cmp)(void*,void*)){
    no *aux;
    int stat;
    if(q!=NULL){
        if(q->first!=NULL){
            aux=q->first;

            stat= cmp((void*)key, aux->data);
            while(stat!=TRUE && aux->next!=NULL){
                aux=aux->next;
                stat=cmp((void*)key, aux->data);
            }
            if(stat==TRUE){
                return aux->data;
            }
        }
    }return NULL;
}
/// - Buscar Primeiro da Lista -
void *sllGetFirst(qsll *q){
	if(q != NULL){
		if(q->first != NULL){
			q->cur = q->first->next;
			return q->first->data;
		}
	}
}
/// Buscar o Próximo da Lista
void *sllGetNext(qsll *q){
	no *aux;
	if(q!= NULL){
		if((q->cur) != NULL){
			aux = q->cur;
			q->cur = aux->next;
			return aux->data;
		}
	}
	return NULL;
}

