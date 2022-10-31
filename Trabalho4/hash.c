#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//448.403.418-26 --> size = 14

#define HASH_SIZE 1023
#define DATA_SIZE 1000
#define CPF_SIZE 5     /*  nao conta com o "\n"  numero de digitos = 11 numero de caracteres = 14(contando com . e - )*/





/*__________________________________________________________________________*/
void inicializaTabela(long *tabelaHash);
int mandaChave(long cpf, int k);

/*__________________________________________________________________________*/

int main(void){
    long tabelaHash[HASH_SIZE];
    long auxLeitura = 0;
    int chave = 0;

    FILE *arquivo_entrada = fopen("cpf.txt", "r");
    if(!arquivo_entrada){
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    inicializaTabela(tabelaHash);

    while(!feof(arquivo_entrada)){
        fscanf(arquivo_entrada, "%ld", &auxLeitura);
        int k = -1;

        do{
            chave = mandaChave(auxLeitura, k++);
        }while(tabelaHash[chave] != -1);
        
        tabelaHash[chave] = auxLeitura;
    }

    //esse for e so pra testar ate onde ta funcionando
    for(int z = 1; z < HASH_SIZE; z++){
        if(tabelaHash[z] != -1){
            printf("%ld -- %d\n", tabelaHash[z], z);
        }
    }

    fclose(arquivo_entrada);
    return 0;
}

//funcao coloca tudo com -1 pra facilitar verificacao se ta vazio ou n, ja q -1 nao e um valor possivel
void inicializaTabela(long *tabelaHash){
    for(int i = 1; i< HASH_SIZE; i++){
        tabelaHash[i] = -1;
    }
}
int mandaChave(long cpf, int k){
    int chave = 0;

    chave = (cpf + k) % DATA_SIZE;

    return chave;
}
