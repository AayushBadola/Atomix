#include "atomix.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath> // Include for fabs, fabsl (global), isinf etc.
#include <cerrno>
#include <stdexcept>
#include <vector>
#include <numeric>   // std::accumulate
#include <algorithm> // std::sort, std::reverse, std::find, std::max_element, std::min_element, std::shuffle, std::copy, std::all_of, std::find_if_not
#include <random>    // std::random_device, std::mt19937, std::uniform_int_distribution, std::uniform_real_distribution
#include <chrono>    // std::chrono::high_resolution_clock, std::chrono::duration
#include <set>       // For array_unique_int
#include <sstream>   // For string splitting and joining, string to num conversion

// --- Global Random Engine ---
static std::mt19937 global_random_engine;
static bool random_initialized = false;

// --- Input Functions ---

// ... (get_string, get_char, get_int, get_long, get_float remain the same) ...
std::string get_string(const char *prompt)
{
    if (prompt != nullptr)
    {
        std::cout << prompt << std::flush;
    }

    std::string line;
    if (std::getline(std::cin, line))
    {
        return line;
    }
    else
    {
        if (std::cin.eof())
        {
            // Return empty string on EOF, let caller decide how to handle
        }
        else if (std::cin.fail())
        {
            std::cerr << "Error: Input error in get_string." << std::endl;
            std::cin.clear(); // Attempt to clear error flags
            // Consume the rest of the bad line if possible
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return ""; // Return empty string on error too
    }
}

char get_char(const char *prompt)
{
    const char *current_prompt = prompt;
    while (true)
    {
        std::string line = get_string(current_prompt);
        if (line.empty() && (std::cin.eof() || std::cin.fail()))
        {
            std::cerr << "\nInput error or EOF encountered. Cannot get character." << std::endl;
            return '\0'; // Indicate failure
        }

        if (line.length() == 1)
        {
            return line[0];
        }

        if (current_prompt == nullptr)
        {
            current_prompt = "Retry: ";
        }
        std::cout << "Invalid input. Please enter exactly one character." << std::endl;
    }
}

int get_int(const char *prompt)
{
    const char *current_prompt = prompt;
    while (true)
    {
        std::string line = get_string(current_prompt);
        if (line.empty() && (std::cin.eof() || std::cin.fail())) {
            std::cerr << "\nInput error or EOF encountered. Cannot get integer." << std::endl;
            return 0; // Indicate failure or default
        }

        if (line.empty()) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
             std::cout << "Invalid input. Please enter an integer." << std::endl;
             continue;
        }

        try
        {
            size_t pos;
            long n = std::stol(line, &pos); // Use long for wider range check

            // Check for trailing non-whitespace characters
            while (pos < line.length() && std::isspace(static_cast<unsigned char>(line[pos])))
            {
                pos++;
            }

            if (pos != line.length())
            {
                 if (current_prompt == nullptr) current_prompt = "Retry: ";
                std::cout << "Invalid input. Trailing characters found after integer." << std::endl;
                continue;
            }

            // Check if the value fits within an int
            if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
            {
                if (current_prompt == nullptr) current_prompt = "Retry: ";
                std::cout << "Input out of range for standard integer type (int). Please enter a value between " << std::numeric_limits<int>::min() << " and " << std::numeric_limits<int>::max() << "." << std::endl;
                continue;
            }

            return static_cast<int>(n);
        }
        catch (const std::invalid_argument& e)
        {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Not a valid integer." << std::endl;
        }
        catch (const std::out_of_range& e)
        {
             if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Input out of range for internal parsing type. Please enter a valid integer within int limits." << std::endl;
        }
    }
}

long get_long(const char *prompt)
{
    const char *current_prompt = prompt;
    while (true)
    {
        std::string line = get_string(current_prompt);
         if (line.empty() && (std::cin.eof() || std::cin.fail())) {
            std::cerr << "\nInput error or EOF encountered. Cannot get long integer." << std::endl;
            return 0L;
        }

        if (line.empty()) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Please enter a long integer." << std::endl;
            continue;
        }

        try {
            size_t pos;
            // Use stoll for long long to detect overflow for long if needed, though stol handles long directly
            long long n_ll = std::stoll(line, &pos);

            while (pos < line.length() && std::isspace(static_cast<unsigned char>(line[pos]))) {
                pos++;
            }

            if (pos != line.length()) {
                if (current_prompt == nullptr) current_prompt = "Retry: ";
                std::cout << "Invalid input. Trailing characters found after long integer." << std::endl;
                continue;
            }

            // Check if the value fits within a long
            if (n_ll < std::numeric_limits<long>::min() || n_ll > std::numeric_limits<long>::max())
            {
                if (current_prompt == nullptr) current_prompt = "Retry: ";
                std::cout << "Input out of range for long integer type. Please enter a value between " << std::numeric_limits<long>::min() << " and " << std::numeric_limits<long>::max() << "." << std::endl;
                continue;
            }


            return static_cast<long>(n_ll);
        } catch (const std::invalid_argument& e) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Not a valid long integer." << std::endl;
        } catch (const std::out_of_range& e) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Input out of range. Please enter a valid long integer between " << std::numeric_limits<long>::min() << " and " << std::numeric_limits<long>::max() << "." << std::endl;
        }
    }
}

