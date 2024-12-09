#ifndef MONEY_CONSTANTS_H
#define MONEY_CONSTANTS_H
#include <map>
#include <string>

const std::map<int, std::string> billValues = {
    {1000, "1000 UAH"},
    {500, "500 UAH"},
    {200, "200 UAH"},
    {100, "100 UAH"},
    {50, "50 UAH"},
    {20, "20 UAH"},
    {10, "10 UAH"},
    {5, "5 UAH"},
    {2, "2 UAH"},
    {1, "1 UAH"}
};

const std::map<int, std::string> coinValues = {
    {1, "1 c."},
    {2, "2 c."},
    {5, "5 c."},
    {10, "10 c."},
    {25, "25 c."},
    {50, "50 c."},
};

#endif