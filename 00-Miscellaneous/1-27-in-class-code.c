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
    int n = 10;
    int i = 0;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum1 = 0, sum2 = 0, sum3 = 0;               // multiple declaration/assignment

    for (i = 1; i <= 5; i++) sum1 += i;
    for (i = 0; i < 5; i++ ) sum2 += arr[i];
    printf("sum = %d\n", sum1);
    printf("sum = %d\n", sum2);

    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) continue;      // continue demo
        sum3 += arr[i];
    }

    // #########################
    // Goto & Labels
    // #########################
    // Goto is really a relic of COBOL-aged programming paradigm, but we have it in C too.

    // Here we use a GOTO to 'break' from a nested loop.
    // NOTE: According to almight StackOverflow, this is "the last remaining valid use-case" of gotos lolol

//     int j = 0, disaster = 0; i=0; // i already declared
//     for (i = 0; i < 5; i++) {
//         for (j = 0; j < 4; j++) {
//             if (disaster == 10) 
//                 goto error;
//             else
//                 disaster++;
//         }
//     }
//     goto okay;

// error:
//     printf("bad tings happen\n");
//     goto end;
// okay:
//     printf("okay\n");
//     goto end;
// end:

    // goto above position? Testing --- yep it works
    int crap = 2;
    above: crap--;
    printf("%d\n", crap);
    if (crap > 0) goto above;

    // #########################
    // Matrices, another use of inner loops
    // #########################
    int matrix[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    i = 0; int j = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\n", matrix[i][j]);
        }
    }

    return 0;
}