float get_float(const char *prompt)
{
    const char *current_prompt = prompt;
    while (true)
    {
        std::string line = get_string(current_prompt);
        if (line.empty() && (std::cin.eof() || std::cin.fail())) {
            std::cerr << "\nInput error or EOF encountered. Cannot get float." << std::endl;
            return 0.0f;
        }

        if (line.empty()) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Please enter a floating-point number." << std::endl;
            continue;
        }

        try {
            size_t pos;
            // Use stod first to potentially handle wider ranges before narrowing
            double d = std::stod(line, &pos);

            while (pos < line.length() && std::isspace(static_cast<unsigned char>(line[pos]))) {
                pos++;
            }

            if (pos != line.length()) {
                if (current_prompt == nullptr) current_prompt = "Retry: ";
                std::cout << "Invalid input. Trailing characters found after floating-point number." << std::endl;
                continue;
            }

            // Check if the value fits within float limits (approximate check)
            if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max()) {
                 if (d != 0.0 && !std::isinf(d) && (std::fabs(d) < std::numeric_limits<float>::min())) {
                    // Handle underflow - treat as 0? Or reprompt? Reprompting is safer.
                     if (current_prompt == nullptr) current_prompt = "Retry: ";
                    std::cout << "Input magnitude too small for float type (underflow)." << std::endl;
                    continue;
                 } else if (!std::isinf(d)) { // Check for overflow only if not already infinite
                    if (current_prompt == nullptr) current_prompt = "Retry: ";
                    std::cout << "Input out of range for float type (overflow)." << std::endl;
                    continue;
                 }
            }


            return static_cast<float>(d);
        } catch (const std::invalid_argument& e) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Not a valid floating-point number." << std::endl;
        } catch (const std::out_of_range& e) {
             // This catch might be for stod if the number is too large/small for double
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Input out of range for internal parsing or float type. Please enter a valid float." << std::endl;
        }
    }
}


double get_double(const char *prompt)
{
    const char *current_prompt = prompt;
    while (true)
    {
        std::string line = get_string(current_prompt);
        if (line.empty() && (std::cin.eof() || std::cin.fail())) {
            std::cerr << "\nInput error or EOF encountered. Cannot get double." << std::endl;
            return 0.0;
        }

        if (line.empty()) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Please enter a double-precision number." << std::endl;
            continue;
        }

        try {
            size_t pos;
            // Use stold for potentially wider range check if needed, though stod handles double
            long double ld = std::stold(line, &pos);

            while (pos < line.length() && std::isspace(static_cast<unsigned char>(line[pos]))) {
                pos++;
            }

            if (pos != line.length()) {
                if (current_prompt == nullptr) current_prompt = "Retry: ";
                std::cout << "Invalid input. Trailing characters found after double-precision number." << std::endl;
                continue;
            }

             // Check if the value fits within double limits (approximate check)
            if (ld > std::numeric_limits<double>::max() || ld < -std::numeric_limits<double>::max()) {
                 // *** Use fabsl (global scope) instead of std::fabsl ***
                 if (ld != 0.0l && !std::isinf(ld) && (fabsl(ld) < std::numeric_limits<double>::min())) {
                     if (current_prompt == nullptr) current_prompt = "Retry: ";
                    std::cout << "Input magnitude too small for double type (underflow)." << std::endl;
                    continue;
                 } else if (!std::isinf(ld)) {
                    if (current_prompt == nullptr) current_prompt = "Retry: ";
                    std::cout << "Input out of range for double type (overflow)." << std::endl;
                    continue;
                 }
            }


            return static_cast<double>(ld);
        } catch (const std::invalid_argument& e) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Not a valid double-precision number." << std::endl;
        } catch (const std::out_of_range& e) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Input out of range. Please enter a valid double-precision number within double limits." << std::endl;
        }
    }
}

// ... (get_int_range, get_string_non_empty remain the same) ...
int get_int_range(const char *prompt, int min_val, int max_val) {
    if (min_val > max_val) {
        std::cerr << "Error in get_int_range: min_val (" << min_val
                  << ") cannot be greater than max_val (" << max_val << ")." << std::endl;
        // Or swap them? For now, return min_val as an error indicator might be confusing.
        // Let's throw or return a sentinel? Sticking to return for now.
        return min_val; // Or perhaps throw std::invalid_argument
    }

    const char *current_prompt = prompt;
    std::string range_prompt_suffix = " (between " + std::to_string(min_val) + " and " + std::to_string(max_val) + "): ";
    std::string full_prompt;

    if (prompt) {
        full_prompt = std::string(prompt) + range_prompt_suffix;
    } else {
        full_prompt = "Enter an integer" + range_prompt_suffix;
    }


    while (true) {
        int value = get_int(full_prompt.c_str()); // Use existing get_int for validation

        // Check if get_int failed due to EOF/error
        if (std::cin.eof() || std::cin.fail()) {
             // get_int already printed an error, just return something
             return min_val; // Or a specific error code if preferred
        }


        if (value >= min_val && value <= max_val) {
            return value;
        } else {
            std::cout << "Input out of range. Please enter a value between "
                      << min_val << " and " << max_val << "." << std::endl;
            // Prepare for retry - get_int might have set current_prompt to "Retry: "
            // We want our specific range prompt again.
            if (prompt) {
                full_prompt = std::string(prompt) + range_prompt_suffix;
            } else {
                 full_prompt = "Retry: Enter an integer" + range_prompt_suffix;
            }

        }
    }
}

std::string get_string_non_empty(const char *prompt) {
    const char *current_prompt = prompt;
    while (true) {
        std::string line = get_string(current_prompt);

        if (line.empty() && (std::cin.eof() || std::cin.fail())) {
            std::cerr << "\nInput error or EOF encountered. Cannot get non-empty string." << std::endl;
            return ""; // Return empty on error/EOF
        }

        if (!line.empty()) {
            return line;
        }

        if (current_prompt == nullptr) {
            current_prompt = "Retry: ";
        }
        std::cout << "Input cannot be empty. Please enter some text." << std::endl;
    }
}

// --- Integer Array Functions ---
// ... (array_max, min, sum, hash table helpers, pair funcs, sort, print, contains, index_of, average, count, copy, reverse, shuffle, unique, concat remain the same) ...
bool array_max(const int *arr, size_t size, int *max_val) {
    if (arr == nullptr || max_val == nullptr || size == 0) {
        return false;
    }

    *max_val = arr[0];
    for (size_t i = 1; i < size; ++i) {
        if (arr[i] > *max_val) {
            *max_val = arr[i];
        }
    }
    return true;
}

