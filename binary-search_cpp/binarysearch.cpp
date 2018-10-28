//Binary Search

#include<iostream>
using namespace std;

class Array
{
	int arr[20];
	int n;

public:
	void setArray();
	void getArray();
	void sortArray();
	void BinaryRec();
	int BinarySearch(int,int,int);
	void BinaryNonRec();
};
void Array::setArray()
{
	cout<<"\nEnter number of elements in array(max 20) : ";
	cin>>n;
	cout<<"\nEnter the elements of array :";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		
	}
}
	
void Array::getArray()
{
	cout<<"\nArray : ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

void Array::sortArray()
{	
	int j;
	for(int i=1;i<n;i++)
	{
		j=i;
		while((j>0) && (arr[j-1]>arr[j]))
		{
			int temp;
			temp=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=temp;
			j=j-1;
		}
	}
	cout<<"\nSorted Array : ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

void Array::BinaryRec()
{
	int elem,pos;
	cout<<"\nEnter element to be searched : ";
	cin>>elem;
	pos = BinarySearch(elem,0,n-1);
	if(pos==-1)
	{
		cout<<"\nElement Not Found!";
	}
	else
	{
		cout<<"\nElement Found!";
		cout<<"\nPosition : "<<pos;
	}
	
}

int Array::BinarySearch(int elem,int low,int high)
{
	int mid;
	if(low<=high)
	{
		mid=(low+high)/2;
		if(elem==arr[mid])
		{
	
			return mid;
		}	
		else if(elem < arr[mid])
		{
			BinarySearch(elem,low,mid-1);
		}
		else if(elem > arr[mid])
		{
			BinarySearch(elem,mid+1,high);
		}
	}
	else
		return -1;
}

void Array::BinaryNonRec()
{
	int low=0;
	int high=n-1;
	int elem,pos,f=0,mid;
	cout<<"\nEnter element to be searched : ";
	cin>>elem;
	while(low<=high)	
	{
		mid=(low+high)/2;
		if(elem == arr[mid])
		{
			f=1;
			cout<<"\nElement Found!";
			cout<<"\nPosition : "<<mid;
			break;
		}
		else if(elem < arr[mid])
		{
			high=mid-1;
		}
		else if(elem > arr[mid])
		{
			low=mid+1;
		}
	}
	
	if(f==0)
	{
		cout<<"Element Not Found!";
	}
}



int main()
{

	Array A;
	char ch;
	do
	{
		int n;
		cout<<"\nMENU";
		cout<<"\n1.Enter Array\n2.Display Array\n3.Sort Array\n4.Recursive Binary Search\n5.Non-Recursive Binary Search";
		cout<<"\nEnter Choice : ";		
		cin>>n;
		switch(n)
		{
			case 1:
			A.setArray();
			break;
			
			case 2:
			A.getArray();
			break;

			case 3:
			A.sortArray();
			break;

			case 4:
			A.BinaryRec();
			break;
		
			case 5:
			A.BinaryNonRec();
			break;

			default:
			cout<<"\nInvalid Choice!";
			break;
		}

		cout<<"\nDo you want to continue ?(y/n) : ";
		cin>>ch;
			
	}while(ch=='y' || ch=='Y');
	
	return 0;
}
