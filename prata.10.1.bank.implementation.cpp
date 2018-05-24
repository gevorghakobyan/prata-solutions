#include "prata.10.1.bank.h"

int main(void)
{
	{
		BankAccount Ruzanna;
		Ruzanna.show();
		Ruzanna = BankAccount("Ruzanna Kusikyan", "2050 0761 9054 1020", 1097000.0);
		Ruzanna.show();
		Ruzanna.deposit(59000.0);
		Ruzanna.show();
		Ruzanna.withdrawal(304005.5);
		Ruzanna.show();
	};
	return 0;
};
