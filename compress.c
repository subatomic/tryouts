/*
 * Compress : 	A simple program to compress
 * 				consecutive occurance of characters
 * 				in the given string
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
int itoa(int n, char s[])
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

	return i;
}

// compress
void compress(char* src)
{	
	char ch = 0;
	char tmp[100];

	int wr_idx 		= 0;
	int rd_idx 		= 0;
	int len 		= 0;
	int occurance 	= 0;
	int slen 		= 0;


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
			slen = itoa((int)occurance, tmp);
			memcpy(&src[wr_idx], &tmp[0], slen);
			wr_idx += slen;
			occurance = 0;
		} else {
			src[wr_idx++] = ch;
			occurance = 0;
		}
	}	
	
	// null terminate
	src[wr_idx] = '\0';

}
		
int main (void)
{
	char src[1000] = "battery type is AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaBBBaaaaaaAlphaaa";
	char dst[1000];

	printf("Original = %s\n", src);
	compress(src);
	printf("Compressed  = %s\n", src);
	return 0;
}
