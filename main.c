#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define maxLimitChar 30 + 2 //Limitando o número de caracteres para 100, o +2 é referente ao \n e \0.

struct personagemIniciativa{
    char nome[maxLimitChar];
    int iniciativa;
};

void printPersonagens(struct personagemIniciativa *jogadores, int numJogadores){
    for(int i = 0; i < numJogadores; i++){
        printf("%d. %s: %d\n", i+1, jogadores[i].nome, jogadores[i].iniciativa);
    }
}

void adjustString(char *word){ //Pede que o usuário insira uma string, remove o enter (a.k.a. \n) e salva.
    fgets(word, maxLimitChar, stdin);
    word[strlen(word) - 1] = '\0';
}

void swap(struct personagemIniciativa *listaBatalha, int x, int y){
    struct personagemIniciativa aux;
    aux = listaBatalha[x];
    listaBatalha[x] = listaBatalha[y];
    listaBatalha[y] = aux;
}

void bubbleSort(struct personagemIniciativa *listaBatalha, int qntPersonagem){
    unsigned short int ordenado;
    do {
        ordenado = 1; //A flag 'ordenado' sempre começa como verdadeiro a cada loop.
        for(int i = 0; i < qntPersonagem - 1; i++){
            if(listaBatalha[i].iniciativa < listaBatalha[i+1].iniciativa){
                swap(listaBatalha, i, i+1);
                ordenado = 0; //A flag indica que houve troca, logo, ainda não está ordenado.
            }
        }
    } while (!ordenado);
}

void atribuicaoPersonagens(struct personagemIniciativa *listaBatalha, int qntPersonagem){
    int iniciativaPersonagem;
    int modificadorIniciativa;
    for (int i = 0; i < qntPersonagem; i++) {

        printf("[%d/%d]. Nome: ", i+1, qntPersonagem);
        adjustString(listaBatalha[i].nome);

        printf("Iniciativa de %s com o MOD aplicado (0 para randomizar): ", listaBatalha[i].nome);
        scanf("%d", &iniciativaPersonagem);
        getchar();

        if (iniciativaPersonagem <= 0) {
            printf("Modificador de iniciativa: ");
            scanf("%d", &modificadorIniciativa);
            getchar();

            //Jogando o 1d20 de iniciativa
            listaBatalha[i].iniciativa = (rand() % 20) + 1;
            printf("Tirou: %d + %d = %d\n", listaBatalha[i].iniciativa, modificadorIniciativa, listaBatalha[i].iniciativa + modificadorIniciativa);

            //Somando o dado com o modificador
            listaBatalha[i].iniciativa += modificadorIniciativa;
        }
        else {
            listaBatalha[i].iniciativa = iniciativaPersonagem;
        }
        printf("\n");

    }
}

void trocarPosicao(struct personagemIniciativa *listaBatalha, int qntPersonagem){
    int p1 = -1;
    int p2 = -1;

    while (p1 < 0 || p1 > (qntPersonagem - 1)) {
        printPersonagens(listaBatalha, qntPersonagem);
        printf("\n\n");
        printf("1. Qual personagem deseja alterar?\nSua resposta: ");
        scanf("%d", &p1);
        getchar();
        printf("\n");
        p1--;
    }
    system("cls");


    while ((p2 < 0 || p2 > (qntPersonagem - 1)) || p1 == p2) {
        printPersonagens(listaBatalha, qntPersonagem);
        printf("\n\n");
        printf("Escolhido 1: %s\n ", listaBatalha[p1].nome);
        printf("2. Por qual personagem deseja trocar?\nSua resposta: ");
        scanf("%d", &p2);
        getchar();
        printf("\n");
        p2--;
    }
    system("cls");


    swap(listaBatalha, p1, p2);
}

int main(){
    
    srand(time(NULL)); //Fornecendo a seed do time(NULL) para a função srand
    int qntPersonagem;
    struct personagemIniciativa *listaBatalha;

    do {
        printf("Insira a quantidade de envolvidos no combate: ");
        scanf("%d", &qntPersonagem);
        getchar();
        printf("\n");
    } while (qntPersonagem <= 0);

    system("CLS");

    listaBatalha = (struct personagemIniciativa*) malloc(sizeof(struct personagemIniciativa) * qntPersonagem);

    if (listaBatalha == NULL) {
        printf("Erro ao alocar memória!\n");
        printf("Reinicie o programa e tente novamente.\n");
        return 1;
    }

    atribuicaoPersonagens(listaBatalha, qntPersonagem);
    bubbleSort(listaBatalha, qntPersonagem);
    system("cls");

    int escolha;
    while (escolha != 3) {
        printf("ORDEM DE INICIATIVA:\n\n");
        printPersonagens(listaBatalha, qntPersonagem);
        printf("\n\n");

        escolha = 0;
        while (escolha <= 0 || escolha > 3) {
            printf("[1] Alterar iniciativa\n");
            printf("[2] Trocar posicao\n");
            printf("[3] Sair\n");
            scanf("%d", &escolha);
            getchar();
        }

        system("cls");

        switch (escolha) {
            case 1:
                //alterarIniciativa(listaBatalha, qntPersonagem);
                break;
            
            case 2:
                trocarPosicao(listaBatalha, qntPersonagem);
                break;

            case 3:
                printf("Saindo...\n");
        }
    }

    // Liberando a memória alocada
    free(listaBatalha);
    
    system("pause");

    return 0;
}