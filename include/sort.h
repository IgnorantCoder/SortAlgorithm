#pragma once

#include "sort_traits.h"

namespace alg {
    template <Strategy s>
    inline void sort(int* arr, int n) {
        sort_traits<s>::apply(arr, n);
        return;
    }
}