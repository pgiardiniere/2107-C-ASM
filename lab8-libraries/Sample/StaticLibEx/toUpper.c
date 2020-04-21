// Include file with prototypes
#include "String.h"
// Convert all lower case char to upper case
void toUpper(char s[]){
	int i = 0;
	for(i=0; i<strLen(s); i++)
		if(s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	return;
}
