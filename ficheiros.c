/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "Gestao_Empresas.h"
    #include "Gestao_Ramos_Atividades.h"
    #include "relatorios.h"
    #include "utilizador.h"
    #include "ficheiros.h"


    /**
     * @brief Função para escrever todos os dados, ramos de atividade e relatórios de empresas num ficheiro binário
     * @param empresas
     * @param relComentarios
     * @param numRelComentarios
     * @param relMedia
     * @param numRelMedia
     * @param ramos
     * @param num_ramos
     * @param nomeArquivo
     */
    void salvarTodosOsDados(Empresas *empresas, EmpresaRelatorioComentarios *relComentarios, int numRelComentarios, EmpresaRelatorioMedia *relMedia, int numRelMedia, Ramo_Atividade *ramos, int num_ramos, const char *nomeArquivo) {
        FILE *arquivo = fopen(nomeArquivo, "wb");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo para escrita.\n");
            return;
        }
        salvarDadosEmpresas(empresas, arquivo);
        salvarDadosRelatorios(relComentarios, numRelComentarios, relMedia, numRelMedia, arquivo);
        salvarDadosRamos(ramos, num_ramos, arquivo);
        fclose(arquivo);
    }
    
    /**
     * @brief Função para ler todos os dados, ramos de atividade e relatórios de empresas de um ficheiro binário
     * @param empresas
     * @param relComentarios
     * @param numRelComentarios
     * @param relMedia
     * @param numRelMedia
     * @param ramos
     * @param num_ramos
     * @param nomeArquivo
     */
    void carregarTodosOsDados(Empresas *empresas, EmpresaRelatorioComentarios **relComentarios, int *numRelComentarios, EmpresaRelatorioMedia **relMedia, int *numRelMedia, Ramo_Atividade **ramos, int *num_ramos, const char *nomeArquivo) {
        FILE *arquivo = fopen(nomeArquivo, "rb");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo para leitura.\n");
            return;
        }
        carregarDadosEmpresas(empresas, arquivo);
        carregarDadosRelatorios(relComentarios, numRelComentarios, relMedia, numRelMedia, arquivo);
        carregarDadosRamos(ramos, num_ramos, arquivo);
        printf("Empresa carregadas\n");
        fclose(arquivo);
    }
    
    /**
     * @brief Função para escrever a estrutura das empresas, os respetivos dados e ainda as classificações e comentários de cada empresa mo ficheiro
     * @param empresas
     * @param arquivo
     */
    void salvarDadosEmpresas(Empresas *empresas, FILE *arquivo) {
        fwrite(&(empresas->contador), sizeof(int), 1, arquivo);
        for (int i = 0; i < empresas->contador; i++) {
            // Escrever os campos fixos da estrutura Empresa
            fwrite(&(empresas->empresas[i]), sizeof(Empresa) - sizeof(Classificacao*) - sizeof(Comentario*), 1, arquivo);

             // Escrever classis, se existir
            if (empresas->empresas[i].classis != NULL && empresas->empresas[i].nclass > 0) {
                fwrite(empresas->empresas[i].classis, sizeof(Classificacao), empresas->empresas[i].nclass, arquivo);
            }

            // Escrever comments, se existir
            if (empresas->empresas[i].comments != NULL && empresas->empresas[i].nComments > 0) {
                fwrite(empresas->empresas[i].comments, sizeof(Comentario), empresas->empresas[i].nComments, arquivo);
            }
        }
    }
    
    /**
     * @brief Função para ler a estrutura das empresas, os respetivos dados e ainda as classificações e comentários de cada empresa do ficheiro
     * @param empresas
     * @param arquivo
     */
    void carregarDadosEmpresas(Empresas *empresas, FILE *arquivo) {
        fread(&(empresas->contador), sizeof(int), 1, arquivo);
        empresas->empresas = malloc(empresas->contador * sizeof(Empresa));

        if (empresas->empresas == NULL && empresas->contador > 0) {
            fprintf(stderr, "Erro: Falha na alocação de memória para empresas.\n");
            return;
        }

        for (int i = 0; i < empresas->contador; i++) {
        // Ler os campos fixos da estrutura Empresa
            if (fread(&(empresas->empresas[i]), sizeof(Empresa) - sizeof(Classificacao*) - sizeof(Comentario*), 1, arquivo) != 1) {
                fprintf(stderr, "Erro de leitura no arquivo.\n");
                // Liberar memória já alocada
                for (int j = 0; j < i; j++) {
                    free(empresas->empresas[j].classis);
                    free(empresas->empresas[j].comments);
                }
                free(empresas->empresas);
                return;
            }

            // Alocar e ler classis

            if (empresas->empresas[i].nclass > 0) {
                empresas->empresas[i].classis = malloc(empresas->empresas[i].nclass * sizeof(Classificacao));
                if (empresas->empresas[i].classis != NULL) {
                    fread(empresas->empresas[i].classis, sizeof(Classificacao), empresas->empresas[i].nclass, arquivo);
                }
            } else {
                empresas->empresas[i].classis = NULL;
            }

            // Alocar e ler comments
            if (empresas->empresas[i].nComments > 0) {
                empresas->empresas[i].comments = malloc(empresas->empresas[i].nComments * sizeof(Comentario));
                if (empresas->empresas[i].comments != NULL) {
                    fread(empresas->empresas[i].comments, sizeof(Comentario), empresas->empresas[i].nComments, arquivo);
                }
            } else {
                empresas->empresas[i].comments = NULL;
            }
        }
    }
    
    /**
     * @brief Função para escrever os relatórios de média de classificação e quantidade de comentários no ficheiro
     * @param relComentarios
     * @param numRelComentarios
     * @param relMedia
     * @param numRelMedia
     * @param arquivo
     */
    void salvarDadosRelatorios(EmpresaRelatorioComentarios *relComentarios, int numRelComentarios, EmpresaRelatorioMedia *relMedia, int numRelMedia, FILE *arquivo) {
        fwrite(&numRelComentarios, sizeof(int), 1, arquivo);
        fwrite(relComentarios, sizeof(EmpresaRelatorioComentarios), numRelComentarios, arquivo);
        fwrite(&numRelMedia, sizeof(int), 1, arquivo);
        fwrite(relMedia, sizeof(EmpresaRelatorioMedia), numRelMedia, arquivo);
    }
    
    /**
     * @brief Função para ler os relatórios de média de classificação e quantidade de comentários do ficheiro
     * @param relComentarios
     * @param numRelComentarios
     * @param relMedia
     * @param numRelMedia
     * @param arquivo
     */
    void carregarDadosRelatorios(EmpresaRelatorioComentarios **relComentarios, int *numRelComentarios, EmpresaRelatorioMedia **relMedia, int *numRelMedia, FILE *arquivo) {
        fread(numRelComentarios, sizeof(int), 1, arquivo);
        *relComentarios = malloc(*numRelComentarios * sizeof(EmpresaRelatorioComentarios));
        fread(*relComentarios, sizeof(EmpresaRelatorioComentarios), *numRelComentarios, arquivo);
        fread(numRelMedia, sizeof(int), 1, arquivo);
        *relMedia = malloc(*numRelMedia * sizeof(EmpresaRelatorioMedia));
        fread(*relMedia, sizeof(EmpresaRelatorioMedia), *numRelMedia, arquivo);
    }

    /**
     * @brief Função para escrever os ramos de atividade no ficheiro
     * @param ramos
     * @param num_ramos
     * @param arquivo
     */
    void salvarDadosRamos(Ramo_Atividade *ramos, int num_ramos, FILE *arquivo) {
        fwrite(&num_ramos, sizeof(int), 1, arquivo);
        fwrite(ramos, sizeof(Ramo_Atividade), num_ramos, arquivo);
    }
    /**
     * @brief Função para ler os ramos de atividade do ficheiro
     * @param ramos
     * @param num_ramos
     * @param arquivo
     */
    void carregarDadosRamos(Ramo_Atividade **ramos, int *num_ramos, FILE *arquivo) {
        fread(num_ramos, sizeof(int), 1, arquivo);
        *ramos = malloc(*num_ramos * sizeof(Ramo_Atividade));
        fread(*ramos, sizeof(Ramo_Atividade), *num_ramos, arquivo);
    }