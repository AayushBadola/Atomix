// test case for atomix library a C++ library having same functionality as Aquant library in C

#include <iostream> 
#include <string>   
#include <vector>   
#include <iomanip>  


#include "atomix.h"


using namespace std;

int main() {

    cout << "--- Atomix Library Example ---" << endl << endl;

    // --- Input Handling Examples ---
    cout << "--- Input Examples ---" << endl;

    // get_string example
    string name = get_string("Enter your name: ");
    if (!name.empty() || !cin.eof()) {
        cout << "You entered (string): \"" << name << "\"" << endl;
    } else {
        cerr << "Error reading name or EOF encountered." << endl;
    }
    cout << endl;

    // get_char example
    char initial = get_char("Enter your initial (single character): ");
    cout << "You entered (char): '" << initial << "'" << endl;
    cout << endl;

    // get_int example
    int age = get_int("Enter your age (integer): ");
    cout << "You entered (int): " << age << endl;
    cout << endl;

    // get_long example
    long big_number = get_long("Enter a large integer (long): ");
    cout << "You entered (long): " << big_number << endl;
    cout << endl;

    // get_float example
    float cost = get_float("Enter a cost (float): ");
    // Set precision for float output
    cout << fixed << setprecision(2);
    cout << "You entered (float): " << cost << endl;
    cout << endl;
    // Reset precision to default or unset fixed
    cout << defaultfloat;

    // get_double example
    double pi_approx = get_double("Enter an approximation of pi (double): ");
    // Set precision for double output
    cout << fixed << setprecision(10);
    cout << "You entered (double): " << pi_approx << endl;
    cout << endl;
     // Reset precision
    cout << defaultfloat;


    // --- Array Utility Examples ---
    cout << "--- Array Utility Examples ---" << endl;

    int numbers[] = {10, -5, 20, 5, 15, -5, 20};
    size_t numbers_size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Working with array: ";
    print_array(numbers, numbers_size); // Uses print_array

    // array_max example
    int max_val;
    if (array_max(numbers, numbers_size, &max_val)) {
        cout << "Maximum value: " << max_val << endl;
    } else {
        cerr << "Failed to find maximum." << endl;
    }

    // array_min example
    int min_val;
    if (array_min(numbers, numbers_size, &min_val)) {
        cout << "Minimum value: " << min_val << endl;
    } else {
        cerr << "Failed to find minimum." << endl;
    }

    // array_sum example
    long long sum_val;
    if (array_sum(numbers, numbers_size, &sum_val)) {
        cout << "Sum of elements: " << sum_val << endl;
    } else {
        cerr << "Failed to calculate sum or overflow detected." << endl;
    }
    cout << endl;

    // array_has_pair_sum example
    int target_sum1 = 15; // 10 + 5, 20 + (-5)
    int target_sum2 = 30; // 10 + 20, 15 + 15 (if 15 existed twice)
    int target_sum3 = 100; // Not found
    cout << "Checking for pairs summing to " << target_sum1 << ": " << (array_has_pair_sum(numbers, numbers_size, target_sum1) ? "Found" : "Not Found") << endl;
    cout << "Checking for pairs summing to " << target_sum2 << ": " << (array_has_pair_sum(numbers, numbers_size, target_sum2) ? "Found" : "Not Found") << endl;
    cout << "Checking for pairs summing to " << target_sum3 << ": " << (array_has_pair_sum(numbers, numbers_size, target_sum3) ? "Found" : "Not Found") << endl;
    cout << endl;


    // array_has_pair_product example
    int target_product1 = -25; // -5 * 5
    int target_product2 = 200; // 10 * 20
    int target_product3 = 99; // Not found
    cout << "Checking for pairs with product " << target_product1 << ": " << (array_has_pair_product(numbers, numbers_size, target_product1) ? "Found" : "Not Found") << endl;
    cout << "Checking for pairs with product " << target_product2 << ": " << (array_has_pair_product(numbers, numbers_size, target_product2) ? "Found" : "Not Found") << endl;
    cout << "Checking for pairs with product " << target_product3 << ": " << (array_has_pair_product(numbers, numbers_size, target_product3) ? "Found" : "Not Found") << endl;
     cout << endl;


    // array_has_pair_difference example
    int target_diff1 = 5;  // 10 - 5, 20 - 15, 0 - (-5) (if 0 existed)
    int target_diff2 = 25; // 20 - (-5)
    int target_diff3 = 0; // 20 - 20, -5 - (-5)
    int target_diff4 = 99; // Not found
    cout << "Checking for pairs with difference " << target_diff1 << ": " << (array_has_pair_difference(numbers, numbers_size, target_diff1) ? "Found" : "Not Found") << endl;
    cout << "Checking for pairs with difference " << target_diff2 << ": " << (array_has_pair_difference(numbers, numbers_size, target_diff2) ? "Found" : "Not Found") << endl;
    cout << "Checking for pairs with difference " << target_diff3 << ": " << (array_has_pair_difference(numbers, numbers_size, target_diff3) ? "Found" : "Not Found") << endl;
    cout << "Checking for pairs with difference " << target_diff4 << ": " << (array_has_pair_difference(numbers, numbers_size, target_diff4) ? "Found" : "Not Found") << endl;
    cout << endl;


    // sort_array example
    // Note: sort_array (Counting Sort) is optimized for non-negative numbers.
    int positive_numbers[] = {5, 2, 8, 2, 1, 9, 4, 0};
    size_t pos_size = sizeof(positive_numbers) / sizeof(positive_numbers[0]);
    cout << "Array before sort: ";
    print_array(positive_numbers, pos_size);
    sort_array(positive_numbers, pos_size);
    cout << "Array after sort:  ";
    print_array(positive_numbers, pos_size);
    cout << endl;


    // find_string example
    
    // We use const char*[] here, which is more common, and need const_cast.
    const char* fruits[] = {"Apple", "Banana", "Cherry", "Apple", "Date"};
    size_t fruits_size = sizeof(fruits) / sizeof(fruits[0]);
    const char* target1 = "Apple";
    const char* target2 = "Grape";

    // const_cast is needed to match the function signature's expected type
    char* const* mutable_fruits = const_cast<char* const*>(fruits);

    int apple_index = find_string(mutable_fruits, fruits_size, target1);
    cout << "First occurrence of \"" << target1 << "\" found at index: " << apple_index << endl;

    int grape_index = find_string(mutable_fruits, fruits_size, target2);
    cout << "First occurrence of \"" << target2 << "\" found at index: " << grape_index << endl;
    cout << endl;

    // print_array examples for edge cases
    cout << "Print array edge cases:" << endl;
    int empty_arr[] = {};
    print_array(empty_arr, 0);
    print_array(nullptr, 10); // Size doesn't matter if array is null
    cout << endl;


    cout << "--- Example Complete ---" << endl;

    return 0;
}
