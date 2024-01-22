#include<iostream>
#include<vector>
using namespace std;

bool checkvalid(char grid[10][10],string word,int &row,int &col, int &start, int &parity){
    int len=word.size();
    // cout<<"Word :"<<word<<endl;
    // cout<<"len"<<" "<<len<<endl;
    //vertical check
    int fi=0;
    int vcount=0;
    // cout<<"row :"<<row<<endl;
    // cout<<"col :"<<col<<endl;
    for(int i=row-1;i>=0;i--){
        if(grid[i][col]=='+'){
            break;
        }
        vcount+=1;
    }
    // cout<<"vcount :"<<vcount<<endl;
    fi=row-vcount;
    int vcount2=vcount;
    int vcount1=0;
    for(int i=row;i<10;i++){
        if(grid[i][col]!='+'){
            vcount1+=1;
        }
        else{
            break;
        }
    }
    vcount+=vcount1;
    // cout<<"vcount :"<<vcount<<endl;
    // cout<<"fi :"<<fi<<endl;
    if(vcount>=len){
        int j=0;
        for(int i=fi;i<row;i++){
            // cout<<"word[j] :"<<word[j]<<endl;
            // cout<<"grid[i][col] :"<<grid[i][col]<<endl;
            if(grid[i][col]==word[j]){
                j++;
            }  
            else{
                j=0;
                if(vcount2!=0){
                    return false;
                }
                break;
            }
        }
        // cout<<j<<endl;
        if(j==0){
            vcount=vcount1;
            if(vcount>=len){
                // cout<<"YES"<<endl;
                start=row;
                parity=0;
                return true;
            }
            else{
                return false;
            }
        }
        else{
            start=fi;
            parity=0;
            return true;
        }
    }
    else{
        // cout<<"horizontal case :"<<endl;
        int hcount=0;
        int hcount1=0;
        for(int i=col-1;i>=0;i--){
            if(grid[row][i]=='+'){
                break;
            }
            else{
                hcount+=1;
            }
        }
        for(int i=col;i<10;i++){
            if(grid[row][i]!='+'){
                hcount1+=1;
            }
            else{
                break;
            }
        }
        // cout<<"hcount :"<<hcount<<endl;
        // cout<<"hcount1 :"<<hcount1<<endl;
        int hi=col-hcount;
        int j=0;
        for(int i=hi;i<col;i++){
            if(word[j]==grid[row][i]){
                j+=1;
            }
            else{
                if(hcount!=0){
                    return false;
                }
                j=0;
                break;
            }
        }
        // cout<<"j :"<<j<<endl;
        if(j==0){
            if(hcount1>=len){
                start=col;
                parity=1;
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(hcount+hcount1>=len){
                start=hi;
                parity=1;
                return true;
            }
            else{
                return false;
            }
        }
    }
    


}
bool findminus(char grid[10][10],int &row, int &col){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(grid[i][j]=='-'){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool solveCrossword(char grid[10][10],vector<string> v,vector<string> filled){
    int r,c;
    if(!findminus(grid,r,c)){
        return true;
    }
    // cout<<r<<" "<<c<<endl;
    int start=0;
    int parity=0;
    for(int i=0;i<v.size();i++){
        char grid1[10][10];
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                grid1[i][j]=grid[i][j];
            }
        }
        if(checkvalid(grid,v[i],r,c,start,parity)){
            // cout<<"parity :"<<parity<<endl;
            if(parity==0){
                for(int j=0;j<v[i].size();j++){
                    grid[start+j][c]=v[i][j];
                }
                // for(int i=0;i<10;i++){
                //     for(int j=0;j<10;j++){
                //         cout<<grid[i][j]<<" ";
                //     }
                //     cout<<endl;
                // }
            }
            else{
                for(int j=0;j<v[i].size();j++){
                    grid[r][start+j]=v[i][j];
                }
                // for(int i=0;i<10;i++){
                //     for(int j=0;j<10;j++){
                //         cout<<grid[i][j]<<" ";
                //     }
                //     cout<<endl;
                // }
            }
            filled.push_back(v[i]);
            string temp=v[i];
            v[i]=v[v.size()-1];
            v[v.size()-1]=temp;
            v.pop_back();
            if(v.size()==0){
                return true;
            }
            // cout<<"size :"<<v.size()<<endl;
            if(solveCrossword(grid,v,filled)){
                return true;
            }
            else{
                // cout<<"BACKTRAC"<<endl;
                for(int i=0;i<10;i++){
                    for(int j=0;j<10;j++){
                        grid[i][j]=grid1[i][j];
                    }
                }
                // for(int i=0;i<10;i++){
                //     for(int j=0;j<10;j++){
                //         cout<<grid[i][j];
                //     }
                //     cout<<endl;
                // }
                v.push_back(filled[filled.size()-1]);
                // string word1=filled[filled.size()-1];
                string temp=v[i];
                v[i]=v[v.size()-1];
                v[v.size()-1]=temp;
                filled.pop_back();
                // if(v[i+1]==word1){
                //     i-=1;
                // }
            }
        }
        else{
            continue;
        }
    }
    return !findminus(grid,r,c);
}
int main(){
    // write your code here
    char grid[10][10];
    for(int i=0;i<10;i++){
        string str;
        cin>>str;
        for(int j=0;j<10;j++){
            grid[i][j]=str[j];
        }
    }
    string s;
    cin>>s;
    vector<string>v;
    string city="";
    for(int i=0;i<s.size();i++){
        if(s[i]==';'){
            v.push_back(city);
            city="";
            continue;
        }
        city+=s[i];
    }
    v.push_back(city);
    vector<string>filled;
    if(solveCrossword(grid,v,filled)){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cout<<grid[i][j];
            }
            cout<<endl;
        }
        
    }
    // for(int i=0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}