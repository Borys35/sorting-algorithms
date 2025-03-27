//
// Created by borys on 22/03/2025.
//

#ifndef INTROSORT_H
#define INTROSORT_H
#endif //INTROSORT_H

#include <math.h>

template<class T>
class Introsort : public SortAlgorithm<T> {
public:
    void introsort(T arr[], int low, int high);
    long long operations() override;
    void reset() override;
private:
    void sort(T arr[], int low, int high, int depth);
    Insertionsort<T> insertionsort;
    Heapsort<T> heapsort;
    Quicksort<T> quicksort;
};

template<class T>
long long Introsort<T>::operations() {
    return insertionsort.operations() + heapsort.operations() + quicksort.operations();
}

template<class T>
void Introsort<T>::reset() {
    insertionsort.reset();
    heapsort.reset();
    quicksort.reset();
}

template<class T>
void Introsort<T>::sort(T arr[], int low, int high, int depth) {
    int n = high - low + 1;
    if (n < 16) {
        insertionsort.insertionsort(arr, low, high);
    }
    else if (depth == 0) {
        heapsort.heapsort(arr + low, n);
    }
    else {
        // quicksort.quicksort(arr, low, high);
        int pivot = this->partition(arr, low, high); // Use Quicksort's partition
        sort(arr, low, pivot, depth - 1); // Recur with depth-1
        sort(arr, pivot + 1, high, depth - 1);
    }
}

template<class T>
void Introsort<T>::introsort(T arr[], int low, int high) {
    int depth = 2 * log2(high - low);
    sort(arr, low, high, depth);
}
