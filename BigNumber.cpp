#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int OO = 1e9 + 7 , N = 2e5 + 5;

void File(){
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
} 

class BitsNumber{
public:

    ll number ;
    int zero, size;

    BitsNumber(){
        zero = number = size = 0;
    }

    BitsNumber(ll num){
        zero = size = 0;

        while(!(num &1)){
            num>>=1;
            incrementZeroes();
        }

        number = num;

        while(num){
            incrementSize();
            num>>=1;
        }

    }
    void addZeros(int x){
        zero+=x;
        size+=x;
    }
    void incrementZeroes(){
        size++;
        zero++;
    }
    void incrementSize(){
        size++;
    }
     
};

class BigNumber{
    BitsNumber number;
public:
    BigNumber(){
        number = BitsNumber();
    }
    BigNumber(ll num){
        number = BitsNumber(num);
    }

    int sz(int num){
        int c =0;
        while(num)
            c++ , num>>=1;

        return c;
    }

    bool operator==(BigNumber a){
        BitsNumber num = a.number;

        return num.zero == number.zero && num.number == number.number;
    }

    bool operator<(BigNumber aa){
        BitsNumber num = aa.number;

        if(number.size < num.size)
            return true;

        else if(number.size > num.size)
            return false;


        int sza = sz(number.number) , szb = sz(num.number);
        
        ll a = number.number , b = num.number;

        while(sza != szb){
            if(sza < szb)
                sza++ , a<<=1;
            else
                szb++ , b<<=1;
        }

        return a<b;
    }

    int makeMeBigerThan(BigNumber a){
        BitsNumber num = a.number;

        int extra = 0;
        int diff = max(num.size - number.size , 0);
        extra+=diff;
        number.addZeros(diff);


        if(*this < a){

            number.incrementZeroes();
            extra++;
        }

        return extra;
    }

};
 
int Solve(int test){
    
    int n;cin>>n;
    BigNumber prev , cur;

    ll res = 0;

    for(int x , i=0;i<n;i++){
        cin>>x;

        prev = cur;

        cur = BigNumber(x);

        if(i == 0)
            continue;

        if(cur < prev){
            res+= cur.makeMeBigerThan(prev);
        }

    }

    cout<<res<<'\n';
   
    
    return 0;
}
 

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    File();

    int t = 1, i = 1;
    cin >> t;
    while (t--)
        Solve(i++);

    return 0;
}
// Solve on paper first
// Verify Your thought before Coding
// Reverse Thinking
// If there's an equation, transform it into an easy one