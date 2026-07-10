#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
#include<queue>
using namespace std;
bool custom_c(vector<long long>&a,vector<long long>&b){
    if(a[0]==b[0]){
        return a[1]>b[1];
    }
    return a[0]<b[0];
}

int main(){
    priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >pq;
    int n;
    cin>>n;
    vector<vector<long long> >ranges(n,vector<long long>(3));
    for(int i=0;i<n;i++){
        cin>>ranges[i][0]>>ranges[i][1];
        ranges[i][2]=i;

    }
    sort(ranges.begin(),ranges.end(),custom_c);
    vector<int>ans(n);
    int room_no=0;
    int min_rooms=0;

    for(int i=0;i<n;i++){
        // if(!pq.empty())cout<<pq.top().first<<" "<<pq.top().second<<endl;
        if(!pq.empty()&&pq.top().first<ranges[i][0]){
            room_no=pq.top().second;
            pq.pop();
        }
        else room_no = pq.size()+1;
        pq.push(make_pair(ranges[i][1],room_no));
        ans[ranges[i][2]]=room_no;
        // cout<<ranges[i][0]<<","<<ranges[i][1]<<" "<< ans[ranges[i][2]]<<endl;
        min_rooms = max(min_rooms,(int)pq.size());
       
        
    }
    cout<<min_rooms<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
