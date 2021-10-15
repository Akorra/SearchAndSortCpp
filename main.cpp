#include <iostream>

#include "Search.h"

int main() 
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << Search::Linear<int>(arr, 10, 5) << std::endl;
    std::cout << Search::ImprovedLinear<int>(arr, 10, 5) << std::endl;
    std::cout << Search::RecursiveBinary<int>(arr, 0, 9, 2) << std::endl;
    std::cout << Search::IterativeBinary<int>(arr, 0, 9, 2) << std::endl;
    return 0;
}