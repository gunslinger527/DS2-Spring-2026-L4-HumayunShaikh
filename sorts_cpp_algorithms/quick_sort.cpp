#include "sorts.h"
#include <algorithm>

static void quick_sort_impl(std::vector<int>& v, int left, int right) {
    //add quick sort code here
    if (left >= right) {
        return;
    }
    int pivot = v[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (v[j] <= pivot) {
            ++i;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[right]);
    quick_sort_impl(v, left, i);
    quick_sort_impl(v, i + 2, right);
}

void quick_sort(std::vector<int>& v) {
    if (!v.empty()) {
        quick_sort_impl(v, 0, static_cast<int>(v.size() - 1));
    }
}