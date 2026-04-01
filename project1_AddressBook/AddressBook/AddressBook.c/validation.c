#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"contact.h"
#include"validation.h"
// Function to validate name
int validate_name(char *name)
{
    int i = 0;//Initialize variable
    if (name[0] == ' ')//Check if first character is space
    {
        printf("Name cannot start with a space\n");
        return 0;//Invalid name
    }
    while (name[i] != '\0')//Loop for checking each character
    {
        //Check if character is not letter or space
        if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == ' ')))
        {
            printf("Name must contain only letters and spaces\n");
            return 0; // Invalid name
        }
        i++;//increment to next character
    }
    return 1;//valid name
}
// Function to validate phone
int validate_phone(char *phone, AddressBook *addressBook)
{
    int i = 0;//initailise variable
    int count = 0;//initailise count variable
    int currentIndex;
    // Count characters
    while (phone[i] != '\0')//Count digits
    {
        count++;//Increment count value
        i++;//Move to next index
    }
    if (count != 10)//Check if count is not 10
    {
        printf("Phone number must be exactly 10 digits\n");
        return 0;//Invalid phone
    }
    // Check all digits
    i = 0;//Reset index
    //Loop for checking digits
    while (phone[i] != '\0')
    {
        if (!(phone[i] >= '0' && phone[i] <= '9'))//Check if it is not a digit
        {
            printf("Phone number must contain digits only\n");
            return 0;//Invalid
        }
        i++;//Increment to next character
    }
    //Duplicate phone check
    //Loop for checking duplicate phone
    for(int i = 0; i < addressBook->contactCount; i++) 
    {
        if (i != currentIndex && strcmp(addressBook->contacts[i].phone, phone) == 0)//if phone matches any other contacts
        {
            printf("Error: Phone number already exists\n");
            return 0;//validation failure
        }
    }
    return 1;//Phone is valid
}

// Function to validate email
int validate_mail(char *mail, AddressBook *addressBook)
{
    int len = strlen(mail);//Get mail length
    int index_at = -1;//Store @ position
    int at_count = 0;//initialise count @
    int i = 0;//initialise Loop variable
    //Loop for checking mail
    while (i < len)
    {
        if (mail[i] == ' ')//Check space
        {
            printf("Email cannot contain spaces\n");
            return 0; //Invalid
        }
        if (mail[i] >= 'A' && mail[i] <= 'Z')//Check uppercase
        {
            printf("Email cannot contain capital letters\n");
            return 0;//Invalid
        }
        if (mail[i] == '@')//Check @ 
        {
            at_count++;//Count @
            index_at = i;//Save @ position
        }
        i++;//Increment to next char
    }
    if (at_count != 1)//Check exactly one @
    {
        printf("Email must contain '@'\n");
        return 0;//Invalid
    }
    if (index_at == 0 || index_at == len - 1)//Check @ position
    {
        printf("'@' cannot be the first or last character\n");
        return 0;//Invalid
    }
    // Check before '@'
    i = 0;//Reset variable position
    while (i < index_at)// Loop for checking before @
    {
        if (mail[i] == '.')//Check dot before @
        {
            printf("'.' is not allowed before '@'\n");
            return 0;//Invalid
        }
        i++;//Move to next 
    }
    // Domain check:must end with gmail.com
    char domain[] = "gmail.com";//check for required domain
    int domain_len = strlen(domain);//check domain length
    if (len - (index_at + 1) != domain_len)//Check domain length matches required domain
    {
        printf("Email must end with 'gmail.com'\n");
        return 0;//Invalid
    }
    i = 0;//Reset index
    while (i < domain_len)//Compare domain
    {
        if (mail[index_at + 1 + i] != domain[i])//Compare domain characters
        {
            printf("Email must end with 'gmail.com'\n");
            return 0;//Invalid
        }
        i++;//Move to next
    }
    //Duplicate mail check
    //Loop for checking duplicate mail
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcmp(addressBook->contacts[i].email, mail) == 0)//if mail matches any other contacts
        {
            printf("Error: Email already exists\n");
            return 0;//validation failure
        }
    }
    return 1;//Email is valid
}
