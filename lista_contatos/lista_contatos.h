#ifndef LISTA_CONTATOS_H_INCLUDED
#define LISTA_CONTATOS_H_INCLUDED

// Criacao da estrutra cliente
typedef struct cliente{
    int id;
    char nome[35];
    char empresa[35];
    char departamento[35];
    char telefone_fixo[20];
    char celular[20];
    char email[35];
}CLIENTE;

// Mudando o nome para ficar mais intuitivo no Main
typedef struct conteudo* Lista;

// Aborta o programa caso necessario
void abortaPrograma();

// Gera uma lista, devolvendo li com o endereco do inicio do bloco alocado
Lista *geraLista();

// Funcao para coleta de dados, ele preenche e retorna uma estrutura cliente
CLIENTE coletaDados();

// Recebe uma lista e um id, fazendo uma busca pelos elementos, caso ele ache retorna 1, se nao retorna 0
int verificaId(Lista *li, int id);

// Insere a estrutura cliente, antes coletada, dentro da lista.
int insereOrdenado(Lista *li, CLIENTE cli);

// Liberar memoria alocada, apagar lista
void apagaLista(Lista *li);


#endif // LISTA_CONTATOS_H_INCLUDED
