#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>

#define MAX_CONTACTS 100

typedef struct Contact{
    char name[50];
    char phone[20];
    char email[50];
} Contact; // this is a structure decleration or proto type;
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook; // this is a structure decleration or proto type;

// • Create a new contact and add it to the address book
void createContact(AddressBook *addressBook);

// • Search for a contact by name, phone, or email
void searchContact(AddressBook *addressBook);

// • Edit the details of an existing contact
void editContact(AddressBook *addressBook);

// • Delete a contact from the address book
void deleteContact(AddressBook *addressBook);

// • List all contacts in the address book
void listContacts(AddressBook *addressBook);

// • Initialize the address book (set contact count to zero)
void initialize(AddressBook *addressBook);

// • Save all contacts to a file for persistence
void saveContactsToFile(AddressBook *AddressBook);


#endif

