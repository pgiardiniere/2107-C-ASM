// Include file with prototypes
#include "String.h"
// Find the length of a string
int strLen(char s[]){
	int i = 0;
	while(s[i] != '\0')
		i++;
	return i;
}
