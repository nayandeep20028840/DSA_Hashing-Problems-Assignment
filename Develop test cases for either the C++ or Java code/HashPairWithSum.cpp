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

void testHasPairWithSum()
{
    std::vector<int> arr1 = {1, 4, 45, 6, 10, 8};
    int target1 = 16;
    assert(hasPairWithSum(arr1, target1) == true); // it ensure the correctness of the program

    std::vector<int> arr2 = {1, 2, 4, 3, 6};
    int target2 = 11;
    assert(hasPairWithSum(arr2, target2) == false);

    std::vector<int> arr3 = {1, 4, 5, 7, 10};
    int target3 = 15;
    assert(hasPairWithSum(arr3, target3) == true);

    std::vector<int> arr4 = {};
    int target4 = 10;
    assert(hasPairWithSum(arr4, target4) == false);
}
int main()
{
    testHasPairWithSum();
    std::cout << "All hasPairWithSum tests passed!" << std::endl;
    return 0;
}
