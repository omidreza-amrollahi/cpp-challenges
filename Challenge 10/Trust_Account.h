#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Account.h"

// Trust Account is a type of Account
//   adds an interest rate
// Withdraw:
//      should only allow 3 withdrawals per year (just make sure the 4th withdrawal fails)
//      each of these must be less than 20% of the account balance
// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
//      any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account
//

#include "Savings_Account.h"

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    int withdraw_counter;
public:
    Trust_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // _TRUST_ACCOUNT_H_
