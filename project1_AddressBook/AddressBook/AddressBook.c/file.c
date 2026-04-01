#include <stdio.h>
#include "file.h"
//Function to save contacts to file
void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fp = fopen("contacts.csv", "w");//Open file in write mode  
    if (fp == NULL)//Check if file is failed to open
    {
        addressBook->contactCount = 0;//Set contact count to 0 if no file
        return;//Exit function
    }
    //Write the contact count
    fprintf(fp,"#%d\n", addressBook->contactCount);//Write contact count in first line
    //Write each contact line
    //Loop for checking each contact
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        //Write name, phone, mail
        fprintf(fp, "%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fp);//Close the file
}
//Function to load contacts from file.
void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fp = fopen("contacts.csv", "r");//Open file in read mode
    if (fp == NULL)//Check if file is not found
    {
        addressBook->contactCount = 0;//Set contact count to 0 if no file
        return;//Exit function
    }
    fscanf(fp,"#%d\n", &addressBook->contactCount);//Read contact count from first line
    //Loop to read each contact
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        //Read name, phone, email separated by commas(,)
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fp);//Close the file
}
