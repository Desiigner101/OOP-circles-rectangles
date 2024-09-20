#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct student{
	char name[50];
	int idno;
	int age;
}stude;

void display(stude s[], int size);
void inputStudent(stude s[], int *size) ;

int main(int argc, char *argv[]) {
	stude s[3];
	int choice;
	int ctr=0;
	//printf("%s",s[1].name);
	do{
		printf("1 - Add Student\n");
		printf("2 - Display\n");
		printf("3 - Exit\n");
		printf("Enter choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
					inputStudent(s,&ctr);
					break;
			case 2:
					display(s,ctr);
					break;
		}
	}while(choice !=3);
	
	return 0;
}

void display(stude s[], int size) {
    int i, j;
    int alreadyDisplayed[size]; // Array to keep track of already displayed IDs
    int count = 0; // Number of unique IDs encountered

    for (i = 0; i < size; i++) {
        // Check if the ID number has already been displayed
        int duplicate = 0;
        for (j = 0; j < count; j++) {
            if (s[i].idno == alreadyDisplayed[j]) {
                duplicate = 1;
                break;
            }
        }

        // If it's not a duplicate, display it and add the ID to the list
        if (!duplicate) {
            printf("Name: %s\t", s[i].name);
            printf("Id Number: %d\t", s[i].idno);
            printf("Age: %d\t", s[i].age);
            printf("\n");

            // Add the current ID to the already displayed list
            alreadyDisplayed[count] = s[i].idno;
            count++;
        }
    }
}



void inputStudent(stude s[], int *size){
	char name[50];
	if(*size == 3)
		printf("Array is full.\n");
	else{
		printf("Enter name: ");
		scanf("%s",name);
		strcpy(s[*size].name,name);

		printf("Enter ID #: ");
		scanf("%d",&s[*size].idno);

		printf("Enter age: ");
		scanf("%d",&s[*size].age);
		(*size)++;
	}
	
}