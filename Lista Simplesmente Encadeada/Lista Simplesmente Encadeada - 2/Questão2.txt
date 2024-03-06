#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista* proximo;
}TLista;

typedef struct{
    TLista* lista;
}Controle;

Controle constroi(int maximoPosicoesAlocadas, int* array){
    Controle inicio = {};
    TLista* listaAtual = NULL;
    if(array != NULL){
        for(int i = 0; i<maximoPosicoesAlocadas; i++){
            TLista* lista = calloc(1,sizeof(lista));
            if(inicio.lista == NULL){
                lista->info = array[i];
                lista->proximo = NULL;
                inicio.lista = lista;
                listaAtual = inicio.lista;
            }else{
                lista->info = array[i];
                lista->proximo = NULL;
                listaAtual->proximo = lista;
                listaAtual = listaAtual->proximo;
            }
        }
        return inicio;
    }else{
        printf("Sem valores adequados para inserir na memória");
    }
}

int igual(Controle lista1, Controle lista2) {
    TLista* ponteiroLista1 = lista1.lista;
    TLista* ponteiroLista2 = lista2.lista;

    while (ponteiroLista1 != NULL && ponteiroLista2 != NULL) {
        if (ponteiroLista1->info == ponteiroLista2->info) {
            ponteiroLista1 = ponteiroLista1->proximo;
            ponteiroLista2 = ponteiroLista2->proximo;
        }else{
            return 0;
        }
    }
    if (ponteiroLista1 == NULL && ponteiroLista2 == NULL) {
        return 1;
    } else {
        return 0;
    }
}

Controle inverte (Controle* comeco){
    Controle invertido = {};
    TLista* listaInvertidaMemoria = malloc(sizeof(listaInvertidaMemoria));
    listaInvertidaMemoria = NULL;
    TLista* listaAtual = comeco->lista;
    TLista*listaAnterior = comeco->lista;
    TLista* listaAtualInvertida;
    TLista* listaArmazena = malloc(sizeof(listaArmazena));
    listaArmazena->proximo = NULL;


    if(comeco->lista != NULL){
        for(int i=0; i<2;i++){
            if(listaInvertidaMemoria == NULL){
                while(1){
                    if(listaAtual->proximo!=NULL){
                        listaAtual = listaAtual->proximo;
                    }else{
                        listaArmazena->info = listaAtual->info;
                        listaInvertidaMemoria = listaArmazena;
                        listaAtual = comeco->lista;
                        break;
                    }
                }
            }else{
                listaAtualInvertida = listaInvertidaMemoria;
                while(1){
                    TLista* listaArmazena = malloc(sizeof(listaArmazena));
                    listaArmazena == NULL;
                    if(listaInvertidaMemoria->proximo == NULL){
                        if(listaAtual->proximo!= NULL){
                            listaAtual = listaAtual->proximo;
                            if(listaAtual->proximo!= NULL){
                                listaAnterior = listaAnterior->proximo;
                            }
                        }else{
                            listaArmazena->info = listaAnterior->info;
                            listaInvertidaMemoria->proximo = listaArmazena;
                            listaAtualInvertida = listaAtualInvertida->proximo;
                            listaAtual = comeco->lista;
                        }
                    }else{

                        if(listaAtual->proximo!= listaAnterior){
                            if(listaAtual == NULL){
                                listaAtual = comeco->lista;
                            }else{
                                listaAtual = listaAtual->proximo;
                            }
                        }else{

                            listaArmazena->info = listaAtual->info;
                            listaAtualInvertida->proximo = listaArmazena;
                            listaAtualInvertida = listaAtualInvertida->proximo;
                            listaAnterior = listaAtual;
                            listaAtual = comeco->lista;
                            if(listaAtual == listaAnterior){
                                listaAtualInvertida->proximo = NULL;
                                break;
                            }
                        }
                    }
                }
            }
        }
        invertido.lista = listaInvertidaMemoria;
        return invertido;
        }else{
        printf("Lista Vazia, sem elementos para inversão");
    }
}

void imprimir( int maximoPosicoesAlocadas,Controle* inicio){
    TLista* listaAtual = inicio->lista;
    for(int i = 0; i<maximoPosicoesAlocadas; i++){
        if(listaAtual != NULL){
            printf("----------------------------------\n\t");
            printf("Informação: %d \n", listaAtual->info);
            listaAtual= listaAtual->proximo;
            }else{
                break;
        }
    }
}

int main(){
    Controle l1 = {};
    Controle l11 = {};
    Controle l2 = {};
    Controle l3 = {};

    int array[10]={10,2,3,4,7,6,7,8,9,1};
    l1 = constroi(10,array);
    int arraay[10]={10,2,3,4,7,6,7,8,9,1};
    l11 = constroi(10,arraay);
    int array1[5]={2,3,2,4,2};
    l2 = constroi(5,array1);

    printf("\nComparação igual a %d:\n\n", igual(l1,l11));


    imprimir(10,&l1);
    l3 = inverte(&l1);
    printf("\n\n==========================================\n\n\n");
    printf("TÁ INVERTENDO");
    imprimir(10,&l3);
    printf("\n\n==========================================\n\n\n");
    imprimir(5,&l2);
    printf("\n\n==========================================\n\n\n");
    imprimir(5,&l3);

}