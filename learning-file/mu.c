#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mu.h"

int main(int argc, char const *argv[])
{
    int op;
    menu();
    scanf("%d", &op);
    getchar();
    while (op)
    {
        if (op == 1)
        {
            cadastrar();
        }
        else if (op == 2)
        {
            listar();
            printf("\n\t ...Enter para sair");
            getchar();
        }
        else if (op == 3)
        {
            editar();
            // printf("Editar\n");
            printf("\t ...Enter para sair");
            getchar();
        }
        else if (op == 4)
        {
            excluir();
            printf("Exluir\n");
            printf("\t ...Enter para sair");
            getchar();
        }
        else if (op == 5)
        {
            buscar();
        }

        else if (op == 6)
        {
        
            Idade(1);
            getchar();
        }

        else if (op == 7)
        {
            Idade(2);
            getchar();
        }

        else
        {
            printf("\n\t opção invalida \n");
            menu();
            scanf("%d", &op);
            getchar();
        }

        menu();
        scanf("%d", &op);
        getchar();
    }

    return 0;
}

void menu(void)
{
    system("clear");
    printf("\nEscolha a funçao quer voce quer fazer\n");
    printf("\n Cadastrar: 1\n");
    printf("\n Listas todos: 2\n");
    printf("\n Editar: 3\n");
    printf("\n Excluir: 4\n");
    printf("\n Buscar um: 5\n");
    printf("\n Mostar por Maior idade de Bovino: 6\n");
    printf("\n Mostar por Menor idade de Bovino: 7\n");
    printf("\n Sair: 0\n");
}

void cadastrar(void)
{
    Mu *bovinos;
    bovinos = (Mu *)malloc(sizeof(Mu));
    printf("\nInforme o Nome do bovino\t");
    scanf("%s", bovinos->nome);
    getchar();
    printf("\nInforme o Tipo do bovino\t");
    scanf("%s", bovinos->tipo);
    getchar();
    printf("\nInforme o Sexo do bovino\t");
    scanf("%c", &bovinos->sexo);
    getchar();
    printf("\nInforme a idade do bovino\t");
    scanf("%d", &bovinos->idade);
    getchar();
    bovinos->status = 'C';
    mostrar(bovinos);
    gravar(bovinos);
    free(bovinos);
    printf("\t ...Enter para sair");
    getchar();
}

void listar(void)
{

    FILE *fp;
    Mu *bovinos;
    fp = fopen("bovinos.dat", "rb");
    if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = S G VACAS = = = \n");
    printf("= = Exibe Animais = = \n");
    printf("= = = = = = = = = = = \n");
    bovinos = (Mu *)malloc(sizeof(Mu));
    while (fread(bovinos, sizeof(Mu), 1, fp))
    {
        if (bovinos->status == 'C')
        {
            mostrar(bovinos);
        }
    }
    fclose(fp);
    free(bovinos);
}

void mostrarDin(Dinan *novo)
{
    printf("\nNome do Bovino: %s", novo->nome);
    printf("\nTipo do Bovino: %s", novo->tipo);
    printf("\nSexo do Bovino: %c", novo->sexo);
    printf("\nIdade do Bovino: %d", novo->idade);
    printf("\nStatus do Bovino: %c", novo->status);
    printf("\n");
    // getchar();

}

void mostrar(Mu *bovinos)
{
    printf("\nNome do Bovino: %s", bovinos->nome);
    printf("\nTipo do Bovino: %s", bovinos->tipo);
    printf("\nSexo do Bovino: %c", bovinos->sexo);
    printf("\nIdade do Bovino: %d", bovinos->idade);
    printf("\nStatus do Bovino: %c", bovinos->status);
    printf("\n");
    // getchar();

}

void gravar(Mu *bovinos)
{
    FILE *fp;
    fp = fopen("bovinos.dat", "ab");
    if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(bovinos, sizeof(Mu), 1, fp);
    fclose(fp);
}

