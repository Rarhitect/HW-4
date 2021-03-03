//
//  main.cpp
//  HW4-1
//
//  Created by Alyaev Roman on 28.02.2021.
//

#include <iostream>
#include <random>
#include <vector>

void print_vector(std::vector <int> vector)
{
    for (auto &i: vector)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main(int argc, const char * argv[])
{
    //создадим последовательность П1 из чисел от 1 до 10
    std::cout << "Creating P1" << std::endl;
    std::vector < int > P1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_vector(P1);
    
    //добавим несколько чисел в П1 через cin
    std::cout << "Add some elements into P1:" << std::endl;
    std::copy(
        std::istream_iterator < int > (std::cin),
        std::istream_iterator < int > (),
        std::back_inserter(P1));
    
    //перемешаем числа в П1 случайным образом
    std::cout << "Mixing P1: ";
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(std::begin(P1), std::end(P1), g);
    print_vector(P1);
    
    //удалим дубликаты П1
    
    return 0;
}
