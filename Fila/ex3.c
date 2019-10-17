#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Fila {
    int prioridade;
    char atividade[51];
    struct Fila *next;
} Fila;

int count = 0;

void insereFim(Fila **head, char atividade[], int prioridade) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    Fila *temp = *head;

    fila->prioridade = prioridade;
    sprintf(fila->atividade, "%s", atividade);
    fila->next = NULL;

    if(*head == NULL) {
        *head = fila;
        return;
    }
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = fila;
    
    count++;
}

void remover(Fila **head, int num) {
    int i = 0, trocou = 0, prioaux;
    Fila *temp = *head;
    Fila *temp2 = *head;
    char atividade[51];

    do {
        trocou = 0;

        while(temp2->next != NULL) {
            if(temp2->prioridade > temp2->next->prioridade) {
                prioaux = temp2->prioridade;
                temp2->prioridade = temp2->next->prioridade;
                temp2->next->prioridade = prioaux;

                sprintf(atividade, "%s", temp2->atividade);
                sprintf(temp2->atividade, "%s", temp2->next->atividade);
                sprintf(temp2->next->atividade, "%s", atividade);

                trocou = 1;
            }
            temp2 = temp2->next;
        }
        temp2 = *head;
    } while(trocou);

    while(i < num && temp != NULL) {
        *head = temp->next;
        free(temp);
        temp = *head;

        i++;    
    }
    
    count -= num;
}

void printFila(Fila *head) {
    Fila *temp = head;
    printf("Tamanho da fila: %d\n", count+1);
    while(temp != NULL) {
        printf("Atividade: %s Prioridade: #%d\n", temp->atividade, temp->prioridade);
        temp = temp->next;
    }
}

int main() {
    Fila *fila = NULL;
    char atividade[51];
    int prioridade;

    while(1) {
        scanf("%s", atividade);

        if(atividade[0] <= 47 || atividade[0] >= 58) {
            scanf("%d", &prioridade);
            insereFim(&fila, atividade, prioridade);
        } else {
            remover(&fila, atoi(atividade));
            break;
        }
    }
    printFila(fila);
    return 0;
}