bool array_min(const int *arr, size_t size, int *min_val) {
    if (arr == nullptr || min_val == nullptr || size == 0) {
        return false;
    }

    *min_val = arr[0];
    for (size_t i = 1; i < size; ++i) {
        if (arr[i] < *min_val) {
            *min_val = arr[i];
        }
    }
    return true;
}

bool array_sum(const int *arr, size_t size, long long *sum) {
    if (sum == nullptr) {
        return false;
    }
    *sum = 0; // Initialize sum
    if (size == 0) {
        return true; // Sum of empty array is 0
    }
     if (arr == nullptr) {
        // Sum of null array (with non-zero size implied) is undefined/error
        return false;
    }


    long long current_sum = 0;
    for (size_t i = 0; i < size; ++i) {
        // Check for potential overflow before adding
        if ((arr[i] > 0 && current_sum > std::numeric_limits<long long>::max() - arr[i]) ||
            (arr[i] < 0 && current_sum < std::numeric_limits<long long>::min() - arr[i])) {
            std::cerr << "Warning: Potential integer overflow detected during array_sum." << std::endl;
            // *sum = current_sum; // Return sum up to the point of overflow? Or just fail? Failing seems safer.
            return false; // Indicate overflow failure
        }
        current_sum += arr[i];
    }
    *sum = current_sum;
    return true;
}

// --- Hash Table Helper (Internal - for pair functions) ---
// Kept from original code for pair functions
struct HashNode {
    int key;
    int count; // Now used for count tracking
    HashNode *next;
};

struct HashTable {
    HashNode **buckets;
    size_t table_size;
};

static size_t hash_func(int key, size_t table_size) {
     // Simple modulo hash, handle negative keys reasonably
    unsigned long long temp_key = static_cast<unsigned long long>(std::llabs(static_cast<long long>(key)));
    return temp_key % table_size;
}

static HashTable* ht_create(size_t initial_size) {
    if (initial_size == 0) initial_size = 16; // Default size

    HashTable *ht = static_cast<HashTable*>(std::malloc(sizeof(HashTable)));
    if (!ht) {
        perror("Failed to allocate memory for HashTable");
        return nullptr;
    }

    // Use calloc to zero-initialize buckets (all pointers will be NULL)
    ht->buckets = static_cast<HashNode**>(std::calloc(initial_size, sizeof(HashNode*)));
    if (!ht->buckets) {
        perror("Failed to allocate memory for HashTable buckets");
        std::free(ht);
        return nullptr;
    }
    ht->table_size = initial_size;
    return ht;
}

static void ht_destroy(HashTable *ht) {
    if (!ht) return;
    for (size_t i = 0; i < ht->table_size; ++i) {
        HashNode *current = ht->buckets[i];
        while (current) {
            HashNode *temp = current;
            current = current->next;
            std::free(temp);
        }
    }
    std::free(ht->buckets);
    std::free(ht);
}

// Searches for a key, returns node if found, nullptr otherwise
static HashNode* ht_search(HashTable *ht, int key) {
    if (!ht || !ht->buckets) return nullptr;
    size_t index = hash_func(key, ht->table_size);
    HashNode *current = ht->buckets[index];
    while (current) {
        if (current->key == key) {
            return current; // Found
        }
        current = current->next;
    }
    return nullptr; // Not found
}

// Inserts a key. If key exists, increments count. Returns true on success, false on memory error.
static bool ht_insert(HashTable *ht, int key) {
    if (!ht || !ht->buckets) return false;

    HashNode* existing_node = ht_search(ht, key);
    if (existing_node) {
        existing_node->count++; // Increment count if key already exists
        return true;
    }

    // Key not found, create and insert a new node
    size_t index = hash_func(key, ht->table_size);
    HashNode *new_node = static_cast<HashNode*>(std::malloc(sizeof(HashNode)));
    if (!new_node) {
        perror("Failed to allocate memory for HashNode");
        return false; // Insertion failed
    }

    new_node->key = key;
    new_node->count = 1; // First occurrence
    new_node->next = ht->buckets[index]; // Insert at the beginning of the list
    ht->buckets[index] = new_node;
    return true; // Insertion successful
}
// --- End Hash Table Helper ---


bool array_has_pair_sum(const int *arr, size_t size, int target) {
    if (arr == nullptr || size < 2) {
        return false;
    }

    // Use a hash table (set) for O(n) average time complexity
    size_t ht_size = (size > 0) ? size : 16; // Estimate hash table size
    HashTable *ht = ht_create(ht_size);
    if (!ht) {
        std::cerr << "Error: Failed to create hash table in array_has_pair_sum." << std::endl;
        return false; // Indicate error
    }

    bool found = false;
    for (size_t i = 0; i < size; ++i) {
        // Calculate complement carefully to avoid overflow issues
        long long complement_ll = static_cast<long long>(target) - arr[i];

        // Check if complement fits within int range before casting
        if (complement_ll < std::numeric_limits<int>::min() || complement_ll > std::numeric_limits<int>::max()) {
            // If complement is out of range, it can't be in the int array
            // Still need to insert the current element for future checks
            if (!ht_insert(ht, arr[i])) {
                 std::cerr << "Error: Failed to insert into hash table in array_has_pair_sum." << std::endl;
                 // Clean up and indicate failure
                 found = false; // Ensure found is false
                 break; // Exit loop on hash table error
             }
            continue; // Move to the next element
        }
        int complement = static_cast<int>(complement_ll);

        HashNode* complement_node = ht_search(ht, complement);
        if (complement_node) {
            // Found the complement in the hash table
            // We need to ensure we aren't using the same element twice if complement == arr[i]
            if (complement == arr[i]) {
                // If the complement is the same as the current number,
                // we need at least two occurrences of this number.
                // The ht_insert function increments count, so check if count > 1 AFTER inserting.
                // However, we search *before* inserting the current element.
                // If complement_node is found, it means a *previous* element was the complement.
                // If that previous element was arr[i], its count would be >= 1 already.
                // So, finding it means we have found a pair.
                found = true;
                break; // Pair found, exit loop
            } else {
                // Complement is different from arr[i], pair found
                found = true;
                break; // Pair found, exit loop
            }
        }

        // Insert the current element into the hash table for subsequent checks
        if (!ht_insert(ht, arr[i])) {
            std::cerr << "Error: Failed to insert into hash table in array_has_pair_sum." << std::endl;
            found = false; // Ensure found is false
            break; // Exit loop on hash table error
        }
    }

    ht_destroy(ht); // Clean up hash table
    return found;
}

