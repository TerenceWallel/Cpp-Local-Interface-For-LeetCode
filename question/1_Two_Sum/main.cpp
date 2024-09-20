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
#ifdef LOCAL_ENV_LEETCODE
#include "readio.hpp"
#endif

using namespace std;

/*-------------------------------------------*/
struct ArgInt {
    int arg;
    int key;

    ArgInt(int _key, int _arg) {
        key = _key;
        arg = _arg;
    }

    bool operator<(ArgInt _a) const {
        return key < _a.key;
    }
};

class Solution {
public:
#define FunctionName twoSum

    static vector<int> twoSum(vector<int> &nums, int target) {
        vector<ArgInt> arg_nums;
        for (int i = 0; i < nums.size(); i++) {
            arg_nums.emplace_back(nums[i], i);
        }

        sort(arg_nums.begin(), arg_nums.end());

        int now = arg_nums.size() - 1;

        for (int i = 0; i < now;) {
            if (arg_nums[i].key + arg_nums[now].key == target) {
                return vector<int>{arg_nums[i].arg, arg_nums[now].arg};
            } else if (arg_nums[i].key + arg_nums[now].key > target) {
                now--;
            } else {
                i++;
            }
        }

        return vector<int>{0, 0};
    }
};

/*--------------------------------------------*/

int main() {
#define STDIN_FILE_NAME "stdin.in"
    typedef function_traits<std::function<decltype(Solution::FunctionName)>> function_input_type;

    // Read Data
    auto data = readFile(getDirByPath(__FILE__, STDIN_FILE_NAME));
    int max_loop = data.size() / function_input_type::nargs;
    for (int loop = 0; loop < max_loop; loop++)
    {
        function_input_type::input_tuple_type mark;
        if constexpr (std::is_same_v<void, function_input_type::result_type>)
        {
            callFunction(Solution::FunctionName, callReadIO(data, mark));
        }
        else
        {
            auto output = callFunction(Solution::FunctionName, callReadIO(data, mark));
        }
    }

    return 0;
}
