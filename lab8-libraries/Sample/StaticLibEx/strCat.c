// Include file with prototypes
#include "String.h"
// Concatenate two strings
void strCat(char dest[], char src[]){
	int i = strLen(dest);
	int j = 0;
	while(src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return;
}
