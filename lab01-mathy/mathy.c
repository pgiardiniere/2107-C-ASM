#include <stdio.h>

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
    printf("hello you should input an integer friend\n");
    int thenum;
    int summed;
    double avged;

    scanf("%d", &thenum);
    summed = sum(thenum);
    avged  = avg(thenum);

    printf("the num is %d\n",  thenum);
    printf("the sum is %d\n",  summed);
    printf("the avg is %lf\n", avged);

    printf("and git works from home-desktop w/ WSL exactly as it does on the laptop now")

    return 0;
}