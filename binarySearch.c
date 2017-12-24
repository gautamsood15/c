#include<stdio.h>

int main()
{
int a[] = {1, 3, 5, 7, 9, 11, 14, 21, 22};
int start, end, k, i;
int searchFor = 21;
char found = 0;

start = 0;
end = 8;
while(end>=start)
{
k = (start+end)/2;
printf(" k is %d\n",k);

if( searchFor == a[k])
{
	printf(" element found at array location %d\n",k);
	found = 1;
	break;
}
else if( searchFor > a[k] )
	start = k + 1;
else
	end = k - 1;

}

if( found == 0)
printf(" the required element %d is not present in the given array\n",searchFor);
}

