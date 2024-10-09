#include <bits/stdc++.h>
#include <cstdio>
#define int long long
using namespace std;

// Function to generate a random operator
char random_operator() {
    char operators[] = {'+', '-', '*', '/'};
    return operators[rand() % 4];
}

// Function to generate a random integer within a range
int random_int(int low, int high) {
    return low + rand() % (high - low + 1);
}

// Helper function to convert number to string using stringstream
string number_to_string(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

// Function to generate input for one test case
void generate_test_case(int test_case_number) {
    // Generate random operator and operands within the range [1, 1e9]
    char op = random_operator();
    int a = random_int(1, 1e9);
    int b = random_int(1, 1e9);

    // Calculate the result based on the operator
    int c;
    if (op == '+') {
        c = a + b;
    } else if (op == '-') {
        c = a - b;
    } else if (op == '*') {
        c = a * b;
    } else {
        // Ensure b is not zero and avoid large division results
        c = a / b;
    }

    // Write the test case to a file
    string input_filename = number_to_string(test_case_number) + ".in";
    string output_filename = number_to_string(test_case_number) + ".out";

    freopen(input_filename.c_str(), "w", stdout);
    printf("%c %lld %lld %lld\n", op, a, b, c);
    fclose(stdout);

    freopen(output_filename.c_str(), "w", stdout);
    if ((op == '+' && a + b == c) || 
        (op == '-' && a - b == c) || 
        (op == '*' && a * b == c) || 
        (op == '/' && b != 0 && a / b == c)) {
        printf("Yes\n%lld%c%lld=%lld\n", a, op, b, c);
    } else {
        printf("No\n");
    }
    fclose(stdout);
}

signed main() {
    srand(time(0)); // Seed for randomness

    // Generate 50 test cases
    for (int i = 1; i <= 50; ++i) {
        generate_test_case(i);
    }

    return 0;
}

