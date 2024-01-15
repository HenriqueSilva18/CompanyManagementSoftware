/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   ficheiros.h
 * Author: Henri
 *
 * Created on 11 de janeiro de 2024, 21:51
 */

#ifndef FICHEIROS_H
#define FICHEIROS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Gestao_Empresas.h"
#include "utilizador.h"
#include "relatorios.h"
#define NOME_FICHEIRO "empresas.bin"
void salvarTodosOsDados(Empresas *empresas, EmpresaRelatorioComentarios *relComentarios, int numRelComentarios, EmpresaRelatorioMedia *relMedia, int numRelMedia, Ramo_Atividade *ramos, int num_ramos, const char *nomeArquivo);
void carregarTodosOsDados(Empresas *empresas, EmpresaRelatorioComentarios **relComentarios, int *numRelComentarios, EmpresaRelatorioMedia **relMedia, int *numRelMedia, Ramo_Atividade **ramos, int *num_ramos, const char *nomeArquivo);
void salvarDadosEmpresas(Empresas *empresas, FILE *arquivo);
void carregarDadosEmpresas(Empresas *empresas, FILE *arquivo);
void salvarDadosRelatorios(EmpresaRelatorioComentarios *relComentarios, int numRelComentarios, EmpresaRelatorioMedia *relMedia, int numRelMedia, FILE *arquivo);
void carregarDadosRelatorios(EmpresaRelatorioComentarios **relComentarios, int *numRelComentarios, EmpresaRelatorioMedia **relMedia, int *numRelMedia, FILE *arquivo);
void salvarDadosRamos(Ramo_Atividade *ramos, int num_ramos, FILE *arquivo);
void carregarDadosRamos(Ramo_Atividade **ramos, int *num_ramos, FILE *arquivo);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* FICHEIROS_H */

