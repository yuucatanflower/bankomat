#ifndef TMONEY_H
#define TMONEY_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>

#include "MoneyConstants.h"

class TMoney
{
private:
    std::map<int, int> bills;
    std::map<int, int> coins;

public:
    TMoney();
    TMoney(const std::map<int, int> &initialBills, const std::map<int, int> &initialCoins);
    void printBillsAndCoins() const; //якщо не використовуєш, то -- видали
    //?? printBills
    //?? printCoins

    // інкремент курюр, монет
    void increment_bill(int nominal, int count);
    void decrement_bill(int nominal, int count);

    
    int totalAmount() const;

    std::map<int, int> get_bills() const;

        TMoney convertToTMoney(int amount);
    // Operator overloads
    TMoney operator+(const TMoney &other) const;
    TMoney operator-(const TMoney &other) const;
    TMoney operator/(int divisor) const;
    TMoney operator*(int multiplier) const;

    bool operator==(const TMoney &other) const;
    bool operator!=(const TMoney &other) const;
    bool operator<(const TMoney &other) const;
    bool operator<=(const TMoney &other) const;
    bool operator>(const TMoney &other) const;
    bool operator>=(const TMoney &other) const;

    friend std::ostream &operator<<(std::ostream &os, const TMoney &money);
};

#endif // TMONEY_H