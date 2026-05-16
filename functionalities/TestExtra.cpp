#pragma once
#include <iostream>
#include <vector>
#include "Comparator.h"
#include "Tutorial.h"
#include "ComparatorByTitle.h"
#include "ComparatorByLikes.h"

template <typename T>
void generic_sort(std::vector<T>& vec, const Comparator<T>& comp) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (!comp.compare(vec[i], vec[j])) {
                std::swap(vec[i], vec[j]);
            }
        }
    }
}

