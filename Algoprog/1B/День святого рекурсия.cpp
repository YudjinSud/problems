#include <bits/stdc++.h>

#define int long long

#define start 1605
#define testsN 10

using namespace std;

int brute(int a, int b) {
    int res = 0;
    if(a < start && b > start) a = start;
    else if(b < start) return 0;
    for(int i = a+1; i <= b; i++) {
        if((i - start) % 10 == 0) res++;
    }
    return res;
}

int solution(int a, int b) {
    int res = 0;
    if(a < start && b < start) return 0;
    else if(a < start && b > start) {a = start;res++;}
    if(b - a <= 10){
        if(((a + 1) - start) % 10 == 0  && (a+1) <= b) res++;
        else if(((a + 2) - start) % 10 == 0 && (a+2) <= b) res++;
        else if(((a + 3) - start) % 10 == 0 && (a+3) <= b) res++;
        else if(((a + 4) - start) % 10 == 0 && (a+4) <= b) res++;
        else if(((a + 5) - start) % 10 == 0 && (a+5) <= b) res++;
        else if(((a + 6) - start) % 10 == 0 && (a+6) <= b) res++;
        else if(((a + 7) - start) % 10 == 0 && (a+7) <= b) res++;
        else if(((a + 8) - start) % 10 == 0 && (a+8) <= b) res++;
        else if(((a + 9) - start) % 10 == 0 && (a+9) <= b) res++;
        else if(((a + 10) - start) % 10 == 0 && (a+10) <= b) res++;
    } else {
        res += solution(a, (a+b)/2);
        res += solution((a+b)/2, b);
    }
    return res;
}

void checker() {
    int seed = 89624;
    srand(seed);
    int a, b;
    for(int i = 0; i < testsN; i++) {
        a = rand() % 2000;
        b = rand() % 2000;
        if(a >= b) {
            i--;
            continue;
        }
        cout << a << " " << b << "\n";
        cout << brute(a,b) << "\n";
        cout << solution(a,b) << "\n";
        // assert(brute(a, b) == solution(a, b));
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    // checker();
    cout<<solution(a,b);
    return 0;
}