#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// constructor
Account::Account(int initial_deposit)
	: _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_displayTimestamp();
	std::cout << "index:" 	<< _nbAccounts;
	std::cout << ";amount:" << _amount;
	std::cout << ";created"	<< std::endl;

	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts++;
}

// destructor
Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:"	<< _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed"	<< std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
}

// getters
int Account::getNbAccounts(void)		{ return _nbAccounts; }
int Account::getTotalAmount(void)		{ return _totalAmount; }
int Account::getNbDeposits(void)		{ return _totalNbDeposits; }
int Account::getNbWithdrawals(void)		{ return _totalNbWithdrawals; }
int Account::checkAmount(void) const	{ return _amount; }

// public methods
void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" 		<< _nbAccounts;
	std::cout << ";total:" 			<< _totalAmount;
	std::cout << ";deposits:" 		<< _totalNbDeposits;
	std::cout << ";withdrawals:"	<< _totalNbWithdrawals	<< std::endl;
}

void Account::makeDeposit(int deposit) {
	int p_amount = _amount;
	_amount += deposit;
	_displayTimestamp();
	std::cout << "index:"			<< _accountIndex;
	std::cout << ";p_amount:"		<< p_amount;
	std::cout << ";deposit:"		<< deposit;
	std::cout << ";amount:"			<< _amount;
	std::cout << ";nb_deposits:"	<< ++_nbDeposits	<< std::endl;

	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:"			<< _accountIndex;
	std::cout << ";p_amount:"		<< _amount;
	if (withdrawal > _amount) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << ";withdrawal:"		<< withdrawal;
	std::cout << ";amount:"			<< (_amount -= withdrawal);
	std::cout << ";nb_withdrawals:"	<< ++_nbWithdrawals	<< std::endl;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return true;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:"			<< _accountIndex;
	std::cout << ";amount:"			<< _amount;
	std::cout << ";deposits:"		<< _nbDeposits;
	std::cout << ";withdrawals:"	<< _nbWithdrawals << std::endl;
}

// private methods
void Account::_displayTimestamp() {
	time_t		rawtime;
	time(&rawtime);
	struct tm *timeinfo = localtime(&rawtime);
	std::cout << "[" << timeinfo->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_sec << "] ";
}
