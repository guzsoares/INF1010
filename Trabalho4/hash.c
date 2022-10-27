#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 1023
/*                          HEADER                      */
void liberaLL(LinkedL* list);
HashT* LinkedL_remove(LinkedL* list);
LinkedL* insereLL(LinkedL* list, HashT* item);
LinkedL* alocaLL ();
void inicializa(HashT *tab);

/*                          STRUCT                      */
//struct da hash table
typedef struct hasht{
    char* endereco;
    char* valor;
}HashT;

//lista encadeada para tratar colisoes
typedef struct linkedl{
    HashT* item; 
    LinkedL* next;
}LinkedL;


int main(void){
    int cpf[1000];
    FILE *arquivo_entrada;
    arquivo_entrada = fopen("cpf.txt", "r");
    if(!arquivo_entrada){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    leFile(arquivo_entrada, &cpf);

    fclose(arquivo_entrada);
    return 0;
}

void leFile(FILE *arquivo_entrada, int *cpf){
    int i = 0;
    while(fgets(cpf[i], sizeof(int), arquivo_entrada) !=EOF){
        printf("%d", cpf[i]);
        i++;
    }
}
/*                          FUNCOES HASH                      */
void inicializa(HashT *tab){
    for (int i = 0; i < m; i++){
        tab[i] = NULL;
    }
}



/*                          FUNCOES LINKED LIST (COLISAO)                      */
LinkedL* alocaLL (){
    // Allocates memory for a LinkedL pointer
    LinkedL* list = (LinkedL*) malloc (sizeof(LinkedL));
    return list;
}

LinkedL* insereLL(LinkedL* list, HashT* item) {
    // Inserts the item onto the Linked List
    if (!list) {
        LinkedL* head = alocaLL();
        head->item = item;
        head->next = NULL;
        list = head;
        return list;
    } 
    
    else if (list->next == NULL) {
        LinkedL* node = alocaLL();
        node->item = item;
        node->next = NULL;
        list->next = node;
        return list;
    }

    LinkedL* temp = list;
    while (temp->next->next) {
        temp = temp->next;
    }
    
    LinkedL* node = alocaLL();
    node->item = item;
    node->next = NULL;
    temp->next = node;
    
    return list;
}

HashT* LinkedL_remove(LinkedL* list) {
    // Removes the head from the linked list
    // and returns the item of the popped element
    if (!list)
        return NULL;
    if (!list->next)
        return NULL;
    LinkedL* node = list->next;
    LinkedL* temp = list;
    temp->next = NULL;
    list = node;
    HashT* it = NULL;
    memcpy(temp->item, it, sizeof(HashT));
    free(temp->item->key);
    free(temp->item->value);
    free(temp->item);
    free(temp);
    return it;
}

void liberaLL(LinkedL* list){
    LinkedL* temp = list;
    while (list) {
        temp = list;
        list = list->next;
        free(temp->item->key);
        free(temp->item->value);
        free(temp->item);
        free(temp);
    }
}