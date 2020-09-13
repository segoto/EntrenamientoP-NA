#include <bits/stdc++.h>

using namespace std;
#define  ll long long
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll L, n, d;
    cin>>L>>n>>d;
    while(L+n+d){
        ll ans = 10000000000;
        ll real_a = ans;
        ll b = ans;
        for(ll i = 1 ; i <= n; ++i){
            ll a = (i*d + L -1)/ L;
            if((a*L)- (i*d) < ans){
                ans = (a*L)- (d*i);
                real_a = a;
                b = i;
            }
            if(!ans){
                break;
            }
        }
        ll gcd = __gcd(real_a*L, b);
        cout<<(real_a*L)/gcd<<"/"<<b/gcd<<endl;
        cin>>L>>n>>d;
    }



    return 0;
}
