# include <stdio.h>
# include <stdarg.h>

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

// ---------- book method: Multiple Arbitrary Arguments ---------- 
// va_arg == variable argument --- some methods contained in <stdarg.h>
void minprintf(char *fmt, ...) {
    /* points to each unnamed arg in turn */
    va_list ap;
    char *p,*sval;
    int ival;
    double dval;
    /* make ap point to 1st unnamed arg */
    va_start(ap,fmt);
    for(p=fmt;*p;p++) {
        if(*p != '%') {
            putchar(*p);
            continue;
        }
        switch(*++p) {
            case 'd':
                ival = va_arg(ap,int);
                printf("%d",ival);
                break;
            case 'f':
                dval = va_arg(ap,double);
                printf("%f",dval);
                break;
            case 's':
                for(sval = va_arg(ap,char *);*sval;sval++)
                putchar(*sval);
                break;
            default:
                putchar(*p);
            break;
        }
    }
    va_end(ap); /* clean up when done */
}

// ---------- Professor method :: Multiple Arbitrary Arguments ----------
void PrintFloats (int n, ...) {
    int i;
    double val;
    printf ("Printing floats:");
    va_list vl;
    va_start(vl,n);
    for (i=0;i<n;i++) {
        val=va_arg(vl,double);
        printf (" [%.2f]",val);
    }
    va_end(vl);
    printf ("\n");
}

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
    // # inclue <stdio.h>
    printf("\n");

    // when scanf reaches end of file (EOF) it returns -1. This is recognized in C as a symb. const. equal to -1.
    int i = 0;
    // while (scanf("%d", &i) != EOF) { printf("%d\n", i); } // works for stuff other than stdin, Ctrl+c to exit

    // printf() formats::
    printf("Char = %c\n", 'a');
    printf("Integer, short or char = %d\n", -5);
    printf("Integer, short or char = %u\n", 10);
    printf("Double or Float = %.2f\n", 3.4);
    printf("String = %s\n", "Hello, World!");
    printf("Pointer = %p\n", 123456);           // hexes & pointers are functionally the same
    printf("Hex = 0x%08X\n", 123456);           // 08 pads with (0-8) 0s up to 8 places  // initial 0x helps you remember it's hexcode.
    printf("Scientific = %e\n", 123.456789);
    printf("Percent = %%\n");

    // #########################
    // Variable length arg lists
    // #########################
    // Consider printf -- has arbitrary input args (0->many
    // ---------- text method -----------
    // we use the (...) ellispes in the method which takes arbitrary args

    // ---------- professor method -----------
    // professor method execution code
    PrintFloats (3,3.14159,2.71828,1.41421);

    
    // #########################

    // #########################

    return 0;
}