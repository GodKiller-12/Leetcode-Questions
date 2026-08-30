class Solution {
public:
    int minimumDeletions(vector<int>& a) {
        int ind1 = -1, ind2 = -1 , mini = INT_MAX , maxi = INT_MIN ;
        for(int i = 0;i<a.size();i++) {
            if(a[i]<mini) mini = a[i] , ind1 = i;
            if(a[i]>maxi) maxi = a[i] , ind2 = i;
        }
        return min({(int)a.size()-min(ind1,ind2),max(ind2,ind1)+1,(int)a.size()-max(ind1,ind2) + min(ind1,ind2) +1}) ;
    }
};