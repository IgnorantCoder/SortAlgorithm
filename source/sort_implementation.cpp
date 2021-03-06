#include "sort_implementation.h"

#include <utility>  //for std::swap
#include <cmath>
#include <memory>
#include <limits>

namespace {
    void insertion_sort(int* arr, int n, int gear) {
        for (int i = 0; i < n; i += gear) {
            for (int j = i; j > gear; j -= gear) {
                if (arr[j - gear] > arr[j]) {    //predictor
                    break;
                }
                std::swap(arr[j - gear], arr[j]);
            }
        }
    }

    int exponentiation(const int a, const int x)
    {
        if (x == 0) {
            return 1;
        }
        return a * exponentiation(a, x - 1);
    }

    int half(const int a)
    {
        return a >> 1;
    }

    std::unique_ptr<int[]> add_sentinel(int const* arr, const int n)
    {
        auto ret = std::make_unique<int[]>(n + 1);
        for (int i = 0; i < n; ++i) {
            ret[i] = arr[i];
        }

        static const int sentinel = std::numeric_limits<int>::min();
        ret[n] = sentinel;

        return ret;
    }

    void merge(int* arr, const int n)
    {
        const auto m = half(n);
        const auto array0 = add_sentinel(arr, m);
        const auto array1 = add_sentinel(arr + m, n - m);
        int i0 = 0;
        int i1 = 0;
        for (int i = 0; i < n; ++i) {
            arr[i] = array0[i0] > array1[i1] ? array0[i0++] : array1[i1++];
        }
        return;
    }
}

namespace alg {
    void bubble_sort(int* arr, int n) {
        for (int l = 0; l < n - 1; ++l) {
            for (int r = l; r < n; ++r) {
                if (arr[l] < arr[r]) {    //predictor
                    std::swap(arr[l], arr[r]);
                }
            }
        }
    }

    void selection_sort(int* arr, int n) {
        for (int i = 0; i < n; ++i) {
            int m = i;
            for (int j = m + 1; j < n; ++j) {
                if (arr[m] < arr[j]) {    //predictor
                    m = j;
                }
            }
            std::swap(arr[i], arr[m]);
        }
    }

    void insertion_sort(int* arr, int n) {
        ::insertion_sort(arr, n, 1);
        return;
    }

    void quick_sort(int* arr, int n) {
        if (n <= 2) {
            if (n == 2) {
                if (arr[0] < arr[1]) {
                    std::swap(arr[1], arr[0]);
                }
            }
            return;
        }

        const int m = (n - 1) >> 1;
        const int pivot =
            arr[0] < arr[m]
            ? arr[m] < arr[n - 1]
            ? arr[m]
            : arr[0] < arr[n - 1] ? arr[n - 1] : arr[0]
            : arr[0] < arr[n - 1]
            ? arr[0]
            : arr[m] < arr[n - 1] ? arr[n - 1] : arr[m];

        int l = 0;
        int r = n - 1;
        for (;;) {
            for (; l < n; ++l)
            {
                if (arr[l] < pivot) {
                    break;
                }
            }
            for (; r >= 0; --r)
            {
                if (arr[r] > pivot) {
                    break;
                }
            }

            if (l > r) {
                break;
            }

            std::swap(arr[l], arr[r]);
        }

        quick_sort(&arr[0], r + 1);
        quick_sort(&arr[l], n - l);
    }

    void shell_sort(int* arr, int n) {
        static const double log3 = std::log(3);
        const int gear_idx = static_cast<int>(std::log(2 * n + 1) / log3 - 1);

        int gear = half(exponentiation(3, gear_idx + 1) - 1);
        static const auto iterate = [](int& g) -> void { g = (g - 1) / 3; };

        for (;gear > 0; iterate(gear)) {
            for (int i = 0; i < gear; ++i) {
                ::insertion_sort(arr + i, n - i, gear);
            }
        }
    }

    void merge_sort(int* arr, int n)
    {
        if (n > 1) {
            const auto m = n >> 1;
            merge_sort(arr, m);
            merge_sort(arr + m, n - m);
            ::merge(arr, n);
        }
        return;
    }
}
