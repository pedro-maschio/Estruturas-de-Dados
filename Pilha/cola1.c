#include <stdio.h>
#include <string.h>

int main () {
    char str[256], palin1[5], palin2[5];
    int num = 0, i = 1, j;

    while(scanf("%s", str) != EOF) {
        palin1[4] = palin2[4] = '\0';

        num = 0;
        i = 1;

        while(str[i] != '\0') {
            /* busca de 3 em 3 */
            while(str[i-1] == str[i+1] && strlen(str) > 3) {
                if (num == 0) {
                    j = 1;
                    palin1[j] = str[i];
                    palin1[j-1] = str[i-1];
                    palin1[j+1] = str[i+1];
                    palin1[j+2] = '\0';
                    num++;
                }
                else {
                	if(num == 1) {
	                    j = 1;
	                    palin2[j] = str[i];
	                    palin2[j-1] = str[i-1];
	                    palin2[j+1] = str[i+1];
	                    palin2[j+2] = '\0';
	                    num++;
	                }
	            }

                i++;
            }
            /* Busca de 2 em 2 */
            while(str[i-1] == str[i] && strlen(str) > 3) {
                if (num == 0) {
                    j = 1;
                    palin1[j] = str[i];
                    palin1[j-1] = str[i-1];
                    palin1[j+1] = str[i+1];
                    palin1[j+2] = str[i+2];
                    num++;
                } else {
                	if(num == 1) {
	                    j = 1;
	                    palin2[j] = str[i]; palin2[j-1] = str[i-1];
	                    palin2[j+1] = str[i+1]; palin2[j+2] = '\0';
	                    num++;
	                }
	            }

                i++;
            }
            i++;

            /* Mostrar palavra com 2-palindromes */
            if (num == 2) {
                if (strcmp(palin1, palin2) != 0) {
                    j = 0;
                    while(str[j] != ' ' && str[j] != '\0') {
                        putchar(str[j]);
                        j++;
                    }
                    putchar('\n');
                } else {
                	if (strcmp(palin1, palin2) == 0)
                    	 num--;
                }

                while(str[i] != ' ' && str[i] != '\0')
                    i++;
            }
        }
    }

return 0;
}