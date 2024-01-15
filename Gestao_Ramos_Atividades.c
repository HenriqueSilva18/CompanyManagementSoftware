/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   Gestão_Ramos_Atividades.c
 * Author: mariana
 *
 * Created on 22 de dezembro de 2023, 12:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gestao_Ramos_Atividades.h"
#include "input.h"
/**
 * 
 * @param ramos
 * @param num_Ramos
 */
void criarRamoAtividade(Ramo_Atividade **ramos, int *num_Ramos) {
    // Verificar o limite de ramos antes de alocar mais memória
    if (*num_Ramos >= MAX_RAMOS_ATIVIDADES) {
        printf("Não é possível adicionar mais ramos de atividades.\n");
        return;
    }

    // Realocar memória para um novo ramo de atividade
    Ramo_Atividade *temp_ramos = realloc(*ramos, (*num_Ramos + 1) * sizeof(Ramo_Atividade));
    if (temp_ramos == NULL) {
        printf("Erro: Memória insuficiente.\n");
        return;
    }

    *ramos = temp_ramos;
    Ramo_Atividade *novoRamo = &(*ramos)[*num_Ramos];

    novoRamo->id_Ramos = *num_Ramos + 1;  // Ou outra lógica para o ID

    printf("Nome do Ramo de Atividade: ");
    scanf("%s", novoRamo->nome_ramo);

    novoRamo->estado = 1;  // Novo ramo é marcado como ativo

    (*num_Ramos)++;
    puts("Ramo de Atividade criado com sucesso!\n");
}


/**
 *  Esta função serve para editar o nome dde ramos de atividade
 * @param ramos
 * @param num_Ramos
 */
void editarRamoAtividade(Ramo_Atividade *ramos, int *num_Ramos){
    int lerID;
    if (*num_Ramos == 0) {
        puts("Não existem Ramos de atividades.");
        return;
    }
    
    puts ("|   Editar Ramo de Atividade   |");
    
    puts("\nLista de Ramos de Atividades: ");
    for (int i = 0; i < *num_Ramos; i++){
        printf("ID: %d\n", ramos[i].id_Ramos);
        printf("Nome do Ramo de Atividade: %s\n", ramos[i].nome_ramo);   
    }
    puts ("Insira o ID do Ramo de Atividade que pretende editar: ");
    scanf("%d", &lerID);
    
    int ramoencontrado = 0;
    for (int i = 0; i< *num_Ramos; i++){
        if (ramos[i].id_Ramos== lerID){
            ramoencontrado = 1;
            break;
        } 
    }
    if (!ramoencontrado){
        puts("ID do Ramo de Atividade não existe!");
        return;
    }
    char novoNome[MAX_NOME];
    puts("Alterar o nome do Ramo de Atividade para: ");
    scanf("%s", novoNome);
    
     // Libera a memória antiga antes de alocar nova memória para o nome
    free(ramos[lerID - 1].nome_ramo);
    
    // Transfere o valor de novoNome para a variavel nome 
    strcpy(ramos[lerID - 1].nome_ramo, novoNome);
    
    
   char *temp_nome = (char *)malloc(strlen(novoNome) + 1);

   
}

void removerRamoAtividade(Ramo_Atividade *ramos, int *num_Ramos){
    //verificar se o ramo está ativo em alguma empresa 
    char lerNome[MAX_NOME];
    if (*num_Ramos == 0){
        printf("Não existem Ramos de Atvidade!");
        return;
    }
    puts("/nLista de Ramos de Atividades: ");
    for (int i = 0; i < *num_Ramos; i++){
        printf("ID: %d\n", ramos[i].id_Ramos);
        printf("Nome do Ramo de Atividade: %s\n", ramos[i].nome_ramo);   
    }
    puts ("Insira o nome do Ramo de Atividade que pretende remover: ");
    scanf("%s", lerNome);
    
    for (int i = 0; i < *num_Ramos; i++) {
        if (strcmp(ramos[i].nome_ramo, lerNome) == 0) {
            if (ramos[i].estado == 1){
                printf("Este Ramo de Atividade está associado a uma empresa. Não pode ser removido.\n");
            } else {
                free(ramos[i].nome_ramo);
                
                for (int j = i; j < (*num_Ramos - 1); j++) {
                    ramos[j] = ramos[j + 1];
                }
                
                (*num_Ramos)--;
                
                puts("Ramo de Atividade removido com sucesso!\n");
                // Ajuste num_Ramos e faça a remoção do ramo da lista se necessário
            }
            return;
        }
    }
    puts("Nome do Ramo de Atividade não encontrado!\n");
    return;
}
    
    
    
//SO O ADMINISTRADOR PODE COLOCAR A EMPRESA ATIVA