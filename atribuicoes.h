#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define maxLimitChar 50 + 2 //Limitando o número de caracteres para 100, o +2 é referente ao \n e \0.

struct batalhaIniciativa{
    char nome[maxLimitChar];
    int iniciativa;
};

void imprimirPersonagem(struct batalhaIniciativa *jogadores, int numJogadores){
    for(int i = 0; i < numJogadores; i++){
        printf("%d. %s: %d\n", i+1, jogadores[i].nome, jogadores[i].iniciativa);
    }
}

void removeEnter(char *word){ //Pede que o usuário insira uma string, remove o enter (a.k.a. \n) e salva.
    fgets(word, maxLimitChar, stdin);
    word[strlen(word) - 1] = '\0';
}

void bubbleSort(struct batalhaIniciativa *listaBatalha, int qntPersonagem){

    struct batalhaIniciativa aux;
    unsigned short int ordenado;

    do{
        ordenado = 1; //A flag 'ordenado' sempre começa como verdadeiro a cada loop.
        for(int i = 0; i < qntPersonagem - 1; i++){
            if(listaBatalha[i].iniciativa < listaBatalha[i+1].iniciativa){
                aux = listaBatalha[i];
                listaBatalha[i] = listaBatalha[i+1];
                listaBatalha[i+1] = aux;
                ordenado = 0; //A flag indica que houve troca, logo, ainda não está ordenado.
            }
        }
    }while(!ordenado);
}