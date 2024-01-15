/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Gestao_Empresas.h"
#include "Gestao_Ramos_Atividades.h"
#include "utilizador.h"
#include "input.h"

int continuarOperacoes = 1; // Inicializa como 1 para entrar no loop

/**
 * @brief Esta função permite a pesquisa de empresas por NIF, nome ou categoria.
 *
 * Permite ao usuário pesquisar empresas com base em um termo de pesquisa especificado.
 * O usuário pode escolher pesquisar por NIF, nome ou categoria. A função exibe todas
 * as empresas que correspondem ao critério de pesquisa.
 *
 * @param empresas Array de estruturas Empresa contendo os dados das empresas.
 * @param num_empresas Número total de empresas no array.
 */
void pesquisarEmpresas(Empresa *empresas, int num_empresas) {
    char termoPesquisa[MAX_NOME];
    int numPesquisa;
    int encontradas = 0;

    printf("Introduza o termo de pesquisa\n\n1 - NIF\n2 - Nome\n3 - Categoria(Micro, PME, Grande empresa)\n: ");
    limparBuffer();
    scanf("%d", &numPesquisa);

    switch (numPesquisa){
        case 1:
            printf("Introduz o NIF da empresa a pesquisar: ");
            scanf("%s", termoPesquisa);
            
            printf("\nEmpresas encontradas:\n");
            for (int i = 0; i < num_empresas; i++) {
            if (strstr(empresas[i].nif, termoPesquisa)) {
                printfEmpresa(&empresas[i]);  // Imprimir empresa pesquisada
                printf("\n");
                encontradas = 1;
                }   
            }
            break;
        case 2:
            printf("Introduz o nome da empresa a pesquisar: ");
            scanf("%s", termoPesquisa);
            
            printf("\nEmpresas encontradas:\n");
            for (int i = 0; i < num_empresas; i++) {
            if (strstr(empresas[i].nome, termoPesquisa)) {
                printfEmpresa(&empresas[i]);  // Imprimir empresa pesquisada
                printf("\n");
                encontradas = 1;
                }   
            }
            break;
        case 3:
            printf("Introduz a categoria (Micro, PME, Grande) da empresa a pesquisar: ");
            scanf("%s", termoPesquisa);
            
            printf("\nEmpresas encontradas:\n");
            for (int i = 0; i < num_empresas; i++) {
            if (strstr(empresas[i].categoria, termoPesquisa)) {
                printfEmpresa(&empresas[i]);  // Imprimir empresa pesquisada
                printf("\n");
                encontradas = 1;
                }   
            }
            break;
        default:
            printf("Termo de pesquisa inválido.\n");
            
    }
    if (!encontradas) {
        printf("Nenhuma empresa encontrada para o termo '%s'.\n", termoPesquisa);
    }
}

/**
 * @brief Permite ao usuário classificar uma empresa.
 *
 * Solicita ao usuário o NIF da empresa e uma classificação de 0 a 5.
 * Atualiza a classificação da empresa especificada, se encontrada.
 * A função gere a alocação de memória necessária para armazenar classificações.
 *
 * @param empresas Array de estruturas Empresa.
 * @param num_empresas Número total de empresas no array.
 */
void classificarEmpresas(Empresa *empresas, int num_empresas) {
    int classificacao;
    char nifEmpresa[MAX_NIF];

    printf("Insira o NIF da empresa que pretende classificar: ");
    limparBuffer();
    scanf("%s", nifEmpresa);

    int empresaEncontrada = 0;
    for (int i = 0; i < num_empresas; i++) {
        if (strcmp(empresas[i].nif, nifEmpresa) == 0) {
            empresaEncontrada = 1;
            do {
            printf("Insira a classificação (de 0 a 5): ");
            limparBuffer();
            scanf("%d", &classificacao);

            if (classificacao < 0 || classificacao > 5) {
                printf("Valor errado. Classifique a empresa de 0 a 5.\n");
            }
            
            } while (classificacao < 0 || classificacao > 5);
           
            // Verificar se é a primeira classificação
            if (empresas[i].nclass == 0) {
                // Alocação inicial para a primeira classificação
                empresas[i].classis = malloc(sizeof(Classificacao));
            } else {
                // Realocação para classificações adicionais
                Classificacao *temp = realloc(empresas[i].classis, (empresas[i].nclass + 1) * sizeof(Classificacao));
                if (temp == NULL) {
                    printf("Erro ao alocar memória.\n");
                    break;
                }
                empresas[i].classis = temp;
            }

            if (empresas[i].classis == NULL) {
                printf("Erro ao alocar memória.\n");
                break;
            }

            // Copiar dados para a nova classificação
            strncpy(empresas[i].classis[empresas[i].nclass].nifEmpresa, nifEmpresa, MAX_NIF - 1);
            empresas[i].classis[empresas[i].nclass].nifEmpresa[MAX_NIF - 1] = '\0';
            empresas[i].classis[empresas[i].nclass].classificacao = classificacao;
            empresas[i].classis[empresas[i].nclass].estado = 'A'; // Ajuste conforme necessário

            empresas[i].nclass++;

            printf("Classificação realizada com sucesso!\n\n");
            break;
        }
    }

    if (!empresaEncontrada) {
        printf("NIF da empresa não existe.\n");
    }
}

