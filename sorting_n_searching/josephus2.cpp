#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
#include<map>
using namespace std;
class FenwickTree{
    private:
        vector<int>tree;
        int n;
    public:
    FenwickTree(int num){
        n = num;
        tree.resize(n+1, 0); 
        for(int i=1;i<=num;i++){
            update(i,1);
        }

    }
    void update(int idx,int delta){
       while(idx<=n){
        tree[idx]+=delta;
        idx += idx&(-idx);
       }
    }
    int query(int idx){
       int ans = 0;
       while(idx>0){
        ans+=tree[idx];
        idx-=idx&(-idx);
       }
       return ans;
    }
    int getKth(int k){ 
        //gives the 
        int idx=0;
        int jump = 1;
        while ((jump << 1) <= n)
            jump <<= 1;
        while(jump>0){
            int next = idx+jump;
            if(next<=n&&tree[next]<k){
                k -= tree[next];
                idx = next;
            }
            jump = jump/2;
        }
        return idx+1;
    }
};
int main(){
    int n,k;
    cin>>n>>k;
    FenwickTree f = FenwickTree(n);
    int alive = n;
    int currRank = 0;
    while (alive>0)
    {
        currRank = (currRank+k)%(alive);
        // cout<<"Now we will search for rank: "<<currRank<<endl;
        int idx = f.getKth(currRank+1);
        f.update(idx,-1);
        cout<<idx<<endl;
        alive--;
        if(currRank==alive){
            currRank=0;
        }
       
    }
    
}