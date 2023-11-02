/*
    Author: Sergio Raya
    Date: 02/11/2023
    Version: 1.0
*/

#include <stdio.h>
#include <string.h>
#include "contact.h"

int main (void) {
    char nombre[25], cntName[25], cntMail[50];
    int control = 1, contactNum, cntPhone, contador = 0, contactoId;

    printf("Identify yourself! Input your name: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    printf("\nCreating contact list ... ");

    printf("\nEnter the maximum number of contacts your list will have: ");
    scanf("%d", &contactNum);
    Contact contactList[contactNum]; // Create ContactList
    printf("\nCreated!\n ... \n ");
    
    printf("\nWelcome %s!\n", nombre);
    printf("To the Contact Management System. Here you will be abel to manage, create, delete and watch your contacts. Thanks for choosing us!\n\n");
    do {
        printf("\n---------- | Contact Management System | ----------\n");
        printf("\n1. Add contact");
        printf("\n2. Modify contact");
        printf("\n3. List of contacts");
        printf("\n4. Delete contact");
        printf("\n5. Exit program");
        printf("\nInput your choice: ");
        scanf("%d", &control);

        switch (control) {      // mirar otras opciones para remplazar el switch por algo más optimo
        case 1:
            printf("\n\nInput contact's name: ");
            fflush(stdin);
            fgets(cntName, sizeof(cntName), stdin);

            printf("Input contact's email: ");
            fflush(stdin);
            fgets(cntMail, sizeof(cntMail), stdin);

            printf("Input contact's phone: ");
            scanf("%d", &cntPhone);

            cntName[strcspn(cntName, "\n")] = '\0';
            cntMail[strcspn(cntMail, "\n")] = '\0';

            createContact(cntName, cntPhone, cntMail, &contactList[contador]);
            contador++;
            printf("\n\n\nContact created!\n");

            break;
        case 2:
            printf("\n\nEnter the id number of the contact to modify it: ");
            scanf("%d", &contactoId);
            contactoId--; // Para hacerlo más amigable con el usuario.

            printf("\nUser %d: \n", contactoId + 1);
            printf("%s\n", contactList[contactoId].nombre);
            printf("%s\n", contactList[contactoId].email);
            printf("%d\n", contactList[contactoId].telefono);

            printf("\n\nInput contact's new name: ");
            fflush(stdin);
            fgets(cntName, sizeof(cntName), stdin);

            printf("Input contact's new email: ");
            fflush(stdin);
            fgets(cntMail, sizeof(cntMail), stdin);

            printf("Input contact's new phone: ");
            scanf("%d", &cntPhone);

            cntName[strcspn(cntName, "\n")] = '\0';
            cntMail[strcspn(cntMail, "\n")] = '\0';

            modifyContact(cntName, cntMail, cntPhone, &contactList[contactoId]);
            printf("\n\n\nContact modified!\n");

            break;
        case 3:
            for (int i = 0; i < contador; i++){
                printf("\nUser %d: \n", i + 1);
                printf("%s\n", contactList[i].nombre);
                printf("%s\n", contactList[i].email);
                printf("%d\n", contactList[i].telefono);
            }
            break;
        case 4:
            // Llamar a la función deleteContact()
            break;
        case 5:
            control = 0;
            break;

        default:
            printf("ERROR!\n");
            printf("%d Is NOT a valid option. You have to choose between the 5 options.", control);
            break;
        }

    } while (control != 0);
    printf("\n\nExit with success!\n");
    printf("\nHave a great day!\n\n");
    
}