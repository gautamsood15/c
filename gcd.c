#include<stdio.h>

int main()
{
	int num1, num2, gcd, i;

	gcd = 1;
	i = 1;

	puts("\n Enter the two num among which to calculate gcd");
	scanf("%d%d", &num1, &num2);
	
	while(1)
	{
		if( (i > num1) || (i > num2) )
			break;

		if( (num1 % i == 0) && (num2 % i == 0) )
			gcd = i;
		i++;
	}

	printf("\n gcd found between %d and %d is %d\n", num1, num2, gcd);
}
