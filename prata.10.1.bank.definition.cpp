#include <iostream>
#include "prata.10.1.bank.h"

BankAccount::BankAccount()
{
	std::cout << "Default constructor called:" << std::endl;
	name = "No name";
	acc_num = "0000 0000 0000 0000";
	balance = 0.0;
};

BankAccount::BankAccount(std::string const & dep_name, std::string const & account_num, double bal)
{
	std::cout << "Using artificial constructor." << std::endl;
	name = dep_name;
	acc_num = account_num;
	if (bal < 0)
	{
		std::cout << "Balance can't be less than 0, so it's set to be 0 for now.";
		balance = 0.0;
	}
	else
		balance = bal;
};

BankAccount::~BankAccount()
{
	std::cout << "Destructor invoked.";
};

void BankAccount::show(void) const
{
	std::cout << "Customer name: " << name << std::endl << "Customer account number: " << acc_num << std::endl << "Current balance: " << balance << std::endl;
};

void BankAccount::deposit(double dep_sum)
{
	if (dep_sum < 0)
		std::cout << "No negative deposit sum. Invalid transaction.";
	else
		balance += dep_sum;
};

void BankAccount::withdrawal(double wit_sum)
{
	if (wit_sum > balance)
		std::cout << "Transaction called off because of insufficient balance.";
	else
		balance -= wit_sum;
};
