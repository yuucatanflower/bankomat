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

    int b{0},c{0};
    TMoney recive_money;

    std::cout << " Input bills: ";
    std::cin >> b;

    if (b * 100 > mon.totalAmount()){
        throw runtime_error("Too much");
    }

    for (const auto &bill : mon.get_bills())
    {
        if (bill.first == b && bill.second > 0) {
            std::cout << "The bill is present!!\n"; 
            std::cout << bill.first << "--" << bill.second << std::endl;
            recive_money.increment_bill(bill.first, 1);
            mon.decrement_bill(bill.first, 1);

           std::cout << "Updated ATM bills:\n";

            for (const auto &updated_bill : mon.get_bills()) {
                std::cout << "Denomination: " << updated_bill.first 
                          << ", Count: " << updated_bill.second << '\n';
            }

            break;
        }
        
       
    }

    // for (const auto &bill : mon.get_coins())
    // {
    //     if (bill.first == b && bill.second > 0) {
    //         std::cout << "The bill is present!!\n"; 
    //         std::cout << bill.first << "--" << bill.second << std::endl;
    //         recive_money.increment_bill(bill.first, 1);
    //         mon.decrement_bill(bill.first, 1);

    //        std::cout << "Updated ATM bills:\n";
           
    //         for (const auto &updated_bill : mon.get_bills()) {
    //             std::cout << "Denomination: " << updated_bill.first 
    //                       << ", Count: " << updated_bill.second << '\n';
    //         }

    //         break;
    //     }
        
       
    // }

    // std::cout << " Input coins: ";
    // std::cin >> c;

    std::cout << "Recive your cash \n" << recive_money 
    << std::endl;
}

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

// Output operator
ostream& operator<<(ostream& o ,const TBankomat& bankomat){ o<<"ID: " << bankomat.id<< endl ; 
o<<"Money Available: " << bankomat.mon << endl; 
// o<<"Min. withdrawal value: " << bankomat.min_withdraw << endl; 
// o<<"Max. withdrawal value: " << bankomat.max_withdraw << endl; 
// o<< "Money: " << bankomat.mon << endl; 
return o; }