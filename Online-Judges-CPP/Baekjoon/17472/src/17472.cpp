#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge{
    int source;
    int dest;
    int weight;
    
    Edge(int s, int d, int w): source(s), dest(d), weight(w){}
    bool operator<(const Edge &comp) const {
        return weight < comp.weight;
    }
};

vector<vector<int>> graph;
queue<pair<int, int>> que;
vector<Edge> edges;
vector<int> root;
vector<int> uf_rank;

vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};

int find(int v){
    if(root.at(v) != v){
        root.at(v) = find(root.at(v));
    }
    return root.at(v);
}

bool unionfun(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a != b){
        if(uf_rank.at(a) < uf_rank.at(b))
            root.at(a) = b;
        else if(uf_rank.at(a) > uf_rank.at(b))
            root.at(b) = a;
        else{
            root.at(b) = a;
            ++uf_rank.at(a);
        }
        return true;
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    graph.assign(N, vector<int>(M, -1));
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            int input;
            cin >> input;
            
            if(input > 0){
                graph.at(i).at(j) = 0;
            }
        }
    }
    
    int island_no = 0;
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(graph.at(i).at(j) != 0)
                continue;
            
            ++island_no;
            que.push(make_pair(i, j));
            graph.at(i).at(j) = island_no;
            
            while(!que.empty()){
                int row = que.front().first;
                int col = que.front().second;
                
                que.pop();
                
                for(int k=0; k<dr.size(); ++k){
                    int new_row = row + dr.at(k);
                    int new_col = col + dc.at(k);
                    
                    if(new_row >= 0 && new_row < N && new_col >= 0 && new_col < M){
                        if(graph.at(new_row).at(new_col) == 0){
                            que.push(make_pair(new_row, new_col));
                            graph.at(new_row).at(new_col) = island_no;
                        }
                    }
                }
            }
        }
    }
    
    root.assign(island_no + 1, 0);
    for(int i=1; i<root.size(); ++i){
        root.at(i) = i;
    }
    
    uf_rank.assign(island_no + 1, 0);
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            const int &is_no = graph.at(i).at(j);
            if(is_no <= 0)
                continue;
            
            for(int k=0; k<dr.size(); ++k){
                int len = 0;
                int is_another = 0;

                while(1){
                    int row = i + (len + 1) * dr.at(k);
                    int col = j + (len + 1) * dc.at(k);
                    
                    if(row < 0 || row >= N || col < 0 || col >= M){
                        break;
                    }
                    
                    is_another = graph.at(row).at(col);
                    if(is_another > 0){
                        break;
                    }
                    
                    ++len;
                }
                
                if(len >= 2 && is_another > 0 && is_another != is_no){
                    edges.push_back(Edge(is_no, is_another, len));
                }
            }
        }
    }
    
    int count_isgroup = island_no;
    sort(edges.begin(), edges.end());
    
    int sum_bridge = 0;
    
    for(auto &e: edges){
        if(unionfun(e.source, e.dest)){
            sum_bridge += e.weight;
            --count_isgroup;
        }
    }
    
    if(count_isgroup != 1){
        cout << -1 << "\n";
    }
    else{
        cout << sum_bridge << "\n";
    }

    return 0;
}
