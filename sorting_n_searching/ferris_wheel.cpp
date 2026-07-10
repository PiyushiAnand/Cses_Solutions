#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    long long x;
    cin>>n>>x;
    vector<long long>p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    sort(p.begin(),p.end());
    int l=0,r=n-1;
    long long ans=0;
    vector<bool>taken(n,false);
    while (l<r)
    {
        if(p[l]+p[r]>x){
            r--;
        }
        else {
            taken[l]=true;
            taken[r]=true;
            l++;
            r--;
            ans++;
        }
        // cout<<l<<" "<<r<<endl;
    }
    

    while(l<n){
       if(!taken[l]) ans++;
        l++;
    }

    cout<<ans<<endl;
    
}