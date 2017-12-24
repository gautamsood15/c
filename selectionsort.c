#include<stdio.h>

int main()
{
int arr[]= {9,3,5,1,0,4,2,8,6,7};

int min, i, j, tmp;
int minIndex;

for( i = 0 ; i < 10; i++)
{
	min = arr[i];
	for(j = i + 1; j < 10; j++)
	{
		if( arr[j] < min ) 
		{
			min = arr[j];		
			minIndex = j;
		}
	}
	tmp = arr[i];
	arr[i] = min;
	arr[minIndex] = tmp;	
}

for( i = 0 ; i < 10 ; i++)
	printf(" \n %d", arr[i]);
}
