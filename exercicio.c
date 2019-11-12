#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}


int main() {
    int i, n, naoc = 0 , comp = 0;
    char c;

    scanf("%d", &n);
    char nomes[n][21];

    for(i = 0; i < n; i++) {
        scanf(" %c", &c);
        
        if(c == '+')
            comp++;
        else 
            naoc++;

        scanf("%s", nomes[i]);
    }
    qsort(nomes, n, 21*sizeof(char), compare);

    for(i = 0; i < n; i++) {
        printf("%s\n", nomes[i]);
    }
    printf("Se comportaram: %d | Nao se comportaram: %d\n", comp, naoc);

    return 0;
}