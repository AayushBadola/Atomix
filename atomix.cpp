#include "atomix.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cerrno>
#include <stdexcept>


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
            return "";
        }
        else if (std::cin.fail())
        {
            std::cerr << "Error: Input error in get_string." << std::endl;
            std::cin.clear();
            return "";
        }
        return "";
    }
}


char get_char(const char *prompt)
{
    const char *current_prompt = prompt;
    while (true)
    {
        std::string line = get_string(current_prompt);
        if (line.empty() && std::cin.eof())
        {
            std::cerr << "\nInput error or EOF encountered. Cannot get character." << std::endl;
            return '\0';
        }
        if (line.empty() && std::cin.fail()) {
             std::cerr << "\nInput error. Cannot get character." << std::endl;
             return '\0';
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
        if (line.empty() && std::cin.eof()) {
            std::cerr << "\nInput error or EOF encountered. Cannot get integer." << std::endl;
            return 0;
        }
         if (line.empty() && std::cin.fail()) {
            std::cerr << "\nInput error. Cannot get integer." << std::endl;
            return 0;
        }

        if (line.empty())
        {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            continue;
        }

        try
        {
            size_t pos;
            long n = std::stol(line, &pos);

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
            continue;
        }
        catch (const std::out_of_range& e)
        {
             if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Input out of range for long. Please enter a valid integer." << std::endl;
            continue;
        }
    }
}


long get_long(const char *prompt)
{
    const char *current_prompt = prompt;
    while (true)
    {
        std::string line = get_string(current_prompt);
        if (line.empty() && std::cin.eof()) {
            std::cerr << "\nInput error or EOF encountered. Cannot get long integer." << std::endl;
            return 0L;
        }
         if (line.empty() && std::cin.fail()) {
            std::cerr << "\nInput error. Cannot get long integer." << std::endl;
            return 0L;
        }

        if (line.empty()) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Please enter a long integer." << std::endl;
            continue;
        }

        try {
            size_t pos;
            long n = std::stol(line, &pos);

            while (pos < line.length() && std::isspace(static_cast<unsigned char>(line[pos]))) {
                pos++;
            }

            if (pos != line.length()) {
                if (current_prompt == nullptr) current_prompt = "Retry: ";
                std::cout << "Invalid input. Trailing characters found after long integer." << std::endl;
                continue;
            }

            return n;
        } catch (const std::invalid_argument& e) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Not a valid long integer." << std::endl;
            continue;
        } catch (const std::out_of_range& e) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Input out of range. Please enter a valid long integer between " << std::numeric_limits<long>::min() << " and " << std::numeric_limits<long>::max() << "." << std::endl;
            continue;
        }
    }
}


float get_float(const char *prompt)
{
    const char *current_prompt = prompt;
    while (true)
    {
        std::string line = get_string(current_prompt);
        if (line.empty() && std::cin.eof()) {
            std::cerr << "\nInput error or EOF encountered. Cannot get float." << std::endl;
            return 0.0f;
        }
         if (line.empty() && std::cin.fail()) {
            std::cerr << "\nInput error. Cannot get float." << std::endl;
            return 0.0f;
        }

        if (line.empty()) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Please enter a floating-point number." << std::endl;
            continue;
        }

        try {
            size_t pos;
            float f = std::stof(line, &pos);

            while (pos < line.length() && std::isspace(static_cast<unsigned char>(line[pos]))) {
                pos++;
            }

            if (pos != line.length()) {
                if (current_prompt == nullptr) current_prompt = "Retry: ";
                std::cout << "Invalid input. Trailing characters found after floating-point number." << std::endl;
                continue;
            }

            return f;
        } catch (const std::invalid_argument& e) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Not a valid floating-point number." << std::endl;
            continue;
        } catch (const std::out_of_range& e) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Input out of range. Please enter a valid floating-point number within float limits." << std::endl;
            continue;
        }
    }
}


double get_double(const char *prompt)
{
    const char *current_prompt = prompt;
    while (true)
    {
        std::string line = get_string(current_prompt);
        if (line.empty() && std::cin.eof()) {
            std::cerr << "\nInput error or EOF encountered. Cannot get double." << std::endl;
            return 0.0;
        }
        if (line.empty() && std::cin.fail()) {
            std::cerr << "\nInput error. Cannot get double." << std::endl;
            return 0.0;
        }

        if (line.empty()) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Please enter a double-precision number." << std::endl;
            continue;
        }

        try {
            size_t pos;
            double d = std::stod(line, &pos);

            while (pos < line.length() && std::isspace(static_cast<unsigned char>(line[pos]))) {
                pos++;
            }

            if (pos != line.length()) {
                if (current_prompt == nullptr) current_prompt = "Retry: ";
                std::cout << "Invalid input. Trailing characters found after double-precision number." << std::endl;
                continue;
            }

            return d;
        } catch (const std::invalid_argument& e) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Invalid input. Not a valid double-precision number." << std::endl;
            continue;
        } catch (const std::out_of_range& e) {
            if (current_prompt == nullptr) current_prompt = "Retry: ";
            std::cout << "Input out of range. Please enter a valid double-precision number within double limits." << std::endl;
            continue;
        }
    }
}


