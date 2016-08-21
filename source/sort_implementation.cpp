#include "sort_implementation.h"

#include <utility>  //for std::swap

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
        for (int i = 1; i < n; ++i) {
            for (int j = i; j > 0; --j) {
                if (arr[j - 1] > arr[j]) {    //predictor
                    break;
                }
                std::swap(arr[j - 1], arr[j]);
            }
        }
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
}
