#include <stdio.h>
#include <stdlib.h>
#include "lista_contatos.h"
// Criando o conteudo da lista
struct conteudo{
    CLIENTE dados;
    struct conteudo* prox;
};
typedef struct conteudo CONT;

Lista *geraLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL){
        *li = NULL;
    }
    return li;
}

// Aborta Programa
void abortaPrograma(){
    printf("Erro! Lista nao foi alocada...");
    system("pause");
    exit(1);
}

// Funcao para coletar dados
CLIENTE coletaDados(){
    CLIENTE cli;
    printf("\nDIGITE OS DADOS DO CLIENTE:");
    printf("\n\nNUMERO DE IDENTIFICACAO: ");
    scanf("%d", &cli.id);
    printf("NOME COMPLETO..........: ");
    fflush(stdin);
    fgets(cli.nome, 34, stdin);
    printf("EMPRESA................: ");
    fflush(stdin);
    fgets(cli.empresa, 34, stdin);
    printf("DEPARTAMENTO...........: ");
    fflush(stdin);
    fgets(cli.departamento, 34, stdin);
    printf("TELEFONE FIXO..........: ");
    fflush(stdin);
    fgets(cli.telefone_fixo, 19, stdin);
    printf("CELULAR................: ");
    fflush(stdin);
    fgets(cli.celular, 19, stdin);
    printf("EMAIL..................: ");
    fflush(stdin);
    fgets(cli.email, 34, stdin);

    return cli;
}

// Consulta Usuario Por ID
int verificaId(Lista* li, int id){
    if(li == NULL){
        printf("Erro! Lista nao existe...");
        return 0;
    }
    CONT* pont = *li;
    while(pont != NULL){
        if (pont->dados.id == id){
            return 1;
        }
        pont = pont->prox;
    }
    return 0;
}

// Verifica lista vazia
int listaVazia(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}


// Insercao para a Lista
int insereOrdenado(Lista *li, CLIENTE cli){
    if(li == NULL){
        abortaPrograma();
    }
    CONT *no = (CONT*) malloc(sizeof(CONT));
    if(no == NULL){
        return 0;
    }
    no->dados = cli;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return cli.id;
    }
    else{
        CONT *ant, *atual = *li;
        while(atual != NULL && atual->dados.id < cli.id){
            ant = atual;//posiciona entre os nos
            atual = atual->prox;
        }
        //insere se estiver na proxima posicao
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }
        else{
            //insere em qualquer outra posicao
            no->prox = ant->prox;
            ant->prox = no;
        }
        return cli.id;
    }
}

// Apagar lista (liberar memoria)
void apagaLista(Lista *li){
    if(li != NULL){
       CONT *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

void listarLista(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    CLIENTE cli;
    CONT* elem = *li;
    while (elem != NULL){
        cli = elem->dados;
        printf("-------------------------------------\n");
        printf("===========DADOS DO CLIENTE==========:");
        printf("\nNUMERO DE IDENTIFICACAO: %d", cli.id);
        printf("\nNOME COMPLETO..........: %s", cli.nome);
        printf("EMPRESA................: %s", cli.empresa);
        printf("DEPARTAMENTO...........: %s", cli.departamento);
        printf("TELEFONE FIXO..........: %s", cli.telefone_fixo);
        printf("CELULAR................: %s", cli.celular);
        printf("EMAIL..................: %s", cli.email);
        printf("-------------------------------------\n");
        elem = elem->prox;
    }
}



