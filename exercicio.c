#include <stdio.h>
#include <stdlib.h>
typedef struct Lista {
    int dado;
    struct Lista *next;
} Lista;

typedef struct {
    Lista *lista;
} Array;



void append(Lista **head, int dado) {
    Lista *nova = (Lista *) malloc(sizeof(Lista));
    Lista *temp = *head;

    nova->dado = dado;
    nova->next = NULL;

    if(*head == NULL) {
        *head = nova;
        return;
    } else {
        while(temp->next != NULL) 
            temp = temp->next;
        temp->next = nova;
    }
}

int size(Lista *head) {
    int count = 0;  
    Lista *temp = head;

    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

int el(Lista *head, int index) {
    Lista *temp = head;
    int count = 0;

    if(index == 0) 
        return temp->dado;
    while(count < index) {
        temp = temp->next;
        count++;
    }
    return temp->next->dado;
}

void printLista(Lista *head) {
    Lista *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->next;
    }
}

int main() {
    int n, i, q, x, y, op, last = 0, pos;
    Lista *seq;

    scanf("%d %d", &n, &q);
    Array array[n];

    for(i = 0; i < n; i++)
        array[i].lista = NULL;

    for(i = 0; i < q; i++) {
        scanf("%d %d %d", &op, &x, &y);
        pos  = (x^last) % n;

        if(op == 1) {    
            append(&array[pos].lista, y);
        } else {   
            pos = (x^last) % n;
            printf("\npos: %d", pos);
            last = el(array[pos].lista, y%size(array[pos].lista));
            
            
        }
    }

    return 0;
}