// Name:Pratham Bansal
// SID:21103105
// Branch:CSE
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
#define int long long
class TrieNode{
    public:
    TrieNode* v[10];
    unordered_map<string,int>names;
    TrieNode(){
        for(int i=0;i<10;i++){
            v[i]=NULL;
        }
    }
};

class PhoneDirectory{
    public:
    TrieNode* root;

    PhoneDirectory(){
        root=new TrieNode();
    }

    void addNumber(int num, string name){
        string x=to_string(num);
        TrieNode* temp=root;
        for(int i=0;i<x.length();i++){
            if(temp->v[x[i]-'0']!=NULL){
                temp=temp->v[x[i]-'0'];
                temp->names[name]++;
            }
            else{
                TrieNode* node=new TrieNode();
                temp->v[x[i]-'0']=node;
                temp=temp->v[x[i]-'0'];
                temp->names[name]++;
            }
        }
    }
    vector<string> searchnumber(int num){
        TrieNode* temp=root;
        string x=to_string(num);
        vector<string>mpty;
        for(int i=0;i<x.length();i++){
            if(temp->v[x[i]-'0']!=NULL){
                temp=temp->v[x[i]-'0'];
            }
            else{
                return mpty;
            }
        }
        for(auto i:temp->names){
            if(i.second>0){
                mpty.push_back(i.first);
            }
        }
        return mpty;
    }
    vector<string>searchprefix(int num){
        return this->searchnumber(num);
    }
    void deleteNumber(int num, string owner){
        string x=to_string(num);
        TrieNode*temp=root;
        for(int i=0;i<x.length();i++){
            temp=temp->v[x[i]-'0'];
            temp->names[owner]--;
        }
    }
    void updateNumber(int oldnum, int newnum, string owner){
        this->deleteNumber(oldnum,owner);
        this->addNumber(newnum,owner);
    }
};

signed main(){
    PhoneDirectory* p1=new PhoneDirectory();
    int t=10;
    int x;
    while(true){
        cout<<"****************-----------------------*****************"<<endl;
        cout<<"Welcome to Phone Directory!"<<endl;
        cout<<"0 to add a contact"<<endl;
        cout<<"1 to search a number"<<endl;
        cout<<"2 to search a prefix"<<endl;
        cout<<"3 to delete a number"<<endl;
        cout<<"4 to update a number"<<endl;
        cout<<"5 to exit Phone Directory"<<endl;
        cout<<"Choose a number:"<<endl;
        cin>>x;
        if(x==0){
            cout<<"Please provide your number:"<<endl;
            int a;
            cin>>a;
            cout<<"Please provide your fullname name:"<<endl;
            string y;
            string x1,x2;
            cin>>x1>>x2;
            y=x1+" "+x2;
            p1->addNumber(a,y);
        }
        else if(x==1){
            cout<<"Please provide your number that you want to search:"<<endl;
            int a;
            cin>>a;
            vector<string> names1=p1->searchnumber(a);
            if(names1.size()==0){
                cout<<"NOT FOUND!!"<<endl;
            }
            else{
                for(auto i:names1){
                    cout<<i<<" ";
                }
                cout<<endl;
            }
        }
        else if(x==2){
            cout<<"Please provide your prefix that you want to search:"<<endl;
            int a;
            cin>>a;
            vector<string>names3=p1->searchprefix(a);
            if(names3.size()==0){
                cout<<"NOT FOUND!!"<<endl;
            }
            else{
                for(auto i:names3){
                    cout<<i<<" | ";
                }
                cout<<endl;
            }
        }
        else if(x==3){
            cout<<"Please provide the number you want to delete:"<<endl;
            int a;
            cin>>a;
            cout<<"Please provide your fullname:"<<endl;
            string y;
            string x1,x2;
            cin>>x1>>x2;
            y=x1+" "+x2;
            p1->deleteNumber(a,y);
        }
        else if(x==4){
            cout<<"Please provide the old number:"<<endl;
            int a;
            cin>>a;
            cout<<"Please provide the new number:"<<endl;
            int y;
            cin>>y;
            cout<<"Please provide your fullname:"<<endl;
            string owner;
            string x1,x2;
            cin>>x1>>x2;
            owner=x1+" "+x2;
            p1->updateNumber(a,y,owner);
        }
        else{
            cout<<"Thank you!!"<<endl;
            break;
        }
    }
    return 0;
}