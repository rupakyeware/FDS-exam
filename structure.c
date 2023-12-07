#include <stdio.h>
#include <string.h>
struct student
{
    char name[20];
    int roll;
    float marks;
};

int menu();
void accept(struct student *s1);
void reset(struct student *s1, int num);
void display(struct student *s1, int n);
void shellSort(struct student *s1, int num);
void bubbleSort(struct student *s1, int num);
void insertionSort(struct student *s1, int num);
void selectionSort(struct student *s1, int num);
void linearSearch(struct student *s1, int num, int roll);
void BinarySearch(struct student *s1, int num, int roll);
void radixsort(struct student *s1, int num);
void bucketSort(struct student *s1, int num);

int main()
{
    int num_of_students;
    struct student stud[100];
    int choice, roll;
    printf("\n");
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            printf("Enter number of students: ");
            scanf("%d", &num_of_students);
            for (int i = 0; i < num_of_students; i++)
            {
                printf("Enter details of student %d\n", i + 1);
                accept(&stud[i]);
            }
            break;
        case 2:
            display(stud, num_of_students);
            break;
        case 3:
            printf("Enter roll to search (Linear): ");
            scanf("%d", &roll);
            linearSearch(stud, num_of_students, roll);
            break;
        case 4:
            printf("Enter roll to search (Binary): ");
            scanf("%d", &roll);
            bubbleSort(stud, num_of_students);
            BinarySearch(stud, num_of_students, roll);
            break;
        case 5:
            bubbleSort(stud, num_of_students);
            printf("Sorted\n");
            break;
        case 6:
            insertionSort(stud, num_of_students);
            break;
        case 7:
            selectionSort(stud, num_of_students);
            break;
        case 8:
            shellSort(stud, num_of_students);
            break;
        case 9:
            reset(stud, num_of_students);
            printf("Reset Succesful!");
            break;
        case 10:
            printf("Exiting...\n");
            return 0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 11);
}

int menu()
{
    int choice;
    printf("1. Accept\n");
    printf("2. Display\n");
    printf("3. Linear Search\n");
    printf("4. Binary Search\n");
    printf("5. Bubble Sort\n");
    printf("6. Insertion Sort\n");
    printf("7. Selection Sort\n");
    printf("8. Shell Sort\n");
    printf("9. Reset Struct\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

void reset(struct student *s1, int num)
{
    for (int i = 0; i < num; i++)
    {
        s1[i].marks = 0;
        s1[i].roll = 0;
        memset(s1[i].name, 0, sizeof(s1[i].name));
    }
}

void accept(struct student *s1)
{
    printf("Enter roll: ");
    scanf("%d", &s1->roll);
    printf("Enter name: ");
    scanf("%s", s1->name);
    printf("Enter marks: ");
    scanf("%f", &s1->marks);
    printf("\n");
}

void display(struct student *s1, int num)
{
    printf("|  Roll  |  Name  |  Marks |\n");
    for (int i = 0; i < num; i++)
    {
        printf("|  %d  |  %s  |  %.2f |\n", s1[i].roll, s1[i].name, s1[i].marks);
    }
}

void linearSearch(struct student *s1, int num, int roll)
{
    for (int i = 0; i < num; i++)
    {
        if (s1[i].roll == roll)
        {
            printf("Student found at position %d\n", i + 1);
            printf("|  Roll  |  Name  |  Marks |\n");
            printf("|  %d  |  %s  |  %.2f |\n", s1[i].roll, s1[i].name, s1[i].marks);
            return;
        }
    }
    printf("Student not found\n");
}

void BinarySearch(struct student *s1, int num, int roll)
{
    int low = 0, high = num - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (s1[mid].roll == roll)
        {
            printf("Student found at position %d\n", mid + 1);
            printf("|  Roll  |  Name  |  Marks |\n");
            printf("|  %d  |  %s  |  %.2f |\n", s1[mid].roll, s1[mid].name, s1[mid].marks);
            return;
        }
        else if (s1[mid].roll < roll)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("Student not found\n");
}

void bubbleSort(struct student *s1, int num)
{
    struct student temp;
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (s1[j].roll > s1[j + 1].roll)
            {
                temp = s1[j];
                s1[j] = s1[j + 1];
                s1[j + 1] = temp;
            }
        }
    }
}

void insertionSort(struct student *s1, int num)
{
    struct student temp;
    int j;
    for (int i = 1; i < num; i++)
    {
        temp = s1[i];
        j = i - 1;
        while (j >= 0 && s1[j].roll > temp.roll)
        {
            s1[j + 1] = s1[j];
            j--;
        }
        s1[j + 1] = temp;
    }
}

void selectionSort(struct student *s1, int num)
{
    struct student temp;
    int min;
    for (int i = 0; i < num - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < num; j++)
        {
            if (s1[j].roll < s1[min].roll)
            {
                min = j;
            }
        }
        temp = s1[i];
        s1[i] = s1[min];
        s1[min] = temp;
    }
};

void shellSort(struct student *s1, int num)
{
    int gap, i, j;
    struct student temp;
    for (gap = num / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < num; i++)
        {
            temp = s1[i];
            j = i;
            while (j >= gap && s1[j - gap].roll > temp.roll)
            {
                s1[j] = s1[j - gap];
                j -= gap;
            }
            s1[j] = temp;
        }
    }
}

void radixsort(struct student *s1, int num)
{
    int highest_num = 0;
    int bucket[9];
    //get the highest number in the struct
    for(int i=1;i<num;i++){
        if(s1[i].roll > highest_num){
            highest_num = s1[i].roll;
        }
    }

}

void bucketSort(struct student *s1, int num)
{
    int highest_num = 0, sorted[num];
    for (int i = 1; i < num; i++){
        if (s1[i].roll > highest_num){
            highest_num = s1[i].roll;
        }
    }
    int bucket[highest_num];
    for(int i=0;i<num;i++){
        if (bucket[s1[i].roll] == 0){
            bucket[s1[i].roll] = 1;
        }else
        {
            bucket[s1[i].roll]++;
        }
    }
}