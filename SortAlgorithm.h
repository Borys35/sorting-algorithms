//
// Created by borys on 23/03/2025.
//

#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#endif //SORTALGORITHM_H

template<class T>
class SortAlgorithm {
public:
    long long operations();
    void reset();
protected:
    void swap(T &a, T &b);
    int partition(T arr[], int low, int high);
    long long comparisons = 0;
    long long swaps = 0;
private:
    T median(T a, T b, T c);
};

template <class T>
T SortAlgorithm<T>::median(T a, T b, T c) {
    if ((a > b) ^ (a > c)) return a;
    else if ((b < a) ^ (b < c)) return b;
    else return c;
}

template<class T>
long long SortAlgorithm<T>::operations() {
    return comparisons + swaps;
}

template<class T>
void SortAlgorithm<T>::reset() {
    comparisons = 0;
    swaps = 0;
}


template<class T>
void SortAlgorithm<T>::swap(T &a, T &b) {
    ++this->swaps;
    T temp = a;
    a = b;
    b = temp;
}

// template<class T>
// int SortAlgorithm<T>::partition(T arr[], int low, int high) {
//     T pivot = arr[(low + high) / 2];
//     int l = low, r = high;
//
//     while (true) {
//         while (arr[l] < pivot) l++;
//         while (arr[r] > pivot) r--;
//         if (l >= r)
//             return r;
//
//         swap(arr[l], arr[r]);
//
//         l++;
//         r--;
//     }
// }

template<class T>
int SortAlgorithm<T>::partition(T arr[], int low, int high) {
    //T pivot = arr[(low + high) / 2];
    T pivot = arr[high];
    //T pivot = arr[rand()%(high-low + 1) + low];
    //T pivot = median(arr[low], arr[low + (high - low)/2], arr[high]);
    int temp = low - 1;

    for (int i = low; i < high; i++) {
        ++this->comparisons;
        if (arr[i] < pivot) {
            temp++;
            swap(arr[i], arr[temp]);

        }
    }

    swap(arr[high], arr[temp + 1]);
    return temp + 1;
}