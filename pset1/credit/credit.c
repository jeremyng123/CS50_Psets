/**
 * amex uses 15-digit numbers -- starts with 34 or 37
 * mastercard uses 16-digit numbers -- starts with [51,55]
 * visa uses 13 and 16 digit numbers -- starts with 4
 * each number is a decimal number, not binary.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long power(int base, int raise);
int iterateDigits(long long card_number, int sigBit);

char *visa13(long long card_number);
char *visa16(long long card_number);
char *amex(long long card_number);
char *master(long long card_number);


int main(void){
    long long card_number, temp;
    printf("Please input card number: ");
    scanf("%lld", &card_number); // do not put \n at the end. it causes bug
    temp = card_number;
    int num_digits = 0;
    while (temp >= 1) {
        temp = temp / 10;
        num_digits += 1;
    }
    int sumEvenSigBits = 0;
    int sumOddSigBits = 0;
    // printf("%d\n",num_digits);
    if (num_digits == 13 && visa13(card_number)!= "INVALID"){
        for (int i = 1; i <= num_digits; i ++){
            if (i % 2 == 0) {
                sumEvenSigBits += iterateDigits(card_number, i);
            }
            else sumOddSigBits += iterateDigits(card_number, i);
        }
        if ((sumEvenSigBits + sumOddSigBits)%10 == 0) printf("VISA\n");
        else printf("INVALID\n");
    }
    else if (num_digits == 16 && visa16(card_number) != "INVALID"){
        for (int i = 1; i <= num_digits; i ++){
            if (i % 2 == 0) {
                sumEvenSigBits += iterateDigits(card_number, i);
            }
            else sumOddSigBits += iterateDigits(card_number, i);
        }
        if ((sumEvenSigBits + sumOddSigBits)%10 == 0) printf("VISA\n");
        else printf("INVALID\n");
    }
    else if (num_digits == 15 && amex(card_number) != "INVALID"){
        for (int i = 1; i <= num_digits; i ++){
            if (i % 2 == 0) {
                sumEvenSigBits += iterateDigits(card_number, i);
            }
            else sumOddSigBits += iterateDigits(card_number, i);
        }
        if ((sumEvenSigBits + sumOddSigBits)%10 == 0) printf("AMEX\n");
        else printf("INVALID\n");
    }
    else if (num_digits == 16 && master(card_number) != "INVALID"){
        for (int i = 1; i <= num_digits; i ++){
            if (i % 2 == 0) {
                sumEvenSigBits += iterateDigits(card_number, i);
            }
            else sumOddSigBits += iterateDigits(card_number, i);
        }
        if ((sumEvenSigBits + sumOddSigBits)%10 == 0) printf("MASTERCARD\n");
        else printf("INVALID\n");
    }
    else printf("INVALID\n");
    return 0;

}



/**
 * return the power
 */
long long power(int base, int raise){
    if (raise == 0) return 1;
    else if (raise == 1) return base;
    else return base * power(base, raise - 1);
}

/**
 * recursively iterate every 2 digits, starting from 2nd last digit
 */
int iterateDigits(long long card_number, int sigBit){
    long long  temp = card_number % power(10, sigBit);
    int digit = temp / power(10, sigBit - 1);
    if (sigBit % 2 != 0) return digit;
    digit *= 2;
    if (digit >= 10) digit -= 9;
    return digit;
}


/**
 * amex uses 15-digit numbers -- starts with 34 or 37
 * each number is a decimal number, not binary.
 */
char *amex(long long card_number){
    int validation = card_number / power(10, 13);
    // printf("at Amex: %d\n", validation);
    if (validation != 34 && validation != 37) return "INVALID";
    else {
        return "incomplete";
    }
}
/**
 * visa uses 13 and 16 digit numbers -- starts with 4
 */
char *visa13(long long card_number){
    int validation = card_number / power(10, 12);
    // printf("At Visa13: %d\n", validation);
    if (validation != 4) return "INVALID";
    else {
        return "incomplete";
    }
}

/**
 * visa uses 16 digit numbers -- starts with 4
 */
char *visa16(long long card_number){
    int validation = card_number / power(10, 15);
    // printf("At Visa16: %d\n", validation);
    if (validation != 4) return "INVALID";
    else {
        return "incomplete";
    }
}

/**
 * mastercard uses 16-digit numbers -- starts with [51,55]
 */
char *master(long long card_number){
    int validation = card_number / power(10, 14);
    // printf("At Master: %d\n", validation);
    if (validation != 51 && validation != 52 && validation != 53 && validation != 54 && validation != 55) return "INVALID";
    else {
        return "incomplete";
    }
}
