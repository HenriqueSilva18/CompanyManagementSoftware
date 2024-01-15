/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   classificacao_comentario.h
 * Author: Henri
 *
 * Created on 4 de janeiro de 2024, 15:04
 */

#ifndef UTILIZADOR_H
#define UTILIZADOR_H
#include "gestao_empresas.h"
#define MAX_TITULO 30

void printfEmpresa(Empresa *empresa);
void pesquisarEmpresas(Empresa *empresas, int num_empresas);
void classificarEmpresas(Empresa *empresas, int num_empresas);
void comentarEmpresas(Empresa *empresas, int num_empresas);
void liberarMemoriaEmpresas(Empresa *empresas, int num_empresas);
void liberarMemoriaClassificacoes(Empresa *empresa);

#endif /* UTILIZADOR_H */

