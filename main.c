#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILENAME_MAX 64

// Ne pas modifier
void init_file(){
    // data.txt
    FILE* f = fopen("data.txt", "w");
    if (f)
    {
        fprintf(f, "5\n12\n8\n1\n19\n");
        fclose(f);
    }

    // data2.txt
    f = fopen("data2.txt", "w");
    if (f)
    {
        fprintf(f, "10\n20\n30\n");
        fclose(f);
    }

    // data3.txt
    f = fopen("data3.txt", "w");
    if (f)
    {
        fprintf(f, "1\n2\n3\n4\n5\n");
        fclose(f);
    }

    // data_vide.txt
    f = fopen("data_vide.txt", "w");
    if (f)
    {
        fclose(f);  // fichier vide
    }
}



typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef struct
{
    Node* head;
    Node* tail;
} List;

// Fonctions de base
void append(List* list, int value){
}

void free_list(List* list){
}

void print_list(const List* list){
}

void reverse_list(List* list){
}

int sum_list(const List* list){
    return 0;
}

int min_list(const List* list){
    return 0;
}

int max_list(const List* list){
    return 0;
}

void filter_list(List* list, int threshold){
}

void help(){
    printf("Utilisation : ./app <fichier> [options]\n\n");
    printf("Options disponibles :\n");
    printf("  --reverse         Inverse l'ordre des éléments\n");
    printf("  --sum             Affiche la somme des éléments\n");
    printf("  --filter <val>    Filtre les éléments >= val\n");
    printf("  --add <val>       Ajoute une valeur à la fin du fichier\n");
    printf("  --help            Affiche ce message d'aide\n");
    printf("  --version, -v     Affiche la version du programme\n");
    printf("  --min             Affiche la valeur minimale de la liste\n");
    printf("  --max             Affiche la valeur maximale de la liste\n");
}

// Lecture fichier
bool read_file(const char* filename, List* list){
    FILE* f = fopen(filename, "r");
    if (!f) return false;
    int value;
    
    while (fscanf(f, "%d", &value) == 1) append(list, value);
    
    fclose(f);
    return true;
}

bool add_to_file(const char* filename, int value){
    FILE* f = fopen(filename, "a");
    if (!f) return false;
    fprintf(f, "%d\n", value);
    fclose(f);
    return true;
}

int main(int argc, char* argv[]){
    // Ne pas modifier
    init_file();
    // ---------------

    if (argc < 2){
        printf("Il manque des arguments !!!\n");
        exit(1);
    }
    
    bool reverse = false;
    bool sum = false;
    bool filter = false;
    bool add = false;
    int add_value = 0;
    int filtervalue = 0;
    bool max = false;
    bool min = false;
    char* filename[FILENAME_MAX]={0};
    for (int i = 1; i < argc; i++){
        if (strcmp(argv[i], "--help") == 0){
            printf("Utilisation : ./app <fichier> [options]\n\n");
            printf("Options disponibles :\n");
            printf("  --reverse         Inverse l'ordre des éléments\n");
            printf("  --sum             Affiche la somme des éléments\n");
            printf("  --filter<val>    Filtre les éléments >= val\n");
            printf("  --add<val>       Ajoute une valeur à la fin du fichier\n");
            printf("  --help            Affiche ce message d'aide\n");
            printf("  --version, -v     Affiche la version du programme\n");
            return 0;
        }
        if (strcmp(argv[i], "--reverse") == 0){
            reverse = true;
            printf("reverse\n");
            continue;
        }
        if (strcmp(argv[i], "--sum") == 0){
            sum = true;
            continue;
        }
        if (sscanf(argv[i], "--filter%d", &filtervalue) == 1){
            filter = true;
            printf("filter value : %d\n", filtervalue);
            continue;
        }
        if (sscanf(argv[i], "--add%d", &add_value) == 1){
            add = true;
            printf("added value : %d\n", add_value);
            continue;
        }
        if ((strcmp(argv[i], "--version")==0) || (strcmp(argv[i], "-v")==0)){
            printf("version 1.0\n");
            continue;
        }
        if (strcmp(argv[i], "--min")==0){
            min = true;
            continue;
        }
        if (strcmp(argv[i], "--max")==0){
            max = false;
            continue;
        }
        else{
            strcpy(filename, argv[i]);
            printf("filename : %s\n", filename);
            continue;
        }
    }
    


    return 0;
}