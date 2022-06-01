// Import account struct and methods
#include "account.h"
#include "account.c"

// Set bank variables
Account accounts[];
int number_accounts = 0;

// New account menu
Account _account_new()
{
  int account_id = number_accounts + 1;
  printf("\nAccount ID: %d\n", account_id); // Testing purpose
  char name;
  int balance;
  int savings;
  printf("\nAccount -> Name: ");
  scanf("%s", &name);
  printf("\nAccount -> Initial balance: ");
  scanf("%i", &balance);
  printf("\nAccount -> Initial savings: ");
  scanf("%i", &savings);
  Account account;
  Account_ctor(&account, account_id, &name, balance, savings);
  accounts[account_id] = account;
  number_accounts += 1;
  return account;
}

// Manage accounts menu
void _accounts()
{
  Account account = _account_new();
  //_account(account);
  while (1)
  {
    for (int i = 0; i < number_accounts; i++)
    {
      printf(
          "\nID: %d\n"
          "Name: %s\n"
          "Balance: %d\n"
          "Savings: %d\n",
          accounts[i].id,
          accounts[i].name,
          accounts[i].balance,
          accounts[i].savings);
      printf("I: %d", i);
    }
    break;
  }
}

// Manage your account menu
void _account(Account account)
{
  while (1)
  {
    printf(
        "0: Savings\n"
        "1: Balance\n"
        "2: Add\n"
        "3: Remove\n"
        "4: New account\n"
        "5: Go back\n"
        "6: Move to savings\n"
        "7: Move from savings\n"
        "8: Exit\n"
        "==> ");
    int operation;
    scanf("%d", &operation);
    int add;
    int remove;
    switch (operation)
    {
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
      break;
    case 5:
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
    case 8:
      exit(0);
      break;
    default:
      printf("Enter a valid value, please try again\n");
      break;
    }
    if (operation == 5)
    {
      break;
    }
  }
}