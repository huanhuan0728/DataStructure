//
//  stock00.cpp
//  cpp_learn
//
//  Created by xuhuan lu on 2024/9/30.
//

#include "stock00.hpp"
#include <iostream>

void Stock::acquire(const std::string & co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "Number of share can't be negative; "
        << company << "share set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
    
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be nagetive. "
        << "Transaction is aboard.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}
