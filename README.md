
<div align="center">

# Atomix

### A Robust C++ Library for Handling User Input and Utilities

<br>

<img src="https://img.shields.io/badge/Author-Aayush%20Badola-blue?style=for-the-badge&logo=github" alt="Author Badge"/>

<br>

<kbd><b><span style="color:#27ae60">Current Version 1.0.0</span></b></kbd>
<br>


![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
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

### "Streamline C++ Input & Array Operations"

</div>

## 📖 Overview

Atomix is a lightweight yet powerful C++ library designed to simplify and standardize the process of obtaining user input using C++ streams, while also providing helpful array manipulation utilities. Developed with a focus on robustness and ease of use, Atomix handles common input scenarios, providing comprehensive error checking and validation that goes beyond basic stream operations.

The library offers a collection of intuitive functions built on top of standard C++ features, promoting safer user interaction and simplifying common array tasks.

<br>
<div align="center">

```
📋 Perfect for educational environments, command-line tools, and any C++ application
requiring secure, validated user input and basic array analytics.
```

</div>

## ✨ Features

<table>
  <tr>
    <td>✅ <b>Robust String Input</b></td>
    <td>Reads entire lines safely using <code>std::string</code> and <code>std::getline</code></td>
  </tr>
  <tr>
    <td>✅ <b>Comprehensive Input Validation</b></td>
    <td>Automatic type checking and error handling for all input functions using C++ exceptions and checks</td>
  </tr>
  <tr>
    <td>✅ <b>Type-Specific Input Functions</b></td>
    <td>Specialized functions for <code>std::string</code>, <code>char</code>, <code>int</code>, <code>long</code>, <code>float</code>, and <code>double</code></td>
  </tr>
  <tr>
    <td>✅ <b>Intelligent Retry Mechanism</b></td>
    <td>Automatic prompting for retries when invalid input is provided</td>
  </tr>
  <tr>
    <td>✅ <b>Numeric Range Validation</b></td>
    <td>Checks for overflow/underflow based on standard type limits</td>
  </tr>
  <tr>
    <td>✅ <b>Array Max/Min/Sum</b></td>
    <td>Efficient functions to find maximum, minimum, and sum of integer arrays</td>
  </tr>
  <tr>
    <td>✅ <b>Array Pair Checks (Sum, Product, Difference)</b></td>
    <td>Optimized O(n) average time functions to find pairs meeting specific criteria using hash tables</td>
  </tr>
    <tr>
    <td>✅ <b>Array Sorting (Counting Sort)</b></td>
    <td>Efficient O(n+k) sort for integer arrays (optimized for non-negative)</td>
  </tr>
    <tr>
    <td>✅ <b>String Array Search</b></td>
    <td>Locate strings within an array of C-style strings</td>
  </tr>
    <tr>
    <td>✅ <b>Array Printing</b></td>
    <td>Formatted output for integer arrays</td>
  </tr>
  <tr>
    <td>✅ <b>Clean C++ API Design</b></td>
    <td>Consistent function signatures and behavior across the library</td>
  </tr>
  <tr>
    <td>✅ <b>Minimal Dependencies</b></td>
    <td>Uses only standard C++ and C standard libraries</td>
  </tr>
  <tr>
    <td>✅ <b>Cross-Platform Compatibility</b></td>
    <td>Works on any system with a standard C++ compiler</td>
  </tr>
</table>

## 🚀 Installation

The simplest way to use Atomix in your project is to include the source files directly:

1. Download both `atomix.cpp` and `atomix.h` (assuming you have one) from this repository, or clone the repository:

```bash
git clone https://github.com/AayushBadola/Atomix.git
```

```bash
cd Atomix
```

2. Place `atomix.cpp` and `atomix.h` in your project directory.
3. Include the header in your source files that need to use Atomix functions:

```c++
#include "atomix.h"
```

4. Compile your program with both files. For example, if your main program is `your_program.cpp`:

```bash
g++ your_program atomix.cpp -o your_program -std=c++11
```

5. Run your program:

```bash
./your_program
```


This will compile both your main file and the Atomix library file, link them, create an executable, and allow you to use the Atomix functions.

<div align="center">

## 💡 Usage Examples

</div>

### Basic String Input

The `get_string` function provides a safe way to read text input of any length into a `std::string`:

```c++
#include <iostream>
#include <string>
#include "atomix.h"

int main() {
    std::string name = get_string("Enter your name: ");
    if (!name.empty() || !std::cin.eof()) {
        std::cout << "Hello, " << name << "!\n";
    } else {
        std::cerr << "Error reading input or EOF encountered.\n";
        return 1;
    }
    return 0;
}
```

### Reading and Validating Numbers

Atomix handles the parsing and validation of numeric input automatically:

```c++
#include <iostream>
#include "atomix.h"

int main() {
    int age = get_int("Enter your age: ");
    std::cout << "You are " << age << " years old.\n";

    float price = get_float("Enter the price: $");
    std::cout << "The price is $" << price << "\n";

    long population = get_long("Enter world population: ");
    std::cout << "World population is " << population << "\n";

    double pi_value = get_double("Enter the value of pi: ");
    std::cout.precision(10);
    std::cout << "Pi is approximately " << pi_value << "\n";

    return 0;
}
```

### User Confirmation

Getting a single character input for confirmation prompts:

```c++
#include <iostream>
#include "atomix.h"

int main() {
    std::cout << "This will delete all files. Are you sure?\n";
    char answer = get_char("Continue? (y/n): ");

    if (answer == 'y' || answer == 'Y') {
        std::cout << "Proceeding with deletion...\n";
    } else {
        std::cout << "Operation cancelled.\n";
    }

    return 0;
}
```

### Using Array Utilities

Examples for the array utility functions:

```c++
#include <iostream>
#include "atomix.h"

int main() {
    int nums[] = {5, -2, 10, 8, 2, 7, 15, 7};
    size_t size = sizeof(nums) / sizeof(nums[0]);

    std::cout << "Array: ";
    print_array(nums, size);

    int max_val;
    if (array_max(nums, size, &max_val)) {
        std::cout << "Max value: " << max_val << "\n";
    }

    int min_val;
    if (array_min(nums, size, &min_val)) {
        std::cout << "Min value: " << min_val << "\n";
    }

    long long sum_val;
     if (array_sum(nums, size, &sum_val)) {
        std::cout << "Sum: " << sum_val << "\n";
    }

    bool found_9 = array_has_pair_sum(nums, size, 9);
    bool found_14 = array_has_pair_sum(nums, size, 14);
    std::cout << "Pair summing to 9 found: " << (found_9 ? "true" : "false") << "\n";
    std::cout << "Pair summing to 14 found: " << (found_14 ? "true" : "false") << "\n";

    bool found_neg_10 = array_has_pair_product(nums, size, -10);
    bool found_49 = array_has_pair_product(nums, size, 49);
    std::cout << "Pair with product -10 found: " << (found_neg_10 ? "true" : "false") << "\n";
    std::cout << "Pair with product 49 found: " << (found_49 ? "true" : "false") << "\n";

    bool found_3 = array_has_pair_difference(nums, size, 3);
    bool found_neg_5 = array_has_pair_difference(nums, size, -5);
    bool found_0 = array_has_pair_difference(nums, size, 0);
    std::cout << "Pair with difference 3 found: " << (found_3 ? "true" : "false") << "\n";
    std::cout << "Pair with difference -5 found: " << (found_neg_5 ? "true" : "false") << "\n";
    std::cout << "Pair with difference 0 found: " << (found_0 ? "true" : "false") << "\n";

    int positive_nums[] = {5, 2, 8, 2, 1, 9, 4, 0};
    size_t pos_size = sizeof(positive_nums) / sizeof(positive_nums[0]);
    std::cout << "Before sort: "; print_array(positive_nums, pos_size);
    sort_array(positive_nums, pos_size);
    std::cout << "After sort:  "; print_array(positive_nums, pos_size);

    char* items[] = {"Apple", "Banana", "Cherry", "Apple", nullptr};
    size_t items_size = 5;
    std::cout << "String items array size: " << items_size << std::endl;


    const char* search_items[] = {"Apple", "Banana", "Cherry", "Apple"};
    size_t search_items_size = 4;
    int index = find_string(const_cast<char* const*>(search_items), search_items_size, "Apple");
    std::cout << "First 'Apple' found at index: " << index << "\n";

    index = find_string(const_cast<char* const*>(search_items), search_items_size, "Durian");
    std::cout << "'Durian' found at index: " << index << "\n";

    return 0;
}
```
*Note on `find_string` example: The function signature `char * const arr_of_strings[]` is slightly unusual, typically it would be `const char* const arr_of_strings[]`. The example uses `const char*[]` which is more common, and requires a `const_cast` to match the function's parameter type. If you can change the library function signature to `const char* const arr_of_strings[]`, it would be more idiomatic C++ and the cast wouldn't be needed.*

<div align="center">

## 📚 API Reference

</div>

### Input Handling

#### `std::string get_string(const char *prompt)`

Reads a line of text from standard input into a `std::string`.

-   **Parameters**:
    -   `prompt`: Text to display before reading input (can be `nullptr`).
-   **Returns**:
    -   A `std::string` containing the input line.
    -   An empty `std::string` if EOF is encountered immediately or a stream failure occurs.
-   **Behavior**:
    -   Uses `std::getline` for safe line reading.
    -   Handles potential stream errors (`std::cin.eof()`, `std::cin.fail()`).
    -   Flushes `std::cout` before reading if a prompt is provided.
-   **Dependencies**: `<iostream>`, `<string>`
-   **Example**:
    ```c++
    std::string input = get_string("Enter text: ");
    if (!input.empty() || !std::cin.eof()) {
        std::cout << "Read: " << input << "\n";
    } else {
         std::cerr << "Input error or EOF.\n";
    }
    ```

#### `char get_char(const char *prompt)`

Reads a single character from standard input with validation.

-   **Parameters**:
    -   `prompt`: Text to display before reading input (can be `nullptr`).
-   **Returns**:
    -   A single `char` entered by the user.
    -   `'\0'` if a fundamental input error or EOF occurs that prevents reading.
-   **Behavior**:
    -   Uses `get_string` internally to read a line.
    -   Validates that the entered line contains exactly one non-newline character.
    -   Automatically prompts for retry ("Retry: ") if input is invalid or empty (unless EOF/fail).
-   **Dependencies**: `<iostream>`, `<string>`, `<cctype>`
-   **Example**:
    ```c++
    char key = get_char("Press a key: ");
    std::cout << "You pressed: " << key << "\n";
    ```

#### `int get_int(const char *prompt)`

Reads an integer from standard input with validation.

-   **Parameters**:
    -   `prompt`: Text to display before reading input (can be `nullptr`).
-   **Returns**:
    -   A valid `int` value entered by the user.
    -   `0` if a fundamental input error or EOF occurs that prevents reading (check `std::cin` state if `0` is a valid input).
-   **Behavior**:
    -   Uses `get_string` internally to read a line.
    -   Uses `std::stol` for parsing, providing robust error detection.
    -   Checks for leading/trailing whitespace.
    -   Ensures no non-whitespace trailing characters exist after the number.
    -   Checks for overflow/underflow against `std::numeric_limits<int>::min()` and `max()`.
    -   Automatically prompts for retry ("Retry: ") on invalid format, range errors, or trailing characters.
-   **Dependencies**: `<iostream>`, `<string>`, `<stdexcept>`, `<limits>`, `<cctype>`
-   **Example**:
    ```c++
    int count = get_int("Enter quantity: ");
    std::cout << "Quantity: " << count << "\n";
    ```

#### `long get_long(const char *prompt)`

Reads a long integer from standard input with validation.

-   **Parameters**:
    -   `prompt`: Text to display before reading input (can be `nullptr`).
-   **Returns**:
    -   A valid `long` value entered by the user.
    -   `0L` if a fundamental input error or EOF occurs.
-   **Behavior**:
    -   Uses `get_string` internally.
    -   Uses `std::stol` for parsing.
    -   Checks for leading/trailing whitespace and non-whitespace trailing characters.
    -   Checks for overflow/underflow against `std::numeric_limits<long>::min()` and `max()`.
    -   Automatically prompts for retry.
-   **Dependencies**: `<iostream>`, `<string>`, `<stdexcept>`, `<limits>`, `<cctype>`
-   **Example**:
    ```c++
    long id = get_long("Enter ID: ");
    std::cout << "ID: " << id << "\n";
    ```

#### `float get_float(const char *prompt)`

Reads a floating-point number from standard input with validation.

-   **Parameters**:
    -   `prompt`: Text to display before reading input (can be `nullptr`).
-   **Returns**:
    -   A valid `float` value entered by the user.
    -   `0.0f` if a fundamental input error or EOF occurs.
-   **Behavior**:
    -   Uses `get_string` internally.
    -   Uses `std::stof` for parsing.
    -   Checks for leading/trailing whitespace and non-whitespace trailing characters.
    -   Checks for overflow/underflow against `float` limits via `std::out_of_range`.
    -   Automatically prompts for retry.
-   **Dependencies**: `<iostream>`, `<string>`, `<stdexcept>`, `<cctype>`
-   **Example**:
    ```c++
    float temperature = get_float("Enter temp: ");
    std::cout << "Temperature: " << temperature << "\n";
    ```

#### `double get_double(const char *prompt)`

Reads a double-precision floating-point number from standard input with validation.

-   **Parameters**:
    -   `prompt`: Text to display before reading input (can be `nullptr`).
-   **Returns**:
    -   A valid `double` value entered by the user.
    -   `0.0` if a fundamental input error or EOF occurs.
-   **Behavior**:
    -   Uses `get_string` internally.
    -   Uses `std::stod` for parsing.
    -   Checks for leading/trailing whitespace and non-whitespace trailing characters.
    -   Checks for overflow/underflow against `double` limits via `std::out_of_range`.
    -   Automatically prompts for retry.
-   **Dependencies**: `<iostream>`, `<string>`, `<stdexcept>`, `<cctype>`
-   **Example**:
    ```c++
    double value = get_double("Enter value: ");
    std::cout << "Value: " << value << "\n";
    ```

### Array Utility Functions

These functions operate on integer arrays (`int[]`) unless otherwise specified.

#### `bool array_max(const int *arr, size_t size, int *max_val)`

Finds the maximum value in an integer array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the integer array.
    -   `size`: `size_t` - Number of elements in the array.
    -   `max_val`: `int*` - Pointer to an `int` variable where the maximum value will be stored if found.
-   **Returns**:
    -   `bool`: `true` if the maximum value was found (input valid: `arr` not `nullptr`, `size > 0`, `max_val` not `nullptr`).
    -   `bool`: `false` otherwise.
-   **Behavior**:
    -   Iterates through the array to find the largest element.
    -   If successful, stores the maximum value found in the variable pointed to by `max_val`.
-   **Dependencies**: `<cstddef>`, `<stdbool.h>`
-   **Example**:
    ```c++
    int nums[] = {5, -2, 10, 8};
    int max_result;
    if (array_max(nums, 4, &max_result)) {
        std::cout << "Max: " << max_result << "\n";
    } else {
        std::cerr << "Could not find maximum.\n";
    }
    ```

#### `bool array_min(const int *arr, size_t size, int *min_val)`

Finds the minimum value in an integer array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the integer array.
    -   `size`: `size_t` - Number of elements in the array.
    -   `min_val`: `int*` - Pointer to an `int` variable where the minimum value will be stored if found.
-   **Returns**:
    -   `bool`: `true` if the minimum value was found (input valid: `arr` not `nullptr`, `size > 0`, `min_val` not `nullptr`).
    -   `bool`: `false` otherwise.
-   **Behavior**:
    -   Iterates through the array to find the smallest element.
    -   If successful, stores the minimum value found in the variable pointed to by `min_val`.
-   **Dependencies**: `<cstddef>`, `<stdbool.h>`
-   **Example**:
    ```c++
    int nums[] = {5, -2, 10, 8};
    int min_result;
    if (array_min(nums, 4, &min_result)) {
        std::cout << "Min: " << min_result << "\n";
    } else {
        std::cerr << "Could not find minimum.\n";
    }
    ```

#### `bool array_sum(const int *arr, size_t size, long long *sum)`

Calculates the sum of all elements in an integer array.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the integer array.
    -   `size`: `size_t` - Number of elements in the array.
    -   `sum`: `long long*` - Pointer to a `long long` variable where the sum will be stored.
-   **Returns**:
    -   `bool`: `true` if the sum was calculated successfully (includes sum = 0 for size 0 or `nullptr` array).
    -   `bool`: `false` if the output pointer `sum` is `nullptr` or if potential overflow during summation was detected and prevented.
-   **Behavior**:
    -   Iterates through the array, adding each element to a `long long` accumulator to reduce overflow risk.
    -   Checks for potential overflow before adding each element.
    -   If successful, stores the final sum in the variable pointed to by `sum`.
    -   Returns `true` for size 0, setting sum to 0.
-   **Dependencies**: `<cstddef>`, `<limits>`, `<stdbool.h>`, `<iostream>`
-   **Example**:
    ```c++
    int nums[] = {5, -2, 10, 8};
    long long sum_result;
    if (array_sum(nums, 4, &sum_result)) {
        std::cout << "Sum: " << sum_result << "\n";
    } else {
        std::cerr << "Could not calculate sum or overflow detected.\n";
    }
    ```

#### `bool array_has_pair_sum(const int *arr, size_t size, int target)`

Checks if any *distinct* pair of elements in the array sums up to the target value.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the integer array.
    -   `size`: `size_t` - Number of elements in the array.
    -   `target`: `int` - The target sum value.
-   **Returns**:
    -   `bool`: `true` if a pair `(arr[i], arr[j])` exists where `i != j` and `arr[i] + arr[j] == target`.
    -   `bool`: `false` otherwise, or if `size < 2`, or if internal memory allocation for the hash table fails.
-   **Behavior**:
    -   Uses an internal hash table to check for the complement (`target - x`) of each element `x`.
    -   Handles duplicate numbers correctly.
-   **Implementation Details**: O(n) average time complexity, O(n) space complexity due to internal hash table.
-   **Dependencies**: `<cstddef>`, `<cstdlib>`, `<cmath>`, `<stdexcept>`, `<limits>`, `<iostream>`, `<stdbool.h>`
-   **Example**:
    ```c++
    int nums[] = {2, 7, 11, 15, 7};
    bool found_9 = array_has_pair_sum(nums, 5, 9);
    bool found_14 = array_has_pair_sum(nums, 5, 14);
    std::cout << "Pair summing to 9 found: " << (found_9 ? "true" : "false") << "\n";
    std::cout << "Pair summing to 14 found: " << (found_14 ? "true" : "false") << "\n";
    ```

#### `bool array_has_pair_product(const int *arr, size_t size, int target)`

Checks if any *distinct* pair of elements in the array multiplies to the target value.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the integer array.
    -   `size`: `size_t` - Number of elements in the array.
    -   `target`: `int` - The target product value.
-   **Returns**:
    -   `bool`: `true` if a pair `(arr[i], arr[j])` exists where `i != j` and `arr[i] * arr[j] == target`.
    -   `bool`: `false` otherwise, or if `size < 2`, or if internal memory allocation for the hash table fails.
-   **Behavior**:
    -   Uses an internal hash table.
    -   Handles zero elements and duplicate numbers correctly.
-   **Implementation Details**: O(n) average time complexity, O(n) space complexity due to internal hash table. Includes checks for intermediate overflow.
-   **Dependencies**: `<cstddef>`, `<cstdlib>`, `<cmath>`, `<stdexcept>`, `<limits>`, `<iostream>`, `<stdbool.h>`
-   **Example**:
    ```c++
    int nums[] = {3, 5, -2, 8, 5};
    bool found_neg_10 = array_has_pair_product(nums, 5, -10);
    bool found_25 = array_has_pair_product(nums, 5, 25);
    std::cout << "Pair with product -10 found: " << (found_neg_10 ? "true" : "false") << "\n";
    std::cout << "Pair with product 25 found: " << (found_25 ? "true" : "false") << "\n";
    ```

#### `bool array_has_pair_difference(const int *arr, size_t size, int target)`

Checks if any pair of elements (order matters, `a - b`) has a difference equal to the target value.

-   **Parameters**:
    -   `arr`: `const int*` - Pointer to the integer array.
    -   `size`: `size_t` - Number of elements in the array.
    -   `target`: `int` - The target difference value (`arr[i] - arr[j] == target`).
-   **Returns**:
    -   `bool`: `true` if a pair `(arr[i], arr[j])` exists where `arr[i] - arr[j] == target`.
    -   `bool`: `false` otherwise, or if `size < 2`, or if internal memory allocation for the hash table fails.
-   **Behavior**:
    -   Uses an internal hash table. Checks for both `x - target` and `x + target` as complements.
    -   Handles duplicates correctly (e.g., `7 - 7 = 0` will be found if 7 appears at least twice).
-   **Implementation Details**: O(n) average time complexity, O(n) space complexity due to internal hash table. Includes checks for intermediate overflow.
-   **Dependencies**: `<cstddef>`, `<cstdlib>`, `<cmath>`, `<stdexcept>`, `<limits>`, `<iostream>`, `<stdbool.h>`
-   **Example**:
    ```c++
    int nums[] = {10, 7, 15, 5, 7};
    bool found_3 = array_has_pair_difference(nums, 5, 3);
    bool found_neg_5 = array_has_pair_difference(nums, 5, -5);
    bool found_0 = array_has_pair_difference(nums, 5, 0);
    std::cout << "Pair with difference 3 found: " << (found_3 ? "true" : "false") << "\n";
    std::cout << "Pair with difference -5 found: " << (found_neg_5 ? "true" : "false") << "\n";
    std::cout << "Pair with difference 0 found: " << (found_0 ? "true" : "false") << "\n";
    ```

#### `void sort_array(int arr[], size_t size)`

Sorts an integer array in ascending order using Counting Sort (O(n+k) time complexity). Modifies the array in-place.

- **Parameters**:
  - `arr`: `int[]` : The integer array to sort.
  - `size`: `size_t` : Number of elements in the array.

- **Returns**: `void`
- **Behavior**:
  - Sorts the array `arr` in non-decreasing order.
  - Optimized for non-negative integers. Prints a warning for negative values (they won't be sorted correctly by this specific implementation).
  - Handles empty arrays or arrays with one element gracefully.
  - Prints an error to `stderr` and returns if memory allocation for internal buffers fails or if the range of values is too large for `size_t`.
- **Implementation Details**: Uses Counting Sort. Requires auxiliary space O(n + k) where k is the range of values.
- **Dependencies**: `<cstddef>`, `<cstdlib>`, `<cstring>`, `<iostream>`, `<limits>`, `<cerrno>`
- **Example**:
```c++
#include <iostream>
#include "atomix.h"

int main() {
    int data[] = {5, 2, 8, 2, 1, 9, 4, 0};
    size_t n = sizeof(data) / sizeof(data[0]);
    std::cout << "Before sort: "; print_array(data, n);
    sort_array(data, n);
    std::cout << "After sort:  "; print_array(data, n);
    return 0;
}
```

#### `int find_string(char * const arr_of_strings[], size_t size, const char *target_string)`

Finds the first occurrence of a specific C-style string within an array of C-style strings.

- **Parameters**:
  - `arr_of_strings`: `char * const []` : An array of C-style strings (pointers to characters).
  - `size`: `size_t` : Number of elements (strings) in the array.
  - `target_string`: `const char*` : The string to search for.
- **Returns**:
  - `int` : The index (0-based) of the first matching string if found.
  - `int : -1` : if the string is not found, or if `arr_of_strings` or `target_string` is `nullptr`.
- **Behavior**:
  - Performs a linear search through the `arr_of_strings` array.
  - Compares each non-`nullptr` string in the array with `target_string` using `strcmp`.
- **Implementation Details**: O(n * m) time complexity, where n is array size and m is average string length. O(1) space.
- **Dependencies**: `<cstddef>`, `<cstring>`
- **Example**:
```c++
#include <iostream>
#include "atomix.h"

int main() {
    const char* items[] = {"Apple", "Banana", "Cherry", "Apple"};
    size_t n = sizeof(items) / sizeof(items[0]);
    int index = find_string(const_cast<char* const*>(items), n, "Apple");
    std::cout << "First 'Apple' found at index: " << index << "\n";

    index = find_string(const_cast<char* const*>(items), n, "Durian");
    std::cout << "'Durian' found at index: " << index << "\n";
    return 0;
}
```

#### `void print_array(const int arr[], size_t size)`

Prints the elements of an integer array to standard output in a formatted way.

- **Parameters**:
  - `arr`: `const int[]` : The integer array to print. Can be `nullptr`.
  - `size`: `size_t` : Number of elements in the array.
- **Returns**: `void`
- **Behavior**:
  - Prints `nullptr` if `arr` is `nullptr`.
  - Prints `[]` if `arr` is not `nullptr` but `size` is 0.
  - Otherwise, prints elements enclosed in `[]`, separated by `, `.
  - Prints a newline character `\n` at the end.
- **Implementation Details**: O(n) time complexity. O(1) space complexity.
- **Dependencies**: `<iostream>`, `<cstddef>`
- **Example**:
```c++
#include <iostream>
#include "atomix.h"

int main() {
    int values[] = {10, 20, 30};
    print_array(values, 3);

    int empty_arr[] = {};
    print_array(empty_arr, 0);

    print_array(nullptr, 5);

    return 0;
}
```

<div align="center">

## 🔧 Internal Implementation

</div>

The library uses a layered approach for input and optimized algorithms for array operations:

1.  **Input Foundation:** `get_string` forms the base, providing robust line reading into `std::string` using `std::getline`.
2.  **Input Validation:** All other `get_*` functions utilize `get_string` internally, followed by specific parsing and validation logic using C++ standard library features:
    *   `get_char` validates line length.
    *   `get_int`, `get_long`, `get_float`, `get_double` use `std::st*` functions (`std::stol`, `std::stof`, `std::stod`) for parsing, handling `std::invalid_argument` and `std::out_of_range` exceptions, checking for trailing characters and numeric ranges.
3.  **Array Operations:**
    *   `array_max`, `array_min`, `array_sum`, `find_string`, `print_array` perform simple O(n) traversals.
    *   `array_has_pair_sum`, `array_has_pair_product`, `array_has_pair_difference` use an **internal hash table** (implemented with dynamic C memory allocation `malloc`/`calloc`) to achieve O(n) average time complexity for checking pair conditions, requiring O(n) auxiliary space.
    *   `sort_array` uses the **Counting Sort** algorithm for O(n+k) time complexity (where k is the range of values) for sorting non-negative integers, requiring O(n+k) auxiliary space (implemented with dynamic C memory allocation).

## 📋 Best Practices

When using the Atomix library, keep the following best practices in mind:

1.  **Check `std::string::empty()` and `std::cin` state** when using `get_string`:
    ```c++
    std::string input = get_string("Enter text: ");
    if (input.empty() && (std::cin.eof() || std::cin.fail())) {
        std::cerr << "Error reading input or EOF.\n";
    }
    ```

2.  **Check boolean return values** for `array_max`, `array_min`, `array_sum`, and `array_has_pair_*` before using the output pointer (for max/min/sum) or relying on the pair check result:
    ```c++
    int arr[] = {1, 2, 3};
    int max_val;
    if (array_max(arr, 3, &max_val)) {
        std::cout << "Max is " << max_val << "\n";
    } else {
        std::cerr << "Failed to find maximum.\n";
    }
    ```

3.  **Be aware of the limitations** of `sort_array` which is optimized for non-negative integers and has memory considerations related to the range of values.

4.  **Consider range limitations** of the various numeric types (`int`, `long`, `float`, `double`) when choosing which `get_*` function to use.

5.  **Use appropriate prompts** to guide users clearly.

## 🔍 Error Handling

Atomix handles most standard input errors internally by prompting the user to retry. For `get_string`, `get_char`, `get_int`, `get_long`, `get_float`, `get_double`, if a fundamental stream error (like EOF or a persistent failure) occurs, they print an error message to `std::cerr` and return a default/empty value (`""`, `'\0'`, `0`, `0L`, `0.0f`, `0.0`). Your calling code should ideally check the return value (for `get_string`) or the state of `std::cin` if default return values are ambiguous for your use case.

For array functions:

1.  **Invalid arguments** (e.g., `nullptr` array pointer with `size > 0`, `nullptr` output pointers) are checked and typically result in a `false` return value.
2.  **Internal memory allocation failure** within hash table or sorting functions (`malloc`/`calloc` returning `nullptr`) is checked. An error message is printed to `stderr` and the function returns `false` (for pair checks) or `void` after printing an error (for sort).
3.  **Potential numeric overflow** is checked in `array_sum` and `sort_array`, resulting in warnings or errors printed to `stderr` and potentially a `false` return value for `array_sum`.

## 📦 Dependencies

Atomix relies only on standard C++ and C libraries:

-   `<iostream>`: For C++ input/output operations (`std::cout`, `std::cin`, `std::cerr`, `std::getline`).
-   `<string>`: For `std::string`.
-   `<cstdlib>`: For C memory allocation (`malloc`, `calloc`, `free`) and `std::llabs`.
-   `<cstring>`: For C string operations (`std::strcmp`, `std::memcpy`).
-   `<cctype>`: For character classification (`std::isspace`).
-   `<cmath>`: For `std::llabs` (needed for hash function).
-   `<cerrno>`: For `errno` (used by `strto*` functions, though not explicitly checked for `ERANGE` in your code's catch blocks, `std::out_of_range` covers it).
-   `<stdexcept>`: For `std::invalid_argument` and `std::out_of_range` exceptions from `std::st*` functions.
-   `<limits>`: For `std::numeric_limits`.
-   `<cstddef>`: For `size_t` and `nullptr`.
-   `<stdbool.h>`: For `bool`, `true`, `false` types.
-   `<stdint.h>`: For `SIZE_MAX` (mentioned in Aquant v1.2.0 README, though not explicitly used in the provided C++ code).

## 🔄 Version History

### Version 1.0.0 [Initial Release]

-   Complete implementation of core C++ `get_*` input functions (`get_string`, `get_char`, `get_int`, `get_long`, `get_float`, `get_double`) built on `std::string` and C++ streams.
-   Input validation and retry logic using C++ exceptions and stream state.
-   **Added C++ Equivalents:** Implemented `array_max`, `array_min`, `array_sum`, `array_has_pair_sum`, `array_has_pair_product`, `array_has_pair_difference` functions in C++.
-   **Optimized Pair Check Functions:** Implemented `array_has_pair_sum`, `array_has_pair_product`, `array_has_pair_difference` using an internal hash table (using C-style memory allocation) for O(n) average time complexity.
-   Added `<cstdlib>`, `<cmath>`, `<stdbool.h>`, `<limits>`, `<stdexcept>`, `<iostream>` dependencies.
-   Improved input function robustness slightly.

-   **Added C++ Equivalents:** Implemented `sort_array`, `find_string`, and `print_array` functions in C++.
-   `sort_array`: Uses Counting Sort for integer arrays (O(n+k)). Optimized for non-negative integers.
-   `find_string`: Linear search for C-style strings in a `char* const []` array.
-   `print_array`: Formatted printing for integer arrays.
-   Added checks for memory allocation failures and range issues in `sort_array`.
-   Added `<cstring>`, `<cmath>`, `<limits>`, `<cerrno>`, `<stdexcept>`, `<iostream>` dependencies explicitly for relevant functions.

## 📝 License

Atomix is based on MIT license and thus protected by said License.

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📞 Contact

Aayush Badola

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

Made with ❤️ by [Aayush Badola](https://github.com/AayushBadola)

</div>



