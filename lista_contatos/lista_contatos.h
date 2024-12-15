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

/******************************************************************************************
 * Gera uma lista dinamica, devolvendo o comeco do bloco alocado.
 *
 *  Retorna um ponteiro para a lista gerada.
 ******************************************************************************************/
Lista *geraLista();

/******************************************************************************************
 * Função para coleta de dados, coleta e devolve os dados em uma estrutra cliente.
 *
 * Retorna uma estrutura cliente preenchida.
 ******************************************************************************************/
CLIENTE coletaDados();

/******************************************************************************************
 * Realiza a busca de um elemento em uma lista pelo ID fornecido.
 *
 * li, Ponteiro para a lista onde será realizada a busca.
 * id, ID do elemento que será procurado.
 *
 * int, Retorna 1 se o elemento for encontrado, ou 0 caso contrário.
 ******************************************************************************************/
int verificaId(Lista *li, int id);

/******************************************************************************************
 * Insere dentro da lista uma estrutura cliente ja preenchida.
 *
 * lista, Ponteiro para a lista onde será realizada a busca.
 * cli, Estrutura cliente que sera inserida.
 *
 * int, Retorna 1 se o elemento for encontrado, ou 0 caso contrário.
 ******************************************************************************************/
int insereOrdenado(Lista *li, CLIENTE cli);

/******************************************************************************************
 * Libera a memória alocada e apaga a lista.
 *
 * li, Ponteiro para a lista que será liberada.
 ******************************************************************************************/
void apagaLista(Lista *li);

/******************************************************************************************
 * Verifica se a lista está vazia.
 *
 * li, Ponteiro para a lista a ser verificada.
 *
 * int, Retorna 1 se a lista estiver vazia, ou 0 caso contrário.
 ******************************************************************************************/
int listaVazia(Lista *li);

/******************************************************************************************
 * Lista todos os dados em forma de relatório.
 *
 * li, Ponteiro para a lista a ser listada. Mostrando os dados da lista.
 ******************************************************************************************/
void listarLista(Lista *li);

/******************************************************************************************
 * Busca individual por ID.
 *
 * li, Ponteiro para a lista onde será realizada a busca.
 * id, ID do cliente que será buscado.
 ******************************************************************************************/
void listaUnica(Lista *li, int id);

/******************************************************************************************
 * Muda a string toda para minúscula.
 *
 * str, Ponteiro para a string a ser convertida.
 *
 * Retorna um ponteiro para a string convertida.
 ******************************************************************************************/
char *strlwr(char *str);

/******************************************************************************************
 * Busca pelo nome, podendo encontrar mais de um cliente.
 *
 * li, Ponteiro para a lista onde será realizada a busca.
 * nome, Nome a ser buscado na lista.
 ******************************************************************************************/
void buscaNome(Lista *li, char nome[35]);

/******************************************************************************************
 * Busca cliente pelo ID, coletando os dados novamente caso encontre.
 *
 * li, Ponteiro para a lista onde será realizada a busca.
 * id, ID do cliente a ser buscado.
 *
 * CLIENTE, Retorna a estrutura cliente encontrada.
 ******************************************************************************************/
CLIENTE editarCliente(Lista *li, int id);

/******************************************************************************************
 * Remove dados da lista pelo ID.
 *
 * li, Ponteiro para a lista onde será realizada a remoção.
 * id, ID do cliente a ser removido.
 *
 * int, Retorna 1 se a remoção for bem-sucedida, ou 0 caso contrário.
 ******************************************************************************************/
int removeOrdenado(Lista *li, int id);

/******************************************************************************************
 * Salva os dados da lista em um arquivo externo.
 *
 * li, Ponteiro para a lista a ser salva.
 * arquivo, Nome do arquivo onde os dados serão salvos.
 ******************************************************************************************/
void salvaDados(Lista *li, char *arquivo);

/******************************************************************************************
 * Carrega os dados de um arquivo e insere na lista.
 *
 * li, Ponteiro para a lista onde os dados serão inseridos.
 * arquivo, Nome do arquivo de onde os dados serão carregados.
 ******************************************************************************************/
void carregaDados(Lista *li, char *arquivo);

#endif // LISTA_CONTATOS_H_INCLUDED
