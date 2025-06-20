#include <stdio.h>
#include <time.h>
#include <stdlib.h>

long long count_swap=0;

void imprimeVetor(int *vetor, int inicio, int fim, char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    for (int i=inicio; i<=fim; i++) fprintf(arquivo, "%d\n", vetor[i]);
    fclose (arquivo);
} 

int insereVetor(int *vetor, char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) exit(1);
    int entrada;
    int i=0;
    while (fscanf(arquivo, "%d", &vetor[i]) == 1) {
        i++;
    }
    fclose(arquivo);
    return i;
}

void swap(int *guardiao, int *explorador) {
    int x = *guardiao;
    *guardiao = *explorador;
    *explorador = x;
    count_swap++;
}

int particionaCrescente (int *vetor, int inicio, int fim) {
    int diferenca = fim-inicio+1;
    int indice_aleatorio = (rand()%diferenca)+inicio;
    swap(&vetor[indice_aleatorio], &vetor[fim]);

    int pivo = vetor[fim];
    int guardiao = inicio-1;
    for (int explorador=inicio; explorador<fim; explorador++) {
        if (vetor[explorador] <= pivo) {
            guardiao++;
            swap(&vetor[guardiao], &vetor[explorador]);
        }
    }
    swap(&vetor[guardiao+1], &vetor[fim]);

    return (guardiao+1);
}

void quickSortCrescente(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionaCrescente(vetor, inicio, fim);
        quickSortCrescente(vetor, inicio, pivo-1);
        quickSortCrescente(vetor, pivo+1, fim);
    }
}

int particionaDecrescente (int *vetor, int inicio, int fim) {
    int diferenca = fim-inicio+1;
    int indice_aleatorio = (rand()%diferenca)+inicio;
    swap(&vetor[indice_aleatorio], &vetor[fim]);

    int pivo = vetor[fim];
    int guardiao = inicio-1;
    for (int explorador=inicio; explorador<fim; explorador++) {
        if (vetor[explorador] >= pivo) {
            guardiao++;
            swap(&vetor[guardiao], &vetor[explorador]);
        }
    }
    swap(&vetor[guardiao+1], &vetor[fim]);

    return (guardiao+1);
}

void quickSortDecrescente(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionaDecrescente(vetor, inicio, fim);
        quickSortDecrescente(vetor, inicio, pivo-1);
        quickSortDecrescente(vetor, pivo+1, fim);
    }
}

void selectionSortCrescente (int *vetor, int tamanho) {
    for (int i=0; i<=tamanho; i++) {
        int menor = i;
        for (int j=i+1; j<=tamanho; j++) {
            if (vetor[j] < vetor[menor]) menor=j;
        }
        swap(&vetor[i], &vetor[menor]);
    }
}

void selectionSortDecrescente (int *vetor, int tamanho) {
    for (int i=0; i<=tamanho; i++) { 
        int maior = i;
        for (int j=i+1; j<=tamanho; j++) { 
            if (vetor[j] > vetor[maior]) maior=j;
        }
        swap(&vetor[i], &vetor[maior]);
    }
}



int main () {
    srand(time(NULL));
    int *vetor = (int*) malloc(100000010 * sizeof(int));
    if (vetor == NULL) {
        fprintf(stderr, "Erro ao alocar memória!\n");
        return 1;
    }
    int tamanho_vetor = insereVetor(vetor, "aleatorios_1.in"); 


    clock_t inicio = clock();
    //selectionSortCrescente(vetor, tamanho_vetor-1); 
    //selectionSortDecrescente(vetor, tamanho_vetor-1); 
    //quickSortCrescente(vetor, 0, tamanho_vetor-1); 
    //quickSortDecrescente(vetor, 0, tamanho_vetor-1); 
    clock_t fim = clock();
    

    imprimeVetor(vetor, 0, tamanho_vetor-1, "arquivo_resultados.out");
    double tempo_execucao = (double)(fim-inicio)/CLOCKS_PER_SEC;
    printf("Tempo de execução do código: %.3lf\n", tempo_execucao);
    printf("Trocas executadas: %lld\n", count_swap);
    free (vetor);
    return 0;
}
