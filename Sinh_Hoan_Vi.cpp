/*
Bước 1: Khởi tạo cấu hình đầu tiên: 1,2,3,…,n-1,n. 

Bước 2: Xét từ cuối dãy lên đầu dãy,tìm phần tử đầu tiên làm mất tính không giảm của dãy,đánh dẫu phần tử đó và thực hiện Bước 3.
Nếu không tìm được,kết thúc quá trình sinh. //Sẽ check bằng 1 biến Check,nếu Check == 1 tức là không tìm được a[i] thoả mãn.

Bước 3: Duyệt từ cuối dãy lên đầu dãy,tìm phần tử đầu tiên lớn hơn phần tử được dánh dấu ở Bước 2,đổi chỗ 2 phần tử đó. 

Bước 4 : Từ vị trí phần tử tìm được ở bước 2,sắp xếp tăng dần từ vị trí đó cho đến cuối dãy.

Bước 5: In ra hoán vị vừa tạo được ở Bước 3,4 rồi quay lại Bước 2. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int Check = 0;

void Init(vector<int> &Arr, int n)
{
    for (int i = 1; i <= n; i++)
        Arr[i] = i;
}

//In ra hoán vị:
void Show(vector<int> Arr, int n)
{
    for (int i = 1; i <= n; i++)
        cout << Arr[i];
    cout << endl;
}

//Bước 3.1: Duyệt từ cuối dãy lên đầu dãy,tìm phần tử đầu tiên lớn hơn phần tử được dánh dấu ở Bước 2.
int FindMin(vector<int> Arr, int n, int i)
{
    while (Arr[i] > Arr[n])
        n--;
    return n;
}

void Sinh(vector<int> &Arr, int n)
{
  //Bước 2: Xét từ cuối dãy lên đầu dãy,tìm phần tử đầu tiên làm mất tính không giảm của dãy,đánh dẫu phần tử đó và thực hiện Bước 3:
    int i = n - 1;
    while (i > 0 && Arr[i] > Arr[i + 1])
        i--;
  
  //Nếu không tì thấy a[i] thoả mãn, gán Check=1 để kết thúc chương trình:
    if (i == 0)
        Check = 1;
    else
    {
      //Bước 3.2: Đổi chỗ phần tử được đánh dấu ở bước 2 và phần tử vừa tìm được ở bước 3.1:
        swap(Arr[i], Arr[FindMin(Arr, n, i)]);
      
      //Bước 4:  Từ vị trí phần tử tìm được ở bước 2,sắp xếp tăng dần từ vị trí đó cho đến cuối dãy:
        sort(Arr.begin() + i + 1, Arr.end());
    }
}

void HoanVi(vector<int> &Arr, int n)
{
    Init(Arr, n);
    while (Check == 0)
    {
        Show(Arr, n);
        Sinh(Arr, n);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> Arr(n + 1);
  
  //Bước 1: Khởi tạo cấu hình đầu tiêb:
    Init(Arr, n);
  
  //Bắt đầu sinh và in ra hoán vị:
    HoanVi(Arr, n);
}
