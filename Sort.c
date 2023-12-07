#include <stdio.h>

#define MAX 999

void radixSort(int[], int);
void bucketSort(int[], int);
void display(int[], int);
void accept(int[], int);

int main()
{
    int num, choice, marks[10];
    printf("Entere number of students: ");
    scanf("%d", &num);
    printf("------\n");
    printf("Enter your choice:\n");
    printf("1. Bucket Sort\n");
    printf("2. Radix Sort\n");
    scanf("%d", &choice);
    printf("------");
    switch (choice)
    {
    case 1:
        accept(marks, num);
        display(marks, num);
        bucketSort(marks, num);
        break;
    case 2:
        accept(marks, num);
        display(marks, num);
        radixSort(marks, num);
        break;
    }
}

void accept(int marks[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("Enter student %d marks: ", i + 1);
        scanf("%d", &marks[i]);
    }
}

void bucketSort(int marks[], int num)
{
    int bucket[MAX];
    for (int i = 0; i < MAX; i++)
    {
        bucket[i] = 0;
    }
    for (int j = 0; j < num; j++)
    {
        ++bucket[marks[j]];
    }
    for (int i = 0, j = 0; i < MAX; i++)
    {
        for (; bucket[i] > 0; --bucket[i])
        {
            marks[j] = i++, j++;
        }
    }
    display(marks, num);
}

void radixSort(int marks[], int n)
{
    int bucket[10][10], bucket_count[10];
    int i, j, k, remainder, NOP = 0, divisor = 1, larger, pass;
    larger = marks[0];
    for (i = 1; i < n; i++)
    {
        if (marks[i] > larger)
            larger = marks[i];
    }
    while (larger > 0)
    {
        NOP++;
        larger /= 10;
    }
    for (pass = 0; pass < NOP; pass++)
    {
        for (i = 0; i < 10; i++)
        {
            bucket_count[i] = 0;
        }
        for (i = 0; i < n; i++)
        {
            remainder = (marks[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = marks[i];
            bucket_count[remainder] += 1;
        }
        i = 0;
        for (k = 0; k < 10; k++)
        {
            for (j = 0; j < bucket_count[k]; j++)
            {
                marks[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;
    }
    display(marks, n);
}

void display(int marks[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", marks[i]);
    }
    printf("\n");
}