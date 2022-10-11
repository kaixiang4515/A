#include <iostream>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <windows.h>

#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;

template <class T>
void insertion_sort(T& v, int len){
    for(int i=1;i<len;++i){
        int j=i;
        auto t=v[i];
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
        for(int j=i+1;j<len;++j)
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

//float a[500000];
//vector<float> a;
array<float,500000> a;

int main(){
    freopen("./file/out.txt","w",stdout);
    cout << fixed << setprecision(8);
    srand( time(NULL) );

    const int nums[11]={10,20,30,40,50,60,100000,200000,300000,400000,500000};

    for(auto n:nums){
        clock_t ct,cs=0;
        int cnt=1; //重複次數
        if(n<100) cnt = 5000;
        REP(k,cnt){
            REP(i,n){
                /*string ts(6,0);
                REP(j,6){
                    int t = rand() %52;
                    if(t<26) ts[j] = 'A'+t;
                    else ts[j] = 'a'+t-26;
                }*/
                a[i] = (float)(30000.0 - 1) * rand() / (RAND_MAX + 1.0) + 1;
                //a.push_back((float)(30000.0 - 1) * rand() / (RAND_MAX + 1.0) + 1);
                //cout << a[i] << " ";
            }
            //cout << "\n\n====================================\n\n";
            ct = clock();
            //insertion_sort(a,n);
            //selection_sort(a,n);
            //bubble_sort(a,n);
            merge_sort(a,0,n-1,a[0]);
            cs += clock() - ct;
            /*if(n>100){
                Beep(5000,500);
                Beep(5000,500);
            }*/
        }
        //REP(i,n) cout << a[i] << "\n";

        cout << " " << n << "筆資料, " << "used time: " << 1.0*cs/cnt/CLOCKS_PER_SEC << "\n";
    }
    return 0;
}
