#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 50

void fPrint(char message[15])
{
    printf("=========================================================================================\n");
    printf("\t  %s\n", message);
    printf("=========================================================================================\n");
}

// a function for adding new students record
void addNewRecord()
{
    // declare variables
    char fname[20];
    char lname[20];
    char rollno[10];
    char dob[12];
    int marks[5];
    int total;
    float percentage;
    // input
    printf("Enter first name: ");
    scanf("%s", fname);
    printf("Enter last name: ");
    scanf("%s", lname);
    printf("Enter roll no.: ");
    scanf("%s", rollno);
    printf("Enter dob: ");
    scanf("%s", &dob);
    printf("Enter marks in physics: ");
    scanf("%d", &marks[0]);
    printf("Enter marks in chemistry: ");
    scanf("%d", &marks[1]);
    printf("Enter marks in maths: ");
    scanf("%d", &marks[2]);
    printf("Enter marks in computer: ");
    scanf("%d", &marks[3]);
    printf("Enter marks in english: ");
    scanf("%d", &marks[4]);

    // process
    total = marks[0] + marks[1] + marks[2] + marks[3] + marks[4];
    percentage = ((float)total / 500) * 100;

    // output
    printf("First name: %s\n", fname);
    printf("Last name: %s\n", lname);
    printf("Roll No.: %s\n", rollno);
    printf("DOB [YYYY/MM/DD]: %s\n", dob);
    printf("Marks in physics: %d\n", marks[0]);
    printf("Marks in chemistry: %d\n", marks[1]);
    printf("Marks in maths: %d\n", marks[2]);
    printf("Marks in computer: %d\n", marks[3]);
    printf("Marks in english: %d\n", marks[4]);
    printf("Total marks: %d\n", total);
    printf("Percentage: %.2f\n", percentage);

    // store the marks for each students in separate files named as rollno.txt
    FILE *fp;
    fp = fopen(strcat(rollno, ".txt"), "w");
    fprintf(fp, "First name: %s\n", fname);
    fprintf(fp, "Last name: %s\n", lname);
    fprintf(fp, "Roll No.: %s\n", rollno);
    fprintf(fp, "DOB: %s\n", dob);
    fprintf(fp, "Marks in physics: %d\n", marks[0]);
    fprintf(fp, "Marks in chemistry: %d\n", marks[1]);
    fprintf(fp, "Marks in maths: %d\n", marks[2]);
    fprintf(fp, "Marks in computer: %d\n", marks[3]);
    fprintf(fp, "Marks in english: %d\n", marks[4]);
    fprintf(fp, "Total marks: %d\n", total);
    fprintf(fp, "Percentage: %.2f\n", percentage);
    fclose(fp);
}

// a function to delete student record
void deleteRecord(char rollNo[10])
{
    if (remove(strcat(rollNo, ".txt")) == 0)
    {
        fPrint("Student record has been deleted successfully\n");
    }
    else
    {
        fPrint("Unable to delete the student record\n");
    }
}

void showChoices()
{
    int choice;

    printf("What would you like to do? \n");
    printf("[1] Add a new student\n[2] Search student result\n[3] Delete student record\n");

    scanf("%d", &choice);

    if (choice == 1)
    {
        addNewRecord();
    }
    else if (choice == 2)
    {
        printf("Enter roll number of the student that you want to look for: ");
        char searchRollNo[10];
        scanf("%s", searchRollNo);
        FILE *fp;
        fp = fopen(strcat(searchRollNo, ".txt"), "r");
        char line[100];
        while (fgets(line, 100, fp))
        {
            printf("%s", line);
        }
        fclose(fp);
    }
    else if (choice == 3)
    {
        printf("Enter roll number of the student that you want to delete: ");
        char searchRollNo[10];
        scanf("%s", searchRollNo);
        deleteRecord(searchRollNo);
    }
    else
    {
        fPrint("Invalid choice");
        showChoices();
    }
}
// a program to take input of students name, roll no, dob, and marks in different subjects and calculate total marks and percentage and save the result in a file
void main()
{
    showChoices();
}
