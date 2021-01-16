#include <bits/stdc++.h>
#include "TextTable.h"
using namespace std;
const int maxn = 2e6+5;
vector<int> adj[maxn];
vector<int> tadj[maxn];
bool used[maxn];
stack<int> s;
int order[maxn];
vector<pair<char,char>>op;
vector<pair<int,int>>ch;
string distr;
vector<pair<string,string>>leftOut;


void dfs(int a){
    used[a]=true;
    for(auto x : adj[a]){
        if(! used[x])
        dfs(x);
    }
    s.push(a);
}
void tdfs(int a ,int val){
    order[a]=val;
    for(auto x : tadj[a]){
        if(order[x] == -1)
        tdfs(x,val);
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m,i,a,b;
    cout<<"Enter the number of families : ";
    cin>>n;
    cout<<"Enter the options : ";
    cin>>m;
    char c1,c2;
    for(i=1;i<=n;i++){
        cin >> c1 >> a >> c2 >>b;
        op.push_back({c1,c2});
        ch.push_back({a,b});
        if(c1 == '-' && c2 == '-')
        {
            adj[2*a].push_back(2*b + 1);
            tadj[2*b + 1].push_back(2*a);
            adj[2*b].push_back(2*a + 1);
            tadj[2*a + 1].push_back(2*b);
        }
        else if(c1 == '-' && c2 == '+')
        {
            adj[2*a].push_back(2*b);
            tadj[2*b].push_back(2*a);
            adj[2*b + 1].push_back(2*a + 1);
            tadj[2*a + 1].push_back(2*b +1);
        }
        else if(c1 == '+' && c2 == '-')
        {
            adj[2*a +1].push_back(2*b +1);
            tadj[2*b +1].push_back(2*a +1);
            adj[2*b].push_back(2*a);
            tadj[2*a].push_back(2*b);
        }
        else if(c1 == '+' && c2 == '+')
        {
            adj[2*a +1].push_back(2*b);
            tadj[2*b].push_back(2*a +1);
            adj[2*b + 1].push_back(2*a);
            tadj[2*a].push_back(2*b +1);
        }
    }
    for(i=1;i<=(2*m)+1;i++){
        order[i]=-1;
        if(! used[i])
        dfs(i);
    }
    int j = 1;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        if(order[node] == -1){
        tdfs(node,j);
        j++;
        }
    }
    bool arr[m+1]={false};
    bool check = false;
    for(i=2;i<=(2*m);i += 2){
        if(order[i] == order[i+1]){
            check = true;
        }
        else
          arr[i/2] = order[i] > order[i+1]; 
    }
    for(i=1;i<=m;i++)
    {
        if(arr[i])
          distr += '+';
        else
          distr += '-';
    }
    int cnt = 0;
    for(int i = 0;i<(int)op.size();i++)
    {
        int temp = 0;
        temp += distr[ch[i].first-1] == op[i].first;
        temp += distr[ch[i].second-1] == op[i].second;;
        if(temp == 0)
        {
            cnt++;
            string t1 = op[i].first + to_string(ch[i].first); 
            string t2 = op[i].second + to_string(ch[i].second);
            leftOut.push_back({t1,t2});
        }
    }
    if(check)
    {
        cout<<"The distribution is IMPOSSIBLE as a few families will be left out";
        cout<<"The distribution is : ";
        cout<<distr<<endl;
        cout<<"Number of families with not even 1 choice reflected in the final distribution : "<<cnt<<endl;
        cout<<"They are : "<<endl;
        TextTable t( '-', '|', '+' );
        t.add( "Family No." );
        t.add( "Choice 1" );
        t.add( "Choice 2" );
        t.endOfRow();
        int no = 1;
        for(auto i : leftOut)
        {
            t.add(to_string(no));no++;
            t.add(i.first);
            t.add(i.second);
            t.endOfRow();
        }
        t.setAlignment( 5, TextTable::Alignment::RIGHT );
        cout << t;
    }
    else
    {
        cout<<"The distribution is : ";
        cout<<distr<<endl;
        cout<<"No family was left out."<<endl;   
    }
    return 0;
}