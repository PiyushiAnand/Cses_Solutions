#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    long long median = vec[n/2];
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans+=abs(vec[i]-median);
    }
    cout<<ans<<endl;
}