#include <iostream>
#include <vector>
#include <list>
#include <chrono>


const int N = 100000;
void measure_vector_insertions(int N) {
    std::vector<int> vec;
    vec.reserve(N); // Pre-allocate memory to prevent reallocation

    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < N; ++i) {
        vec.insert(vec.begin() + vec.size() / 2, i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "std::vector insertions took: "
              << std::chrono::duration<double, std::milli>(end - start).count()
              << " ms\n";
}
void measure_vector_insertions_preallocate(int N) {
    std::vector<int> vec;
    vec.reserve(N); // Pre-allocate memory to prevent reallocation

    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < N; ++i) {
        vec.insert(vec.begin() + vec.size() / 2, i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "std::preallocated vector insertions took: "
              << std::chrono::duration<double, std::milli>(end - start).count()
              << " ms\n";
}
void measure_list_insertions(int N) {
    std::list<int> lst;

    auto start = std::chrono::high_resolution_clock::now();

    auto it = lst.begin();
    for (int i = 0; i < N; ++i) {
        it = lst.insert(std::next(lst.begin(), lst.size() / 2), i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "std::list insertions took: "
              << std::chrono::duration<double, std::milli>(end - start).count()
              << " ms\n";
}

void measure_list_insertions_fixed_middle(int N) {
    std::list<int> lst;
    auto mid = lst.begin();  // Iterator pointing to the middle

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        mid = lst.insert(mid, i); // Insert before mid and update the iterator

        // Maintain the middle iterator correctly
        if (i % 2 == 0) {
            ++mid; // Move forward only on even-sized lists
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "fixed middle std::list insertions took: "
              << std::chrono::duration<double, std::milli>(end - start).count()
              << " ms\n";
}


int main() {
    std::cout << "Performance difference for insertions between std::vector and std::list for " << N <<" elemenets is\n";
    measure_vector_insertions(N);
    measure_vector_insertions_preallocate(N);
    measure_list_insertions(N);
    measure_list_insertions_fixed_middle(N);
    return 0;
}
