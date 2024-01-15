/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   gestao_empresas.h
 * Author: Mariana Silva
 */



#ifndef GESTAO_EMPRESAS_H
#define GESTAO_EMPRESAS_H

#define ALOCACAO_EMPRESAS   2
#define MAX_EMPRESAS        10
#define MAX_COMENTARIOS     200
#define MAX_CLASSIFICACAO   2
#define MAX_NIF             10
#define MAX_NOME_EMPRESA    60
#define MAX_CATEGORIA       20
#define MAX_RUA             30
#define MAX_LOCALIDADE      15
#define MAX_CODIGO_POSTAL   9
#define MAX_NOME_RAMO       15
#define MAX_RAMOS_ATIVIDADE 10
#define MAX_EMAIL           50

typedef struct {
    char nifEmpresa[MAX_NIF];
    char nome[MAX_NOME_EMPRESA];
    char email[MAX_EMAIL]; // Adicionado o campo para o email
    char titulo[MAX_NOME_EMPRESA];
    char comentario[MAX_COMENTARIOS];
    char estado; // 'A' para ativo, 'I' para inativo
} Comentario;

typedef struct {
    char nifEmpresa[MAX_NIF];
    int classificacao;
    char estado;
} Classificacao;


typedef struct {
    int id;
    char nif[MAX_NIF];
    char nome[MAX_NOME_EMPRESA];
    char categoria[MAX_CATEGORIA];
    char ramo_atividade[MAX_RAMOS_ATIVIDADE];
    char rua[MAX_RUA];
    char localidade[MAX_LOCALIDADE];
    char codigo_postal[MAX_CODIGO_POSTAL];
    int estado;
    int nclass;
    Classificacao *classis;
    int nComments;
    Comentario *comments;
} Empresa;

typedef struct {
    int contador, alocadas;
    Empresa *empresas;
} Empresas;

int validarCodigoPostal(const char *codigo_postal);
void criarEmpresa(Empresas *empresas, int *num_empresas);
void editarEmpresa(Empresa *empresas, int *num_Empresas);
void removerEmpresa(Empresa *empresas, int *num_Empresas);
#endif /* GESTAO_EMPRESAS_H */

