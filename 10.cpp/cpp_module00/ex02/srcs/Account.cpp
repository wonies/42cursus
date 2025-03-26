/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:00:29 by wonhshin          #+#    #+#             */
/*   Updated: 2023/11/17 16:24:47 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(0);
    std::tm *ptm = std::localtime(&now);

    char buffer[18];

    std::strftime(buffer, 18, "[%Y%m%d_%H%M%S]", ptm);
    std::cout << buffer;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "\taccounts:" << getNbAccounts() << \
	";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" \
	<< getNbWithdrawals() << std::endl;
	_nbAccounts = 0;
}

int Account::checkAmount(void) const
{
	if (_amount <= 0)
		return (0);
	return (1);
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "\tindex:" << _accountIndex << \
	";amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "\tindex:" << _accountIndex << \
	";amount:" <<  _amount << ";deposits:" <<  _nbDeposits << ";withdrawals:" << \
	_nbWithdrawals << std::endl;
	_nbAccounts++;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	_nbDeposits = 1;
	_amount += deposit;
	Account::_displayTimestamp();
	std::cout << "\tindex:" << _accountIndex << \
	";p_amount:" <<  _amount - deposit << ";deposit:" <<  deposit << ";amount:" << \
	_amount << ";nb_deposits:" << _nbDeposits << std::endl;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal( int withdrawal )
{
	_amount -= withdrawal;
	if (!checkAmount())
	{
		_amount += withdrawal;
		_displayTimestamp();
		std::cout << "\tindex:" << _accountIndex << \
		";p_amount:" <<  _amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		_nbWithdrawals = 1;
		_totalAmount -= withdrawal;
		_displayTimestamp();
		std::cout << "\tindex:" << _accountIndex << \
		";p_amount:" <<  _amount + withdrawal << ";withdrawal:" <<  withdrawal << ";amount:" << \
		_amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalNbWithdrawals++;
		return true;
	}
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "\tindex:" << _accountIndex << \
	";amount:" <<  _amount << ";closed" << std::endl;
}
