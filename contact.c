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


