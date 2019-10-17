/** Matricula: 190018763
 *       Nome: Pedro de Tôrres Maschio
 *      Turma: A */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int top;
    char *elementos;
} Pilha;

// Seta o top da pilha
Pilha* iniciaPilha() {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    pilha->top = -1;
    pilha->elementos = malloc(201*sizeof(char));

    return pilha;
}

int taVazia(Pilha *pilha) {
    return pilha->top == -1;
}

char push(Pilha *pilha, char elemento) {
    pilha->elementos[++pilha->top] = elemento;

    return elemento;
}

char pop(Pilha *pilha) {
    return pilha->elementos[pilha->top--];
}

char peek(Pilha *pilha) {
    return pilha->elementos[pilha->top];
}

// Precedencia na pilha
int precedencia(char elemento) {
    if(elemento == '-' || elemento == '+')
        return 2;
    else if(elemento == '/' || elemento == '*')
        return 4;
    else if(elemento == '^')
        return 5;
    else if(elemento == '(')
        return 0;
    return 0;
}

// Precedencia fora da pilha
int foraPrec(char elemento) {
    if(elemento == '+' || elemento == '-') 
        return 1; 
    else if(elemento == '*' || elemento == '/')  
        return 3; 
    else if(elemento == '^') 
        return 6; 
    else if(elemento == '(') 
        return 100; 
}

int ehOperador(char el) {
    if(el == '+' || el == '-' || el == '/' || el == '*' || el == '^' || el == '(')
        return 1;
    return 0;
}

/* Mudei a assinatura da funcao pois ficava mais facil ir 
imprimindo do que preencher a string de resultado :)
*/
void transforma(const char* infixa, Pilha *pilha) {
    int i;
    for(i = 0; i < strlen(infixa); i++) {
        char c = infixa[i];
        if(c >= 48 && c <= 57) {
            while((c >= 48 && c <= 57) || c == '.') {
                printf("%c", c);
                i++;
                c = infixa[i];
            }
            printf(" ");
        i--;
        } else if(ehOperador(c)) {
            if(taVazia(pilha) || (foraPrec(c) > precedencia(peek(pilha)))) {
                push(pilha, c);
            } else {
                while(!taVazia(pilha) && (foraPrec(c) < precedencia(peek(pilha)))) {
                    printf("%c ", pop(pilha));
                }
                push(pilha, c);
            }
        } else if(c == ')') {
            while(peek(pilha) != '(') {
                printf("%c ", pop(pilha));

                if(taVazia(pilha)) {
                    return;
                }
            }
            pop(pilha);
        }
    }

    while(!taVazia(pilha)) {
        if(peek(pilha) == '(') {
            return;
        }
        printf("%c ", pop(pilha));
    }
}


int main() {
    char infixa[101], posfixa[201];
    Pilha *pilha = iniciaPilha();

    scanf("%100[^\n]", infixa);

    transforma(infixa, pilha);

    return 0;
}