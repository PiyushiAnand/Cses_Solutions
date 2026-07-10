#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
#include<set>
using namespace std;

class BIT{
    private:
        vector<int>freq;
        int n;
    public:
        BIT(int num){
            n = num;
            freq.resize(n+1,0);
        }
        void update(int idx){
            while(idx<=n){
                freq[idx]+=1;
                idx+=idx&(-idx);
            }
        }
        int query(int idx){
            int ans=0;
            while(idx>0){
                ans+=freq[idx];
                idx-=idx&(-idx);
            }
            return ans;
        }

};
bool custom_c(vector<long long>&a,vector<long long>&b){
    if(a[0]==b[0]){
        return a[1]>b[1];
    }
    return a[0]<b[0];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    set<long long>endpoints;
    vector<vector<long long> >ranges(n,vector<long long>(3));
    for(int i=0;i<n;i++){
        cin>>ranges[i][0]>>ranges[i][1];
        ranges[i][2]=i;
        endpoints.insert(ranges[i][1]);

    }
    sort(ranges.begin(),ranges.end(),custom_c);
    map<long long,int>endpoint_idx;
    int idx = 1;
    for(auto it:endpoints){
        endpoint_idx[it]=idx;
        idx++;
    }
    
    BIT b = BIT(endpoints.size());
    vector<int>ans1(n);
    vector<int>ans2(n);
    for(int i=ranges.size()-1;i>=0;i--){
        long long end = ranges[i][1];
        int idx = endpoint_idx[end];
        // cout<<"inserting index"<<idx<<endl;
        
        ans1[ranges[i][2]]=b.query(idx);
        b.update(idx);
    }
    BIT b2 = BIT(endpoints.size());
    for(int i=0;i<ranges.size();i++){
        long long end = ranges[i][1];
        int idx = endpoint_idx[end];
        // cout<<"inserting index"<<idx<<endl;
        
        ans2[ranges[i][2]]=i-b2.query(idx-1);
        b2.update(idx);
    }

    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i]<<" ";
    }



}