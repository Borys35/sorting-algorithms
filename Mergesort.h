//
// Created by borys on 19/03/2025.
//

#ifndef MERGESORT_H
#define MERGESORT_H

#endif //MERGESORT_H

template<class T>
class Mergesort : public SortAlgorithm<T> {
public:
    void mergesort(T a[], int low, int high);
private:
    void merge(T a[], int low, int mid, int high);
};

// Rozbijamy tablice na pojedyncze części
template<class T>
void Mergesort<T>::mergesort(T a[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}

// łączymy pojedyncze elementy w większe, posortowane tablice
template<class T>
void Mergesort<T>::merge(T a[], int low, int mid, int high) {
    int n1 = mid - low + 1, n2 = high - mid;

    T *left = new T[n1];
    T *right = new T[n2];

    for (int i = 0; i < n1; i++) {
        left[i] = a[low + i];
        ++this->swaps;
    }
    for (int i = 0; i < n2; i++) {
        right[i] = a[mid + 1 + i];
        ++this->swaps;
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        ++this->comparisons;
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        ++this->swaps;
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
