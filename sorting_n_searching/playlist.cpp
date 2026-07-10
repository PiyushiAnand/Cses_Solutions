#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<long long,int>s;
    int count = 0;
    int l = 0;
    vector<long long>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
        if(s.empty()){
            s[vec[i]]=i;
        }
        else{
            if(s.find(vec[i])==s.end()){
                s[vec[i]]=i;
            }
            else {
                int j = s[vec[i]];
                // cout<<j<<","<<l<<endl;
                if(j>=l){
                l = j+1;
                
                }
                s[vec[i]]=i;
            }
        }
        // cout<<l<<" to "<<i<<endl;
        count = max(count, i-l+1);
    }
    cout<<count<<endl;
}