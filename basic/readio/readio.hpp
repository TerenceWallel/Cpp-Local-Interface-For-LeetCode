#ifndef LEETCODE_READIO_H
#define LEETCODE_READIO_H

#include <fstream>
#include <string>
#include <tuple>
#include <queue>
#include <functional>

#include "json.hpp"
#include "json_fwd.hpp"

template<typename T>
void readIO(std::vector<std::string> data, T &arg) {
    auto json_message = nlohmann::json::parse(data.at(0));
    arg = json_message.get<T>();
}

template<typename T, typename... Types>
void readIO(std::vector<std::string> data, T &first_arg, Types &... args) {
    std::string message = data.at(0);
    data.erase(data.begin());

    auto json_message = nlohmann::json::parse(message);
    first_arg = json_message.get<T>();

    readIO(data, args...);
}

std::vector<std::string> readFile(const std::string &path = STDIN_FILE_PATH) {
    std::fstream file(path, std::ios::in);
    std::vector<std::string> output;

    std::string str;

    while (std::getline(file, str)) {
        output.push_back(str);
    }

    return output;
}

template<size_t... Is, typename... Args>
void callReadIOHelper(std::vector<std::string> data, std::index_sequence<Is...>, std::tuple<Args...> &tp) {
    readIO(data, std::get<Is>(tp)...);
}

template<typename... Args>
auto callReadIO(std::vector<std::string> data, std::tuple<Args...> &tp) {
    callReadIOHelper(data, std::make_index_sequence<sizeof...(Args)>(), tp);
    return tp;
}

template<typename F, size_t... Is, typename... Args>
auto callFunctionHelper(F f, std::index_sequence<Is...>, std::tuple<Args...> &tp) {
    return f(std::get<Is>(tp)...);
}

template<typename F, typename... Args>
auto callFunction(F f, std::tuple<Args...> tp) {
    return callFunctionHelper(f, std::make_index_sequence<sizeof...(Args)>(), tp);
}

template<typename T>
struct function_traits;

// R为返回类型
// ...Args 为输入参数类型，个数不限
template<typename R, typename ...Args>
struct function_traits<std::function<R(Args...)>> {
    static const size_t nargs = sizeof...(Args);
    // 返回类型
    typedef R result_type;

    typedef std::tuple<remove_reference<Args>::type...> input_tuple_type;

    // 输入参数类型,i为从0开始的参数类型索引
    template<size_t i>
    struct arg {
        typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
    };

};

std::string getDirByPath(const std::string &path, const std::string& file_path) {
    return path.substr(0, path.find_last_of('\\')) + '\\' + file_path;
}

#endif //LEETCODE_READIO_H
