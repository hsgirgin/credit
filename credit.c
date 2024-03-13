#include <stdio.h>
#include <cs50.h>
#include <math.h>
bool check(long number,long length){
    int even = 1;
    long sum = 0;
    for(long digit = 0;digit < length;digit++){
        if (even%2 == 0){
            sum += (2L * ((number/(long)pow(10L, digit))%10L))%10;
            sum += ((2L * ((number/(long)pow(10L, digit))%10L))/10)%10;
        }
        else{
            sum += ((number/(long)pow(10L, digit)))%10L;
        }
        even++;
    }
    if (sum%10L == 0){
        return true;
    }
    else{
        printf("INVALID\n");
        return false;
        ;
    }
}
int main(void){
    long number;
    do {
    number = get_long("Card Number: ");
    }
    while(number<0);
    if(number/1000000000000000L > 0){
        if (check(number,16L) == true){
            if ((number/(long)pow(10,15))%10L == 4L){
                printf("VISA\n");
                return 0;
                        }
            if ((number/(long)pow(10,15))%10L == 5L&&(number/(long)pow(10,14))%10L > 0L&&(number/(long)pow(10,14))%10L < 6L){
                printf("MASTERCARD\n");
                return 0;
                        }
        }
    printf("INVALID\n");

    }
    else if(number/100000000000000L > 0){
        if (check(number,15L) == true){
            if ((number/(long)pow(10,14))%10L == 3L){
                if ((number/(long)pow(10,13))%10L == 4L||(number/(long)pow(10,13))%10L == 7L){
                    printf("AMEX\n");
                    return 0;
                        }
                        }
        }
        printf("INVALID\n");

    }
    else if(number/1000000000000L > 0){
        if (check(number,13L) == true){
            if ((number/(long)pow(10,12))%10L == 4L){
                printf("VISA\n");
                return 0;

            }

        }
        printf("INVALID\n");

    }
    else{

        printf("INVALID\n");
    }
}
