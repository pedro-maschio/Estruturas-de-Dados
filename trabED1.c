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

int taVazio(Pilha *pilha) {
    return pilha->top == -1;
}

int ehOPerador(char el) {
    if(el == '*' || el == '+' || el == '-' || el == '/' || el == '^')
        return 1;
    return 0;
}

int taOk(const char expressao[], int i) {
    int numCount = 0, opCount = 0;
    char c;

    while(i >= 0) {
        c = expressao[i];

        if(c >= 48 && c <= 57) {
            numCount++;

            while(c != ' ' && c != '(' && c != '[' && c != '{' && !ehOPerador(c) && i != 0)
                c = expressao[--i];
            i++;
        } else if(ehOPerador(c))
            opCount++;
    
        i--;
    }
    if(numCount != (opCount-1))
        return false;
    return true;
}

 _Bool valida(const char* expressao) {
    Pilha *pilha = criaPilha(strlen(expressao));
    int i = 0, opCount = 0, numCount = 0, cCount=0;
    char c;

    while(i < strlen(expressao)) {
        c = expressao[i];

        if(i == 0 && ehOPerador(c))
            return false;
        else if(i == 0 && (c == ')' || c == ']' || c == '}')) {
            return false;
        } if(c == '(') {
            push(pilha, c);
            cCount++;
        } else if(c == '{') {
            push(pilha, c);
            cCount++;
        } else if(c == '[') {
            push(pilha, c);
            cCount++;
        } else if(c == ')' && pop(pilha) != '(') {
            return false;
        } else if(c == ']' && pop(pilha) != '[') {
            return false;
        } else if(c == '}' && pop(pilha) != '{') {
            return false;
        } else if(c == ')' || c == ']' || c == '}') {
            cCount--;
        } if(ehOPerador(c))
            opCount++;
        else if(c >= 48 && c <= 57) {
            numCount++;
            while(c != '\0' && !ehOPerador(c) && c != ' ' && c != ')' && c != ']' && c != '}') {
                c = expressao[++i];
            }
            c = expressao[--i];
        } else if(c == ')' || c == '}' || c == ']') {
            if(!taOk(expressao, i))
                return false;
        }
        i++;
    }

    if(opCount != (numCount-1)) 
        return false;
    else if(cCount != 0) {
        
        return false;
    }
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