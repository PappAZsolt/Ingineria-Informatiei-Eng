#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
  string accountHolderName;
  int accountNumber;
  double balance;

public:
  BankAccount(string name, int accNumber, double initialBalance)
      : accountHolderName(name), accountNumber(accNumber), balance(initialBalance) {}

  void deposit(double amount)
  {
    if (amount > 0)
    {
      balance += amount;
      cout << "Deposit successful. New balance: " << balance << "\n";
    }
    else
    {
      cout << "Invalid deposit amount.\n";
    }
  }

  void withdraw(double amount)
  {
    if (amount > balance)
    {
      cout << "Insufficient funds. Withdrawal denied.\n";
    }
    else if (amount <= 0)
    {
      cout << "Invalid withdrawal amount.\n";
    }
    else
    {
      balance -= amount;
      cout << "Withdrawal successful. New balance: " << balance << "\n";
    }
  }

  friend ostream &operator<<(ostream &os, const BankAccount &account)
  {
    os << "Account Holder: " << account.accountHolderName << "\n"
       << "Account Number: " << account.accountNumber << "\n"
       << "Balance: " << account.balance << "\n";
    return os;
  }
};

int main()
{

  BankAccount account("Papp Zsolt", 1, 1000.0);

  cout << account;

  double num = 0;
  cin >> num;

  // account.deposit(num);
  account.withdraw(num);

  cout << account;

  return 0;
}
