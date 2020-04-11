// NOTE:    Both _add() and add() have over/underflow protections, independent of one another. I commented out _add()s
//          Also _add(), I made the entire function without any relational operators --- bitwise only
#include <stdio.h>
#include <limits.h>         // Used library to proxy 0x7FFFFFFF to INT_MAX, and 0x80000000 to INT_MIN

// Prototypes
int _add(int a, int b);
int add(int a, int b);
int sub(int a, int b);
int neg(int a);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);
int power(int a, int b);
int convert(char *input);
// Prototypes (to stop implicit declaration warnings)
int system (const char* command);
char * strtok (char * str, const char * delimiters);      // strtok() used once for newline character elimination.
void exit (int status);                                   // exit() used to expedite testing.

int _add (int a, int b) {
    int x = a;
    int y = b;
    int carry;
    while (y & 0xFFFFFFFF) {    // while y has any non-zero bits
        carry = x & y;
        x =     x ^ y;
        y = carry << 1;
    }
    int c = x;
    // // Detect Underflow
    // // Maximum possible underflow (INT_MIN + INT_MIN) yields 0. Min underflow is INT_MAX. Thus underflow -> c:Positive (0 <= c <= INT_MAX)
    // int aNonPositive = a & INT_MIN;
    // int bNonPositive = a & INT_MIN;
    // x = c;
    // x = ~x;                     // bitwise negate, if X was positive (underflow), make negative
    // x = x >> 31;                // get x most significant digit
    // if (aNonPositive)
    //     if (bNonPositive)
    //         if (x) { printf("Underflow\n"); return(0); }    // If X had overflowed, 

    // // Detect Overflow
    // // Maximum possible overflow (INT_MAX + INT_MAX) yields -2. Min overflow is INT_MIN. Thus underflow -> c:Negative (INT_MIN <= c <= -2)
    // int aNonNegative; if (aNonPositive) aNonNegative = 0;   // if (a <= 0), then !(a > 0)
    // int bNonNegative; if (aNonPositive) bNonNegative = 0;
    // x = c;
    // x = x >> 31;
    // if (aNonNegative)
    //     if (bNonNegative)
    //         if (x) { printf("Overflow\n"); return(0); }

    // printf("Calculation is in-bounds. Result is %d\n", c);
    return c;
}

int add (int a, int b) {
    int c = _add(a, b);
    
    // Detect whether we over/underflowed. If not, return result.
    if (a >= 0 && b >= 0 && c < a) {
        printf("Overflow\n"); exit(-1);
    }
    else if (a <= 0 && b <= 0 && c > a) {
        printf("Underflow\n"); exit(-1);
    }
    else {
        return c;
    }
}

// Return negation of a and add 1
int neg(int a) { return add( ~a, 1 ); }

// Define safe subtract by add - negate b
int sub(int a, int b) { 
    return add(a, neg(b));
}

// Define multiply by repeatedly calling add
int mul(int a, int b) {
    int result = 0;
    // Get sign of product.
    int negate;
    if ( a < 0 && b < 0 || a > 0 && b > 0)
        negate = 0;
    else negate = 1;
    // Force a, b positive. reassign negativity at end.
    if (a < 0) a = neg(a);
    if (b < 0) b = neg(b);

    int i = 0;
    if (a < b) {
        while (i < a) {
            result = add(result, b);
            i = add(i, 1);
        }
    }
    else {
        while (i < b) {
            result = add(result, a);
            i = add(i, 1);
        }
    }
    if (negate) result = neg(result);
    return result;
}

// Define integer division by repeatedly calling subtract
int div(int a, int b) {
    int count = 0;
    // Get sign of product.
    int negate;
    if ( a < 0 && b < 0 || a > 0 && b > 0 )
        negate = 0;
    else negate = 1;
    // Force a, b positive. reassign negativity at end.
    if (a < 0) a = neg(a);
    if (b < 0) b = neg(b);
    while (b <= a) {
        a = sub(a, b);
        count = add(count, 1);
    }
    if (negate) count = neg(count);
    return count;
}

