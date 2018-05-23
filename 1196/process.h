#include <iostream>
#include <vector>
#include <algorithm>

void process(std::istream& is = std::cin, std::ostream& os = std::cout)
{
    int n;
    int cnt = 0;
    std::vector<uint32_t> data;
    int d;

    is >> n;
    data.reserve(n);
    for(auto i = 0; i < n; ++i){
      
        is >> d;
        data.push_back(d);
    }

    is >> n;
    for(auto i = 0; i < n; ++i){
      
        is >> d;
        if(std::binary_search(data.begin(), data.end(), d)) {
            ++cnt;
        }
    }    
    os << cnt << "\n"; 
}