#include<stdio.h>

int calc_factorial(int);

int main()
{
	int fac, num;

	puts("\n Enter the number for which to calculate factorial");
	scanf("%d",&num);
	
	if( num < 1)
	{
		puts("\n Number should be > 0");
		return;
	}

	fac = calc_factorial(num);

	printf("\n Factorial for %d = %d\n", num, fac);
}

int calc_factorial(int n)
{
	if( n == 1 )
		return 1;
	else
	{
		return( n* calc_factorial(n-1) );
	}	
}
