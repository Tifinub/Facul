#include <stdlib.h>
#include <stdio.h>

//definindo a estrutura de um nó
typedef struct node
{
    int data;
    struct node *ponteiro;
}
node;

//declarando o inicio e o fim da lista
node *lista = NULL;
node *final = NULL;

//Função para adicionar ao começo da lista
void AdicionarComeço(int i) {
    node *n = malloc(sizeof(node));

    n->data = i;
    n->ponteiro = NULL;
    if(lista == 0){
        final = n;
    }
    n->ponteiro = lista;
    lista = n;

    n = NULL;
    free(n);
};

//Função para adicionar ao final da lista
void AdicionarFinal(int i){
    
    if (lista == NULL){
        AdicionarComeço(i);
        return;
    }

    node *n = malloc(sizeof(node));

    n->data = i;
    n->ponteiro = NULL;

    final->ponteiro = n;
    final = n;

    n = NULL;
    free(n);
    
}

//função para imprimir lista
void ImprimirLista(){

    if(lista == NULL){
        printf("Lista vazia");
    }

    node *ptr = lista;

    while(ptr != NULL){
        printf("%i ", ptr->data);
        ptr = ptr->ponteiro;
    }
    printf("\n");
    ptr = NULL;
    free(ptr);
}

//app principal
int main(void){

    //condição do while loop
    int loop = 1;
    
    //declarando variavel para adição de numero a lista
    int num;

    //While loop para escolhar
    while (loop == 1)
    {
        int escolha;

        printf("1: Adicionar no começo\n2: Adicionar do fim\n3: Imprimir Lista\n0: Sair\n");
        scanf("%d", &escolha);


    switch (escolha)
        {
        case 1:
            printf("Numero que deseja inserir no começo da lista: ");
            scanf("%d", &num);
            AdicionarComeço(num);
            ImprimirLista();
            break;
        case 2:
            printf("Numero que deseja inserir ao final da lista: ");
            scanf("%d", &num);
            AdicionarFinal(num);
            ImprimirLista();
            break;
        case 3:
            ImprimirLista();
            break;
        case 0:
            loop = 0;
            break;
        default:
            if(escolha != 0){
            printf("Escolha não existe\n");
            }
            break;
        }
    }
}