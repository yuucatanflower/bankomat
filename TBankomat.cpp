#include <iostream>
#include <vector>
#include "TMoney.h"
#include "TBankomat.h"
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

// Default constructor
TBankomat::TBankomat() : id("00000"), mon({}), min_withdraw(0), max_withdraw(0) {}

// Constructor with ID
TBankomat::TBankomat(string id) : id(id), mon({}), min_withdraw(0), max_withdraw(0) {
    if (id.size() != 5) {
        throw runtime_error("Wrong ID");
    }
}

// Constructor with ID and current sum
TBankomat::TBankomat(string id, TMoney mon) : id(id), mon(mon), min_withdraw(0), max_withdraw(mon.totalAmount()) {
    if (id.size() != 5) {
        throw runtime_error("Wrong ID");
    }
    if (mon.totalAmount() < 0) {
        throw runtime_error("Negative value");
    }
}

// // Constructor with ID, current sum, and min/max withdraw values
TBankomat::TBankomat(string id, TMoney mon, int min_withdraw) : id(id), mon(mon), min_withdraw(min_withdraw), max_withdraw(mon.totalAmount()) {
    if (id.size() != 5) {
        throw runtime_error("Wrong ID");
    }
    if (mon.totalAmount() < 0) {
        throw runtime_error("Negative value");
    }
}

TBankomat::TBankomat(string id, TMoney mon, int min_withdraw, int max_withdraw) : id(id), mon(mon), min_withdraw(min_withdraw), max_withdraw(max_withdraw) {
    if (id.size() != 5) {
        throw runtime_error("Wrong ID");
    }
    if (mon.totalAmount() < 0) {
        throw runtime_error("Negative value");
    }
}

// Set current sum
void TBankomat::set_current(TMoney setmon) {
    mon = setmon;
}

void TBankomat::get_cash(){
    float des_am{0};
    int b{0},c{0};
    TMoney recive_money;

    std::cout << " Input desired amount (xxx.yy) :  ";
    std::cin >> des_am;

    b = des_am * 100;

     if (des_am <= 0) {
        throw runtime_error("Enter a positive amount");
    }

    if (b > mon.totalAmount()){
        throw runtime_error("Insufficient funds in the ATM");
    }

    while (recive_money.totalAmount() < b)
    {
        for (auto it = billValues.rbegin(); it != billValues.rend(); ++it)
        {
            for (const auto bill: mon.get_bills()){
                int bill_count{0};
                
                while (it->first == bill.first && bill.second - bill_count > 0 && bill.first*100 <= b)
                {
                    recive_money.increment_bill(bill.first, 1);
                    mon.decrement_bill(bill.first, 1);
                    bill_count += 1;
                    b -= bill.first*100;

                }
            }

        if (b != 0) {
    for (const auto& [value, count] : recive_money.get_bills()) {
        mon.increment_bill(value, count);
    }
    for (const auto& [value, count] : recive_money.get_coins()) {
        mon.increment_coin(value, count);
    }
    throw std::runtime_error("Cannot dispense the exact amount"); 
}

std::cout<<"Recive your cash \n" << recive_money << endl;
    }
        


        }
  
        std::cout << "Rest after bills: " << b << std::endl;

        for (auto it = coinValues.rbegin(); it != coinValues.rend(); ++it)
        {

            for (const auto coin : mon.get_coins())
            {
                int coin_count{0};

                while (it->first == coin.first && coin.second - coin_count > 0 && coin.first <= b)
                {
                    recive_money.increment_coin(coin.first, 1);
                    mon.decrement_coin(coin.first, 1);
                    coin_count += 1;
                    b -= coin.first;
                }
            }
        }

        std::cout << "Rest after coins: " << b << std::endl;
    }
    

    // TODO if b != 0 do exception!!

   


    // withdraw tmoney tmoney
    void TBankomat::withdraw(TMoney &balance, TMoney &withdraw_amount)
{
    if(withdraw_amount.totalAmount() > mon.totalAmount()){throw runtime_error("Withdrawal amount exceeds available funds");}
    if (withdraw_amount.totalAmount() > balance.totalAmount()) {throw runtime_error("Withdrawal amount exceeds balance");}
    if (withdraw_amount.totalAmount() < TMoney().totalAmount() ) {throw runtime_error("Withdrawal amount is negative");}
    if (withdraw_amount.totalAmount() > max_withdraw) {throw runtime_error("Withdrawal amount exceeds maximum withdrawal");}
    if (withdraw_amount.totalAmount() < min_withdraw) {throw runtime_error("Withdrawal amount is less than minimum withdrawal");} 
    balance = balance - withdraw_amount;
    mon = mon - withdraw_amount;
}
//witdraw tmoney int
void TBankomat::withdraw(TMoney& balance, int withdr_am) {
    
    TMoney withdraw_amount_tmoney = convertToTMoney(withdr_am);

    withdraw(balance, withdraw_amount_tmoney);
}

void TBankomat::load_cash(TMoney& load){
 cout<< "Loading cash: " << load.totalAmount()/100<<"."<<load.totalAmount()%100<<endl;
    if(load.totalAmount()<=0){
        throw runtime_error("Enter a positive amount");
    }

    mon = mon + load;
    
    cout<<"Money Available: " << mon << endl; 
};

// Output operator
ostream& operator<<(ostream& o ,const TBankomat& bankomat){ o<<"ID: " << bankomat.id<< endl ; 
o<<"Money Available: " << bankomat.mon << endl; 
// o<<"Min. withdrawal value: " << bankomat.min_withdraw << endl; 
// o<<"Max. withdrawal value: " << bankomat.max_withdraw << endl; 
// o<< "Money: " << bankomat.mon << endl; 
return o; }