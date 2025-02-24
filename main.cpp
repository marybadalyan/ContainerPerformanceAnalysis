#include <iostream>
#include <vector>
#include <list>
#include <chrono>

void measure_vector_insertions() {
    std::vector<int> vec;
    vec.reserve(10000); // Pre-allocate memory to prevent reallocation

    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < 10000; ++i) {
        vec.insert(vec.begin() + vec.size() / 2, i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "std::vector insertions took: "
              << std::chrono::duration<double, std::milli>(end - start).count()
              << " ms\n";
}
void measure_vector_insertions_preallocate() {
    std::vector<int> vec;
    vec.reserve(10000); // Pre-allocate memory to prevent reallocation

    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < 10000; ++i) {
        vec.insert(vec.begin() + vec.size() / 2, i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "std::preallocated vector insertions took: "
              << std::chrono::duration<double, std::milli>(end - start).count()
              << " ms\n";
}
void measure_list_insertions() {
    std::list<int> lst;

    auto start = std::chrono::high_resolution_clock::now();

    auto it = lst.begin();
    for (int i = 0; i < 10000; ++i) {
        it = lst.insert(std::next(lst.begin(), lst.size() / 2), i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "std::list insertions took: "
              << std::chrono::duration<double, std::milli>(end - start).count()
              << " ms\n";
}

int main() {
    measure_vector_insertions();
    measure_vector_insertions_preallocate();
    measure_list_insertions();
    return 0;
}
