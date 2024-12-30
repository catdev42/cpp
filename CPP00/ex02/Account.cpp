/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:32:42 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/30 16:41:36 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

//[19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts: " << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits()<< ";";
	std::cout << "withdrawals:" << getNbWithdrawals()<< std::endl;
	;
}

// [19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit) : _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = getNbAccounts();
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index: " << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "ccreated" << std::endl;
	return ;
}

//[19920104_091532] index:0;amount:47;closed
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index: " << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

/*[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1*/
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index: " << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	_nbDeposits += 1;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << std::endl;
}

/*
[19920104_091532] index:0;p_amount:47;withdrawal:refused
[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
*/
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index: " << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal < _amount)
	{
		this->_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
	}
}

int Account::checkAmount(void) const
{
	return (_amount);
}

/*[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0*/
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index: " << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t		now;
	struct tm	*timeinfo;
	char		buffer[20];

	now = time(NULL);
	timeinfo = localtime(&now);
	strftime(buffer, 20, "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << buffer << " ";
}
