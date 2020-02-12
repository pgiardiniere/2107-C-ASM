# include <stdio.h>

// For:: Union
# define NKEYS 3
# define INT 0
# define FLOAT 1
# define STRING 2

// For :: Bit-Fields
# define KEYWORD 1
# define EXTERNAL 2
# define STATIC 4

//

// unions are a feature in C, allow you to store multiple disparate datatypes in a single 'thing'
// basically useless. But they're part of the C Spec, so we're covering it. Won't use
union u_tag {
    int ival;
    float fval;
    char *sval;
};

int main() {
    // #########################
    // Union execution block ::
    // #########################
    union u_tag us;
    us.sval = "Hello World";
    us.fval = 123.45;
    us.ival = 5;
    union u_tag *u_ptr = &us;

    // int type = STRING;
    // int type = FLOAT;
    int type = INT;             // switching 'type' to the commented out lines will instead print the other vals.

    if(type == INT)
    printf("The value is: %d\n", u_ptr->ival);
    else if(type == FLOAT)
    printf("The value is: %f\n", u_ptr->fval);
    else if(type == STRING)
    printf("The value is: %s\n", u_ptr->sval);
    else
    printf("Bad type\n");

    // #########################
    // Bit Fields
    // #########################
    unsigned char flag = 0;             // Set all flag bits to zero
    flag |= KEYWORD;                    // Set KEYWORD bit
    printf("flag = %d\n", flag);
    flag |= STATIC;                     // Set STATIC bit
    printf("flag = %d\n", flag);

    // Check if STATIC bit is set
    if ( flag & STATIC ) printf("The STATIC bit is set.\n");
    else printf("The STATIC bit is NOT set.\n");

    // useful for: if needing to do multiple declaration (of 32 vars in an array or something)
    // you could instead use this, higher performance

    // you're flipping the 8 bits available in that char flag directly
    // flag at initialization & assignment to 0:
    //      0000 0000
    // flag at |= 1
    //      0000 0001
    // flag at |= 4         
    //      0000 1001
    // which is why we use the OR-Equals operator.

    // #########################
    // BEGIN :: Ch 7 material (see 07 folder)
    // Standard Input & Output
    // #########################



    return 0;
}