#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>     // required for malloc()

#define NORMALIZED 0
#define DENORMALIZED 1
#define SPECIAL 2
#define BIAS 127

/*
    Declare a "typedef struct {} flt;" to contain data for a float
    The data should include:
        An integer for the sign
            (1 for positive, -1 for negative)
        An integer for the exponent value
            (should be bit value to integer minus BIAS or -126 for denormalized)
        A float to contain the value of the mantissa
            (Actual float value extracted from the binary value)
        An integer to contain the mode using the defines above
            (NORM, DNORM and SPEC)
    Example after processing: -15.375 = 1 10000010 11101100000000000000000
        sign = -1
        exp = 3
        man = 0.9218750000
        mode = NORM
*/
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

/*
    Write a function to print a flt struct to screen.
    It should accept a flt struct and return nothing.
    Hint: Use if statement to print mode.
*/
void printFlt(flt fl) {
    printf("flt.sign is %d\n", fl.sign);
    printf("flt.exp is %d\n", fl.exp);
    printf("flt.mant is %f\n", fl.mant);
    if (fl.mode == 0) printf("flt.mode is Normalized\n");
    if (fl.mode == 1) printf("flt.mode is Denormalized\n");
    if (fl.mode == 2) printf("flt.mode is Special\n");
}

/*
    Write a function to get the actual float value back
    out of a flt struct.
    Hints:
        The float value produced will depend on the mode.
        To set a float to infinity use the math library constant INFINITY
        To set a float to not-a-number use the math library constant NAN
        Check the slides and text for conditions for NORN, DNORM and SPEC
        You need to return (sign) * M * 2^e
*/
float Flt_to_float(flt fl) {
    // if (mode == DENORMALIZED) {
    //     exp = -126;
    // }
    // else if (mode == SPECIAL) {  // i.e. exp==255
    //     if (mantissa == 0)
    //         f = INFINITY;   // float is infinity
    //     else
    //         f = NAN;        // float is Not-a-Number
    // }
    // else if (mode == NORMALIZED) {
    //     exp -= BIAS;
    // }
}



/*
    Write a main function that calls an prints results for
    each function when completed.

    get_flt_val_flt
    print_flt

    get_flt_bits_val
*/
int main() {
    printf("float f is -15.375\n#########################\n");
    float f = -15.375;
    int bits = getFltBitsInt(f);
    printf("bits: as int is decimal %d, or hex 0x%X\n", bits, bits);

    char c = getFltSignAsChar(f);
    int sign = getFltSign(f);
    printf("signs: char sign returns %c and int sign returns %d\n", c, sign);

    char* str = getFltExpStr(f);
    int exp = getFltExp(f);
    printf("exponents: str exp returns %s and int exp returns %d\n", str, exp);
    free(str);

    char* manStr = getFltManStr(f);
    float man = getFltMan(f);
    printf("mantissa: str   mantissa returns %s\n", manStr);
    printf("          float mantissa returns %f\n", man);
    free(manStr);

    char* bitStr = getFltBitString(f);
    printf("bits: as string is %s\n", bitStr);
    free(bitStr);

    return 0;
}