bool array_has_pair_product(const int *arr, size_t size, int target) {
     if (arr == nullptr || size < 2) {
        return false;
    }

    size_t ht_size = (size > 0) ? size : 16;
    HashTable *ht = ht_create(ht_size);
    if (!ht) {
        std::cerr << "Error: Failed to create hash table in array_has_pair_product." << std::endl;
        return false;
    }

    bool found = false;
    size_t zero_count = 0;

    // First pass: Populate hash table and count zeros
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == 0) {
            zero_count++;
        } else {
            // Insert non-zero elements into hash table
            if (!ht_insert(ht, arr[i])) {
                std::cerr << "Error: Failed to insert into hash table in array_has_pair_product (pass 1)." << std::endl;
                ht_destroy(ht);
                return false;
            }
        }
    }

    // Check cases involving zero
    if (target == 0) {
        // Need one zero and at least one non-zero OR at least two zeros
        bool has_non_zero = false;
        // Check if hash table has any entries (meaning non-zero elements existed)
        for(size_t i = 0; i < ht->table_size; ++i) {
            if (ht->buckets[i] != nullptr) {
                has_non_zero = true;
                break;
            }
        }

        if (zero_count > 0 && has_non_zero) {
            found = true;
        } else if (zero_count >= 2) {
            found = true;
        }
    } else { // Target is non-zero
        // If target is non-zero, we cannot use any zeros from the array.
        // Iterate through the original array again (or hash table keys)
        for (size_t i = 0; i < size; ++i) {
             int current_val = arr[i];
             if (current_val == 0) continue; // Skip zeros

            // Check if current_val is a divisor of target
            if (target % current_val == 0) {
                int needed = target / current_val;

                // Search for the 'needed' value in the hash table
                HashNode *needed_node = ht_search(ht, needed);

                if (needed_node) {
                    // Found the needed value. Ensure we are not using the same element twice.
                    if (needed == current_val) {
                        // If needed is the same as current_val, we need at least two occurrences.
                        // The count in the hash node tells us how many times 'needed' appeared.
                        if (needed_node->count > 1) {
                            found = true;
                            break; // Found pair
                        }
                        // If count is 1, it means we only saw this value once (the current one), so no pair yet.
                    } else {
                        // Needed value is different from current_val. We found a pair.
                        found = true;
                        break; // Found pair
                    }
                }
            }
        }
    }

    ht_destroy(ht);
    return found;
}


bool array_has_pair_difference(const int *arr, size_t size, int target) {
     if (arr == nullptr || size < 2) {
        return false;
    }
    // Allow target == 0 (means finding duplicate elements)

    size_t ht_size = (size > 0) ? size : 16;
    HashTable *ht = ht_create(ht_size);
    if (!ht) {
        std::cerr << "Error: Failed to create hash table in array_has_pair_difference." << std::endl;
        return false;
    }

    bool found = false;
    for (size_t i = 0; i < size; ++i) {
        int current_val = arr[i];

        // Check if (current_val - target) exists in the hash table
        long long needed1_ll = static_cast<long long>(current_val) - target;
        if (needed1_ll >= std::numeric_limits<int>::min() && needed1_ll <= std::numeric_limits<int>::max()) {
            int needed1 = static_cast<int>(needed1_ll);
            HashNode* node1 = ht_search(ht, needed1);
            if (node1) {
                // Found an element `x` such that current_val - x = target
                // If target is 0, need count > 1 check? No, ht_search finds *previous* elements.
                // If we find needed1 = current_val (when target is 0), it means current_val was inserted before.
                found = true;
                break;
            }
        }

        // Check if (current_val + target) exists in the hash table
        // This covers the case where x - current_val = target
        long long needed2_ll = static_cast<long long>(current_val) + target;
         if (needed2_ll >= std::numeric_limits<int>::min() && needed2_ll <= std::numeric_limits<int>::max()) {
            int needed2 = static_cast<int>(needed2_ll);
            HashNode* node2 = ht_search(ht, needed2);
            if (node2) {
                 // Found an element `x` such that x - current_val = target
                // If target is 0, this check is redundant with the first one, but harmless.
                found = true;
                break;
            }
        }


        // Insert current value into the hash table for future checks
        if (!ht_insert(ht, current_val)) {
            std::cerr << "Error: Failed to insert into hash table in array_has_pair_difference." << std::endl;
            found = false; // Ensure found is false
            break; // Exit loop on hash table error
        }
    }

    ht_destroy(ht);
    return found;
}

void sort_array(int arr[], size_t size) {
    if (arr == nullptr || size < 2) {
        return; // Nothing to sort
    }
    // Use std::sort (more robust than the original counting sort)
    std::sort(arr, arr + size);
}

