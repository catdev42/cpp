/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:32:42 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/29 22:26:22 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_deposit) : _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = getNbAccounts();
	this->_nbAccounts += 1;
	return ;
}

//must print
void Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	_totalNbDeposits += 1;
	_nbDeposits += 1;
}

//must print
bool	makeWithdrawal(int withdrawal)
{
	this->_amount -= withdrawal;

}

/*GETTERS*/

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