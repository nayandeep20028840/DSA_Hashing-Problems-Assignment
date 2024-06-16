#include <bits/stdc++.h>
using namespace std;

bool hasPairWithSum(const vector<int> &arr, int target)
{
    unordered_map<int, int> seen;
    for (int num : arr)
    {
        if (seen.find(target - num) != seen.end())
        {
            return true;
        }
        seen[num] = num; // Store the number as both key and value
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 16;

    if (hasPairWithSum(arr, target))
    {
        cout << "Array has two elements with sum " << target << endl;
    }
    else
    {
        cout << "Array doesn't have two elements with sum " << target << endl;
    }

    return 0;
}