void print_array(const int arr[], size_t size) {
    if (arr == nullptr) {
        std::cout << "nullptr" << std::endl;
        return;
    }
    std::cout << "[";
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

bool array_contains_int(const int *arr, size_t size, int value) {
    if (arr == nullptr || size == 0) {
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int array_index_of_int(const int *arr, size_t size, int value) {
     if (arr == nullptr || size == 0) {
        return -1;
    }
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == value) {
            // Check for potential overflow if size_t > max int, though unlikely
            if (i > static_cast<size_t>(std::numeric_limits<int>::max())) {
                 std::cerr << "Warning: Index found (" << i << ") exceeds maximum representable int value. Returning -1." << std::endl;
                 return -1;
            }
            return static_cast<int>(i);
        }
    }
    return -1; // Not found
}

bool array_average(const int *arr, size_t size, double *average) {
    if (arr == nullptr || average == nullptr || size == 0) {
        if(average) *average = 0.0; // Define average of empty/null array as 0?
        return false; // Indicate invalid input or empty array
    }

    long long sum_ll = 0;
    if (!array_sum(arr, size, &sum_ll)) {
        // array_sum failed (likely overflow), cannot calculate average reliably
        *average = 0.0; // Or std::nan?
        return false;
    }

    *average = static_cast<double>(sum_ll) / size;
    return true;
}

size_t array_count_occurrence(const int *arr, size_t size, int value) {
    if (arr == nullptr || size == 0) {
        return 0;
    }
    size_t count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

int* array_copy_int(const int *arr, size_t size) {
    if (arr == nullptr) {
        return nullptr;
    }
    if (size == 0) {
        // Return an empty allocation? Or nullptr? Let's return a valid pointer to 0 elements.
         int* new_arr = new (std::nothrow) int[0]; // Allocate 0 bytes, standard allows this
         return new_arr; // Caller should still delete[] this
    }

    int* new_arr = new (std::nothrow) int[size];
    if (new_arr == nullptr) {
        perror("Failed to allocate memory for array copy");
        return nullptr;
    }
    std::memcpy(new_arr, arr, size * sizeof(int));
    // Or using std::copy: std::copy(arr, arr + size, new_arr);
    return new_arr;
}

void array_reverse_int(int *arr, size_t size) {
    if (arr == nullptr || size < 2) {
        return; // Nothing to reverse
    }
    std::reverse(arr, arr + size);
}

void array_shuffle_int(int *arr, size_t size) {
     if (arr == nullptr || size < 2) {
        return; // Nothing to shuffle
    }
    if (!random_initialized) {
        initialize_random(); // Ensure seeded if not already done
    }
    std::shuffle(arr, arr + size, global_random_engine);
}

int* array_unique_int(const int *arr, size_t size, size_t *unique_size) {
     if (unique_size == nullptr) {
        std::cerr << "Error: unique_size pointer cannot be null." << std::endl;
        return nullptr;
     }
     *unique_size = 0; // Initialize output size

     if (arr == nullptr) {
         return nullptr; // Cannot process null array
     }
     if (size == 0) {
         int* new_arr = new (std::nothrow) int[0]; // Return valid pointer to 0 elements
         return new_arr;
     }

    std::set<int> unique_set(arr, arr + size);

    *unique_size = unique_set.size();
    int* result = new (std::nothrow) int[*unique_size];
    if (!result) {
        perror("Failed to allocate memory for unique array");
        *unique_size = 0;
        return nullptr;
    }

    std::copy(unique_set.begin(), unique_set.end(), result);

    return result;
}

int* array_concat_int(const int *arr1, size_t size1, const int *arr2, size_t size2, size_t *new_size) {
     if (new_size == nullptr) {
          std::cerr << "Error: new_size pointer cannot be null." << std::endl;
         return nullptr;
     }
     *new_size = 0;

     // Check for potential overflow when calculating total size
     if (size1 > std::numeric_limits<size_t>::max() - size2) {
         std::cerr << "Error: Combined size exceeds maximum possible size_t value." << std::endl;
         return nullptr;
     }
     size_t total_size = size1 + size2;
     *new_size = total_size;

     if (total_size == 0) {
         int* new_arr = new (std::nothrow) int[0]; // Return valid pointer to 0 elements
         return new_arr;
     }

     int* result = new (std::nothrow) int[total_size];
     if (!result) {
         perror("Failed to allocate memory for concatenated array");
         *new_size = 0;
         return nullptr;
     }

     // Copy first array (if exists and size > 0)
     if (arr1 != nullptr && size1 > 0) {
         std::memcpy(result, arr1, size1 * sizeof(int));
     }

     // Copy second array (if exists and size > 0) starting after the first
     if (arr2 != nullptr && size2 > 0) {
         std::memcpy(result + size1, arr2, size2 * sizeof(int));
     }

     return result;
}

// --- Float Array Functions ---

// *** REMOVED static inline floats_are_close - moved to header ***

// ... (max, min, sum, average, sort, contains, index_of, count, copy, print, reverse, shuffle, concat for float remain the same, they use the inline func from header) ...
bool array_max_float(const std::vector<float>& vec, float* max_val) {
    if (vec.empty() || max_val == nullptr) {
        return false;
    }
    *max_val = *std::max_element(vec.begin(), vec.end());
    return true;
}

bool array_min_float(const std::vector<float>& vec, float* min_val) {
     if (vec.empty() || min_val == nullptr) {
        return false;
    }
    *min_val = *std::min_element(vec.begin(), vec.end());
    return true;
}

bool array_sum_float(const std::vector<float>& vec, double* sum) {
    if (sum == nullptr) {
        return false;
    }
    // Use double for accumulation to minimize precision errors
    *sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    return true;
}

bool array_average_float(const std::vector<float>& vec, double* average) {
    if (vec.empty() || average == nullptr) {
        if (average) *average = 0.0;
        return false;
    }
    double sum = 0.0;
    if (!array_sum_float(vec, &sum)) { // Should not fail if average != nullptr
         *average = 0.0; // Or NaN?
        return false; // Should be unreachable if vec not empty and average not null
    }
    *average = sum / vec.size();
    return true;
}

void array_sort_float(std::vector<float>& vec) {
    std::sort(vec.begin(), vec.end());
}

bool array_contains_float(const std::vector<float>& vec, float value, float epsilon) {
    for (float element : vec) {
        if (floats_are_close(element, value, epsilon)) { // Uses inline from header
            return true;
        }
    }
    return false;
}

long long array_index_of_float(const std::vector<float>& vec, float value, float epsilon) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (floats_are_close(vec[i], value, epsilon)) { // Uses inline from header
             // Check potential overflow before casting size_t to long long (extremely unlikely)
            if (i > static_cast<size_t>(std::numeric_limits<long long>::max())) {
                 std::cerr << "Warning: Index found (" << i << ") exceeds maximum representable long long value. Returning -1." << std::endl;
                 return -1LL;
            }
            return static_cast<long long>(i);
        }
    }
    return -1LL; // Not found
}

