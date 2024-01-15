/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Gestao_Ramos_Atividades.h
 * Author: maria
 *
 * Created on 22 de dezembro de 2023, 14:38
 */

#ifndef GESTAO_RAMOS_ATIVIDADES_H
#define GESTAO_RAMOS_ATIVIDADES_H

#define MAX_RAMOS_ATIVIDADES 10
#define MAX_NOME 60 

typedef struct{
    int id_Ramos;
    char nome_ramo[MAX_NOME];
    char estado; // 0 - Inativo | 1 - Ativo
}Ramo_Atividade;

void criarRamoAtividade(Ramo_Atividade **ramos, int *num_Ramos);
void editarRamoAtividade(Ramo_Atividade *ramos, int *num_Ramos);
void removerRamoAtividade(Ramo_Atividade *ramos, int *num_Ramos);

#endif /* GESTAO_RAMOS_ATIVIDADES_H */

