/*
Bước 1: Khởi tạo cấu hình đầu tiên: 11111...11(k số 1) 

Bước 2: Duyệt từ đầu đến cuối tìm phần tử đầu tiên khác n.Nếu tìm thấy,tiếp tục thực hiên các bước sau.
Nếu không tìm thấy,kết thúc chương trình vì đã đạt được cấu hình cuối cùng.

Bước 3: Tăng phần tử vừa tìm được ở bước 2 lên 1 đơn vị,đồng thời biến tất cả các phần tử đứng sau nó thành 1. 

Bước 4: Quay lại bước 2. 
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//hàm khởi tạo cấu hình đầu tiên gồm k chữ số 1.
void Init2(vector<int> &Arr, int k)
{
    for (int i = 0; i < k; i++)
        Arr[i] = 1;
}
//hàm in ra các chỉnh hợp lặp sau khi sinh:
void Show2(vector<int> Arr)
{
    for (int i = 0; i < Arr.size(); i++)
        cout << Arr.at(i);
    cout << endl;
}
//hàm thực hiện biến đổi các phần tử đứng sau phần tử được đánh dấu ở bước 2 thành 1:
void set_1(vector<int> &Arr, int j)
{
    for (; j < Arr.size(); j++)
        Arr.at(j) = 1;
}
//hmaf sinh các chỉnh hợp lặp:
void Sinh2(vector<int> &Arr, int n, int k, int &Check2)
{
    int j = n - 1;
  //Bước 2:tìm phần tử đầu tiên từ cuối dãy có giá trị khác n:
    while (j >= 0 && Arr[j] == n)
        j--;
  //nếu không tìm thấy thì gán Check2=1 để kết thúc chương trình:
    if (j < 0)
        Check2 = 1;
  //Nếu không thực hiện Bước 3:
    else
    {
        Arr.at(j) += 1;
        set_1(Arr, j + 1);
    }
}
int main()
{
    int n, k, Check2 = 0;
    cin >> n >> k;
    vector<int> Arr(k);
  //Bước 1:khởi tạo cấu hình đầu tiên gồm k chữ số 1:
    Init2(Arr, k);
    while (Check2 == 0)
    {
        Show2(Arr);
        Sinh2(Arr, n, k, Check2);
    }
    return 0;
}
