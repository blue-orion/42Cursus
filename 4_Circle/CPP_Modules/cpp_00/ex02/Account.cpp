/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:26:29 by takwak            #+#    #+#             */
/*   Updated: 2025/04/17 22:52:07 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	index = 0;
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_displayTimestamp();
	this->_nbAccounts++;
	this->_accountIndex = index++;
	this->_amount = initial_deposit;
	this->_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:"<< this->_amount << ";"
		<< "created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:"<< this->_amount << ";"
		<< "closed" << std::endl;
}

int	Account::getNbAccounts(void) {
	return _nbAccounts;
}

int	Account::getTotalAmount(void) {
	return _totalAmount;
}

int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

int	 Account::checkAmount(void) const {
	return _amount;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:"<< this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	int	p_amount = this->_amount;

	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:"<< p_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int	p_amount = this->_amount;

	if (this->_amount < withdrawal) {
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:"<< p_amount << ";"
			<< "withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:"<< p_amount << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

#include <ctime>

void	Account::_displayTimestamp(void) {
	time_t	timestamp;
	struct tm	*timeinfo;
	char	buffer[20];

	time(&timestamp);
	timeinfo = localtime(&timestamp);
	std::strftime(buffer, 20, "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << buffer << "] ";
}
