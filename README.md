Performance Comparison of std::vector and std::list Insertions
This C++ program benchmarks the performance of inserting elements into std::vector and std::list containers. It measures the time taken to insert 10,000 integers at the middle of each container and outputs the results in milliseconds.

Compilation and Execution with CMake
To compile and run this program using CMake, follow these steps:

## Compilation and Execution

### Build & Run
To clone and run this project, you'll need Git and CMake installed on your computer. From your command line:

# Clone this repository
$ git clone https://github.com/marybadalyan/vectorvslist2

# Go into the repository
$ cd vectorvslist2

# Generate the build files
$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

# Build the project
$ cmake --build build --config Release

Then, run the executable generated in the build directory.


## Performance Benchmark 

Expected output:

std::vector insertions took: 11.295 ms
std::preallocated vector insertions took: 10.8599 ms
std::list insertions took: 182.001 ms
Performance Analysis
The output indicates the following:

std::vector Insertions:

Without pre-allocation: 11.295 ms
With pre-allocation (vec.reserve(10000)): 10.8599 ms
std::list Insertions:

Insertions took 182.001 ms
Observations
std::vector Performance:

Inserting elements at the beginning or middle of a std::vector is generally inefficient because it requires shifting all subsequent elements to accommodate the new element. This results in a time complexity of O(n) for each insertion.
Pre-allocating memory using reserve() can improve performance by reducing the number of reallocations, but it doesn't eliminate the need to shift elements during insertions.
std::list Performance:

std::list is optimized for insertions and deletions at arbitrary positions, offering O(1) time complexity for these operations. However, the observed performance is significantly slower than std::vector, which may be due to factors such as less efficient memory allocation patterns and poorer cache locality.
Conclusion
While std::list provides efficient insertions at arbitrary positions, its performance in this benchmark is slower than std::vector. This discrepancy highlights the importance of considering both time complexity and practical performance characteristics, such as memory allocation patterns and cache locality, when choosing the appropriate container for a given use case.
