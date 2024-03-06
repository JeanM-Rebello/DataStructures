#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void MaiorMenor (TPilha *p){
    NO* pilha = p->topo;
    int maior = 0;
    int menor = INT_MAX;
    int comparador = 0;
    while(1){
        if(pilha->prox != NULL){
            comparador = pilha->info;
            pilha = pilha->prox;
            if(comparador > pilha->info){
                if(comparador>maior){
                    maior = comparador;
                }
                if(menor>pilha->info){
                    menor = pilha->info;
                }
            }
        }else{
            printf("Maior: %d\n", maior);
            printf("Menor: %d\n", menor);
            break;
        }
    }
}

TPilha* ordena(TPilha* f) {
    TPilha* pilhaSecundaria = inicializa(NULL);
    while (f->topo!=NULL) {
        int valorTemporario = f->topo->info;
        pop(f);
        while (pilhaSecundaria->topo != NULL && pilhaSecundaria->topo->info > valorTemporario) {
            push(f, pilhaSecundaria->topo->info);
            pop(pilhaSecundaria);
        }
        push(pilhaSecundaria, valorTemporario);
    }
    return pilhaSecundaria;
}


int main(){
    TPilha* pilhaPrincipal = inicializa(NULL);
    push(pilhaPrincipal, 4);
    push(pilhaPrincipal, 2);
    push(pilhaPrincipal, 30);
    push(pilhaPrincipal, 0.5);
    push(pilhaPrincipal, 5);

    push(pilhaPrincipal, 1);
    push(pilhaPrincipal, 2);
    push(pilhaPrincipal, 300);
    push(pilhaPrincipal, 2);
    push(pilhaPrincipal, 1);

    MaiorMenor(pilhaPrincipal);
    pilhaPrincipal = ordena(pilhaPrincipal);
    MaiorMenor(pilhaPrincipal);

    return 0;
}