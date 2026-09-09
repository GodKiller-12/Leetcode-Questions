class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int left = 0,right = n-1;

        while(left<=right)
        {
            int mid = left + (right-left)/2;

            int mx = mat[0][mid],idx = 0;
            for(int i = 1; i<m ; i++)
            {
                if(mat[i][mid]>mx)
                {
                    mx = mat[i][mid];
                    idx = i;
                }
            }

            int leftSide = (mid-1>=0 ? mat[idx][mid-1] : -1);
            int rightSide = (mid+1 < n ? mat[idx][mid+1] : -1);
            if(mx>leftSide && mx>rightSide) return {idx,mid};
            else if(mx < leftSide) right = mid-1;
            else left = mid+1;
        }

        return {};
    }
};