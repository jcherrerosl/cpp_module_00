/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanherr <juanherr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:47:35 by juanherr          #+#    #+#             */
/*   Updated: 2025/05/09 01:20:45 by juanherr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

//las defino fuera de la clase porque son estaticas
// y no pertenecen a una instancia de la clase
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit),
		_nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount;
	if (_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal
					<< ";amount:" << _amount
					<< ";nb_withdrawals:" << _nbWithdrawals
					<< std::endl;
		return (true);
	}
}
int Account::checkAmount() const
{
	return (_amount);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}
int Account::getNbAccounts()
{
	return (_nbAccounts);
}
int Account::getTotalAmount()
{
	return (_totalAmount);
}
int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}
int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}
void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t now = std::time(NULL);
	std::tm* ltm = std::localtime(&now);

	std::cout << "["
	          << (ltm->tm_year + 1900)
	          << std::setw(2) << std::setfill('0') << (ltm->tm_mon + 1)
	          << std::setw(2) << std::setfill('0') << ltm->tm_mday
	          << "_"
	          << std::setw(2) << std::setfill('0') << ltm->tm_hour
	          << std::setw(2) << std::setfill('0') << ltm->tm_min
	          << std::setw(2) << std::setfill('0') << ltm->tm_sec
	          << "] ";
}
