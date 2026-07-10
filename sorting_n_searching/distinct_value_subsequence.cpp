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
    map<long long,int>count;
    long long MOD  = 1e9+7;
    long long ans=1;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        count[x]++;
        // cout<<ans<<endl;
    }
    for(auto it:count){
        ans = (ans*(it.second+1))%MOD;
    }
    cout<<ans-1<<endl;
}
