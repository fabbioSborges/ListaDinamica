typedef struct{
  int matricula;
  float media;
}TInfo;

typedef struct elem{
  TInfo info; 
  struct elem *prox;
}TElem;

typedef struct{
  TElem *prim;
  int tamanho;
  TElem *ultimo;
}TListaDinamica;

TListaDinamica *CriarLista();
int ListaVazia(TListaDinamica *lista);
int InserirPrimeiraPosicao(TListaDinamica *lista, TInfo info);
void imprimirLista(TListaDinamica *lista);
int InserirUltimaPosicao(TListaDinamica *lista, TInfo info);
