//A a program  calculating the net pay and prompt the user for inputs:
/*
Name: George Maina Ngugi
RegNo:CT100/G/26171/25
Description; A program  calculating net pay from users input:
*/
#include <stdio.h>

int main() {
    float hours, rate, grossPay, tax, netPay;

    // Input houurs worked in a week:
           printf("Enter hours worked in a week: ");
           scanf("%f", &hours);
           printf("Enter hourly wage: ");
           scanf("%f", &rate);

    // Calculate gross pay:
           if (hours <= 40)
             grossPay = hours * rate;
         else
            grossPay = (40 * rate) + ((hours - 40) * rate * 1.5);

    // Calculate tax:
          if (grossPay <= 600)
            tax = 0.15 * grossPay;
         else
            tax = 0.15 * 600 + 0.20 * (grossPay - 600);

    // Calculate the Net pay
           netPay = grossPay - tax;

    // printing out gross pay,taxes and net pay
          printf("\nGross Pay is %.2f", grossPay);
          printf("\n tax is %f" ,tax);
          printf("\nNet Pay is %.2f" , netPay);
    return 0;
}