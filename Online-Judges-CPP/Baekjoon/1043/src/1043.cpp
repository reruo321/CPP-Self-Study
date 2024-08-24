#include <iostream>
#include <vector>

#define TRUTH 0

using namespace std;

vector<int> graph;
vector<int> party;

int find(int a){
    if(a != graph.at(a))
        graph.at(a) = find(graph.at(a));
        
    return graph.at(a);
}

void unionSet(int a, int b){
    int root_a = find(a);
    int root_b = find(b);
    
    if(root_a != root_b){
        if(root_a == TRUTH || root_b == TRUTH){
            graph.at(root_a) = TRUTH;
            graph.at(root_b) = TRUTH;
        }
        else{
            graph.at(root_b) = root_a;
        }
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    graph.assign(N+1, 0);
    party.assign(M, 0);

    for(int i=1; i<=N; ++i){
        graph.at(i) = i;
    }

    int T;
    cin >> T;
    
    for(int i=0; i<T; ++i){
        int input;
        cin >> input;
        graph.at(input) = TRUTH;
    }
    
    for(int i=0; i<M; ++i){
        int pnum;
        int pput;
        cin >> pnum;
 
        cin >> pput;
        party.at(i) = pput;
        
        for(int j=1; j<pnum; ++j){
            cin >> pput;
            unionSet(party.at(i), pput);
        }
    }
    
    int answer = 0;
    for(auto &p: party){
        if(find(p) != TRUTH)
            ++answer;
    }
    
    cout << answer << "\n";

    return 0;
}
