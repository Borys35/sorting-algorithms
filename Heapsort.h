//
// Created by borys on 22/03/2025.
//

#ifndef HEAPSORT_H
#define HEAPSORT_H

#endif //HEAPSORT_H

// https://www.geeksforgeeks.org/heap-sort/

template<class T>
class Heapsort : public SortAlgorithm<T> {
public:
    void heapsort(T arr[], int n);
private:
    void heapify(T arr[], int n, int i);
};

template<class T>
void Heapsort<T>::heapify(T* arr, int n, int i) {
    int largest = 0;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[i]) {
        ++this->comparisons;
        largest = l;
    } else {
        ++this->comparisons;
        largest = i;
    }
    if (r < n && arr[r] > arr[largest]) {
        ++this->comparisons;
        largest = r;
    }

    if (largest != i) {
        this->swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template<class T>
void Heapsort<T>::heapsort(T* arr, int n) {
    int size = n;

    for (int i = (size - 1) / 2; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        this->swap(arr[0], arr[i]);
        --size;
        heapify(arr, size, 0);
    }
}
