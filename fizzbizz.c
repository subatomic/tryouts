// The Fizz Bizz program

#include <stdio.h>

int main(void)
{
	int i = 0;
	
	for (i = 0; i <= 100; i++) {
		if (((i % 3) == 0) && ((i % 5) == 0))
			printf("FizzBizz (%d)\n", i);
		else if ((i % 3) == 0)
			printf("Fizz (%d)\n", i);
		else if ((i % 5) == 0)
			printf("Bizz (%d)\n", i);
	}
	return 0;
}

