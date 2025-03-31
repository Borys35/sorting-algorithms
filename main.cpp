#include <iostream>
#include <fstream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

#include "SortAlgorithm.h"
#include "Heapsort.h"
#include "Insertionsort.h"
#include "Mergesort.h"
#include "Quicksort.h"
#include "Introsort.h"

// C++20

template <class T>
T* createSingleArray(int n, float ratio) {
    T* arr = new T[n];

    if (ratio == -1) {
        for (int i = 0; i < n; i++) {
            arr[i] = n - i;
        }
    } else {
        for (int i = 0; i < n; i++) {
            float c_ratio = static_cast<float>(i) / static_cast<float>(n);
            // jezeli ratio=0, wszystkie wartosci beda losowe
            // jezeli ratio=1, wszystkie wartosci beda posortowane
            if (c_ratio >= ratio) {
                arr[i] = rand() % 101;
            } else {
                arr[i] = i;
            }
        }
    }
    return arr;
}

template <class T>
T* copySingleArray(T origin[], int n) {
    T *dest = new T [n];
    for (int i=0; i<n; i++) {
        dest[i] = origin[i];
    }
    return dest;
}

template <class T>
bool checkIfSorted(T* arr, int n) {
    for (int i=0; i < n - 1; i++) {
        if (arr[i] > arr[ i + 1 ]) {
            std::cout<<"Bad: ";
            for (int i = 0; i < n; i++) {
                std::cout<<arr[i]<<", ";
            }
            std::cout<<arr[i]<<"-"<<arr[i+1]<<std::endl;
            return false;
        }
    }
    return true;
}

int main() {
    std::ofstream file;

    file.open("./data_new.txt", std::ios::out | std::ios::trunc);

    if (!file.is_open()) {
        std::cout<<"File could not be opened"<<std::endl;
        return 0;
    }

    srand(0);
    // dla 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000
    // 9 rozmiarów * 8 przypadków = 72 tablice do posortowania
    // 72 tablice * 3 algorytmy = 216 cykli

    Quicksort<int> quicksort;
    Mergesort<int> mergesort;
    Introsort<int> introsort;

    float ratios[8] = {0, 0.25, 0.5, 0.75, 0.95, 0.99, 0.997, -1};
    int sizes[9] = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};

    // headers
    file << "no.,size,ratio,quicksort [ms],mergesort [ms],introsort [ms],quicksort [op_count],mergesort [op_count],introsort [op_count]\n";

    // data
    // sizes
    for (int i = 0; i < 9; i++) {
        // ratios
        for (int j = 0; j < 8; j++) {
            int size = sizes[i];
            float ratio = ratios[j];
            std::cout<<"Sorting array [size=" << size << ", ratio=" << ratio << "]"<<std::endl;

            for (int k = 0; k < 100; k++) {

                file << k + 1 << "," << size << "," << ratio << ",";

                int *array = createSingleArray<int>(size, ratio);
                int* arr_qs = copySingleArray<int>(array, size);
                auto t1 = Clock::now();
                quicksort.quicksort(arr_qs, 0, size-1);
                auto t2 = Clock::now();
                long time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
                file << time_ms << ",";
                // if (!checkIfSorted<int>(arr_qs, size)) {
                //     std::cout<<"Quicksort Bad!!\n";
                //     return 3;
                // }
                delete[] arr_qs;

                int* arr_ms = copySingleArray<int>(array, size);
                t1 = Clock::now();
                mergesort.mergesort(arr_ms, 0, size-1);
                t2 = Clock::now();
                time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
                file << time_ms << ",";
                // if (!checkIfSorted<int>(arr_ms, size)) {
                //     std::cout<<"Mergesort Bad!!";
                //     return 3;
                // }
                delete[] arr_ms;

                int* arr_is = copySingleArray<int>(array, size);
                t1 = Clock::now();
                introsort.introsort(arr_is, 0, size-1);
                t2 = Clock::now();
                time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
                file << time_ms << ",";
                // if (!checkIfSorted<int>(arr_is, size)) {
                //     std::cout<<"Introsort Bad!!";
                //     return 3;
                // }
                delete[] arr_is;
                delete[] array;

                file << quicksort.operations() << ",";
                quicksort.reset();

                file << mergesort.operations() << ",";
                mergesort.reset();

                file << introsort.operations() << "\n";
                introsort.reset();
            }
        }
    }

    file.close();
    return 0;
}