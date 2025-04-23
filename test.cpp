// atomix_test.cpp
// Basic test suite for Atomix Library v1.2.0

#include "atomix.h" // Include the library header
#include <iostream>
#include <vector>
#include <string>
#include <cmath>     // For fabs, NAN
#include <limits>    // For numeric_limits
#include <cassert>   // For basic assertions (optional, can use if/else)
#include <cstring>   // For memcmp
#include <thread>    // For std::this_thread::sleep_for (testing timer)
#include <chrono>    // For std::chrono::milliseconds
#include <algorithm> // For std::sort, std::equal (used in unique test)

// Use standard namespace for brevity
using namespace std;

// --- Helper Function ---
void print_test_result(const string& test_name, bool success) {
    cout << "Test: " << test_name << " - " << (success ? "PASSED" : "FAILED") << endl;
}

// --- Interactive Test Function ---
// Requires manual input to verify prompts, retries, and edge cases (like EOF).
void test_get_functions_interactive() {
    cout << "\n--- Testing get_* Functions (Manual Interaction Required) ---" << endl;
    cout << "Please follow the prompts and try various inputs, including:" << endl;
    cout << "  * Valid input" << endl;
    cout << "  * Invalid input (e.g., text for numbers, wrong number of chars)" << endl;
    cout << "  * Empty input (just press Enter)" << endl;
    cout << "  * Out-of-range values (too large/small)" << endl;
    cout << "  * Input with leading/trailing whitespace" << endl;
    cout << "  * End-of-File (EOF): Ctrl+Z then Enter (Windows) or Ctrl+D (Linux/macOS)" << endl;
    cout << "Verify that prompts, error messages, and retries behave as expected." << endl;
    cout << "---------------------------------------------------------------" << endl;


    // Test get_string
    cout << "\n[Interactive] Testing get_string..." << endl;
    string str_val = get_string("Enter any string (or EOF): ");
    cout << "           -> get_string returned: \"" << str_val << "\"" << endl;
    cin.clear(); // Clear EOF/fail state if triggered

    // Test get_char
    cout << "\n[Interactive] Testing get_char..." << endl;
    char char_val = get_char("Enter exactly one char (or EOF): ");
    cout << "           -> get_char returned: '" << char_val << "' (int: " << (int)char_val << ")" << endl;
    cin.clear();

    // Test get_int
    cout << "\n[Interactive] Testing get_int..." << endl;
    int int_val = get_int("Enter an integer (or EOF): ");
    cout << "           -> get_int returned: " << int_val << endl;
    cin.clear();

    // Test get_long
    cout << "\n[Interactive] Testing get_long..." << endl;
    long long_val = get_long("Enter a long integer (or EOF): ");
    cout << "           -> get_long returned: " << long_val << endl;
    cin.clear();

    // Test get_float
    cout << "\n[Interactive] Testing get_float..." << endl;
    float float_val = get_float("Enter a float (or EOF): ");
    cout << "           -> get_float returned: " << float_val << endl;
    cin.clear();

    // Test get_double
    cout << "\n[Interactive] Testing get_double..." << endl;
    double double_val = get_double("Enter a double (or EOF): ");
    cout << "           -> get_double returned: " << double_val << endl;
    cin.clear();

    // Test get_int_range
    cout << "\n[Interactive] Testing get_int_range(prompt, 1, 10)..." << endl;
    int range_val = get_int_range("Enter int [1-10] (or EOF): ", 1, 10);
    cout << "           -> get_int_range returned: " << range_val << endl;
    cin.clear();

    // Test get_string_non_empty
    cout << "\n[Interactive] Testing get_string_non_empty..." << endl;
    string non_empty = get_string_non_empty("Enter non-empty string (or EOF): ");
    cout << "           -> get_string_non_empty returned: \"" << non_empty << "\"" << endl;
    cin.clear(); // Clear potential EOF state for safety if more tests followed

    cout << "--- End Interactive Input Tests ---" << endl;
}

// --- Automated Test Functions ---

