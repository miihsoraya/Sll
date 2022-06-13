#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Conta.h"
#include "Lista.h"
#include <locale.h>

int main()
{
    qsll *lista=NULL;
    conta *c1;
    void* search;
    char *r, *nome;
    float preco;
    int codigo, stat=FALSE, find, stts =FALSE;

    do{
        //GetElem();
        r = cMenu();
        if(NotNumeric(r)!= TRUE && (atoi(r))>=0 && (atoi(r))<7){ ///se for um numero aceitavel
            ///come�a programa
            if(*r == '0'){
                exit(0);
            }
            else if(*r == '1'){
                    if(stts!= TRUE){
                        lista=sllCreate(); //list created
                        if(lista!= NULL){
                            printf("Registro criado\n\n");
                            stts = TRUE;
                        }else{
                            printf("ERRO666: REGISTRO NAO CRIADO");
                        }
                    }else{
                        printf("Registro ja criado! Adicione produtos!\n");
                    }
                    getch();
            }
            else if(*r == '2'){
                    if(lista!= NULL){
                        nome=(char*)malloc(sizeof(char)*100);

                        printf("Digite o codigo do produto: \n");
                        scanf("%d", &codigo);
                        printf("Digite o nome do produto: \n");
                        scanf("%s", nome);
                        printf("Digite o valor do produto: (somente numeros)\n");
                        scanf("%f", &preco);


                        c1=RecElem(nome, codigo, preco);
                        stat=sllInsertFirst(lista,(void*)c1);

                    }else{
                        printf("ERRO666: CONTA NAO CRIADA\n");
                    }
                    if(stat){
                            printf("Produto adicionado!\n");
                    }else{
                            printf("Produto NAO adicionado!\n");
                    }
                    getch();
            }
            else if(*r == '3'){
                    if(sllDestroy(lista)!=FALSE){
                        printf("Registro DESTRUIDO!!!\n");
                    }else{
                        printf("ERRO666: CONTA NAO DESTRUIDA\n"); ///tenta destruir com nada dentro
                    }
                    getch();
            }

            else if(*r == '4'){
                if(lista!= NULL){
                    if(stat){
                        printf("Consultar por:\n 1-codigo\n 2-Nome do produto\n 3-Valor do produto\n");
                        scanf("%d", &find);
                        if(find==1){
                            printf("Digite o codigo\n");
                            scanf("%d", &codigo);
                            search = sllQuery(lista, (void*)codigo, CompCOD);
                            Achou(search); // msg de registro encontrado

                        }
                        else if(find==2){
                            printf("Digite o nome do produto\n");
                            scanf("%s", nome);
                            search = sllQuery(lista, (void*)nome, CompNome);
                            Achou(search);

                        }
                        else if(find==3){
                            //float *p = malloc(sizeof *p);
                            printf("Digite o valor do produto\n");
                            scanf("%f", &preco);
                            search = sllQuery(lista, (void*)&preco, CompValor);
                            Achou(search);

                        }else{
                            printf("Opcao invalida!");
                        }
                    }else{
                        printf("Lista vazia\n");
                    }
                }else{
                    printf("Lista NAO alocada\n");
                }

                getch();
            }
            else if(*r == '5'){ ///FALTA ISSO
                if(lista!= NULL){
                    if(stat){
                        printf("Consultar por:\n 1-codigo\n 2-Nome do produto\n 3-Valor do produto\n");
                        scanf("%d", &find);
                        if(find==1){
                            printf("Digite o codigo do produto que deseja remover\n");
                            scanf("%d", &codigo);
                            search = sllRemoveSpec(lista, (void*)codigo, CompCOD);
                            Achou(search);
                        }else if(find==2){
                            printf("Digite o nome do produto que deseja remover\n");
                            scanf("%s", nome);
                            search = sllRemoveSpec(lista, (void*)nome, CompNome);
                            Achou(search);
                        }else if(find==3){
                            printf("Digite o valor do produto que deseja remover\n");
                            scanf("%f", &preco);
                            search = sllRemoveSpec(lista, (void*)&preco, CompValor);
                            Achou(search);
                        }else{
                            printf("Lista vazia \n");
                        }
                    }else{
                        printf("Lista NAO alocada\n");
                    }
                }
                getch();
            }
            else if(*r == '6'){
                if(lista != NULL){
                    sllPrint(lista);

                }else{
                    printf("Registro nao existe\n");
                }
                getch();
            }
        }

    }while(atoi(r)!=0);
	//scanf("%s*c",c1->cliente);

    return 0;
}
