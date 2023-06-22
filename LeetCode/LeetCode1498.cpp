#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
long long modPower(const long long base, long long power) {
    if (!power)
        return 1;

    long long baseMod = modPower(base, power >> 1);
    if (power & 1)
        return (baseMod * baseMod * base) % MOD;
    else
        return (baseMod * baseMod) % MOD;
}

int numSubseq(vector<int> &nums, int target) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int high = nums[i];
        auto lowIt = upper_bound(nums.begin(), nums.end() - (n - 1 - i), target - high);
        int lowNum = lowIt - nums.begin();

        int prefixNum = 1, midNum = 1;

        if (lowNum == i + 1) { // min-max is the same element
            prefixNum = (modPower(2, lowNum - 1)) % MOD;
        } else { // min-max are different elements
            prefixNum = (modPower(2, lowNum) - 1) % MOD;
            if (prefixNum < 0)
                prefixNum += MOD;

            int mid = max(0, i - lowNum);
            midNum = modPower(2, mid);
        }

        ans = (ans + prefixNum * midNum) % MOD;
    }
    return (int)ans;
}

int main() {
    vector<int> nums = {2, 3, 3, 4, 6, 7};
    int target = 12;
    cout << numSubseq(nums, target);
    return 0;
}