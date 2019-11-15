#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char str[100000];
    int i, freq[26], aux[26], flag = 0, k = 0;
    for(i = 0; i < 26; i++)
        freq[i] = aux[i] = 0;

    scanf("%s", str);

    for(i = 0; i < strlen(str); i++) 
        freq[str[i]-'a']++;

    for(i = 0; i < 25; i++) {
        if(freq[i] > 0) {
            aux[k] = freq[i];
            k++;
        }
    }
    for(i = 0; i < k-1; i++) {
        if(aux[i] == aux[i+1])
            flag++;
        else 
            flag--;
    }
    if(flag == k-1 || flag == k-2)
        printf("YES");
    else 
        printf("NO");
    
    return 0;
}