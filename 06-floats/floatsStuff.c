#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>     // required for malloc()

#define NORMALIZED 0        // but... should be 1
#define DENORMALIZED 1      // but... should be 0   // email prof? maybe not.
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
    int mant;
    int mode;
} flt;

// Get the bits of a float, and instead store them in an int
int getFltBitsInt(float f) {
    return *(int*)&f;   // &f get float pointer location, (int*) cast to int pointer, *(int*) interpret memory at int* pointer as an int val
}

char getFltSignAsChar(float f) {    // Write a function that returns the sign of a float as a char.
    int bits = getFltBitsInt(f);    // You should call get_flt_bits_int to get the bits in an int
    bits >>= 31;                    // and return '1' if the sign is negative else return '0'.  The
    return (bits & 1) ? '1' : '0';  // function should accept a float and return a string.
}

char getFltSignAsInt(float f) {     // Write a function that returns the sign of a float as an integer.
    int bits = getFltBitsInt(f);    // You should call get_flt_bits_int to get the bits in an int
    bits >>= 31;                    // and return -1 if the sign is negative else return 1.  The function
    return (bits & 1) ? -1 : 1;     // should accept a float and return an int.
}

/*
    Write a function to return a string containing the
    actual binary value of the exponent of a float in a
    char array.  You should call get_flt_bits_int to get
    the bits in an int and return the string.
    Example:
        for f = -15.375
            n = 1 10000010 11101100000000000000000
            the exponent bits are "10000010"
    The function should accept a float and return a string.
*/
char* getFltExpBitsAsStr(float f) {
    char* expStr = malloc(9);
    if (expStr == NULL) { perror("Error : "); exit(-1); }
    expStr[8] = '\0';

    int bits = getFltBitsInt(f);
    bits >>= 23;
    int i = 7;
    while (i >= 0) {
        expStr[i] = (bits & 1) ? '1' : '0';
        bits >>= 1;
        i--;
    }
    return expStr;
}


/*
    Write a function to return an integer containing the
    actual integer value of the exponent of a float.  You
    should call get_flt_bits_int to get the bits in an int
    and return the int with the exponent value.
    Example:
        for f = -15.375
            n = 11000001011101100000000000000000
            the exponent bits are 10000010
            the actual value of the exponent is 3
    The function should accept a float and return an int.
*/
int getFltExp(float f) {
    char* expStr = getFltExpBitsAsStr(f);
    int exp = 0;
    int place = 1;
    int i = 7;
    while (i >= 0) {
        exp += (expStr[i] - 48) * place;
        place *= 2;
        i--;
    }
    free(expStr);
    exp -= BIAS;
    return exp;
}

/*
    Write a function to return an integer containing the
    mode of the exponent of a float.  You should call
    get_flt_exp_val to get the bits in an int and return
    the int with the mode value.
    Example:
        for f = -15.375
            n = 11000001011101100000000000000000
            the exponent bits are 10000010
            the mode is NORM
    The function should accept a float and return an int.
*/




/*
    Write a function to return a string containing the
    actual binary value of the mantissa of a float in a
    char array.  You should call get_flt_bits_int to get
    the bits in an int and return the string.
    Example:
        for f = -15.375
            n = 11000001011101100000000000000000
            the mantissa bits are "11101100000000000000000"
    The function should accept a float and return a string.
*/




/*
    Write a function to return a float containing the
    actual float value of the mantissa of a float.  You
    should call get_flt_bits_int to get the bits in an int
    and return the int with the mantissa value.
    Example:
        for f = -15.375
            n = 11000001011101100000000000000000
            the mantissa bits are 11101100000000000000000
            the actual value of the mantissa is 0.9218750000
    The function should accept a float and return an int.
*/




/*
    Write a function to return a string containing the
    actual binary value of a float in a char array.  You
    should call get_flt_sign_char, get_flt_exp_str and
    get_flt_man_str to get the bits in an char and two
    strings and return the concatenated string.
    Example:
        for f = -15.375
            n = 11000001011101100000000000000000
            The sign is '1'
            the exponent is "10000010"
            and the mantissa bits are "11101100000000000000000"
            The string should be formatted as:
                "1 10000010 11101100000000000000000" to clearly
                separate the 3 parts.
    The function should accept a float and return a string.
*/




/*
    Write a function to separate the parts of a float
    into a flt struct as described above.  You should
    call get_flt_sign_val, get_flt_exp_mode,
    get_flt_exp_val and get_flt_man_val.
    Hint:  make sure to set exponent to -126 for
    DNORM mode.
*/




/*
    Write a function to print a flt struct to screen.
    It should accept a flt struct and return nothing.
    Hint: Use if statement to print mode.
*/




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




/*
    Write a main function that calls an prints results for
    each function when completed.
    get_flt_sign_char
    get_flt_sign_val

    get_flt_exp_str
    get_flt_exp_val

    get_flt_man_str
    get_flt_man_val

    get_flt_bits_str

    get_flt_val_flt
    print_flt

    get_flt_bits_val
*/
int main(){
    float f = -15.375;
    int exp = getFltExp(f);
    printf("exp of %f (less Bias) is %d\n", f, exp);     // prints 3

    f = 0;
    exp = getFltExp(f);
    printf("exp of %f (less Bias) is %d\n", f, exp);     // prints -127  --- wrong? but makes sense, it's not detecting denormalized I think

    f = 1;
    exp = getFltExp(f);
    printf("exp of %f (less Bias) is %d\n", f, exp);     // prints 0, expected



    return 0;
}
