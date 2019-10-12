#include <stdio.h>
#include <stdlib.h>
typedef struct Lista {
    int dado;
    struct Lista *prox, *ant;
} Lista;

void insereFim(Lista **head, int dado) {
    Lista *temp = *head;
    Lista *nova = (Lista *) malloc(sizeof(Lista));
    nova->dado = dado;
    nova->prox = NULL;

    if(*head == NULL) {
        nova->ant = NULL;
        *head = nova;
        return;
    }
    while(temp->prox != NULL)
        temp = temp->prox;
    temp->prox = nova;
    nova->ant = temp;
}
void insereInicio(Lista **head, int dado) {
    Lista *temp = *head;
    Lista *nova = (Lista *) malloc(sizeof(Lista));
    nova->dado = dado;
    nova->ant = NULL;

    if(*head == NULL) {
        nova->prox = NULL;
        *head = nova;
        return;
    }
    nova->prox = temp;
    temp->ant = nova;
    *head = nova;
}

void removeInicio(Lista **head) {
    Lista *temp = *head;

    if(temp->prox == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    *head = (*head)->prox;
    (*head)->ant = NULL;
    free(temp);
}

void removeFim(Lista **head) {
    Lista *temp = *head, *prev;

    if(*head == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    while(temp->prox != NULL) {
        prev = temp;
        temp = temp->prox;
    }
    prev->prox = NULL;
    free(temp);

}

void inserirPosicao(Lista **head, int dado, int posicao) {
    Lista *nova = (Lista *) malloc(sizeof(Lista));
    Lista *temp = *head, *prev;

    nova->dado = dado;
    int count = 0;

    if(posicao == 0) {
        nova->prox = *head;
        nova->ant = NULL;
        *head = nova;
        return;
    }

    while(temp->prox != NULL && posicao != count) {
        count++;
        prev = temp;
        temp = temp->prox;
    }
    prev->prox = nova;
    nova->ant = prev;
    nova->prox = temp;
    temp->ant = nova;
}
void removePosicao(Lista **head, int posicao) {
    int count = 0;
    Lista *temp = *head, *prev;
    
    while(temp->prox != NULL && posicao != count) {
        prev = temp;
        temp = temp->prox;
        count++;
    }
    prev->prox = temp->prox;
    free(temp);
}
void printLista(Lista *head) {
    int count = 0, prox, ant;
    while(head != NULL) {
        if(head->prox)
            prox = 1;
        else
            prox = 0;
        if(head->ant)
            ant = 1;
        else    
            ant = 0;

        printf("%d - %d - %d\n", head->dado, ant, prox);
        head = head->prox;
        count++;
    }
    printf("Tamanho: %d\n\n", count);
}
void printReverso(Lista *head) {
    int count = 0, prox, ant;
    Lista *temp = head;
    while(temp->prox != NULL) {
        temp = temp->prox;
    }
    while(temp != head) {
        if(temp->prox)
            prox = 1;
        else
            prox = 0;
        if(temp->ant)
            ant = 1;
        else    
            ant = 0;

        printf("%d - %d - %d\n", temp->dado, ant, prox);
        temp = temp->ant;
        count++;   
    }
    printf("Tamanho: %d\n\n", count);
}
int main() {
    int dado;
    Lista *head = NULL;

    while(scanf("%d", &dado) > 0) {   
        insereFim(&head, dado);
    }
    printLista(head);
    


    insereFim(&head, 43);
    insereFim(&head, 65);
    printLista(head);

    insereInicio(&head, 56);
    insereInicio(&head, 12);
    printLista(head);

    inserirPosicao(&head, 10, 2);
    insereInicio(&head, 15);
    printLista(head);

    removeFim(&head);
    removeFim(&head);
    removeFim(&head);
    printLista(head);


    removeInicio(&head);
    removeInicio(&head);
    removeInicio(&head);
    printLista(head);

    removeFim(&head);
    removePosicao(&head, 2);
    printLista(head);
    printReverso(head);

    
    return 0;
}