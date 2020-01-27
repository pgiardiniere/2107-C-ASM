#include <stdio.h>

enum Colors {Red, Green, Blue};

int main() {
    // Block of code    -- since initialized outisde, data persists
    char *s;
    {
        s = "yo";
    }
    printf("%s\n", s);

    // if else loops and short circuiting and whatever
    int x = 2;
    // dis logic bad. anything < 30 will just do the first thing. Not the laters. doi.
    if (x <= 30) 
        printf("stuff\n");
    else if (x <= 20) 
        printf("other stuff\n");
    else if (x <= 10)
        printf("Der\n");
    else
        printf("der\n");

    // #########################
    // Switches in C
    // #########################

    // Switch statements in C :: (may only use Chars, Ints, Enums)
    // this will print case 2 AND default --- no breaks
    int cond = 2;
    switch (cond) {
        case 1:
            printf("cond = 1\n");
        case 2:
            printf("cond = 1\n");
        default:
            printf("cond !=(1 || 2)");
    }

    // Switch statements in C :: (may only use Chars, Ints, Enums)
    // this will print case 2 ONLY 
    int cond = 2;
    switch (cond) {
        case 1:
            printf("cond = 1\n");
            break;
        case 2:
            printf("cond = 2\n");
            break;
        default:
            printf("cond !=(1 || 2)");
    }

    // May also use switches with Enums
    enum Colors color = Red;
    switch (color) {
        case Red:
            printf("cond = Red\n");
            break;
        case Green: 
            printf("cond = Green\n");
            break;
        default:
            printf("cond = Blue");
    }

    // Switches are really good for menuing systems --- marginally more performant than chained if-else statements

    // #########################
    // Loop stuff......... come onnn so slow
    // #########################
    int n = 5;
    int i = 0;
    int sum = 0;

    for (i = 1; i <= 5; i++) sum += i;
    printf("sum = %d\n", sum);



    return 0;
}