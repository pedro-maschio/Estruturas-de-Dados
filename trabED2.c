/** Matricula: 190018763
 *       Nome: Pedro de Tôrres Maschio
 *      Turma: A */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int capacidade, top;
    char *string;
} Pilha;

Pilha*  inicializaPilha(int capacidade) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->top = -1;
    pilha->string = malloc(capacidade * sizeof(char));

    return pilha;
}

char push(Pilha *pilha, char ch) {
    pilha->string[++pilha->top] = ch;
    return ch;
}

char pop(Pilha *pilha) {
    return pilha->string[pilha->top--];
}


int precedencia(char op) {
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '^')
        return 3;
    else 
        return 0;
}

void transforma(const char* infixa, char* posfixa, Pilha *pilha) {
    /* Insira seu código aqui. */
    int i;

    for(i = 0; i < strlen(infixa); i++) {

    }
}

int main() {
    char infixa[101], posfixa[201];
    Pilha *pilha = inicializaPilha(201);

    scanf("%100[^\n]", infixa);

    transforma(infixa, posfixa, pilha);
    printf("%s\n", posfixa);

    return 0;
}