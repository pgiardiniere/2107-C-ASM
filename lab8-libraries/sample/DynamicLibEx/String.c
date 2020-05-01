/*

    This file contains code that approximates C's string.h
    with some enhanced features.

*/

// Include file with prototypes
#include "String.h"


// String function code


// Convert all lower case char to upper case
void toUpper(char s[]){
	int i = 0;
	for(i=0; i<strLen(s); i++)
		if(s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	return;
}


// Convert all upper case char to lower case
void toLower(char s[]){
	int i = 0;
	for(i=0; i<strLen(s); i++)
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	return;
}


// Find the length of a string
int strLen(char s[]){
	int i = 0;
	while(s[i] != '\0')
		i++;
	return i;
}


// Copy one string to another
void strCpy(char dest[], char src[]){
	int i = 0;
	while(src[i] != '\0')
		dest[i] = src[i++];
	dest[i] = '\0';
	return;
}


// Concatenate two strings
void strCat(char dest[], char src[]){
	int i = strLen(dest);
	int j = 0;
	while(src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return;
}


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


// Compare two strings ignoring case
int strCmpIgnoreCase(char s[], char t[]){
	int i = 0;
	// Make temp copies of s and t in upper case
	char su[100], tu[100];
	strCpy(su, s);
	toUpper(su);
	strCpy(tu, t);
	toUpper(tu);
	while(s[i] != '\0' && t[i] != '\0'){
		if(su[i] < tu[i])
			return -1;
		else if(su[i] > tu[i])
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
