// Include file with prototypes
#include "String.h"
// Compare two strings
int strCmp(char s[], char t[]){
	int i = 0;
	while(s[i] != '\0' && t[i] != '\0'){
		if(s[i] < t[i])
			return -1;
		else if(s[i] > t[i])
			return 1;
		else
			i++;
	}
	if(s[i] != '\0')
		return 1;
	else if(t[i] != '\0')
		return -1;
	return 0;
}
