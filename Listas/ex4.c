#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista {
    int chave, tempo;
    struct Lista *next, *back;
} Lista;

int count = 0;

int sizeLista(Lista *head) {
    int count = 0;
    while(head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

void insereI(Lista **head, int n, int j) {
    int tam, i = 0;
    Lista *nova = (Lista *) malloc(sizeof(Lista));
    Lista *temp = *head;

    nova->chave = n;
    nova->tempo = count;
    nova->next = NULL;
    count++;

    if(*head == NULL) {
        *head = nova;
        return;
    } else if(j == 0) {
        nova->back = NULL;
    }
    
    if(j != 0) {
        tam = sizeLista(*head);
        while(i < (tam-j) && temp != NULL) {
            temp = temp->next;
            i++;
        }
        nova->back = temp;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nova;

}


void removeR(Lista **head, int n) {
    Lista *temp = *head;

    count++; // aumenta tempo

    if(temp != NULL) {
        *cab = temp = aux->prox;
        aux->prox = aux->back = NULL;
        while(temp != NULL) {
            if(temp->back == aux)
                temp->back = NULL;
            temp = temp->prox;
        }
    } else {
        while(aux->chave != n && aux->prox != NULL) {
            temp = aux;
            aux = aux->prox;
        }
        if(aux->chave == n) { 
            temp->prox = aux->prox;
            aux->back =  aux->prox = NULL;
        }     
        temp = temp->prox;
        while(temp != NULL) {
            if(temp->back == aux)
                temp->back = NULL;
            temp = temp->prox;
        }

    }
    }
    free(temp);

}

void printList(Lista *head) {
    int count = 0;
    Lista *temp = head;
    if(temp == NULL) {
        printf("-1\n");
        return;
    }
    while(temp != NULL) {
        if(temp->back == NULL)
            printf("[%d,%d] ", temp->chave, temp->tempo);
        else {
            Lista *temp2 = head;
            while(temp2->next != NULL && temp2 != temp->back) {
                count++;
                temp2 = temp2->next;
            }
            printf("[%d,%d,%d] ", temp->chave, temp->tempo, count);
        }
        temp = temp->next;
        count = 0;
    }
}

int main() {
    Lista *head = NULL;
    char i;
    int n, j;

    while(1) {
        scanf(" %c", &i);
        if(i == 'f')
            break;
        else if(i == 'i') {
            scanf("%d %d", &n, &j);
            insereI(&head, n, j);
        } else if(i == 'r') {
            scanf("%d", &n);
            removeR(&head, n);
        }
    }

    printList(head);
    return 0;
}