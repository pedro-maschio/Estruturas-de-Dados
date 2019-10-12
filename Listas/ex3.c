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
    Lista *temp = *head, *prev = *head;

    if(temp->next == NULL) {
        printf("%d\n", temp->dado);
        *head = NULL;
        free(temp);
        return;
    }
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("%d\n", temp->dado);
    prev->next = NULL;
    free(temp);
    temp = NULL;
}
void removeValor(Lista **head, int dado) {
    int count = 0;
    Lista *temp = *head, *prev;

    while(temp != NULL && temp->dado == dado) {
        *head = temp->next;
        free(temp);
        temp = *head;
        count++;
    }

    while(temp != NULL) {
        while(temp != NULL && temp->dado != dado) {
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL) {
            printf("%d\n", count);
            return;
        }
        prev->next = temp->next;
        free(temp);

        temp = prev->next;
        count++;
    }

    printf("%d\n", count);
}
void removePosicao(Lista **head, int posicao) {
    Lista *temp = *head, *prev;
    int count = 1;
    if(posicao == 1) {
        printf("%d\n", temp->dado);
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && count != posicao) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    printf("%d\n", temp->dado);
    prev->next = temp->next;
    free(temp);
}
void trocaValor(Lista **head, int dado, int novo) {
    Lista *temp = *head;

    while(temp != NULL && temp->dado != dado) {
        temp = temp->next;
    }
    temp->dado = novo;
}

void conta(Lista **head, int dado) {
    Lista *temp = *head;
    int count = 0;

    while(temp != NULL) {
        if(temp->dado == dado)
            count++;
        temp = temp->next;
    }
    printf("%d\n", count);
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
    int dado, troca;

    while(1) {
        scanf(" %c", &op);
        if(op == 'I' || op == 'F' || op == 'V' || op == 'E' || op == 'T' || op == 'C') {
            scanf("%d", &dado);
            if(op == 'I')
                insereInicio(&head, dado);
            else if(op == 'F')
                insereFim(&head, dado);
            else if(op == 'V')
                removeValor(&head, dado);
            else if(op == 'E')
                removePosicao(&head, dado);
            else if(op == 'T') {
                scanf("%d", &troca);
                trocaValor(&head, dado, troca);
            } else 
                conta(&head, dado);

        } 
        else if(op == 'P')
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