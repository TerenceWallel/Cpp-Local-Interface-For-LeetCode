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

class Solution {
public:

#define FunctionName lengthOfLongestSubstring

    static int lengthOfLongestSubstring(string s) {
        int ch_list[26];

        return 0;
    }
};

/*--------------------------------------------*/

int main() {
#define STDIN_FILE_NAME "stdin.in"
    typedef function_traits<std::function<decltype(Solution::FunctionName)>> function_input_type;

    // Read Data
    auto data = readFile(getDirByPath(__FILE__, STDIN_FILE_NAME));

    for (int loop = 0; loop < data.size() / function_input_type::nargs; loop++)
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
