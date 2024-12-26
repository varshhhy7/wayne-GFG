//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int findPivot(vector<int>& nums, int n) {
    int l = 0, r = n - 1;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] > nums[r]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return r; // or l, as they will be the same at this point
}

int binarySearch(int l, int r, vector<int>& nums, int target) {
    int idx = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) {
            idx = mid;
            break;
        } else if(nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return idx;
}

int search(vector<int>& nums, int key) {
    int n = nums.size();
    int pivot_index = findPivot(nums, n);

    // Search in the left side of the pivot
    int idx = binarySearch(0, pivot_index - 1, nums, key);
    if(idx != -1)
        return idx;

    // Search in the right side including pivot
    idx = binarySearch(pivot_index, n - 1, nums, key);
    return idx;
}

    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends