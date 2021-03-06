#include <stdio.h>
#include <limits.h>
#include <math.h>       // MUST COMPILE WITH "gcc -o floatsStuff floatsStuff.c -lm" to get linker to find pow() function.
#include <float.h>
#include <stdlib.h>     // required for malloc()

#define NORMALIZED 0
#define DENORMALIZED 1
#define SPECIAL 2
#define BIAS 127

typedef struct {
    int sign;
    int exp;
    float mant;
    int mode;
} flt;

// Get the bits of a float, and instead store them in an int
int getFltBitsInt(float f) {
    return *(int*)&f;
}

char getFltSignAsChar(float f) {        // Write a function that returns the sign of a float as a char.
    int bits = getFltBitsInt(f);        // You should call get_flt_bits_int to get the bits in an int
    bits >>= 31;                        // and return '1' if the sign is negative else return '0'.  The
    return (bits & 1) ? '1' : '0';      // function should accept a float and return a string.
}

char getFltSign(float f) {              // Write a function that returns the sign of a float as an integer.
    int bits = getFltBitsInt(f);        // You should call get_flt_bits_int to get the bits in an int
    bits >>= 31;                        // and return -1 if the sign is negative else return 1.  The function
    return (bits & 1) ? -1 : 1;         // should accept a float and return an int.
}

char* getFltExpStr(float f) {
    char* expStr = malloc(9);                   // Write a function to return a string containing the
    if (expStr == NULL) {                       // actual binary value of the exponent of a float in a
        perror("Error : ");                     // char array.  You should call get_flt_bits_int to get
        exit(-1);                               // the bits in an int and return the string.
    }                                           // Example:
    expStr[8] = '\0';                               // for f = -15.375
    int bits = getFltBitsInt(f);                        // n = 1 10000010 11101100000000000000000
    bits >>= 23;                                        // the exponent bits are "10000010"
    int i = 7;                                  // The function should accept a float and return a string.
    while (i >= 0) {
        expStr[i] = (bits & 1) ? '1' : '0';
        bits >>= 1;
        i--;
    }
    return expStr;
}

int getFltExp(float f) {
    char* expStr = getFltExpStr(f);             // Write a function to return an integer containing the
    int exp = 0;                                // actual integer value of the exponent of a float.  You
    int place = 1;                              // should call get_flt_bits_int to get the bits in an int
    int i = 7;                                  // and return the int with the exponent value.
    while (i >= 0) {                            // Example:
        exp += (expStr[i] - 48) * place;        //     for f = -15.375
        place *= 2;                             //         n = 11000001011101100000000000000000
        i--;                                    //         the exponent bits are 10000010
    }                                           //         the actual value of the exponent is 3
    free(expStr);                               // The function should accept a float and return an int.
    return exp;
}

int getExpMode(float f) {               // Write a function to return an integer containing the
    int exp = getFltExp(f);             // mode of the exponent of a float.  You should call
    int expMode;                        // get_flt_exp_val to get the bits in an int and return
    if (exp == 0)                       // the int with the mode value.
        expMode = DENORMALIZED;         // Example:
    if (exp == 255)                     //     for f = -15.375
        expMode = SPECIAL;              
    else                                //         n = 11000001011101100000000000000000
        expMode = NORMALIZED;           //         the exponent bits are 10000010
    return expMode;                     //         the mode is NORM
}                                       // The function should accept a float and return an int.

char* getFltManStr(float f) {         
    char* manStr = malloc(24);          // Write a function to return a string containing the
    if (manStr == NULL) {               // actual binary value of the mantissa of a float in a
        perror("Error : ");             // char array.  You should call get_flt_bits_int to get
        exit(-1);                       // the bits in an int and return the string.
    }                                   // Example:
    manStr[23] = '\0';                  //     for f = -15.375
    int bits = getFltBitsInt(f);        //         n = 11000001011101100000000000000000
    bits >>= 0;                         //         the mantissa bits are "11101100000000000000000"
    int i = 22;                         // The function should accept a float and return a string.
    while (i >= 0) {                    
        manStr[i] = (bits & 1) ? '1' : '0';
        bits >>= 1;
        i--;
    }
    return manStr;
}

