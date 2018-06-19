#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int vist(vector< pair<int , int > > cust,pair<int ,int > home,vector<bool> vis,int i){
    int max=9999;
    int flag=1;
    for(int j=0;j<vis.size();j++){
        if(!vis[j]){
            flag=0;
            vis[j]=true;
            int temp = abs(cust[j].first,cust[i].first)+abs(cust[j].second,cust[i].second)+vist(cust,home,vis,j);
            vis[j]=false;
            if(temp<max) max=temp;
        }
    }
    if(flag==1){
        return abs(cust[i].first, home.first)+abs(cust[i].second,home.second);
    }
    else return max;
}


int location (pair<int ,int > off ,vector< pair<int , int > > cust ,pair<int ,int > home){
    vector<bool> vis(cust.size(),false);
    int max=9999;
    for(int j=0;j<vis.size();j++){
        if(!vis[j]){
            vis[j]=true;
            int temp = abs(cust[j].first,off.first)+abs(cust[j].second,off.second)+vist(cust,home,vis,j);
            vis[j]=false;
            if(temp<max) max=temp;
        }
    }
    return max;
}
int main(){
    pair<int ,int > off (88,81);
    pair<int ,int > home (85,80);
    vector<pair<int ,int > > cust;
    cust.push_back(make_pair(19,22));
    cust.push_back(make_pair(31,15));
    cust.push_back(make_pair(27,29));
    cust.push_back(make_pair(30,10));
    cust.push_back(make_pair(20,26));
    cust.push_back(make_pair(5,14));
    cout<<location(off,cust,home);
}