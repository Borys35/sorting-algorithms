//
// Created by borys on 22/03/2025.
//

#ifndef INTROSORT_H
#define INTROSORT_H
#include <numbers>
#include <valarray>

#endif //INTROSORT_H

template<class T>
class Introsort : public SortAlgorithm<T> {
public:
    void introsort(T arr[], int low, int high);
private:
    void sort(T arr[], int low, int high, int depth);
};

template<class T>
void Introsort<T>::sort(T arr[], int low, int high, int depth) {
    int n = high - low + 1;
    if (n < 16) {
        Insertionsort<T> insertionsort;
        insertionsort.insertionsort(arr, low, high);
    } else if (depth == 0) {
        Heapsort<T> heapsort;
        heapsort.heapsort(arr, n);
    } else {
        int pivot = this->partition(arr, low, high);
        sort(arr, low, pivot - 1, depth - 1);
        sort(arr, pivot + 1, high, depth - 1);
    }
}

template<class T>
void Introsort<T>::introsort(T arr[], int low, int high) {
    int depth = std::log2(high  - low + 1) * 2;
    sort(arr, low, high, depth);
}
