#include <iostream>
#include <stack>
#include <string>
#include <regex>
#include <list>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        for (auto pos = std::next(path.begin(), 1); pos != path.end();) {
            if (*pos == '/' && *std::prev(pos) == '/') {
                path.erase(pos);
            } else {
                ++pos;
            }
        }
        if (*std::prev(path.end()) == '/') {
            path.erase(std::prev(path.end()));
        }
        std::stack<std::string> sta;
        std::regex rgx("/");
        std::sregex_token_iterator iter(path.begin(), path.end(), rgx, -1);
        std::sregex_token_iterator end;
        for ( ; iter != end; ++iter) {
            if (*iter == "." || *iter == "") {
                continue;
            } else if (*iter == "..") {
                if (!sta.empty()) {
                    sta.pop();
                }
            } else {
                sta.push(*iter);
            }
        }
        std::list<std::string>  lst;
        while(!sta.empty()) {
            lst.push_front(sta.top());
            sta.pop();
        }
        std::stringstream ss;
        ss<<"/";
        for (auto pos = lst.begin(); pos != lst.end(); ++pos) {
            ss<<*pos;
            if (std::next(pos, 1) != lst.end()) {
                ss<<"/";
            }
        }
        return ss.str();
    }
};


int main() {
    Solution s;
    for (auto & str : {
        "/home/",
        "/../",
        "/home//foo/",
        "/a/./b/../../c/",
        "/a/../../b/../c//.//",
        "/a//b////c/d//././/.."
    }) {
        std::cout<<s.simplifyPath(str)<<std::endl;
    }
}