// Include file with prototypes
#include "String.h"
// Copy one string to another
void strCpy(char dest[], char src[]){
	int i = 0;
	while(src[i] != '\0')
		dest[i] = src[i++];
	dest[i] = '\0';
	return;
}
