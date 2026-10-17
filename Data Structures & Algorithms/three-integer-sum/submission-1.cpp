// class Solution {
//    public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> output;
//         unordered_map<string, int> mp;
//         int n = nums.size();
//         for (int k = 0; k < n - 2; k++) {
//             int target = -(nums[k]);
//             int i=k+1,j=n-1;
//             while (i < j) {
//                 if (nums[i] + nums[j] > target) {
//                     j--;
//                 } else if (nums[i] + nums[j] < target) {
//                     i++;
//                 } else {
//                     string key = "";
//                     key += to_string(nums[k]) + "#" + to_string(nums[i]) + "#" +
//                            to_string(nums[j]) + "#";
                    
//                     if (mp.find(key)== mp.end()) {
//                         vector<int> v={nums[k],nums[i],nums[j]};
//                         output.push_back(v);
//                         mp[key]=1;
//                     }
//                     i++;
//                     j--;
//                 }
//             }
//         }
//         return output;
//     }
// };




class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> output;
        int n = nums.size();

        for (int k = 0; k < n - 2; k++) {

            // Skip duplicate first elements
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }

            // All remaining elements are non-negative
            if (nums[k] > 0) {
                break;
            }

            int i = k + 1;
            int j = n - 1;

            while (i < j) {
                long long sum = (long long)nums[k] + nums[i] + nums[j];

                if (sum < 0) {
                    i++;
                }
                else if (sum > 0) {
                    j--;
                }
                else {
                    output.push_back({nums[k], nums[i], nums[j]});

                    // Skip duplicate second elements
                    while (i < j && nums[i] == nums[i + 1]) {
                        i++;
                    }

                    // Skip duplicate third elements
                    while (i < j && nums[j] == nums[j - 1]) {
                        j--;
                    }

                    i++;
                    j--;
                }
            }
        }

        return output;
    }
};