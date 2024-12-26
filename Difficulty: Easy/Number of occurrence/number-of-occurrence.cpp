//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int start=0 , end=arr.size()-1 , count=0 , mid;
        
        //count occurances
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]==target){
                count++;
                //count occurances in left side
                int left=mid-1;
                while(left>=0 && arr[left]==target){
                    count++;
                    left--;
                }
                //count occurances on the right side
            
                int right=mid+1;
                while(right<arr.size()&&arr[right]==target){
                    count++;
                    right++;
                }
                break;
        
            }
            else if(arr[mid]<target){
                start=mid+1;
                
            }
            else {
                end=mid-1;
            }
        }
        return count;
        
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends