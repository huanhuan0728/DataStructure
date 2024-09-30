//
//  stock00.hpp
//  cpp_learn
//
//  Created by xuhuan lu on 2024/9/30.
//

#ifndef stock00_hpp
#define stock00_hpp

#include <stdio.h>
#include <string>
class Stock //class declaration
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot()
    {
        total_val = shares * share_val;
    }
public:
    void acquire(const std::string & co , long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};  //  note semicolon at the end

#endif /* stock00_hpp */
