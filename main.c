#include "atribuicoes.h"

int main(){
    srand(time(NULL));
    int qntPersonagem;
    struct batalhaIniciativa *listaBatalha;

    do{
        do{
            printf("Insira a quantidade de envolvidos no combate: ");
            scanf("%d", &qntPersonagem);
            getchar(); // O getchar() é necessário devido ao '\n' que o scanf gera
            printf("\n");
        }while(qntPersonagem <= 0);

        system("CLS");

        // Alocando memória em tempo de execução
        listaBatalha = (struct batalhaIniciativa*) malloc(sizeof(struct batalhaIniciativa) * qntPersonagem);

        if(listaBatalha == NULL){
            printf("Erro ao alocar memória!");
            return 1;
        }
    }while(listaBatalha == NULL);

    int iniciativaPersonagem, modificadorIniciativa;

    for(int i = 0; i < qntPersonagem; i++){

        printf("[%d/%d]. Nome: ", i+1, qntPersonagem);
        removeEnter(listaBatalha[i].nome);

        printf("Iniciativa de %s com o MOD aplicado (0 para randomizar): ", listaBatalha[i].nome);
        scanf("%d", &iniciativaPersonagem);
        getchar();

        if(iniciativaPersonagem <= 0){
            printf("Modificador de iniciativa: ");
            scanf("%d", &modificadorIniciativa);
            getchar();

            //Jogando o 1d20 de iniciativa
            listaBatalha[i].iniciativa = (rand() % 20) + 1;
            printf("Tirou: %d + %d = %d\n", listaBatalha[i].iniciativa, modificadorIniciativa, listaBatalha[i].iniciativa + modificadorIniciativa);

            //Somando o dado com o modificador
            listaBatalha[i].iniciativa += modificadorIniciativa;
        }
        else{
            listaBatalha[i].iniciativa = iniciativaPersonagem;
        }
        printf("\n");

    }

    //Ordenando as iniciativas em ordem decrescente
    bubbleSort(listaBatalha, qntPersonagem);

    system("CLS");

    //Imprimindo a lista ordenada
    printf("ORDEM DE INICIATIVA:\n\n");
    imprimirPersonagem(listaBatalha, qntPersonagem);
    printf("\n");

    // Liberando a memória alocada
    free(listaBatalha);
    
    system("pause");

return 0;
}
