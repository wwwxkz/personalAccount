
// Class methods declaration
void Account_ctor(Account *const me, int id, char *name, int balance, int savings);
void Account_savings(Account *const me);
void Account_balance(Account *const me);
void Account_add_balance(Account *const me, int value);
void Account_remove_balance(Account *const me, int value);
void Account_add_savings(Account *const me, int value);
void Account_remove_savings(Account *const me, int value);

// Class methods initialization
void Account_ctor(Account *const me, int id, char *name, int balance, int savings)
{
  me->id = id;
  me->name = name;
  me->balance = balance;
  me->savings = savings;
}
void Account_savings(Account *const me)
{
  printf("\nAccount name: %s, \nSavings: %i\n", me->name, me->savings);
}
void Account_balance(Account *const me)
{
  printf("\nAccount name: %s, \nBalance: %i\n", me->name, me->balance);
}
void Account_add_balance(Account *const me, int value) { me->balance += value; }
void Account_remove_balance(Account *const me, int value)
{
  me->balance -= value;
}
void Account_add_savings(Account *const me, int value)
{
  if (me->balance - value > 0)
  {
    me->savings += value;
    me->balance -= value;
  }
}
void Account_remove_savings(Account *const me, int value)
{
  if (me->savings - value > 0)
  {
    me->balance += value;
    me->savings -= value;
  }
}
