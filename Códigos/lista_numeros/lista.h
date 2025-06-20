#ifndef LISTA_NUMEROS_H
#define LISTA_NUMEROS_H

struct dado {
    int valor;
};
typedef struct dado Dados;
typedef struct elemento Elemento;
typedef struct lista Lista;


Lista* listaCriar();

void listaDestruir(Lista *minha_lista);

void listaImprimir(Lista *minha_lista, char *nome_arquivo);

int listaInsertInicio(Lista *minha_lista, int valor_copiar);

int listaRemoveInicio(Lista *minha_lista);

int listaInsertFim(Lista *minha_lista, int valor_copiar);

int listaRemoveFim(Lista *minha_lista);

int listaInsertMeio(Lista *minha_lista, int valor_copiar); 

int listaRemoveMeio(Lista *minha_lista, int valor_remover); 

void listaSelectionSortCrescente(Lista *minha_lista);

void listaSelectionSortDecrescente(Lista *minha_lista);

void listaQuickSortCrescente(Lista *minha_lista);

void listaQuickSortDecrescente(Lista *minha_lista);

int listaLerArquivos(Lista *minha_lista, char *nome_arquivo);

long long getQuantidadeSwap();
#endif


