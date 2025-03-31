//
// Created by borys on 23/03/2025.
//

#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#endif //SORTALGORITHM_H

template<class T>
class SortAlgorithm {
public:
    virtual long long operations() { return comparisons + swaps; };
    virtual void reset() {
        comparisons = 0;
        swaps = 0;
    };
    virtual ~SortAlgorithm() = default;
protected:
    void swap(T &a, T &b) noexcept;
    int partition(T arr[], int low, int high);
    long long comparisons = 0;
    long long swaps = 0;
};


template<class T>
void SortAlgorithm<T>::swap(T &a, T &b) noexcept {
    ++this->swaps;
    T temp = a;
    a = b;
    b = temp;
}

// Hoare's partitioning
template<class T>
int SortAlgorithm<T>::partition(T arr[], int low, int high) {
    T pivot = arr[(low + high) / 2]; // middle element
    int i = low - 1, j = high + 1;

    while (true) {
        do {
            i++;
            ++this->comparisons;
        } while (arr[i] < pivot);

        do {
            j--;
            ++this->comparisons;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}