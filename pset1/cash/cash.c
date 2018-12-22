/**
 * Using US denominations
 * quarters (25¢)
 * dimes (10¢)
 * nickels (5¢)
 * pennies (1¢)
 */

#include <stdio.h>

int changer(int chg, int deno, int amtChge){
    if (chg < deno) return amtChge;
    return changer(chg-deno, deno, amtChge+1);  // recursive function
}

int main (void){
    int change;
    do {
        printf("How much change do you need?: ");
        scanf("%d",&change);
    } while (change <= 0);
    int QUARTERS = 25;
    int DIMES = 10;
    int NICKELS = 5;
    int PENNIES = 1;
    int amtQuarters = 0, amtDimes = 0, amtNickels = 0, amtPennies = 0;

    while (change >= PENNIES){
        if (change > QUARTERS) {
            amtQuarters = changer(change, QUARTERS,amtQuarters);
            change %= QUARTERS;
        }
        else if (change > DIMES) {
            amtDimes = changer(change, DIMES, amtDimes);
            change %= DIMES;
        }
        else if (change > NICKELS) {
            amtNickels = changer(change, NICKELS, amtNickels);
            change %= NICKELS;
        }
        else {
            amtPennies = changer(change, PENNIES, amtPennies);
            change %= PENNIES;
        }
    }
    printf("Quarters: %d, Dimes: %d, Nickels: %d, Pennies: %d\n",amtQuarters, amtDimes, amtNickels, amtPennies);
    return 0;
}