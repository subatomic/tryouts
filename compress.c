
/*
 * Compress : 	A simple program to compress
 * 				consecutive occurance of characters
 * 				in the given string
 *	
 * To Try	:	In place replacement
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reverse the string
void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = (strlen(s) - 1); i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

// Integer to ASCII
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;

	do {
		s[i++] = n % 10 + '0';
	}while ((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

// Inplace compress
void inplace_compress(char* src, char* dst)
{	
	char ch = 0;
	char tmp[2];

	int wr_idx 		= 0;
	int rd_idx 		= 0;
	int len 		= 0;
	int occurance 	= 0;


	// get string length
	len = strlen(src);

	while (rd_idx < len) {

		ch = src[rd_idx];

		// find numbe of consecutive occurance
		while ((src[rd_idx] == ch) && (src[rd_idx] != '\0')) {
			occurance++;
			rd_idx++;
		}

		// compress if more than two consecutive occurance
		if (occurance > 2) {
			src[wr_idx++] = ch;
			itoa((int)occurance, tmp);
			src[wr_idx++] = tmp[0];
			occurance = 0;
		} else {
			src[wr_idx++] = ch;
			occurance = 0;
		}
	}	
	
	// null terminate
	src[wr_idx] = '\0';

}
		
// Compress
void compress(char* src, char* dst)
{	
	char ch = 0;
	char tmp[2];

	int wr_idx 		= 0;
	int rd_idx 		= 0;
	int len 		= 0;
	int occurance 	= 0;


	// get string length
	len = strlen(src);

	while (rd_idx < len) {

		ch = src[rd_idx];

		// find numbe of consecutive occurance
		while ((src[rd_idx] == ch) && (src[rd_idx] != '\0')) {
			occurance++;
			rd_idx++;
		}

		// compress if more than two consecutive occurance
		if (occurance > 2) {
			dst[wr_idx++] = ch;
			itoa((int)occurance, tmp);
			dst[wr_idx++] = tmp[0];
			occurance = 0;
		} else {
			dst[wr_idx++] = ch;
			occurance = 0;
		}
	}	
	
	// null terminate
	dst[wr_idx] = '\0';
}

int main (void)
{
	char src[100] = "battery type is AAA";
	char dst[100];

	printf("Original = %s\n", src);
	inplace_compress(src, dst);
	printf("Compressed  = %s\n", src);
	return 0;
}
