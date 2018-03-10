#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define sc second

int n, heu[100], path[100];
vector <int> adjList[100];
priority_queue <pii, vector<pii>, greater<pii> > q;

int main() {

	int u, v, edge, weight,vertex, hval;
    printf("Masukkan banyaknya node : ");
    scanf("%d",&n);

    printf("Masukkan banyaknya edge : ");
    scanf("%d",&edge);

    printf("Masukkan node dan nilai heuristicnya : \n");
    for(int i=0; i<n; i++){
        scanf("%d%d",&vertex,&hval);
        heu[vertex] = hval;
    }
    
    printf("Masukkan graph-nya <dari> <ke>:\n");
    for(int i=0;i<edge;i++){
        scanf("%d %d",&u,&v);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    int src,dst;
    printf("Masukkan titik mula - mula :\n");
    scanf("%d",&src);					//node tersebut adalah parent dari dirinya sendiri
    printf("Masukkan titik akhir :\n");
    scanf("%d",&dst);
    
    int distnow = heu[src];
    q.push(make_pair(distnow,src)); //dist now sama start
    while (!q.empty()){
    	pii temp = q.top();
    	q.pop();
    	if (temp.second == dst) break;
    	for (int i=0;i<adjList[temp.sc].size();i++){
    		int heunext = heu[adjList[temp.sc][i]]; //nilai heuristic nextnode
    		int nextnode = adjList[temp.sc][i]; //anaknya berapa aja
    		if (heunext < temp.fi) //jika lebih kecil dari curr simpan
			{
				q.push(make_pair(heunext,nextnode));
				printf("Memasukkan heunext %d pada node %d\n",heunext,nextnode);
			}
		}
	}
    
        return 0;
}
