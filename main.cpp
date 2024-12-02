#include "TMoney.h"
#include <iostream>
// #include "TBankomat.h"
#include <vector>

using namespace std;
int main()
{
    try
    {
        TMoney money({{15,1}},{{5,10}});
        money.printBillsAndCoins();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        TMoney money({{10, -1}}, {{5, 10}});
        money.printBillsAndCoins();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        TMoney money({{10, 1}}, {{3, 10}});
        money.printBillsAndCoins();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        TMoney money;
        money.printBillsAndCoins();
        std::cout << money<<"\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        TMoney money({},{});
        money.printBillsAndCoins();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    const vector<TMoney> mn{
        TMoney({}, {}),
        TMoney({{10, 1}}, {}),
        TMoney({}, {{5, 25}}),
        TMoney({{1, 10}, {2, 15}, {1000, 3}}, {{50, 100}, {10, 1000}})};


    // for (const auto& m: mn){
    //     m.printBalance();
    //     std::cout << std::endl;
    //     std::cout << m << "\n";
    // }

    TMoney money1({{500, 1}, {100, 1}}, {{50, 1}, {25, 1}});
    TMoney money2({{200, 1}, {100, 1}}, {{25, 1}, {10, 1}});

    // TMoney try1({{-20, 1}});
    //  TMoney balance1({1, 6, 1, 2, 1, 0, 3, 0, 0}, {4, 0, 1, 0, 0, 0});
    //  TMoney balance2({0, 0, 1, 2, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0});

    cout << money1 << endl
         << money2 << endl;

    TMoney sum = money1 + money2;
    cout << "Sum of money1 and money2: " << sum << endl;

    try
    {
        TMoney diffn = money2 - money1;
        cout << "Difference between money2 and money1: " << diffn << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    try{
        TMoney diff = money1 - money2;
        cout << "Difference between money1 and money2: " << diff << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }

    TMoney money3({{500, 1}, {100, 3}}, {{50, 1}, {25, 1}});
    // TODO fix constructor {100, 1}, {100, 2} -> {100, 3}

    // money3.printBillsAndCoins();
    TMoney money4({{500, 1}, {100, 1}}, {{25, 1}, {10, 1}});
    try{
        TMoney tmp = money3 - money4;


    }
    catch (const exception &e){
        cerr << e.what() << '\n';
    }

        TMoney product = money1 * 2;
    cout << "Money1 multiplied by 2: " << product << endl;
    // try{
    // TMoney product_negative = money1 * (-22);
    // cout << "Money1 multiplied by -22: " << product_negative << endl;
    // }
//    catch (const exception &e){
//         cerr << e.what() << '\n';
//     }

    TMoney quotient = money1 / 2;
    cout << "Money1 divided by 2: " << quotient << endl;

    cout << "Comparison results:" << endl;
    cout << "money1 == money2: " << (money1 == money2 ? "true" : "false") << endl;
    cout << "money1 != money2: " << (money1 != money2 ? "true" : "false") << endl;
    cout << "money1 < money2: " << (money1 < money2 ? "true" : "false") << endl;
    cout << "money1 <= money2: " << (money1 <= money2 ? "true" : "false") << endl;
    cout << "money1 > money2: " << (money1 > money2 ? "true" : "false") << endl;
    cout << "money1 >= money2: " << (money1 >= money2 ? "true" : "false") << endl;

    std::cout << "Babay!"<< std::endl;

    return 0;
}