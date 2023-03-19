#include <stdio.h>

void gerar_combinacoes(int matriz[4][4], int numeros[], int linhas[], int indice, int* count) {
    if (indice == 4) {
        // Verificar se não há números repetidos nas colunas
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 3; i++) {
                if (matriz[i][j] == matriz[i+1][j]) {
                    return;
                }
            }
        }
        // Verificar se não há linhas repetidas
        for (int i = 0; i < 3; i++) {
            for (int j = i+1; j < 4; j++) {
                if (matriz[i][0] == matriz[j][0] && matriz[i][1] == matriz[j][1] && matriz[i][2] == matriz[j][2] && matriz[i][3] == matriz[j][3]) {
                    return;
                }
            }
        }
        // Imprimir a combinação válida
        printf("\nCombinação %d:\n", (*count)+1);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
        (*count)++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (linhas[i] == -1) {
            continue;
        }
        // Atribuir o número na posição correta da matriz
        matriz[indice][linhas[i]] = numeros[indice];
        int temp = linhas[i];
        linhas[i] = -1;
        gerar_combinacoes(matriz, numeros, linhas, indice+1, count);
        linhas[i] = temp;
        matriz[indice][temp] = 0;
    }
}

int main() {
    // Criar uma lista de todos os números possíveis
    int numeros[4] = {1, 2, 3, 4};

    // Criar uma lista de todas as combinações possíveis de linhas, sem repetir nenhuma
    int linhas[4] = {0, 1, 2, 3};

    // Gerar todas as 288 combinações possíveis
    int matriz[4][4] = {{0}};
    int count = 0;
    gerar_combinacoes(matriz, numeros, linhas, 0, &count);

    printf("\nTotal de combinações: %d\n", count);
    return 0;
}
