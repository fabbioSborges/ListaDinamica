#include <stdio.h>
#include "ListaDinamica.h"

int main(void) {
  TInfo aluno;    
  TListaDinamica *minhaLista = CriarLista();
  
  if(ListaVazia(minhaLista)){
    printf("Lista vazia \n");
  }

  //Inserir  novo elemento
  aluno.matricula = 10;
  aluno.media = 7;
  //InserirPrimeiraPosicao(minhaLista, aluno);
  InserirUltimaPosicao(minhaLista, aluno);

  //Inserir  novo elemento
  aluno.matricula = 6;
  aluno.media = 9.5;
  //InserirPrimeiraPosicao(minhaLista, aluno);
  InserirUltimaPosicao(minhaLista, aluno);
    
  imprimirLista(minhaLista);
  return 0;
}