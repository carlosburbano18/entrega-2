#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapa;
        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if (mapa.find(comp) != mapa.end()) {
                return {mapa[comp], i};
            }
            mapa[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    int n, target;
    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Ingrese los numeros: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Ingrese el valor objetivo (target): ";
    cin >> target;

    Solution sol;
    vector<int> res = sol.twoSum(nums, target);

    if (!res.empty()) {
        cout << "Indices encontrados: [" << res[0] << ", " << res[1] << "]" << endl;
    } else {
        cout << "No se encontraron dos numeros que sumen " << target << endl;
    }

    return 0;
}
