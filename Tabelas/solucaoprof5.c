#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 1000
#define MAX_NOME 20

int primeira_ocorrencia(char* nome, char nomes[][MAX_NOME], int n) {
	int i;
	for (i = 0; i < n; ++i) {
		if (0 == strcmp(nomes[i], nome)) {
			return i;
		}
	}
	return -1;
}

int main() {
	char nomes[MAX_ALUNOS][MAX_NOME];
	int repeticoes[MAX_ALUNOS] = {0};
	int n, i, j, distintos = 0;
	char nome[MAX_NOME];

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s", nome);

		j = primeira_ocorrencia(nome, nomes, distintos);
		if (j >= 0) {
			repeticoes[j]++;
		} else {
			strcpy(nomes[distintos], nome);
			++distintos;
		}
	}

	for (i = 0; i < distintos; ++i) {
		printf("%s %d\n", nomes[i], repeticoes[i]);
	}

    return 0;
}
