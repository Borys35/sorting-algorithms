//
// Created by borys on 22/03/2025.
//

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#endif //INSERTIONSORT_H

template<class T>
class Insertionsort : public SortAlgorithm<T> {
public:
    void insertionsort(T arr[], int low, int high);
};

template<class T>
void Insertionsort<T>::insertionsort(T arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > key) {
            ++this->comparisons;
            // ++this->swaps;
            this->swap(arr[j + 1], arr[j]);
            // arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        ++this->swaps;
    }
}

