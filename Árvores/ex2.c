typedef struct ab_int {
    int dado;
    struct ab_int *esq;
    struct ab_int *dir;
} ab_int;
int altura(ab_int *raiz) {
    if(!raiz)   
        return 0;
    else {
        int alturaEsq =  altura(raiz->esq);
        int alturaDir = altura(raiz->dir);

        if(alturaEsq > alturaDir)
            return (alturaEsq + 1);
        else 
            return (alturaDir + 1);
    }
}
int main() {


    return 0;
}