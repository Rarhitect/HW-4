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
    //#1. создадим последовательность П1 из чисел от 1 до 10
    std::cout << "Creating P1" << std::endl;
    std::vector < int > P1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_vector(P1);
    std::cout << std::endl;
    
    //#2. добавим несколько чисел в П1 через cin
    std::cout << "Add some elements into P1: ";
    std::copy(
        std::istream_iterator < int > (std::cin),
        std::istream_iterator < int > (),
        std::back_inserter(P1));
    std::cout << std::endl;
    
    //#3. перемешаем числа в П1 случайным образом
    std::cout << "Mixing P1: ";
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(std::begin(P1), std::end(P1), g);
    print_vector(P1);
    std::cout << std::endl;
    
    //#4. удалим дубликаты П1
    std::sort(std::begin(P1), std::end(P1));
    P1.erase(std::unique(std::begin(P1), std::end(P1)), std::end(P1));
    std::cout << "Deleting dublicates from P1:" << std::endl;
    print_vector(P1);
    std::cout << std::endl;
    
    //#5. подсчитаем количество четных чисел в П1
    auto even = std::count_if(std::begin(P1), std::end(P1), [](auto x){return x % 2 == 0;});
    std::cout << even << " evens" << std::endl;
    std::cout << std::endl;
    
    //#6. определим максимальное и минимальное в П1
    auto [min, max] = std::minmax_element(std::begin(P1), std::end(P1));
    std::cout << "Min num = " << *min << "; Max num = " << *max << std::endl;
    std::cout << std::endl;
    
    //#7. попробуем найти хотя бы одно простое число в П1
    auto prime_num = std::find_if(std::begin(P1), std::end(P1), [](auto x){return is_prime(x);});
    if (prime_num == std::end(P1))
        std::cout << "No prime numbers" << std::endl;
    else
        std::cout << "There is at least one prime num: " << *prime_num << std::endl;
    std::cout << std::endl;
    
    //#8. заменим все числа в П1 их квадратами
    
    std::cout << "Let's displace numbers of P1 with their squares:" << std::endl;
    std::transform(std::begin(P1), std::end(P1), std::begin(P1), [](auto x){return std::pow(x, 2);});
    print_vector(P1);
    std::cout << std::endl;
    
    //#9. создадим последовательность П2 из N случайных чисел
    std::vector<int> P2(std::size(P1), 0);
    std::cout << "Creating a new sequence P2:" << std::endl;
    std::mt19937 mersenne(rd());
    std::uniform_int_distribution<> uid(1, 10);
    for (auto &i: P2)
    {
        i = uid(mersenne);
    }
    print_vector(P2);
    std::cout << std::endl;
    
    //#10. вычислим сумму чисел в П2
    auto res = std::accumulate(std::begin(P2), std::end(P2), 0, [](int sum, int elem){return sum += elem;});
    std::cout << "The summ of P2 nums = " << res << std::endl;
    std::cout << std::endl;
    
    //#11. заменим первые несколько чисел П2 на 1
    std::cout << "Turning some numbers of P2 into 1:" << std::endl;
    std::transform(std::begin(P2), std::next(std::begin(P2), 4), std::begin(P2), [](auto x){return 1;});
    print_vector(P2);
    std::cout << std::endl;
    
    //#12. создадим П3 как разность П1 и П2
    std::cout << "Remember achieved P1 sequence:" << std::endl;
    std::transform(std::begin(P1), std::end(P1), std::begin(P1), [](auto x){return sqrt(x);});
    print_vector(P1); //возвращаем к прежнему виду последовательность П1
    std::sort(std::begin(P1), std::end(P1));
    std::sort(std::begin(P2), std::end(P2));
    std::cout << "Set difference of P1 and P2 (this is P3):" << std::endl;
    std::vector < int > P3;
    std::set_difference(
        P1.cbegin(), P1.cend(),
        P2.cbegin(), P2.cend(),
        std::inserter(P3, std::begin(P3)));
    print_vector(P3);
    std::cout << std::endl;
    
    //#13. заменим все отрицательные элементы П3 на нули
    std::cout << "For the next task i have to add some negative numbers to P3:" << std::endl;
    P3.push_back(-9);
    P3.push_back(-25);
    P3.push_back(-77);
    print_vector(P3);
    std::cout << "Let's turn negative elements of P3 into zeroes:" << std::endl;
    auto it = std::partition(std::begin(P3), std::end(P3), [](auto x){return x < 0;});
    std::transform(std::begin(P3), it, std::begin(P3), [](auto x){return 0;});
    std::cout << "MAGIC: ";
    print_vector(P3);
    std::cout << std::endl;
    
    //#14. удалим полностью все нулевые элементы из П3
    std::cout << "Now we are going to delete every zero from P3:" << std::endl;
    P3.erase(std::remove_if(std::begin(P3), std::end(P3), [](auto x){return x == 0;}));
    print_vector(P3);
    std::cout << std::endl;
    
    //#15. изменим порядок следования элементов П3 на обратный
    std::cout << "Reversing P3:" << std::endl;
    std::reverse(std::begin(P3), std::end(P3));
    print_vector(P3);
    std::cout << std::endl;
    
    //#16. определим топ-3 наибольших элемента в П3
    std::vector<int> copy_of_P3 = P3;
    std::sort(std::begin(copy_of_P3), std::end(copy_of_P3), [](auto x, auto y){return x > y;});
    std::cout << "TOP-3 OF P3:" << std::endl;
    for (auto i = 0; i < 3; ++i)
    {
        std::cout << "№" << i + 1 << ". " << copy_of_P3[i] << std::endl;
    }
    std::cout << std::endl;
    
    //#17. отсортируем полностью П1 и П2 по возрастанию
    std::cout << "Sorting P1 and P2:" << std::endl;
    std::sort(std::begin(P1), std::end(P1));
    std::cout << "Sorted P1: ";
    print_vector(P1);
    std::sort(std::begin(P2), std::end(P2));
    std::cout << "Sorted P2: ";
    print_vector(P2);
    std::cout << std::endl;
    
    //#18. создадим последовательность П4 как слияние П1 и П2
    std::cout << "Creating P4 as merge of P1 & P2:" << std::endl;
    std::vector < int > P4;
    std::merge(std::begin(P1), std::end(P1), std::begin(P2), std::end(P2), std::inserter(P4, std::begin(P4)));
    print_vector(P4);
    std::cout << std::endl;
    
    //#19. определим диапазон для упорядоченной вставки числа 1 в П4
    auto counter = std::count_if(std::begin(P4), std::end(P4), [](auto x){return x == 1;});
    std::cout << "Area for order-insert of 1 in P4 is from: 1 to " << counter << std::endl << std::endl;
    
    //#20. выведем все наши последовательности в cout
    std::cout << "FINALLY let's cout our sequences:" << std::endl;
    std::cout << "P1: ";
    std::copy(std::begin(P1), std::end(P1), std::ostream_iterator < int > (std::cout, " "));
    std::cout << std::endl;
    std::transform(std::begin(P1), std::end(P1), std::begin(P1), [](auto x){return std::pow(x, 2);});
    std::cout << "P2: ";
    std::copy(std::begin(P2), std::end(P2), std::ostream_iterator < int > (std::cout, " "));
    std::cout << std::endl;
    std::cout << "P3: ";
    std::copy(std::begin(P3), std::end(P3), std::ostream_iterator < int > (std::cout, " "));
    std::cout << std::endl;
    std::cout << "P4: ";
    std::copy(std::begin(P4), std::end(P4), std::ostream_iterator < int > (std::cout, " "));
    std::cout << std::endl;
    std::cout << "Don't forget about (P1)^2: ";
    std::copy(std::begin(P1), std::end(P1), std::ostream_iterator < int > (std::cout, " "));
    std::cout << std::endl << std::endl;
    
    return 0;
}
