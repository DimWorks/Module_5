#include <stdio.h>

extern int degree3(int x);

extern int degree4(int x);

int main()
{
	int x = 5;
	
	printf("%d^3 = %d\n", x, degree3(x));
	printf("%d^4 = %d\n", x, degree4(x));

	return(0);

}

