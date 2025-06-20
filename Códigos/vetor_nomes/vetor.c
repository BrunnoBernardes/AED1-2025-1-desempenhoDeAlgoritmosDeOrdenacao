#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

long long count_swap=0;

void imprimeVetor(char **vetor, int inicio, int fim, char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    for (int i=inicio; i<=fim; i++) fprintf(arquivo, "%s\n", vetor[i]);
    fclose (arquivo);
} 

int insereVetor(char **vetor, char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) exit(1);
    char entrada[500];
    int N=0;
    while (fscanf(arquivo, " %[^\n]", entrada) == 1) {
        vetor[N] = (char*) malloc((strlen(entrada)+1) * sizeof(char));
        if (vetor[N] == NULL) {
            printf("Erro ao alocar memória no vetor\n");
            for(int i=0; i<N; i++) free(vetor[i]);
            fclose(arquivo);
            exit(1);
        }
        strcpy(vetor[N], entrada);
        N++;
    }
    fclose(arquivo);
    return N;
}

void swap(char **pos1, char **pos2) {
    char *aux = *pos1;
    *pos1 = *pos2;
    *pos2 = aux;
    count_swap++;
}

int particionaCrescente (char **vetor, int inicio, int fim) {
    int diferenca = fim-inicio+1;
    int indice_aleatorio = (rand()%diferenca)+inicio;
    swap(&vetor[indice_aleatorio], &vetor[fim]);

    char *pivo = vetor[fim];
    int guardiao = inicio-1;
    for (int explorador=inicio; explorador<fim; explorador++) {
        if (strcmp(vetor[explorador], pivo) <= 0) {
            guardiao++;
            swap(&vetor[guardiao], &vetor[explorador]);
        }
    }
    swap(&vetor[guardiao+1], &vetor[fim]);

    return (guardiao+1);
}

void quickSortCrescente(char **vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionaCrescente(vetor, inicio, fim);
        quickSortCrescente(vetor, inicio, pivo-1);
        quickSortCrescente(vetor, pivo+1, fim);
    }
}

int particionaDecrescente (char **vetor, int inicio, int fim) {
    int diferenca = fim-inicio+1;
    int indice_aleatorio = (rand()%diferenca)+inicio;
    swap(&vetor[indice_aleatorio], &vetor[fim]);

    char *pivo = vetor[fim];
    int guardiao = inicio-1;
    for (int explorador=inicio; explorador<fim; explorador++) {
        if (strcmp(vetor[explorador], pivo) >= 0) {
            guardiao++;
            swap(&vetor[guardiao], &vetor[explorador]);
        }
    }
    swap(&vetor[guardiao+1], &vetor[fim]);

    return (guardiao+1);
}

void quickSortDecrescente(char **vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionaDecrescente(vetor, inicio, fim);
        quickSortDecrescente(vetor, inicio, pivo-1);
        quickSortDecrescente(vetor, pivo+1, fim);
    }
}

void selectionSortCrescente (char **vetor, int tamanho) {
    for (int i=0; i<=tamanho; i++) {
        int menor = i;
        for (int j=i+1; j<=tamanho; j++) {
            if (strcmp(vetor[j], vetor[menor]) < 0) menor=j;
        }
        swap(&vetor[i], &vetor[menor]);
    }
}

void selectionSortDecrescente (char **vetor, int tamanho) {
    for (int i=0; i<=tamanho; i++) { 
        int maior = i;
        for (int j=i+1; j<=tamanho; j++) { 
            if (strcmp(vetor[j], vetor[maior]) > 0) maior=j;
        }
        swap(&vetor[i], &vetor[maior]);
    }
}


int main () {
    srand(time(NULL));
    char **vetor = (char**) malloc(100000000 * sizeof(char*));
    if (vetor == NULL) {
        fprintf(stderr, "Erro ao alocar memoria\n");
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
    for (int i=0; i<tamanho_vetor; i++) free(vetor[i]);
    free (vetor);
    return 0;
}