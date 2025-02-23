#include <iostream>
#include <vector>
#include <list>
#include <chrono>

const int NUM_INSERTIONS = 1000000;

void measure_vector_insertions() {
    std::vector<int> vec;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < NUM_INSERTIONS; ++i) {
        vec.insert(vec.begin() + vec.size() / 2, i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "std::vector insertions time: " << duration.count() << " ms\n";
}

void measure_preallocated_vector_insertions() {
    std::vector<int> vec;
    vec.reserve(NUM_INSERTIONS);  // Preallocate memory
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < NUM_INSERTIONS; ++i) {
        vec.insert(vec.begin() + vec.size() / 2, i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Preallocated std::vector insertions time: " << duration.count() << " ms\n";
}

void measure_list_insertions_with_mid_iterator() {
    std::list<int> lst;
    auto mid = lst.begin();  // Iterator to track the middle

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < NUM_INSERTIONS; i++) {
        if (lst.empty()) {
            lst.push_back(i);
            mid = lst.begin();  // First element, mid points to it
        } else {
            // Insert the new value at the middle
            auto it = mid;
            lst.insert(it, i);  // Insert at the middle

            // After insertion, update the mid pointer correctly
            if (lst.size() % 2 == 0) {
                // Even size list, move the middle pointer to the previous node
                mid = std::prev(mid);
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Optimized std::list insertions time: " << duration.count() << " ms\n";
}

int main() {
    measure_vector_insertions();
    measure_preallocated_vector_insertions();
    measure_list_insertions_with_mid_iterator();
    return 0;
}
