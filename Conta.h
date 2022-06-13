#ifndef CONTA_H_INCLUDED
#define CONTA_H_INCLUDED
#define TRUE 1
#define FALSE 0


typedef struct qsll qsll;
typedef struct no no;
typedef struct conta conta;

char *cMenu();
int NotNumeric (char *opc);
//void GetElem();
conta *RecElem(char* prod, int codigo, float preco);
int CompValor(void* a, void* b);
int CompCOD(void* a, void* b);
int CompNome(void* a, void* b);
void sllPrint(qsll *l);
void Print(conta* c);
void Achou( void* procura);

#endif // CONTA_H_INCLUDED
