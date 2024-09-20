// IO
#include <iostream>
#include <fstream>

// C Lib
#include <cstdio>
#include <cstdlib>
#include <cstring>

// STL
#include <tuple>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

// Leetcode IO
#include "readio.hpp"

using namespace std;

/*-------------------------------------------*/

class Solution {
public:
#define FunctionName countSpecialNumbers

    static int countSpecialNumbers(int n) {
        vector<int> n_number;

        while (n > 0) {
            n_number.push_back(n % 10);
            cout << n % 10 << endl;
            n /= 10;
        }

        int f[11][11];
        memset(f, 0, sizeof(int));

        for (int j = 0; j < 11; j++) {
            f[0][j] = 1;
        }

        for (int i = 1; i <= 10; i++) {
            for (int j = i; j <= 10; j++) {
                if (i == 1) {
                    f[i][j] = j;
                } else {
                    f[i][j] = f[i - 1][j - 1] * j;
                }
            }
        }

        int ans = 0;
        for (int i = n_number.size() - 1; i >= 0; i--) {
            ans += n_number[i] * f[i][10 - n_number.size() + i];
            cout << i << ' ' << ans << endl;
        }
        return ans + 1;
    }
};

/*--------------------------------------------*/

int main() {
#define STDIN_FILE_NAME "stdin.in"
    typedef function_traits<std::function<decltype(Solution::FunctionName)>> function_input_type;

    // Read Data
    auto data = readFile(getDirByPath(__FILE__, STDIN_FILE_NAME));

    int max_loop = data.size() / function_input_type::nargs;
    for (int loop = 0; loop < max_loop; loop++) {
        function_input_type::input_tuple_type mark;
        if constexpr (std::is_same_v<void, function_input_type::result_type>) {
            callFunction(Solution::FunctionName, callReadIO(data, mark));
        } else {
            auto output = callFunction(Solution::FunctionName, callReadIO(data, mark));
        }
    }

    return 0;
}
