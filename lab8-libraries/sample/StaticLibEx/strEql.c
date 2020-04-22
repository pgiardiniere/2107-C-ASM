// Include file with prototypes
#include "String.h"
// Are two strings equal
int strEql(char s[], char t[]){
	int i = 0;
	while(s[i] != '\0' && t[i] != '\0'){
		if(s[i] != t[i])
			return 0;
		i++;
	}
	if(s[i] != '\0')
		return 0;
	else if(t[i] != '\0')
		return 0;
	return 1;
}
