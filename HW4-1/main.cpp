//
//  main.cpp
//  HW4-1
//
//  Created by Alyaev Roman on 28.02.2021.
//

#include <iostream>
#include <random>
#include <vector>


int main(int argc, const char * argv[])
{
    //создадим последовательность П1 из чисел от 1 до 10
    std::vector < int > P1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    //добавим несколько чисел в П1 через cin
    int a, b, c, d;
    std::cout << "Let's add some numbers into P1: ";
    std::cin >> a >> b >> c >> d;
    std::cout << std::endl;
    
    
    return 0;
}
