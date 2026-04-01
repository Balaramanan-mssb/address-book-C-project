#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "validation.h"
void listContacts(AddressBook *addressBook) 
{
    //Function to display all contacts
    // Sort contacts based on the chosen criteria
     if (addressBook->contactCount == 0)// check if address book is empty
     {
         printf("No contacts to display\n");//print when no contact exist
         return;// Exit the function
     }
    for(int i=0;i<addressBook->contactCount;i++)// Loop for all contacts to display
    {
        printf("Name of the contact:%s\n",addressBook->contacts[i].name);// print name
        printf("Phone number:%s\n",addressBook->contacts[i].phone);// print phone
        printf("Email id:%s\n",addressBook->contacts[i].email);// print mail
        printf("\n");
    } 
}
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveContacts(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
}

void exitProgram(AddressBook *addressBook){
exit(EXIT_SUCCESS); // Exit the program
}

//Function to create contact
void createContact(AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */
    if (addressBook->contactCount >= 100)//check whether the address book already has the maximum
    {
        printf("Address book is full\n");
        return;//exit function
    }
    //declare buffer for contact name,phone and mail
    char name[50];
    char phone[20];
    char mail[50];
    // Input Name
    do {
        printf("Enter the name of the new contact: ");
        scanf(" %[^\n]", name);//Read input name
    }while (!validate_name(name));//check for validation
    // Input Phone with duplicate check
    do {
        printf("Enter the Phone number: ");
        scanf("%s", phone);//Read phone
    }while (!validate_phone(phone, addressBook));//end infinite loop for phone input
    // Input Email with duplicate check
    do {
        printf("Enter mail id: ");
        scanf("%s", mail);//read mail
    }while (!validate_mail(mail, addressBook));//end infinite loop for mail input
    // Save Contact
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);//copy validated name into the new contact
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);//copy phone into the new contact
    strcpy(addressBook->contacts[addressBook->contactCount].email, mail);//copy mail into the new contact 
    addressBook->contactCount++;//increment contact count
    printf("Contact created successfully\n");
}

//Function to search contact
void searchContact(AddressBook *addressBook) 
{
    /* Define the logic to create a Contacts */
    if (addressBook->contactCount == 0)//check for no contacts
    {
        printf("\nNo contacts available to search\n");
        return;
    }
    int choice;//declare variable to search
    char search[50];//store buffer for search input
    //show search menu 
    printf("Search by:\n");
    printf("1. Name of the contact\n");
    printf("2. Phone number\n");
    printf("3. Email id\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);//read user choice
    switch (choice)
    {
        case 1: // Search by name
        {
            //loop for name search
            do {
                printf("Enter name to search: ");
                scanf(" %[^\n]", search);//read name
            } while (!validate_name(search));//validate name
            //loop for check name matches
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].name, search) == 0)//if it is matches
                {
                    //print matched contact details
                    printf("\nContact Found:\n");
                    printf("Name of the contact: %s\n", addressBook->contacts[i].name);
                    printf("Phone number: %s\n", addressBook->contacts[i].phone);
                    printf("Email id: %s\n", addressBook->contacts[i].email);
                    return;
                }
            }
            //if it is not matches
            printf("No contact found with that name\n");
            break;
        }
        case 2: // Search by phone
        {
            //loop for phone search
            do {
                printf("Enter phone to search: ");
                scanf("%s", search);//read phone
            }while(validate_phone(search, addressBook));//validate phone
            //loop for check phone matches
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].phone, search) == 0)//if it is matches
                {
                    //print matched contact details
                    printf("\nContact Found:\n");
                    printf("Name of the contact: %s\n", addressBook->contacts[i].name);
                    printf("Phone number: %s\n", addressBook->contacts[i].phone);
                    printf("Email id: %s\n", addressBook->contacts[i].email);
                    return;
                }
            }
            //if it is not matches
            printf("No contact found with that phone number\n");
            break;
        }
        case 3: // Search by email
        {
            //loop for mail search
            do{
                printf("Enter email to search: ");
                scanf("%s", search);//read mail
            }while(validate_mail(search, addressBook));//validate mail
            //loop for check mail matches
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].email, search) == 0)//if it is matches
                {
                    //print matched contact details
                    printf("\nContact Found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Phone: %s\n", addressBook->contacts[i].phone);
                    printf("Email: %s\n", addressBook->contacts[i].email);
                    return;
                }
            }
            //if it is not matches
            printf("No contact found with that email\n");
            break;
        }
        //check for imnvalid choice
        default:
            printf("Invalid choice\n");
    }
}

