#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//Bước 3:In ra kết quả sau mỗi lần sinh:
void Xuat(vector<int> Arr)
{
    for (int i = 0; i < Arr.size(); i++)
        cout << Arr.at(i);
    cout << endl;
}
//Bước 2.5:
void set_0(vector<int> &Arr, int j)
{
    for (; j < Arr.size(); j++)
        Arr.at(j) = 0;
}
//Bước 2:
void Sinh(vector<int> &Arr)
{
	//Duyệt ngược từ cuối dãy:
    for (int j = Arr.size() - 1; j >= 0; j--)
    {
    	//Số 0 đầu tiên gặp phải sẽ được thay bằng 1,
    	//các số đứng sau nó được thay bằng 0
        if (Arr.at(j) == 0)
        {
            Arr.at(j) = 1;
            set_0(Arr, j + 1);
            Xuat(Arr);
            break;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> Arr(n, 0);
    Xuat(Arr);
    //Bước 4:Thực hiện lặp lại việc sinh và in ra:
    for (int i = 1; i < pow(2, n); i++)
    {
        Sinh(Arr);
    }
    return 0;
}
