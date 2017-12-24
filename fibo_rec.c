#include<stdio.h>

int fibo(int);

int main()
{
	int n, Tn;	
	puts("\nEnter the value of n for which to give fibonacci term");
	scanf("%d",&n);

	Tn = fibo(n);

	printf("\n%dth term of the fibonacci series is %d\n", n, Tn);


}


int fibo(int n)
{
	if( n == 1 )
		return 0;
	else if( n == 2 )
		return 1;
	else 
		return ( fibo(n-1) + fibo(n-2) );
}
