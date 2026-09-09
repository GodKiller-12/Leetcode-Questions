class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        int lo = 0;
        int hi = n-1;
        if(n==1) return 0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(mid==0 && a[mid]>a[mid+1]) return mid ;
            if(mid == n-1 && a[mid-1]<a[mid]) return mid ;
            if(a[mid]>a[mid+1] && a[mid]>a[mid-1]) return mid ;
            if(mid+1 <n && a[mid]<a[mid+1]){
                lo = mid +1;
            }
            else{
                hi = mid -1;
            }
        }
        return -1;   
    }
};