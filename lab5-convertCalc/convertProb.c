// This program should accept numeric values in hexadecimal,
// decimal, octal and binary formats as:
//     Hex 0x0 to 0xFFFFFFFF
//     Dec 0   to 4294967295
//     Oct o0  to o37777777777
//     Bin b0  to b11111111111111111111111111111111

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

int main() {
    char input[50];
    unsigned int n = 0;
    char output[50];

    printf("Enter a binary, octal, decimal or hexadecimal number\n");
    printf("convert > ");
    fgets(input, 49, stdin);
    strtok(input, "\n");

    // Detect input data type, make into unsigned int
    if(input[0] == '0' && input[1] == 'x')       n = hex_to_uint(input);    // Hexadecimal
    else if (input[0] >= '0' && input[0] <= '9') n = dec_to_uint(input);    // Decimal
    else if (input[0] == 'o')                    n = oct_to_uint(input);    // Octal
    else if (input[0] == 'b')                    n = bin_to_uint(input);    // Binary
    else printf("ERROR: Unknown data type: %s\n", input);                   // Unknown/invalid type

    // Print unsigned int as Dec, Hex, Oct, and Bin
    printf("The decimal value of %s is %u\n", input, n);
    uint_to_hex(n, output);
    printf("The hexadecimal value of %s is %s\n", input, output);
    uint_to_oct(n, output);
    printf("The octal value of %s is %s\n", input, output);
    uint_to_bin(n, output);
    printf("The binary value of %s is %s\n", input, output);

    return 0;
}

// ########################################
//  Char[] (hex, oct, bin) to Unsigned Ints
// ########################################
unsigned int hex_to_uint(char *input){
    unsigned int result = 0;
    unsigned int multiplier = 1;

    int i = 0;                      // walk i to end of data. must process string in reverse
    while (input[i]) { i++; } i--;
    
    while (i > 1) {
        if ( input[i] >= 48 && input[i] <= 57 ) result += (input[i] - 48) * multiplier;  // if   chars 0-9, multiply and add to result 
        else                                    result += (input[i] - 55) * multiplier;  // else chars A-F, multiply and add to result
        multiplier *= 16;
        i--;
    }
    return result;
}

unsigned int dec_to_uint(char *input){
    unsigned int result = 0;
    unsigned int multiplier = 1;

    int i = 0;
    while (input[i]) { i++; } i--;
    
    while (i > -1) {
        result += (input[i] - 48) * multiplier;  // assume good input - i.e. chars 0-9, multiply and add to result 
        multiplier *= 10;
        i--;
    }
    return result;
}

unsigned int oct_to_uint(char *input){
    unsigned int result = 0;
    unsigned int multiplier = 1;

    int i = 0;
    while (input[i]) { i++; } i--;
    
    while (i > 0) {
        result += (input[i] - 48) * multiplier;  // assume good input - i.e. chars 0-7, multiply and add to result 
        multiplier *= 8;
        i--;
    }
    return result;
}

unsigned int bin_to_uint(char *input){
    unsigned int result = 0;
    unsigned int multiplier = 1;

    int i = 0;
    while (input[i]) { i++; } i--;
    
    while (i > 0) {
        result += (input[i] - 48) * multiplier;  // assume good input - i.e. chars 0-7, multiply and add to result 
        multiplier *= 2;
        i--;
    }
    return result;
}

// ########################################
//  Conversions :: Unsigned ints to Hex/Oct/Bin
// ########################################
void uint_to_hex(unsigned int n, char *output) {
    unsigned int remainder;
    unsigned int dividend = n;
    // Declare a char array buffer
    char temp[50];
    int i = 0;

    while (dividend != 0) {
        remainder = dividend % 16;
        dividend = dividend / 16;
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
    return;
}

void uint_to_oct(unsigned int n, char *output){
    unsigned int remainder;
    unsigned int dividend = n;
    // Declare a char array buffer
    char temp[50];
    int i = 0;

    while (dividend != 0) {
        remainder = dividend % 8;
        dividend = dividend / 8;
        temp[i] = remainder + 48;
        i++;
    }
    temp[i] = '\0';         // Put null at end of buffer

    output[0] = '0';        // Format output (octal -> '0' integer literal). Then reverse-copy temp to yield output octal string.
    int j = 1; i--;
    while (i > -1) {
        output[j] = temp[i];
        j++; 
        i--;
    }
    output[j] = '\0';       // Put null at end of buffer
    return;
}

void uint_to_bin(unsigned int n, char *output){
    unsigned int remainder;
    unsigned int dividend = n;
    // Declare a char array buffer
    char temp[50];
    int i = 0;

    while (dividend != 0) {
        remainder = dividend % 2;
        dividend = dividend / 2;
        temp[i] = remainder + 48;
        i++;
    }
    temp[i] = '\0';         // Put null at end of buffer

    output[0] = '0';        // Format output (Bin -> '0b' integer literal). Then reverse-copy temp to yield output binary string.
    output[1] = 'b';
    int j = 2; i--;
    while (i > -1) {
        output[j] = temp[i];
        j++; 
        i--;
    }
    output[j] = '\0';       // Put null at end of buffer
    return;
}