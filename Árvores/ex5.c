#include <stdio.h>
#include <stdlib.h>
typedef struct ab_char {
    char dado;
    struct ab_char *esq;
    struct ab_char *dir;
} ab_char;

void mostra_arvore(ab_char* raiz) {
    printf("(");
    if(raiz) {
        printf("%c ", raiz->dado);
        mostra_arvore(raiz->esq);
        printf(" ");
        mostra_arvore(raiz->dir);
    }
    printf(")");
}

int altura(ab_char *raiz) {
    if(!raiz)   
        return 0;
    else {
        int alturaEsq =  altura(raiz->esq);
        int alturaDir = altura(raiz->dir);

        if(alturaEsq > alturaDir)
            return (alturaEsq + 1);
        else 
            return (alturaDir + 1);
    }
}

void rotaciona_esquerda(ab_char **root) {


    
}

int main() {




    return 0;
}