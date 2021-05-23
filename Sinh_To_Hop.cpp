/*
Bước 1: Khởi tạo cấu hình ban đầu : 1,2,3,4,…,k-1,k. 

Bước 2: Duyệt dãy từ cuối lên đầu,tìm phần tử thứ i đầu tiên không thỏa mãn a[i]=n - k + i .
Nếu tìm được, thực hiện Bước 3,4,5 .Nếu không tìm được,kết thúc quá trình sinh.
//kiểm tra bằng 1 biến Check,nếu Check == 1 sẽ kết thúc chương trình.

Bước 3: Tăng a[i] vừa tìm được ở bước 2 lên 1 đơn vị. 

Bước 4: Đặt các phần tử đứng sau a[i] tìm được ở Bước 2 bằng giới hạn dưới của chúng : a[j]=a[j-1] + 1. 

Bước 5: In tổ hợp vừa sinh ra màn hình rồi quay lại Bước 2. 
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int Check = 0;
//Hàm khởi tạo cấu hình ban đầu 1,2,3,...,k:
void Init(vector<int> &Arr, int k)
{
    for (int i = 1; i <= k; i++)
        Arr[i] = i;
}

//Hàm in ra các tổ hợp được sinh:
void Show(vector<int> Arr, int k)
{
    for (int i = 1; i <= k; i++)
        cout << Arr[i] << " ";
    cout << endl;
}

//Hàm đặt các phần tử đứng sau a[i] tìm được ở Bước 2 bằng giới hạn dưới của chúng : a[j]=a[j-1] + 1:
void Set(vector<int> &Arr, int k, int i)
{
    for (int j = i + 1; j <= k; j++)
        Arr[j] = Arr[j - 1] + 1;
}

//Hàm sinh:
void Sinh(vector<int> &Arr, int n, int k)
{
    int i = k;
  
  //Bước 2: Duyệt dãy từ cuối lên đầu,tìm phần tử thứ i đầu tiên không thỏa mãn a[i]=n - k + i .
    while (i > 0 && Arr[i] == n - k + i)
        i--;
  
  //Nếu không tìm thấy,gán Check = 1 để kết thúc chương trình:
    if (i == 0)
        Check = 1;
  //Nếu tìm thấy:
    else
    {
      //Bước 3: Tăng a[i] vừa tìm được ở bước 2 lên 1 đơn vị. 
        Arr[i]++;
      
      //BƯớc 4: Đặt các phần tử đứng sau a[i] tìm được ở Bước 2 bằng giới hạn dưới của chúng : a[j]=a[j-1] + 1. 
        Set(Arr, k, i);
    }
}

void ToHop(vector<int> &Arr, int n, int k)
{
    Init(Arr, k);
    while (Check == 0)
    {
      //Bước 5: In ra màn hình tổ hợp vừa tạo ra:
        Show(Arr, k);
        Sinh(Arr, n, k);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> Arr(k + 1);

    ToHop(Arr, n, k);
}
