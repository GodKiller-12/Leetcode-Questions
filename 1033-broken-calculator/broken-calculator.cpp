class Solution {
public:
    int brokenCalc(int s, int t) {
int count = 0;
if(s>=t) {
    return s-t;
}
        while(t!=s){
            cout<<t<<endl;
            if(t%2==1){
                t++;
                count ++;
            }
            int p = t/2;
            if(p>s){
                t = t/2;
                count ++;
            }
            else{
                count += 1 + s-p;
                break;
            }
        }
        return count ;
        
    }
};