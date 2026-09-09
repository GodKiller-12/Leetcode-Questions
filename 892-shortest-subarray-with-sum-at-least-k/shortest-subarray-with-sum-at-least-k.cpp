class Solution {
public:

class SegTree{
    int n;
    vector<int> t;

    void build(int node,int l,int r,vector<int>& a){
        if(l==r){
            t[node]=a[l];
            return;
        }

        int m=(l+r)/2;
        build(2*node,l,m,a);
        build(2*node+1,m+1,r,a);

        t[node]=max(t[2*node],t[2*node+1]);
    }

    void update(int node,int l,int r,int i,int x){
        if(l==r){
            t[node]=x;
            return;
        }

        int m=(l+r)/2;

        if(i<=m) update(2*node,l,m,i,x);
        else update(2*node+1,m+1,r,i,x);

        t[node]=max(t[2*node],t[2*node+1]);
    }

    int query(int node,int l,int r,int ql,int qr){
        if(qr<l || r<ql) return INT_MIN;

        if(ql<=l && r<=qr) return t[node];

        int m=(l+r)/2;

        return max(
            query(2*node,l,m,ql,qr),
            query(2*node+1,m+1,r,ql,qr)
        );
    }

public:
    SegTree(vector<int>& a){
        n=a.size();
        t.resize(4*n);
        build(1,0,n-1,a);
    }

    void update(int i,int x){
        update(1,0,n-1,i,x);
    }

    int query(int l,int r){
        return query(1,0,n-1,l,r);
    }
};

    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size();
        vector<int>pref(n+1,0);
        //  i have curr sum so i want a sum t 
        // curr - (k+x) 
        //  i want t so it should be less than or equal to  curr - (k+1)
        // so find upper bound of it 
        // it should be less than curr -k strictly less than equal to 
        int ans = INT_MAX;
        pref[0] = a[0];
        if(a[0]>=k) return 1;
        for(int i = 1;i<n;i++){
            pref[i] += pref[i-1] + a[i];
            if(a[i]>=k) return 1;
        }
        int curr = 0;
        SegTree sg(pref);
        for(int i = 0;i<n;i++){
            // curr += a[i];
            int t = curr + k ;
          int lo = i;
          int hi = n-1;
          int ind = -1;
          while(lo<hi){
            int mid = (lo+hi)/2;
            int maxi1 = sg.query(lo,mid);
            int maxi2 = sg.query(mid+1,n-1);
            if(t>maxi1 && t>maxi2){
                break;
            }
            if(maxi1>=t){
                ind = mid ;
                hi = mid ;
            }
            else{
                lo = mid +1;
                ind = mid +1;
            }
          }
           curr += a[i];
          if(ind == -1) continue ;
          ind = hi ;
          ans = min(ans , ind - i +1);
         
        }
        // over a given range from i+1 to n i need to find the first index where element is greater than t 
        // binary search + segment tree 
        
        // sorted on basis of sum 
        // yha pe prefix sum non increasing hai so binary search not work 
        if(ans==INT_MAX) return -1;
        return ans ;

        
    }
};