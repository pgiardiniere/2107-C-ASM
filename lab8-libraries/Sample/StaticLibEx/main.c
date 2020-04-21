#include <stdio.h>
#include <stdlib.h>

// Include file with prototypes
#include "String.h"

#define CLEAR 1

int main(){

	// Strings
	char aString[100];
	char bString[100];
	// Index or iterator
	int i = 0;
	char c;

	// Clear screen
	system("clear");

	// Write toUpper function
	printf("Use custom toUpper to convert a string to upper case\n\n");
	strCpy(aString, "AbCdEf");
	printf("aString = %s\n", aString);
	toUpper(aString);
	printf("aString = %s\n\n", aString);

	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("clear");


	// Use custon strLen()
	printf("Use custom strLen to count chars in a string\n\n");
	printf("aString = %s has %d chars\n\n", aString, strLen(aString));

	// Use custom strCpy()
	printf("Use custom strCpy to copy a string\n\n");
	strCpy(aString, "AbCdEf");
	printf("aString = %s\n", aString);
	strCpy(bString, "EfGhIj");
	printf("bString = %s\n\n", bString);

	// Use custom strCat()
	printf("Use custom strCat to concatenate strings\n\n");
	strCat(aString, bString);
	printf("aString = %s\n\n", aString);

	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("clear");


	// Use custom strCmp()
	printf("Use custom strCmp to compare strings\n\n");
	strCpy(aString, "AbCdEf");
	strCpy(bString, "EfGhIj");
	i = strCmp(aString, bString);
	printf("%s is %d compared to %s\n\n", aString, i, bString);
	i = strCmp(bString, aString);
	printf("%s is %d compared to %s\n\n", bString, i, aString);
	strCpy(bString, "AbCdEf");
	i = strCmp(aString, bString);
	printf("%s is %d compared to %s\n\n", aString, i, bString);

	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("clear");


	// Use custom strCmpIgnoreCase()
	printf("Use custom strCmp to compare strings\n\n");
	strCpy(aString, "AbCdEf");
	strCpy(bString, "ABCDEF");
	i = strCmp(aString, bString);
	printf("%s is %d compared to %s with strCmp()\n\n", aString, i, bString);
	printf("Use custom strCmpIgnoreCase to compare strings\n\n");
	i = strCmpIgnoreCase(aString, bString);
	printf("%s is %d compared to %s with strCmpIgnoreCase()\n\n", aString, i, bString);

	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("clear");


	// Use custom strEql
	printf("Test strings for equality using custom functions\n\n");
	printf("aString = %s\n", aString);
	printf("bString = %s\n\n", bString);
	printf("Use custom strEql to compare strings\n\n");
	i = strEql(aString, bString);
	if(i)
		printf("The strings %s and %s are equal with strEql (%d).\n\n", aString, bString, i);
	else
		printf("The strings %s and %s are NOT equal with strEql (%d).\n\n", aString, bString, i);


	// Use custom strEqlIgnoreCase
	printf("Use custom strEqlIgnoreCase to compare strings\n\n");
	i = strEqlIgnoreCase(aString, bString);
	if(i)
		printf("The strings %s and %s are equal with strEqlIgnoreCase (%d).\n\n", aString, bString, i);
	else
		printf("The strings %s and %s are NOT equal with strEqlIgnoreCase (%d).\n\n", aString, bString, i);

	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("clear");

    return 0;
}
