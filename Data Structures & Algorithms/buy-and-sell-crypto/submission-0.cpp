class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0],maxi=0,n=prices.size();

        for (int i = 1; i < n; i++) {
            if (prices[i] > mini) {
                int diff=prices[i]-mini;
                maxi=max(maxi,diff);
            }
            else{
                mini=prices[i];
            }
        }
        return maxi;
    }
};
