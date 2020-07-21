#include <bits/stdc++.h>


using namespace std;
vector<int16_t> nul_vector(32);

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
void print(vector<int16_t> a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << '\n';
}

int Poly_deg(vector<int16_t> a) {
    //степень многочлена
    for (int i = 31; i > 0; i--)
        if (a[i])
            return i;
    return 0;
}

void Poly_mul_x(vector<int16_t> &G, int delta, int degG) {
    //Умножение многочлена на x^delta
    //degG = степень G
    for (int i = degG + delta; i >= delta; i--)
        if (G[i - delta]) {
            G[i] = 1;
            G[i - delta] = 0;
        }
}

vector<int16_t> xorim(vector<int16_t> V, vector<int16_t> G) {
    //Xor многочленов - тоже самое, что и сложение
    vector<int16_t> V2(32);
    for (int i = 0; i < 32; i++)
        V2[i] = V[i] ^ G[i];
    return V2;
}


vector<int16_t> Poly_div(vector<int16_t> V, vector<int16_t> G) {
    //Сдвиг знаменталея на x - подбор по старшей степени числителя
    //Затем сложение(вычитание) в Z2
    int degV = Poly_deg(V);
    int degG = Poly_deg(G);
    int delta = degV - degG;
    vector<int16_t>res(32);
    vector<int16_t>copyG = G;
    while(delta >= 0) {
        degV = Poly_deg(V);
        degG = Poly_deg(G);
        delta = degV - degG;
        if (delta < 0) break;
        if (delta == 0) {
            V = xorim(V, G);
            res[0] = 1;
            break; //если числитель стал >= знаменателя
        }
        Poly_mul_x(G, delta, degG);
        res[delta] = 1;
        V = xorim(V, G);
        G = copyG;
    }
    return res;
}


void Poly_mod(vector<int16_t> &V, vector<int16_t> G) {
    //Сдвиг знаменталея на x - подбор по старшей степени числителя
    //Затем сложение(вычитание) в Z2
    int degV = Poly_deg(V);
    int degG = Poly_deg(G);
    int delta = degV - degG;
    vector<int16_t>copyG = G;
    while(delta >= 0) {
        degV = Poly_deg(V);
        degG = Poly_deg(G);
        delta = degV - degG;
        if (delta < 0) break;
        if (delta == 0) {
            V = xorim(V, G);
            break; //если числитель стал >= знаменателя
        }
        Poly_mul_x(G, delta, degG);
        V = xorim(V, G);
        G = copyG;
    }
}

void ymnoz_Z2(vector<int16_t> G, vector<int16_t> A, vector<int16_t> &V) {
    //V(x) = G(x)A(x) + S
    //V(x) -= G(x)A(x)
    //дан третий, из третьего вычитается(складывается) перемножение A на G
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            if (G[i] == 1 && A[j] == 1) {
                V[i + j] += 1;
                V[i + j] %= 2;
            }
        }
    }
}

vector<int16_t> Vector_mul_in_GF2(vector<int16_t> E, vector<int16_t> G) {
    //Перемножение двух многочленов в Z_2
    vector<int16_t> V(32);
    for (int i = 0; i < G.size(); i++) {
        for (int j = 0; j < E.size(); j++) {
            if (G[i] == 1 && E[j] == 1) {
                V[i + j] += 1;
                V[i + j] %= 2;
            }
        }
    }
    return V;
}

int Hamming_sum(vector<int16_t> S) {
    //Вес Хэмминга
    int res = 0;
    for(int i = 0; i < S.size();i++)
        if(S[i]) res++;
    return res;
}

void initializing(vector<int16_t> &G,vector<int16_t> &A, vector<int16_t> &init,vector<int16_t> &V){
    G[11] = 1; G[9] = 1; G[4] = 1; G[3] = 1; G[0] = 1;
    V[20] = 1; V[18] = 1; V[16] = 1; V[14] = 1; V[12] =1; V[10] = 1; V[8] =1; V[4] = 1; V[0] = 1;
    init[21] = 1;
    init[0] = 1;
}


