// ThuattoanPRIM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <queue>
using namespace std;
using ll = long long;
const ll maxnn = 100001;
int n, m,s;
vector<pair<int, int>> adj[maxnn];

void nhap() {
    std::cin >> n >> m>>s;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({ y,w });
        adj[y].push_back({ x,w });
    }
}
void PRIM() { 
    int ketqua = 0;
    vector<ll> mangPRIM(n+1,0);
    vector<ll> bandau(n + 1, 1);
    mangPRIM[s] = 1; bandau[s] = 0;
    int i = 1;
    cout << s << " ";
    while (i <= n - 1) {
        i++;
        priority_queue <pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> Q;
        for (int j = 0; j < n; j++) {
            if (mangPRIM[j]) {
                for (auto it : adj[j]) {
                    int v = it.first;
                    int w = it.second;
                    if(!mangPRIM[v])
                    Q.push({ w,v });
                }            
            }
        }
        pair <int, int> top = Q.top();
        int v = top.second;
        cout << v << " ";
        ketqua += top.first;
        mangPRIM[v] = 1;
        bandau[v] = 0;
       
    }
    cout << "\n" << ketqua;
   
}
int main()
{
    nhap();
    PRIM();
}


