#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate}, withdraw_counter {0} {
}

// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
//      any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account
//
bool Trust_Account::deposit(double amount) {
    if (amount >= 5000) {
        amount += 50;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if (amount > (balance * 0.2)) {
        return false;
    }
    if (withdraw_counter >= 3) {
        return false;
    }
    ++withdraw_counter;
    return Savings_Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate 
        << "%, withdrawals: " << account.withdraw_counter <<  "]";
    return os;
}