float getFltMan(float f) {
    char* manStr = getFltManStr(f);         // Write a function to return a float containing the
    float man = 0;                          // actual float value of the mantissa of a float.  You
    float place = 0.5;                      // should call get_flt_bits_int to get the bits in an int
    int i = 0;                              // and return the int with the mantissa value.
    while (manStr[i]) {                     // Example:
        man += (manStr[i] - 48) * place;    //     for f = -15.375
        place *= 0.5;                       //         n = 11000001011101100000000000000000
        i++;                                //         the mantissa bits are 11101100000000000000000
    }                                       //         the actual value of the mantissa is 0.9218750000
    free(manStr);                           // The function should accept a float and return an int.
    return man;
}

char* getFltBitString(float f) {
    char* bitStr = (char*) malloc(34);  // Write a function to return a string containing the
    bitStr[0] = getFltSignAsChar(f);    // actual binary value of a float in a char array.  You
    bitStr[1] = ' ';                    // should call get_flt_sign_char, get_flt_exp_str and
    char* expStr = getFltExpStr(f);     // get_flt_man_str to get the bits in an char and two
    int i = 0;                          // strings and return the concatenated string.
    while (i < 8) {                     // Example:
        bitStr[i + 2] = expStr[i];      //     for f = -15.375
        i++;                            //         n = 11000001011101100000000000000000
    }                                   //         The sign is '1'
    bitStr[10] = ' ';                   //         the exponent is "10000010"
    char* manStr = getFltManStr(f);     //         and the mantissa bits are "11101100000000000000000"
    i = 11;                             //         The string should be formatted as:
    while (i < 32) {                    //             "1 10000010 11101100000000000000000" to clearly
        bitStr[i] = manStr[i - 11];     //             separate the 3 parts.
        i++;                            // The function should accept a float and return a string.
    }
    bitStr[33] = '\0';
    return bitStr;
}

/*
    Write a function to separate the parts of a float
    into a flt struct as described above.  You should
    call get_flt_sign_val, get_flt_exp_mode,
    get_flt_exp_val and get_flt_man_val.
    Hint:  make sure to set exponent to -126 for
    DNORM mode.
*/
flt assembleFlt(float f) {
    int sign = getFltSign(f);
    int exp = getFltExp(f);
    float mantissa = getFltMan(f);
    int mode = getExpMode(f);

    if (mode == DENORMALIZED) {
        exp = -126;
    }
    else if (mode == NORMALIZED) {
        exp -= BIAS;
    }

    flt fl = { sign, exp, mantissa, mode };
    return fl;
}

void printFlt(flt fl) {
    printf("flt.sign is %d\n", fl.sign);
    printf("flt.exp is %d\n", fl.exp);
    printf("flt.mant is %f\n", fl.mant);
    if (fl.mode == 0) printf("flt.mode is Normalized\n");
    if (fl.mode == 1) printf("flt.mode is Denormalized\n");
    if (fl.mode == 2) printf("flt.mode is Special\n");
}

// The float value produced will depend on the mode.
// Check the slides and text for conditions for NORM, DNORM and SPEC
// You need to return (sign) * M * 2^e
float Flt_to_float(flt fl) {
    float f;
    if (fl.mode == SPECIAL) {
        f = (fl.mant == 0) ? INFINITY: NAN;
    }
    else if (fl.mode == DENORMALIZED) {
        f = fl.sign * fl.mant * (int) pow(2, fl.exp);
    }
    else if (fl.mode == NORMALIZED) {
        f = fl.sign * (1 + fl.mant) * (int) pow(2, fl.exp);
    }
    return f;
}

// Simply change the value of float f below to test entire suite of functions with different floating-point numbers.
int main() {
    float f = -15.375;
    printf("float f is %f\n#########################\n", f);

    int bits = getFltBitsInt(f);
    printf("bits:     int bits is decimal %d, or hex 0x%X\n", bits, bits);

    char c = getFltSignAsChar(f);
    int sign = getFltSign(f);
    printf("sign:     char sign returns    %c, int sign returns %d\n", c, sign);

    char* str = getFltExpStr(f);
    int exp = getFltExp(f);
    printf("exponent: str exp returns %s, int exp returns %d\n", str, exp);
    free(str);

    char* manStr = getFltManStr(f);
    float man = getFltMan(f);
    printf("mantissa: str   mantissa returns %s\n", manStr);
    printf("          float mantissa returns %f\n\n", man);
    free(manStr);

    char* bitStr = getFltBitString(f);
    printf("bits: as string is %s\n\n", bitStr);
    free(bitStr);

    flt fl = assembleFlt(f);
    printFlt(fl);    
    printf("\n");

    float translated = Flt_to_float(fl);
    printf("translated flt back into float with value %f\n", translated);

    return 0;
}