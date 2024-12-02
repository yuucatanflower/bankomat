// #include <iostream>
// #include <vector>
// #include "TMoney.h"
// #include "TBankomat.h"
// #include <string>
// #include <stdexcept>
// #include <algorithm>

// using namespace std;

// // Default constructor
// TBankomat::TBankomat() : id("00000"), current_sum(0), min_withdraw(0), max_withdraw(0) {}

// // Constructor with ID
// TBankomat::TBankomat(string id) : id(id), current_sum(0), min_withdraw(0), max_withdraw(0) {
//     if (id.size() != 5) {
//         throw runtime_error("Wrong ID");
//     }
// }

// // Constructor with ID and current sum
// TBankomat::TBankomat(string id, int current_sum) : id(id), current_sum(current_sum), min_withdraw(0), max_withdraw(current_sum) {
//     if (id.size() != 5) {
//         throw runtime_error("Wrong ID");
//     }
//     if (current_sum < 0) {
//         throw runtime_error("Negative value");
//     }
// }

// // Constructor with ID, current sum, and min/max withdraw values
// TBankomat::TBankomat(string id, int current_sum, int min_withdraw) : id(id), current_sum(current_sum), min_withdraw(min_withdraw), max_withdraw(current_sum) {
//     if (id.size() != 5) {
//         throw runtime_error("Wrong ID");
//     }
//     if (current_sum < 0) {
//         throw runtime_error("Negative value");
//     }
// }

// TBankomat::TBankomat(string id, int current_sum, int min_withdraw, int max_withdraw) : id(id), current_sum(current_sum), min_withdraw(min_withdraw), max_withdraw(max_withdraw) {
//     if (id.size() != 5) {
//         throw runtime_error("Wrong ID");
//     }
//     if (current_sum < 0) {
//         throw runtime_error("Negative value");
//     }
// }

// // Set current sum
// void TBankomat::set_current(int sum) {
//     current_sum = sum;
// }




// //withdraw tmoney tmoney
// void TBankomat::withdraw(TMoney& balance, TMoney& withdraw_amount){
//     if(withdraw_amount.totalAmount() > current_sum){throw runtime_error("Withdrawal amount exceeds available funds");}
//     if (withdraw_amount.totalAmount() > balance.totalAmount()) {throw runtime_error("Withdrawal amount exceeds balance");}
//     if (withdraw_amount.totalAmount() < TMoney().totalAmount() ) {throw runtime_error("Withdrawal amount is negative");}
//     if (withdraw_amount.totalAmount() > max_withdraw) {throw runtime_error("Withdrawal amount exceeds maximum withdrawal");}
//     if (withdraw_amount.totalAmount() < min_withdraw) {throw runtime_error("Withdrawal amount is less than minimum withdrawal");} 
//     balance = balance - withdraw_amount;
//     current_sum = current_sum - withdraw_amount.totalAmount();
// }
// //witdraw tmoney int
// void TBankomat::withdraw(TMoney& balance, int withdr_am) {
    
//     TMoney withdraw_amount_tmoney = convertToTMoney(withdr_am);

//     withdraw(balance, withdraw_amount_tmoney);
// }

// // Output operator
// ostream& operator<<(ostream& o ,const TBankomat& bankomat){ o<<"ID: " << bankomat.id<< endl ; 
// o<<"Money Available: " << bankomat.current_sum << endl; 
// o<<"Min. withdrawal value: " << bankomat.min_withdraw << endl; 
// o<<"Max. withdrawal value: " << bankomat.max_withdraw << endl; 
// // o<< "Money: " << bankomat.mon << endl; 
// return o; }