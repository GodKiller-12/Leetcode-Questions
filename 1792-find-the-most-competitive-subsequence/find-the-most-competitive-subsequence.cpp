class Solution {
public:
    vector<int> mostCompetitive(vector<int>& a, int k) {
        // lexicographically smallest subsequence of size k 
int n = a.size();
        // 2 3  3 5 4 9 6 
        stack<int>st;
        vector<int>ans ;
        for(int i = 0;i<n;i++){
            while(!st.empty() && ((st.size() + n-i-1)>= k && a[i]<st.top())){
                st.pop();
            }
            st.push(a[i]);
            if(st.size() + n-i-1 == k){
                while(!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
                reverse(ans.begin(),ans.end());
                for(int j = i+1;j<n;j++){
                    ans.push_back(a[j]);
                }
                break;
            }
        }
        if(ans.empty()){
            int p = st.size();
              while(!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
                reverse(ans.begin(),ans.end());
                int r = p-k;
                while(r--){
                    ans.pop_back();
                }
        }
        return ans ;
    }
};