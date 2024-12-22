
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool can_assign_jobs(vector<int>& jobs, int k, long long maxTime) {
    int workers = 1;
    long long current_load = 0;
    
    for (int job : jobs) {
        if (job > maxTime) return false;
        
        if (current_load + job > maxTime) {
            workers++;
            current_load = job;            
            if (workers > k) return false;
        } else {
            current_load += job;
        }
    }
    return true;
}

long long minimum_time_required(vector<int>& jobs, int k) {
    sort(jobs.rbegin(), jobs.rend());
    
    long long left = jobs[0];                                     // Minimum possible time is the largest job
    long long right = accumulate(jobs.begin(), jobs.end(), 0LL);  // Maximum is sum of all jobs
    
    while (left < right) {
        long long mid = left + (right - left) / 2;
        
        if (can_assign_jobs(jobs, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    vector<int> jobs1 = {3, 2, 3};
    int k1 = 3;
    cout << "Minimum time required : " << minimum_time_required(jobs1, k1) << endl;
    return 0;
}
