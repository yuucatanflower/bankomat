// #include "TMoney.h"
// #include <iomanip>
// #include <stdexcept>
// #include <string>

// #include "MoneyConstants.h"

// TMoney::TMoney()
// {
//     for (const auto &bill : billValues)
//     {
//         bills[bill.first] = 0;
//     }
//     for (const auto &coin : coinValues)
//     {
//         coins[coin.first] = 0;
//     }
// }

// TMoney::TMoney(const std::map<int, int> &initialBills = {}, const std::map<int, int> &initialCoins = {}){

//     for (const auto& bill: billValues){
//         bills[bill.first] = initialBills.count(bill.first) ? initialBills.at(bill.first) : 0;
//     }

//     for (const auto &bill : initialBills)
//     {
//         if (billValues.find(bill.first) == billValues.end()){
//             throw std::runtime_error(" Not valid bill: " + std::to_string(bill.first) + " UAH");
//         }
//     }

//     for (const auto &coin : coinValues)
//     {
//         coins[coin.first] = initialCoins.count(coin.first) ? initialCoins.at(coin.first) : 0;
//     }

//     for (const auto &coin : initialCoins)
//     {
//         if (billValues.find(coin.first) == coinValues.end())
//         {
//             throw std::runtime_error(" Not valid coin: " + std::to_string(coin.first) + " UAH");
//         }
//     }
// };

// void TMoney::printBillsAndCoins() const{
//     std::cout << "Current bills:\n";
//     for (const auto &bill : bills)
//     {
//         std::cout << "  Bill " << bill.first << " UAH: " << bill.second << " p.\n";
//     }
//     std::cout << "Current coins:\n";
//     for (const auto &coin : coins)
//     {
//         std::cout << "  Coin " << coin.first << " UAH: " << coin.second << " p.\n";
//     }
// };

// // const std::vector<int> TMoney::billValues = {1, 2, 5, 10, 20, 50, 100, 200, 500};
// // const std::vector<double> TMoney::coinValues = {0.01, 0.02, 0.05, 0.1, 0.25, 0.5};

// // TMoney::TMoney() : bills(billValues.size(), 0), coins(coinValues.size(), 0) {}

// // TMoney::TMoney(const std::vector<int>& b, const std::vector<int>& c) : bills(b), coins(c) {}

// // TMoney TMoney::convertToTMoney(int amount){
    
// //     std::vector<int> billsCount(billValues.size(), 0);
    
    
// //     for (size_t i = billValues.size(); i > 0; --i) {
// //         int billValue = billValues[i - 1];
// //         while (amount >= billValue) {
// //             billsCount[i - 1]++;
// //             amount -= billValue;
// //         }
// //     }

// //     return TMoney(billsCount, std::vector<int>(coins.size(), 0));
// // }


// // int TMoney::totalAmount() const {
// //     int sumCents = 0;

// //     // Sum the value of each bill in cents
// //     for (size_t i = 0; i < bills.size(); ++i) {
// //         sumCents += bills[i] * billValues[i] * 100;
// //     }

// //     // Sum the value of each coin in cents
// //     for (size_t i = 0; i < coins.size(); ++i) {
// //         sumCents += static_cast<int>(coins[i] * coinValues[i] * 100);
// //     }

// //     return sumCents;
// // }

// // TMoney TMoney::operator+(const TMoney& other) const {
// //     std::vector<int> newBills(bills.size());
// //     std::vector<int> newCoins(coins.size());

// //     for (size_t i = 0; i < bills.size(); ++i) {
// //         newBills[i] = bills[i] + other.bills[i];
// //     }
// //     for (size_t i = 0; i < coins.size(); ++i) {
// //         newCoins[i] = coins[i] + other.coins[i];
// //     }

// //     return TMoney(newBills, newCoins);
// // }

// // TMoney TMoney::operator-(const TMoney& other) const {
// //     std::vector<int> newBills(bills.size());
// //     std::vector<int> newCoins(coins.size());

   

// //     if((totalAmount()-other.totalAmount())<0){throw std::runtime_error("Error: negative sum");}
// //     for (size_t i = 0; i < bills.size(); ++i) {newBills[i] = bills[i] - other.bills[i];}
// //     for (size_t i = 0; i < coins.size(); ++i) {newCoins[i] = coins[i] - other.coins[i];}
        
  
// //     return TMoney(newBills, newCoins);
// // }

// // TMoney TMoney::operator/(int divisor) const {
// //     if (divisor == 0) {
// //         throw std::runtime_error("Error: Division by zero is not allowed.");
// //     }

// //     std::vector<int> newBills(bills.size());
// //     std::vector<int> newCoins(coins.size());

// //     for (size_t i = 0; i < bills.size(); ++i) {
// //         newBills[i] = bills[i] / divisor;
// //     }
// //     for (size_t i = 0; i < coins.size(); ++i) {
// //         newCoins[i] = coins[i] / divisor;
// //     }

// //     return TMoney(newBills, newCoins);
// // }

// // TMoney TMoney::operator*(int multiplier) const {
// //     std::vector<int> newBills(bills.size());
// //     std::vector<int> newCoins(coins.size());

// //     for (size_t i = 0; i < bills.size(); ++i) {
// //         newBills[i] = bills[i] * multiplier;
// //     }
// //     for (size_t i = 0; i < coins.size(); ++i) {
// //         newCoins[i] = coins[i] * multiplier;
// //     }

// //     return TMoney(newBills, newCoins);
// // }

// // bool TMoney::operator==(const TMoney& other) const {
// //     return totalAmount() == other.totalAmount();
// // }

// // bool TMoney::operator!=(const TMoney& other) const {
// //     return !(*this == other);
// // }

// // bool TMoney::operator<(const TMoney& other) const {
// //     return totalAmount() < other.totalAmount();
// // }

// // bool TMoney::operator<=(const TMoney& other) const {
// //     return totalAmount() <= other.totalAmount();
// // }

// // bool TMoney::operator>(const TMoney& other) const {
// //     return totalAmount() > other.totalAmount();
// // }

// // bool TMoney::operator>=(const TMoney& other) const {
// //     return totalAmount() >= other.totalAmount();
// // }



// // std::ostream& operator<<(std::ostream& os, const TMoney& money) {
// //     int totalCents = money.totalAmount();
// //     int wholeUAH = totalCents / 100;
// //     int cents = totalCents % 100;

// //     os << "Total amount: " << wholeUAH << "," 
// //        << std::setw(2) << std::setfill('0') << cents << " UAH";
// //     return os;
// // }
