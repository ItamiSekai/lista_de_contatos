#ifndef LISTA_CONTATOS_H_INCLUDED
#define LISTA_CONTATOS_H_INCLUDED

/// Criacao da estrutra cliente
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

/// Aborta o programa caso necessario
void abortaPrograma();

/// Gera uma lista, devolvendo li com o endereco do inicio do bloco alocado
Lista *geraLista();

/// Funcao para coleta de dados, ele preenche e retorna uma estrutura cliente
CLIENTE coletaDados();

/** Recebe uma lista e um id, fazendo uma busca pelos elementos. Podendo gerar dois casos:
/   Caso seja verdadeiro, retorna 1.
/   Caso seja falso, retorna 0;
*/
int verificaId(Lista *li, int id);

/// Insere a estrutura cliente, antes coletada, dentro da lista.
int insereOrdenado(Lista *li, CLIENTE cli);

/// Liberar memoria alocada, apagar lista
void apagaLista(Lista *li);

/// Verifica se a lista esta vazia
int listaVazia(Lista *li);

/// Listar todos os dados em forma de relatorio
void listarLista(Lista *li);

/// Busca individual por Id
void listaUnica(Lista *li, int id);

/// Busca pelo nome, podendo achar mais de um cliente
void buscaNome(Lista *li, char nome[35]);

#endif // LISTA_CONTATOS_H_INCLUDED
