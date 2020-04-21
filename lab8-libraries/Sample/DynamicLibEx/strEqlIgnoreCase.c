// Include file with prototypes
#include "String.h"
// Are two strings equal ignoring case
int strEqlIgnoreCase(char s[], char t[]){
	int i = 0;
	// Make temp copies of s and t in upper case
	char su[100], tu[100];
	strCpy(su, s);
	toUpper(su);
	strCpy(tu, t);
	toUpper(tu);
	while(s[i] != '\0' && t[i] != '\0'){
		if(su[i] != tu[i])
			return 0;
		i++;
	}
	if(s[i] != '\0')
		return 0;
	else if(t[i] != '\0')
		return 0;
	return 1;
}
