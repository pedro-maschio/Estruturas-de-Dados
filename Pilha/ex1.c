#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ehPalindromo(char s[]) {
    int i, count = 0;
    for(i = 0; i < strlen(s); i++) {
        if(s[i] == s[strlen(s)-i-1])
            count++;
    }
    if(count == strlen(s))
        return 1;
    else 
        return 0;
}
int main() {
    char s[256], aux[4];
    int i, j, k, count = 0;


    while(scanf("%s", s) != EOF) {
        for(i = 0; i < strlen(s); i++) {
            k = 0;
            for(j = i; j < (i+3); j++) {
                aux[k] = s[j];
                k++;
            }
            aux[k+1] = '\0';;
            if(ehPalindromo(aux) && strlen(aux) > 2) {
                count++;
            }
        }
        if(count >= 2)
            printf("%s\n", s);
        count = 0;
    }
    return 0;
}