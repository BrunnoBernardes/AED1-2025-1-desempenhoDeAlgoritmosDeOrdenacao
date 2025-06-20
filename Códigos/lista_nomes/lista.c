#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

long long count_swap=0;

struct elemento {
    Dados dados;
    Elemento *prox;
    Elemento *ante;
};

struct lista {
    Elemento *inicio;
    Elemento *fim;
    int size;
};

Lista* listaCriar() {
    Lista *minha_lista = (Lista*) malloc(sizeof(Lista));
    if (minha_lista!=NULL) {
        minha_lista->inicio = NULL;
        minha_lista->fim = NULL;
        minha_lista->size=0;
    }
    return minha_lista;
}

void listaDestruir(Lista *minha_lista) {
    if (minha_lista == NULL) return;
    Elemento *aux = minha_lista->inicio;
    while (aux!=NULL) {
        Elemento *aux2 = aux;
        aux = aux->prox;
        free(aux2->dados.nome);
        free(aux2);
    }
    free(minha_lista);
    return;
}

void listaImprimir(Lista *minha_lista, char *nome_arquivo) {
    if (minha_lista == NULL) return;
    if (minha_lista->inicio == NULL) return;
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) return;
    Elemento *aux = minha_lista->inicio;
    while (aux!=NULL) {
        fprintf(arquivo, "%s\n", aux->dados.nome);
        aux = aux->prox;
    }
    fclose(arquivo);
    return;
}

int listaInsertInicio(Lista *minha_lista, char *nome_copiar) {
    if (minha_lista == NULL) return -1; 
    char *nome = (char*) malloc((strlen(nome_copiar)+1) * sizeof(char));
    strcpy(nome, nome_copiar);
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return -1;
    no->dados.nome = nome;
    minha_lista->size++;
    if (minha_lista->inicio == NULL) { 
        no->prox = minha_lista->inicio;
        minha_lista->inicio = no;
        minha_lista->fim = no;
        no->ante = NULL;
        return 1;
    }
    (minha_lista->inicio)->ante = no;
    no->prox = minha_lista->inicio;
    no->ante = NULL;
    minha_lista->inicio = no;
    return 1;
}

int listaRemoveInicio(Lista *minha_lista) {
    if (minha_lista == NULL) return -1; 
    if (minha_lista->inicio == NULL) return -1; 
    if (minha_lista->size == 1) { 
        free((minha_lista->inicio)->dados.nome);
        free(minha_lista->inicio);
        minha_lista->inicio = NULL;
        minha_lista->fim = NULL;
        minha_lista->size--;
        return 1;
    }
    Elemento *aux = minha_lista->inicio;
    minha_lista->inicio = (minha_lista->inicio)->prox;
    (aux->prox)->ante = NULL;
    free(aux->dados.nome);
    free(aux);
    minha_lista->size--;
    return 1;
}

int listaInsertFim(Lista *minha_lista, char *nome_copiar) {
    if (minha_lista == NULL) return -1; 
    if (minha_lista->inicio == NULL) return listaInsertInicio(minha_lista, nome_copiar); 
    char *nome = (char*) malloc((strlen(nome_copiar)+1) * sizeof(char));
    strcpy(nome, nome_copiar);
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return -1;
    no->dados.nome = nome;
    minha_lista->size++;
    (minha_lista->fim)->prox = no;
    no->prox = NULL;
    no->ante = minha_lista->fim;
    minha_lista->fim = no;
    return 1;
}

int listaRemoveFim(Lista *minha_lista) {
    if (minha_lista == NULL) return -1; 
    if (minha_lista->inicio == NULL) return -1; 
    if (minha_lista->size == 1) return listaRemoveInicio(minha_lista);
    Elemento *aux = minha_lista->fim;
    minha_lista->fim = (minha_lista->fim)->ante;
    (aux->ante)->prox = NULL;
    free(aux->dados.nome);
    free(aux);
    minha_lista->size--;
    return 1;
}

int listaInsertMeio(Lista *minha_lista, char *nome_copiar) {
    if (minha_lista == NULL) return -1; 
    if (minha_lista->inicio == NULL) return listaInsertInicio(minha_lista, nome_copiar); 
    Elemento *aux = minha_lista->inicio;
    while (aux!=NULL && strcmp(aux->dados.nome, nome_copiar) < 0) aux = aux->prox;
    if (aux == minha_lista->inicio) return listaInsertInicio(minha_lista, nome_copiar); 
    if (aux == NULL) return listaInsertFim(minha_lista, nome_copiar); 
    char *nome = (char*) malloc((strlen(nome_copiar)+1) * sizeof(char));
    strcpy(nome, nome_copiar);
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return -1;
    no->dados.nome = nome;
    minha_lista->size++;
    no->prox = aux;
    no->ante = aux->ante;
    (aux->ante)->prox = no;
    aux->ante = no;
    return 1;
}

int listaRemoveMeio(Lista *minha_lista, char *nome) {
    if (minha_lista == NULL) return -1;
    if (minha_lista->inicio == NULL) return -1; 
    if (minha_lista->size == 1) {
        if (strcmp((minha_lista->inicio)->dados.nome, nome) == 0) return listaRemoveInicio(minha_lista);
        else return -1; 
    }
    Elemento *aux = minha_lista->inicio;
    while (aux!=NULL && strcmp(aux->dados.nome, nome)!=0) aux = aux->prox;
    if (aux==NULL) return -1;
    if (aux==minha_lista->inicio) return listaRemoveInicio(minha_lista);
    if (aux==minha_lista->fim) return listaRemoveFim(minha_lista);
    (aux->ante)->prox = aux->prox;
    (aux->prox)->ante = aux->ante;
    free(aux->dados.nome);
    free(aux);
    minha_lista->size--;
    return 1;
}

