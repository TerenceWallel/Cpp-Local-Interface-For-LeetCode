# A C/C++ local interface for leetcode

A local C and C++ compilation and debugging interface for LeetCode, supporting LeetCode-style input and output without the need for any additional code.

## How to use it
The main.cpp is divide in three part: the include part, the solution part and the main part.

You can add the code in include part and the solution part, but do not change the code in main part.

The input data should in the 'stdin.in' in the dir of main.cpp.

```

/*-------------------------------------------*/
//Incude part
//You can add head file all you want

// IO
#include <iostream>

...

/*-------------------------------------------*/
// Solution Part
// You need to change the function name for different question in LeetCode

class Solution {
public:
// Importance Define
#define FunctionName twoSum

// The mark of "static" is necessary for function in Solution
    static vector<int> twoSum(vector<int> &nums, int target) {
        ...
    }
};

/*--------------------------------------------*/
// Main Function Part
// Don't change and just use it.

int main() {
#define STDIN_FILE_NAME "stdin.in"
    typedef function_traits<std::function<decltype(Solution::FunctionName)>> function_input_type;

    // Read Data
    auto data = readFile(getDirByPath(__FILE__, STDIN_FILE_NAME));
    ...

    return 0;
}
```

## Input data
The input data should be in the file of "stdin.in" in the dir of "main.cpp", and the style is similar to the style in leetcode.

For example, the input of 1_two_sum question in leetcode should be like:

```
[2,7,11,15]
9
[3,2,4]
6
[3,3]
6
```

The code will automaticly run three times, and get three output accodring to the input.

## Cite
```
@software{Wan_Cpp_Local_Interface_For_Leetcode_2024,
  author = {J, Wan},
  url = {https://github.com/TerenceWallel/Cpp-Local-Interface-For-LeetCode},
  version = {1.0.0},
  year = {2024}
}
```
