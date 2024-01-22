class TrieNode{
    public:
    // int x;
    TrieNode* a[26];
    bool flag=false;
    public:
    TrieNode(){
        // cout<<"Created"<<endl;
        // x=1;
        for(int i=0;i<26;i++){
            a[i]=NULL;
        }
    }
    public:
    bool contains(char x){
        // cout<<"YES1"<<endl;
        if(a[x-'a']==NULL){
            return false;
        }
        else{
            return true;
        }
    }
    
    void put(char x, TrieNode* node){
        a[x-'a']=node;
    }
    
    void set(){
        flag=true;
    }
    
    TrieNode* get(char x){
        return a[x-'a'];
    }
    
    bool set1(){
        if(flag==true){
            return true;
        }
        else{
            return false;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        // cout<<root->x<<endl;
        for(int i=0;i<word.length();i++){
            // cout<<word[i]<<endl;
            if(!node->contains(word[i])){
                node->put(word[i],new TrieNode());
            }
            node=node->get(word[i]);
            if(i==word.length()-1){
                node->set();
            }
        }
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->contains(word[i])){
                return false;
            }
            else{
                node=node->get(word[i]);
            }
            if(i==word.length()-1){
                if(node->set1()){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->contains(prefix[i])){
                return false;
            }
            else{
                node=node->get(prefix[i]);
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */