#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[50];
    int idno;
    int age;
} stude;

void display(stude s[], int size);
void inputStudent(stude s[], int *size);

int main(int argc, char *argv[]) {
    stude s[3];
    int choice;
    int ctr = 0;

    do {
        printf("1 - Add Student\n");
        printf("2 - Display\n");
        printf("3 - Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputStudent(s, &ctr);
                break;
            case 2:
                display(s, ctr);
                break;
        }
    } while (choice != 3);

    return 0;
}

void display(stude s[], int size) {
    int x;
    for (x = 0; x < size; x++) {
        printf("Name: %s\t", s[x].name);
        printf("Id Number: %d\t", s[x].idno);
        printf("Age: %d\t", s[x].age);
        printf("\n");
    }
}

void inputStudent(stude s[], int *size) {
    if (*size == 3) {
        printf("Array is full.\n");
    } else {
        int id, i;
        char name[50];
        int duplicate = 0;

        printf("Enter ID #: ");
        scanf("%d", &id);

        for (i = 0; i < *size; i++) {
            if (s[i].idno == id) {
                duplicate = 1;
                break;
            }
        }

        if (duplicate) {
            printf("Error: A student with ID number %d already exists.\n", id);
        } else {
            s[*size].idno = id; 
            printf("Enter name: ");
            scanf("%s", name);
            strcpy(s[*size].name, name);

            printf("Enter age: ");
            scanf("%d", &s[*size].age);

            (*size)++;
        }
    }
}