bool array_max(const int *arr, size_t size, int *max_val) {
    if (arr == nullptr || max_val == nullptr) {
        return false;
    }
    if (size == 0) {
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
    if (arr == nullptr || min_val == nullptr) {
        return false;
    }
    if (size == 0) {
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
    if (arr == nullptr && size > 0) {
        *sum = 0;
        return false;
    }
    if (arr == nullptr && size == 0) {
        *sum = 0;
        return true;
    }

    *sum = 0;
    long long current_sum = 0;
    for (size_t i = 0; i < size; ++i) {
        if ((arr[i] > 0 && current_sum > std::numeric_limits<long long>::max() - arr[i]) ||
            (arr[i] < 0 && current_sum < std::numeric_limits<long long>::min() - arr[i])) {
            std::cerr << "Warning: Potential integer overflow detected during array_sum." << std::endl;
            *sum = current_sum;
            return false;
        }
        current_sum += arr[i];
    }
    *sum = current_sum;
    return true;
}


struct HashNode {
    int key;
    int count;
    HashNode *next;
};

struct HashTable {
    HashNode **buckets;
    size_t table_size;
};


static size_t hash_func(int key, size_t table_size) {
    unsigned long long temp_key = static_cast<unsigned long long>(std::llabs(static_cast<long long>(key)));
    return temp_key % table_size;
}


static HashTable* ht_create(size_t initial_size) {
    if (initial_size == 0) initial_size = 16;

    HashTable *ht = static_cast<HashTable*>(std::malloc(sizeof(HashTable)));
    if (!ht) {
        perror("Failed to allocate memory for HashTable");
        return nullptr;
    }

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


static HashNode* ht_search(HashTable *ht, int key) {
    if (!ht || !ht->buckets) return nullptr;
    size_t index = hash_func(key, ht->table_size);
    HashNode *current = ht->buckets[index];
    while (current) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}


static bool ht_insert(HashTable *ht, int key) {
    if (!ht || !ht->buckets) return false;
    size_t index = hash_func(key, ht->table_size);
    HashNode *current = ht->buckets[index];

    while (current) {
        if (current->key == key) {
            current->count++;
            return true;
        }
        current = current->next;
    }

    HashNode *new_node = static_cast<HashNode*>(std::malloc(sizeof(HashNode)));
    if (!new_node) {
        perror("Failed to allocate memory for HashNode");
        return false;
    }

    new_node->key = key;
    new_node->count = 1;
    new_node->next = ht->buckets[index];
    ht->buckets[index] = new_node;
    return true;
}



bool array_has_pair_sum(const int *arr, size_t size, int target) {
    if (arr == nullptr || size < 2) {
        return false;
    }

    size_t ht_size = (size > 0) ? size : 16;
    HashTable *ht = ht_create(ht_size);
    if (!ht) {
        std::cerr << "Error: Failed to create hash table in array_has_pair_sum." << std::endl;
        return false;
    }

    bool found = false;
    for (size_t i = 0; i < size; ++i) {
        long long complement_ll = static_cast<long long>(target) - arr[i];

        if (complement_ll < std::numeric_limits<int>::min() || complement_ll > std::numeric_limits<int>::max()) {
            if (!ht_insert(ht, arr[i])) {
                 std::cerr << "Error: Failed to insert into hash table in array_has_pair_sum." << std::endl;
                 found = false;
                 break;
             }
            continue;
        }
        int complement = static_cast<int>(complement_ll);

        HashNode* complement_node = ht_search(ht, complement);
        if (complement_node) {
            if (complement == arr[i]) {
                if (complement_node->count >= 1) {
                    found = true;
                    break;
                }
            } else {
                found = true;
                break;
            }
        }

        if (!ht_insert(ht, arr[i])) {
            std::cerr << "Error: Failed to insert into hash table in array_has_pair_sum." << std::endl;
            found = false;
            break;
        }
    }

    ht_destroy(ht);
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

    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == 0) {
            zero_count++;
        } else {
            if (!ht_insert(ht, arr[i])) {
                std::cerr << "Error: Failed to insert into hash table in array_has_pair_product." << std::endl;
                ht_destroy(ht);
                return false;
            }
        }
    }

    if (target == 0) {
        bool has_non_zero = false;
        for(size_t i = 0; i < ht->table_size; ++i) {
            HashNode *node = ht->buckets[i];
            while(node) {
                has_non_zero = true;
                break;
            }
            if (has_non_zero) break;
        }

        if (zero_count > 0 && has_non_zero) {
            found = true;
        } else if (zero_count > 1) {
            found = true;
        }
    } else {
        for (size_t i = 0; i < ht->table_size; ++i) {
            HashNode *node = ht->buckets[i];
            while(node) {
                int current_val = node->key;

                if (current_val != 0 && target % current_val == 0) {
                    int needed = target / current_val;
                    HashNode *needed_node = ht_search(ht, needed);

                    if (needed_node) {
                        if (needed == current_val) {
                            if (needed_node->count > 1) {
                                found = true;
                                break;
                            }
                        } else {
                            found = true;
                            break;
                        }
                    }
                }
                node = node->next;
            }
            if (found) break;
        }
    }

    ht_destroy(ht);
    return found;
}


bool array_has_pair_difference(const int *arr, size_t size, int target) {
    if (arr == nullptr || size < 2) {
        return false;
    }

    size_t ht_size = (size > 0) ? size : 16;
    HashTable *ht = ht_create(ht_size);
    if (!ht) {
        std::cerr << "Error: Failed to create hash table in array_has_pair_difference." << std::endl;
        return false;
    }

    bool found = false;
    for (size_t i = 0; i < size; ++i) {
        int current_val = arr[i];

        long long needed1_ll = static_cast<long long>(current_val) - target;
        if (needed1_ll >= std::numeric_limits<int>::min() && needed1_ll <= std::numeric_limits<int>::max()) {
            int needed1 = static_cast<int>(needed1_ll);
            HashNode* node1 = ht_search(ht, needed1);
            if (node1) {
                found = true;
                break;
            }
        }

        if (target != 0) {
            long long needed2_ll = static_cast<long long>(current_val) + target;
            if (needed2_ll >= std::numeric_limits<int>::min() && needed2_ll <= std::numeric_limits<int>::max()) {
                int needed2 = static_cast<int>(needed2_ll);
                HashNode* node2 = ht_search(ht, needed2);
                if (node2) {
                        found = true;
                        break;
                }
            }
        }

        if (!ht_insert(ht, current_val)) {
            std::cerr << "Error: Failed to insert into hash table in array_has_pair_difference." << std::endl;
            found = false;
            break;
        }
    }

    ht_destroy(ht);
    return found;
}


void sort_array(int arr[], size_t size) {
    if (arr == nullptr || size < 2) {
        return;
    }

    int max_val;
    if (!array_max(arr, size, &max_val)) {
        std::cerr << "Error: Could not determine maximum value for sorting." << std::endl;
        return;
    }
    int min_val;
    if (!array_min(arr, size, &min_val)) {
        std::cerr << "Error: Could not determine minimum value for sorting." << std::endl;
        return;
    }

    if (min_val < 0) {
        std::cerr << "Warning: sort_array using Counting Sort is optimized for non-negative integers. Array contains negative values." << std::endl;
        return;
    }

    unsigned long long range_check = static_cast<unsigned long long>(max_val) + 1;
    if (range_check > std::numeric_limits<size_t>::max()) {
         std::cerr << "Error: Range of values (" << max_val << ") too large for counting sort memory allocation." << std::endl;
        return;
    }
    size_t range = static_cast<size_t>(max_val) + 1;

    size_t memory_limit_factor = 100;
    if (range > size * memory_limit_factor && size > 1024) {
        std::cerr << "Error: Range of values (" << range << ") significantly exceeds array size (" << size << "), potentially requiring excessive memory for counting sort." << std::endl;
        return;
    }


    int *count = static_cast<int*>(std::calloc(range, sizeof(int)));
    if (count == nullptr) {
        perror("Failed to allocate memory for count array in sort_array");
        return;
    }

    int *output = static_cast<int*>(std::malloc(size * sizeof(int)));
    if (output == nullptr) {
        perror("Failed to allocate memory for output array in sort_array");
        std::free(count);
        return;
    }

    for (size_t i = 0; i < size; ++i) {
         if (static_cast<unsigned long long>(arr[i]) >= range) {
             std::cerr << "Error: Array element " << arr[i] << " at index " << i << " is out of calculated range [0, " << max_val << "]." << std::endl;
             std::free(count);
             std::free(output);
             return;
         }
        count[arr[i]]++;
    }

    for (size_t i = 1; i < range; ++i) {
         if (static_cast<long long>(count[i-1]) > std::numeric_limits<int>::max() - count[i]) {
             std::cerr << "Error: Integer overflow calculating cumulative counts in sort_array." << std::endl;
             std::free(count);
             std::free(output);
             return;
         }
        count[i] += count[i - 1];
    }

    for (long long i = static_cast<long long>(size) - 1; i >= 0; --i) {
        if (static_cast<unsigned long long>(arr[i]) >= range || static_cast<size_t>(count[arr[i]]) == 0 || static_cast<size_t>(count[arr[i]]) > size) {
             std::cerr << "Error: Invalid index calculation during output placement in sort_array." << std::endl;
             std::free(count);
             std::free(output);
             return;
        }
        output[static_cast<size_t>(count[arr[i]]) - 1] = arr[i];
        count[arr[i]]--;
    }

    std::memcpy(arr, output, size * sizeof(int));

    std::free(count);
    std::free(output);
}


int find_string(char * const arr_of_strings[], size_t size, const char *target_string) {
    if (arr_of_strings == nullptr || target_string == nullptr) {
        return -1;
    }

    for (size_t i = 0; i < size; ++i) {
        if (arr_of_strings[i] != nullptr && std::strcmp(arr_of_strings[i], target_string) == 0) {
            return static_cast<int>(i);
        }
    }
    return -1;
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
