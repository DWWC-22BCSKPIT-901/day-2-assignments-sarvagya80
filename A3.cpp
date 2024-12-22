#include <iostream>
using namespace std;
int minJumps(int nums[], int n) { if (n <= 1) return 0;
int jumps = 0;  
int currentEnd = 0;  
int currentFarthest = 0;
for (int i = 0; i < n - 1; i++) {  currentFarthest = max(currentFarthest, i + nums[i]);
if (i == currentEnd) {  jumps++;   
currentEnd = currentFarthest; 
if (currentEnd >= n - 1) break;  
        }
    
}     
return jumps; 
        
} int main() {  
    int n; 
cout << "Enter the size of the array: "; 
cin >> n;    
int* nums = new int[n]; 
cout << "Enter the elements of the array: ";   
for (int i = 0; i < n; i++) {  cin 
>> nums[i];  
    }  
    int result = minJumps(nums, n); 
    cout << "Minimum number of jumps to reach the last index: " << result << endl; 
    delete[] nums;   
    return 0;  
}
