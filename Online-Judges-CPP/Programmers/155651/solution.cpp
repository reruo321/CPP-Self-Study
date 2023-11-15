#include <string>
#include <vector>
#include <algorithm>

#define HM 24*60

using namespace std;

int strToInt(string &str){
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    return h*60+m;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int sum = 0;
    vector<pair<int, int>> bookvec;
    
    for(auto &book: book_time){
        int start = strToInt(book.at(0));
        int end = strToInt(book.at(1)) + 10;
        if(end >= HM)
            end = HM - 1;
        bookvec.push_back({start, 1});
        bookvec.push_back({end, -1});
    }
    
    sort(bookvec.begin(), bookvec.end());
    
    for(auto &b: bookvec){
        sum += b.second;
        if(answer < sum)
            answer = sum;
    }
    return answer;
}
