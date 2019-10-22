#include <stdio.h>
int main() {
    int n, i, max_h = 0, max_f = 0, start, s = 0, end;

    scanf("%d", &n);
    int vetor[n];

    for(i = 0; i < n; i++)
        scanf("%d", &vetor[i]);
    for(i = 0; i < n; i++) {
        max_h += vetor[i];
        if(max_h < 0) {
            max_h = 0;
            s = i + 1;
        }
        if(max_f < max_h) {
            max_f = max_h;
            end = i;
            start = s;
        }
    }
    printf("start: %d end: %d == %d", start, end, max_f);
}