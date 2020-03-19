// NOTE: I wasn't looking at instructions carefully when I programmed this.
// Both _add() and add() have over/underflow protections, independent of one another. I commented out _add()s
// Also _add(), I made the entire function without any relational operators --- bitwise only

// I also defined sub() independently of _add(), before I created the neg() method.


/*
    Safe integer calculator - warns if an overflow or
    underflow error occurs.

    Menu
    Negation
    Safe unsigned ops
    Safe signed ops
    Arithmetic without + - * / % ++ or --

    Code the functions below and uncomment the code in main()
    when completed.

    Code the functions in order as they appear.  Subsequent
    functions depend on previous functions.  You cannot use
    any math operators (+ - * / % ++ or --) except simple
    assignment (=).  However, you may use relational and
    logical operators.

    The _add() function should only use bitwise operators.  All
    other functions can call functions necessary to complete the
    required operation.  I added some hints above functions.

*/
#include <stdio.h>
#include <limits.h>         // temporariliy included for easy limit comparison during testing

// Review :: Operator types allowed :: (obviously, assignment.)
//      Relational      ==  !=  <  <=   >  >=
//      Logical         &&  ||  !
//      Bitwise         &   |   ^   ~   << >>


// Prototypes
int _add(int a, int b);     // Bitwise
int add(int a, int b);      // Bitwise || Logical || Relational
int sub(int a, int b);
int neg(int a);             // also, any function may use another which you have defined to get its output. (mult as repeated add, for ex)
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);
int power(int a, int b);
int convert(char *input);

// Prototypes (stops all implicit declaration warnings)
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
        printf("Overflow\n"); return(0);
    }
    else if (a <= 0 && b <= 0 && c > a) {
        printf("Underflow\n"); return(0);
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
    // Get sign of product. Assign most significant digit to vars. If both 0 or both 1, then result is positive.
    int x = a >> 31;
    int y = b >> 31;
    int negate = x ^ y;
    // Force a, b positive for our loops to work. reassign negativity at end.
    a &= 0x7FFFFFFF;
    b &= 0x7FFFFFFF;
    // For efficiency - smaller number should be multiplier
    int i = 0;
    if (a < b) {
        while (i < a) {
            result = add(result, b);
            i++;
        }
    }
    else {
        while (i < b) {
            result = add(result, a);
            i++;
        }
    }
    // Accumulate result
    // Set sign to output
    if (negate) result = neg(result);
    return result;
}


/*
    Safe div() repeatedly subtracts b from a, counting the
    number of subtractions until a < b, which it returns.
*/
// Define safe divide by calling safe subtract b times
int div(int a, int b){
    // Declare int to count how many times can b be subtracted from a
    int cnt = 0;
    // Declare sign

    // Absolute value of a and flip sign

    // Absolute value of b and flip sign

    // loop to calculate how many times can b be subtracted from a

    // Set sign to output

    return cnt;
}


/*
    Safe mod() repeatedly subtracts b from a until a < b, returning a.
*/
// Define safe modulus by calling safe subtract
int mod(int a, int b){
    // Absolute value of a

    // Absolute value of b

    // Find remainder by repeated subtraction a - b

    return a;
}


/*
    Safe power() calculates as the math power function but
    only uses the safe operations.
        result = n^exp
    Loop until exp is zero
        result = result * n
        exp = exp - 1
    Remember the special case for n^0

*/
// Define safe power by calling safe multiply exp times
int power(int n, int exp){
    // Declare int for result of n^exp
    int result = 0;
    // Loop and multiply to calculate n^exp

    return result;
}


/*
    This function extracts the integer value from the input string.
        If input = "+ -123", result = -123.
        If input = "* 987654", result = 987654.
    The best way to solve complicated problems is to work them out
    on paper first.
*/
// Extract the integer from the input string and convert to int
int convert(char *input){
    // Declare int for result extracted from input
    int result = 0;
    // Declare int for sign of result

    // Declare two iterators

    // Declare a buffer for numeric chars

    // Set error to zero - no error found yet

    // Check for space in element 1

    // Check for negative integer at element 2

    // Loop to copy all numeric chars to buffer
    // i is iterator for input string and should start at first numeric char
    // j is iterator for buffer where numeric chars are copied
    // This must test for chars between 0 and 9

    // i gets position of last numeric char in buffer

    // j is now used for power function - start at zero

    // Construct integer from buffer using power j increases and i decreases

    // Set sign for output
    return result;
}

void menu(){
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

    // Write code here to test your functions
    // Uncomment code below when done
    result = add(20, 32); printf("result of 20 + 32 is  %d\n", result);
    result = neg(20);     printf("result of ~20     is %d\n", result);
    result = sub(32, 20); printf("result of 32 - 20 is  %d\n", result);
    result = mul( 2,4 );  printf("result of 2 * 3   is  %d\n", result);
    result = mul( 2,-1 ); printf("result of 2 * 10  is  %d\n", result);

    exit(-1);

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