#pragma once

#include "sort_implementation.h"

namespace alg {
    enum class Strategy {
        None = 0,
        Bubble,
        Selection,
        Insertion,
        Quick,
        Size
    };

    template <Strategy s>
    struct sort_traits {
        static void apply(int* arr, int n)
        {
            return;
        }
    };

    template <>
    struct sort_traits<Strategy::Bubble> {
        static void apply(int* arr, int n)
        {
            bubble_sort(arr, n);
            return;
        }
    };

    template <>
    struct sort_traits<Strategy::Selection> {
        static void apply(int* arr, int n)
        {
            selection_sort(arr, n);
            return;
        }
    };

    template <>
    struct sort_traits<Strategy::Insertion> {
        static void apply(int* arr, int n)
        {
            insertion_sort(arr, n);
            return;
        }
    };

    template <>
    struct sort_traits<Strategy::Quick> {
        static void apply(int* arr, int n)
        {
            quick_sort(arr, n);
            return;
        }
    };
}