/*
    Author: Sergio Raya
    Date: 02/11/2023
    Version: 1.0
*/ 
typedef struct Contacto {
    char nombre[25];
    int telefono;
    char email[50];
} Contacto;

void createContact(char nombre[], int telefono, char email[]);


