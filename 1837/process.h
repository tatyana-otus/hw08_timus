#include <iostream>
#include <map>
#include <set>
#include <string>


void process(std::istream& is = std::cin, std::ostream& os = std::cout)
{
    std::map<std::string, std::set<std::string>> all;
    std::map<std::string, int> one;

    int n;
    std::string s1, s2, s3;
    is >> n;
    
    for(auto i = 0; i < n; ++i){
        
        is >> s1;
        is >> s2;
        is >> s3;

        all[s1].insert(s2);
        all[s1].insert(s3);
        
        all[s2].insert(s1);
        all[s2].insert(s3);
        
        all[s3].insert(s2);
        all[s3].insert(s1); 
        
        one[s1] = -1;
        one[s2] = -1;
        one[s3] = -1;
    }

    std::set<std::string> tmp1, tmp2;
    if(all.find("Isenbaev") != all.end()){
        tmp1.insert("Isenbaev");
        one["Isenbaev"] = 0;
    }    
    int cnt = 1;
    while (tmp1.size() > 0) {
        for(const auto& i : tmp1) {
            for(const auto& j : all[i] ){
                if(one[j] == -1){
                    one[j] = cnt;
                    tmp2.insert(j);
                }           
            }
            all.erase(i);
        }
        std::swap(tmp1, tmp2);
        tmp2.clear();
        ++cnt;
    }
    
    for(const auto& i : one){
        if(i.second != -1) {
            os << i.first << " " <<  i.second << "\n";
        }
        else{
            os << i.first << " " << "undefined" << "\n";
        }   
    }
}