#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    long long k;
    cin>>n>>m>>k;
    vector<long long>a_vec(n);
    vector<long long>b_vec(m);
    for(int i=0;i<n;i++){
        cin>>a_vec[i];
    }
    for(int i=0;i<m;i++){
        cin>>b_vec[i];
    }

    sort(a_vec.begin(),a_vec.end());
    sort(b_vec.begin(),b_vec.end());

    int a_ptr=0,b_ptr=0;
    int ans = 0;
    while(a_ptr<n&&b_ptr<m){
        if((b_vec[b_ptr]<a_vec[a_ptr]-k)){
            b_ptr++;
        }
        else if((b_vec[b_ptr]>a_vec[a_ptr]+k)){
            a_ptr++;
        }
        else{
            a_ptr++;
            b_ptr++;
            ans++;
        }
        //cout<<a_ptr<<" "<<b_ptr
    } 

    cout<<ans<<endl;

}