#include <stdio.h>
#include <stdlib.h>
typedef struct Lista {
    int chave, tempo;
    struct Lista *prox, *back; 
} Lista;
int tempo = 0;

void insereI(Lista **head, int n, int j) {
    Lista *nova = (Lista *) malloc(sizeof(Lista));
    nova->
    
    if(j == 0) {

    }
}

int main() {
    Lista *head = NULL;
    char i;
    int n, j;

    while(i != 'f') {
        scanf(" %c", &i);
        if(i == 'f')
            break;
        else if(i == 'r') {  
            scanf("%d", &n);
            insereI(&head, n);
        }
        else if(i == 'i') {
            scanf("%d %d", &n, &j);
            insereI(&head, n, j);
        }
    }


    return 0;
}