#ifndef _Checking_ACCOUNT_H_
#define _Checking_ACCOUNT_H_
#include "Account.h"

// Checking Account is a type of Account
//   has a fee of $1.50 per withdrawal transaction
// Withdraw - withdraws an extra $1.50 per transaction
// Deposit - same as a regular account
//

class Checking_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_withdrawal_fee = 1.5;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);    
    bool withdraw(double amount);
    // Inherits the Account::deposit methods
};

#endif // _Checking_ACCOUNT_H_
