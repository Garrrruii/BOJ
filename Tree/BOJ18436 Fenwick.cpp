#include <iostream>
using namespace std;

int N, fen[100001], a[100001];
void upd_(int idx, bool add){
    if(add){
        while(idx<=N) fen[idx]++, idx+=(idx&-idx);
    }
    else {
        while(idx<=N) fen[idx]--, idx+=(idx&-idx);
    }
}
int sum_(int l, int r){ //l+1~r cnt odd num
    int ret=0;
    while(r) ret+=fen[r], r-=(r&-r);
    while(l) ret-=fen[l], l-=(l&-l);
    return ret;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin>>N;
    for(int i=1;i<=N;++i) {
        cin>>a[i];
        if(a[i]&1) upd_(i,1);
    }
    int M, q, l, r;
    cin>>M;
    while(M--){
        cin>>q>>l>>r;
        if(q<2){
            if((a[l]&1) && !(r&1)) upd_(l,false);
            else if(!(a[l]&1) && (r&1)) upd_(l,true);
            a[l]=r;
        }
        else if(q==2){ l--; cout<<r-l-sum_(l,r)<<"\n"; }
        else{ l--; cout<<sum_(l,r)<<"\n"; }
    }
    return 0;
}
