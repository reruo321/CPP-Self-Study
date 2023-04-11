#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

typedef pair<int, int> P;

vector<int> solution(vector<vector<int>> arr) {
    if(arr.size()==1){
        if(arr.at(0).at(0))
            return {0,1};
        else
            return {1,0};
    }
    int n = arr.size();
    int i, j, k=1;
    vector<int> answer(2, 0);
    set<pair<int, int>> se;
    bool ischanged = false;
    
    for(i=0; i<n; i+=2*k){
        for(j=0; j<n; j+=2*k){
            int sum = arr.at(i).at(j) + arr.at(i+k).at(j) + arr.at(i).at(j+k) + arr.at(i+k).at(j+k);
            if(!sum){
                ++answer.at(0);
                se.insert(make_pair(i, j));
            }
            else if(sum==4){
                ++answer.at(1);
                se.insert(make_pair(i, j));
            }
            else{
                answer.at(0) += 4-sum;
                answer.at(1) += sum;
            }
        }
    }
    k<<=1;
        
    do{
        for(i=0; i<n; i+=2*k){
            for(j=0; j<n; j+=2*k){
                ischanged = true;
                if(se.count(P(i,j)))
                    se.erase(P(i,j));
                else
                    ischanged = false;
                if(se.count(P(i+k,j)))
                    se.erase(P(i+k,j));
                else
                    ischanged = false;
                if(se.count(P(i,j+k)))
                    se.erase(P(i,j+k));
                else
                    ischanged = false;
                if(se.count(P(i+k,j+k)))
                    se.erase(P(i+k,j+k));
                else
                    ischanged = false;
                
                if(ischanged){
                    int sum =
                        arr.at(i).at(j)
                        + arr.at(i+k).at(j)
                        + arr.at(i).at(j+k)
                        + arr.at(i+k).at(j+k);
                    
                    if(!sum){
                        answer.at(0) -= 3;
                        se.insert(make_pair(i, j));
                    }
                    else if(sum==4){
                        answer.at(1) -= 3;
                        se.insert(make_pair(i, j));
                    }
                }
                    
            }
        }
        
        k<<=1;
    } while(!se.empty());
    
    
    return answer;
}
