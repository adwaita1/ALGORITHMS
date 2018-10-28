//quicksort


#include <iostream>
#include <stdio.h>
#include <omp.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
    for (int j=l; j <= h-1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
		
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}


void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
		int p = partition(arr, l, h);
		#pragma omp parallel sections
		{
			#pragma omp section
				{int i=omp_get_thread_num();
				cout<<"\nThread executing :: "<<i;
				quickSort(arr, l, p - 1);}
			#pragma omp section	
			{int j=omp_get_thread_num();
				cout<<"\nThread executing :: "<<j;
				quickSort(arr, p + 1, h);}
		}
    }
}

void displayArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
}


int main()
{
    omp_set_nested(1);
    omp_set_num_threads(4);
    int size;
    cout << "Enter the number of elements to be sorted :: ";
    cin	>> size;
    int arr[size];
    cout << "\nEnter elements to be sorted :: \n";
    for(int i=0;i<size;i++)
    {
    	cin >> arr[i];
    }
    double start = omp_get_wtime(); 
    quickSort(arr, 0, size-1);
    cout << "\nElements after Quick Sort :: ";
    displayArray(arr, size);
    double end = omp_get_wtime();
    cout<<"\nThe total Excecution time for performing the quick sort :: "<<end - start<<" seconds "; 
    cout<<"\n";
    return 0;
}


