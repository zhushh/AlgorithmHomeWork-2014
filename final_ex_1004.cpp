#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int medianOfSmall, medianOfBig;
    int testCast, N, K;
    int arr[100005];
    int cs = 0;
    int tmd;
    cin >> testCast;
    while (testCast-- > 0)
    {
        cin >> N >> K;
        tmd = 0;
        while (tmd < N)
        {
            cin >> arr[tmd];
            tmd++;
        }
        sort(arr, arr + N);
        if (K % 2 == 0)
        {
            medianOfSmall = arr[K / 2] + arr[K / 2 - 1];
            medianOfBig = arr[N - K / 2 - 1] + arr[N - K / 2];
            medianOfSmall /= 2;
            medianOfBig /= 2;
        }
        else
        {
            medianOfSmall = arr[K / 2];
            medianOfBig = arr[N - K / 2 - 1];
        }
        cout << medianOfBig - medianOfSmall << endl;
    }

    return 0;
}