//Function to edit contact
void editContact(AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */
    //check for no contact exist
    if (addressBook->contactCount == 0)
    {
        printf("No contacts available to edit\n");
        return;
    }
    char search[50];//store buffer for search input
    printf("Enter phone number of the contact you want to edit: ");
    scanf("%s", search);//read phone to edit
    //loop to find contact whose phone matches
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, search) == 0)//if it is matches
        {
            int choice;//declare variable to search
            //print matched contact details
            printf("\nContact Found:\n");
            printf("Name: %s\nPhone: %s\nEmail: %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            //show edit menu to choice
            printf("\nWhat do you want to edit?\n");
            printf("1. Name\n2. Phone\n3. Email\nEnter your choice: ");
            scanf("%d", &choice);//read choice
            getchar();//consume leftover newline
            switch (choice)//select choice to edit
            {
                case 1: // Edit name
                {
                    char newName[50];//store buffer for newName
                    int valid;//declare variable to check valid name
                    do
                    {
                        printf("Enter new name: ");
                        scanf(" %[^\n]",newName);//read newName
                        valid = validate_name(newName);//validate newName
                    } while (!valid);
                    strcpy(addressBook->contacts[i].name, newName);//copy to addressBook
                    break;
                }
                case 2: // Edit phone
                {
                    char newPhone[20];//store buffer for newPhone
                    int valid;//declare variable to check valid phone
                    do
                    {
                        printf("Enter new phone number: ");
                        scanf("%s", newPhone);//read newPhone
                        valid = validate_phone(newPhone, addressBook);//validate newPhone
                    } while (!valid);
                    strcpy(addressBook->contacts[i].phone, newPhone);//copy to addressBook
                    break;
                }
                case 3: // Edit email
                {
                    char newMail[50];//store buffer for newMail
                    int valid;//declare variable to check valid mail
                    do
                    {
                        printf("Enter new email: ");
                        scanf("%s", newMail);//read new mail
                        valid = validate_mail(newMail, addressBook);//validate newMail
                    } while (!valid);
                    strcpy(addressBook->contacts[i].email, newMail);//copy to addressBook
                    break;
                }
                //handles invalid choice
                default:
                    printf("Invalid choice.\n");
                    return;
            }
            printf("Contact updated successfully!\n");
            return;//return success
        }
    }
    //loop finishes without finding contact
    printf("No contact found with that phone number.\n");
}

//Function to delete contact
void deleteContact(AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */
    //check for empty addressBook
    if (addressBook->contactCount == 0)
    {
        printf("No contacts available to delete.\n");
        return;
    }
    char phone[20];//buffer to store phone
    printf("Enter phone number of the contact to delete: ");
    scanf("%s", phone);//read phone to locate contact to delete
    int found = 0;//initialise found flag
    //condition to search for matching phone
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, phone) == 0)//if it is matches
        {
            //print contact details
            printf("\nContact Found:\n");
            printf("Name : %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);
            char confirm;//declare confirm buffer
            printf("\nAre you sure you want to delete this contact? (y/n): ");
            scanf(" %c", &confirm);//read choice for confirmation
            if (confirm == 'y' || confirm == 'Y')//if user confirms deletion
            {
                // Shift contacts left
                for (int j = i; j < addressBook->contactCount - 1; j++)
                {
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                }
                addressBook->contactCount--;//decrement contact count
                found = 1;//set found flag
                printf("Contact deleted successfully!\n");
                // Save updated contacts to file
                saveContactsToFile(addressBook);
            }
            else//if user cancels deletion
            {
                printf("Deletion cancelled.\n");
            }
            break;//break out of loop
        }
    }
    if(!found)//if not found
    {
        printf("No contact found with that phone number.\n");
    }
}
