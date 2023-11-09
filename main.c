/*
    Author: Sergio Raya
    Date: 02/11/2023
    Version: 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

void showContact (int contactId, Contact contactList[]);
void getData(char* name, char* email, int* phone);

int main (void) {
    char nombre[25], cntName[25], cntMail[50];
    int control = 1, contactNum, cntPhone, contador = 0, contactoId;

    system("cls");
    printf("Identify yourself! Input your name: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    printf("\nCreating contact list ... ");

    printf("\nEnter the maximum number of contacts your list will have: ");
    scanf("%d", &contactNum);
    Contact contactList[contactNum]; // Create ContactList
    printf("\nCreated!\n ... \n ");

    printf("\nWelcome %s!\n", nombre);
    printf("To the Contact Management System. Thanks for choosing us!\n\n");

    do {
        printf("\n---------- | Contact Management System | ----------\n");
        printf("\n1. Add contact");
        printf("\n2. Modify contact");
        printf("\n3. List of contacts");
        printf("\n4. Delete contact");
        printf("\n5. Exit program");
        printf("\nInput your choice: ");
        scanf("%d", &control);


        switch (control) {      // mirar otras opciones para remplazar el switch por algo más óptimo.
        case 1:
            getData(cntName, cntMail, &cntPhone);
            createContact(cntName, cntPhone, cntMail, &contactList[contador]);
            printf("\n\n\nContact created!\n");
            contador++; 

            break;
        case 2:
            printf("\n\nEnter the id number of the contact to modify it: ");
            scanf("%d", &contactoId);
            contactoId--; // Más amigable

            printf("\nUser %d: \n", contactoId + 1);
            showContact(contactoId, &contactList[0]);

            getData(cntName, cntMail, &cntPhone);
            modifyContact(cntName, cntMail, cntPhone, &contactList[contactoId]);
            printf("\n\n\nContact modified!\n");

            break;
        case 3:
            for (int i = 0; i < contador; i++){
                printf("\nContact %d: \n", i + 1);
                showContact(i, &contactList[0]);
            }

            break;
        case 4:
            printf("\n\nEnter the id number of the contact to delete it: ");
            scanf("%d", &contactoId);

            printf("\n\n\nContact %s deleted!\n", contactList[contactoId-1].nombre);
            deleteContact(&contactList[0], contactoId, contactNum);
            contador--; // Restamos un contacto.
            break;
        case 5:
            control = 0;
            break;

        default:
            system("cls");
            printf("ERROR!\n");
            printf("%d Is NOT a valid option. You have to choose between the 5 options.", control);
            break;
        }

    } while (control != 0);

    system("cls");
    printf("\n\nExit with success!\n");
    printf("\nHave a great day %s!\n\n", nombre);

}




void showContact (int contactId, Contact contactList[]) {
    printf("%s\n", contactList[contactId].nombre);
    printf("%s\n", contactList[contactId].email);
    printf("%d\n", contactList[contactId].telefono);
}

void getData(char* name, char* email, int* phone) {
    char cntName[25], cntMail[50];
    int cntPhone;

    printf("\n\nInput contact's name: ");
    fflush(stdin);
    scanf("%[^\n]", cntName);

    printf("Input contact's email: ");
    fflush(stdin);
    scanf("%[^\n]", cntMail);

    printf("Input contact's phone: ");
    scanf("%d", &cntPhone);

    strncpy(name, cntName, sizeof(cntName));
    strncpy(email, cntMail, sizeof(cntMail));
    *phone = cntPhone;
}
