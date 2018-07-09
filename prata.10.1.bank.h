#include <string>

#ifndef BANK_H_
#define BANK_H_

class BankAccount
{
	private:
		std::string name;
		std::string acc_num;
		double balance;
	public:
		BankAccount();
		BankAccount(std::string const & dep_name, std::string const & account_num, double bal = 0.0);
		~BankAccount();
		void show(void) const;
		void deposit(double dep_sum);
		void withdrawal(double wit_sum);
};

#endif
