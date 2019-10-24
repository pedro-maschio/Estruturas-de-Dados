#include <stdio.h>
#include <string.h>
int TAM_MAX;

typedef struct {
    unsigned int num_elementos;
    char dados[2][50];
} tab_disp_str;

int hash(int chave) {

}

char *busca(tab_disp_str* tabela, int chave) {
    if(tabela->dados[hash(chave)][0] != '\0')
        return tabela->dados[hash(chave)];
    else 
        return NULL;
}
int main() {
    tab_disp_str tabela;

}