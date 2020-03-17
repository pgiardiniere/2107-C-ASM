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

/*
    This function should only use bitwise operators and
    relational operators
*/
// Add operation using only bitwise operators
int _add(int a, int b){
    // Loop until b is zero

        // Find carry 1 bits - a AND b assign to carry

        // Find non carry 1 bits - a XOR b assign to a

        // Multiply carry by 2 by shift and assign to b

    return a;
}


/*
    Safe add() should call _add() and check for both
    overflow and underflow errors.
*/
// Safe add operation
int add(int a, int b){
    // Declare int for result
    int result = 0;
    // Call to _add() a and b and assign to result

    // Check for overflow - look at page 90 in book

    // Check for underflow - look at page 90 in book

    return result;
}


/*
    Negate a by using a bitwise operator and safe add().
    Look on page 95 in book.
    Replace the zero with an expression that solves this.
*/
// Define negation with ~ and safe add
int neg(int a){
    // Return negation of a and add 1
    return 0;   // Replace 0 with code
}


/*
    Remember that subtraction is the same as addition
    if you negate one of the operands.
    Replace the zero with an expression that solves this.
*/
// Define safe subtract by safe add - negate b
int sub(int a, int b){
    return 0;  // Replace 0 with code
}


/*
    Safe mul() uses an iterative call to safe add()
    to calculate a product. Remember that
        5 x 4 = 5 + 5 + 5 + 5 = 20
*/
// Define safe multiply by calling safe add b times
int mul(int a, int b){
    // Declare and initialize cumulative result
    int result = 0;
    // Declare sign of product - initially assume positive

    // For efficiency - smaller number should be multiplier

    // Absolute value of a and flip sign

    // Absolute value of b and flip sign

    // Accumulate result

    // Set sign to output

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

    unsigned long size = sizeof(int);
    printf("sizeof int is %lu\n", size);
    printf("bitsof int is %lu\n", size*8);
    printf("bit representation :: 32 bits\n");
    printf("0000 0000 0000 0000 0000 0000 0000 0000\n");
    printf("hex representation :: 32 bits\n");
    printf("FFFF FFFF\n");                                                  // ^> implies we have 0x80000000        (Verified)
    printf("Integer Min is %d with hexcode %x\n", INT_MIN, INT_MIN);        // define __INT_MIN__ ( -INT_MAX - 1)   == (decimal) -2,147,483,648
    printf("Integer Max is  %d with hexcode %x\n", INT_MAX, INT_MAX);       // define __INT_MAX__ 0x7fffffff        == (decimal)  2,147,483,647
                                                                            // MIN binary :: 1000 0000 0000 0000 0000 0000 0000 0000
                                                                            // MAX binary :: 0111 1111 1111 1111 1111 1111 1111 1111
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