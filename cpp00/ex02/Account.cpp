
#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}

Account::Account( int initial_deposit )
{
    //Account();
    Account::_nbAccounts += 1;
    this->_accountIndex = getNbAccounts() - 1;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _totalAmount += this->_amount;
    _totalNbDeposits += this->_nbDeposits;
    _totalNbWithdrawals += this->_nbWithdrawals;
    _displayTimestamp();
    std::cout \
    << "index:" << this->_accountIndex \
    << ";amount:" << this->_amount \
    << ";created" \
    << std::endl;
}

Account::Account( void )
{
    return;
}

Account::~Account( void )
{
    _displayTimestamp();
    Account::_nbAccounts -= 1;
    std::cout \
    << "index:" << this->_accountIndex \
    << ";amount:" << this->_amount \
    << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
    time_t curr_time;
    tm * curr_tm;
    char date_string[9];
    char time_string[7];
    
    std::time(&curr_time);
    curr_tm = std::localtime(&curr_time);
    std::strftime(date_string, 9, "%EY%m0%u", curr_tm);
    std::strftime(time_string, 7, "%H%M%S", curr_tm);
    std::cout << "[" << date_string << "_" << time_string << "] ";
}

//accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout \
    << "accounts:" << getNbAccounts() \
    << ";total:" << getTotalAmount() \
    << ";deposits:" << getNbDeposits() \
    << ";withdrawals:" << getNbWithdrawals() \
    << std::endl;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout \
    << "index:" << this->_accountIndex \
    << ";amount:" << this->_amount \
    << ";deposits:" << this->_nbDeposits \
    << ";withdrawals:" << this->_nbWithdrawals \
    << std::endl;
}

//index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout \
    << "index:" << this->_accountIndex \
    << ";p_amount:" << this->_amount;

    this->_amount += deposit;
    this->_nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;

    std::cout \
    << ";deposit:" << deposit \
    << ";amount:" << checkAmount() \
    << ";nb_deposits:" << this->_nbDeposits \
    << std::endl;
}
// index:0;p_amount:47;withdrawal:refused
// index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    if (checkAmount() - withdrawal >= 0)
    {
        std::cout \
        << "index:" << this->_accountIndex \
        << ";p_amount:" << checkAmount() \
        << ";withdrawal:" << withdrawal;
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals += 1;
        std::cout \
        << ";amount:" << checkAmount() \
        << ";nb_withdrawals:" << this->_nbWithdrawals \
        << std::endl;
        return true;
    }
    else
    {
        std::cout \
        << "index:" << this->_accountIndex \
        << ";p_amount:" << this->_amount \
        << ";withdrawal:refused" \
        << std::endl;
        return false;
    }
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}