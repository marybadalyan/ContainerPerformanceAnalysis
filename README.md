
# List vs Vector: Performance Benchmark

This program benchmarks the performance of inserting  elements in the middle of two different containers: `std::vector` and `std::list`. It compares the total time taken to insert  `N` elements into each container, and calculates the difference in performance between the two.

## Description

The program performs the following operations:

1. **Vector Insertion**: Measures the time to insert `N` elements in a `std::vector`.
2. **Pre-Allocated Vector Insertion**: Measures the time to insert `N` elements in a already allocated `std::vector`.
3. **List Insertion**: Measures the time to insert `N` elements in a `std::list`.
4. **Fixed Middle List Insertion**: Measures the time to insert `N` elements in a `std::list` while fixing the approximate middle.
5. **Time Comparison**: Calculates and displays the difference in total durations between the insertion and removal operations for both containers.

### Time Metrics

- The program uses `std::chrono::high_resolution_clock` to measure the time taken for each operation (insertion and removal).
- The durations are displayed in seconds.

### Benchmark Output

The program will output:

- The time taken for vector insertion for `N` elements.
- The time taken for pre-allocated vector insertion for `N` elements.
- The time taken for list insertion for `N` elements.
- The time taken for list insertion for `N` elements while fixing the middle.
- The difference in total time between the list and vector operations in seconds.


### Functions Used:
- `measure_vector_insertions(N)`:Inserts and Mesures time taken to insert `N` elements in the middle of the pre-allocated `std::vector` container `v`.
- `measure_vector_insertions_preallocate(N)`: Inserts and Mesures time taken to insert `N` elements in the middle of the `std::vector` container `v`.
- `measure_list_insertions(N)`: Inserts and Mesures time taken to insert `N` elements in the middle of the `std::list` container `l`.
- `measure_list_insertions_fixed_middle(N)`: Inserts and Mesures time taken to insert `N` elements in the fixed middle of the `std::list` container `l`.

## Requirements

- C++11 or later is required for compiling due to the use of `std::chrono`.
- A C++ compiler such as GCC or Clang is needed to compile the program.
- The code assumes the `vectorInsert`, `vectorRemove`, `listInsert`, and `listRemove` functions are defined elsewhere and handle the actual insertion and removal of elements.

## Compilation and Execution

### Build & Run
To clone and run this project, you'll need Git and CMake installed on your computer. From your command line:

# Clone this repository
```$ git clone https://github.com/marybadalyan/ContainerPerformanceAnalysis```

# Go into the repository
```$ cd ContainerPerformanceAnalysis```

# Generate the build files
```$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build```

# Build the project
```$ cmake --build build --config Release```

Then, run the executable generated in the build directory.
Clone the repository:

## Performance Benchmark


```
Performance comparison for 100000 insertions:

+--------------------------------------+------------+
| Insertion Method                     | Time (ms)  |
+--------------------------------------+------------+
| std::vector (no preallocation)       |    260.558 |
+--------------------------------------+------------+
| std::vector (preallocated)           |    230.659 |
+--------------------------------------+------------+
| std::list (middle recalculated)      |    16017.4 |
+--------------------------------------+------------+
| std::list (fixed middle)             |     4.2194 |
+--------------------------------------+------------+
```
**Conclusion:**  
The ```std::vector``` implementation is significantly faster than the ```std::list``` implementation when the middle position is not fixed. This performance difference arises because accessing elements in a vector is O(1) due to contiguous memory storage, whereas accessing elements in a list is O(N) since it requires traversal. Inserting elements into a vector, however, is O(N) because it may involve shifting elements, while insertion in a list is O(1) as it only requires pointer adjustments. Despite this, vectors often outperform lists due to better cache locality. Pre-allocating space in a vector using the reserve function can further enhance performance by reducing the need for frequent reallocations. 

This program allows for a quick performance comparison between two commonly used containers, `std::vector` and `std::list`. You can adjust the value of `N` to test with different amounts of data and observe how each container performs in terms of insertion and removal operations.
