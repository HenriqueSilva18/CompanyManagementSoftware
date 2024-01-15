/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: Mariana Silvas
 */

#include <stdio.h>
#include <stdlib.h>
#include "gestao_empresas.h"
#include "utilizador.h"
#include "Gestao_Ramos_Atividades.h"
#include "input.h"
#include "ficheiros.h"
#include "relatorios.h"

int main(int argc, char** argv) {
    
    Empresas empresas = {0, NULL};
    
    EmpresaRelatorioComentarios *relComentarios = NULL;
    int numRelComentarios = 0;
    EmpresaRelatorioMedia *relMedia = NULL;
    int numRelMedia = 0;
    Ramo_Atividade *ramos = NULL;
    
    empresas.alocadas = 0;
    empresas.contador = 0;
    empresas.empresas = NULL;
    int num_empresas = 0;
    int num_ramos = 0;
    
    carregarTodosOsDados(&empresas, &relComentarios, &numRelComentarios, &relMedia, &numRelMedia, &ramos, &num_ramos, NOME_FICHEIRO);
    
    int op, op1, op2, opc3, opc4, opc5, opcao3;

    //Menu Principal
    do {
        puts("-           EMPRESA          -");
        printf("1-Perfil de Administrador\n");
        printf("2-Perfil de Utilizador\n");
        printf("3-Empresa\n");
        printf("4-Sair\n");
        printf("Opção: ");
        scanf("%d", &op);

        //Validação da opção variavél op
        while ((op < 1) || (op > 4)) {
            printf("Caracter não reconhecido!\n");
            printf("Insira novamente a sua opção\n");
            scanf("%d", &op);
        }
        switch (op) {
            case 1:
                //Menu do Administrador
                do {
                    puts("-       PERFIL ADMINISTRADOR       -");
                    puts("1-Gerir o Catálogo de empresa");
                    puts("2-Gerir Ramos de Atividade");
                    puts("3-Visualizar Relatórios");
                    puts("4-Voltar ao menu anterior");
                    puts("5-Sair");
                    printf("Opção: ");
                    limparBuffer();
                    scanf("%d", &op1);

                    //Validação da opção a cima variável op1
                    while ((op1 < 1) || (op1 > 5)) {
                        printf("Caracter não reconhecido!\n");
                        printf("Insira novamente a sua opção\n");
                        limparBuffer();
                        scanf("%d", &op1);
                    }

                    switch (op1) {
                        case 1:
                            //Menu Gerir Catálogo de empresa
                            do {
                                puts("\n");
                                puts("-  Gerir o Catálogo de empresa  -");
                                puts("1-Criar Empresa");
                                puts("2-Editar Empresa");
                                puts("3-Remover Empresa");
                                puts("4-Voltar ao menu anterior");
                                puts("5-Sair do programa");
                                printf("Opção: ");
                                limparBuffer();
                                scanf("%d", &opc3);
                                //Validação da opção variável opc3
                                while ((opc3 < 1) || (opc3 > 5)) {
                                    printf("Caracter não reconhecido!\n");
                                    printf("Insira novamente a sua opção\n");
                                    limparBuffer();
                                    scanf("%d", &opc3);
                                }
                                switch (opc3) {
                                    case 1:
                                        criarEmpresa(&empresas, &num_empresas);
                                        break;
                                    case 2:
                                        editarEmpresa(empresas.empresas, &num_empresas);
                                        break;
                                    case 3:
                                        removerEmpresa(empresas.empresas, &num_empresas);
                                        break;
                                    case 4:
                                        puts("\n");
                                        break;
                                    case 5:
                                        op1 = 5;
                                        op = 4;
                                        break;
                                }
                            } while ((opc3 != 4)&&(opc3 != 5));
                            break;
                        case 2:
                            do {
                                //Menu Gerir Ramo de Atividade
                                puts("-    Gerir Ramos de Atividade    -");
                                puts("1-Criar Ramo de Atividades");
                                puts("2-Editar Ramo de Atividades");
                                puts("3-Remover Ramo de Atividades");
                                puts("4-Voltar ao menu anterior");
                                puts("5-Sair do programa");
                                printf("Opção: ");
                                limparBuffer();
                                scanf("%d", &opc4);
                                //Validação da opção variável opc4
                                while ((opc4 < 1) || (opc4 > 5)) {
                                    printf("Caracter não reconhecido!\n");
                                    printf("Insira novamente a sua opção\n");
                                    limparBuffer();
                                    scanf("%d", &opc4);
                                }
                                switch (opc4) {
                                    case 1:
                                        criarRamoAtividade(&ramos, &num_ramos);
                                        //criarRamoAtividade(ramos, &num_ramos);
                                        break;
                                    case 2:
                                        editarRamoAtividade(ramos, &num_ramos);
                                        //editarRamoAtividade(ramos, num_ramos);
                                        break;
                                    case 3:
                                        removerRamoAtividade(ramos, &num_ramos);
                                        //removerRamoAtividade(ramos, &num_ramos, empresas, num_empresas);
                                        break;
                                    case 4:
                                        puts("\n");
                                        op = 0;
                                        break;
                                    case 5:
                                        op1 = 5;
                                        op = 4;
                                        break;
                                }
                            } while ((opc4 != 4) && (opc4 != 5));
                            break;
                        case 3:
                            //Visualizar Comentários e Classificações das empresas
                            do {
                                //Menu Gerir Ramo de Atividade
                                puts("\n-    Visualizar Relatórios    -");
                                puts("1-Empresas por classificação média");
                                puts("2-Empresas por nº de comentários");
                                puts("3-Voltar ao menu anterior");
                                puts("4-Sair do programa");
                                printf("Opção: ");
                                limparBuffer();
                                scanf("%d", &opcao3);
                                //Validação da opção variável opcao3
                                while ((opcao3 < 1) || (opcao3 > 5)) {
                                    printf("Caracter não reconhecido!\n");
                                    printf("Insira novamente a sua opção\n");
                                    limparBuffer();
                                    scanf("%d", &opcao3);
                                }
                                switch (opcao3) {
                                    case 1: // Opção para Visualizar Empresas mais comentadas
                                        gerarRelatorioMediaClassificacoes(empresas.empresas, num_empresas);
                                        break;
                                    case 2: // Outra opção para relatório de média de classificações
                                        gerarRelatorioEmpresasMaisComentadas(empresas.empresas, num_empresas);
                                        break;
                                    case 3:
                                        puts("\n");
                                        opcao3 = 4;
                                        break;
                                    case 4:
                                        op1 = 5;
                                        op = 4;
                                        opc4 = 4;
                                        break;
                                }
                            } while (opcao3 != 4) ;
                            //Função para visualizar os comentarios e as classificações
                            break;
                        case 4:
                            puts("\n");
                            op = 0;
                            break;
                        case 5:
                            op = 4;
                            break;
                    }
                } while ((op1 != 4)&&(op1 != 5));
                break;

            case 2:
                //Menu do Utilizador
                do {
                    puts("***********UTILIZADOR*************");
                    puts("1-Pesquisar Empresas");
                    puts("2-Classificar Empresas");
                    puts("3-Comentar Empresas");
                    puts("4-Voltar ao menu anterior");
                    puts("5-Sair do programa");
                    printf("Opção: ");
                    limparBuffer();
                    scanf("%d", &op2);
                    //Validação da opção variável op2
                    while ((op2 < 1) || (op2 > 5)) {
                        printf("Caracter não reconhecido!\n");
                        printf("Insira novamente a sua opção\n");
                        limparBuffer();
                        scanf("%d", &op2);
                    }
                    switch (op2) {
                        case 1:
                            pesquisarEmpresas(empresas.empresas, num_empresas);
                            break;
                        case 2:
                            classificarEmpresas(empresas.empresas, num_empresas); 
                            break;
                        case 3:
                            comentarEmpresas(empresas.empresas, num_empresas);
                            break;
                        case 4:
                            puts("\n");
                            op = 0;
                            break;
                        case 5:
                            op = 4;
                            break;
                    }
                } while ((op2 != 4)&&(op2 != 5));
                break;

            case 3:
                //Empresas FAZER CASO DER TEMPO
                break;
        }
    } while (op != 4);
    
    salvarTodosOsDados(&empresas, relComentarios, numRelComentarios, relMedia, numRelMedia, ramos, num_ramos, NOME_FICHEIRO);
    // Liberar memória alocada
    for (int i = 0; i < empresas.contador; i++) {
        free(empresas.empresas[i].classis);
        empresas.empresas[i].classis = NULL;
        
        free(empresas.empresas[i].comments);
        empresas.empresas[i].comments = NULL;
    }
    free(empresas.empresas);
    empresas.empresas = NULL;
    
    free(relComentarios);
    relComentarios = NULL;
    
    free(relMedia);
    relMedia = NULL;
    
    free(ramos);
    ramos = NULL;
    
    return (EXIT_SUCCESS);
}


