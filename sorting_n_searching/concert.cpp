#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<long long>price_vec(n);
    vector<long long>cust_vec(m);
    map<long long,int>mappr;
    for(int i=0;i<n;i++){
        cin>>price_vec[i];
        mappr[price_vec[i]]++;
    }
    for(int i=0;i<m;i++){
        cin>>cust_vec[i];
        if(mappr.empty()||cust_vec[i]<mappr.begin()->first){
            cout<<-1<<endl;
            continue;
        }

        auto it = mappr.lower_bound(cust_vec[i]);
        if(it == mappr.end()){
            --it;  // largest ticket
        }
        if(it->first>cust_vec[i]){
            it--;
        } 
        cout<<it->first<<endl;
            it->second--;
            if(it->second==0){
                mappr.erase(it->first);
        }
        
    }

    
}