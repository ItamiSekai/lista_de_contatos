#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "lista_contatos.h"

// Criando o conteudo da lista
struct conteudo{
    CLIENTE dados;
    struct conteudo* prox;
};
typedef struct conteudo CONT;

// Cria lista
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
    cli.nome[strcspn(cli.nome, "\n")] = '\0';
    printf("EMPRESA................: ");
    fgets(cli.empresa, 34, stdin);
    cli.empresa[strcspn(cli.empresa, "\n")] = '\0';
    printf("DEPARTAMENTO...........: ");
    fgets(cli.departamento, 34, stdin);
    cli.departamento[strcspn(cli.departamento, "\n")] = '\0';
    printf("TELEFONE FIXO..........: ");
    fgets(cli.telefone_fixo, 19, stdin);
    cli.telefone_fixo[strcspn(cli.telefone_fixo, "\n")] = '\0';
    printf("CELULAR................: ");
    fgets(cli.celular, 19, stdin);
    cli.celular[strcspn(cli.celular, "\n")] = '\0';
    printf("EMAIL..................: ");
    fgets(cli.email, 34, stdin);
    cli.email[strcspn(cli.email, "\n")] = '\0';

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

// Listagem como relatorio
void listarLista(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    CLIENTE cli;
    CONT* elem = *li;
    while (elem != NULL){
        printf("\n-------------------------------------\n");
        printf("===========DADOS DO CLIENTE==========:");
        printf("\nNUMERO DE IDENTIFICACAO: %d", cli.id);
        printf("\nNOME COMPLETO..........: %s", cli.nome);
        printf("\nEMPRESA................: %s", cli.empresa);
        printf("\nDEPARTAMENTO...........: %s", cli.departamento);
        printf("\nTELEFONE FIXO..........: %s", cli.telefone_fixo);
        printf("\nCELULAR................: %s", cli.celular);
        printf("\nEMAIL..................: %s", cli.email);
        printf("\n-------------------------------------\n");
        elem = elem->prox;
    }
}

// Lista uma unica vez, buscando o elemento pelo ID
void listaUnica(Lista *li, int id){
    if(li == NULL){
        abortaPrograma();
    }
    CLIENTE cli;
    CONT* elem = *li;
    while (elem != NULL){
        cli = elem->dados;
        if (id == cli.id){
            printf("\n-------------------------------------\n");
            printf("===========DADOS DO CLIENTE==========:");
            printf("\nNUMERO DE IDENTIFICACAO: %d", cli.id);
            printf("\nNOME COMPLETO..........: %s", cli.nome);
            printf("\nEMPRESA................: %s", cli.empresa);
            printf("\nDEPARTAMENTO...........: %s", cli.departamento);
            printf("\nTELEFONE FIXO..........: %s", cli.telefone_fixo);
            printf("\nCELULAR................: %s", cli.celular);
            printf("\nEMAIL..................: %s", cli.email);
            printf("\n-------------------------------------\n");
            break;
        }
        elem = elem->prox;
    }
    printf("\nErro ao procurar cadastro...\n");
}

// Colocando todas em letras minusculas
char *strlwr(char *str) {
    char *p = str;
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
    return p;
}

// Lista o cliente buscando pelo nome
void buscaNome(Lista *li, char nome[35]){
    if(li == NULL){
        abortaPrograma();
    }
    CONT *elem = *li;
    char cliMinus[35];
    char nomeMinus[35];

    strcpy(nomeMinus, nome);
    strlwr(nomeMinus);

    while (elem != NULL){
        CLIENTE cli = elem->dados;
        strcpy(cliMinus, cli.nome);
        strlwr(cliMinus);

        if (strstr(cliMinus, nomeMinus) != NULL){
            printf("\n-------------------------------------\n");
            printf("===========DADOS DO CLIENTE==========:");
            printf("\nNUMERO DE IDENTIFICACAO: %d", cli.id);
            printf("\nNOME COMPLETO..........: %s", cli.nome);
            printf("\nEMPRESA................: %s", cli.empresa);
            printf("\nDEPARTAMENTO...........: %s", cli.departamento);
            printf("\nTELEFONE FIXO..........: %s", cli.telefone_fixo);
            printf("\nCELULAR................: %s", cli.celular);
            printf("\nEMAIL..................: %s", cli.email);
            printf("\n-------------------------------------\n");
        }
        elem = elem->prox;
    }
}



