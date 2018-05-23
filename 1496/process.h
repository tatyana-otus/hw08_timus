#include <iostream>
#include <set>
#include <string>

void process(std::istream& is = std::cin, std::ostream& os = std::cout)
{
    int n;
    std::string s;

    std::set<std::string> subm;
    std::set<std::string> res;

    is >> n;
    for(auto i = 0; i < n; ++i){
      
        is >> s;

        auto p = subm.insert(s);
        if (!p.second)
            res.insert(s);
    }

    for (const auto & i : res)
        os << i << "\n"; 
}