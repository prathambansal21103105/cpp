#include<iostream>
#include<vector>
using namespace std;


bool func(vector<int>&v1, vector<int>&v2){
    return v1[0]<v2[0];
}
vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
    if(intervals.size()==0){
        intervals.push_back(newInterval);
        return intervals;
    }
    int st=newInterval[0];
    int en=newInterval[1];
    int flag=0;
    if(intervals.size()==1){
        int i=0;
        int st1=intervals[i][0];
        int en1=intervals[i][1];
        if(en<st1){
            intervals.push_back(newInterval);
            sort(intervals.begin(),intervals.end(),func);
        }
        if(st>en1){
            intervals.push_back(newInterval);
            sort(intervals.begin(),intervals.end(),func);
        }
        if(st<st1 and en>en1){
            intervals[i][0]=st;
            intervals[i][1]=en;
        }
        else if(st>=st1 and st<=en1){
            intervals[i][1]=max(en,en1);
        }      
        else if(en>=st1 and en<=en1){
            intervals[i][0]=min(st,st1);
        }
        return intervals;
    }
    vector<vector<int> >v;
    for(int i=0;i<intervals.size();i++){
        int st1=intervals[i][0];
        int en1=intervals[i][1];
        if(st>=st1 and st<=en1){
            intervals[i][1]=max(en,en1);
            flag=1;
            break;
        }
        if(en>=st1 and en<=en1){
            intervals[i][0]=min(st,st1);
            flag=1;
            break;
        }
        if(st<st1 and en>en1){
            intervals[i][0]=st;
            intervals[i][1]=en;
            flag=1;
            break;
        }
        if(st>=st1 and en<=en1){
            flag=1;
            break;
        }
    }
    if(flag==0){
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),func);
        return intervals;
    }
    else{
        sort(intervals.begin(),intervals.end(),func);
        int j=0;
        int k=1;
        while(k<intervals.size()){
            if(intervals[k][0]<=intervals[j][1]){
                intervals[j][1]=max(intervals[j][1],intervals[k][1]);
                if(k==intervals.size()-1){
                    v.push_back(intervals[j]);
                    break;
                }
                else if(k<intervals.size()-1){
                    k+=1;
                }
                else{
                    break;
                }
            }
            else{
                v.push_back(intervals[j]);
                j=k;
                if(k==intervals.size()-1){
                    v.push_back(intervals[k]);
                    break;
                }
                else if(k<intervals.size()-1){
                    k+=1;
                }
                else{
                    break;
                }
            }
        }
        return v;
    }
}

int main(){
    int n;
    cin>>n;

    vector<vector<int> > v;
    for(int i=0;i<n;i++){
        vector<int>v1;
        int a,b;
        cin>>a>>b;
        v1.push_back(a);
        v1.push_back(b);
        v.push_back(v1);
    }
    int x,y;
    cin>>x>>y;

    vector<int>newint;
    newint.push_back(x);
    newint.push_back(y);
    sort(v.begin(),v.end(),func);
    vector<vector<int> >ans=insert(v,newint);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

/*
2
1 3
6 9
2 5

5
1 2
3 5
6 7
8 10
12 16
4 8
*/
