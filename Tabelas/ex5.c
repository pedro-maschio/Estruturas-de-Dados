#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long int hash(char s[]) {
    long long int  hash, i;
    for(hash = i = 0; i < strlen(s); ++i)
    {
        hash += s[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    return hash%5381;
}
int main() {
    int i, n;

    scanf("%d", &n);
    char s[n][21];
    int *vetor = (int *) calloc(10000, sizeof(int));

    for(i = 0; i < n; i++) {
        scanf("%s", s[i]);
        vetor[hash(s[i])]++;
    }
    for(i = 0; i < n; i++) {
        if(vetor[hash(s[i])] >= 0) {
            printf("%s %d\n", s[i], vetor[hash(s[i])]-1);
            vetor[hash(s[i])] = -1;
        }
    }
    return 0;
}