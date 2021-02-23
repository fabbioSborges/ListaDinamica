#include <stdlib.h>
#include <stdio.h>
#include "ListaDinamica.h"

TListaDinamica *CriarLista(){
  TListaDinamica *lista = (TListaDinamica*) malloc(sizeof(TListaDinamica));
  if(lista == NULL){
    return NULL;
  }
  lista->prim = NULL;
  lista->ultimo = NULL;
  lista->tamanho = 0;
  return lista;
}

int ListaVazia(TListaDinamica *lista){
  if(lista->prim == NULL){
    return 1;
  }else{
    return 0;
  }
}

int InserirPrimeiraPosicao(TListaDinamica *lista, TInfo info){
  TElem *novo = (TElem*) malloc (sizeof(TElem));
  if(novo == NULL){
    return 0;
  }
  novo->info = info;
  
  // inserir em uma lista vazia
  if(ListaVazia(lista)){
    lista->prim = novo;
    lista->ultimo = novo;
    novo->prox = NULL;
  }else{ //lista com elementos
    novo->prox = lista->prim;
    lista->prim = novo;
  }

  lista->tamanho++;
  return 1;
}


void imprimirLista(TListaDinamica *lista){
  TElem *aux = lista->prim;
  int i = 1;
  while(aux != NULL){
    printf("-------Elemento %d------\n", i);
    printf("Matricula: %d\n", aux->info.matricula);
    printf("Media: %f\n\n", aux->info.media);
    i++;
    aux = aux->prox;

  }
}

int InserirUltimaPosicao(TListaDinamica *lista, TInfo info){
  TElem *novo = (TElem*) malloc (sizeof(TElem));
  if(novo == NULL){
    return 0;
  }
  novo->info = info;
  
  // inserir em uma lista vazia
  if(ListaVazia(lista)){
    lista->prim = novo;
    lista->ultimo = novo;
    novo->prox = NULL;
  }else{ //lista com elementos
    lista->ultimo->prox = novo;
    novo->prox = NULL;
    lista->ultimo = novo;
  }
  lista->tamanho++;
  return 1;
}

int RemovePrimeiro(TListaDinamica *lista){
  if(ListaVazia(lista)){
    return 0;
  }
  TElem *noRemove;
  noRemove = lista->prim;
  //lista->prim = lista->prim->prox;
  lista->prim = noRemove->prox;
  //remover uma lista com somente um elemento
  if(lista->prim == NULL){
    lista->ultimo = NULL;
  }
  lista->tamanho--;
  free(noRemove);
  return 1;
}

int RemoveUltimo(TListaDinamica *lista){
  if(ListaVazia(lista)){
    return 0;
  }
  TElem *noRemove = lista->prim;
  TElem *noAnt;
  
  // remover lista com somsnete um elemento
  if(lista->prim->prox == NULL){
    lista->prim = noRemove->prox;
    lista->ultimo = noRemove->prox;
    free(noRemove);
    return 1;
  }

  while(noRemove->prox != NULL){
    noAnt = noRemove;
    noRemove = noRemove->prox;
  }
  noAnt->prox = noRemove->prox;
  lista->ultimo = noAnt;
  free(noRemove);
  return 1;
}