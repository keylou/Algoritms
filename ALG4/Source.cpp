#include <iostream>
#include <cmath>
using namespace std;

int l1, l2, l3, c1, c2, c3, sum=0;

int f(int* array, int n, int beg, int end)
{
    int tmp3 = array[end] - l3, tmp2 = array[end] - l2, tmp1 = array[end] - l1;
    int k3=0, k2=0, k1=0;
    if (tmp1 <= array[beg]) return c1;
    else if (tmp2 <= array[beg]) return c2;
    else if (tmp3 <= array[beg]) return c3;
    for (int i = 0; i < end; i++)
    {
        if (tmp3 > array[i]) k3++;
        if (tmp2 > array[i]) k2++;
        if (tmp1 > array[i]) k1++;
    }
    if (k1 == end && k2==end)
        sum = f(array, n, beg, k3) + c3;
    else if (k1 == end)
        sum = min(f(array, n, beg, k2) + c2, f(array, n, beg, k3) + c3);
    else if (k2 == end)
        sum = min(f(array, n, beg, k1) + c1, f(array, n, beg, k3) + c3);
    else sum = min(min(f(array, n, beg, k1)+c1, f(array, n, beg, k2)+c2), f(array, n, beg, k3)+c3);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n,beg,end;
    cout << "Введите зависимость расстояний и цен билетов\n";
    cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3;
    cout << "Введите количество станций, отправную и конечную станцию\n";
    cin >> n >> beg >> end;
    int* array = new int[n];
    array[0] = 0;
    cout << "Расстояния между станциями\n";
    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        array[i] = a;
    }
    f(array, n, beg-1, end-1);
    cout << sum;
    return 0;
}