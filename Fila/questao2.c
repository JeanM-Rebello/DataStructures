#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void adicionarAviaoListaEspera(TFila* inicio, int numeroId, char* nome){
    insere(inicio, numeroId, nome);
}

void removerAviaoListaEspera(TFila* inicio){
    retira(inicio);
}

void numerarAvioesEsperandoDecolagem(TFila* inicio){
    NO* comeco = inicio->inicio;
    int contador = 0;
    while(1){
        if(comeco != NULL){
            contador++;
            comeco = comeco->prox;
        }else{
            
            printf("O numero de aviões aguardadando a decolagem é: ");
            printf("%d\n\n\n\n",contador);
            break;
        }
    }
}

void listarAvioesEsperandoDecolagem(TFila* inicio){
    NO* comeco = inicio->inicio;
    printf(" A Lista de Aviões Aguardando a Decolagem é: \n");
    while(1){
        if(comeco != NULL){
            printf("----------------------------------\n\t");
            printf("Nome: %s\n\t", comeco->nome);
            printf("ID: %d\n", comeco->numeroId);
            comeco = comeco->prox;
        }else{
            printf("----------------------------------\n\n\n\n");
            break;
        }
    }
}


void listarPrimeiroAviaoEsperandoDecolagem(TFila* inicio){
    NO* comeco = inicio->inicio;
    printf(" O primeiro avião na lista de decolagem: \n");
    if(comeco != NULL){
        printf("----------------------------------\n\t");
        printf("Nome: %s\n\t", comeco->nome);
        printf("ID: %d\n", comeco->numeroId);
        comeco = comeco->prox;
        printf("----------------------------------\n\n\n\n");
    }
}



int main(){

    TFila* ListaPrincipal = inicializa(NULL);

    adicionarAviaoListaEspera(ListaPrincipal, 1, "Avuao");
    adicionarAviaoListaEspera(ListaPrincipal, 2, "Caça");
    adicionarAviaoListaEspera(ListaPrincipal, 3, "Avião");
    adicionarAviaoListaEspera(ListaPrincipal, 4, "Bimotor");
    adicionarAviaoListaEspera(ListaPrincipal, 5, "Bicicleta com Asa");

    numerarAvioesEsperandoDecolagem(ListaPrincipal);
    listarAvioesEsperandoDecolagem(ListaPrincipal);
    listarPrimeiroAviaoEsperandoDecolagem(ListaPrincipal);
    removerAviaoListaEspera(ListaPrincipal);
    listarPrimeiroAviaoEsperandoDecolagem(ListaPrincipal);
    removerAviaoListaEspera(ListaPrincipal);
    listarPrimeiroAviaoEsperandoDecolagem(ListaPrincipal);
    removerAviaoListaEspera(ListaPrincipal);

    return 0;
}