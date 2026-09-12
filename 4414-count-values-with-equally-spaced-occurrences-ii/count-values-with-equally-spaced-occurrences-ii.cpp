class Solution {
public:
    int countSpecialIntegers(vector<int>& a) {
        int n = a.size();
        int count = 0;
        map<int,int>mp;
        map<int,int>c ,dist,mp1;

        for(int i = 0;i<n;i++){
          if(mp.find(a[i])==mp.end()){
            mp[a[i]] = i;
          }
          else{
            int dis = i-mp[a[i]];
            if(dist.find(a[i])==dist.end()){
                dist[a[i]] = dis;
            }
            else{
                if(dis!=dist[a[i]]) {
                    mp1[a[i]]++;
                }
            }
          }
          c[a[i]]++;
          mp[a[i]] = i;
        }
        for(auto i :c){
            if(i.second >= 3 && mp1.find(i.first)==mp1.end()) count ++;
        }
        return count ;
    }
};