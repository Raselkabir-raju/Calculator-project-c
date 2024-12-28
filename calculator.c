#include <stdio.h>

int main() {
    double result = 0, number; 
    char operation, choice;
    int first_time = 1;

    while (1) {
        if (first_time) {
            printf("Enter the first number: ");
            scanf("%lf", &result);
            first_time = 0;
        }

        printf("Select an operation (+, -, *, /, %%): ");
        scanf(" %c", &operation);

        if (operation == 'c' || operation == 'C') {
        
            first_time = 1; 
            result = 0;
            printf("Calculator reset! Starting fresh...\n");
            continue; 
        }

      
        printf("Enter the next number: ");
        scanf("%lf", &number);

        switch (operation) {
            case '+':
                result += number;
                break;
            case '-':
                result -= number;
                break;
            case '*':
                result *= number;
                break;
            case '/':
                if (number != 0)
                    result /= number;
                else
                    printf("Error: Division by zero is not allowed.\n");
                break;
            case '%':
                if ((int)number != 0)
                    result = (int)result % (int)number;
                else
                    printf("Error: Modulus by zero is not allowed.\n");
                break;
            default:
                printf("Invalid operation! Please use +, -, *, /, %%, or C.\n");
                continue;
        }

        printf("Current Result: %.2lf\n", result);

        printf("Do you want to continue with this result? (y/n or r to reset): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            printf("Final Result: %.2lf\n", result);
            printf("Thank you for using the calculator!\n");
            break; 
        } else if (choice == 'r' || choice == 'R') {
            first_time = 1; 
            result = 0; 
            printf("Calculator reset! Starting fresh...\n");
        }
    }

}
