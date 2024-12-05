#include "TMoney.h"
#include <iomanip>
#include <stdexcept>
#include <string>

#include "MoneyConstants.h"

TMoney::TMoney()
{
    for (const auto &bill : billValues)
    {
        bills[bill.first] = 0;
    }
    for (const auto &coin : coinValues)
    {
        coins[coin.first] = 0;
    }
}

TMoney::TMoney(const std::map<int, int> &initialBills = {}, const std::map<int, int> &initialCoins = {})
{

    for (const auto &bill : billValues)
    {
        bills[bill.first] = initialBills.count(bill.first) ? initialBills.at(bill.first) : 0;
    }

    for (const auto &bill : initialBills)
    {
        if (billValues.find(bill.first) == billValues.end())
        {
            throw std::runtime_error(" Not valid bill: " + std::to_string(bill.first) + " UAH");
        }

        if (bill.second < 0)
        {
            throw std::runtime_error(" Negative count "+ std::to_string(bill.second) +" of valid bill: " + std::to_string(bill.first) + " UAH");
        }
    }

    for (const auto &coin : coinValues)
    {
        coins[coin.first] = initialCoins.count(coin.first) ? initialCoins.at(coin.first) : 0;
    }

    for (const auto &coin : initialCoins)
    {
        if (coinValues.find(coin.first) == coinValues.end())
        {
            throw std::runtime_error(" Not valid coin: " + std::to_string(coin.first) + " p.");
        }

        if (coin.second < 0 ) {
            throw std::runtime_error(" Negative count of coin: " + std::to_string(coin.first) + " p.");
        }
    }
};

std::map<int, int> TMoney::get_bills() const{

    return bills;
};

void TMoney::printBillsAndCoins() const
{
    std::cout << "Current bills:\n";
    bool hasBills = false;
    for (const auto &bill : bills)
    {
        if (bill.second > 0)
        {
            std::cout << "  " << bill.second << " x " << bill.first << " UAH\n";
            hasBills = true;
        }
    }
    if (!hasBills)
    {
        std::cout << "  None\n";
    }

    std::cout << "Current coins:\n";
    bool hasCoins = false;
    for (const auto &coin : coins)
    {
        if (coin.second > 0)
        {
            std::cout << "  " << coin.second << " x " << coin.first << " kopiyok\n";
            hasCoins = true;
        }
    }
    if (!hasCoins)
    {
        std::cout << "  None\n";
    }
}

void TMoney::increment_bill(int nominal, int count){

    if (count < 0)
    {
        throw std::invalid_argument("Кількість має бути не від'ємною");
    }

    bills[nominal] += count;
};

TMoney TMoney::convertToTMoney(int amount)
{

    std::map<int, int> billsCount;
    std::map<int, int> coinsCount;

    int remainingCents = amount * 100;

    for (auto it = billValues.rbegin(); it != billValues.rend(); ++it)
    {

        int billValueInCents = it->first * 100;

        billsCount[it->first] = remainingCents / billValueInCents;

        remainingCents %= billValueInCents;
    }

    for (auto it = coinValues.rbegin(); it != coinValues.rend(); ++it)
    {

        coinsCount[it->first] = remainingCents / it->first;

        remainingCents %= it->first;
    }

    return TMoney(billsCount, coinsCount);
}

int TMoney::totalAmount() const
{
    int totalCents = 0;

    for (const auto &bill : bills)
    {
        totalCents += bill.first * 100 * bill.second;
    }

    // Sum the value of each coin in cents
    for (const auto &coin : coins)
    {
        totalCents += coin.first * coin.second;
    }

    return totalCents;
}

TMoney TMoney::operator+(const TMoney &other) const
{

    std::map<int, int> newBills = bills;
    std::map<int, int> newCoins = coins;

    for (const auto &bill : other.bills)
    {

        newBills[bill.first] += bill.second;
    }

    for (const auto &coin : other.coins)
    {
        newCoins[coin.first] += coin.second;
    }

    return TMoney(newBills, newCoins);
}