size_t array_count_occurrence_float(const std::vector<float>& vec, float value, float epsilon) {
    size_t count = 0;
    for (float element : vec) {
        if (floats_are_close(element, value, epsilon)) { // Uses inline from header
            count++;
        }
    }
    return count;
}

std::vector<float> array_copy_float(const std::vector<float>& vec) {
    return vec; // Vector copy constructor handles this
}

void array_print_float(const std::vector<float>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void array_reverse_float(std::vector<float>& vec) {
    std::reverse(vec.begin(), vec.end());
}

void array_shuffle_float(std::vector<float>& vec) {
     if (vec.size() < 2) return;
     if (!random_initialized) initialize_random();
     std::shuffle(vec.begin(), vec.end(), global_random_engine);
}

std::vector<float> array_concat_float(const std::vector<float>& vec1, const std::vector<float>& vec2) {
    std::vector<float> result = vec1; // Start with a copy of vec1
    result.insert(result.end(), vec2.begin(), vec2.end()); // Append vec2
    return result;
}


// --- Double Array Functions ---

// *** REMOVED static inline doubles_are_close - moved to header ***

// ... (max, min, sum, average, sort, contains, index_of, count, copy, print, reverse, shuffle, concat for double remain the same) ...
bool array_max_double(const std::vector<double>& vec, double* max_val) {
    if (vec.empty() || max_val == nullptr) {
        return false;
    }
    *max_val = *std::max_element(vec.begin(), vec.end());
    return true;
}

bool array_min_double(const std::vector<double>& vec, double* min_val) {
     if (vec.empty() || min_val == nullptr) {
        return false;
    }
    *min_val = *std::min_element(vec.begin(), vec.end());
    return true;
}

bool array_sum_double(const std::vector<double>& vec, double* sum) {
    if (sum == nullptr) {
        return false;
    }
    *sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    return true;
}

bool array_average_double(const std::vector<double>& vec, double* average) {
    if (vec.empty() || average == nullptr) {
        if (average) *average = 0.0;
        return false;
    }
    double sum = 0.0;
     if (!array_sum_double(vec, &sum)) {
         *average = 0.0;
         return false;
     }
    *average = sum / vec.size();
    return true;
}

void array_sort_double(std::vector<double>& vec) {
    std::sort(vec.begin(), vec.end());
}

bool array_contains_double(const std::vector<double>& vec, double value, double epsilon) {
     for (double element : vec) {
        if (doubles_are_close(element, value, epsilon)) { // Uses inline from header
            return true;
        }
    }
    return false;
}

long long array_index_of_double(const std::vector<double>& vec, double value, double epsilon) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (doubles_are_close(vec[i], value, epsilon)) { // Uses inline from header
             if (i > static_cast<size_t>(std::numeric_limits<long long>::max())) {
                 std::cerr << "Warning: Index found (" << i << ") exceeds maximum representable long long value. Returning -1." << std::endl;
                 return -1LL;
            }
            return static_cast<long long>(i);
        }
    }
    return -1LL; // Not found
}

size_t array_count_occurrence_double(const std::vector<double>& vec, double value, double epsilon) {
    size_t count = 0;
    for (double element : vec) {
        if (doubles_are_close(element, value, epsilon)) { // Uses inline from header
            count++;
        }
    }
    return count;
}

std::vector<double> array_copy_double(const std::vector<double>& vec) {
    return vec;
}

