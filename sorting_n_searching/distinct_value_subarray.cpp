#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<long long,int>pos;
    long long left = 0;
    long long ans = 0;
    for(long long i=0;i<n;i++){
        long long x;
        cin>>x;
        if(pos.find(x)==pos.end()){
            pos[x]=i;
        }
        else {
            if(left<pos[x]+1){
                left = pos[x]+1;
            }
            pos[x]=i;
        }
        ans += (i-left)+1;
        // cout<<left<<" "<<i<<endl;
    }
    cout<<ans<<endl;
}