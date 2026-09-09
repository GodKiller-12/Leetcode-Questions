class Solution {
public:
    int search(vector<int>& a, int target) {
        //  standing at any point half of the vector is sorted so i will check if the 
        // sorted half contains my answer or not if it does not contain i will move to the next half
int n = a.size();
        int lo = 0;
        int hi = n-1;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(a[mid]==target) return mid ;
            if(a[mid]>=a[lo]){
            // this half is sorted if check here i can find my target if not move to the next half
            if(target >=a[lo] && target <= a[mid]){
                hi = mid-1 ;
            }
            else{
                lo = mid+1 ;
            }
            }
            else{
                // a[hi] >a[mid]
                if(target >=a[mid] && target <= a[hi]){
                    lo = mid +1;
                }
                else{
                    hi = mid-1 ;
                }
            }

        }
        return -1;

    }
};