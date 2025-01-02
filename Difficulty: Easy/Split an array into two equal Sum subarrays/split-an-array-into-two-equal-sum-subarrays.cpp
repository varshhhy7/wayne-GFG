//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& nums) {
        // code hereint total_sum=0;
        int total_sum=0;
        int prefix=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
          total_sum+=nums[i];
        }
        for(int i=0 ;i<n-1;i++){
            prefix+=nums[i];
            int ans=total_sum-prefix;
            if(ans==prefix){
                return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends