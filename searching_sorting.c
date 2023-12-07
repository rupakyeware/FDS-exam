#include <stdio.h>

void display(int[], int);
void linearSearch(int, int, int[]);
void binarySearch(int, int, int[]);
void bubbleSort(int[], int);
void insertionSort(int[], int);
void selectionSort(int[], int);
void shellSort(int [], int);

int main()
{
	int n;
	printf("\nEnter the size of array: ");
	scanf("%d", &n);

	int arr[n];
	printf("\nEnter %d numbers-\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	while (1)
	{
		printf("\n0. Display\n");
		printf("1. Linear Search\n");
    		printf("2. Binary Search\n");
    		printf("3. Bubble Sort\n");
    		printf("4. Insertion Sort\n");
    		printf("5. Selection Sort\n");
    		printf("6. Shell Sort\n");
    		printf("8. Exit\n");
    		printf("\nEnter your choice: ");
		int choice;
		scanf("%d", &choice);

		switch(choice)
		{

			case 0:
				display(arr, n);		
				break;
			
			case 1:	
				printf("\nEnter number to search: "); 
				int num;
				scanf("%d", &num);
				linearSearch(num, n, arr);
				break;

			case 2: 
				printf("\nEnter number to search: "); 
				scanf("%d", &num);
				binarySearch(num, n, arr);
				break;

			case 3:
				bubbleSort(arr, n);
				break;

			case 4:
				insertionSort(arr, n);
				break;

			case 5:
				selectionSort(arr, n);
				break;

			case 6:
				shellSort(arr, n);
				break;

			case 8:
				return 0;
		}
	}	
}

void display(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n%d", arr[i]);
	}
}

void linearSearch(int n, int total, int arr[])
{
	for (int i = 0; i < total; i++)
	{
		if (arr[i] == n)
		{
			printf("\nElement found at index %d!", i);
			return;
		}
	}
	printf("\nElement does not exist in array!");
}

void binarySearch(int n, int total, int arr[])
{	
	int low = 0, high = n-1, mid = (low + high) / 2;
	while (low <= high)
	{
		if (arr[mid] == n)
		{
			printf("\nElement found at %d!", mid);
			return;
		}
		else if(arr[mid] > n)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
		mid = (low + high )/ 2;
	}
	printf("\nElement not found in array!\n");
}

void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void insertionSort(int arr[], int n)
{
	int j, key;
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void selectionSort(int arr[], int n)
{	
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for(int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = arr[j];
			}
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}
