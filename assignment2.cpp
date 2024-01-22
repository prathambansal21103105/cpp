/*------------Pratham Bansal-----------------*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
double eps = 1e-12;
#define endl "\n"
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

template <int MOD=1000000007>
struct Modular {
  int value;
  static const int MOD_value = MOD;

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Modular mexp(Modular a, long long e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};

Modular<>z=1;
Modular<>y=0;

int Mex(vector<int> a) {
    sort(a.begin(), a.end());
    if(a[0] > 0) return 0;
    for (int i = 1; i < (int) a.size(); i++) {
        if (a[i] > a[i - 1] + 1) {
            return a[i - 1] + 1;
        }
    }
    return a.back() + 1;
}
void binary(vector<int>&v, int& target, int& val1, int st, int end){
    if(st<=end){
        int mid=(st+end)/2;
        if(v[mid]<=target){
           val1=max(val1,v[mid]);
           binary(v,target,val1,mid+1,end);
        }
        else{
           binary(v,target,val1,st,mid-1);
        }
    }
    else{
        return;
    }
}
void remove(vector<long>&v, int index1){
    v.erase(v.begin()+index1);
}
int binexp(int a, int b, int M){
  if(b==0){
     return 1;
  }
  long long x=binexp(a,b/2,M)%M;
  if(b&1){
      return ((((a%M)*(x%M))%M)*(x%M))%M;
  }
  else{
      return ((x%M)*(x%M))%M;
  }
}
/*     bin=pow(b,m-2)     */
int sum(int bit[], int index){
    int sum1=0;
    for(int i=index;i>0;i-=(i&(-i))){
      sum1+=bit[i];
    }
    return sum1;
}
/*To add a val to index i*/
void update(int bit[], int index, int last, int x){
    for(int i=index;i<=last;i+=(i&(-i))){
        bit[i]+=x;
    }
}

