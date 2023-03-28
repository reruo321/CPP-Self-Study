#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(!cacheSize)
        return 5 * cities.size();
    
    vector<string> cache;
    for(auto &city: cities){
        for(auto &c: city){
            if(c>='A'&&c<='Z'){
                c = 'a' + (c-'A');
            }
        }
    }
    
    for(auto &city: cities){
        int i = -1;
        bool iscache = false;
        for(auto &ca: cache){
            ++i;
            if(city == ca){
                iscache = true;
                break;
            }
        }
        if(iscache){
            ++answer;
            cache.erase(cache.begin()+i);
            cache.push_back(city);
        }
        else{
            answer += 5;
            if(cache.size()>=cacheSize){
                cache.erase(cache.begin());
            }
            cache.push_back(city);
        }
    }
    
    return answer;
}