void buscar(void)
{
    FILE *fp;
    Mu *bovinos;
    int resultado;
    char nomeBusca[51];
    fp = fopen("bovinos.dat", "rb");
    if (fp == NULL)
    {
        /* code */
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    system("clear");
    printf("\n informe o nome do bovino que voce busca\t");
    scanf("%s", nomeBusca);
    bovinos = (Mu *)malloc(sizeof(Mu));
    resultado = 0;
    while ((!resultado) && (fread(bovinos, sizeof(Mu), 1, fp)))
    {
        /* code */
        if ((strcmp(bovinos->nome, nomeBusca) == 0) && (bovinos->status == 'C'))
        {
            /* code */
            resultado = 1;
        }
    }
    fclose(fp);
    if (resultado)
    {
        /* code */
        mostrar(bovinos);
    }
    else
    {
        printf("Bovino %s não encontrado...", nomeBusca);
    }
    free(bovinos);
}

void excluir(void)
{

    FILE *fp;
    Mu *bovino;
    int achou;
    char resp;
    char procurado[15];
    fp = fopen("bovinos.dat", "r+b");
    if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = S G Vacas = = = \n");
    printf("= =   Bovinos   = = \n");
    printf("= = = = = = = = = = = \n");
    printf("Informe o nome do animal a ser apagado: ");
    scanf(" %14[^\n]", procurado);
    bovino = (Mu *)malloc(sizeof(Mu));
    achou = 0;
    while ((!achou) && (fread(bovino, sizeof(Mu), 1, fp)))
    {
        if ((strcmp(bovino->nome, procurado) == 0) && (bovino->status == 'C'))
        {
            achou = 1;
        }
    }

    if (achou)
    {
        mostrar(bovino);
        getchar();
        printf("Deseja realmente apagar este animal (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S')
        {
            bovino->status = 'A';
            fseek(fp, (-1) * sizeof(Mu), SEEK_CUR);
            fwrite(bovino, sizeof(Mu), 1, fp);
            printf("\nAnimal excluído com sucesso!!!\n");
        }
        else
        {
            printf("\nOk, os dados não foram alterados\n");
        }
    }
    else
    {
        printf("O animal %s não foi encontrado...\n", procurado);
    }
    free(bovino);
    fclose(fp);
}

void editar(void)
{

    FILE *fp;
    Mu *bovinos;
    int achou;
    char resp;
    char procurado[15];
    fp = fopen("bovinos.dat", "r+b");
    if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = S G P e t = = = \n");
    printf("= = Editar Animal = = \n");
    printf("= = = = = = = = = = = \n");
    printf("Informe o nome do animal a ser alterado: ");
    scanf(" %14[^\n]", procurado);
    bovinos = (Mu *)malloc(sizeof(Mu));
    achou = 0;
    while ((!achou) && (fread(bovinos, sizeof(Mu), 1, fp)))
    {
        if ((strcmp(bovinos->nome, procurado) == 0) && (bovinos->status == 'C'))
        {
            achou = 1;
        }
    }
    if (achou)
    {
        mostrar(bovinos);
        getchar();
        printf("Deseja realmente editar este animal (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S')
        {
            printf("\nInforme o nome do bovino: ");
            scanf("%s", bovinos->nome);
            getchar();
            printf("Informe o tipo do animal: ");
            scanf(" %s14[^\n]", bovinos->tipo);
            getchar();
            printf("Informe o sexo do bovino: ");
            scanf(" %c,14[^\n]", &bovinos->sexo);
            getchar();
            bovinos->status = 'C';
            fseek(fp, (-1) * sizeof(Mu), SEEK_CUR);
            fwrite(bovinos, sizeof(Mu), 1, fp);
            printf("\nBovino editado com sucesso!!!\n");

        }
        else
        {
            printf("\nOk, os dados não foram alterados\n");
        }
    }
    else
    {
        printf("O animal %s não foi encontrado...\n", procurado);
    }
    free(bovinos);
    fclose(fp);
}

void Idade(int num) {
    FILE *fp;
    Mu * mumuzinho;
    Dinan *novo;
    Dinan *lista;
    int tam;

    if (access("bovinos.dat", F_OK) != -1)    {
        /* code */
        fp = fopen("bovinos.dat","rb");

        if (fp == NULL) {

            printf("Erro na abertura do arquivo");
        }
        
        else
        {
            /* code */
            lista = NULL;

            mumuzinho = (Mu*) malloc(sizeof(Mu));

            while (fread(mumuzinho, sizeof(Mu), 1, fp))
            {
                /* code */
                if (mumuzinho->status == 'C')
                {
                    /* code */
                    novo = (Dinan*) malloc(sizeof(Dinan));

                    tam = strlen(mumuzinho->nome) + 1;

                        strcpy(novo->nome, mumuzinho->nome);
                        strcpy(novo->tipo, mumuzinho->tipo);
                        // novo->nome = mumuzinho->nome;
                        novo->status = mumuzinho->status;
                        novo->sexo = mumuzinho->sexo;
                        //novo->tipo = mumuzinho->tipo;
                        
                        //  (char*) malloc(tam*sizeof(char));
                        // strcpy(novo->nome, mumuzinho->nome);

                        // tam = strlen(mumuzinho->status) + 1;

                        // novo->status = (char*) malloc(tam*sizeof(char));
                        // strcpy(novo->status, mumuzinho->status);

                        // tam = strlen(mumuzinho->sexo) + 1;

                        // novo->sexo = (char*) malloc(tam*sizeof(char));
                        // strcpy(novo->sexo, mumuzinho->sexo);

                        // tam = strlen(mumuzinho->tipo) + 1;

                        // novo->tipo = (char*) malloc(tam*sizeof(char));
                        // strcpy(novo->tipo, mumuzinho->tipo);

                    
                    novo->idade = mumuzinho->idade;

                    if (num == 1) {
                        if (lista == NULL) {
                            lista = novo;
                            novo->prox = NULL;
                        } 

                        else if (novo->idade > lista->idade) {
                            novo->prox = lista;
                            lista = novo;
                        } 

                        else {
                            Dinan* anter = lista;
                            Dinan* atual = lista->prox;

                            while ((atual != NULL) && atual->idade > novo->idade) {
                                anter = atual;
                                atual = atual->prox;
                            }

                            anter->prox = novo;
                            novo->prox = atual;

                        }
                    }

                    else {
                        if (lista == NULL) {
                            lista = novo;
                            novo->prox = NULL;
                        } 

                        else if (novo->idade < lista->idade) {
                            novo->prox = lista;
                            lista = novo;
                        } 

                        else {
                            Dinan* anter = lista;
                            Dinan* atual = lista->prox;

                            while ((atual != NULL) && atual->idade < novo->idade) {
                                anter = atual;
                                atual = atual->prox;
                            }

                            anter->prox = novo;
                            novo->prox = atual;

                        }

                    }

                    
                }
                

            }

            free(mumuzinho);

            novo = lista;
            while (novo != NULL) {

                mostrarDin(novo);
                novo = novo->prox;

            }

            novo = lista;
            while (lista != NULL) {
                lista = lista->prox;
                // free(novo->nome);
                // free(novo->status);
                free(novo);
                novo = lista;
            }
            
        }

        fclose(fp);
        
    }
    
}