// Simple program to purge the given character from 
// the string

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int purge(char c, char* str)
{
	int rd_ptr = 0;
	int wr_ptr = 0;
	int len = strlen(str);
	int i = 0;

	for (i = 0; i < len; i++) {
		if (str[rd_ptr] != c) {
			str[wr_ptr] = str[rd_ptr];
			wr_ptr++;
		}
		rd_ptr++;
	}
	str[wr_ptr] = '\0';
	return 0;
}

int main(void)
{	
	char str[100] = "Alphabet";
	printf("%s\n", str);
	purge('A', str);
	printf("%s\n", str);
	return 0;
}
			
			

	