int listaLerArquivos(Lista *minha_lista, char *nome_arquivo) {
    if (minha_lista == NULL) return -1; 
    FILE *arquivo;
    char entrada[500];
    arquivo = fopen (nome_arquivo, "r");
    if (arquivo == NULL) return -1;
    while (fscanf(arquivo, " %499[^\n]", entrada) == 1) listaInsertFim(minha_lista, entrada);
    fclose(arquivo);
    return 1;
}

void swap(Elemento *pos1, Elemento *pos2) {
    char *aux = pos1->dados.nome;
    pos1->dados.nome = pos2->dados.nome;
    pos2->dados.nome = aux;
    count_swap++;
}

void listaSelectionSortCrescente(Lista *minha_lista) {
    if (minha_lista==NULL) return;
    if (minha_lista->size==1) return;
    Elemento *pos_atual = minha_lista->inicio;
    while (pos_atual != NULL) {
        Elemento *percorre_atual = pos_atual;
        Elemento *menor = pos_atual;
        while (percorre_atual!=NULL) { 
            if (strcmp(percorre_atual->dados.nome, menor->dados.nome) < 0) menor = percorre_atual;
            percorre_atual = percorre_atual->prox;
        }
        swap(pos_atual, menor);
        pos_atual = pos_atual->prox;
    }
    return;
}

void listaSelectionSortDecrescente(Lista *minha_lista) {
    if (minha_lista==NULL) return;
    if (minha_lista->size==1) return;
    Elemento *pos_atual = minha_lista->inicio;
    while (pos_atual != NULL) {
        Elemento *percorre_atual = pos_atual;
        Elemento *maior = pos_atual;
        while (percorre_atual!=NULL) { 
            if (strcmp(percorre_atual->dados.nome, maior->dados.nome) > 0) maior = percorre_atual;
            percorre_atual = percorre_atual->prox;
        }
        swap(pos_atual, maior);
        pos_atual = pos_atual->prox;
    }
    return;
}

Elemento *particionaCrescente (Elemento *inicio, Elemento *fim) {
    if (inicio!=fim) {
        int n=0;
        Elemento *aux = inicio;
        while (1) { 
            n++;
            if (aux==fim) break;
            aux = aux->prox;
        }
        int num_troca = rand() % n;
        Elemento *pivo_troca = inicio;
        for (int k=0; k<num_troca; k++) pivo_troca = pivo_troca->prox;
        swap(pivo_troca, fim);
    }   
    Elemento * guardiao = NULL;
    char *pivo = fim->dados.nome;
    for (Elemento * explorador = inicio; explorador!=fim; explorador = explorador->prox) {
        if(strcmp(explorador->dados.nome, pivo) <= 0) { 
            if (guardiao == NULL) guardiao = inicio; 
            else guardiao = guardiao->prox; 
            swap(guardiao, explorador); 
        }
    }
    if (guardiao==NULL) guardiao = inicio; 
    else guardiao = guardiao->prox; 
    swap(guardiao, fim);
    return guardiao;
}

void quickSortCrescente(Elemento *inicio, Elemento *fim) {
    if (fim!=NULL && inicio!=fim && inicio!=fim->prox) {
        Elemento *pivo = particionaCrescente(inicio, fim);
        quickSortCrescente(inicio, pivo->ante);
        quickSortCrescente(pivo->prox, fim);
    }
}

void listaQuickSortCrescente(Lista *minha_lista) {
    if (minha_lista==NULL || minha_lista->size <= 1) return; 
    quickSortCrescente(minha_lista->inicio, minha_lista->fim); 
    return;
}

Elemento *particionaDecrescente (Elemento *inicio, Elemento *fim) {
    if (inicio!=fim) {
        int n=0;
        Elemento *aux = inicio;
        while (1) {
            n++;
            if (aux==fim) break;
            aux = aux->prox;
        }
        int troca = rand() % n;
        Elemento *pivo_troca = inicio;
        for (int k=0; k<troca; k++) pivo_troca = pivo_troca->prox;
        swap(pivo_troca, fim);
    }
    
    Elemento * guardiao = NULL;
    char *pivo = fim->dados.nome;
    for (Elemento * explorador = inicio; explorador!=fim; explorador = explorador->prox) {
        if(strcmp(explorador->dados.nome, pivo) >= 0) { 
            if (guardiao == NULL) guardiao = inicio; 
            else guardiao = guardiao->prox; 
            swap(guardiao, explorador); 
        }
    }
    if (guardiao==NULL) guardiao = inicio; 
    else guardiao = guardiao->prox; 
    swap(guardiao, fim); 
    return guardiao;
}

void quickSortDecrescente(Elemento *inicio, Elemento *fim) {
    if (fim!=NULL && inicio!=fim && inicio!=fim->prox) {
        Elemento *pivo = particionaDecrescente(inicio, fim);
        quickSortDecrescente(inicio, pivo->ante);
        quickSortDecrescente(pivo->prox, fim);
    }
}

void listaQuickSortDecrescente(Lista *minha_lista) {
    if (minha_lista==NULL || minha_lista->size <= 1) return;
    quickSortDecrescente(minha_lista->inicio, minha_lista->fim); 
    return;
}

long long getQuantidadeSwap() {
    return count_swap;
}