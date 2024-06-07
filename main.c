#include "atribuicoes.h"

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