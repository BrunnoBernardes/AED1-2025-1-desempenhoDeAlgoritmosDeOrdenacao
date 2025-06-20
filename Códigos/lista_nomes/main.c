#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "lista.h"
int main () {
    srand(time(NULL));
    Lista *minha_lista = NULL;
    minha_lista = listaCriar();
    listaLerArquivos(minha_lista, "aleatorios_1.in");
    

    clock_t inicio = clock();
    //listaSelectionSortCrescente(minha_lista); 
    //listaSelectionSortDecrescente(minha_lista); 
    //listaQuickSortCrescente(minha_lista); 
    //listaQuickSortDecrescente(minha_lista); 
    clock_t fim = clock();

    
    listaImprimir(minha_lista, "arquivo_resultado.out");
    double tempo_execucao = (double)(fim-inicio)/CLOCKS_PER_SEC;
    printf("Tempo de execução do código: %.3lf\n", tempo_execucao);
    printf("Trocas executadas: %lld\n", getQuantidadeSwap());
    listaDestruir(minha_lista);
    return 0;
}
