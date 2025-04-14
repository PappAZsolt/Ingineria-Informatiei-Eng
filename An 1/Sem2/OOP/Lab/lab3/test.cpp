#include <iostream>
#include <string>

class BankAccount
{
private:
  std::string accountHolderName;
  int accountNumber;
  double balance;

public:
  // Parameterized Constructor
  BankAccount(std::string name, int accNumber, double initialBalance)
      : accountHolderName(name), accountNumber(accNumber), balance(initialBalance) {}

  // Method to deposit money
  void deposit(double amount)
  {
    if (amount > 0)
    {
      balance += amount;
      std::cout << "Deposit successful. New balance: " << balance << "\n";
    }
    else
    {
      std::cout << "Invalid deposit amount.\n";
    }
  }

  // Method to withdraw money
  void withdraw(double amount)
  {
    if (amount > balance)
    {
      std::cout << "Insufficient funds. Withdrawal denied.\n";
    }
    else if (amount <= 0)
    {
      std::cout << "Invalid withdrawal amount.\n";
    }
    else
    {
      balance -= amount;
      std::cout << "Withdrawal successful. New balance: " << balance << "\n";
    }
  }

  // Friend function declaration
  friend void display(const BankAccount &account);
};

// Friend function definition
void display(const BankAccount &account)
{
  std::cout << "Account Holder: " << account.accountHolderName << "\n"
            << "Account Number: " << account.accountNumber << "\n"
            << "Balance: " << account.balance << "\n";
}

int main()
{
  // Creating a bank account object
  BankAccount account("John Doe", 123456, 1000.0);

  // Displaying account details using friend function
  display(account);

  // Performing transactions
  account.deposit(500);
  account.withdraw(200);
  account.withdraw(1500); // This should show an insufficient funds message

  // Displaying updated account details
  display(account);

  return 0;
}
