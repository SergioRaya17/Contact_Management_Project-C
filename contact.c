#include <stdio.h>
#include <string.h>
#include "contact.h"

void createContact(char nombre[], int telefono, char email[], Contact *contactList) {
    strncpy(contactList->email, email, sizeof(contactList->email));
    strncpy(contactList->nombre, nombre, sizeof(contactList->nombre));
    contactList->telefono = telefono;
} 

void modifyContact(char nombre[], char email[], int telefono, Contact *contactMod) {
    strncpy(contactMod->email, email, sizeof(contactMod->email));
    strncpy(contactMod->nombre, nombre, sizeof(contactMod->nombre));
    contactMod->telefono = telefono;
}

void deleteContact(Contact *contactDel, int idContact, int arraySize) {
    
    for (int i = idContact; i < arraySize - 1; i++) {
        strcpy(contactDel[i].email, contactDel[i + 1].email);
        strcpy(contactDel[i].nombre, contactDel[i + 1].nombre);
        contactDel[i].telefono = contactDel[i + 1].telefono;

        if (contactDel[i + 1].nombre == NULL) {
            strcpy(contactDel[i].email, "");
            strcpy(contactDel[i].nombre, "");
            contactDel[i].telefono = 0;
        }
    }
}


