#include <iostream>
#include <cstdint>
#include <cstring>
#include <algorithm>
using namespace std;

class GraphEdge{
	public:
		uint16_t v[2];
		int16_t w;
};

inline bool sortByW(GraphEdge i,GraphEdge j){return i.w <= j.w;}

bool findUnion(uint16_t x,uint16_t y,uint16_t* parent){
	uint16_t i = x;
	uint16_t j = y;
	while(parent[i] != i) i = parent[i];
	while(parent[j] != j) j = parent[j];
	if(i != j) parent[j] = i;
	return i == j;
}

int main(){
	uint16_t n;
	uint32_t m;
	int32_t numMST[20];
	memset(numMST,0,80);
	uint16_t i = 0;
	while(true){
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		GraphEdge* graphEdge = new GraphEdge[m];
		for(uint32_t j=0 ; j<m ; j++){
			cin >> graphEdge[j].v[0] >> graphEdge[j].v[1] >> graphEdge[j].w;
		}
		uint16_t numEdge = 0;
		uint16_t* graphParent = new uint16_t[n];
		for(uint16_t j=0 ; j<n ; j++) graphParent[j] = j;
		sort(graphEdge,graphEdge+m,sortByW);
		for(uint32_t j=0 ; j<m ; j++){
			if(!findUnion(graphEdge[j].v[0],graphEdge[j].v[1],graphParent)){
				numMST[i] += graphEdge[j].w;
				numEdge++;
				if(numEdge == n-1) break;
			}
		}
		i++;
		delete[] graphEdge;
		delete[] graphParent;
	}
	for(uint16_t j=0 ; j<i ; j++){
		cout << numMST[j] << endl;
	}
	return 0;
}
