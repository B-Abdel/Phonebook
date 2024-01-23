#include <stdio.h>
#include <stdlib.h>
#include <phonebook.h>

#define FILE_PATH "/c/Program Files/BTAPPLEX/c_codes/Myprojects/Phonebook"

int number_of_contacts = 0;


void add_contact(contact_t contact) {
    FILE* fp = fopen(FILE_PATH, "a+");
    if(fp != NULL) {
        fprintf(fp, "%s, %s, %d, %d\n", contact.first_name, contact.last_name, contact.number, contact.email);
        fclose(fp);
        number_of_contacts++;
    }
    else {
        printf("Error opening Phonebook!\n");
    }
}

