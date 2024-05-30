#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define limit 100 + 2 //Limitando o número de caracteres para 100, o +2 é referente ao \n e \0.

struct batalhaIniciativa{
    char nome[limit];
    int iniciativa;
};

void imprimirPersonagem(struct batalhaIniciativa *jogadores, int numJogadores){
    for(int i = 0; i < numJogadores; i++){
        printf("%d. %s: %d\n", i+1, jogadores[i].nome, jogadores[i].iniciativa);
    }
}

void removeEnter(char *word){ //Pede que o usuário insira uma string, remove o enter (a.k.a. \n) e salva.
    fgets(word, limit, stdin);
    word[strlen(word) - 1] = '\0';
}

void bubbleSort(struct batalhaIniciativa *listaBatalha, int qntPersonagem){

    struct batalhaIniciativa aux;
    int ordenado;

    do{
        ordenado = 1; //A flag 'ordenado' começa com verdadeiro.
        for(int i = 0; i < qntPersonagem - 1; i++){
            if(listaBatalha[i].iniciativa < listaBatalha[i+1].iniciativa){
                aux = listaBatalha[i];
                listaBatalha[i] = listaBatalha[i+1];
                listaBatalha[i+1] = aux;
                ordenado = 0; //A flag indica que houve troca, logo, ainda não está ordenado.
            }
        }
    }while(ordenado == 0);
}

int main(){

    int qntPersonagem;

    printf("Insira a quantidade de envolvidos no combate: ");
    scanf("%d", &qntPersonagem);
    getchar();

    struct batalhaIniciativa listaBatalha[qntPersonagem];

    for(int i = 0; i < qntPersonagem; i++){

        printf("%d. Nome: ", i+1);
        removeEnter(listaBatalha[i].nome);

        printf("Iniciativa de %s: ", listaBatalha[i].nome);
        scanf("%d", &listaBatalha[i].iniciativa);
        getchar();
        printf("\n");

    }

    //Ordenando as iniciativas em ordem decrescente
    bubbleSort(listaBatalha, qntPersonagem);

    system("CLS");

    //Imprimindo a lista ordenada
    printf("ORDEM DE INICIATIVA:\n\n");
    imprimirPersonagem(listaBatalha, qntPersonagem);

return 0;
}