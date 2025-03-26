//
// Created by borys on 19/03/2025.
//

#ifndef MERGESORT_H
#define MERGESORT_H

#endif //MERGESORT_H

//https://www.geeksforgeeks.org/merge-sort/
//https://en.wikipedia.org/wiki/Merge_sort

template<class T>
class Mergesort : public SortAlgorithm<T> {
public:
    void mergesort(T a[], int low, int high);
private:
    void merge(T a[], int low, int mid, int high);
};

template<class T>
void Mergesort<T>::mergesort(T a[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}

template<class T>
void Mergesort<T>::merge(T a[], int low, int mid, int high) {
    int n1 = mid - low + 1, n2 = high - mid;

    T *left = new T[n1];
    T *right = new T[n2];

    for (int i = 0; i < n1; i++) {
        left[i] = a[low + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = a[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        ++this->comparisons;
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
            ++this->swaps;
        } else {
            a[k] = right[j];
            j++;
            ++this->swaps;
        }
        k++;
    }

    while (i < n1) {
        a[k] = left[i];
        i++;
        k++;
        ++this->swaps;
    }
    while (j < n2) {
        a[k] = right[j];
        j++;
        k++;
        ++this->swaps;
    }

    delete[] left;
    delete[] right;
}
