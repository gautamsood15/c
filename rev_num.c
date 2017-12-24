#include<stdio.h>

int rev_number(int);

int main()
{
	int i, num, rev;

	puts("\n Enter the number to be reversed");
	scanf("%d", &num);

	rev = rev_number(num);

	printf("\n The reverse no. for %d is %d\n", num, rev);
}

int rev_number(int n)
{
	int rem, rev = 0;
	while(n)
	{
		rem = n%10;
		rev = rev*10 + rem;
		n = n/10;
	}
	return rev;
}
