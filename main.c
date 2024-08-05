#include "atribuicoes.h"

int main() {
    
    srand(time(NULL)); //Fornecendo a seed do time(NULL) para a função srand
    int qntPersonagens;
    struct personagemIniciativa *listaBatalha;

    do {
        printf("Insira a quantidade de envolvidos no combate: ");
        scanf("%d", &qntPersonagens);
        getchar();
        printf("\n");
    } while (qntPersonagens <= 0);

    system("CLS");

    listaBatalha = (struct personagemIniciativa*) malloc(sizeof(struct personagemIniciativa) * qntPersonagens);

    if (listaBatalha == NULL) {
        printf("Erro ao alocar memória!\n");
        printf("Reinicie o programa e tente novamente.\n");
        return 1;
    }

    atribuicaoPersonagens(listaBatalha, qntPersonagens);
    bubbleSort(listaBatalha, qntPersonagens);
    system("cls");

    int escolha;
    while (escolha != 3) {
        printf("ORDEM DE INICIATIVA:\n\n");
        printPersonagens(listaBatalha, qntPersonagens);
        printf("\n\n");

        escolha = 0;
        while (escolha <= 0 || escolha > 3) {
            printf("[1] Alterar iniciativa\n");
            printf("[2] Trocar posicao\n");
            printf("[3] Sair\n");
            printf("Sua escolha: ");
            scanf("%d", &escolha);
            getchar();
        }

        system("cls");

        switch (escolha) {
            case 1:
                alterarIniciativa(listaBatalha, qntPersonagens);
                bubbleSort(listaBatalha, qntPersonagens);
                break; 
            
            case 2:
                trocarPosicao(listaBatalha, qntPersonagens);
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