#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>


void process(std::istream& is = std::cin, std::ostream& os = std::cout)
{
    std::map<std::string, std::set<std::string>> all_participant;
    std::map<std::string, int> one_participant;

    int n;
    std::string participant_1, participant_2, participant_3;
    is >> n;
    
    for(auto i = 0; i < n; ++i){
        
        is >> participant_1;
        is >> participant_2;
        is >> participant_3;

        all_participant[participant_1].insert(participant_2);
        all_participant[participant_1].insert(participant_3);
        
        all_participant[participant_2].insert(participant_1);
        all_participant[participant_2].insert(participant_3);
        
        all_participant[participant_3].insert(participant_2);
        all_participant[participant_3].insert(participant_1); 
        
        one_participant[participant_1] = -1;
        one_participant[participant_2] = -1;
        one_participant[participant_3] = -1;
    }

    std::list<std::string> tmp1, tmp2;
    if(all_participant.find("Isenbaev") != all_participant.end()){
        tmp1.push_back("Isenbaev");
        one_participant["Isenbaev"] = 0;
    }    
    int cnt = 1;
    while (tmp1.size() > 0) {
        for(const auto& i : tmp1) {
            for(const auto& j : all_participant[i] ){
                if(one_participant[j] == -1){
                    one_participant[j] = cnt;
                    tmp2.push_back(j);
                }           
            }
            all_participant.erase(i);
        }
        std::swap(tmp1, tmp2);
        tmp2.clear();
        ++cnt;
    }
    
    for(const auto& i : one_participant){
        if(i.second != -1) {
            os << i.first << " " <<  i.second << "\n";
        }
        else{
            os << i.first << " " << "undefined" << "\n";
        }   
    }
}