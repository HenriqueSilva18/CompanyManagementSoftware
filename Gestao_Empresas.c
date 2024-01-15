/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <regex.h>
#include "Gestao_Empresas.h" 
#include "Gestao_Ramos_Atividades.h"
#include "input.h"

/**
 * @brief Função para validar Codigo Postal
 * @param codigoPostal
 * @return 
 */
int validarCodigoPostal(const char *codigo_postal) {

    regex_t regex;
    int resultado;

    // Ajustando a expressão regular para corresponder ao formato do código postal em Portugal
    const char *pattern = "^\\d{4}-\\d{3}$";

    // Compilando a expressão regular
    resultado = regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB);
    if (resultado != 0) {
        printf("Erro ao compilar a expressão regular.\n");
        return 0;
    }

    // Executando a expressão regular para verificar se o código postal está no formato correto
    resultado = regexec(&regex, codigo_postal, 0, NULL, 0);

    // Liberando recursos
    regfree(&regex);

    if (resultado == 0) {
        return 1;
    } else {
        return 0;
    }
}


/**
 * @brief Função para criar empresas
 * @param empresas
 * @param num_Empresas
 */
void criarEmpresa(Empresas *empresas, int *num_empresas) {
    // Verifica se é necessário realocar mais memória
    if (*num_empresas == empresas->alocadas) {
        empresas->alocadas += ALOCACAO_EMPRESAS;
        Empresa *temp = realloc(empresas->empresas, empresas->alocadas * sizeof(Empresa));
        if (temp == NULL) {
            printf("Erro ao alocar memória.\n");
            return;
        }
        empresas->empresas = temp;
    }
    
    Empresa *novaEmpresa = &empresas->empresas[*num_empresas];

    // Preenchimento os dados da nova empresa

    int nifValido = 0;
    while (!nifValido) {
        printf("NIF da empresa: ");
        limparBuffer();
        scanf("%s", novaEmpresa->nif);

        // Verificar se o NIF tem 9 dígitos
        if (strlen(novaEmpresa->nif) == 9) {
            nifValido = 1; // Assume inicialmente que o NIF é válido
            for (int i = 0; i < 9; i++) {
                //Verifica se todos os caracteres do 'NIF' são números
                if (!isdigit(novaEmpresa->nif[i])) {
                    nifValido = 0; // NIF é inválido se encontrar um caractere não numérico
                    printf("NIF inválido. Deve conter apenas dígitos.\n");
                    break;
                }
            }
        } else {
            printf("NIF inválido. Deve ter exatamente 9 dígitos.\n");
        }
    }


    printf("Nome da empresa: ");
    limparBuffer();
    scanf("%s", novaEmpresa->nome);

    printf("Categoria da empresa (Micro, PME, Grande empresa): ");
    limparBuffer();
    int categoriaValida = 0;
    do {
        scanf("%s", novaEmpresa->categoria);

        if (strcmp(novaEmpresa->categoria, "Micro") == 0 || strcmp(novaEmpresa->categoria, "PME") == 0 || strcmp(novaEmpresa->categoria, "Grande empresa") == 0) {
            categoriaValida = 1;
        } else{
            puts("Categoria Errada! Introduza a categoria da Empresa");
            limparBuffer();
            scanf("%s", novaEmpresa->categoria);
        }
    } while (categoriaValida != 1);

    printf("Ramo de atividade da empresa: ");
    limparBuffer();
    scanf("%s", novaEmpresa->ramo_atividade);

    printf("Rua da empresa: ");
    limparBuffer();
    scanf("%s", novaEmpresa->rua);

    printf("Localidade da empresa: ");
    limparBuffer();
    scanf("%s", novaEmpresa->localidade);

    printf("Código postal da empresa: ");
    limparBuffer();
    scanf("%s", novaEmpresa->codigo_postal);
    if (!validarCodigoPostal(novaEmpresa->codigo_postal)){
        puts("Codigo Postal Inválido!!\n");
        puts("Insira o Codigo de Postal(0000-000):");
        scanf("%s", novaEmpresa->codigo_postal);
    }

    // Por padrão, uma nova empresa é marcada como ativa
    novaEmpresa->estado = 1;
    novaEmpresa->nclass = 0;
    novaEmpresa->classis = NULL;
    novaEmpresa->nComments = 0;
    novaEmpresa->comments = NULL;

    
    // Incrementa o número total de empresas
    (*num_empresas)++;
    empresas->contador = *num_empresas;
    printf("Empresa criada com sucesso!\n");
}

/**
 * @brief Esta função permite a edição de  Empresas já criadas.
 * 
 * @param empresas Array de estruturas Empresa contendo os dados das empresas.
 * @param num_Empresas Número total de empresas no array.
 */
