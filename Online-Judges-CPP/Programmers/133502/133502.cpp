#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    const string bur = "1231";
    const vector<int> bad = {0, 3, 2, 1};
    string ing;
    for(auto &n : ingredient)
        ing.push_back(n+'0');
    int i = 3;
    
    while(ing.size() > 3 && i < ing.size()){
        bool isbur = true;
        int jump = -2;
        
        if(i < 3)
            isbur = false;
        else
        for(int j=0; j<4; ++j){
            if(ing.at(i-j) != bur.at(3-j)){
                isbur = false;
                jump = bad.at(ing.at(i-j) - '0');
                break;
            }
        }
        
        if(isbur){
            ing.erase(i-3, 4);
            ++answer;
        }
        
        if(i+jump<3)
            i = 3;
        else
            i += jump;
        
    }
    
    return answer;
}
