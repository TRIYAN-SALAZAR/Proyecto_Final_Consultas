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
#include <windows.h>

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
void show_user(int i);

void show_all();
void table_header();
void clear_screen();
void wait_an_action();

int main()
{
    load_data_from_file();

    while(1) {
        int opt, band = 0;
        opt = menu();
        switch (opt) {
        case 1:
            clear_screen();
            find_data(opt);
            wait_an_action();
            break;
        case 2:
            clear_screen();
            find_data(opt);
            wait_an_action();
            break;
        case 3:
            clear_screen();
            find_data(opt);
            wait_an_action();
            break;
        case 4:
            band = 1;
            break;
        default:
            printf("\nEsa opcion no es valida\n");
            break;
        }

        if(band)
            break;
    }
    printf("GRACIAS POR UTILIZAR ESTE PROGRAMA");
    return 0;
}

int menu() {
    int opt;
    printf("\n----------------- Menu -----------------");
    printf("\n1) Mostrar alumnos menores de 20 a%cos", 164);
    printf("\n2) Mostrar alumnos de 20 a%cos", 164);
    printf("\n3) Mostrar alumnos mayores de 20 a%cos", 164);
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

void find_data(int type) {
    int i = 0;
    if(type == 1 ) printf("\n\tAlumnos Menores a 20 a%cos", 164);
    if(type == 2 ) printf("\n\t   Alumnos de 20 a%cos", 164);
    if(type == 3 ) printf("\n\tAlumnos Mayores a 20 a%cos", 164);
    printf("\n");
    table_header();
    while(i < MAX_USERS) {
        int age = users[i].age;
        // printf("\nedad test: %d", age);
        if(age < 20 && type == 1) show_user(i);
        if(age == 20 && type == 2) show_user(i);
        if(age > 20 && type == 3) show_user(i);
        i++;
    }
    printf("+--------------------+-------+---------+\n");
}

void show_user(int i) {
    printf("| %-18s | %-5d | %-6s  |\n", users[i].name, users[i].age, users[i].career);
}

void table_header() {
    printf("+--------------------+-------+---------+\n");
    printf("| Nombre             | Edad  | Carrera |\n");
    printf("+--------------------+-------+---------+\n");
}

void show_all() {
    int i;
    table_header();
    for(i = 0; i < MAX_USERS; i++) {
        show_user(i);
    }
}

void clear_screen() {
    system("cls");
}

void wait_an_action() {
    printf("\n\nPresione ENTER para continuar...");
    fflush(stdin);
    getchar();
}