void editarEmpresa(Empresa *empresas, int *num_Empresas) {
    char lerNif[MAX_NIF];
    int index = atoi(lerNif) -1;
 
    //Verifica se existem empresas guardados
    if (*num_Empresas == 0) {
        printf("Não há empresas no catálogo.\n");
        return;
    }

    //Menu de edição de Empresas
    puts("|   Editar Empresa    |");

    //Lista as empresas para facilitar a pesquisa
    printf("Lista de Empresas:\n");
    for (int i = 0; i < *num_Empresas; i++) {
        printf("NIF: %s\n", empresas[i].nif);
        printf("Nome: %s\n", empresas[i].nome);
        printf("Categoria: %s\n", empresas[i].categoria);
        printf("Ramo de Atividade: %p\n", empresas[i].ramo_atividade);
        printf("Rua: %s\n", empresas[i].rua);
        printf("Localidade: %s\n", empresas[i].localidade);
        printf("Código Postal: %s\n", empresas[i].codigo_postal);
        printf("\n");
    }
    puts("Insira o nif da empresa que pretende alterar: ");
    scanf("%s", &lerNif);

    //Verifica se nif da empresa existe
    int empresaEncontrada = 0; // Variável para indicar se a empresa foi encontrada
    for (int i = 0; i < *num_Empresas; i++) {
        if (strcmp(empresas[i].nif, lerNif)== 0){
            empresaEncontrada = 1; // Empresa encontrada
            
            puts("-     Editar informações da empresa     -");
            puts("Vai alterar a empresa:");
            printf("NIF: %s\n", empresas[i].nif);
            printf("Nome: %s\n", empresas[i].nome);
            printf("Categoria: %s\n", empresas[i].categoria);
            printf("Ramo de Atividade: %p\n", empresas[i].ramo_atividade);
            printf("Rua: %s\n", empresas[i].rua);
            printf("Localidade: %s\n", empresas[i].localidade);
            printf("Código Postal: %s\n", empresas[i].codigo_postal);
            printf("\n");
            
            bool nifValido = false;
            while (!nifValido) {
                printf("NIF da empresa: ");
                limparBuffer();
                fgets(empresas[i].nif, 10, stdin);
                empresas[i].nif[strcspn(empresas[i].nif, "\n")] = '\0';

                // Verificar se tem 9 dígitos
                if (strlen(empresas[i].nif) == 9) {
                    nifValido = true;
                    for (int j = 0; j < 9; j++) {
                        if (!isdigit(empresas[i].nif[j])) {
                            nifValido = false;
                            printf("NIF inválido. Deve conter apenas dígitos.\n");
                                    break;
                        }
                    }
                } else {
                    printf("NIF inválido. Deve ter exatamente 9 dígitos.\n");
                }
            }


            printf("Nome da empresa: ");
            limparBuffer();
            scanf("%s", empresas[index].nome);
            strcpy(empresas[i].nome, empresas[index].nome);

            printf("Categoria da empresa (Micro, PME, Grande empresa): ");
            limparBuffer();
            int categoriaValida = 0;
            do {
                scanf("%s", empresas[index].categoria);

                if (strcmp(empresas[index].categoria, "Micro") == 0 || strcmp(empresas[index].categoria, "PME") == 0 || strcmp(empresas[index].categoria, "Grande empresa") == 0) {
                    categoriaValida = 1;
                } else{
                    puts("Categoria Errada! Introduza a categoria da Empresa");
                    limparBuffer();
                    scanf("%s", empresas[index].categoria);
                }
            } while (categoriaValida != 1);
            strcpy(empresas[i].categoria, empresas[index].categoria);

            printf("Ramo de atividade da empresa: ");
            limparBuffer();
            scanf("%s", empresas[index].ramo_atividade);
            strcpy(empresas[i].ramo_atividade, empresas[index].ramo_atividade);

            printf("Rua da empresa: ");
            limparBuffer();
            scanf("%s", empresas[index].rua);
            strcpy(empresas[i].rua, empresas[index].rua);

            printf("Localidade da empresa: ");
            limparBuffer();
            scanf("%s", empresas[index].localidade);
            strcpy(empresas[i].localidade, empresas[index].localidade);

            printf("Código postal da empresa: ");
            limparBuffer();
            scanf("%s", empresas[index].codigo_postal);
            if (!validarCodigoPostal(empresas[index].codigo_postal)){
                puts("Codigo Postal Inválido!!\n");
                puts("Insira o Codigo de Postal(0000-000):");
                scanf("%s", empresas[index].codigo_postal);
            }
            strcpy(empresas[i].codigo_postal, empresas[index].codigo_postal);
            
            printf("Edição concluída com sucesso!\n");
            break;
        }
    }
    //Caso não exista um id dá return
    if (!empresaEncontrada) {
        puts("Não existe nenhuma empresa com esse nif");
        return;
    }
   
}

/**
 * @brief Esta função permite a eliminação de Empresas.
 * 
 * @param empresas Array de estruturas Empresa contendo os dados das empresas.
 * @param num_Empresas Número total de empresas no array.
 */
void removerEmpresa(Empresa *empresas, int *num_Empresas) {
    char nifRemovido[MAX_NIF];

    // Verifica se existem empresas guardadas
    if (*num_Empresas == 0) {
        printf("Não há empresas no catálogo.\n");
        return;
    }

    // Lista as empresas para facilitar a pesquisa
    printf("Lista de Empresas:\n");
    for (int i = 0; i < *num_Empresas; i++) {
        printf("NIF: %s\n", empresas[i].nif);
        printf("Nome: %s\n", empresas[i].nome);
        printf("\n");
    }

    // Solicita o ID da empresa a ser removida
    printf("Insira o Nif da empresa que deseja remover: ");
    scanf("%s", &nifRemovido);

    // Verifica se o ID da empresa existe
    int empresaEncontrada = 0;
    for (int i = 0; i < *num_Empresas; i++) {
        if (strcmp(empresas[i].nif, nifRemovido)== 0) {
            // Move a última empresa para a posição da empresa a ser removida
            empresas[i] = empresas[*num_Empresas - 1];
            (*num_Empresas)--;  // Decrementa o número total de empresas
            empresaEncontrada = 1;
            empresas[*num_Empresas].estado = 0;
            printf("Empresa removida com sucesso!\n");
            break;
        }
    }
    if (!empresaEncontrada) {
        printf("NIF da empresa não existe.\n");
    }
}
