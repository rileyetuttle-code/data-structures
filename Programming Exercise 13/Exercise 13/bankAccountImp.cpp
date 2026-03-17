
//Implementation file bankAccountImp.cpp
  
#include <iostream>
#include <iomanip>
#include "bankAccount.h"

using namespace std;

bankAccount::bankAccount(int acctNumber, double bal) 
{
  //assign member variables to the parameter
...........................................
}

void bankAccount::setAccountNumber(int acct) 
{
    accountNumber = acct;
}

int bankAccount::getAccountNumber() const
{
  //return account number
.........................
}

double bankAccount::getBalance() const
{
    return balance;
}

// withdraw member function definitions
..............................
{
	balance = balance - amount;
}

void bankAccount::deposit(double amount)
{
	// equations for depositing balance
}

void bankAccount::print() const
{
    cout << fixed << setprecision(2);
    cout << accountNumber << " balance : $"
         << balance << endl;
}
