#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct Fila {
    char nome[51];
    struct Fila *lig;
} Fila;

void adicionaElemento(Fila **head, char nome[]) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    Fila *temp = *head;
    sprintf(fila->nome, "%s", nome);
    fila->lig = NULL;

    if(*head == NULL) {
        *head = fila;
        return;
    } else {
        while(temp->lig != NULL)
            temp = temp->lig;
        temp->lig = fila;
    }
}

char* removeElemento(Fila **head, char *nome) {
    Fila *temp = *head;
    if(*head == NULL)
        return NULL;
    else {
        sprintf(nome, "%s", temp->nome);
        *head = temp->lig;
        free(temp); 
        temp = NULL;
    }
    return nome;
}

void moveFila(Fila **head, int move) {
    char *nome = malloc(51*sizeof(char));
    int i = 0;
    while(i < move) {
        nome = removeElemento(head, nome);
        adicionaElemento(head, nome);
        i++;
    }
}

void printFila(Fila *head) {
    Fila *temp = head;
    if(head == NULL)
        return;
    printf("Pessoa da frente: %s\n", temp->nome);
    while(temp->lig != NULL) {
        temp = temp->lig;
    }
    printf("Pessoa do fim: %s\n", temp->nome);
}

int main() {
    Fila *head = NULL;
    char nome[51];

    while(1) {
        scanf("%s", nome);
        if(atoi(nome) != 0) {
            moveFila(&head, atoi(nome));
            break;
        }
        else if(nome[0] == '0') {
            moveFila(&head, 0); 
            break;
        }
        else {
            adicionaElemento(&head, nome);
        }
    }
    printFila(head);


    return 0;
}
