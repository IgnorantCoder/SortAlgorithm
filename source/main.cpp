#include <iostream>

#include "sort.h"

void print(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        if (0 != i) {
            std::cout << ", ";
        }
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

int main()
{
    {
        std::size_t size = 8;
        int a[] = { 8, 4, 3, 7, 6, 5, 2, 1 };
        alg::sort<alg::Strategy::Bubble>(a, size);
        print(a, size);
    }
    {
        std::size_t size = 8;
        int a[] = { 8, 4, 3, 7, 6, 5, 2, 1 };
        alg::sort<alg::Strategy::Selection>(a, size);
        print(a, size);
    }
    {
        std::size_t size = 8;
        int a[] = { 8, 4, 3, 7, 6, 5, 2, 1 };
        alg::sort<alg::Strategy::Insertion>(a, size);
        print(a, size);
    }
    {
        std::size_t size = 8;
        int a[] = { 8, 4, 3, 7, 6, 5, 2, 1 };
        alg::sort<alg::Strategy::Quick>(a, size);
        print(a, size);
    }

    {
        std::size_t size = 8;
        int a[] = { 8, 4, 3, 7, 6, 5, 2, 1 };
        alg::sort<alg::Strategy::Shell>(a, size);
        print(a, size);
    }

    return 0;
}