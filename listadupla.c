#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct no{
    int codigo;
    char nome[20];
    struct no *next;
    struct no *back;
}no;

struct no *inicio = NULL;
struct no *auxiliar = NULL;
struct no *auxiliar2 = NULL;
struct no *corrente = NULL;
struct no *fim = NULL;


void enterdata(){
    printf("Insira o Nome: \n");
    scanf("%s", &corrente->nome);
    printf("\n Insira o codigo: \n");
    scanf("%d", &corrente->codigo);
}

/*void insert(){
    if(inicio == NULL){
        corrente = (no*)malloc(sizeof(no));
        auxiliar = corrente;
        inicio = corrente;
        fim = corrente;
        corrente->next = NULL;
        corrente->back = NULL;
        enterdata();
    }else{
        corrente = (no*)malloc(sizeof(no));
        auxiliar->next = corrente;
        corrente->back = auxiliar;
        corrente->next = NULL;
        auxiliar = corrente;
        fim = corrente;
        enterdata();
    }

}*/

void inserir(){
    int achou = 0;

    corrente = (no*)malloc(sizeof(no));

    enterdata();

    corrente->next = NULL;
    corrente->back = NULL;

    auxiliar = inicio;

    // Lista vazia
    if(inicio == NULL){
        inicio = corrente;
        fim = corrente;

        printf("Inserido primeiro elemento\n");
        return;
    }

    // Inserir no começo
    if(strcmp(corrente->nome, auxiliar->nome) <= 0){
        corrente->next = auxiliar;
        corrente->back = NULL;

        auxiliar->back = corrente;

        inicio = corrente;

        printf("Inserido no comeco da lista\n");
        return;
    }

    // Procurar posição no meio
    auxiliar2 = auxiliar->next;

    while(auxiliar2 != NULL){

        if(strcmp(corrente->nome, auxiliar->nome) > 0 &&
           strcmp(corrente->nome, auxiliar2->nome) <= 0){

            auxiliar->next = corrente;
            corrente->back = auxiliar;

            corrente->next = auxiliar2;
            auxiliar2->back = corrente;

            achou = 1;

            printf("Inserido no meio da lista\n");
            break;
        }

        auxiliar = auxiliar->next;
        auxiliar2 = auxiliar2->next;
    }

    // Inserir no final
    if(achou == 0){
        auxiliar->next = corrente;
        corrente->back = auxiliar;
        corrente->next = NULL;

        fim = corrente;

        printf("Inserido no final da lista\n");
    }
}


void listar(){
    if(inicio == NULL){
        printf("Lista Vazia");
    }else{
        auxiliar = inicio;
        while(auxiliar !=NULL){
            printf("Cod: %d \n", auxiliar->codigo);
            printf("Nome: %s \n", auxiliar->nome);
            auxiliar = auxiliar->next;
        }
        printf("\n \n");
    }

}

void listarReverso(){
    if(inicio == NULL){
        printf("Lista Vazia");
    }else{
        auxiliar = fim;
        while(auxiliar != NULL){
            printf("Cod: %d \n", auxiliar->codigo);
            printf("Nome: %s \n", auxiliar->nome);
            auxiliar = auxiliar->back;
        }
        printf("\n \n");
    }
}

void excluir(){
    if(inicio == NULL){
        printf("Lista Vazia");
    }else{
        auxiliar = inicio;
        int rm = 0;
        printf("Codigo a ser removido: \n");
        scanf("%d", &rm);

        //procura o nó
        while(auxiliar->codigo != rm){
            auxiliar = auxiliar->next;
        }

        if(auxiliar == NULL){
            printf("Codigo não encontrado");
        }


        // Verificando se existe um nó anterior
        if(auxiliar->back != NULL){
            auxiliar->back->next = auxiliar->next;
        }else{
            // se não, é o primeiro da lista
            inicio = auxiliar->next; //nó posterior vira o primeiro
        }

        // Se existe um nó posterior
        if(auxiliar->next != NULL){
            auxiliar->next->back = auxiliar->back;
           //auxiliar->next->back é como se fosse ponteiroAnterior->back
        }else{
            // se não, é o ultimo da lista
            fim = auxiliar->back; //nó anterior vira o ultimo
        }

        printf("Usuário %s removido! \n", auxiliar->nome);
        free(auxiliar);


        //o next do ponteiro anterior tem q apontar para o valor do next do ponteiro a ser removido
        //o back do proximo ponteiro tem q apontar para o valor do back do ponteiro a ser removido

    }
}


void editar(){
    if(inicio == NULL){
        printf("Lista Vazia");
    }else{
        auxiliar = inicio;
        int busca = 0;
        printf("Insira o Código que deseja alterar: \n");
        scanf("%d", &busca);

        while(auxiliar->codigo != busca){
            auxiliar = auxiliar->next;
            corrente = auxiliar;
        }
        if(auxiliar == NULL){
            printf("Não encontrado!");
        }else{
            printf("Registro a ser Modificado: \n");
            printf("Codigo %d \n", corrente->codigo);
            printf("Nome: %s \n", corrente->nome);
            printf("------------------------------ \n");
            printf("Novo Nome:  ");
            scanf("%s", &corrente->nome);
        }

    }


}

void buscar(){
    if(inicio == NULL){
        printf("Lista Vazia");
    }else{
        int opBusca = 0;
        int codBusca = 0;

        printf("Escolha o tipo de Busca: \n");
        printf("------------------------ \n");
        printf("(1) - Busca Padrão \n");
        printf("(2) - Busca Reversa \n");
        scanf("%d", &opBusca);
        if(opBusca == 1){
            auxiliar = inicio;
            printf("Qual o codigo para busca: \n");
            scanf("%d", &codBusca);
            while(auxiliar->codigo != codBusca){
                auxiliar = auxiliar->next;
                corrente = auxiliar;
            }
            if(auxiliar == NULL){
                printf("Não encontrado!");
            }else{
                printf("Registros Encontrados: \n");
                printf("Codigo: %d \n", corrente->codigo);
                printf("Nome: %s \n", corrente->nome);
                printf("-----------------------\n");
            }
        }else if(opBusca == 2){
            auxiliar = fim;
            printf("Qual o codigo para busca: \n");
            scanf("%d", &codBusca);
            while(auxiliar->codigo != codBusca){
                auxiliar = auxiliar->back;
                corrente = auxiliar;
            }
            if(auxiliar == NULL){
                printf("Não encontrado!");
            }else{
                printf("Registros Encontrados: \n");
                printf("Codigo: %d \n", corrente->codigo);
                printf("Nome: %s \n", corrente->nome);
                printf("-----------------------\n");
            }
        }
    }

}


int main(){
    int op = 0;
    while(op != 7){
        printf("(1) - Inserir \n");
        printf("(2) - Listar \n");
        printf("(3) - Listar Reverso \n");
        printf("(4) - Excluir \n");
        printf("(5) - Editar \n");
        printf("(6) - Buscar \n");
        printf("(7) - Sair \n");

        printf("Escolha: ");
        scanf("%d", &op);

        switch(op){
        case 1:
            system("clear");
            inserir();
            break;
        case 2:
            system("clear");
            listar();
            break;
        case 3:
            system("clear");
            listarReverso();
            break;
        case 4:
            system("clear");
            excluir();
            break;
        case 5:
            system("clear");
            editar();
            break;
        case 6:
            system("clear");
            buscar();
            break;
        case 7:
            break;
        default:
            system("clear");
            printf("OP invalida");
            break;
        }
    }
}