TMoney TMoney::operator-(const TMoney &other) const
{
    // TMoney money1({{500, 1}, {100, 1}}, {{50, 1}, {25, 1}});
    // TMoney money2({{200, 1}, {100, 1}}, {{25, 1}, {10, 1}});

    std::map<int, int> newBills = bills;
    std::map<int, int> newCoins = coins;
    for (const auto &bill: other.bills){
        newBills[bill.first] -= bill.second;
    }

    for (const auto &coin : other.coins)
    {
        newCoins[coin.first] -= coin.second;
    }

    for (const auto &bill : newBills){
        if (bill.second < 0 ){
            throw std::runtime_error("Error: Negative value for a bill denomination!!.");
        }
    }

    for (const auto &coin : newCoins)
    {
        if (coin.second < 0)
        {
            throw std::runtime_error("Error: Negative value for a coin denomination!!.");
        }
    }

        return TMoney(newBills, newCoins);
}

TMoney TMoney::operator/(int divisor) const
{
    if (divisor == 0)
    {
        throw std::runtime_error("Error: Division by zero is not allowed.");
    }

    std::map<int, int> newBills;
    std::map<int, int> newCoins;

    
    for (const auto &bill : bills)
    {
        if (bill.second % divisor != 0)
        {
            throw std::runtime_error("Error: Bills cannot be evenly divided.");
        }
        newBills[bill.first] = bill.second / divisor;
    }

    
    for (const auto &coin : coins)
    {
        if (coin.second % divisor != 0)
        {
            throw std::runtime_error("Error: Coins cannot be evenly divided.");
        }
        newCoins[coin.first] = coin.second / divisor;
    }

    return TMoney(newBills, newCoins);
}

TMoney TMoney::operator*(int multiplier) const
{

    std::map<int, int> newBills;
    std::map<int, int> newCoins;

    if (multiplier < 0)
    {
        throw std::runtime_error("Error: Negative multiplier is not allowed.");
    }

    for (const auto &bill : bills)
    {
        newBills[bill.first] = bill.second * multiplier;
    }

    for (const auto &coin : coins)
    {
        newCoins[coin.first] = coin.second * multiplier;
    }

    return TMoney(newBills, newCoins);
}

bool TMoney::operator==(const TMoney &other) const
{
    // TODO скористатися циклом для порівняння купюр та монет (this map<int, int> bills == other map<int, int> bills)
    // а чого цикл? працює вот таке
    if(bills != other.bills){return false;}
    if(coins != other.coins){return false;}
    return true;
    
}

bool TMoney::operator!=(const TMoney &other) const
{
    if(bills == other.bills){return false;}
    if(coins == other.coins){return false;}
    return true;
}

bool TMoney::operator<(const TMoney &other) const
{
    return totalAmount() < other.totalAmount();
}

bool TMoney::operator<=(const TMoney &other) const
{
    return totalAmount() <= other.totalAmount();
}

bool TMoney::operator>(const TMoney &other) const
{
    return totalAmount() > other.totalAmount();
}

bool TMoney::operator>=(const TMoney &other) const
{
    return totalAmount() >= other.totalAmount();
}

std::ostream &operator<<(std::ostream &o, const TMoney &money)
{
    
    int totalCents = money.totalAmount();
    int wholeUAH = totalCents / 100;
    int cents = totalCents % 100;

    o << "Total amount: " << wholeUAH << ","
      << std::setw(2) << std::setfill('0') << cents << " UAH\n";

    // bills breakdown
    o << "  Bills:\n";
    for (const auto &bill : money.bills)
    {
        if (bill.second > 0) 
        {
            o << "  " << bill.second << " x " << bill.first << " UAH\n";
        }
    }

    // Display coins breakdown
    o << "  Coins:\n";
    for (const auto &coin : money.coins)
    {
        if (coin.second > 0) 
        {
            o << "  " << coin.second << " x " << coin.first << " p.\n";
        }
    }

    return o;
}