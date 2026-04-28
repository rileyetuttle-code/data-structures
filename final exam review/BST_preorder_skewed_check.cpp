#include <iostream>
#include <algorithm>
using namespace std;

bool isSkewedBST(int pre[], int n)
{
    if (n <= 2) {
        return true;
    }

    int min_so_far = min(pre[n-1], pre[n-2]);
    int max_so_far = max(pre[n-1], pre[n-2]);

    for (int i = n - 3; i >= 0; i--)
    {
        if (pre[i] < min_so_far) {
            min_so_far = pre[i];
        }
        else if (pre[i] > max_so_far) {
            max_so_far = pre[i];
        }
        else {
            return false;
        }
    }

    return true;
}

int main()
{
    int pre[] = { 15, 30, 25, 18, 20 };

    bool isSkewed = isSkewedBST(pre, 5);
    if (isSkewed) {
        cout << "BST is skewed";
    }
    else {
        cout << "BST is not skewed";
    }

    return 0;
}