#include<iostream>
#include<vector>

using namespace std;

class UnionFindSet{
public:
	UnionFindSet(int n){
		parents_ = vector<int>(n + 1, 0);
		ranks_ = vector<int>(n + 1, 0);
		
		for(int i = 0; i < parents_.size(); ++i){
			parents_[i] = i;
		}
	}
	
	bool Union(int u, int v){
		int pu = Find(u);
		int pv = Find(v);
		if(pu == pv)
			return false;
			
		if(ranks_[pu] > ranks_[pv]){
			parents_[pv] = pu;
		}
		else if(ranks_[pu] < ranks_[pv]){
			parents_[pu] = pv;
		}
		else{
			parents_[pu] = pv;
			++ranks_[pv];
		}
		
		return true;
	}
	
	int Find(int id){
		if(id != parents_[id])
			parents_[id] = Find(parents_[id]);
		return parents_[id];
	}
	
private:
	vector<int> parents_;
	vector<int> ranks_;	
}; 


int main(){
	vector<vector<int>> edges{{1,2},{2,3},{3,4},{1,4},{1,5}};
	UnionFindSet s(edges.size());
	vector<int> e;
	for(const auto& edge: edges){
		if(!s.Union(edge[0],edge[1]))
		e = edge;
	}
	for(auto i : e){
		cout << i << ' ';
	}
	
	return 0;
}
