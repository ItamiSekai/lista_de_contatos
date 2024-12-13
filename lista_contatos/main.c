#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "lista_contatos.h"

int main()
{
    /// Criar lista
    Lista *li = NULL;
    if ((li = geraLista()) == NULL){
        abortaPrograma();
    }

    /// Menu de Opcoes
    int opcao = 0;
    do{
    printf("       |LISTA DE CONTATOS| \n\n");
    printf("=============MENU=============\n");
    printf("| Escolha uma opcao:         |\n");
    printf("| 1. Inserir dados           |\n");
    printf("| 2. Listar todos            |\n");
    printf("| 3. Busca unica             |\n");
    printf("| 4. Busca por nome          |\n");
    printf("| 5. Edicao de dados         |\n");
    printf("| 6. Remocao                 |\n");
    printf("| 7. Sair                    |\n");
    printf("=============MENU=============\n\n");
    printf("Digite: ");
    scanf("%d", &opcao);

    switch (opcao){
        case 1:
            system("cls");
            CLIENTE cli = coletaDados();
            char escolha;

            // Chega se o id eh igual, se for ele mantem a execucao do while ate ser diferente
            while (verificaId(li, cli.id)){
                printf("\nUsuario com esse numero de identificacao ja foi inserido.");
                printf("\nDeseja refazer a insercao?(S/N):  ");
                fflush(stdin);
                escolha = getchar();
                if (escolha == 'S' || escolha == 's'){
                    cli = coletaDados();
                }
                else{
                    printf("Voce sera redirecionado ao menu...\n");
                    system("pause");
                    break;
                }
            }
            // Se saiu do While, entao o id nao esta repetindo, assim podendo inserir na lista
            // Caso conseguia inserir, mostra uma mensagem de sucesso, em caso de erro ele retorna para o menu
            if (!verificaId(li, cli.id)){
                if (insereOrdenado(li, cli)){
                    system("cls");
                    printf("\nUsuario inserido com sucesso!!\n\n");
                }else{
                    printf("\nErro ao inserir usuario....");
                }
            }
            else{
                printf("\nVoltando ao menu...\n");
            }
            printf("\nErro ao inserir...\n\n");
            system("pause");
            break;

            system("pause");
                    break;
        case 2:
            system("cls");
            listarLista(li);
            system("pause");
            break;
        case 3:
            system("cls");
            int id;
            printf("\nDigite o numero de identificacao: ");
            fflush(stdin);
            scanf("%d", &id);
            listaUnica(li, id);
            system("pause");
            break;
        case 4:
            system("cls");
            char nome[35];
            printf("\nDigite o nome: ");
            fflush(stdin);
            fgets(nome, 34, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            buscaNome(li, nome);
            system("pause");
            break;
        case 5:
            system("cls");
            printf("\nDigite o numero de identificacao: ");
            fflush(stdin);
            scanf("%d", &id);
            editarCliente(li, id);
            system("pause");
            break;
        case 6:
            system("cls");
            printf("Qual o numero de identificacao? ");
            scanf(" %d", &id);
            listaUnica(li, id); // Mostra os dados ao usuario
            printf("\nDeseja realmente remover (S/N): ");
            scanf(" %c", &escolha);
            if (escolha == 's' || escolha == 'S'){
                removeOrdenado(li, id);
                printf("\nUsuario removido com sucesso!\n\n");
                system("pause");
                break;
            }
            printf("Retornando ao menu...\n\n");
            system("pause");
            break;
        case 7:
            system("cls");
            printf("Saindo... \n");
            exit(1);
        default:
            system("cls");
            printf("Opcao invalida, tente novamente.\n");
            system("pause");
            break;
    }
    system("cls");
    }while(opcao != 6);

    apagaLista(li);
    return 0;
}

/// PROJETO AAA

/// struct cliente deve ter:
/*
Clientes para a empresa fictícia ACME S.A., que contará com informações tais como:
número de identificação do cliente, nome do cliente,
empresa onde trabalha, departamento, telefones fixo, celular e e-mail.
*/

/// Deve ser capaz de
/*
Seu programa deverá ser capaz de salvar e recuperar os dados gerados entre seções de
trabalho anteriores e atuais, além de possibilitar a inserção de novos clientes e remoção de clientes
existentes, edição dos dados de clientes já armazenados, e exibição dos dados de clientes.

A ordenação dos elementos na lista de contatos deverá
ser crescente e baseada no atributo (campo) código, portanto, só há a necessidade de se contar com
as funções de inserção e remoção ordenadas.

uma verificação de duplicidade deve ser realizada durante as
inserções de novos clientes.

A funcionalidade de gravação e recuperação de dados entre seções, deverá ser implementada
utilizando o modo gravação binária (REQUISITO), salvando as estruturas (structs) completas, com
todos os dados dos clientes. Isso torna a recuperação dos dados mais simples.

Todas as funcionalidades do seu programa deverão estar implementadas em funções que
realizarão apenas uma atividade específica por vez.

Seu aplicativo deverá contar com um menu, exibido de forma ininterrupta, e que terá suas
opções disponíveis acessíveis por números, onde o usuário escolherá a opção que desejar apenas
digitando o número correspondente e confirmar teclando enter.

Após finalização da execução de cada funcionalidade, o fluxo de execução seu programa
deverá retornar ao menu reapresentando-o, possibilitando então novas escolhas.
O menu deverá contar ainda com uma opção específica para encerramento da aplicação, lembrando que neste ponto
deve-se tomar o cuidado com a perda de dados.

O menu terá que contar no mínimo, com as seguintes opções:

• Inserção de novo contato, verificando a duplicidade de códigos (não pode haver dois iguais);
• Gerar e exibir relatório de contatos em forma de lista total;
• Gerar e exibir relatório individual com busca por identificador (código);
• Gerar e exibir relatório com busca por nome (neste caso exibir todos que tenham o mesmo
nome utilizado na busca – Ex: busca = “José” – lista todos os clientes que possuam este mesmo
nome);
• Edição de dados do contato, escolhido por identificador;
• Remover contato, escolhido por identificador;
• Sair e encerrar o programa, porém, antes de sua efetiva finalização,salvando toda a lista para
posterior nova seção de trabalho.


O arquivo de dados salvos da lista de contatos, deverá entregue para avaliação juntamente
com o aplicativo, possuindo no mínimo 10 registros de clientes previamente gravados para
os testes funcionais de avaliação, assim como todos os arquivos gerados pela IDE CodeBlocks;

Extremamente importante informar, com comentários, o que e como as rotinas (funções)
funcionam (lembrem-se: eu não conheço o seu raciocínio, portanto comentem!!!), vale
pontos;
*/
