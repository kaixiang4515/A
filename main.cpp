//#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
#include <algorithm>
#include <vector>
//#include <iomanip>

//#define LOCAL
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;

template <class T>
void insertion_sort(T& v, int len){
    for(int i=1;i<len;++i){
        int j=i,t=v[i];
        while(j && t<v[j-1]){
            v[j] = v[j-1];
            --j;
        }
        v[j] = t;
    }
}

template <class T>
void selection_sort(T& v, int len){
    for(int i=0;i<len-1;++i){
        int t=i;
        for(int j=i+1;j<v.size();++j)
            if(v[j] < v[t]) t=j;

        swap(v[t],v[i]);
    }
}

template <class T>
void bubble_sort(T& v, int len){
    for(int i=len-1;i;--i){
        for(int j=0;j<i;++j){
            if(v[j] > v[j+1])
                swap(v[j], v[j+1]);
        }
    }
}
/*
template <class T>
class myTclass{
    T v
};
*/
template <class T1, class T2>
void merge_sort(T1& v, int f, int e, T2 tmp){
    if(f<e){
        int mid = (f+e)/2;
        merge_sort(v, f, mid, tmp);
        merge_sort(v, mid+1, e, tmp);

        vector<T2> vt;
        int l=f,r=mid+1;
        while(l<=mid && r<=e){
            if(v[l]<v[r]) vt.push_back(v[l++]);
            else vt.push_back(v[r++]);
        }
        while(l<=mid) vt.push_back(v[l++]);
        while(r<=e) vt.push_back(v[r++]);
        REP(i,vt.size()) v[f+i] = vt[i];
    }
}

//vector<int> a,b;
int a[1000000],b[1000000];

int main(){
    #ifdef LOCAL
        //freopen("./file/in.txt","r",stdin);
        //freopen("./file/out.txt","w",stdout);
    #endif // LOCAL
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout << fixed << setprecision(3);

    srand( time(NULL) );
    int n,t;
    bool ok = 1;
    cin >> t >> n;
    while(t--){
        //a.clear(), b.clear();
        REP(i,n){
            int m = rand() % 99 + 1;
            /*a.push_back(m);
            b.push_back(m);*/
            a[i]=b[i]=m;
        }
        merge_sort(a,0,n-1,a[0]);
        sort(b, b+n);
        REP(i,n){
            if(a[i] != b[i]){
                ok = false;
                break;
            }
        }
        cout << t+1 << ": ";
        if(ok) cout << "correct!\n";
        else cout << "error!!\n";
    }
    if(ok) cout << "correct!\n";


    return 0;
}
