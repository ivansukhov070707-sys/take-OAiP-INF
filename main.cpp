#include <iostream>
#include <vector>

int findMax(const std::vector<int>& arr) {
    if (arr.empty()) return INT_MIN;
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) maxVal = num;
    }
    return maxVal;
}

int main() {
    std::vector<int> arr = {3,1,4,1,5};
    std::cout << "Max: " << findMax(arr) << std::endl;
    return 0;
}
