
<div align="center">

# Atomix

### A Robust C++ Library for User Input, Array/Vector Operations, String Manipulation, and Utilities

<br>

<img src="https://img.shields.io/badge/Author-Aayush%20Badola-blue?style=for-the-badge&logo=github" alt="Author Badge"/>

<br>

<kbd><b><span style="color:#27ae60">Current Version 1.1.0</span></b></kbd>
<br>
<kbd><b><span style="color:#27ae60">Previous Version 1.0.0</span></b></kbd>
<br>

![Language](https://img.shields.io/badge/language-C++-blue.svg)
![Platform](https://img.shields.io/badge/platform-Cross--Platform-lightgrey.svg)
![License](https://img.shields.io/badge/license-MIT-orange.svg)
![Status](https://img.shields.io/badge/status-Active-brightgreen.svg)

<br>

<div align="center">
  <a href="https://github.com/AayushBadola">
    <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" alt="GitHub"/>
  </a>
  <a href="https://www.linkedin.com/in/aayush-badola-0a7b2b343">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn"/>
  </a>
  <a href="https://mail.google.com/mail/?view=cm&fs=1&to=aayush.badola2@gmail.com" target="_blank">
    <img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="Email"/>
  </a>
</div>

</div>

---

<div align="center">

### "Modern C++ Input, Collections, Strings & More"

</div>

## 📖 Overview

Atomix is a powerful and versatile C++ library designed to simplify common programming tasks. It offers robust user input handling using C++ streams, extensive utilities for manipulating both C-style arrays and `std::vector` collections (integers, floats, doubles, strings), a suite of string processing functions, and helpful tools like random number generation and timing.

Built with modern C++ practices in mind (leveraging the Standard Library where appropriate), Atomix provides intuitive functions, comprehensive error checking, and validation, aiming to make C++ development safer and more efficient. Its goal is to abstract away boilerplate code for routine tasks, allowing developers to focus on core application logic.

<br>
<div align="center">

```
📋 Ideal for educational settings, command-line tools, scientific computing,
data processing tasks, game development utilities, and any C++ application
needing reliable input, collection manipulation, string processing,
and utility functions.
```

</div>

## ✨ Features



<table>
  <tr>
    <th colspan="2" align="center">Input Handling</th>
  </tr>
  <tr>
    <td>✅ <b>Robust User Input</b></td>
    <td>Safe line reading (`get_string`), validated single character (`get_char`), integer (`get_int`, `get_long`), float (`get_float`), and double (`get_double`) input with automatic retries and comprehensive error checking using C++ exceptions and stream states.</td>
  </tr>
  <tr>
    <td>✅ <b>Range-Validated Input</b></td>
    <td>`get_int_range` ensures integer input falls within specified inclusive bounds.</td>
  </tr>
   <tr>
    <td>✅ <b>Non-Empty Input</b></td>
    <td>`get_string_non_empty` guarantees the user provides some text input, retrying if empty.</td>
  </tr>
   <tr>
    <th colspan="2" align="center">Collection Utilities (C-Style Arrays & `std::vector`)</th>
  </tr>
  <tr>
    <td>✅ <b>Modern C++ Vector Support</b></td>
    <td>Extensive, type-safe functions for `std::vector<int>`, `std::vector<float>`, `std::vector<double>`, and `std::vector<std::string>`.</td>
  </tr>
  <tr>
    <td>✅ <b>Comprehensive Analytics</b></td>
    <td>Find maximum, minimum, sum, and average for integer arrays and vectors of int, float, double. Handles potential integer overflow and uses `double` for floating-point sums/averages.</td>
  </tr>
  <tr>
    <td>✅ <b>Search & Counting</b></td>
    <td>Check for element existence (`contains`), find the first index (`index_of`), and count occurrences for all supported array/vector types. Uses epsilon tolerance for float/double comparisons.</td>
  </tr>
    <tr>
    <td>✅ <b>Efficient Sorting</b></td>
    <td>Uses `std::sort` internally for efficient (typically O(n log n)) and general-purpose sorting of integer, float, double, and string arrays/vectors.</td>
  </tr>
  <tr>
    <td>✅ <b>Modification Operations</b></td>
    <td>In-place reversal (`reverse`) and shuffling (`shuffle`) using standard algorithms and `<random>`.</td>
  </tr>
   <tr>
    <td>✅ <b>Copying & Concatenation</b></td>
    <td>Create deep copies or concatenate arrays/vectors into new collections. Manages memory appropriately (heap allocation for C-style arrays, RAII for vectors).</td>
  </tr>
  <tr>
    <td>✅ <b>Integer Array Pair Checks</b></td>
    <td>Optimized O(n) average time functions (`array_has_pair_sum`, `product`, `difference`) for C-style integer arrays using an internal hash table. Handles duplicates and edge cases.</td>
  </tr>
   <tr>
    <td>✅ <b>Unique Elements</b></td>
    <td>Function `array_unique_int` to create a new array containing only the unique elements from a C-style integer array.</td>
  </tr>
    <tr>
    <td>✅ <b>Formatted Printing</b></td>
    <td>Utility functions to print the contents of arrays and vectors in a readable `[elem1, elem2, ...]` format. Handles `nullptr` for C-style arrays.</td>
  </tr>
   <tr>
    <th colspan="2" align="center">String Manipulation</th>
  </tr>
   <tr>
    <td>✅ <b>Extensive String Utilities</b></td>
    <td>Trim whitespace, split strings by delimiter, join vector elements into a string, perform case conversions (`to_lower`, `to_upper`), check properties (`is_int`, `is_alpha`, etc.), extract substrings, find characters/substrings, replace characters, check prefix/suffix, compare equality. Operates on `std::string`.</td>
  </tr>
   <tr>
    <td>✅ <b>Safe Type Conversion</b></td>
    <td>Reliable functions (`string_to_float`, `string_to_double`) to convert `std::string` to numeric types, returning success status and handling errors gracefully.</td>
  </tr>
   <tr>
    <th colspan="2" align="center">General Utilities</th>
  </tr>
  <tr>
    <td>✅ <b>Random Number Generation</b></td>
    <td>Easy generation of cryptographically-seeded pseudo-random integers, floats, and doubles within specified ranges using `<random>`. Automatic seeding on first use.</td>
  </tr>
   <tr>
    <td>✅ <b>Timer Utilities</b></td>
    <td>Simple functions (`start_timer`, `stop_timer`) to measure execution time using `<chrono>` high-resolution clock. Returns duration in seconds.</td>
  </tr>
   <tr>
    <td>✅ <b>Memory Management Helpers</b></td>
    <td>Optional functions (`free_string`, `free_string_array`) to aid in freeing memory allocated by C-style string functions if needed.</td>
  </tr>
   <tr>
    <th colspan="2" align="center">Design & Compatibility</th>
  </tr>
  <tr>
    <td>✅ <b>Clean C++ API Design</b></td>
    <td>Consistent function signatures and behavior, leveraging standard C++ types like `std::string`, `std::vector`, `size_t`, and standard exceptions. Clear separation between C-style array and `std::vector` functions.</td>
  </tr>
  <tr>
    <td>✅ <b>Minimal Dependencies</b></td>
    <td>Relies solely on the C++11 Standard Library. No external libraries required.</td>
  </tr>
  <tr>
    <td>✅ <b>Cross-Platform Compatibility</b></td>
    <td>Designed to work on any system with a standard C++ compiler supporting C++11 or later (e.g., GCC, Clang, MSVC).</td>
  </tr>
</table>

## 🚀 Installation



1.  Download both `atomix.cpp` and `atomix.h` from the repository. Alternatively, clone the repository:

    ```bash
    git clone https://github.com/AayushBadola/Atomix.git
    ```
    ```
    cd Atomix
    ```

2.  Place `atomix.cpp` and `atomix.h` into your project's source directory.
3.  Include the Atomix header file in your C++ source files where you need its functionality:

    ```c++
    #include "atomix.h"
    ```

4.  Compile your program, making sure to include both your source file(s) and `atomix.cpp`. Use the `-std=c++11` flag (or a later standard like `-std=c++14`, `-std=c++17`, `-std=c++20`) to ensure compatibility.

    **Example using g++:**
    ```bash
    g++ your_program.cpp atomix.cpp -o your_program -std=c++11
    ```

5.  Run your compiled executable:

    ```bash
    ./your_program
    ```

#### **BONUS**

*   To compile and run the provided `test.cpp` file
    ```bash
    g++ test.cpp atomix.cpp -o test -std=c++11
    ```
    ```
    ./test
    ```

<div align="center">

## 💡 Usage Examples (Function-Specific Snippets)

</div>

This section provides minimal code snippets demonstrating the usage of specific Atomix functions. Assume necessary headers like `<iostream>`, `<vector>`, `<string>`, and `"atomix.h"` are included.

---
### Input Handling Functions

```c++
// Get a line of text
std::string user_name = get_string("Enter name: ");
std::cout << "Read: " << user_name << std::endl;

// Get a single character
char choice = get_char("Enter choice (Y/N): ");
std::cout << "Choice: " << choice << std::endl;

// Get an integer
int items = get_int("Number of items: ");
std::cout << "Items: " << items << std::endl;

// Get a long integer
long record_id = get_long("Enter Record ID: ");
std::cout << "ID: " << record_id << std::endl;

// Get a float
float temp = get_float("Temperature: ");
std::cout << "Temp: " << temp << std::endl;

// Get a double
double pressure = get_double("Pressure (kPa): ");
std::cout << "Pressure: " << pressure << std::endl;

// Get an integer within a specific range [1-10]
int rating = get_int_range("Rating (1-10): ", 1, 10);
std::cout << "Rating: " << rating << std::endl;

// Get a string that cannot be empty
std::string feedback = get_string_non_empty("Feedback (required): ");
std::cout << "Feedback given: " << feedback << std::endl;
```

---
### Integer Array Utilities (`int[]`)

```c++
// Setup for examples
int data[] = {3, 1, 4, 1, 5, 9, 2, 6};
size_t data_size = sizeof(data) / sizeof(data[0]);

// Get Max/Min value
int max_v, min_v;
if (array_max(data, data_size, &max_v)) { /* max_v = 9 */ }
if (array_min(data, data_size, &min_v)) { /* min_v = 1 */ }

// Calculate Sum
long long sum_v;
if (array_sum(data, data_size, &sum_v)) { /* sum_v = 31 */ }

// Calculate Average
double avg_v;
if (array_average(data, data_size, &avg_v)) { /* avg_v = 3.875 */ }

// Check if contains value 5
bool has_5 = array_contains_int(data, data_size, 5); // true

// Find index of first occurrence of 1
int index_1 = array_index_of_int(data, data_size, 1); // 1

// Count occurrences of 1
size_t count_1 = array_count_occurrence(data, data_size, 1); // 2

// Sort the array in-place
sort_array(data, data_size); // data is now {1, 1, 2, 3, 4, 5, 6, 9}

// Reverse the array in-place
array_reverse_int(data, data_size); // data is now {9, 6, 5, 4, 3, 2, 1, 1}

// Shuffle the array in-place
array_shuffle_int(data, data_size); // data is now in random order

// Print array contents
print_array(data, data_size); // e.g., [random_order...]

// Check if a pair sums to 7 (e.g., 1+6, 2+5, 3+4)
bool pair_sum_7 = array_has_pair_sum(data, data_size, 7); // true

// Check if a pair has product 12 (e.g., 3*4)
bool pair_prod_12 = array_has_pair_product(data, data_size, 12); // true

// Check if a pair has difference 2 (e.g., 3-1, 4-2, 6-4)
bool pair_diff_2 = array_has_pair_difference(data, data_size, 2); // true

// Create a heap-allocated copy
#include <cstdlib> // Required for delete[]
int* data_copy = array_copy_int(data, data_size);
if (data_copy) {
    // ... use data_copy ...
    delete[] data_copy; // IMPORTANT: Cleanup
}

// Get unique elements into a new heap-allocated array
size_t unique_count;
int* unique_data = array_unique_int(data, data_size, &unique_count);
if (unique_data) {
    // ... use unique_data (sorted: {1, 2, 3, 4, 5, 6, 9}) ...
    delete[] unique_data; // IMPORTANT: Cleanup
}

// Concatenate two arrays into a new heap-allocated array
int data2[] = {10, 11}; size_t data2_size = 2;
size_t concat_count;
int* combined_data = array_concat_int(data, data_size, data2, data2_size, &concat_count);
if (combined_data) {
    // ... use combined_data ...
    delete[] combined_data; // IMPORTANT: Cleanup
}
```

---
### Vector Utilities (`std::vector<T>`)


```c++
#include <vector>
#include <limits> // For epsilon example

// Setup for examples
std::vector<float> values = {3.1f, 1.5f, 4.1f, 1.5f, 5.9f};
float epsilon = std::numeric_limits<float>::epsilon() * 100;

// Get Max/Min value
float max_f, min_f;
if (array_max_float(values, &max_f)) { /* max_f = 5.9f */ }
if (array_min_float(values, &min_f)) { /* min_f = 1.5f */ }

// Calculate Sum
double sum_f;
if (array_sum_float(values, &sum_f)) { /* sum_f approx 16.1f */ }

// Calculate Average
double avg_f;
if (array_average_float(values, &avg_f)) { /* avg_f approx 3.22f */ }

// Check if contains value 4.1f (using epsilon)
bool has_4_1 = array_contains_float(values, 4.1f, epsilon); // true

// Find index of first occurrence of 1.5f (using epsilon)
long long index_1_5 = array_index_of_float(values, 1.5f, epsilon); // 1

// Count occurrences of 1.5f (using epsilon)
size_t count_1_5 = array_count_occurrence_float(values, 1.5f, epsilon); // 2

// Sort the vector in-place
array_sort_float(values); // values is now {1.5f, 1.5f, 3.1f, 4.1f, 5.9f}

// Reverse the vector in-place
array_reverse_float(values); // values is now {5.9f, 4.1f, 3.1f, 1.5f, 1.5f}

// Shuffle the vector in-place
array_shuffle_float(values); // values is now in random order

// Print vector contents
array_print_float(values); // e.g., [random_order...]

// Create a copy (vector handles memory)
std::vector<float> values_copy = array_copy_float(values);

// Concatenate two vectors (vector handles memory)
std::vector<float> values2 = {10.0f, 11.0f};
std::vector<float> combined_values = array_concat_float(values, values2);

// Helper for close-enough comparison (used internally by above functions)
bool close = floats_are_close(0.1f + 0.2f, 0.3f, epsilon); // Likely true
```

---
### String Array Utilities (`char*[]`)

```c++
#include <cstring> // For strcmp used internally

// Note: Requires const_cast if source array is defined as const char* []
const char* items_const[] = {"Pen", "Pencil", "Eraser"};
char* const* items_ptr = const_cast<char* const*>(items_const);
size_t items_size = 3;

// Find index of "Pencil"
int idx = find_string(items_ptr, items_size, "Pencil"); // 1
```

---
### String Manipulation (`std::string`)

```c++
#include <string>
#include <vector>

// Setup for examples
std::string text = "  Atomix Library!  ";
std::string numbers = "1,2,3";

// Copy and Compare
std::string text_copy = string_copy(text);
bool equal = string_equals(text, text_copy); // true

// Trim whitespace
std::string trimmed = string_trim(text); // "Atomix Library!"

// Check Type/Content
bool is_int_check = string_is_int(" -42 "); // true
bool is_alpha_check = string_is_alpha("Atomix"); // true
bool is_digit_check = string_is_digit("123"); // true
bool is_alnum_check = string_is_alnum("Atomix123"); // true
bool is_space_check = string_is_space(" \t "); // true
bool is_empty_check = string_is_empty(""); // true

// Change Case
std::string lower_case = string_to_lower("MixedCase"); // "mixedcase"
std::string upper_case = string_to_upper("MixedCase"); // "MIXEDCASE"

// Get Substring (index 7, length 7)
std::string sub = string_substring(trimmed, 7, 7); // "Library"

// Find Character/Substring
long long idx_L = string_find_char(trimmed, 'L'); // 7
long long idx_Lib = string_find_substring(trimmed, "Lib"); // 7

// Replace Character '!' with '?'
std::string replaced = string_replace_char(trimmed, '!', '?'); // "Atomix Library?"

// Split string by comma
std::vector<std::string> parts = string_split(numbers, ','); // {"1", "2", "3"}

// Join vector elements with "-"
std::string joined = string_join(parts, "-"); // "1-2-3"

// Check Prefix/Suffix
bool starts_with_Ato = string_starts_with(trimmed, "Ato"); // true
bool ends_with_ry_q = string_ends_with(replaced, "ry?"); // true

// Concatenate Strings
std::string s1 = "Hello";
std::string s2 = " World";
std::string combined = string_concat(s1, s2); // "Hello World"

// Convert String to Float/Double
float f_val;
double d_val;
bool ok_f = string_to_float(" 3.14 ", &f_val); // true, f_val = 3.14f
bool ok_d = string_to_double(" -1.6e-19 ", &d_val); // true, d_val approx -1.6e-19
```

---
### Memory Management Helpers

```c++
#include <cstdlib> // For malloc/free/strdup used in example scenario
#include <cstring> // For strdup

// Scenario: You receive a C-string from a function that used malloc/strdup
char* c_string = strdup("Allocated C String");
if (c_string) {
    // ... use c_string ...
    free_string(c_string); // Use helper to free it
}

// Scenario: You receive a C-string array where array and strings used malloc
char** c_array = (char**)malloc(2 * sizeof(char*));
if(c_array) {
    c_array[0] = strdup("First");
    c_array[1] = strdup("Second");
    if(c_array[0] && c_array[1]) {
       // ... use c_array ...
       free_string_array(c_array, 2); // Use helper to free strings and array
    } else { /* handle partial allocation */ free(c_array); }
}

// Note: Use delete[] for arrays returned by Atomix's array_copy_int etc.
```

---
### Utility Functions

```c++
#include <chrono> // For time_point

// Initialize random generator (optional, happens automatically on first use)
// initialize_random();

// Get random numbers
int random_int = get_random_int(1, 6); // Random integer between 1 and 6
float random_float = get_random_float(0.0f, 1.0f); // Random float between 0.0 and 1.0
double random_double = get_random_double(-10.0, 10.0); // Random double between -10.0 and 10.0

// Time an operation
auto t_start = start_timer();
// ... code to measure ...
double duration_sec = stop_timer(t_start);
std::cout << "Operation took " << duration_sec << " seconds.\n";
```

<div align="center">

## 📚 API Reference

</div>



---
### Input Handling Functions
**`std::string get_string(const char *prompt)`**
*   **Description:** Reads an entire line of text from standard input.
*   **Parameters:** `prompt`: (Optional) C-string to display before reading input.
*   **Returns:** `std::string` containing the input line. Empty string on EOF/error.
*(... and so on for all other input functions: get_char, get_int, get_long, get_float, get_double, get_int_range, get_string_non_empty ...)*

---
### Integer Array Utilities (`int[]`)
**`bool array_max(const int *arr, size_t size, int *max_val)`**
*   **Description:** Finds the maximum value in the array.
*   **Parameters:** `arr`, `size`, `max_val` (output pointer).
*   **Returns:** `true` on success, `false` otherwise.
*(... and so on for all other int[] functions: array_min, array_sum, array_average, array_contains_int, array_index_of_int, array_count_occurrence, sort_array, array_reverse_int, array_shuffle_int, print_array, array_has_pair_sum, array_has_pair_product, array_has_pair_difference, array_copy_int, array_unique_int, array_concat_int ...)*

---
### Vector Utilities (`std::vector`)
*(Summarize group and mention specific names like `array_max_float`, `array_sort_string`, etc., referring to `atomix.h`)*
**Analytics (`array_max_<type>`, `array_min_<type>`, `array_sum_<type>`, `array_average_<type>`)**
*   **Description:** Calculate max, min, sum, and average of vector elements.
*(... and so on for other vector function groups: Search & Counting, Modification, Copying & Concatenation, Printing, Float/Double Helpers ...)*

---
### String Array Utilities (`char*[]`)
**`int find_string(char * const arr_of_strings[], size_t size, const char *target_string)`**
*   **Description:** Finds the index of the first occurrence of a specific C-style string.
*   **Parameters:** `arr_of_strings`, `size`, `target_string`.
*   **Returns:** Index or `-1`.


---
### String Manipulation (`std::string`)
**Basic Ops & Checks**
*   `std::string string_copy(const std::string& str)`
*   `bool string_equals(const std::string& str1, const std::string& str2)`


---
### Memory Management Helpers
**`void free_string(char* str)`**
*   **Description:** Frees a single C-style string allocated with `malloc`/`strdup`.


---
### Utility Functions
**`void initialize_random()`**
*   **Description:** Initializes the global random number generator.

---

<div align="center">

## 🔧 Internal Implementation

</div>



Atomix leverages the C++ Standard Library extensively for robustness and efficiency:

1.  **Input Foundation:** `get_string` uses `std::getline`. Other `get_*` functions build upon `get_string`, using `std::sto*` functions (`stol`, `stoll`, `stof`, `stod`, `stold`) for parsing, handling exceptions (`std::invalid_argument`, `std::out_of_range`), and performing additional checks (trailing chars, numeric ranges). Retry loops handle invalid input.
2.  **Integer Array Pair Checks:** The `array_has_pair_*` functions use an internal C-style hash table (implemented with linked lists for collision resolution via `malloc`/`free`) to achieve O(n) average time complexity.
3.  **Sorting:** `sort_array` (for `int[]`) and `array_sort_<type>` (for `std::vector`) use `std::sort`, offering efficient (typically O(n log n)) and general-purpose sorting suitable for various data distributions.
4.  **Vector Operations:** Functions operating on `std::vector` heavily utilize standard library components:
    *   `<algorithm>`: `std::find`, `std::count`, `std::max_element`, `std::min_element`, `std::reverse`, `std::shuffle`, `std::copy`, `std::all_of`, `std::replace`, `std::transform`.
    *   `<numeric>`: `std::accumulate` for sums.
    *   RAII: `std::vector` manages its own memory, simplifying copy and concatenation logic.
5.  **String Manipulation:** Functions utilize `std::string` methods and algorithms from `<algorithm>`, `<sstream>`, `<cctype>`.
6.  **Random Numbers:** Employs the `<random>` library, specifically `std::mt19937` (Mersenne Twister) seeded by `std::random_device` for better randomness compared to `rand()`.
7.  **Timing:** Uses the `<chrono>` library's `std::chrono::high_resolution_clock` for potentially the most precise timing available on the platform.

## 📋 Best Practices



1.  **Check `std::cin` State:** When using input functions (`get_string`, `get_int`, etc.), if the default return value on error (e.g., `0` for `get_int`, empty string for `get_string`) is potentially valid input, check `std::cin.eof()` or `std::cin.fail()` afterwards to distinguish between valid input and a stream error/EOF condition.
    ```c++
    std::string input = get_string("Enter text (or press Ctrl+D): ");
    if (input.empty() && std::cin.eof()) { /* Handle EOF */ }
    // ...
    ```
2.  **Check Boolean Return Values:** Always check the `bool` return value of functions like `array_max`, `array_min`, `array_sum`, `array_average`, `string_to_float`, etc., before using the value stored in the output pointer. A `false` return indicates failure.
    ```c++
    double avg;
    if (array_average_float(my_vector, &avg)) { /* Use avg */ }
    // ...
    ```
3.  **Prefer `std::vector`:** Whenever possible, use `std::vector` and the corresponding Atomix vector utilities (`array_*_<type>`). `std::vector` handles memory management automatically (RAII).
4.  **Manage C-Style Array Memory:** If you use C-style array functions that return dynamically allocated memory (`array_copy_int`, `array_unique_int`, `array_concat_int`), **always** free the memory using `delete[]` when done.
    ```c++
    int* unique_data = array_unique_int(source_array, source_size, &unique_size);
    if (unique_data) { /* ... use unique_data ... */ delete[] unique_data; }
    ```
5.  **Floating-Point Comparisons:** Use an appropriate `epsilon` value when calling functions that compare floats or doubles.
6.  **Use Clear Prompts:** Provide informative prompts to the user when calling input functions.

## 🔍 Error Handling



*   **Input Function Retries:** Invalid format, out-of-range values, or empty input (for `get_string_non_empty`) typically trigger a retry prompt.
*   **Input Function Failures:** Fundamental stream errors (`std::cin.eof()`, `std::cin.fail()`) print an error message to `std::cerr`, and a default value is returned.
*   **Invalid Function Arguments:** Passing `nullptr` where a valid pointer is expected or invalid sizes usually results in the function returning `false` or performing no operation.
*   **Memory Allocation Failures:** Failures in `new` or C-style `malloc`/`calloc` print errors to `stderr` (via `perror` or `std::cerr`) and return `false`, `nullptr`, or perform no operation. `new` might throw `std::bad_alloc` if not using `nothrow`.
*   **Numeric Overflows:** Input functions check against type limits. `array_sum` for `int[]` checks for `long long` overflow.

## 📦 Dependencies



Atomix requires a C++ compiler that supports the **C++11 standard** or later. It relies only on the C++ Standard Library headers:

*   **Core:** `<iostream>`, `<string>`, `<vector>`, `<limits>`, `<stdexcept>`, `<cstddef>`, `<cstdlib>`, `<cstring>`, `<cmath>`, `<cctype>`
*   **Algorithms & Numerics:** `<algorithm>`, `<numeric>`
*   **Utilities:** `<random>`, `<chrono>`, `<set>`, `<sstream>`
*   **Error Handling/Low-level:** `<cstdio>` (for `perror`), `<cerrno>`, `<new>` (for `std::nothrow`)

No external third-party libraries are required.

## 🔄 Version History



### Version 1.1.0

*   **Added `std::vector` Support:** Introduced comprehensive functions for `std::vector<int>`, `float`, `double`, `std::string`.
*   **Enhanced Sorting:** Switched C-style array sort to `std::sort`. Vector sort also uses `std::sort`.
*   **Added String Manipulation:** Included a large suite of `std::string` processing functions.
*   **Added Random Utilities:** Introduced functions using `<random>`.
*   **Added Timer Utilities:** Introduced functions using `<chrono>`.
*   **Added Float/Double Comparison Helpers:** Added `floats_are_close` and `doubles_are_close`.
*   **Added Input Validation:** Implemented `get_int_range` and `get_string_non_empty`.
*   **Refactored Internals:** Increased use of standard library algorithms.
*   **Added Memory Helpers:** Included `free_string`, `free_string_array`, and C-style array copy/unique/concat functions requiring `delete[]`.
*   **Dependencies Updated:** Requires C++11, added new standard headers.

### Version 1.0.0 [Initial Release]

*   Core C++ `get_*` input functions.
*   Input validation and retry logic.
*   C-style integer array utilities: `array_max`, `min`, `sum`.
*   Optimized C-style integer array pair check functions (`sum`, `product`, `difference`) using hash table.
*   Initial `sort_array` using Counting Sort.
*   `find_string` for C-style `char*[]`.
*   `print_array` for C-style integer arrays.

## 📝 License


Atomix is released under the MIT License. See the LICENSE file for details.

```
MIT License

Copyright (c) 2025 Aayush Badola

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```


## 🤝 Contributing


Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](https://github.com/AayushBadola/Atomix/issues).

1.  Fork the Project Repository.
2.  Create your Feature Branch (`git checkout -b feature/YourAmazingFeature`).
3.  Commit your Changes (`git commit -m 'Add YourAmazingFeature'`).
4.  Push to the Branch (`git push origin feature/YourAmazingFeature`).
5.  Open a Pull Request.

## 📞 Contact



Aayush Badola

*   **GitHub:** [github.com/AayushBadola](https://github.com/AayushBadola)
*   **LinkedIn:** [linkedin.com/in/aayush-badola-0a7b2b343](https://www.linkedin.com/in/aayush-badola-0a7b2b343)
*   **Email:** [aayush.badola2@gmail.com](mailto:aayush.badola2@gmail.com)

<div align="center">
  <a href="https://github.com/AayushBadola">
    <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" alt="GitHub"/>
  </a>&nbsp;&nbsp;
  <a href="https://www.linkedin.com/in/aayush-badola-0a7b2b343">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn"/>
  </a>&nbsp;&nbsp;
  <a href="mailto:aayush.badola2@gmail.com">
    <img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="Email"/>
  </a>
</div>

---

<div align="center">

Made with ❤️ and C++ by [Aayush Badola](https://github.com/AayushBadola)

</div>



