#include <bits/stdc++.h>

using namespace std;

// Grande Tratado da Bytelândia - SBC

typedef complex<double> pt;

#define x real()
#define y imag()
#define vec(a,b) ((b)-(a))
#define cp(a,b) ((conj(a)*(b)).imag())

int n;
map<pair<int,int>, int> mp;
set<int> s;

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x==b.x && a.y < b.y);
}

bool ccw(pt a, pt b, pt c) {
    return cp(vec(a,b), vec(b,c)) >= 0;
}

vector<pt> convex_hull(vector<pt> &p) {
    sort(p.begin(), p.end(), cmp);
    p.erase(unique(p.begin(), p.end()), p.end());
    if(p.size() <= 1) return p;
    
    vector<pt> l, u;
    for (int i=0; i<p.size(); i++) {
        while(l.size() > 1 && !ccw(l.end()[-2], l.end()[-1], p[i])) {
            l.pop_back();
        }
        l.push_back(p[i]);
    }
    
    for (int i=p.size()-1; i>=0; i--) {
        while(u.size() > 1 && !ccw(u.end()[-2], u.end()[-1], p[i])) {
            u.pop_back();
        }
        u.push_back(p[i]);
    }
    l.pop_back(); u.pop_back();
    for (pt j : u) l.push_back(j);
    return l;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    
    vector<pt> v(n);
    for (int i=0; i<n; i++) {
        int a, b; cin>>a>>b;
        v[i]=pt(a,b);
        mp[{a,b}]=i+1;
    }
    vector<pt> vv=convex_hull(v);
    
    for (auto it : vv) {
        s.insert(mp[{it.x,it.y}]);
    }
    
    for (int r : s) cout<<r<<' ';

    return 0;
}