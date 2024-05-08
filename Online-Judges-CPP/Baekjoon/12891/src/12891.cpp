#include <iostream>
#include <vector>

using namespace std;

bool isSatisfied(vector<int> &vec){
    for(auto &v: vec){
        if(v < 0){
            return false;
        }
    }
    return true;
}

int main()
{
    int S, P;
    string dna_string;
    int answer = 0;
    
    vector<char> valpha = {'A', 'C', 'G', 'T'};
    vector<int> vcurrent(valpha.size(), 0);
    
    cin >> S >> P;
    cin >> dna_string;

    for(int i=0; i<vcurrent.size(); ++i){
        int input;
        cin >> input;
        vcurrent.at(i) = -input;
    }
        
    for(int i=0; i<P; ++i){
        for(int j=0; j<valpha.size(); ++j){
            if(dna_string.at(i) == valpha.at(j)){
                ++vcurrent.at(j);
            }
        }
    }
    
    if(isSatisfied(vcurrent))
        ++answer;
    
    for(int i=0; i<S-P; ++i){
        for(int j=0; j<valpha.size(); ++j){
            if(dna_string.at(i) == valpha.at(j)){
                --vcurrent.at(j);
            }
            if(dna_string.at(P+i) == valpha.at(j)){
                ++vcurrent.at(j);
            }
        }
        if(isSatisfied(vcurrent))
            ++answer;
    }
    
    cout << answer << endl;
    

    return 0;
}
