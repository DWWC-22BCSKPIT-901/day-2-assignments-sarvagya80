#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = nums[0];
    int count = 0;

    
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    
    return candidate;
}

int main() {
    vector<int> nums1 = {3, 2, 3};
    cout << "Output: " << majorityElement(nums1) << endl;

    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Output: " << majorityElement(nums2) << endl;

    return 0;
}
