#include <iostream>
#include <vector>

using namespace std;

vector<int> graph;
vector<int> hier;

int find(int x){

    if(x != graph.at(x))
        graph.at(x) = find(graph.at(x));
    
    return graph.at(x);
}

void unionSets(int a, int b){
    int root_a = find(a);
    int root_b = find(b);
    
    if(root_a != root_b){
        if(hier.at(root_a) < hier.at(root_b))
            graph.at(root_a) = root_b;
        else if(hier.at(root_a) > hier.at(root_b))
            graph.at(root_b) = root_a;
        else{
            graph.at(root_a) = root_b;
            ++hier.at(root_b);
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    graph.assign(N, 0);
    
    for(int i=0; i<N; ++i){
        graph.at(i) = i;
    }
    
    hier.assign(N, 0);
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            int input;
            cin >> input;
            if(input){
                unionSets(i, j);
            }
        }
    }
    
    int root = -1;
    bool isanswer = true;
    
    for(int i=0; i<M; ++i){
        int input;
        cin >> input;
        --input;
        
        if(i == 0){
            root = find(input);
        }
        else{
            if(root != find(input)){
                isanswer = false;
                break;
            }
        }
    }
    
    if(isanswer)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
