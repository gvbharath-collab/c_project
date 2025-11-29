#include <stdio.h>

// Global variables
char name[50];
int pin = 0;
float balance = 0;
int accountCreated = 0;   // 0 = no account, 1 = created

// Function declarations
void createAccount();
void deposit();
void withdrawMoney();
void checkBalance();
void changePin();

int main() {
    int choice;

    while (1) {
        printf("\n===== SIMPLE BANKING SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Change PIN\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            createAccount();
        else if (choice == 2)
            deposit();
        else if (choice == 3)
            withdrawMoney();
        else if (choice == 4)
            checkBalance();
        else if (choice == 5)
            changePin();
        else if (choice == 6) {
            printf("Thank you! Exiting...\n");
            break;
        }
        else
            printf("Invalid choice! Try again.\n");
    }

    return 0;
}

// Create Account Function
void createAccount() {
    if (accountCreated == 1) {
        printf("Account already created!\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Set a 4-digit PIN: ");
    scanf("%d", &pin);

    balance = 0;
    accountCreated = 1;

    printf("Account created successfully!\n");
}

// Deposit Function
void deposit() {
    if (accountCreated == 0) {
        printf("Please create an account first.\n");
        return;
    }

    int enteredPin;
    float amount;

    printf("Enter PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin) {
        printf("Incorrect PIN!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0)
        printf("Invalid amount!\n");
    else {
        balance += amount;
        printf("Deposited %.2f successfully!\n", amount);
    }
}

// Withdraw Function
void withdrawMoney() {
    if (accountCreated == 0) {
        printf("Please create an account first.\n");
        return;
    }

    int enteredPin;
    float amount;

    printf("Enter PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin) {
        printf("Incorrect PIN!\n");
        return;
    }

    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
    }
    else if (amount > balance) {
        printf("Insufficient balance!\n");
    }
    else {
        balance -= amount;
        printf("Withdrawn %.2f successfully!\n", amount);
    }
}

// Check Balance Function
void checkBalance() {
    if (accountCreated == 0) {
        printf("Please create an account first.\n");
        return;
    }

    int enteredPin;
    printf("Enter PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin)
        printf("Incorrect PIN!\n");
    else
        printf("Your balance: %.2f\n", balance);
}

// Change PIN Function
void changePin() {
    if (accountCreated == 0) {
        printf("Please create an account first.\n");
        return;
    }

    int oldPin, newPin;

    printf("Enter old PIN: ");
    scanf("%d", &oldPin);

    if (oldPin != pin) {
        printf("Incorrect PIN!\n");
        return;
    }

    printf("Enter new PIN: ");
    scanf("%d", &newPin);

    pin = newPin;
    printf("PIN changed successfully!\n");
}
