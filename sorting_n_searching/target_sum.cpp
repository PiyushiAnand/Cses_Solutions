#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long x;
    cin>>x;
    vector<pair<long long,int> >vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i].first;
        vec[i].second=i+1;
    }
    sort(vec.begin(),vec.end());
    int i=0,j=n-1;
    while(i<j){
        if(vec[i].first+vec[j].first<x)i++;
        else if(vec[i].first+vec[j].first>x)j--;
        else{
            cout<<vec[i].second<<" "<<vec[j].second<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}