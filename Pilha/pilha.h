#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int info;
	struct no *prox;
}NO;

typedef struct pilha{
    NO *topo;
}TPilha;


TPilha *inicializa(TPilha *p){
    p = (TPilha*) malloc(sizeof(TPilha));
    p->topo = NULL;
    return p;
}

int vazia(TPilha *p){
    if(p->topo == NULL){
        return 1;
    } else {
        return 0;
    }
}

void push(TPilha *p, int info){
    NO *novo = (NO*) malloc(sizeof(NO));
    novo->info = info;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(TPilha *p){
    if(vazia(p)){
        return -1;
    }

    NO *aux = NULL;
    aux = p->topo;

    p->topo = p->topo->prox;

    int info = aux->info;
    free(aux);
    return info;
}

void libera(TPilha *p){
    while (!vazia(p)){
        pop(p);
    }
}

#endif