int mod(int a, int b){
    int count = 0;
    // Get sign of product.
    int negate;
    if ( a < 0 && b < 0 || a > 0 && b > 0 )
        negate = 0;
    else negate = 1;
    // Force a, b positive. reassign negativity at end.
    if (a < 0) a = neg(a);
    if (b < 0) b = neg(b);
    while (b <= a) {
        a = sub(a, b);
        count = add(count, 1);
    }
    if (negate) count = neg(count);
    return a;
}

// Define power by calling multiply exp times
int power(int n, int exp) {
    if (exp < 0) { printf("No negative exponents allowed on set of integers.\n"); exit(-1); }
    if (exp == 0) return 1;
    int result = 1;
    while (exp > 0) {
        result = mul(result, n);
        exp = sub(exp, 1);
    }
    return result;
}

// Extract the integer from the input string and convert to int
int convert(char *input) {
    // Declare int for result extracted from input // Declare int for sign of result,  // Declare two iterators
    int result = 0;
    int sign;          // 0 denotes positive, 1 denotes negative
    int i;
    int j;
    // Declare a buffer for numeric chars
    char nums[50];
    // Set error to zero - no error found yet     // int error;
    // Check for space in element 1
    if ( !(input[1] == 32) ) { printf("Unexpected input, should have a space here\n"); exit(-1); }
    // Check for negative integer at element 2
    if ( input[2] == 45 ) { 
        sign = 1; 
        i = 3;
    }
    else {
        sign = 0;
        i = 2;
    }
    // Loop to copy all numeric chars to buffer
        // i is iterator for input string and should start at first numeric char
        // j is iterator for buffer where numeric chars are copied
    j = 0;
    while (input[i] != '\0') {
        if (input[i] < 48 || input[i] > 57) { printf("that's not a numeric char, enter valid input next time\n"); exit(-1); }
        nums[j] = input[i];
        j++;
        i++;
    }
    nums[j] = '\0';
    // Now that verified good input, build our int from the clean char array
    j--;
    i = 1;
    while (j >= 0) {
        result += mul((nums[j] - 48), i);
        i *= 10;
        j--;                                    // we could have used the arithmetic functions defined above instead of arithmetic operators
    }   
    if (sign == 1) { result = neg(result); }    // Re-apply our sign for output
    return result;
}

void menu() {
    printf("\nSafe Integer Calculator\n");
    printf("+ x to add\n");
    printf("- x to subtract\n");
    printf("* x to multiply\n");
    printf("/ x to divide\n");
    printf("%% x to modulus\n");
    printf("~ x to negate\n");
    printf("^ x to raise by power x\n");
    printf("c x to clear result\n");
    printf("q x to quit\n");
    return;
}

int main(int argc, char *argv[]) {

    int result = 0;     // Cumulative result - running total
    int n = 0;          // For number conversion from input string
    char input[50];     // Input string
    input[0] = '\0';    // Put null in operator char so loop works

    // Loop until quit is selected
    while(input[0] != 'q' && input[0] != 'Q'){
        // Show menu choices
        menu();
        // Print prompt with running total
        printf("\nresult = %d > ", result);
        // Get input string
        fgets(input, 49, stdin);              // replaced gets() with fgets() & strtok() to get input WITHOUT comiler warnings
        strtok(input, "\n");
        // Clear screen
        system("clear");

        // Switch on operator char input[0]
        switch (input[0]){
            case '+':
                result = add(result, convert(input));
                break;
            case '-':
                result = sub(result, convert(input));
                break;
            case '*':
                result = mul(result, convert(input));
                break;
            case '/':
                result = div(result, convert(input));
                break;
            case '%':
                result = mod(result, convert(input));
                break;
            case '~':
                result = neg(result);
                break;
            case '^':
                result = power(result, convert(input));
                break;
            case 'c':
            case 'C':
                result = 0;
                break;
            case 'q':
            case 'Q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Enter a valid operator and operand\n");

        }
    }
    return 0;
}