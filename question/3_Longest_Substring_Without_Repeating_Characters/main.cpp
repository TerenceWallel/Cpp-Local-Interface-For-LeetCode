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

    typedef function_traits <std::function<decltype(Solution::FunctionName)>> function_input_type;
    function_input_type::input_tuple_type mark;

    auto answer = callFunction(Solution::FunctionName, callReadIO(readFile(), mark));

    return 0;
}
