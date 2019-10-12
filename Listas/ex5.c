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

void printLista(Lista *head) {
    while(head != NULL) {
        printf("%d\n", head->dado);
        head = head->prox;
    }
}
void printa(Lista *head) {
    Lista *temp = head;
    printf("Fila geral original\n");
    int i, j;
    for(i = 1; temp != NULL; temp = temp->prox, i++) {
        printf("%d - %d\n", i, temp->dado);
    }

    printf("\n");
    temp = head;
    printf("Fila preferencial\n");
    for(i = 1; temp != NULL; temp = temp->prox, i++) {
        if(temp->dado >= 60)
            printf("%d - %d\n", i, temp->dado);
    }
    
    printf("\n");
    temp = head;
    printf("Fila geral atualizada\n");
    for(i = 1; temp != NULL; temp = temp->prox, i++) {
        if(temp->dado < 60)
            printf("%d - %d\n", i, temp->dado);
    }

    printf("\n");
    temp = head;
    printf("Resultado esperado fila preferencial\n");
    for(i = 1, j = 1; temp != NULL; temp = temp->prox, i++) {
        if(temp->dado >= 60) {
            printf("%d - %d\n", j, i);
            j++;
        }
    }

    printf("\n");
    temp = head;
    printf("Resultado esperado fila geral\n");
    for(i = 1, j = 1; temp != NULL; temp = temp->prox, i++) {
        if(temp->dado < 60) {
            printf("%d - %d\n", j, i);
            j++;
        }
    }
}

int main() {
    Lista *head = NULL;
    int dado;

    while(scanf("%d", &dado) > 0)
        insereFim(&head, dado);
    printa(head);


    return 0;
}