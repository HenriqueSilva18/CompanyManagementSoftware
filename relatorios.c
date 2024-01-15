/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include "relatorios.h"



 /** 
 * @brief Função de comparação para ordenar empresas pelo número de comentários.
 *
 * Esta função é projetada para ser usada com qsort e compara duas estruturas
 * EmpresaRelatorio pelo número de comentários de cada uma. 
 * Ordena as empresas em ordem decrescente de número de comentários.
 *
 * @param a O ponteiro para o primeiro elemento de EmpresaRelatorioComentarios a ser comparado.
 * @param b O ponteiro para o segundo elemento de EmpresaRelatorioComentarios a ser comparado.
 * @return Um inteiro menor, igual ou maior que zero se a primeira empresa tiver 
 *         respectivamente menos, igual ou mais comentários que a segunda empresa.
 */
int compararPorComentarios(const void *a, const void *b) {
    EmpresaRelatorioComentarios *empresaA = (EmpresaRelatorioComentarios *)a;
    EmpresaRelatorioComentarios *empresaB = (EmpresaRelatorioComentarios *)b;
    return empresaB->numComentarios - empresaA->numComentarios; // Ordem decrescente
}
/**
 * @brief Gera e exibe um relatório das empresas ordenadas pelo número de comentários.
 * 
 * Este relatório lista as empresas com base no número total de comentários que cada uma recebeu,
 * começando pela empresa com o maior número de comentários. É útil para entender que
 * empresas estão a gerar mais interesse entre os utilizadores.
 *
 * @param empresas Array de estruturas Empresa contendo os dados das empresas.
 * @param num_empresas Número de empresas no array empresas.
 */
void gerarRelatorioEmpresasMaisComentadas(Empresa *empresas, int num_empresas) {
    EmpresaRelatorioComentarios relatorio[MAX_EMPRESAS];

    // Preencher dados para relatório
    for (int i = 0; i < num_empresas; i++) {
        strcpy(relatorio[i].nome, empresas[i].nome);
        strcpy(relatorio[i].nif, empresas[i].nif);
        relatorio[i].numComentarios = empresas[i].nComments;
    }

    // Ordenar empresas por número de comentários
    qsort(relatorio, num_empresas, sizeof(EmpresaRelatorioComentarios), compararPorComentarios);

    // Exibir relatório
    printf("\nEmpresas Mais Comentadas:\n");
    for (int i = 0; i < num_empresas; i++) {
        printf("Empresa: %s, NIF: %s, Comentários: %d\n", relatorio[i].nome, relatorio[i].nif, relatorio[i].numComentarios);
    }
}
/**
 * @brief Função de comparação para ordenar empresas pela classificação média.
 *
 * Esta função é utilizada com qsort para comparar duas estruturas EmpresaRelatorioMedia.
 * Ordena as empresas em ordem decrescente da média de suas classificações.
 *
 * @param a O ponteiro para o primeiro elemento de EmpresaRelatorioMedia a ser comparado.
 * @param b O ponteiro para o segundo elemento de EmpresaRelatorioMedia a ser comparado.
 * @return -1 se a média de classificação da primeira empresa for maior que a da segunda,
 *          1 se for menor, e 0 se forem iguais.
 */
int compararPorMedia(const void *a, const void *b) {
    EmpresaRelatorioMedia *empresaA = (EmpresaRelatorioMedia *)a;
    EmpresaRelatorioMedia *empresaB = (EmpresaRelatorioMedia *)b;
    if (empresaB->mediaClassificacao > empresaA->mediaClassificacao) return 1;
    else if (empresaB->mediaClassificacao < empresaA->mediaClassificacao) return -1;
    else return 0;
}
/**
 * @brief Gera e exibe um relatório das empresas ordenadas pela média de classificações.
 * 
 * Este relatório lista as empresas de acordo com a média das classificações recebidas,
 * do maior para o menor valor médio. A função é útil para identificar as empresas com
 * melhor desempenho segundo a avaliação dos usuários.
 *
 * @param empresas Array de estruturas Empresa contendo os dados das empresas.
 * @param num_empresas Número de empresas no array empresas.
 */
void gerarRelatorioMediaClassificacoes(Empresa *empresas, int num_empresas) {
    EmpresaRelatorioMedia relatorio[MAX_EMPRESAS];

    for (int i = 0; i < num_empresas; i++) {
        strcpy(relatorio[i].nome, empresas[i].nome);
        strcpy(relatorio[i].nif, empresas[i].nif);

        int somaClassificacoes = 0;
        for (int j = 0; j < empresas[i].nclass; j++) {
            somaClassificacoes += empresas[i].classis[j].classificacao;
        }

        if (empresas[i].nclass > 0) {
            relatorio[i].mediaClassificacao = (float)somaClassificacoes / empresas[i].nclass;
        } else {
            relatorio[i].mediaClassificacao = 0; // Pode definir um valor padrão para empresas sem classificações
        }
    }

    qsort(relatorio, num_empresas, sizeof(EmpresaRelatorioMedia), compararPorMedia);

    printf("\nEmpresas Ordenadas por Média de Classificação:\n");
    for (int i = 0; i < num_empresas; i++) {
        printf("Empresa: %s, NIF: %s, Média de Classificação: %.2f\n", relatorio[i].nome, relatorio[i].nif, relatorio[i].mediaClassificacao);
    }
}