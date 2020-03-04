#include <cs50.h>
#include <math.h>
#include <stdio.h>

int requestChangeFloat(void);

int main(void)
{
    //ask the user for input of change to return
    printf("%d\n", requestChangeFloat());
}

int requestChangeFloat(void)
{
    //set the change owed variable
    float dollarsOwed;

    do
    {
        //ask for the user's input
        dollarsOwed = get_float("Change owed: ");
        printf("%f\n", dollarsOwed);
    }
    //if the user enters an amount less than 0, continue to prompt for change owend
    while (dollarsOwed <= 0);

    int centsOwed;
    centsOwed = round(dollarsOwed * 100);

    int totalCoins = 0;

    while (centsOwed >= 25)
    {
        centsOwed -= 25;
        totalCoins++;
    }

    while (centsOwed >= 10)
    {
        centsOwed -= 10;
        totalCoins++;
    }

    while (centsOwed >= 5)
    {
        centsOwed -= 5;
        totalCoins++;
    }

    while (centsOwed >= 1)
    {
        centsOwed -= 1;
        totalCoins++;
    }

    return totalCoins;
}
