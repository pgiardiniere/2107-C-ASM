/*
    This program should accept numeric values in hexadecimal,
    decimal, octal and binary formats as:

        Hex 0x0 to 0xFFFFFFFF
        Dec 0 to 4294967295
        Oct o0 to o37777777777
        Bin b0 to b11111111111111111111111111111111
*/
#include <stdio.h>
#include <string.h>

//int input_to_decimal(char *input);
unsigned int bin_to_uint(char *input);
unsigned int oct_to_uint(char *input);
unsigned int hex_to_uint(char *input);
unsigned int dec_to_uint(char *input);
void uint_to_hex(unsigned int n, char *output);
void uint_to_oct(unsigned int n, char *output);
void uint_to_bin(unsigned int n, char *output);

int error = 0;

int main(){

    char input[50];
    unsigned int n = 0;
    char output[50];

    // so, we are intaking __whatever__ base.
    // we make that into an unsigned int
    // then, we turn that unsigned int   into __whatever__ base.

    // printf("Enter a binary, octal, decimal or hexadecimal number\n");
    // printf("convert > ");
    // gets(input);

    unsigned int x = 0;
    unsigned int y = 48;
    unsigned int z = 65;
    printf("x,y,z = %d %d %d\n", x, y, z);
    printf("x,y,z = %c %c %c\n", x, y, z);

    x += 48;
    printf("x,y,z = %c %c %c\n", x, y, z);

    char c[1];
    c[0] = 9 + 48;
    printf("%c\n", c[0]);

    unsigned int m = 32;
    uint_to_hex(m, output);
    printf("hex value of %d is %s\n", m, output);



    return -1;

    // // Detect input data type
    // if(input[0] == '0' && input[1] == 'x')       n = hex_to_uint(input);    // Hexadecimal
    // else if (input[0] >= '0' && input[0] <= '9') n = dec_to_uint(input);    // Decimal
    // else if (input[0] == 'o')                    n = oct_to_uint(input);    // Octal
    // else if (input[0] == 'b')                    n = bin_to_uint(input);    // Binary
    // else printf("ERROR: Unknown data type: %s\n", input);                   // Unknown/invalid type

    // // Print results
    // printf("The decimal value of %s is %u\n", input, n);
    // uint_to_hex(n, output);
    // printf("The hexadecimal value of %s is %s\n", input, output);
    // uint_to_oct(n, output);
    // printf("The octal value of %s is %s\n", input, output);
    // uint_to_bin(n, output);
    // printf("The binary value of %s is %s\n", input, output);

    return 0;
}

unsigned int hex_to_uint(char *input){
    unsigned int result = 0;
    unsigned int mult = 1;

    int i;
    for (i = 2; i < sizeof(input); i++) {
        // If between 0 and 9 add 0 to 9 to result with multiplier

        // If between A and F add 10 to 15 to result with multiplier

        // Error - exit

        // Advance multiplier to next position value
        mult *= 2;
    }

    return result;
}


/*
    Copy hex_to_uint() and modify for decimal input.
*/
// Convert a unsigned integer char array to uint
unsigned int dec_to_uint(char *input){
    unsigned int result = 0;

    return result;
}


/*
    Copy dec_to_uint() and modify for octal input.
*/
// Convert a octal char array to uint
unsigned int oct_to_uint(char *input){
    unsigned int result = 0;

    return result;
}


/*
    Copy oct_to_uint() and modify for binary input.
*/
// Convert a binary char array to unsigned int
unsigned int bin_to_uint(char *input){
    unsigned int result = 0;

    return result;
}


/*
    This function converts from unsigned int to a hex
    char array.  Try this on paper before coding.
*/
// Convert a unsigned integer char array to hexadecimal
void uint_to_hex(unsigned int n, char *output){
    unsigned int remainder;
    unsigned int dividend = n;
    // Declare a char array buffer
    char temp[50];
    int i = 0;

    while (dividend != 0) {
        remainder = dividend % 16;
        dividend = dividend/16;
        if (remainder > 9) { temp[i] = remainder + 55; }
        else               { temp[i] = remainder + 48; }
        i++;
    }
    temp[i] = '\0';         // Put null at end of buffer

    output[0] = '0';        // Format output. Then reverse-copy temp to yield output hex string.
    output[1] = 'x';
    int j = 2; i--;
    while (i > -1) {
        output[j] = temp[i];
        j++; 
        i--;
    }
    output[j] = '\0';       // Put null at end of buffer

    printf("temp has %s\n", temp);
    printf("output has %s\n", output);
    return;
}


/*
    Copy uint_to_hex() and modify for octal
*/
// Convert a unsigned integer char array to octal
void uint_to_oct(unsigned int n, char *output){

    return;
}


/*
    Copy uint_to_oct() and modify for binary
*/
// Convert a unsigned integer char array to binary
void uint_to_bin(unsigned int n, char *output){

    return;
}