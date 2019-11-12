#include <stdio.h>
#include <stdlib.h>
typedef struct ab_int {
    int dado;
    struct ab_int *esq;
    struct ab_int *dir;
} ab_int;

ab_int* novoNo(int dado) {
    ab_int *novo = (ab_int *) malloc(sizeof(ab_int));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->dado = dado;

    return novo;
}

ab_int* insere(ab_int *root, int dado) {
    if(root == NULL)
        return novoNo(dado);
    if(dado > root->dado) 
        root->dir = insere(root->dir, dado);
    else if(dado < root->dado)
        root->esq = insere(root->esq, dado);

    return root;
}

void imprimir(ab_int *root) {
    if(!root)
        return;
    printf("%d ", root->dado);
    imprimir(root->esq);
    imprimir(root->dir);
}

void mostra_arvore(ab_int* raiz) {
    printf("(");
    if(raiz) {
        printf("%d ", raiz->dado);
        mostra_arvore(raiz->esq);
        printf(" ");
        mostra_arvore(raiz->dir);
    }
    printf(")");
}

int main() {
    ab_int *root = NULL;

    root = insere(root, 1);
    insere(root, 2);
    insere(root, 3);
    insere(root, 4);

    mostra_arvore(root);
}