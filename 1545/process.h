#include <iostream>
#include <array>
#include <map>
#include <set>

void process(std::istream& is = std::cin, std::ostream& os = std::cout)
{
    std::array<std::array<char, 26 >, 26> d = { 0 };
    std::array<char, 26> idx = { 0 };

    int n;
    char k, v, j;
    is >> n;
    for(auto i = 0; i < n; ++i) {
        is >> k >> v; 
        j = k - 'a';
        d[j][idx[j]++] = v;  
    }
    
    is >> k;
    j = k - 'a';
    for(auto i = 0; i < idx[j]; ++i) {
        os << k << d[j][i] << "\n";
    }
}

void process_alt(std::istream& is = std::cin, std::ostream& os = std::cout)
{
    
    std::map<char, std::set<char>> table;
    int n;

    is >> n;
    char first, second;
    for (auto i = 0; i < n; ++i)
    {
        is >> first >> second;
        table[first].insert(second);
    }

    is >> first;
    for (const auto& res : table[first])
    {
        os << first << res << '\n';
    }
}