/**
 * @brief Permite ao usuário adicionar um comentário a uma empresa.
 *
 * Solicita ao usuário o NIF da empresa e os detalhes do comentário, incluindo
 * o nome e email do próprio, título e texto do comentário.
 * Adiciona o comentário à empresa especificada, se encontrada.
 * A função lida com a alocação de memória para os comentários.
 *
 * @param empresas Array de estruturas Empresa.
 * @param num_empresas Número total de empresas no array.
 */
void comentarEmpresas(Empresa *empresas, int num_empresas) {
    int comentário;
    char nifEmpresa[MAX_NIF];  // Alterado para char[MAX_NIF]

    // Pesquisar por NIF da empresa
    printf("Insira o NIF da empresa que pretende classificar: ");
    scanf("%s", nifEmpresa);

    // Verifica se o NIF da empresa existe
    int empresaEncontrada = 0;
    char nome[MAX_NOME], email[MAX_EMAIL], titulo[MAX_NOME], texto[MAX_COMENTARIOS];

    // Verifica se o NIF da empresa existe
    for (int i = 0; i < num_empresas; i++) {
        if (strcmp(empresas[i].nif, nifEmpresa) == 0) {
            empresaEncontrada = 1;

            // Solicita as informações do comentário
            printf("Insira o seu nome: ");
            limparBuffer();
            scanf("%[^\n]", nome);

            printf("Insira o seu email: ");
            limparBuffer();
            scanf("%[^\n]", email);

            printf("Insira o título do comentário: ");
            limparBuffer();
            scanf("%[^\n]", titulo);

            printf("Insira o texto do comentário: ");
            limparBuffer();
            scanf("%[^\n]", texto);

            
            // Atualiza o número de comentários da empresa
            int indiceComentario = empresas[i].nComments;
            
             // Verificar se é a primeira classificação
            if (empresas[i].nComments == 0) {
                // Alocação inicial para a primeira classificação
                empresas[i].comments = malloc(sizeof(Comentario));
            } else {
                // Realocação para classificações adicionais
                Comentario *temp = realloc(empresas[i].comments, (empresas[i].nComments + 1) * sizeof(Comentario));
                if (temp == NULL) {
                    printf("Erro ao alocar memória.\n");
                    break;
                }
                empresas[i].comments = temp;
            }

            if (empresas[i].comments == NULL) {
                printf("Erro ao alocar memória.\n");
                break;
            }
            empresas[i].nComments++;
            
            strcpy(empresas[i].comments[indiceComentario].nifEmpresa, nifEmpresa);  // Copia o NIF diretamente
            strcpy(empresas[i].comments[indiceComentario].nome, nome);
            strcpy(empresas[i].comments[indiceComentario].email, email);
            strcpy(empresas[i].comments[indiceComentario].titulo, titulo);
            strcpy(empresas[i].comments[indiceComentario].comentario, texto);

            printf("Comentário adicionado com sucesso!\n\n");
        }
    }

    if (!empresaEncontrada) {
        printf("NIF da empresa não existe.\n");
    }
}

/**
 * @brief Esta função exibe ao utilizador os detalhes de uma empresa.
 *
 * A função imprime detalhes da empresa tais como NIF, nome, categoria
 * ramo de atividade, localidade e respetivo código postal.
 * Esta função é solicitada na função pesquisarEmpresas, de modo a mostrar os resultados - as ditas empresas.
 *
 * @param empresa Ponteiro para uma estrutura Empresa a ser exibida.
 */
void printfEmpresa(Empresa *empresa) {
    printf("NIF: %s\n", empresa->nif);
    printf("Nome: %s\n", empresa->nome);
    printf("Categoria: %s\n", empresa->categoria);
    printf("Ramo de Atividade: %s\n", empresa->ramo_atividade);
    if (strlen(empresa->rua) > 0) {
        printf("Rua: %s\n", empresa->rua);
    }
    printf("Localidade: %s\n", empresa->localidade);
    printf("Código Postal: %s\n", empresa->codigo_postal);
}
