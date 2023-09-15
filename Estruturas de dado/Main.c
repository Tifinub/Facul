#include <stdio.h>
#include <stdlib.h>

// Estrutura do Nó

typedef struct node
{
    int data;
    struct node *ponteiro;
}
node;


int main (int argc,char *argv[]){

node *list = NULL;

    for(int i = 1; i < argc; i++){

        int num = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if(n == NULL){
            return 1;
        }
        n->data = num;
        n->ponteiro = NULL;

        n->ponteiro = list;
        list = n;

    }
    node *ptr = list;

    while(ptr != NULL){
        printf("%i\n", ptr->data);
        ptr = ptr->ponteiro;
    }

    ptr = list;

    while(ptr != NULL){
        node *prox = ptr->ponteiro;
        free(ptr);
        ptr = prox;
    }
    return 0;
}
