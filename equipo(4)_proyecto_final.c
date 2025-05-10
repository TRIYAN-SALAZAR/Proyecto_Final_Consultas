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

#define MAX_USERS 6

typedef struct
{
    char name[10];
    char career[7];
    int age;
} User;

User users[MAX_USERS];

int menu();
void load_data_from_file();
void find_data(int type);

int main()
{
    load_data_from_file();
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

int menu() {
    int opt;
    printf("\n----------- Menu -----------");
    printf("\n1) Mostrar alumnos menores de 20 años");
    printf("\n2) Mostrar alumnos de 20 años");
    printf("\n3) Mostrar alumnos mayores de 20 años");
    printf("\n4) Salir\n");

    scanf("%d", &opt);
    return opt;
}

void load_data_from_file()
{
    FILE *file = fopen("alumnos.txt", "r");

    if (file == NULL)
        printf("No se pudo abrir el archivo");

    char buffer[256];
    int totalRegisters = 0;

    fgets(buffer, sizeof(buffer), file);
    fgets(buffer, sizeof(buffer), file);

    while (fgets(buffer, sizeof(buffer), file))
    {
        if (buffer[0] == '+')
            continue;

        char name[30], career[10];
        int age;

        sscanf(buffer, "| %29[^|] | %d | %9[^|] |", name, &age, career);

        name[strcspn(name, " ")] = '\0';
        career[strcspn(career, " ")] = '\0';

        strcpy(users[totalRegisters].name, name);
        strcpy(users[totalRegisters].career, career);
        users[totalRegisters].age = age;
        totalRegisters++;

        if (totalRegisters >= MAX_USERS)
            break;
    }

    fclose(file);
}

void find_data(int type) {}