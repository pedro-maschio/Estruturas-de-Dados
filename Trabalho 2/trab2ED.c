#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXELS 1024

typedef struct Qua {
    char cor;
    struct Qua *next[4];
} Qua;

Qua* criaFolha(char c) {
    Qua *novo = (Qua *) malloc(sizeof(Qua));
    if(!novo)
        return NULL;
    novo->next[0] = novo->next[1] = novo->next[2] = novo->next[3] = NULL;
    novo->cor = c;

    return novo;
}

void mostra_arvore(Qua **raiz){
    Qua *temp = *raiz;
    printf("(");

    if(temp){
        printf("%c ",temp->cor);
        mostra_arvore(&temp->next[0]);
        printf(" ");
        mostra_arvore(&temp->next[1]);
        printf(" ");
        mostra_arvore(&temp->next[2]);
        printf(" ");
        mostra_arvore(&temp->next[3]);
    }

    printf(")");
}

Qua* montaArvore(char str[], Qua *arvore, int *pos) {
    (*pos)++;
    if(str[*pos] == '\0')   
        return arvore;
    if(!arvore) {
        arvore = criaFolha(str[*pos]);

        arvore->cor = str[*pos];
    }
    if(str[*pos] == 'p') {
        
        int i = 0;
        while(i < 4) {
            arvore->cor = 'p';
            arvore->next[i] = montaArvore(str, arvore->next[i], pos);
            
            i++;
        }
    }

    return arvore;
}

int acabou(Qua *arv1) {
    if(!arv1->next[0] && !arv1->next[1] && !arv1->next[2] && !arv1->next[3])
        return 1;
    else 
        return 0;
}

int mesclaArvore(Qua *arv1, Qua *arv2, int maxpixels) {
    if(arv1->cor == 'f' || arv2->cor == 'f')
        return maxpixels;

    if(acabou(arv1) && acabou(arv2))
        return 0;



    int i = 0, pixels = 0;
    while(i < 4) {
        // percorre as duas, uma so ou so a outra
        if(!acabou(arv2) && !acabou(arv1)) {
            pixels += mesclaArvore(arv1->next[i], arv2->next[i], maxpixels / 4);
        } else if(acabou(arv1)) {
            pixels += mesclaArvore(arv1, arv2->next[i], maxpixels / 4);
        } else {
            pixels += mesclaArvore(arv1->next[i], arv2, maxpixels / 4);
        }
        i++;
    }
    return pixels;
}

int main() {
    char str1[5000], str2[5000];
    Qua *arvore1 = NULL;
    Qua *arvore2 = NULL;

    int i = -1;

    scanf("%s", str1);
    scanf("%s", str2);
    
    arvore1 = montaArvore(str1, arvore1, &i);
    i = -1;
    arvore2 = montaArvore(str2, arvore2, &i);

    mostra_arvore(&arvore1);
    printf("\n\n");
    mostra_arvore(&arvore2);
    printf("\n\n");

    int numpixels = mesclaArvore(arvore1, arvore2, MAX_PIXELS);
    printf("%d\n", numpixels);

}