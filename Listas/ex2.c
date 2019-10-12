#include <stdio.h>
#include <stdlib.h>
typedef struct Lista {
    int dado;
    struct Lista *next;
} Lista;

void insereInicio(Lista **head, int dado) {
    Lista *nova = (Lista *) malloc(sizeof(Lista));
    nova->dado = dado;
    nova->next = *head;

    (*head) = nova;
}
void insereFim(Lista **head, int dado) {
    Lista *nova = (Lista *) malloc(sizeof(Lista));
    nova->dado = dado;
    nova->next = NULL;

    if(*head == NULL) {
        *head = nova;
        return;
    }

    Lista *temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = nova;  


}
void removeInicio(Lista **head) {
    Lista *temp = *head;
    if(*head == NULL) {
        return;
    }
    printf("%d\n", (*head)->dado);
    (*head) = (*head)->next;
    free(temp);
}
void removeFim(Lista **head) {
    Lista *temp = *head, *prev;

    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("%d\n", temp->dado);
    prev->next = NULL;
    free(temp);
}
void printLista(Lista *head) {
    while(head != NULL && head->dado != 0) {
        printf("%d\n", head->dado);
        head = head->next;
    }
}


int main() {
    Lista *head = NULL;
    char op;
    int dado;

    while(1) {
        scanf(" %c", &op);
        if(op == 'I' || op == 'F') {
            scanf("%d", &dado);
            if(op == 'I')
                insereInicio(&head, dado);
            else if(op == 'F')
                insereFim(&head, dado);
        } else if(op == 'P')
            removeFim(&head);
        else if(op == 'D')
            removeInicio(&head);
        else if(op == 'X') {
            printf("\n");
            printLista(head);
            break;
        }
    }
    return 0;
}