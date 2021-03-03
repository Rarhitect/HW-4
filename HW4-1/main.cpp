//
//  main.cpp
//  HW4-1
//
//  Created by Alyaev Roman on 28.02.2021.
//

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <cmath>

void print_vector(std::vector <int> vector)
{
    for (auto &i: vector)
        std::cout << i << " ";
    std::cout << std::endl;
}

bool predicate (int a)
{
    if (a / 2 == 0)
        return 1;
    else
        return 0;
}

bool is_prime(int x)
{
    std::vector < int > v;
    if (x == 1)
    {
        return false;
    }
    for (auto i = 2; i < x; ++i)
    {
        v.push_back(x % i);
    }
    auto count_of_zeroes = std::count_if(std::begin(v), std::end(v), [](auto x){return x == 0;});
    
    return (count_of_zeroes == 0);
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
    std::sort(std::begin(P1), std::end(P1));
    P1.erase(std::unique(std::begin(P1), std::end(P1)), std::end(P1));
    std::cout << "Deleting dublicates from P1:" << std::endl;
    print_vector(P1);
    
    //подсчитаем количество четных чисел в П1
    auto even = std::count_if(std::begin(P1), std::end(P1), [](auto x){return x % 2 == 0;});
    std::cout << even << " evens" << std::endl;
    
    //определим максимальное и минимальное в П1
    auto [min, max] = std::minmax_element(std::begin(P1), std::end(P1));
    std::cout << "Min num = " << *min << "; Max num = " << *max << std::endl;
    
    //попробуем найти хотя бы одно простое число в П1
    auto prime_num = std::find_if(std::begin(P1), std::end(P1), [](auto x){return is_prime(x);});
    if (prime_num == std::end(P1))
        std::cout << "No prime numbers" << std::endl;
    else
        std::cout << "There is at least one prime num: " << *prime_num << std::endl;
    
    //заменим все числа в П1 их квадратами
    std::cout << "Let's displace numbers of P1 with their squares:" << std::endl;
    std::transform(std::begin(P1), std::end(P1), std::begin(P1), [](auto x){return std::pow(x, 2);});
    print_vector(P1);
    
    //создадим последовательность П2 из N случайных чисел
    std::vector<int> P2(std::size(P1), 0);
    std::cout << "Creating a new sequence P2:" << std::endl;
    std::mt19937 mersenne(rd());
    std::uniform_int_distribution<> uid(1, 10);
    for (auto &i: P2)
    {
        i = uid(mersenne);
    }
    print_vector(P2);
    
    //вычислим сумму чисел в П2
    auto res = std::accumulate(std::begin(P2), std::end(P2), 0, [](int sum, int elem){return sum += elem;});
    std::cout << "The summ of P2 nums = " << res << std::endl;
    
    
    
    return 0;
}
