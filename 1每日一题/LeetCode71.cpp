class Solution {
public:
    string simplifyPath(string path) {
        string ans, name;
        if (path.back() != '/') path += '/';
        for (auto c : path) {
            if (c != '/') name += c;
            else {
                if (name == "..") {
                    while (ans.size() && ans.back() != '/') ans.pop_back();
                    if (ans.size()) ans.pop_back();
                } else if (name != "." && name != "") {
                    ans += '/' + name;
                }
                name = "";
            }
        }

        if (ans.empty()) ans = "/";
        return ans;
    }
};
