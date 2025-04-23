#ifndef ATOMIX_H
#define ATOMIX_H

#include <cstddef> // size_t
#include <string>  // std::string
#include <vector>  // std::vector
#include <limits>  // std::numeric_limits
#include <chrono>  // For timer
#include <cmath>   // For std::fabs in helper functions

// --- Constants ---
const float FLOAT_EPSILON = 1e-5f;
const double DOUBLE_EPSILON = 1e-9;

// --- Helper Functions (moved here and made inline) ---


inline bool floats_are_close(float a, float b, float epsilon = FLOAT_EPSILON) {
    // Consider also checking for infinity cases if necessary
    return std::fabs(a - b) <= epsilon;
}


inline bool doubles_are_close(double a, double b, double epsilon = DOUBLE_EPSILON) {
     // Consider also checking for infinity cases if necessary
    return std::fabs(a - b) <= epsilon;
}


// --- Input Functions ---
std::string get_string(const char *prompt = nullptr);
char get_char(const char *prompt = nullptr);
int get_int(const char *prompt = nullptr);
long get_long(const char *prompt = nullptr);
float get_float(const char *prompt = nullptr);
double get_double(const char *prompt = nullptr);
int get_int_range(const char *prompt, int min_val, int max_val);
std::string get_string_non_empty(const char *prompt = nullptr);

// --- Integer Array Functions ---
bool array_max(const int *arr, size_t size, int *max_val);
bool array_min(const int *arr, size_t size, int *min_val);
bool array_sum(const int *arr, size_t size, long long *sum);
bool array_has_pair_sum(const int *arr, size_t size, int target);
bool array_has_pair_product(const int *arr, size_t size, int target);
bool array_has_pair_difference(const int *arr, size_t size, int target);
void sort_array(int arr[], size_t size); // Uses std::sort now
void print_array(const int arr[], size_t size);
bool array_contains_int(const int *arr, size_t size, int value);
int array_index_of_int(const int *arr, size_t size, int value);
bool array_average(const int *arr, size_t size, double *average);
size_t array_count_occurrence(const int *arr, size_t size, int value);
int* array_copy_int(const int *arr, size_t size); // Caller must delete[] result
void array_reverse_int(int *arr, size_t size);
void array_shuffle_int(int *arr, size_t size);
int* array_unique_int(const int *arr, size_t size, size_t *unique_size); // Caller must delete[] result
int* array_concat_int(const int *arr1, size_t size1, const int *arr2, size_t size2, size_t *new_size); // Caller must delete[] result

// --- Float Array Functions (using std::vector) ---
bool array_max_float(const std::vector<float>& vec, float* max_val);
bool array_min_float(const std::vector<float>& vec, float* min_val);
bool array_sum_float(const std::vector<float>& vec, double* sum); // Use double for sum to avoid precision loss
bool array_average_float(const std::vector<float>& vec, double* average);
void array_sort_float(std::vector<float>& vec);
bool array_contains_float(const std::vector<float>& vec, float value, float epsilon = FLOAT_EPSILON);
long long array_index_of_float(const std::vector<float>& vec, float value, float epsilon = FLOAT_EPSILON); // Returns -1 if not found
size_t array_count_occurrence_float(const std::vector<float>& vec, float value, float epsilon = FLOAT_EPSILON);
std::vector<float> array_copy_float(const std::vector<float>& vec);
void array_print_float(const std::vector<float>& vec);
void array_reverse_float(std::vector<float>& vec);
void array_shuffle_float(std::vector<float>& vec);
std::vector<float> array_concat_float(const std::vector<float>& vec1, const std::vector<float>& vec2);

// --- Double Array Functions (using std::vector) ---
bool array_max_double(const std::vector<double>& vec, double* max_val);
bool array_min_double(const std::vector<double>& vec, double* min_val);
bool array_sum_double(const std::vector<double>& vec, double* sum);
bool array_average_double(const std::vector<double>& vec, double* average);
void array_sort_double(std::vector<double>& vec);
bool array_contains_double(const std::vector<double>& vec, double value, double epsilon = DOUBLE_EPSILON);
long long array_index_of_double(const std::vector<double>& vec, double value, double epsilon = DOUBLE_EPSILON); // Returns -1 if not found
size_t array_count_occurrence_double(const std::vector<double>& vec, double value, double epsilon = DOUBLE_EPSILON);
std::vector<double> array_copy_double(const std::vector<double>& vec);
void array_print_double(const std::vector<double>& vec);
void array_reverse_double(std::vector<double>& vec);
void array_shuffle_double(std::vector<double>& vec);
std::vector<double> array_concat_double(const std::vector<double>& vec1, const std::vector<double>& vec2);

// --- String Array Functions (using std::vector<std::string>) ---
int find_string(char * const arr_of_strings[], size_t size, const char *target_string); // Existing C-style
bool array_max_string(const std::vector<std::string>& vec, std::string* max_val); // Lexicographical max
bool array_min_string(const std::vector<std::string>& vec, std::string* min_val); // Lexicographical min
void array_sort_string(std::vector<std::string>& vec); // Lexicographical sort
bool array_contains_string(const std::vector<std::string>& vec, const std::string& value);
long long array_index_of_string(const std::vector<std::string>& vec, const std::string& value); // Returns -1 if not found
size_t array_count_occurrence_string(const std::vector<std::string>& vec, const std::string& value);
std::vector<std::string> array_copy_string(const std::vector<std::string>& vec); // Deep copy
void array_print_string(const std::vector<std::string>& vec);
void array_reverse_string(std::vector<std::string>& vec);
void array_shuffle_string(std::vector<std::string>& vec);
std::vector<std::string> array_concat_string(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2);

// --- String Manipulation Functions ---
std::string string_copy(const std::string& str);
bool string_equals(const std::string& str1, const std::string& str2);
std::string string_trim(const std::string& str);
bool string_is_int(const std::string& str);
bool string_is_alpha(const std::string& str);
bool string_is_digit(const std::string& str);
bool string_is_alnum(const std::string& str);
bool string_is_space(const std::string& str);
bool string_is_empty(const std::string& str);
std::string string_concat(const std::string& str1, const std::string& str2);
std::string string_substring(const std::string& str, size_t start, size_t length = std::string::npos);
long long string_find_char(const std::string& str, char c, size_t start_pos = 0); // Returns -1 if not found
long long string_find_substring(const std::string& haystack, const std::string& needle, size_t start_pos = 0); // Returns -1 if not found
std::string string_replace_char(const std::string& str, char find, char replace);
std::string string_to_lower(const std::string& str);
std::string string_to_upper(const std::string& str);
std::vector<std::string> string_split(const std::string& str, char delimiter);
std::string string_join(const std::vector<std::string>& parts, const std::string& separator);
bool string_starts_with(const std::string& str, const std::string& prefix);
bool string_ends_with(const std::string& str, const std::string& suffix);
bool string_to_float(const std::string& str, float* out_val);
bool string_to_double(const std::string& str, double* out_val);

// --- Memory Management Helpers ---
void free_string(char* str);
void free_string_array(char** arr, size_t size);

// --- Utility Functions ---
void initialize_random();
int get_random_int(int min_val, int max_val); // Inclusive range
float get_random_float(float min_val, float max_val); // Inclusive range approx
double get_random_double(double min_val, double max_val); // Inclusive range approx
std::chrono::high_resolution_clock::time_point start_timer();
double stop_timer(std::chrono::high_resolution_clock::time_point start_time); // Returns elapsed seconds


#endif // ATOMIX_H
