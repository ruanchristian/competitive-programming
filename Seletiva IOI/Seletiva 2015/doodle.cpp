#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define all(x) x.begin(), x.end()
#define mk make_pair

const int MAX = 1e5+1;

int n, k, d, cnt, bit[MAX];
vector<int> abX, abY;
vector<pair<pair<int,int>, pair<int,int>>> ret, at;
unordered_map<int,int> mpx, mpy;

auto merge(int x1, int y1, int x2, int y2) {
    return mk(mk(x1,y1), mk(x2,y2));
}

void update(int x, int v) {
    for (; x<=cnt+10; x+=(x&-x)) {
        bit[x]+=v;
    }
}

int qry(int x) {
    int soma=0;
    for (; x>0; x-=(x&-x)) {
        soma+=bit[x];
    }
    return soma;
}

int eng(int x) {
    int ans=0;
    vector<pair<pair<int,int>, pair<int,int>>> trk;
    
    for (int i=0; i<x; i++) {
        if(!(i&1)) {
            int x1=ret[i].f.f;
            int y1=ret[i].f.s;
            int x2=ret[i].s.f;
            
            if(x2<x1) swap(x1, x2);
            
            trk.push_back(merge(x1, y1, 0, 0));
            trk.push_back(merge(x2, y1, 0, 1));
        } else {
            int x1=ret[i].f.f;
            int y1=ret[i].f.s;
            int y2=ret[i].s.s;
            
            if(y2<y1) swap(y1, y2);
            
            trk.push_back(merge(x1, y1, y2, 2));
        }
    }
    sort(all(trk));
    
    for (int i=0; i<trk.size(); i++) {
        int t=trk[i].s.s;
        
        if(!t) {
            update(trk[i].f.s, 1);
        } else if(t==1) {
            update(trk[i].f.s, -1);
        } else if(t==2) {
            int l=trk[i].f.s;
            int r=trk[i].s.f;
            
            ans+=qry(max(l,r)-1)-qry(min(l,r));
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>k;
    
    int x=0, y=0;
    abX.push_back(x); abY.push_back(y);
    
    for (int i=0; i<n; i++) {
        cin>>d;
        if(!(i&1)) {
            at.push_back(merge(x, y, x+d, y));
            x+=d;
            abX.push_back(x);
        } else {
            at.push_back(merge(x, y, x, y+d));
            y+=d;
            abY.push_back(y);
        }
    }
    sort(all(abX));
    sort(all(abY));
    
    for (int i=0; i<abX.size(); i++) {
        if(!mpx[abX[i]]) mpx[abX[i]] = ++cnt;
    }
    cnt=0;
    
    for (int i=0; i<abY.size(); i++) {
        if(!mpy[abY[i]]) mpy[abY[i]] = ++cnt;
    }
    
    for (int i=0; i<at.size(); i++) {
        if(!(i&1)) {
            int x1=mpx[at[i].f.f];
            int x2=mpx[at[i].s.f];
            int y1=mpy[at[i].f.s];
            ret.push_back(merge(x1, y1, x2, y1));
        } else {
            int x1=mpx[at[i].f.f];
            int y1=mpy[at[i].f.s];
            int y2=mpy[at[i].s.s];
            ret.push_back(merge(x1, y1, x1, y2));
        }
    }
    
    int l=0, r=n, seg=0, ints=0;
    
    // busca binária na resposta
    while(l<=r) {
        int mid=(l+r)/2;
        int tot=eng(mid);

        if(tot>=k) {
            seg=mid;
            ints=tot;
            r=mid-1;
        } else {
            if(ints<=tot) {
                seg=mid;
                ints=tot;
            }
            l=mid+1;
        }
    }
    
    cout<<seg<<' '<<ints<<endl;
}