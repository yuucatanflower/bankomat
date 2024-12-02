// #ifndef TBANKOMAT_H
// #define TBANKOMAT_H

// #include <iostream>
// #include <vector>
// #include "TMoney.h"
// #include <string>

// using namespace std;

// class TBankomat : public TMoney { // Corrected inheritance
// private:
//     string id;
//??     int current_sum; // виведення балансу на 'табло' 
//     int min_withdraw;
//     int max_withdraw;
//     TMoney mon; // Money in the bankomat

// public:
//     // Constructors
//     TBankomat();
//     TBankomat(string id);
//??     TBankomat(string id, int current_sum);
//??     TBankomat(string id, int current_sum, int min_withdraw);
//??     TBankomat(string id, int current_sum, int min_withdraw, int max_withdraw);

//     // Set current sum
//     void set_current(int sum);

//     void withdraw(TMoney& balance, TMoney& withdraw_amount);
//     void withdraw(TMoney& balance, int withdr_am);
//     // Convert current_sum to TMoney
//     TMoney currentSumToTMoney() const;

//     // Convert TMoney to current_sum
//     void TMoneyToCurrentSum(const TMoney& money); // "ТАБЛО"

//     // Friend function for output
//     friend ostream& operator<<(ostream& o, const TBankomat& bankomat);
// };

// #endif // TBANKOMAT_H