# address-book-C-project
C-based address book system implementing file handling concepts to create, search, edit, delete, list contacts with phone number and email, manage contact information efficiently.

Address Book in C:

Description:
          
This project is a command-line based Address Book application project developed by using C programming. It uses file handling concepts to store, retrieve, and manage contact information efficiently.

Operations:

-> Create new contacts

-> Search for contacts

-> Edit existing contacts

-> Delete contacts

-> Display all contacts

-> Save contacts and Exit


Concepts used:

- C Programming Fundamentals
- File Handling (fopen, fread, fwrite, fclose)
- Structures for storing contact details
- Pointers for memory access and data manipulation
- Functions for modular programming
- String concepts used (strcmp, strcpy, strlen)
- Command-line interface (CLI) based interaction
- Basic data management system design

Project File Structure:

address-book-c/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── populate.c
├── populate.h
├── validation.c
├── validation.h
├── contacts.csv
├── documentation.txt


How to Run:
1. Compile the program:
   gcc *.c

2. Run the program:
   ./a.out

Sample input: 

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save contacts
7. Exit

Enter your choice: 1

Enter the name of the new contact:abc

Enter the Phone number: 1234567890

Enter mail id:abc@gmail.com

Enter your choice: 2

Search by:

1. Name of the contact
2. Phone number
3. Email id
4. 
Enter your choice:1

Enter name to search: abc

Enter your choice: 3

Enter phone number of the contact you want to edit:1234567890 

Contact Found:

Name of the contact: abc
Phone number: 1234567890
Email id: abc@gmail.com

What do you want to edit?

1. Name
2. Phone
3. Email

Enter your choice:1
Enter new name: abcd

Enter your choice: 4
Enter phone number of the contact to delete: 1234567890

Contact Found:
Name : abcd
Phone: 1234567890
Email: abc@gmail.com

Are you sure you want to delete this contact? (y/n): y

Enter your choice: 5

Sample output:

Contact created successfully!

Contact Found:

Name of the contact: abc
Phone number: 1234567890
Email id: abc@gmail.com

Contact updated successfully!

Contact deleted successfully!

Name of the contact:abcd
Phone number:1234567890
Email id:abc@gmail.com

Concepts Learned:
- Improved understanding of file handling in C
- Strengthened problem-solving skills
- Hands-on experience with real-time data management

Author:
Balaramanan M
