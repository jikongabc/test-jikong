#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    long long total_sum = 0;
    int min1 = INT_MAX, min2 = INT_MAX;

    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
        total_sum += a[i];
        if(a[i] < min1){
            min2 = min1;
            min1 = a[i];
        } else if(a[i] < min2) {
            min2 = a[i];
        }
    }

    double area = 0.0;
    if(n >= 2) {
        area = total_sum - (min1 + min2) / 2.0;
    }

    std::cout << std::fixed << std::setprecision(2) << area << std::endl;

    return 0;
}
