/*
    Integrantes:
        Ozuna Salazar Jorge Alejandro
        Pulido Moreno Hugo Nicolas
        Ramírez Sánchez Miguel Angel
    PROYECTO FINAL - Archivo de acceso secuencial – consultas filtradas
    Fecha: 10 de Mayo del 2025
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct users
{
    char name[10];
    char career[7];
    int age;
};


int menu();
void load_data_from_file();
void find_data(int type);

int main() {
    while(1) {
        int opt, band = 0;
        opt = menu();
        switch (opt)
        {
        case 1:
            find_data(opt);
            break;
        case 2:
            find_data(opt);
            break;
        case 3:
            find_data(opt);
            break;
        case 4:
            band = 1;
            break;
        default:
            break;
        }

        if(band)
            break;
    }
    return 0;
}

int menu() {}

void load_data_from_file() {}

void find_data(int type) {}