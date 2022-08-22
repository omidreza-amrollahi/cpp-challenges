#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance} {
}

// Withdraw:
//      Extra $1.50 will be deducted from balance per transaction
//
bool Checking_Account::withdraw(double amount) {
    amount += def_withdrawal_fee;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << "]";
    return os;
}

