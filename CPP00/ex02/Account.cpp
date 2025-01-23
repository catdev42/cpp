/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:32:42 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/18 18:18:44 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

const std::string BLUE = "\033[34m";
const std::string RESET = "\033[0m";

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

// Define static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//[19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts: " << BLUE << getNbAccounts() << RESET << ";";
	std::cout << "total:" << BLUE << getTotalAmount() << RESET << ";";
	std::cout << "deposits:" << BLUE << getNbDeposits() << RESET << ";";
	std::cout << "withdrawals:" << BLUE << getNbWithdrawals() << RESET << std::endl;
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
	std::cout << "index: " << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "amount:" << BLUE << this->_amount << RESET << ";";
	std::cout << "created" << std::endl;
	return ;
}

//[19920104_091532] index:0;amount:47;closed
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index: " << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "amount:" << BLUE << this->_amount << RESET << ";";
	std::cout << "closed" << std::endl;
}

/*[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1*/
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index: " << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "p_amount:" << BLUE << this->_amount << RESET << ";";
	this->_amount += deposit;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	_nbDeposits += 1;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << BLUE << this->_amount << RESET << ";";
	std::cout << "deposits:" << BLUE << this->_nbDeposits << RESET << std::endl;
}

/*
[19920104_091532] index:0;p_amount:47;withdrawal:refused
[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
*/
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index: " << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "p_amount:" << BLUE << this->_amount << RESET << ";";
	if (withdrawal < _amount)
	{
		this->_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		std::cout << "withdrawal:" << BLUE << withdrawal << RESET << ";";
		std::cout << "amount:" << BLUE << this->_amount << RESET << ";";
		std::cout << "withdrawals:" << BLUE << this->_nbWithdrawals << RESET << std::endl;
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	return (true);
}

int Account::checkAmount(void) const
{
	return (_amount);
}

/*[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0*/
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index: " << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "amount:" << BLUE << this->_amount << RESET << ";";
	std::cout << "deposits:" << BLUE << this->_nbDeposits << RESET << ";";
	std::cout << "withdrawals:" << BLUE << this->_nbWithdrawals << RESET << std::endl;
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
