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
        return 1;
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
        return 1;
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
        cli = elem->dados;
        printf("\n-------------------------------------\n");
        printf("===========DADOS DO CLIENTE==========");
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
    if (elem == NULL){
        printf("\nErro ao procurar cadastro...\n");
    }
}

// So para colocar todas as letras em minusculas
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

// Busca usuario pelo id, possibilitando edicao dos seus dados
CLIENTE editarCliente (Lista *li, int id){
    if(li == NULL){
        abortaPrograma();
    }
    CLIENTE cli;
    CONT* elem = *li;
    char escolha;
    while (elem != NULL){
        cli = elem->dados;
        if (id == cli.id){ // Procura usuario por id
            listaUnica(li, id); // Mostra os dados ao usuario
            printf("\nDeseja realmente alterar os dados?(S/N): ");
            scanf(" %c", &escolha);
            if(escolha == 'S' || escolha == 's'){

                removeOrdenado(li, id); // Remove primeiro para poder colocar outro no lugar
                cli = coletaDados(); // Apos remover, coleta os dados da edicao

                if (insereOrdenado(li, cli)){ // Verifica a insercao
                    system("cls");
                    printf("\nUsuario alterado com sucesso!!\n\n");
                    break;
                }
                else{
                    printf("Erro ao editar... \n");
                }
                break;
            }
            // Caso o usuario digite qualquer outra coisa ele retorna ao menu
            printf("Retornando ao menu...\n\n");
            break;
        }
        elem = elem->prox;
    }
    // Caso nao ache o id
    if (elem == NULL){
        printf("\nErro ao procurar cadastro...\n");
    }
}

// Remove dados procurando pelo id
int removeOrdenado(Lista *li, int id){
    int identificao;
    if(li == NULL){
        abortaPrograma();
    }
    CONT *ant, *no = *li;
    while(no != NULL && no->dados.id != id){ // Procura o id
        ant = no;
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no == *li){
        *li = no->prox;
    }
    else{
        ant->prox = no->prox;
    }
    identificao = no->dados.id;
    free(no); // Libera a memoria alocada, apagando os dados da lista com aquele id
    return 1;
}

// Salva dados em arquivo externo
void salvaDados(Lista *li, char *arquivo) {
    listaVazia(li);

    // Abrir o arquivo em modo de escrita binária
    FILE *f = fopen(arquivo, "wb");
    if (f == NULL) { // Aviso caso nao abra
        printf("\nErro ao abrir o arquivo para escrita...\n\n");
        system("pause");
        return;
    }

    CONT *elem = *li;

    // Percorre a lista e grava cada cliente no arquivo
    while (elem != NULL) {
        if (fwrite(&elem->dados, sizeof(CLIENTE), 1, f) != 1) {
            printf("\nErro ao salvar dados...\n\n");
            fclose(f);
            return;
        }
        elem = elem->prox;
    }

    fclose(f);
}

// Abre arquivo no inicio do programa
void carregaDados(Lista *li, char *arquivo) {

    // Abrir o arquivo em modo de leitura binária
    FILE *f = fopen(arquivo, "rb");
    if (f == NULL) {
        printf("Nenhum arquivo encontrado....\n\n");
        return;
    }

    CLIENTE cli;
    // Le os dados e insere dentro da lista
    while (fread(&cli, sizeof(CLIENTE), 1, f) == 1) {
        insereOrdenado(li, cli);
    }

    fclose(f);
}