void next_permutation(vector<int16_t> &E, int &k){
    k++;
    for (int i = 0; i < E.size(); ++i) {
        E[i] = (k >> i) & 1;
    }
}

void Minimum_code_dist(vector<int16_t> E, vector<int16_t> G, int &d, int &k){
    vector<int16_t> V;
    while(Hamming_sum(E) != 7) {
        next_permutation(E, k);
        V = Vector_mul_in_GF2(E, G);
        d = min(d, Hamming_sum(V));
    }
}

void gcd_poly_GF2(vector<int16_t> &A, vector<int16_t> &B){

    if(A == B || B == nul_vector || A == nul_vector) {
        return;
    }
    Poly_mod(A, B); // GCD(a,b) = GCD(a%b, b) = ...
    //Poly_mod(A, B);
    gcd_poly_GF2(B, A);
}


void test1() {
    vector<int16_t> X(32),Y(32);
    X[10] = 1;
    X[8] = 1;
    X[7] = 1;
    X[6] = 1;
    X[4] = 1;
    X[2] = 1;
    X[1] = 1;
    X[0] = 1;
    Y[6] = 1;
    Y[0] = 1;
    gcd_poly_GF2(X, Y);
    Y == nul_vector ? print(X) : print(Y);
}


void test2() {
    vector<int16_t> X(32),Y(32);
    X[3] = 1;
    X[0] = 1;
    Y[2] = 1;
    gcd_poly_GF2(X, Y);
    Y == nul_vector ? print(X) : print(Y);
}

void test3() {
    vector<int16_t> X(32),Y(32);
    X[12] = 1;
    X[8] = 1;
    X[7] = 1;
    X[5] = 1;
    X[1] = 1;
    X[0] = 1;
    Y[6] = 1;
    Y[4] = 1;
    Y[0] = 1;
    gcd_poly_GF2(X, Y);
    Y == nul_vector ? print(X) : print(Y);
}

void test4() {
    vector<int16_t> X(32),Y(32);
    X[6] = 1;
    X[4] = 1;
    X[1] = 1;
    X[0] = 1;
    Y[6] = 1;
    Y[4] = 1;
    Y[0] = 1;
    gcd_poly_GF2(X, Y);
    Y == nul_vector ? print(X) : print(Y);
}

int32_t main() {
    vector<int16_t> G(32),A(32),V(32), initial(32);
    int d = 5, k = 0;
    int stepen_yslovie = 21;
    initializing(G,A, initial,V);
    vector<int16_t>copyG = G;
//    test1();
//    test2();
//    test3();
//    test4();
    vector<int16_t> E(stepen_yslovie - Poly_deg(G));
//    ymnoz_Z2(G, A, V);
//    Minimum_code_dist(E, G, d, k);
    cout << "d* = " << d << '\n';
    int kolvo_owibok = (d-1)/2;
    cout << "r = " << kolvo_owibok << '\n';
    vector<int16_t> V_old = V;
    Poly_mod(V, G); // поиск S - синдрома(ищем остаток от деления V(x) / G(x))
    vector<int16_t> S = V;
    print(S);
    V = V_old;
    int degX = 0;
    while (Hamming_sum(S) >= kolvo_owibok) {
        Poly_mul_x(S, 1, Poly_deg(S));
        if(Hamming_sum(S) <= kolvo_owibok) {
            break;
        }
        Poly_mod(S, G);
        print(S);
        degX++;
    }
    cout << "X^" << degX <<  "*S(x) =";
    Poly_mul_x(S, stepen_yslovie - degX, Poly_deg(S));
    Poly_mod(S, initial);
    print(S);
    E = S;
    vector<int16_t> VE = V;
    VE = xorim(VE, E);
    vector<int16_t> res = Poly_div(VE, copyG);
    cout << "Сообщение  = ";
    print(res);
}