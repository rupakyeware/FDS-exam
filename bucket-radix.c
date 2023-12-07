#include <stdio.h>

void display(int[], int);
int getMax(int[], int);
void bucketSort(int[], int);
	
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

	while(1)
	{	
		int choice;	
		printf("\nEnter your choice-\n1. Display\n2. Bucket Sort\n3. Radix Sort\n4. Exit");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			display(arr, n);
			break;

			case 2:
				bucketSort(arr, n);
				break;
			
			case 4:
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

int getMax(int a[], int n)
{  
  int max = a[0];  
  for (int i = 1; i < n; i++)  
    if (a[i] > max)  
      max = a[i];  
  return max;  
}  

void bucketSort(int arr[], int n)
{
	int max = getMax(arr, n);
	int bucket[max];

	for (int i = 0; i <= max; i++)
	{
		bucket[i] = 0;
	}

	for (int i = 0; i < max; i++)
	{
		bucket[arr[i]]++;
	}

	for (int i = 0, j = 0; i <= max; i++)
	{
		while(bucket[i] > 0)
		{
			arr[j++] = i;
			bucket[i]--;
		}
	}
}

void radixSort(int arr[], int n)
{
	int nop, bucket_count[10], bucket[10][10], divisor = 1;
	int greatest = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > greatest)
			greatest = arr[i];
	}

	while(greatest > 0)
	{
		greatest /= 10;
		nop++;
	}	

	for (int pass = 0; pass < nop; pass++)
	{
		for (int i = 0; i < n; i++)
		{
			bucket_count[i] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			int remainder = (arr[i]/divisor) % 10;
			bucket[remainder][bucket_count[remainder]] = arr[i];
			bucket_count[remainder]++; 
		}

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < bucket_count[i]; j++)
			{
				arr[i] = bucket[i][j];
			}
		}
		divisor *= 10;	
	}
}