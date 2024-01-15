/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

/*
 * @file Input.c
 * @author Mariana Silva | Henrique Silva
 * @date 15/01/24
 * @version 1
 * 
 * @brief 
 */

#include <stdio.h>
#include <string.h>

#define VALOR_INVALIDO "O valor introduzido Ã© invalido."

void limparBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getInt(int minValue, int maxValue, char *msg) {
    int value;
    printf(msg);
    while (scanf("%d", &value) != 1 || value < minValue || value > maxValue) {
        puts(VALOR_INVALIDO);
        limparBuffer();
        printf(msg);
    }
    limparBuffer();
    return value;
}

float getFloat(float minValue, float maxValue, char *msg) {
    float value;
    printf(msg);
    while (scanf("%f", &value) != 1 || value < minValue || value > maxValue) {
        puts(VALOR_INVALIDO);
        limparBuffer();
        printf(msg);
    }
    limparBuffer();
    return value;
}

double getDouble(double minValue, double maxValue, char *msg) {
    double value;
    printf(msg);
    while (scanf("%lf", &value) != 1 || value < minValue || value > maxValue) {
        puts(VALOR_INVALIDO);
        limparBuffer();
        printf(msg);
    }
    limparBuffer();
    return value;
}

char getChar(char *msg) {
    char value;
    printf(msg);
    value = getchar();
    limparBuffer();
    return value;
}

void readString(char *string, unsigned int size, char *msg) {
    printf(msg);
    if (fgets(string, size, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            limparBuffer();
        }
    }
}