/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * @file:   Input.h
 * @author Mariana Silva | Henrique Silva
 * @date 15/01/24
 * @version 1
 * 
 * @brief 
 */

#ifndef INPUT_H
#define INPUT_H

void limparBuffer();
int getInt(int, int, char *);
float getFloat(float, float, char *);
double getDouble(double, double, char *);
char getChar(char *);
void readString(char *, unsigned int, char *);

#endif /* INPUT_H */