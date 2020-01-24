#include <stdio.h>
#include <stdlib.h>

int sum(int num) {
    int sum = 0;
    while (num > -1) {
        sum += num;
        num--;
    }
    return sum;
}

double avg(int num) {
    double avg = 0;
    int summed = sum(num);
    avg = (double)summed/num;
    return avg;
}

int main() {
    printf("hello! you should input positive, non-zero integer, friend\n\n");
    int summed;
    double avged;
    char str[256];
    int thenum;

    scanf("%s", str);
    thenum = atoi(str);    
    while (thenum <= 0) {
        printf("You seem poor at following instructions. Please input a positive, nonzero integer.\n");
        printf("If you input a decimal anyways then I'm gonna truncate it.\n\n");
        scanf("%s", str);
        thenum = atoi(str);
    }
    summed = sum(thenum);
    avged  = avg(thenum);

    printf("the num is %d\n",  thenum);
    printf("the sum is %d\n",  summed);
    printf("the avg is %lf\n", avged);

    return 0;
}