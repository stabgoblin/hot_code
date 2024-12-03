#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define vull vector<unsigned long long>
#define pb push_back
#define mp make_pair
#define fwdi(a,b) for(int i=a;i<b;i++)
#define el "\n"
#define sp <<" "
#define co cout<<
#define ci cin>>
#define all(arr) arr.begin(),arr.end()
#define rall(arr) arr.rbegin(),arr.rend() 
 
using namespace std;
 
int d(int n){int ans = 0;int i=1;while(i*i<n){if(n%i == 0){ans++;ans++;}i++;}if(i*i == n){ans++;}return ans;}
 
void solve(){
	//	ifstream cin("input.txt");
	// 	ofstream cout("output.txt");
	//	solution here
    // pattern to find :
    
    // do int x int and store result
    // step 1 : I can iterate untill i find "mul(" pattern then 
    // step 2 : store whatever comes next into a string a untill that whatever is comma
    // in between if some non digit comes I go to step 1
    // step 3 : again iterate untill I find closing B and store whatever comes into
    // a string b if that whatever is not digit then go to step 1
    // step 4 : do sum += stoi(a)*stoi(b)
    // mul(1,1)
    // first part = 173529487
    string s;
    int ans = 0;
    bool flag = true;
    while(ci s){
        int n = s.size(); 
        int i=0;
        
        while(i<n-5){
            if(s[i] == 'd' and s[i+1]=='o' and s[i+2]=='(' and s[i+3] == ')'){
                flag = true;
                i++;
            }
            if(s[i] == 'd' and s[i+1] == 'o' and s[i+2] == 'n' and s[i+3] == '\'' and s[i+4] == 't' and s[i+5] == '(' and s[i+6] == ')'){
                flag = false;
                i++;
            }
            if(s[i]=='m' and s[i+1]=='u' and s[i+2]=='l' and s[i+3]=='(' and flag){
                int j = i+4;
                string a,b;
                while(s[j]>='0' and s[j]<='9'){
                    a.pb(s[j]);
                    j++;
                }
                if(s[j]==','){
                    // proceed
                    j++;
                    while(s[j]>='0' and s[j]<='9'){
                        b.pb(s[j]);
                        j++;
                    }
                    if(s[j]==')'){
                        if(a.size()<=3 and b.size()<=3)
                            ans += stoi(a) * stoi(b);
                        i=j+1;
                    }
                    else{
                        i=j+1;
                    }
                }
                else{
                    i=j+1;
                }
            }
            else{
                i++;
            }
        }
    }
    co ans;
 }
        
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    
	int t=1;
	// cin>>t; //if multiple test cases
	while(t--){
		solve();
	}
}
