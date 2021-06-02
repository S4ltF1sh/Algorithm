//https://twitter.com/tamasgorbe/status/1259143589772345344
/*
Tìm số Fibonacci thứ n dựa trên công thức  

{(0,1) , (1,1)} ^ n * {(F0),(F1)} = {(Fn),(Fn + 1)} 

//Với F0=0,F1=1 thì => chỉ cần tính A ^ n = {(0,1) , (1,1)} ^ n rồi in ra A[0][1] là được
vì lúc đó Fn = A[0][0] * F0 + A[0][1] * F1 = A[0][1]. 
*/


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const long long MOD = 1e9 + 7;
//khởi tạo ma trận gốc {(0,1),(1,1)}:
struct MATRIX
{
    long long tmp[2][2] = {{0, 1}, {1, 1}};
};

//hàm tính tích 2 ma trận:
MATRIX Multi(MATRIX a, MATRIX b, int n)
{
    MATRIX Res;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            Res.tmp[i][j] = 0;
            for (int k = 0; k < n; k++)
                Res.tmp[i][j] = (Res.tmp[i][j] + a.tmp[i][k] * b.tmp[k][j]) % MOD;
        }
    return Res;
}

//hàm tính A^n: (Dùng công thức chia để trị:
//A^n = (A^[n/2])^2 nếu n % 2 == 0.
//A^n = A*(A^[n-1])
MATRIX POW(MATRIX a, int k, int n)
{
    if (k == 1)
        return a;
    if (k % 2 == 0)
    {
        MATRIX x = POW(a, k / 2, n);
        return Multi(x, x, n);
    }
    else
    {
        return Multi(a, POW(a, k - 1, n), n);
    }
}
void Run()
{
    long long k;
    cin >> k;
    MATRIX a;
    a = POW(a, k, 2);
    cout << a.tmp[0][1] << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Run();
}
