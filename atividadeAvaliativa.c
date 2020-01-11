#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Lista {
    char nome[21];
    double preco;
    struct Lista *next;
} Lista;

void insere(Lista **head, char nome[], double preco) {
    Lista *new = malloc(sizeof(Lista));
    new->preco = preco;
    sprintf(new->nome, "%s", nome);

    new->next = *head;
    *head = new;
}
void remover(Lista **head, char nome[]) {
    Lista *temp = *head, *anterior;

    if(temp != NULL && strcmp(temp->nome, nome) == 0)  {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && (strcmp(temp->nome, nome) != 0)) {
        anterior = temp;
        temp = temp->next;
    }
    anterior->next = temp->next;
    free(temp);
}
void print(Lista *head) {
    Lista *temp = head;

    while(temp->next != NULL) {
        printf("%s %.2lf\n", temp->nome, temp->preco);
        temp = temp->next;
    }
}
void count(Lista *head, double *soma, int *itens) {
    Lista *temp = head;

    while(temp->next != NULL) {
        *itens += 1;
        *soma += temp->preco;
        temp = temp->next;
    }
}
int main() {

    Lista *head = malloc(sizeof(Lista));
    head->next = NULL;

    char nomepreco[31], nome[21], preco[10];

    double soma = 0;
    int itens = 0;

    while(1) {
        scanf("%[^\n]", nomepreco);
        getchar();
        
        sscanf(nomepreco, "%s %s", nome, preco);

        if(strcmp(nome, "fim") == 0)
            break;
        else if(nome[0] == '-') {
            remover(&head, preco);
        } else {
            double precofloat = atof(preco);
            insere(&head, nome, precofloat);
        }

    }
    print(head);
    printf("----------------------\n");

    count(head, &soma, &itens);
    printf("%d item(ns): R$ %.2lf\n", itens, soma);
    return 0;
}