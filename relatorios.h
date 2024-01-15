/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   relatorios.h
 * Author: Henri
 *
 * Created on 13 de janeiro de 2024, 16:10
 */

#ifndef RELATORIOS_H
#define RELATORIOS_H
#include <stdio.h>
#include <string.h>
#include "Gestao_Empresas.h" 
#include "Gestao_Ramos_Atividades.h"

typedef struct {
    char nome[MAX_NOME];
    char nif[MAX_NIF];
    int numComentarios;
} EmpresaRelatorioComentarios;

typedef struct {
    char nome[MAX_NOME];
    char nif[MAX_NIF];
    float mediaClassificacao;
} EmpresaRelatorioMedia;

void gerarRelatorioEmpresasMaisComentadas(Empresa *empresas, int num_empresas);
void gerarRelatorioMediaClassificacoes(Empresa *empresas, int num_empresas);



#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* RELATORIOS_H */

