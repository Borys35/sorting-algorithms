//
// Created by borys on 18/03/2025.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H

//https://en.wikipedia.org/wiki/Quicksort

template<class T>
class Quicksort : public SortAlgorithm<T> {
public:
    void quicksort(T arr[], int low, int high);
};

template<class T>
void Quicksort<T>::quicksort(T arr[], int low, int high) {
    if (low < high) {
        int pivot = this->partition(arr, low, high);
        quicksort(arr, low, pivot);
        quicksort(arr, pivot + 1, high);
    }
}


#endif //QUICKSORT_H
