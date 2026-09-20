class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>>ans;
        int n = a.size();
        int count = (1<<n) - 1;
        for(int i = 0;i<=count;i++){
            vector<int>temp;
            for(int j = 0;j<n;j++){
                if((1<<j)&(i)){
                   temp.push_back(a[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans ;
    }
};