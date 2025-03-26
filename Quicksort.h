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
    // if (low >= high || low < 0) return;
    //
    // int pivot = this->partition(arr, low, high);

    //if (low < pivot - 1)
        //quicksort(arr, low, pivot - 1);
    //if (pivot + 1 < high)
        //quicksort(arr, pivot + 1, high);

    while (low < high) {
        int pivot = this->partition(arr, low, high);
        if (pivot - low < high - pivot) {
            quicksort(arr, low, pivot - 1);
            low = pivot + 1;
        } else {
            quicksort(arr, pivot + 1, high);
            high = pivot - 1;
        }
    }
}


#endif //QUICKSORT_H
