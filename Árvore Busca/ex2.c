#include <stdio.h>
#include <stdlib.h>
typedef struct ab_char {
    int dado;
    struct ab_char *esq;
    struct ab_char *dir;
} ab_char;

void mostra_arvore(ab_char* raiz) {
    printf("(");
    if(raiz) {
        printf("%d ", raiz->dado);
        mostra_arvore(raiz->esq);
        printf(" ");
        mostra_arvore(raiz->dir);
    }
    printf(")");
}


void rotaciona_esquerda(ab_char **raiz) {

    if(*raiz == NULL)
        return;
    ab_char *node = *raiz;
    ab_char *temp;

    *raiz = node->dir;
    temp = (*raiz)->esq;
    (*raiz)->esq = node;
    node->dir = temp;

}

ab_char* criaNo(int dado) {
    ab_char* novo = (ab_char *) malloc(sizeof(ab_char));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->dado = dado;

    return novo;
}

ab_char* insere(ab_char* raiz, int dado) {
    if(!raiz)
        return criaNo(dado);
    else {
        if(dado <= raiz->dado)   
            raiz->esq = insere(raiz->esq, dado);
        else 
            raiz->dir = insere(raiz->dir, dado);
    }

    return raiz;
}

void em_lista(ab_char **p_raiz) {
    int i;

    if(p_raiz == NULL || (*p_raiz) == NULL)
        return;
    else {
        for(i = 0; (*p_raiz)->dir != NULL; i++)
            rotaciona_esquerda(p_raiz);
    }
    
    em_lista(&(*p_raiz)->esq);
}

int main() {
    ab_char *root = NULL;

    int n, i, v;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &v);
        if(i == 0)
            root = insere(root, v);
        else 
            insere(root, v);
    }
    rotaciona_esquerda(&root);
    rotaciona_esquerda(&root); 
    root = root->esq;
    rotaciona_esquerda(&(root->esq));
    mostra_arvore(root);
    return 0;
}