void array_print_double(const std::vector<double>& vec) {
     std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void array_reverse_double(std::vector<double>& vec) {
    std::reverse(vec.begin(), vec.end());
}

void array_shuffle_double(std::vector<double>& vec) {
    if (vec.size() < 2) return;
    if (!random_initialized) initialize_random();
    std::shuffle(vec.begin(), vec.end(), global_random_engine);
}

std::vector<double> array_concat_double(const std::vector<double>& vec1, const std::vector<double>& vec2) {
    std::vector<double> result = vec1;
    result.insert(result.end(), vec2.begin(), vec2.end());
    return result;
}


// --- String Array Functions ---
// ... (find_string C-style, max, min, sort, contains, index_of, count, copy, print, reverse, shuffle, concat for string remain the same) ...
// Existing C-style find_string
int find_string(char * const arr_of_strings[], size_t size, const char *target_string) {
    if (arr_of_strings == nullptr || target_string == nullptr) {
        return -1;
    }

    for (size_t i = 0; i < size; ++i) {
        // Ensure the pointer in the array is not null before comparing
        if (arr_of_strings[i] != nullptr && std::strcmp(arr_of_strings[i], target_string) == 0) {
             if (i > static_cast<size_t>(std::numeric_limits<int>::max())) {
                 std::cerr << "Warning: Index found (" << i << ") exceeds maximum representable int value. Returning -1." << std::endl;
                 return -1;
            }
            return static_cast<int>(i);
        }
    }
    return -1; // Not found
}

// New std::vector<std::string> functions
bool array_max_string(const std::vector<std::string>& vec, std::string* max_val) {
    if (vec.empty() || max_val == nullptr) {
        return false;
    }
    // std::max_element uses operator<, which is lexicographical for std::string
    *max_val = *std::max_element(vec.begin(), vec.end());
    return true;
}

bool array_min_string(const std::vector<std::string>& vec, std::string* min_val) {
    if (vec.empty() || min_val == nullptr) {
        return false;
    }
    *min_val = *std::min_element(vec.begin(), vec.end());
    return true;
}

void array_sort_string(std::vector<std::string>& vec) {
    std::sort(vec.begin(), vec.end()); // Lexicographical sort
}

bool array_contains_string(const std::vector<std::string>& vec, const std::string& value) {
    // std::find uses operator== for std::string
    return std::find(vec.begin(), vec.end(), value) != vec.end();
}

long long array_index_of_string(const std::vector<std::string>& vec, const std::string& value) {
    auto it = std::find(vec.begin(), vec.end(), value);
    if (it != vec.end()) {
        size_t index = std::distance(vec.begin(), it);
        if (index > static_cast<size_t>(std::numeric_limits<long long>::max())) {
            std::cerr << "Warning: Index found (" << index << ") exceeds maximum representable long long value. Returning -1." << std::endl;
            return -1LL;
        }
        return static_cast<long long>(index);
    }
    return -1LL; // Not found
}

size_t array_count_occurrence_string(const std::vector<std::string>& vec, const std::string& value) {
    // std::count uses operator==
    return std::count(vec.begin(), vec.end(), value);
}

std::vector<std::string> array_copy_string(const std::vector<std::string>& vec) {
    return vec; // Vector copy constructor performs deep copy of strings
}

void array_print_string(const std::vector<std::string>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        // Consider quoting strings if they might contain commas or brackets?
        std::cout << "\"" << vec[i] << "\""; // Basic quoting
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void array_reverse_string(std::vector<std::string>& vec) {
    std::reverse(vec.begin(), vec.end());
}

void array_shuffle_string(std::vector<std::string>& vec) {
    if (vec.size() < 2) return;
    if (!random_initialized) initialize_random();
    std::shuffle(vec.begin(), vec.end(), global_random_engine);
}

std::vector<std::string> array_concat_string(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2) {
    std::vector<std::string> result = vec1;
    result.insert(result.end(), vec2.begin(), vec2.end());
    return result;
}

// --- String Manipulation Functions ---
// ... (copy, equals, trim remain the same) ...
std::string string_copy(const std::string& str) {
    return str; // std::string assignment/copy constructor handles this
}

bool string_equals(const std::string& str1, const std::string& str2) {
    return str1 == str2;
}

std::string string_trim(const std::string& str) {
    const char* whitespace = " \t\n\r\f\v";
    size_t first = str.find_first_not_of(whitespace);
    if (first == std::string::npos) {
        return ""; // String is all whitespace
    }
    size_t last = str.find_last_not_of(whitespace);
    return str.substr(first, (last - first + 1));
}


bool string_is_int(const std::string& str) {
    std::string trimmed = string_trim(str);
    if (trimmed.empty()) {
        return false;
    }
    size_t pos = 0;
    try {
        // Use stol/stoll for parsing check, but check for trailing characters
        // *** REMOVED [[maybe_unused]] attribute ***
        long long val = std::stoll(trimmed, &pos);
         // Ensure the entire string was consumed by stoll
         return pos == trimmed.length();
    } catch (const std::invalid_argument&) {
        return false; // Not a number
    } catch (const std::out_of_range&) {
        return false; // Number is valid format but outside long long range
    }
    // Should not be reached
    return false;
}

// ... (is_alpha, is_digit, is_alnum, is_space, is_empty, concat, substring, find_char, find_substring, replace_char, to_lower, to_upper, split, join, starts_with, ends_with, to_float remain the same) ...
bool string_is_alpha(const std::string& str) {
    if (str.empty()) return false; // Or true depending on definition? Usually false.
    return std::all_of(str.begin(), str.end(), ::isalpha);
}

bool string_is_digit(const std::string& str) {
     if (str.empty()) return false;
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool string_is_alnum(const std::string& str) {
     if (str.empty()) return false;
    return std::all_of(str.begin(), str.end(), ::isalnum);
}

bool string_is_space(const std::string& str) {
     if (str.empty()) return false; // Or true? Let's say false.
    return std::all_of(str.begin(), str.end(), ::isspace);
}

bool string_is_empty(const std::string& str) {
    return str.empty();
}

std::string string_concat(const std::string& str1, const std::string& str2) {
    return str1 + str2;
}

std::string string_substring(const std::string& str, size_t start, size_t length) {
    // std::string::substr handles bounds checking (throws out_of_range if start > size)
    // and automatically adjusts length if it goes past the end.
    try {
       return str.substr(start, length);
    } catch (const std::out_of_range& oor) {
        std::cerr << "Error: Substring start position (" << start << ") is out of range for string of length " << str.length() << "." << std::endl;
        return ""; // Return empty string on error
    }

}

long long string_find_char(const std::string& str, char c, size_t start_pos) {
    size_t pos = str.find(c, start_pos);
    if (pos == std::string::npos) {
        return -1LL;
    }
     if (pos > static_cast<size_t>(std::numeric_limits<long long>::max())) {
            std::cerr << "Warning: Index found (" << pos << ") exceeds maximum representable long long value. Returning -1." << std::endl;
            return -1LL;
     }
    return static_cast<long long>(pos);
}

long long string_find_substring(const std::string& haystack, const std::string& needle, size_t start_pos) {
    size_t pos = haystack.find(needle, start_pos);
     if (pos == std::string::npos) {
        return -1LL;
    }
      if (pos > static_cast<size_t>(std::numeric_limits<long long>::max())) {
            std::cerr << "Warning: Index found (" << pos << ") exceeds maximum representable long long value. Returning -1." << std::endl;
            return -1LL;
     }
    return static_cast<long long>(pos);
}

std::string string_replace_char(const std::string& str, char find, char replace) {
    std::string result = str;
    std::replace(result.begin(), result.end(), find, replace);
    return result;
}

std::string string_to_lower(const std::string& str) {
     std::string result = str;
     std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::tolower(c); });
     return result;
}

std::string string_to_upper(const std::string& str) {
    std::string result = str;
     std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::toupper(c); });
     return result;
}