void test_integer_array_functions() {
    cout << "\n--- Testing Integer Array Functions ---" << endl;
    int arr1[] = {5, -2, 10, 0, 5, 8};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr_empty[] = {};
    size_t size_empty = 0;
    int arr_single[] = {42};
    size_t size_single = 1;

    // --- Analytics ---
    int max_v, min_v;
    long long sum_v;
    double avg_v;
    print_test_result("array_max (basic)", array_max(arr1, size1, &max_v) && max_v == 10);
    print_test_result("array_max (empty)", !array_max(arr_empty, size_empty, &max_v));
    print_test_result("array_max (single)", array_max(arr_single, size_single, &max_v) && max_v == 42);
    print_test_result("array_min (basic)", array_min(arr1, size1, &min_v) && min_v == -2);
    print_test_result("array_sum (basic)", array_sum(arr1, size1, &sum_v) && sum_v == 26);
    print_test_result("array_sum (empty)", array_sum(arr_empty, size_empty, &sum_v) && sum_v == 0);
    print_test_result("array_average (basic)", array_average(arr1, size1, &avg_v) && doubles_are_close(avg_v, 26.0 / 6.0));
    print_test_result("array_average (empty)", !array_average(arr_empty, size_empty, &avg_v) && avg_v == 0.0); // Expect false for empty

    // --- Search & Count ---
    print_test_result("array_contains_int (found)", array_contains_int(arr1, size1, 10));
    print_test_result("array_contains_int (not found)", !array_contains_int(arr1, size1, 99));
    print_test_result("array_contains_int (empty)", !array_contains_int(arr_empty, size_empty, 0));
    print_test_result("array_index_of_int (found first)", array_index_of_int(arr1, size1, 5) == 0);
    print_test_result("array_index_of_int (found last)", array_index_of_int(arr1, size1, 8) == 5);
    print_test_result("array_index_of_int (not found)", array_index_of_int(arr1, size1, 99) == -1);
    print_test_result("array_index_of_int (empty)", array_index_of_int(arr_empty, size_empty, 0) == -1);
    print_test_result("array_count_occurrence (found multiple)", array_count_occurrence(arr1, size1, 5) == 2);
    print_test_result("array_count_occurrence (found single)", array_count_occurrence(arr1, size1, 8) == 1);
    print_test_result("array_count_occurrence (not found)", array_count_occurrence(arr1, size1, 99) == 0);
    print_test_result("array_count_occurrence (empty)", array_count_occurrence(arr_empty, size_empty, 0) == 0);

    // --- Pair Checks ---
    print_test_result("array_has_pair_sum (found 5+0)", array_has_pair_sum(arr1, size1, 5));
    print_test_result("array_has_pair_sum (found 5+5)", array_has_pair_sum(arr1, size1, 10));
    print_test_result("array_has_pair_sum (not found)", !array_has_pair_sum(arr1, size1, 1));
    print_test_result("array_has_pair_product (found 5*0)", array_has_pair_product(arr1, size1, 0));
    print_test_result("array_has_pair_product (found 5*8)", array_has_pair_product(arr1, size1, 40));
    print_test_result("array_has_pair_product (found -2*10)", array_has_pair_product(arr1, size1, -20));
    print_test_result("array_has_pair_product (not found)", !array_has_pair_product(arr1, size1, 99));
    print_test_result("array_has_pair_difference (found 5-0)", array_has_pair_difference(arr1, size1, 5));
    print_test_result("array_has_pair_difference (found 8-5)", array_has_pair_difference(arr1, size1, 3));
    print_test_result("array_has_pair_difference (found 5-5)", array_has_pair_difference(arr1, size1, 0)); // requires duplicates
    print_test_result("array_has_pair_difference (not found)", !array_has_pair_difference(arr1, size1, 100));

    // --- Copy/Unique/Concat (Heap allocation) ---
    int* arr1_copy = array_copy_int(arr1, size1);
    bool copy_ok = (arr1_copy != nullptr && memcmp(arr1, arr1_copy, size1 * sizeof(int)) == 0);
    if (arr1_copy) arr1_copy[0] = 999; // Modify copy
    copy_ok = copy_ok && arr1_copy && (arr1[0] == 5); // Check original is unchanged
    print_test_result("array_copy_int (deep copy check)", copy_ok);
    delete[] arr1_copy;

    int* empty_copy = array_copy_int(arr_empty, size_empty);
    print_test_result("array_copy_int (empty source)", empty_copy != nullptr); // Should return valid ptr to 0 elements
    delete[] empty_copy;

    size_t unique_size = 0;
    int arr_uniq_src[] = {1, 2, 2, 3, 1, 4, 4, 5};
    int arr_uniq_expected[] = {1, 2, 3, 4, 5}; // Expected unique elements (sorted by std::set)
    int* unique_arr = array_unique_int(arr_uniq_src, 8, &unique_size);
    bool unique_ok = (unique_arr != nullptr && unique_size == 5);
    if (unique_ok) {
        // array_unique_int currently uses std::set, results are sorted
        // If implementation changes, might need to sort unique_arr before compare
        // std::sort(unique_arr, unique_arr + unique_size); // Uncomment if needed
        unique_ok = equal(unique_arr, unique_arr + unique_size, arr_uniq_expected);
    }
    print_test_result("array_unique_int (with duplicates)", unique_ok);
    delete[] unique_arr;

    int c1[] = {1, 2};
    int c2[] = {3, 4, 5};
    int c_exp[] = {1, 2, 3, 4, 5};
    size_t concat_size = 0;
    int* concat_arr = array_concat_int(c1, 2, c2, 3, &concat_size);
    bool concat_ok = (concat_arr != nullptr && concat_size == 5 && memcmp(concat_arr, c_exp, 5 * sizeof(int)) == 0);
    print_test_result("array_concat_int (two non-empty)", concat_ok);
    delete[] concat_arr;

    // --- In-place modification ---
    int arr_mod[] = {3, 1, 4, 2};
    int arr_mod_sorted[] = {1, 2, 3, 4};
    sort_array(arr_mod, 4); // Uses std::sort
    print_test_result("sort_array (basic)", memcmp(arr_mod, arr_mod_sorted, 4 * sizeof(int)) == 0);

    int arr_rev[] = {1, 2, 3, 4, 5};
    int arr_rev_expected[] = {5, 4, 3, 2, 1};
    array_reverse_int(arr_rev, 5);
    print_test_result("array_reverse_int (odd size)", memcmp(arr_rev, arr_rev_expected, 5 * sizeof(int)) == 0);

    int arr_shuf[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t size_shuf = 8;
    vector<int> shuf_before(arr_shuf, arr_shuf + size_shuf);
    array_shuffle_int(arr_shuf, size_shuf); // Uses std::shuffle
    vector<int> shuf_after(arr_shuf, arr_shuf + size_shuf);
    // Basic check: size and elements are the same (just rearranged)
    sort(shuf_before.begin(), shuf_before.end());
    sort(shuf_after.begin(), shuf_after.end());
    print_test_result("array_shuffle_int (elements preserved)", shuf_before == shuf_after);
    // Note: Verifying *true* randomness is complex and beyond this basic test.

    // --- Printing ---
    cout << "array_print demo: ";
    print_array(arr_single, size_single); // Expected: [42]
}

void test_float_double_vector_functions() {
    cout << "\n--- Testing Float/Double Vector Functions ---" << endl;
    // Define epsilon values for float/double comparisons
    float f_eps = numeric_limits<float>::epsilon() * 100;
    double d_eps = numeric_limits<double>::epsilon() * 100;

    // --- Float Tests ---
    vector<float> f_vec = {1.1f, -2.2f, 3.3f, 0.0f, 3.3f};
    vector<float> f_empty;
    float f_max, f_min;
    double f_sum, f_avg;

    print_test_result("array_max_float (basic)", array_max_float(f_vec, &f_max) && floats_are_close(f_max, 3.3f, f_eps));
    print_test_result("array_min_float (basic)", array_min_float(f_vec, &f_min) && floats_are_close(f_min, -2.2f, f_eps));
    print_test_result("array_sum_float (basic)", array_sum_float(f_vec, &f_sum) && doubles_are_close(f_sum, 1.1 - 2.2 + 3.3 + 0.0 + 3.3, d_eps));
    print_test_result("array_average_float (basic)", array_average_float(f_vec, &f_avg) && doubles_are_close(f_avg, (1.1 - 2.2 + 3.3 + 0.0 + 3.3)/5.0, d_eps));
    print_test_result("array_contains_float (found)", array_contains_float(f_vec, 3.3f, f_eps));
    print_test_result("array_contains_float (not found)", !array_contains_float(f_vec, 1.23f, f_eps));
    print_test_result("array_index_of_float (found first)", array_index_of_float(f_vec, 3.3f, f_eps) == 2);
    print_test_result("array_index_of_float (not found)", array_index_of_float(f_vec, 1.23f, f_eps) == -1LL);
    print_test_result("array_count_occurrence_float (found multiple)", array_count_occurrence_float(f_vec, 3.3f, f_eps) == 2);
    print_test_result("array_count_occurrence_float (not found)", array_count_occurrence_float(f_vec, 1.23f, f_eps) == 0);

    vector<float> f_copy = array_copy_float(f_vec); // Vector copy
    f_copy[0] = 99.9f;
    print_test_result("array_copy_float (deep copy check)", f_copy.size() == f_vec.size() && !floats_are_close(f_vec[0], 99.9f, f_eps));

    vector<float> f_rev = {1.0f, 2.0f, 3.0f};
    array_reverse_float(f_rev); // In-place
    print_test_result("array_reverse_float", f_rev.size()==3 && floats_are_close(f_rev[0], 3.0f, f_eps) && floats_are_close(f_rev[2], 1.0f, f_eps));

    vector<float> f_sort = {3.0f, 1.0f, 2.0f};
    array_sort_float(f_sort); // In-place
    print_test_result("array_sort_float", f_sort.size()==3 && floats_are_close(f_sort[0], 1.0f, f_eps) && floats_are_close(f_sort[1], 2.0f, f_eps));

    vector<float> f_shuf = {1.0f, 2.0f, 3.0f, 4.0f};
    vector<float> f_shuf_before = f_shuf;
    array_shuffle_float(f_shuf); // In-place
    vector<float> f_shuf_after = f_shuf;
    sort(f_shuf_before.begin(), f_shuf_before.end());
    sort(f_shuf_after.begin(), f_shuf_after.end());
    print_test_result("array_shuffle_float (elements preserved)", f_shuf_before == f_shuf_after);

    vector<float> f_cat1 = {1.0f}, f_cat2 = {2.0f, 3.0f};
    vector<float> f_cat_res = array_concat_float(f_cat1, f_cat2); // Creates new vector
    print_test_result("array_concat_float", f_cat_res.size()==3 && floats_are_close(f_cat_res[0],1.0f, f_eps) && floats_are_close(f_cat_res[2],3.0f, f_eps));

    // --- Double Tests --- (Structure mirrors float tests)
    vector<double> d_vec = {1.11, -2.22, 3.33, 0.0, 3.33};
    vector<double> d_empty;
    double d_max, d_min, d_sum, d_avg;

    print_test_result("array_max_double", array_max_double(d_vec, &d_max) && doubles_are_close(d_max, 3.33, d_eps));
    print_test_result("array_min_double", array_min_double(d_vec, &d_min) && doubles_are_close(d_min, -2.22, d_eps));
    print_test_result("array_sum_double", array_sum_double(d_vec, &d_sum) && doubles_are_close(d_sum, 1.11 - 2.22 + 3.33 + 0.0 + 3.33, d_eps));
    print_test_result("array_average_double", array_average_double(d_vec, &d_avg) && doubles_are_close(d_avg, (1.11 - 2.22 + 3.33 + 0.0 + 3.33)/5.0, d_eps));
    print_test_result("array_contains_double", array_contains_double(d_vec, -2.22, d_eps));
    print_test_result("array_index_of_double", array_index_of_double(d_vec, 3.33, d_eps) == 2);
    print_test_result("array_count_occurrence_double", array_count_occurrence_double(d_vec, 3.33, d_eps) == 2);
    // ... other double tests (copy, reverse, sort, shuffle, concat) would follow same pattern ...

    // --- Printing ---
    cout << "array_print_float demo: ";
    array_print_float(f_vec); // Example output
    cout << "array_print_double demo: ";
    array_print_double(d_vec); // Example output
}

void test_string_vector_functions() { // Renamed from test_string_array_functions for clarity
    cout << "\n--- Testing String Vector/Array Functions ---" << endl;

    // --- std::vector<string> Tests ---
    vector<string> s_vec = {"apple", "banana", "Orange", "apple", "grape"};
    vector<string> s_empty;
    string s_max, s_min;

    print_test_result("array_max_string", array_max_string(s_vec, &s_max) && s_max == "grape"); // Lexicographical max
    print_test_result("array_min_string", array_min_string(s_vec, &s_min) && s_min == "Orange"); // Lexicographical min

    vector<string> s_sort = {"c", "a", "b"};
    array_sort_string(s_sort); // In-place sort
    print_test_result("array_sort_string", s_sort.size()==3 && s_sort[0]=="a" && s_sort[1]=="b" && s_sort[2]=="c");

    print_test_result("array_contains_string (found)", array_contains_string(s_vec, "banana"));
    print_test_result("array_contains_string (case-sensitive)", !array_contains_string(s_vec, "orange"));
    print_test_result("array_contains_string (not found)", !array_contains_string(s_vec, "kiwi"));
    print_test_result("array_index_of_string (found first)", array_index_of_string(s_vec, "apple") == 0);
    print_test_result("array_index_of_string (not found)", array_index_of_string(s_vec, "kiwi") == -1LL);
    print_test_result("array_count_occurrence_string (found multiple)", array_count_occurrence_string(s_vec, "apple") == 2);
    print_test_result("array_count_occurrence_string (not found)", array_count_occurrence_string(s_vec, "kiwi") == 0);

    vector<string> s_copy = array_copy_string(s_vec); // Vector copy
    s_copy[0] = "pear";
    print_test_result("array_copy_string (deep copy check)", s_copy.size() == s_vec.size() && s_vec[0] == "apple");

    vector<string> s_rev = {"a", "b"};
    array_reverse_string(s_rev); // In-place
    print_test_result("array_reverse_string", s_rev.size()==2 && s_rev[0]=="b" && s_rev[1]=="a");

    vector<string> s_shuf = {"a", "b", "c", "d"};
    vector<string> s_shuf_before = s_shuf;
    array_shuffle_string(s_shuf); // In-place
    vector<string> s_shuf_after = s_shuf;
    sort(s_shuf_before.begin(), s_shuf_before.end());
    sort(s_shuf_after.begin(), s_shuf_after.end());
    print_test_result("array_shuffle_string (elements preserved)", s_shuf_before == s_shuf_after);

    vector<string> s_cat1 = {"x"}, s_cat2 = {"y", "z"};
    vector<string> s_cat_res = array_concat_string(s_cat1, s_cat2); // Creates new vector
    print_test_result("array_concat_string", s_cat_res.size()==3 && s_cat_res[0]=="x" && s_cat_res[2]=="z");

    // --- C-Style Array Test ---
    // Note potential need for const_cast if source is const char*[]
    const char* c_arr_const[] = {"hello", "world", "test"};
    char* const* c_arr = const_cast<char* const*>(c_arr_const);
    size_t c_size = 3;
    print_test_result("find_string (C-style, found)", find_string(c_arr, c_size, "world") == 1);
    print_test_result("find_string (C-style, not found)", find_string(c_arr, c_size, "atomix") == -1);

    // --- Printing ---
    cout << "array_print_string demo: ";
    array_print_string(s_vec); // Example output
}

void test_string_manipulation_functions() {
     cout << "\n--- Testing String Manipulation Functions ---" << endl;
     string s1 = "  Hello World!  ";
     string s2 = "HelloWorld!";
     string s_num_valid = " -123 ";
     string s_num_invalid = " 12a ";
     string s_float_valid = " 3.14e-2 ";
     string s_float_invalid = " 3.x ";
     string s_alpha = "Alpha";
     string s_alnum = "Alpha123";
     string s_space = " \t\n ";
     string s_empty = "";
     string s_csv = "a,b,c";
     vector<string> v_str = {"x", "y", "z"};
     float f_eps = numeric_limits<float>::epsilon() * 100; // Epsilon for float comparison
     double d_eps = numeric_limits<double>::epsilon() * 100; // Epsilon for double comparison

    // Basic Ops
    print_test_result("string_copy", string_copy(s_alpha) == "Alpha");
    print_test_result("string_equals (equal)", string_equals(s_alpha, "Alpha"));
    print_test_result("string_equals (unequal)", !string_equals(s_alpha, "alpha"));
    print_test_result("string_trim", string_trim(s1) == "Hello World!");
    print_test_result("string_concat", string_concat("abc", "def") == "abcdef");

    // Content Checks
    print_test_result("string_is_int (valid)", string_is_int(s_num_valid));
    print_test_result("string_is_int (invalid)", !string_is_int(s_num_invalid));
    print_test_result("string_is_alpha (valid)", string_is_alpha(s_alpha));
    print_test_result("string_is_alpha (invalid)", !string_is_alpha(s_alnum));
    print_test_result("string_is_digit (valid)", string_is_digit("123"));
    print_test_result("string_is_digit (invalid)", !string_is_digit(s_num_valid)); // Contains space/-
    print_test_result("string_is_alnum (valid)", string_is_alnum(s_alnum));
    print_test_result("string_is_alnum (invalid)", !string_is_alnum(s1)); // Contains space/!
    print_test_result("string_is_space (valid)", string_is_space(s_space));
    print_test_result("string_is_space (invalid)", !string_is_space(s_alpha));
    print_test_result("string_is_empty (valid)", string_is_empty(s_empty));
    print_test_result("string_is_empty (invalid)", !string_is_empty(s_space));

    // Case Conversion
    print_test_result("string_to_lower", string_to_lower("HeLLo") == "hello");
    print_test_result("string_to_upper", string_to_upper("HeLLo") == "HELLO");

    // Substring & Finding
    print_test_result("string_substring", string_substring(s2, 5, 5) == "World");
    print_test_result("string_find_char (found)", string_find_char(s1, 'W') == 8);
    print_test_result("string_find_char (not found)", string_find_char(s1, 'z') == -1LL);
    print_test_result("string_find_substring (found)", string_find_substring(s1, "World") == 8);
    print_test_result("string_find_substring (not found)", string_find_substring(s1, "Atomix") == -1LL);

    // Modification & Split/Join
    print_test_result("string_replace_char", string_replace_char("banana", 'a', 'o') == "bonono");
    vector<string> split_res = string_split(s_csv, ',');
    print_test_result("string_split", split_res.size()==3 && split_res[0]=="a" && split_res[1]=="b" && split_res[2]=="c");
    print_test_result("string_join", string_join(v_str, "-") == "x-y-z");

    // Prefix/Suffix
    print_test_result("string_starts_with (true)", string_starts_with("prefix_text", "prefix"));
    print_test_result("string_starts_with (false)", !string_starts_with("prefix_text", "text"));
    print_test_result("string_ends_with (true)", string_ends_with("text_suffix", "suffix"));
    print_test_result("string_ends_with (false)", !string_ends_with("text_suffix", "text"));

    // String to Number Conversion
    float f_val; double d_val;
    bool f_ok = string_to_float(s_float_valid, &f_val);
    print_test_result("string_to_float (valid)", f_ok && floats_are_close(f_val, 0.0314f, f_eps));
    print_test_result("string_to_float (invalid)", !string_to_float(s_float_invalid, &f_val));
    bool d_ok = string_to_double(" -1.23456789e+5 ", &d_val);
    print_test_result("string_to_double (valid)", d_ok && doubles_are_close(d_val, -123456.789, d_eps));
    print_test_result("string_to_double (invalid)", !string_to_double("nan", &d_val)); // Does not parse nan/inf currently
}

void test_utility_functions() {
     cout << "\n--- Testing Utility Functions ---" << endl;

     // Random number generation (basic range check)
     bool rand_int_ok = true;
     bool rand_float_ok = true;
     bool rand_double_ok = true;
     int r_i_min = 10, r_i_max = 20;
     float r_f_min = -1.0f, r_f_max = 1.0f;
     double r_d_min = -100.0, r_d_max = 100.0;

     for(int i=0; i<200; ++i) { // Increase iterations for better chance of hitting bounds
         int r_int = get_random_int(r_i_min, r_i_max);
         if (r_int < r_i_min || r_int > r_i_max) rand_int_ok = false;

         float r_float = get_random_float(r_f_min, r_f_max);
         if (r_float < r_f_min || r_float > r_f_max) rand_float_ok = false;

         double r_double = get_random_double(r_d_min, r_d_max);
         if (r_double < r_d_min || r_double > r_d_max) rand_double_ok = false;
     }
     print_test_result("get_random_int (range check)", rand_int_ok);
     print_test_result("get_random_float (range check)", rand_float_ok);
     print_test_result("get_random_double (range check)", rand_double_ok);

     // Timer check
     auto start = start_timer();
     this_thread::sleep_for(chrono::milliseconds(15)); // Sleep briefly (adjust if needed)
     double elapsed = stop_timer(start);
     // Check if elapsed time is roughly positive and reasonable (e.g., > 0.01 seconds)
     print_test_result("start/stop_timer (check > ~0.01s)", elapsed > 0.01 && elapsed < 0.1); // Adjust bounds based on system speed/load

    // Memory helpers are tested implicitly via C-style array tests needing cleanup,
    // but direct testing is harder without known allocated pointers.
}


// --- Main Function ---
int main() {
    cout << "===== Atomix Library Test Suite v1.2.0 =====" << endl;

    initialize_random(); // Initialize random once for all automated tests that use it

    // --- Run Automated Tests ---
    test_integer_array_functions();
    test_float_double_vector_functions(); // Covers float/double vectors
    test_string_vector_functions(); // Covers string vectors and C-style find_string
    test_string_manipulation_functions();
    test_utility_functions();

    // --- Run Interactive Tests (Optional) ---
    // Uncomment the following line to manually test the get_* input functions.
    // test_get_functions_interactive();

    cout << "\n===== Test Suite Finished =====" << endl;

    return 0; // Indicate successful execution (individual tests print PASS/FAIL)
}
