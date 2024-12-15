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

/******************************************************************************************
 * @brief Realiza a busca de um elemento em uma lista pelo ID fornecido.
 *
 * @param lista, Ponteiro para a lista onde será realizada a busca.
 * @param id, ID do elemento que será procurado.
 *
 * @return int, Retorna 1 se o elemento for encontrado, ou 0 caso contrário.
 ******************************************************************************************/
int verificaId(Lista *li, int id);

/******************************************************************************************
 * @brief Insere dentro da lista uma estrutura cliente ja preenchida.
 *
 * @param lista, Ponteiro para a lista onde será realizada a busca.
 * @param cli, Estrutura cliente que sera inserida.
 *
 * @return int, Retorna 1 se o elemento for encontrado, ou 0 caso contrário.
 ******************************************************************************************/
int insereOrdenado(Lista *li, CLIENTE cli);

/// Liberar memoria alocada, apagar lista
void apagaLista(Lista *li);

/// Verifica se a lista esta vazia
int listaVazia(Lista *li);

/// Listar todos os dados em forma de relatorio
void listarLista(Lista *li);

/// Busca individual por Id
void listaUnica(Lista *li, int id);

/// Mudar a string toda para minuscula
char *strlwr(char *str);

/// Busca pelo nome, podendo achar mais de um cliente
void buscaNome(Lista *li, char nome[35]);

/// Busca cliente pelo Id, coletando os dados novamente caso encontre
CLIENTE editarCliente (Lista *li, int id);

/// Remove dados da lista
int removeOrdenado(Lista *li, int id);

/// Salva dados da lista em arquivo externo
void salvaDados(Lista *li, char *arquivo);

/// carrega dos dados do arquivo e insere na lista
void carregaDados(Lista *li, char *arquivo);

#endif // LISTA_CONTATOS_H_INCLUDED
