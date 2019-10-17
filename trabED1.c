#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int capacidade;
    char *array;
    int top;
} Pilha;

Pilha* criaPilha(int capacidade) {
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->top = -1;
    pilha->capacidade = capacidade;
    pilha->array = (char *) malloc(pilha->capacidade * sizeof(Pilha));


    return pilha;
}   
char push(Pilha *pilha, char elemento) {
    pilha->array[++pilha->top] = elemento;

    return elemento;
}
char pop(Pilha *pilha) {
    return pilha->array[pilha->top--];
}
int tamanho(Pilha *pilha) {
    return pilha->top;
}

 _Bool valida(const char* expressao) {
    Pilha *pilha = criaPilha(strlen(expressao));
    int i, count = 0;

    for(i = 0; i < strlen(expressao); i++) {
        if(expressao[i] == '(') {
            push(pilha, expressao[i]);
        } else if(expressao[i] == '[') {
            push(pilha, expressao[i]);
        } else if(expressao[i] == '{') {
            push(pilha, expressao[i]);
        } else if(expressao[i] == ')' && pop(pilha) != '(')
            return false;
        else if(expressao[i] == ']' && pop(pilha) != '[')
            return false;
        else if(expressao[i] == '}' && pop(pilha) != '{')
            return false;
        else if(expressao[i] == '*' || expressao[i] == '+' || expressao[i] == '/' || expressao[i] == '^' || expressao[i] == '-')
            count++;
        
    }
    if(count == 0)
        return false;
    return true;
    
}

int main() {
    char expressao[101];
    
    scanf("%100[^\n]", expressao);
    
    if (valida(expressao))
        printf("VALIDA\n");
    else
        printf("INVALIDA\n");


    return 0;
}