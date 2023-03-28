#include <string>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> cli;
    unordered_map<string, list<string>::iterator> mmap;
    if(!cacheSize)
        return cities.size() * 5;
    
    for(auto &city: cities){
        for(auto &c: city){
            if(c>='A'&&c<='Z')
                c = 'a' + (c-'A');
        }
        
        if(mmap.find(city)==mmap.end()){
            if(cli.size()==cacheSize){
                string s = cli.back();
                cli.pop_back();
                mmap.erase(s);
            }
            cli.push_front(city);
            mmap.insert(make_pair(city, cli.begin()));
            answer += 5;
        }
        else{
            cli.erase(mmap.at(city));
            cli.push_front(city);
            mmap.at(city) = cli.begin();
            ++answer;
        }
    }
    
    return answer;
}
