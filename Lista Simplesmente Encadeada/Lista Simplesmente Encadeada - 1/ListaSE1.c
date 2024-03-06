#include <stdio.h>
#include <stdlib.h>

typedef struct notas{
    char matricula[15];
    float a1;
    float a2;
    float a3;
    float mediaFinal;
    
    struct notas* proximo;
}Notas;

typedef struct{
    Notas* notas;
}Controle;


float mediaParMaior(float a1, float a2, float a3){
    float media = 0;
    if(a3>a2){ 
        if(a3>a1){ 
            if(a2>a1){
                media = (a3+a2)/2;
            }else{
                media = (a3+a1)/2;
            }
        }else{
            media = (a1+a3)/2;
        }
    }else if(a2>a1){
        if(a1>a3){
            media = (a2+a1)/2;
        }else{
            media = (a2+a3)/2;
        }
    }else{
            media = (a1+a2)/2;
    }
    return media;
}

void inserir(Controle* inicio){
    Notas* alunoP = malloc(sizeof(alunoP));
    alunoP->proximo=NULL;
    Notas* notaAtual;
    Notas* notaAnterior ={};
    
    printf("Por favor insira o a matricula: ");
    scanf("%s",&alunoP->matricula);
    printf("Nota A1: ");
    scanf("%f",&alunoP->a1);
    printf("Nota A2: ");
    scanf("%f",&alunoP->a2);
    printf("Nota A3: ");
    scanf("%f",&alunoP->a3);
    
    alunoP->mediaFinal = mediaParMaior(alunoP->a1,alunoP->a2,alunoP->a3);

    
    if(inicio->notas == NULL){
        inicio->notas = alunoP; 
    }else{
        notaAtual = inicio->notas; 
        while(1){
            if(notaAtual->proximo !=NULL){
                notaAnterior = notaAtual;
                notaAtual = notaAtual->proximo;

                if(notaAnterior->mediaFinal<alunoP->mediaFinal){
                    inicio->notas = alunoP;
                    inicio->notas->proximo= notaAnterior;
                    break;

                }else if(notaAtual->mediaFinal<alunoP->mediaFinal){
                    notaAnterior->proximo = alunoP;
                    notaAnterior = notaAnterior->proximo;
                    notaAnterior->proximo= notaAtual;
                    break;

                }else{
                    notaAnterior = notaAtual;
                    notaAtual->proximo = alunoP;
                    notaAtual = alunoP;
                    break;
                }

            }else{

                if(notaAnterior == NULL){
                    if(notaAtual->mediaFinal<alunoP->mediaFinal){
                        inicio->notas = alunoP;
                        notaAnterior = alunoP;
                        notaAnterior->proximo = notaAtual;
                        break;

                    }else{
                        notaAtual->proximo = alunoP;
                        notaAnterior = notaAtual;
                        notaAtual = notaAtual->proximo;
                        break;
                    }

                }else{
                    notaAtual->proximo = alunoP;
                    break;
                }
            }
        }
    }
}

void imprimiMediaAcimaValor(Controle* inicio){
    Notas* notaAtual;
    notaAtual = inicio->notas;
    float valor;
    printf("Por favor insira o valor desejado para buscas acima desse valor: ");
    scanf("%f",&valor);
    
    if(notaAtual==NULL){
        printf("Nenhum valor armazenado na memória.");
        return;
    }else{
        if(notaAtual->mediaFinal > valor){
            while(1){
                if(notaAtual->mediaFinal > valor){
                    printf("\n-------------------------------\n\n\t");
                    printf("Matricula: %s\n\t",notaAtual->matricula);
                    printf("A1: %.1f\n\t",notaAtual->a1);
                    printf("A2: %.1f\n\t",notaAtual->a2);
                    printf("A3: %.1f\n\t",notaAtual->a3);
                    printf("Media: %.1f\n",notaAtual->mediaFinal);
                    notaAtual = notaAtual->proximo;
                }else{
                    return;
                }
            }
        }else{
            printf("Nenhum valor correspondente ao desejado;");
            return;
        }
    }
}

int main(){
    Controle inicio = {};
    for(int i= 0; i<4;i++){
        inserir(&inicio);
    }
    imprimiMediaAcimaValor(&inicio);
}