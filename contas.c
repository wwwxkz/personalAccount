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
} Account;

// Class methods declaration
void Account_ctor(Account *const me, char *name, int balance);
void Account_balance(Account *const me);
void Account_add_balance(Account *const me, int value);
void Account_remove_balance(Account *const me, int value);

// Class methods initialization
void Account_ctor(Account *const me, char *name, int balance) {
  me->name = name;
  me->balance = balance;
}
void Account_balance(Account *const me) {
  printf("\nAccount name: %s, \nBalance: %i\n", me->name, me->balance);
}
void Account_add_balance(Account *const me, int value) { me->balance += value; }
void Account_remove_balance(Account *const me, int value) {
  me->balance -= value;
}

// Main, initialize classes and create interaction menus
int main() {
  while (1) {
    int i = 1;
    // Accouts menu
    char name;
    int balance;
    printf("\nInsert the account name: ");
    scanf("%s", &name);
    printf("\nInsert your initial balance: ");
    scanf("%i", &balance);
    Account account;
    Account_ctor(&account, &name, balance);
    // Operation menu
    while (i == 1) {
      printf("1: Balance\n2: Add\n3: Remove\n4: New account\n5: Exit\n==> ");
      int operation;
      scanf("%d", &operation);
      int add;
      int remove;
      switch (operation) {
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
      default:
        printf("Enter a valid value, please try again\n");
        break;
      }
    }
  }
  return 0;
}
