#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
bool custom_c(pair<long long,long long>a,pair<long long,long long>b){
    if(a.second==b.second)return a.first<b.first;
    return a.second < b.second;
}
int main(){
    int n;
    cin>>n;
    vector<pair<long long,long long> >m(n);
    for(int i=0;i<n;i++){
        cin>>m[i].first;
        cin>>m[i].second;
    }
    sort(m.begin(),m.end(),custom_c);

    int count = 1;
    long long end = m[0].second;
    for(int i=1;i<n;i++){
        long long s = m[i].first,e = m[i].second;
        if(s>=end){
            count++;
            end = e;
        }
    }
    cout<<count<<endl;
    
}