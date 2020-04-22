// Include file with prototypes
#include "String.h"
// Convert all upper case char to lower case
void toLower(char s[]){
	int i = 0;
	for(i=0; i<strLen(s); i++)
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	return;
}
