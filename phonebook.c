#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char first_name[20];
    char last_name[20];
    long int number;
    char email[50];
} contact_t;

void menu();
void add_contact();
void list_contacts();
void search_contact();
void edit_contact();

#define FILE_PATH "C:/Program Files/BTAPPLEX/c_codes/Myprojects/Phonebook/contacts.csv"

int number_of_contacts = 0;

// main function
int main() {
    int op = 0;
    do {
        menu();
        scanf("%d", &op);
        switch(op) {
            case 1 :
                printf("1 saved\n");
                add_contact();
                break;
            case 2 : 
                search_contact();
                break;
            case 3 : 
                //edit_contact();
                //break;
            case 4 : 
                list_contacts();
                break;
            case 5 : 
                //delete_contact();
                //break;
            case 6 : 
                break;
            default : 
                printf("Command unknown!\n");
                getchar();
                getchar();
                break;
        }
    } while (op != 6);
    
}

// Display main menu
void menu() {
    system("cls");
    printf("/************ Phonebook ************/\n\n");
    printf("1- Add contact \t\t 4- List contacts \n");
    printf("2- Search \t\t 5- Delete contact \n");
    printf("3- Edit contact \t 6- Exit App \n\n");
    printf("Enter an operation : ");
}

// Create a new contact
void add_contact() {
    contact_t contact;

    system("cls");
    printf("/************ Phonebook ************/\n\n");
    printf("ADD CONTACT\n\n");

    FILE* fp = fopen(FILE_PATH, "a");
    if(fp == NULL) {
        printf("Can't find contacts file!\n");
        getchar();
        menu();
    }
    printf("Enter the first name : ");
    scanf("%s", contact.first_name);
    printf("Enter the last name : ");
    scanf("%s", contact.last_name);
    printf("Enter mobile nummber : ");
    scanf("%ld", &contact.number);
    printf("Enter Email address : ");
    scanf("%s", contact.email);

    fprintf(fp, "%s,%s,%ld,%s\n", contact.first_name, contact.last_name, contact.number, contact.email);
    fclose(fp);
    number_of_contacts++;
    printf("New contact successfully created\n");
    getchar();
    getchar();
}

void list_contacts() {
    contact_t contact;

    system("cls");
    printf("/************ Phonebook ************/\n\n");
    printf("CONTACTS LIST\n\n");
    FILE* fp = fopen(FILE_PATH, "r");
    if(fp == NULL) {
        printf("Can't find contacts file!\n");
        getchar();
        menu();
    }
    while(fscanf(fp, "%[^,],%[^,],%ld,%[^,\n]", contact.first_name, contact.last_name, &contact.number, contact.email) == 4) {
        printf("%s \t %s \n %ld \t %s \n", contact.first_name, contact.last_name, contact.number, contact.email);
        printf("*****************************\n");
    }
    fclose(fp);
    getchar();
    getchar();
}

void search_contact() {
    contact_t contact;
    char target[20];
    int match = 0;

    system("cls");
    printf("/************ Phonebook ************/\n\n");
    printf("SEARCH\n\n");
    
    printf("Enter the name you are looking for : ");
    scanf("%s", target);

    FILE* fp = fopen(FILE_PATH, "r");
    if(fp == NULL) {
        printf("Can't find contacts file!\n");
        getchar();
        menu();
    }
    char line[200];
    while(fgets(line, sizeof(line), fp) != NULL){
        sscanf(line, "%[^,],%[^,],%ld,%[^\n]", contact.first_name, contact.last_name, &contact.number, contact.email);
        if(!strcmp(contact.first_name, target)) {
            match = 1;
            printf("info for %s are : \n", target);
            printf("Name : %s %s\n", contact.first_name, contact.last_name);
            printf("number : %ld\n", contact.number);
            printf("email : %s", contact.email);
            printf("\n*********\n");
        }
    }
    if(match == 0) printf("%s not found in contacts!\n", target);
    fclose(fp);
    getchar();
    getchar();
}

void edit_contact() {
    contact_t contact;
    char target[20];

    system("cls");
    printf("/************ Phonebook ************/\n\n");
    printf("EDIT CONTACT\n\n");

    printf("Enter the contact you want to edit : ");
    scanf("%s", target);

    FILE* fp = fopen(FILE_PATH, "r");
}