long long GCD(long long x, long long y){
   if(y==0){
       return x;
   }
   return GCD(y, x%y);
}
long long LCM(long long x, long long y){
   return x*y/GCD(x,y);
}
bool isPrime(int n){
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
void primefactors(vector<int>& v, int x){
    while(x%2==0){
        v.pb(2);
        x/=2;
    }
    for(int i=3;i<=sqrt(x);i+=2){
        while(x%i==0){
            v.pb(i);
            x/=i;
        }
    }
    if(x>2){
        v.pb(x);
    }
}
string getbin(int val){
    string str;
    for(int i=0;i<32;i++){
        if((val & (1<<i)) !=0){
            str='1' + str;
        }
        else{
            str='0' + str;
        }
    }
    return str;
}
/*------------code-----------------*/

class TrieNode
{
public:
    char nameAplhabet;
    unordered_map<string, vector<string> > contacts;
    vector<TrieNode *> children;
    TrieNode(char data)
    {
        this->nameAplhabet = data;

        for (int i = 0; i < 26; i++)
        {
            children.push_back(NULL);
        }
    }
};

class PhoneDirectory
{

public:
    unordered_map<string, string> directoryPhoneNumberSearch;
    TrieNode *root;
    PhoneDirectory()
    {
        root = new TrieNode('\0');
    }
    void insert(TrieNode *root, string &Name, string &contactNumber, int index, int n)
    {
        if (index >= n)
        {
            // root->Contacts.push_back({Name,contactNumber});
            return;
        }
        if (Name[index] == ' ')
        {
            insert(root, Name, contactNumber, index + 1, n);
            return;
        }

        int loc = Name[index] - 'a';
        if (Name[index] >= 65 && Name[index] <= 90)
        {
            loc += 32;
        }
        if (root->children[loc] == NULL)
        {
            root->children[loc] = new TrieNode(Name[index]);
        }
        root->children[loc]->contacts[Name].push_back(contactNumber);
        insert(root->children[loc], Name, contactNumber, index + 1, n);
    }

    void search(string &name, TrieNode *root, int index, int n)
    {
        if (index >= n)
        {
            int m = root->contacts[name].size();
            vector<string> numbers = root->contacts[name];
            if (m > 0)
            {
                cout << "Following contacts were found for: " << name << endl;
                for (int i = 0; i < m; i++)
                {
                    cout << numbers[i] << endl;
                }
            }
            else
            {
                cout << "No contacts were found for: " << name << endl;
            }
            return;
        }

        if (name[index] == ' ')
        {
            search(name, root, index + 1, n);
            return;
        }

        int loc = name[index] - 'a';
        if (name[index] >= 65 && name[index] <= 90)
        {
            loc += 32;
        }
        if (root->children[loc] == NULL)
        {
            cout << "No contacts were found for: " << name << endl;
        }
        else
        {
            search(name, root->children[loc], index + 1, n);
        }
    }

    void search(string &name)
    {
        search(name, root, 0, name.length());
    }
    void prefixsearch(string &name, TrieNode *root, int index, int n)
    {
        if (index >= n)
        {
            if (root->contacts.size() == 0)
            {
                cout << "No details for prefix " << name << " !" << endl;
            }
            else
            {
                unordered_map<string, vector<string> >::iterator dk = root->contacts.begin();
                cout << "The following details were found" << endl;
                while (dk != root->contacts.end())
                {
                    for (int i = 0; i < dk->second.size(); i++)
                    {
                        cout << dk->first << " " << dk->second[i] << endl;
                    }
                    dk++;
                }
            }
            return;
        }

        if (name[index] == ' ')
        {
            prefixsearch(name, root, index + 1, n);
            return;
        }

        int loc = name[index] - 'a';
        if (name[index] >= 65 && name[index] <= 90)
        {
            loc += 32;
        }
        if (root->children[loc] == NULL)
        {
            cout << "No details for prefix " << name << " !" << endl;
        }
        else
        {
            prefixsearch(name, root->children[loc], index + 1, n);
        }
    }
    void prefixSearch(string &prefix)
    {
        prefixsearch(prefix, root, 0, prefix.length());
    }
    void searchwithContact(string &number)
    {
        if (directoryPhoneNumberSearch.count(number) == 0)
        {
            cout << "No details found!" << endl;
            return;
        }
        cout << "The person corressponding to the Number :" << number << " is :" << directoryPhoneNumberSearch[number] << endl;
    }
    void insert(string &Name, string &contactNumber)
    {
        directoryPhoneNumberSearch[contactNumber] = Name;
        insert(root, Name, contactNumber, 0, Name.length());
    }

    void deleteContact(TrieNode *root, string &Name, string &Number, int index, int n)
    {
        if (index >= n)
        {
            return;
        }
        if (Name[index] == ' ')
        {
            deleteContact(root, Name, Number, index + 1, n);
            return;
        }
        int loc = Name[index] - 'a';
        if (Name[index] >= 65 && Name[index] <= 90)
        {
            loc += 32;
        }
        if (root->children[loc] == NULL)
        {
            return;
        }
        // root->children[loc]->contacts[Name].erase()
        vector<string> temp;
        for (int i = 0; i < root->children[loc]->contacts[Name].size(); i++)
        {
            if (root->children[loc]->contacts[Name][i] != Number)
            {
                temp.push_back(root->children[loc]->contacts[Name][i]);
            }
        }
        root->children[loc]->contacts[Name] = temp;

        deleteContact(root->children[loc], Name, Number, index + 1, n);
    }
    void deletecontact(string &Name, string &Number)
    {
        directoryPhoneNumberSearch.erase(Number);
        deleteContact(root, Name, Number, 0, Name.length());
    }
    void update(string &name, string &oldContact, string &newContact)
    {
        deletecontact(name, oldContact);
        insert(name, newContact);
    }
};

int main()
{
    PhoneDirectory directory;

    while (true)
    {
        cout << "                             Welcome!" << endl;
        cout << "Choose your action" << endl;
        cout << "1) Insert" << endl;
        cout << "2) Search with Name" << endl;
        cout << "3) Search with Prefix" << endl;
        cout << "4) Search with Phone Number" << endl;
        cout << "5) Update Contact" << endl;
        cout << "6) Delete Contact" << endl;
        cout << "Any other number to exit" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the name of contact" << endl;
            string name;
            cin >> name;
            string number;
            cout << "Enter the number of contact" << endl;
            cin >> number;
            directory.insert(name, number);
        }
        else if (choice == 2)
        {
            cout << "Enter the name of contact" << endl;
            string name;
            cin >> name;
            // getline(cin,name);

            directory.search(name);
        }
        else if (choice == 3)
        {
            cout << "Enter the prefix of contact" << endl;
            string name;
            cin >> name;
            // getline(cin,name);

            directory.prefixSearch(name);
        }
        else if (choice == 4)
        {
            cout << "Enter the number of contact" << endl;
            string name;
            cin >> name;

            directory.searchwithContact(name);
        }
        else if (choice == 5)
        {
            cout << "Enter the name of contact" << endl;
            string name;
            // getline(cin,name);
            cin >> name;
            string number, newNumber;
            cout << "Enter the old number of contact" << endl;
            cin >> number;
            cout << "Enter the new number of contact" << endl;
            cin >> newNumber;
            directory.update(name, number, newNumber);
        }
        else if (choice == 6)
        {
            cout << "Enter the name of contact" << endl;
            string name;
            // getline(cin,name);
            cin >> name;
            string number;
            cout << "Enter the number of contact" << endl;
            cin >> number;
            directory.deletecontact(name, number);
        }
        else
        {
            cout << "Thank You!" << endl;
            break;
        }
    }

    return 0;
}