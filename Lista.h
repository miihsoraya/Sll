#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct qsll qsll;
typedef struct no no;

////////////////////////
int sllInsertFirst(qsll *q,void *data);
int sllDestroy(qsll *q);
qsll *sllCreate();
void *sllRemoveSpec(qsll *q, void *key, int (*cmp)(void *a, void *b));
void *sllDequeue(qsll *q);
void *sllQuery(qsll *q,void *key,int(cmp)(void*,void*));

#endif // LISTA_H_INCLUDED
