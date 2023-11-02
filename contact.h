/*
    Author: Sergio Raya
    Date: 02/11/2023
    Version: 1.0
*/ 
typedef struct Contact {
    char nombre[25];
    int telefono;
    char email[50];
} Contact;

void createContact(char nombre[], int telefono, char email[], Contact *contactList);
void modifyContact(char[], char[], int, Contact*);


