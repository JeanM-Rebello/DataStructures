#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int informacao;
    struct lista* proximo;
    struct lista* anterior;
}Lista;

typedef struct{
    Lista* lista;
}Controle;

void inserirInicio(Controle* inicio, int* informacao){
    Lista* listaNova = malloc(sizeof(listaNova));
    listaNova->proximo = NULL;
    listaNova->anterior = NULL;
    Lista* listaAtual;

    while(1){
        if(inicio->lista!=NULL){
            listaAtual = inicio->lista;
            inicio->lista = listaNova;
            listaNova->informacao= *informacao;
            listaNova->proximo = listaAtual;
            listaAtual->anterior = listaNova;
            break;
        }else{
            inicio->lista = listaNova;
            listaNova->informacao = *informacao;
            break;
        }
    }
}

void excluirValorEscolido(Controle* inicio, int* informacao){
    Lista* listaAtual;
    Lista* listaResgate = inicio->lista ;
    listaAtual = inicio->lista;
    if(listaAtual != NULL){
        while(1){
            if(listaAtual != NULL){
                    if(listaAtual->anterior != NULL){
                        if(listaAtual->informacao == *informacao){
                            if(listaResgate == listaAtual->anterior){
                                listaAtual = listaAtual->proximo;
                                listaResgate->proximo = listaAtual;
                                listaAtual->anterior = listaResgate;
                                break;
                            }else if(listaAtual->proximo== NULL){
                                if(listaAtual->informacao == *informacao){
                                    while(1){
                                        if(listaResgate->proximo!= listaAtual){
                                            listaResgate = listaResgate->proximo;
                                        }else{
                                            listaResgate->proximo = NULL;
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }else{
                                listaResgate = listaAtual->anterior;
                            }
                        }else{
                            listaAtual = listaAtual->proximo;
                        }
                    }else{
                        if(listaAtual->informacao == *informacao){
                            inicio->lista = listaAtual->proximo;
                            listaAtual->anterior = NULL;
                            break;
                        }
                        listaAtual = listaAtual->proximo;
                    }
            }else{
                break;
            }
        }
    }else{
        printf("Não tem itens para serem excluidos na lista.");
    }
}


void imprimir(Controle* inicio){
    Lista* listaAtual;
    listaAtual = inicio->lista;
    while(1){
        if(listaAtual != NULL){
            printf("\n----------------------------------\n\n\t");
            printf("Informação: %d \n\t", listaAtual->informacao);
            listaAtual = listaAtual->proximo;
        }else{
            printf("\n\n\n");
            break;
        }
    }
}

int main(){
    Controle lista = {};
    int a =1;
    int b =2;
    int c =3;
    int d =3;
    int e =4;

    inserirInicio(&lista,&a);
    inserirInicio(&lista,&b);
    inserirInicio(&lista,&c);
    inserirInicio(&lista,&d);
    inserirInicio(&lista,&e);
    imprimir(&lista);
    excluirValorEscolido(&lista,&b);
    imprimir(&lista);
}