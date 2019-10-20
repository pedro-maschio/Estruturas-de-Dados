#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct element_t{
    int prioridade;
    char atividade[100];
    struct element_t* next;
} element_t;

typedef struct {
    element_t* first;
    element_t* last;
    int tamanho;
} queue_t;


//-----------------------------------------------------------------
_Bool isEmpty(queue_t* queue){
    return(queue && queue->first == NULL && queue->last == NULL);
}//end isEmpty()


//-----------------------------------------------------------------
element_t* get_element(int prioridade, char* atividade){
    element_t* e = (element_t *) malloc(sizeof(element_t));

    e->prioridade = prioridade;
    strcpy(e->atividade, atividade);
    e->next = NULL;

    return e;
}//end get_element()


//-----------------------------------------------------------------
queue_t* get_queue(){
    queue_t* f = (queue_t *) malloc(sizeof(queue_t));

    f->first   = NULL;
    f->last    = NULL;
    f->tamanho = 0;

    return f;
}//end get_queue()


//-----------------------------------------------------------------
_Bool enqueue(queue_t* queue,int prioridade, char* atividade){
    element_t* e = get_element(prioridade, atividade);

    if(!e)
        return false;

    if(isEmpty(queue)){
        queue->first = e;
        queue->last  = queue->first;
    }else{
        queue->last->next = e;
        queue->last       = e;
    }

    queue->tamanho++;
    return true;
}//end enqueue()


//-----------------------------------------------------------------
_Bool dequeue(queue_t* queue){
    element_t* e = NULL;

    if(isEmpty(queue))
        return false;

    e = queue->first;

    if(queue->first == queue->last){
        queue->first = NULL;
        queue->last  = NULL;
    }else{
        queue->first = queue->first->next;
    }

    queue->tamanho--;
    free(e);
    return true;
}//end dequeue()


//-----------------------------------------------------------------
_Bool get_head(queue_t* queue, int* prioridade, char* atividade){
    if(isEmpty(queue))
        return false;

    *prioridade = queue->first->prioridade;
    strcpy(atividade, queue->first->atividade);
    return true;
}//end get_head()


//-----------------------------------------------------------------
void free_queue(queue_t* queue){
    element_t* aux = NULL;

    if(!queue)
        return;

    aux = queue->first;

    while(queue->first){
        queue->first = queue->first->next;

        free(aux);

        aux = queue->first;
    }

}//end free_queue()


//-----------------------------------------------------------------
void print(queue_t *queue) {
    element_t* e = NULL;

    if(isEmpty(queue))
        return;

    e = queue->first;

    //iterando na pilha
    while(e) {
        printf("Atividade: %s Prioridade: #%d \n", e->atividade, e->prioridade);
        e = e->next;
    }
}

_Bool verifica_se_numero(char* str){

    if(str[0] <= 57 && str[0] >= 48)
        return true;

    return false;
}




int main() {
    queue_t* queue[10];
    char entrada[200];
    char delim[]   = " ";
    char *ptr      = NULL;
    int prioridade;
    char atividade[200];
    int qt, tamanho;

    for(int i = 0; i < 10; i++)
        queue[i] = get_queue();

    scanf("%[^\n]s", entrada);

    ptr = strtok(entrada, delim);

    while(ptr != NULL){

        if(verifica_se_numero(ptr)){
            sscanf(ptr, "%d", &prioridade);
            enqueue(queue[prioridade-1], prioridade, atividade);
        }else{
            strcpy(atividade, ptr);
        }

        ptr = strtok(NULL, delim);
    }

    scanf("%d", &qt);

    if(qt > 0) {
        for (int i = 0; i < 10; i++) {
            tamanho = queue[i]->tamanho;
            for (int j = 0; j < tamanho; j++) {
                dequeue(queue[i]);
                qt--;

                if (qt == 0)
                    break;
            }

            if (qt == 0)
                break;

        }
    }

    tamanho  = 0;
    for (int i = 0; i < 10; i++){
        tamanho += queue[i]->tamanho;
    }

    printf("Tamanho da fila: %d\n", tamanho);
    for (int i = 0; i < 10; i++){
        print(queue[i]);
    }


    for(int i = 0; i < 10; i++)
        free_queue(queue[i]);

    return 0;
}