#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	char nome[15];
    int numeroId;
	struct no *prox;
}NO;

typedef struct fila{
    NO *inicio;
    NO *fim;
}TFila;

TFila* inicializa(TFila *f);
void insere(TFila *f, int numeroId, char* nome);
int retira(TFila *f);
int vazia(TFila *f);
void libera(TFila *f);



TFila *inicializa(TFila *f){
    f = (TFila*) malloc(sizeof(TFila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void insere(TFila *f, int numeroId, char* nome){
    NO *novo = (NO*) malloc(sizeof(NO));
    
    novo->numeroId = numeroId;
    strncpy(novo->nome, nome,sizeof(novo->nome));

    novo->prox = NULL;

    if(vazia(f)){
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }

    f->fim = novo;
}

int retira(TFila *f){
    if(vazia(f)){
        return -1;
    }

    NO *aux = NULL;
    if(f->inicio == f->fim){
        aux = f->inicio;
        f->inicio = NULL;
        f->fim = NULL;
    } else {
        aux = f->inicio;
        f->inicio = f->inicio->prox;
    }

    int numeroId = aux->numeroId;   
    char nome[15];
    strncpy(nome, aux->nome,sizeof(nome));
    free(aux);
    return numeroId;
}

int vazia(TFila *f){
    if(f->inicio == NULL && f->fim == NULL){
        return 1;
    } else {
        return 0;
    }
}

void libera(TFila *f) {
    while (!vazia(f)) {
        retira(f);
    }
    free(f);
}

#endif