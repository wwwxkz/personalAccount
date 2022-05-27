#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Refactoring C++ code to C for learning purpose, trying abstract classes and
// how it compares to C++ code style and performance. Also improving old code
// and removing hard code using menus and objects as now using classes I can

// Class data declartion
typedef struct {
  char *name;
  int balance;
  int savings;
} Account;

// Class methods declaration
void Account_ctor(Account *const me, char *name, int balance, int savings);
void Account_savings(Account *const me);
void Account_balance(Account *const me);
void Account_add_balance(Account *const me, int value);
void Account_remove_balance(Account *const me, int value);
void Account_add_savings(Account *const me, int value);
void Account_remove_savings(Account *const me, int value);

// Class methods initialization
void Account_ctor(Account *const me, char *name, int balance, int savings) {
  me->name = name;
  me->balance = balance;
}
void Account_savings(Account *const me) {
  printf("\nAccount name: %s, \nSavings: %i\n", me->name, me->savings);
}
void Account_balance(Account *const me) {
  printf("\nAccount name: %s, \nBalance: %i\n", me->name, me->balance);
}
void Account_add_balance(Account *const me, int value) { me->balance += value; }
void Account_remove_balance(Account *const me, int value) {
  me->balance -= value;
}
void Account_add_savings(Account *const me, int value) {
  if (me->balance - value > 0) {
    me->savings += value;
    me->balance -= value;
  }
}
void Account_remove_savings(Account *const me, int value) {
  if (me->savings - value > 0) {
    me->balance += value;
    me->savings -= value;
  }
}

// Main, initialize classes and create interaction menus
int main() {
  while (1) {
    int i = 1;
    // Accouts menu
    char name;
    int balance;
    int savings;
    printf("\nInsert the account name: ");
    scanf("%s", &name);
    printf("\nInsert your initial balance: ");
    scanf("%i", &balance);
    printf("\nInsert your initial savings: ");
    scanf("%i", &savings);
    Account account;
    Account_ctor(&account, &name, balance, savings);
    // Operation menu
    while (i == 1) {
      printf("0: Savings\n1: Balance\n2: Add\n3: Remove\n4: New account\n5: "
             "Exit\n6: Move to savings\n7: Move from savings\n==> ");
      int operation;
      scanf("%d", &operation);
      int add;
      int remove;
      switch (operation) {
      case 0:
        Account_savings(&account);
        break;
      case 1:
        Account_balance(&account);
        break;
      case 2:
        printf("How much you want to add: ");
        scanf("%i", &add);
        Account_add_balance(&account, add);
        Account_balance(&account);
        break;
      case 3:
        printf("How much you want to remove: ");
        scanf("%i", &remove);
        Account_remove_balance(&account, remove);
        Account_balance(&account);
        break;
      case 4:
        i = 0;
        break;
      case 5:
        exit(0);
        break;
      case 6:
        printf("How much you want to move to savings: ");
        scanf("%i", &add);
        Account_add_savings(&account, add);
        Account_savings(&account);
        break;
      case 7:
        printf("How much you want to move from savings: ");
        scanf("%i", &remove);
        Account_remove_savings(&account, remove);
        Account_savings(&account);
      default:
        printf("Enter a valid value, please try again\n");
        break;
      }
    }
  }
  return 0;
}
