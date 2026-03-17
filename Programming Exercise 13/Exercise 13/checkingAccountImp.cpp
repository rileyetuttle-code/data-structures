
//Implementation file checkingAccountImp.cpp
  
#include <iostream>
#include <iomanip>
#include "checkingAccount.h"

using namespace std;

checkingAccount::checkingAccount(int acctNumber, double bal, 
                                 double minBal, double intRate, double servC)
               : bankaccount(acctnumber, bal)
               
{
    interestRate = intRate;
    minimumBalance = minBal;
    serviceCharge = servC;
}

double checkingAccount::getMinimumBalance() const 
{
    return minimumBalance;
}

void checkingAccount::setMinimumBalance(double minBalance)
{
    minimumBalance = minBal;
.........
}

double checkingAccount::getInterestRate() const
{
    return interestRate;
}

void checkingAccount::setInterestRate(double intRate)
{
    interestRate = intRate;
}

void checkingAccount::getServiceCharge() const
.................................................
{
    return serviceCharge;
}

void checkingAccount::setServiceCharge(double servC)
{
    serviceCharge = servC;
}

void checkingAccount::postInterest() const
.........................................
{
    balance = balance + balance * interestRate;
}

bool checkingAccount::verifyMinimumumBalance(double amount)
{
    return (balance - amount >= minimumBalance);
}

 void checkingAccount::writeCheck(double amount)
{
    withdraw(amount);
}

void checkingAccount::withdraw(double amount)
{
// verify if the balance less than minimum balance
    if (balance - amount - service charge < 0)
    {
        cout << "Error. Balance is below minimum balance.";
    }
    else
    {
        balance = balance - amount - service charge
    }
................................................
}

void checkingAccount::print() const
{
    cout << fixed << setprecision(2);
    cout << "Interest Checking ACCT#:\t" << getAccountNumber()
         << "\tBalance: $" << getBalance() << endl;
}