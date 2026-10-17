class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        unordered_map<string, int> mp;
        int n = nums.size();
        for (int k = 0; k < n - 2; k++) {
            int target = -(nums[k]);
            int i=k+1,j=n-1;
            while (i < j) {
                if (nums[i] + nums[j] > target) {
                    j--;
                } else if (nums[i] + nums[j] < target) {
                    i++;
                } else {
                    // int arr[] = {nums[i], nums[j], nums[k]};
                    // sort(arr, arr + 3);
                    string key = "";
                    key += to_string(nums[k]) + "#" + to_string(nums[i]) + "#" +
                           to_string(nums[j]) + "#";
                    
                    if (mp.find(key)== mp.end()) {
                        vector<int> v={nums[k],nums[i],nums[j]};
                        output.push_back(v);
                        mp[key]=1;
                    }
                    i++;
                    j--;
                }
            }
        }
        return output;
    }
};
