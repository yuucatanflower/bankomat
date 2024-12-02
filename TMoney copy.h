// #ifndef TMONEY_H
// #define TMONEY_H

// #include <iostream>
// #include <vector>
// #include <map>
// #include <string>
// #include <stdexcept>

// #include "MoneyConstants.h"

// class TMoney {
// private:

//     std::map<int, int> bills; 
//     std::map<int, int> coins; 

//     // static const std::vector<int> billValues; 
//     // static const std::vector<double> coinValues; 

// public:
//     TMoney();
//     TMoney(const std::map<int, int> &initialBills, const std::map<int, int> &initialCoins);
//     void printBillsAndCoins() const;
//     // TMoney();
//     // TMoney(const std::vector<int>& b, const std::vector<int>& c);

//     // std::vector<int> exchange(int& sum);
//     // int totalAmount() const;
//     // int totalCoins() const;

//     // // Accessors for billValues and coinValues
//     // static const std::vector<int>& getBillValues() { return billValues; }
//     // static const std::vector<double>& getCoinValues() { return coinValues; }
    
//     // TMoney convertToTMoney(int amount);
//     // // Operator overloads
//     // TMoney operator+(const TMoney& other) const;
//     // TMoney operator-(const TMoney& other) const;
//     // TMoney operator/(int divisor) const;
//     // TMoney operator*(int multiplier) const;

//     // bool operator==(const TMoney& other) const;
//     // bool operator!=(const TMoney& other) const;
//     // bool operator<(const TMoney& other) const;
//     // bool operator<=(const TMoney& other) const;
//     // bool operator>(const TMoney& other) const;
//     // bool operator>=(const TMoney& other) const;

//     // friend std::ostream& operator<<(std::ostream& os, const TMoney& money);
// };

// #endif // TMONEY_H