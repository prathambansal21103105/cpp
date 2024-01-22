#include <bits/stdc++.h>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    
    bool checkpalindrome(string word){
        bool check=true;
        int n=word.length();
        for(int i=0;i<word.length()/2;i++){
            if(word[i]==word[n-1-i]){
                check=check and true;
            }
        }
        return check;
    }
    bool ifpalindrome(TrieNode*newroot){
        for(int i=0;i<26;i++){
            if(newroot->children[i]!=NULL){
                newroot=newroot->children[i];
            }
        }
        // cout<<"YES12 \n";

        string w="";
        while(newroot->isTerminal==false){
            // cout<<"one \n";
            w=w+newroot->data;
            for(int i=0;i<26;i++){
                if(newroot->children[i]!=NULL){
                    newroot=newroot->children[i];
                }
            }
        }
        if(newroot->isTerminal==true){
            // cout<<"Here \n";

            w=w+newroot->data;
        }
        bool ret=true;
        int n=w.length();
        // cout<<w<<endl;
        if(n==1){
            // cout<<"washere";
            // cout<<'\n';
            return true;
        }
        for(int i=0;i<w.length()/2;i++){
            if(w[i]==w[n-1-i]){
                ret=ret and true;
            }
        }
        return ret;
    }

    bool palindrome(string curr,TrieNode*newroot){
        int check=true;
        for(int j=0;j<curr.length();j++){
            int c=curr[j]-'a';
            if(newroot->children[c]!=NULL){
                check=check and true;
                newroot=newroot->children[c]; // abc c node
                if(newroot->isTerminal==true and j!=curr.length()-1){
                    return checkpalindrome(curr.substr(j+1));
                }
            }
            else{
                return false;
            }
        }
        if(check){
            // cout<<"YES \n";
            if(newroot->isTerminal){
                // cout<<"YES1 \n";
                return true;
            }
            else{
                // cout<<"NO \n";
                return ifpalindrome(newroot);
            }
        }
        return check;
    }
    bool isPalindromePair(vector<string> words) {
        for(int i=0;i<words.size();i++){
            string str=words[i];
            reverse(str.begin(),str.end());
            add(str);
        }
        bool check=false;
        TrieNode*newroot=root;
        for(int i=0;i<words.size();i++){
            string curr=words[i];
            check=check or palindrome(curr,newroot);
        }
        return check;
    }
};
int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}