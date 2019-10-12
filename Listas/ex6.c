#include <stdio.h>
#include <stdlib.h>
typedef struct Lista {
    int dado;
    struct Lista *next, *prev;
} Lista;

void insereFim(Lista **head, int dado) {
    Lista *nova = (Lista *) malloc(sizeof(Lista));
    Lista *temp = *head;

    nova->dado = dado;
    nova->next = NULL;

    if(*head == NULL) {
        nova->prev = NULL;
        *head = nova;
        return;
    }
    while(temp->next != NULL) 
        temp = temp->next;
    temp->next = nova;
    nova->prev = temp;

}

void insereInicio(Lista **head, int dado) {
    Lista *nova = (Lista *) malloc(sizeof(Lista));

    nova->dado = dado;
    nova->next = *head;
    nova->prev = NULL;

    if(*head != NULL)
        (*head)->prev = nova;
    (*head) = nova;
}

void inserePosicao(Lista **head, int dado, int posicao) {
    Lista *temp = *head, *prev;
    int count = 0;
    Lista *nova = (Lista *) malloc(sizeof(Lista));
    nova->dado = dado;

    while(count != posicao && temp->next != NULL) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    prev->next = nova;
    nova->prev = prev;
    nova->next = temp;
    temp->prev = nova;
}

void removeInicio(Lista **head) {
    if(head == NULL)
        return;
    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Lista *temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}

void removeFim(Lista **head) {
    Lista *temp = *head, *prev;

    if(*head == NULL)
        return;

    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL;
}

void removePosicao(Lista **head, int posicao) {
    int count = 0;
    Lista *temp = *head, *prev;

    if(*head == NULL)
        return;

    while(temp->next != NULL && count != posicao) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    prev->next = temp->next;
    temp->next->prev = prev;
    free(temp);
}

void printList(Lista *head) {
    int prev, next, tam = 0;
    while(head != NULL) {
        if(head->next)
            next = 1;
        else 
            next = 0;

        if(head->prev)
            prev = 1;
        else 
            prev = 0;
        printf("%d - %d - %d\n", head->dado, prev, next);

        head = head->next;
        tam++;
    }
    printf("Tamanho: %d\n\n", tam);
}

void printReversal(Lista *head) {
    Lista *temp = head;
    int tam = 0, prev, next;

    if(head != NULL) {

        while(temp->next != NULL)
            temp = temp->next;
        while(temp != NULL) {
            if(temp->next)
                next = 1;
            else 
                next = 0;

            if(temp->prev)
                prev = 1;
            else 
                prev = 0;
            printf("%d - %d - %d\n", temp->dado, prev, next);

            temp = temp->prev;
            tam++;    
        }
    }
    printf("Tamanho: %d\n", tam);
}

int main() {
    int dado;
    Lista *head = NULL;

    while(scanf("%d", &dado) > 0) {
        insereFim(&head, dado);
    }    
    
    printList(head);

    insereFim(&head, 43);
    insereFim(&head, 65);
    printList(head);

    insereInicio(&head, 56);
    insereInicio(&head, 12);
    printList(head);

    inserePosicao(&head, 10, 2);
    insereInicio(&head, 15);
    printList(head);

    removeFim(&head);
    removeFim(&head);
    removeFim(&head);
    printList(head);

    removeInicio(&head);
    removeInicio(&head);
    removeInicio(&head);
    printList(head);

    removeFim(&head);
    removePosicao(&head, 2);
    printList(head);


    printReversal(head);


    return 0;
}