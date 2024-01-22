int countPairs(vector<int>&v,int target){
    map<int,int>amap;
    for(auto i:v){
        amap[i]++;
    }
    int res=0;
    for(auto i:amap){
        if(amap.count(i.first-target)!=0){
            if(i.first-target==i.first){
                res+=((i.second*(i.second-1))/2);
            }
            else{
                res+=(i.second*(amap[i.first-target]));
            }
        }
    }
    return res;
}
vector<string>preprocessDate(vector<string>& dates){
    map<string,string>month;
    month["Jan"]="01";
    month["Feb"]="02";
    month["Mar"]="03";
    month["Apr"]="04";
    month["May"]="05";
    month["Jun"]="06";
    month["Jul"]="07";
    month["Aug"]="08";
    month["Sep"]="09";
    month["Oct"]="10";
    month["Nov"]="11";
    month["Dec"]="12";
    vector<string>res;
    for(int i=0;i<dates.size();i++){
        string date=dates[i];
        vector<string>curr;
        string str="";
        for(int j=0;j<date.length();j++){
            if(date[j]==' '){
                curr.push_back(str);
                str="";
            }
            else{
                str.push_back(date[j]);
            }
        }
        curr.push_back(str);
        string ans="";
        ans+=curr[2];
        ans.push_back('-');
        ans+=month[curr[1]];
        string day=curr[0];
        day.pop_back();
        day.pop_back();
        ans.push_back('-');
        if(day.length()==1){
            day='0'+day;
        }
        ans+=day;
        res.push_back(ans);
    }
    return res;
}