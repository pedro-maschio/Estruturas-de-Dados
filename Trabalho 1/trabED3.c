/** Matricula: 190018763
 *       Nome: Pedro de Tôrres Maschio
 *      Turma: A */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int top;
    double array[201];
} Pilha;

double push(Pilha *pilha, double elemento) {
    pilha->array[++pilha->top] = elemento;

    return elemento;
}
double pop(Pilha *pilha) {
    return pilha->array[pilha->top--];
}

void calcula(const char* posfixa, Pilha *pilha) {
    int i, k = 0;
    double num = 0, a, b;

    char *aux = calloc(8, sizeof(char));

    for(i = 0; i < strlen(posfixa); i++) {
        if((posfixa[i] >= 48 && posfixa[i] <= 57)) {
            while(posfixa[i] != ' ') {
                aux[k] = posfixa[i];
                i++;
                k++;
            }
            num = atof(aux);
            k = 0;
            push(pilha, num);
            free(aux);
            aux = calloc(8, sizeof(char)); // para remover o que tinha antes no vetor

        } else if(posfixa[i] == '+') {
            a = pop(pilha);
            b = pop(pilha);
            push(pilha, a+b);
        } else if(posfixa[i] == '*') {
            a = pop(pilha);
            b = pop(pilha);
            push(pilha, a*b);
        } else if(posfixa[i] == '^') {
            a = pop(pilha);
            b = pop(pilha);
            push(pilha, pow(b, a));
        } else if(posfixa[i] == '/') {
            a = pop(pilha);
            b = pop(pilha);
            push(pilha, b/a);
        } else if(posfixa[i] == '-') {
            a = pop(pilha);
            b = pop(pilha);
            push(pilha, b - a);
        }    
           
    }
    printf("%.5lf\n", pilha->array[pilha->top]);
}

int main() {
    Pilha *pilha = malloc(sizeof(Pilha));
    char posfixa[201];

    scanf("%200[^\n]", posfixa);
    calcula(posfixa, pilha);

    return 0;

    return 0;
}