std::vector<std::string> string_split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    // Handle case where the string might end with a delimiter (adds an empty token)
    // or if the string is empty (results in an empty vector, which is correct)
    return tokens;
}

std::string string_join(const std::vector<std::string>& parts, const std::string& separator) {
    std::string result;
    for (size_t i = 0; i < parts.size(); ++i) {
        result += parts[i];
        if (i < parts.size() - 1) {
            result += separator;
        }
    }
    return result;
}

bool string_starts_with(const std::string& str, const std::string& prefix) {
    // C++20 has str.starts_with()
    // Pre-C++20 implementation:
    return str.rfind(prefix, 0) == 0;
    // Or: return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
}

bool string_ends_with(const std::string& str, const std::string& suffix) {
    // C++20 has str.ends_with()
    // Pre-C++20 implementation:
     if (suffix.size() > str.size()) return false;
     return std::equal(suffix.rbegin(), suffix.rend(), str.rbegin());
    // Or: return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

bool string_to_float(const std::string& str, float* out_val) {
    if (out_val == nullptr) return false;
    std::string temp_str = string_trim(str); // Handle leading/trailing whitespace
    if (temp_str.empty()) return false;

    try {
        size_t pos;
        // Use stod for wider range check first
        double d = std::stod(temp_str, &pos);

        // Ensure entire string was consumed
        if (pos != temp_str.length()) {
            return false; // Trailing characters
        }

        // Check float range before assignment
        if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max()) {
            if (d != 0.0 && !std::isinf(d) && (std::fabs(d) < std::numeric_limits<float>::min())) {
                // Underflow - maybe acceptable as 0.0f? Let's return true but set 0.
                *out_val = 0.0f;
                return true; // Or false if underflow is an error
            } else if (!std::isinf(d)) { // Overflow
                return false;
            }
            // Allow Inf/-Inf through if that's the result of stod
        }

        *out_val = static_cast<float>(d);
        return true;
    } catch (const std::invalid_argument&) {
        return false; // Not a valid number format
    } catch (const std::out_of_range&) {
        return false; // Out of range for double (and thus definitely for float)
    }
}


bool string_to_double(const std::string& str, double* out_val) {
     if (out_val == nullptr) return false;
     std::string temp_str = string_trim(str);
     if (temp_str.empty()) return false;

    try {
        size_t pos;
        // Use stold for potentially wider range check if needed, though stod is usually fine
        long double ld = std::stold(temp_str, &pos);

        if (pos != temp_str.length()) {
            return false; // Trailing characters
        }

        // Check double range (less likely to fail than float, but good practice)
        if (ld > std::numeric_limits<double>::max() || ld < -std::numeric_limits<double>::max()) {
             // *** Use fabsl (global scope) instead of std::fabsl ***
             if (ld != 0.0l && !std::isinf(ld) && (fabsl(ld) < std::numeric_limits<double>::min())) {
                 // Underflow
                 *out_val = 0.0;
                 return true; // Or false?
             } else if (!std::isinf(ld)) { // Overflow
                return false;
             }
             // Allow Inf/-Inf
        }

        *out_val = static_cast<double>(ld);
        return true;
    } catch (const std::invalid_argument&) {
        return false;
    } catch (const std::out_of_range&) {
        // Out of range for long double
        return false;
    }
}


// --- Memory Management Helpers ---
// ... (free_string, free_string_array remain the same) ...
void free_string(char* str) {
    // Assumes str was allocated with malloc/calloc/strdup
    std::free(str);
}

void free_string_array(char** arr, size_t size) {
    // Assumes arr was allocated with malloc/calloc, and each arr[i] with malloc/calloc/strdup
    if (arr == nullptr) {
        return;
    }
    for (size_t i = 0; i < size; ++i) {
        std::free(arr[i]); // Free each individual string
    }
    std::free(arr); // Free the array of pointers
}

// --- Utility Functions ---
// ... (initialize_random, get_random_int, get_random_float, get_random_double, start_timer, stop_timer remain the same) ...
void initialize_random() {
    std::random_device rd; // Obtain a random number from hardware entropy source
    global_random_engine.seed(rd()); // Seed the Mersenne Twister engine
    random_initialized = true;
}

int get_random_int(int min_val, int max_val) {
    if (!random_initialized) {
        initialize_random();
    }
    if (min_val > max_val) {
        std::swap(min_val, max_val); // Handle incorrect order
    }
    std::uniform_int_distribution<int> distrib(min_val, max_val);
    return distrib(global_random_engine);
}

float get_random_float(float min_val, float max_val) {
     if (!random_initialized) {
        initialize_random();
    }
     if (min_val > max_val) {
        std::swap(min_val, max_val);
    }
    // Inclusive range for real distribution
    std::uniform_real_distribution<float> distrib(min_val, std::nextafter(max_val, std::numeric_limits<float>::infinity()));
    return distrib(global_random_engine);
}

double get_random_double(double min_val, double max_val) {
    if (!random_initialized) {
        initialize_random();
    }
     if (min_val > max_val) {
        std::swap(min_val, max_val);
    }
    std::uniform_real_distribution<double> distrib(min_val, std::nextafter(max_val, std::numeric_limits<double>::infinity()));
    return distrib(global_random_engine);
}

std::chrono::high_resolution_clock::time_point start_timer() {
    return std::chrono::high_resolution_clock::now();
}

double stop_timer(std::chrono::high_resolution_clock::time_point start_time) {
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;
    return elapsed.count(); // Return duration in seconds
}
