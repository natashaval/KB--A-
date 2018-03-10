#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair
#define fi first
#define sc second

int n, heu[100], path[100], vis[100];
vector <int> adjList[100];
deque < pair<pii,int> > q;
int src, dst;

int greedy()
{
	while (!q.empty()){
    	pair<pii,int> temp;
    	temp = q.front();
    	q.pop_front();
    	int curr_state = temp.fi.fi;
    	int curr_heu = temp.fi.sc;
    	int start_counter = temp.sc;
    	int curr_size;
    	for (int i=start_counter;i<adjList[curr_state].size();i++){
    		curr_size = adjList[curr_state].size();
    		int succ_state, succ_heu;
    		succ_state = adjList[curr_state][i];
 //   		printf("==succ_state %d\n",succ_state);
    		if (succ_state == dst) {
    			printf("sampai di %d",succ_state);
    			printf("ketemuwut");
    			return 100;
			}
    		succ_heu = heu[succ_state];
    		
    		if (succ_heu < curr_heu && !vis[succ_state]) {
    			q.push_front(mp(mp(curr_state,curr_heu),start_counter+1));
    			q.push_front(mp(mp(succ_state,succ_heu),0));
    			printf("masuk ke state %d heu %d\n",succ_state,succ_heu);
				vis[succ_state] = 1;
			}
			else
				q.push_back(mp(mp(succ_state,succ_heu),0));
		}
	}
}

int main() {

	for (int i=0;i<100;i++) vis[i] = 0;

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
    
    printf("Masukkan titik mula - mula :\n");
    scanf("%d",&src);					//node tersebut adalah parent dari dirinya sendiri
    printf("Masukkan titik akhir :\n");
    scanf("%d",&dst);
    
    int distnow = heu[src];
    q.push_back(mp(mp(src,heu[src]),0));
   /* 
    pair<pii,int> temp;
    	temp = q.front();
    	q.pop_front();
    	int curr_state = temp.fi.fi;
    	int curr_heu = temp.fi.sc;
    	int start_counter = temp.sc;
    	
    	printf("%d %d %d",curr_state, curr_heu, start_counter);
    	*/
   
    printf("nilai %d",greedy());
    
        return 0;
}
