#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100
//Define a structure for contact
typedef struct {
    //store contact name,phone and mail
    char name[50];
    char phone[20];
    char email[50];
} Contact;
//Define a structure for the address book
typedef struct {
    Contact contacts[100];//Declare Array to store up to 100 contacts
    int contactCount;//Declare variable to store number of contacts
} AddressBook;
//Create functions to create,search,edit,delete,list,save and exit
void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContacts(AddressBook *addressBook);
void exitProgram(AddressBook *addressBook);


#endif
