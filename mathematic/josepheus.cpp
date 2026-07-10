#include<iostream>
#include<cmath>
using namespace std;

long long solve(long long n,long long k){
    if(n == 1) return 1;
    if(k<=n/(long long)2)return (long long)2*k;
    if(n%(long long)2==0){
        return (long long)2*solve(n/(long long)2,k-n/(long long)2)-1;
    }
    long long x = solve((n+1)/(long long)2,k-n/(long long)2);
    if(x==1)return n;
    return (long long)2*(x-1)-1;
}
int main(){
    int q;
    long long n,k;
    cin>>q;
    while(q--){
        cin>>n>>k;
        cout<<solve(n,k)<<endl;
    }
}