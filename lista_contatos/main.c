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

    /// Abrindo arquivo caso exista
    carregaDados(li, "dados_salvos.txt"); // Abre arquivo e insere de forma ordenada na lista

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
            CLIENTE cli = coletaDados(); // Coleta dados e passa para uma estrutura cliente
            char escolha;

            // Checa se o id eh igual, se for ele mantem a execucao do while ate ser diferente
            while (verificaId(li, cli.id)){
                printf("\nUsuario com esse numero de identificacao ja foi inserido.");
                printf("\nDeseja refazer a insercao?(S/N):  ");
                fflush(stdin);
                escolha = getchar();
                if (escolha == 'S' || escolha == 's'){
                    cli = coletaDados(); // Caso nao tenha duplicidade, insere na lista
                }
                else{
                    printf("Voce sera redirecionado ao menu...\n"); // Caso nao queira alterar, volta ao menu
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
                printf("\nVoltando ao menu...\n\n");
            }
            system("pause");
            break;

        case 2:
            system("cls");
            listarLista(li); // Lista todas as informacoes da lista
            system("pause");
            break;

        case 3:
            system("cls");
            int id;
            printf("\nDigite o numero de identificacao: ");
            fflush(stdin);
            scanf("%d", &id);
            listaUnica(li, id); // Pesquisa pelo id sollicitado
            system("pause");
            break;

        case 4:
            system("cls");
            char nome[35];
            printf("\nDigite o nome: ");
            fflush(stdin);
            fgets(nome, 34, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            buscaNome(li, nome); // Pega o nome digitado e busca pela lista
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
                if(removeOrdenado(li, id)){
                    printf("\nUsuario removido com sucesso!\n\n");
                }
                else{
                    printf("\nErro ao remover usuario...\n\n");
                }
            }
            else{
                printf("Retornando ao menu...\n\n");
            }
            system("pause");
            break;

        case 7:
            system("cls");
            printf("Saindo... \n");
            salvaDados(li, "dados_salvos.txt"); // Antes de finalizar, salva os dados para evitar perda
            exit(1); // Sai do programa

        default:
            system("cls");
            printf("Opcao invalida, tente novamente.\n\n");
            system("pause");
            break;
    }
    system("cls");
    }while(opcao != 7);

    apagaLista(li); // Apaga a lista anteriormente criada
    return 0;
}
