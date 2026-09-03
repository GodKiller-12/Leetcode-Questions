class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        bool alleven = true ;
        bool allodd = true ;
        vector<int>a = nums;
        sort(a.begin(),a.end());
        int sodd = -1;
        int seven = -1;
        for(int i = 0;i<n;i++){
            if(sodd == -1 && a[i]%2==1){
                sodd = a[i];
            }
            if(seven == -1 && a[i]%2==0){
                seven = a[i];
            }
        }
        //  even 
        for(auto i :nums){
            if(i%2==1){
                if(sodd>=i){
                    alleven = false ;
                    break;
                }
            }
        }
         for(auto i :nums){
            if(i%2==0){
                if(sodd>=i){
                    allodd = false ;
                    break;
                }
            }
        }
        return allodd || alleven ;
    }
};