#include <stdio.h>
#include "contact.h"
int main() {
    int choice;// Variable to store user’s selection
    AddressBook addressBook;//create variable to store contacts
    addressBook.contactCount=0;//Initialize contact count to zero
    initialize(&addressBook); // Initialize the address book
    int sortChoice=0;//declare variable for sorting
    //loop for selecting user's option
    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);// Read user’s selection
        //Open switch to select user's choice
        switch (choice) {
            //Call function to create,search,edit,delete,list,save and exit
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook);
                break;
            case 6:
                saveContacts(&addressBook);
                //saveContactsToFile(&addressBook);
                break;
            case 7:
                exitProgram(&addressBook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        //Run loop until user choose option 8
    } while (choice != 8);
    
       return 0;
}
