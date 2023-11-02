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
    int control = 1, contactNum, cntPhone;

    printf("Identify yourself! Input your name: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    printf("\nCreating contact list ... ");

    printf("\nEnter the maximum number of contacts your list will have: ");
    scanf("%d", &contactNum);
    //struct Contacto[contactNum]; // Create ContactList
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
            // Llamar a la función createContact()
            printf("\n\nInput contact's name: ");
            getchar();
            fgets(cntName, sizeof(cntName), stdin);

            printf("Input contact's email: ");
            getchar();
            fgets(cntMail, sizeof(cntMail), stdin);

            printf("Input contact's phone: ");
            scanf("%d", cntPhone);

            cntName[strcspn(cntName, "\n")] = '\0';
            cntMail[strcspn(cntMail, "\n")] = '\0';

            createContact(cntName, cntPhone, cntMail);
            printf("\n\nContact created!\n");
            break;
        case 2:
            // Llamar a la función modifyContact()
            break;
        case 3:
            // Llamar a la función listContacts()
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