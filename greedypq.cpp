#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair
#define fi first
#define sc second

int n, heu[100], path[100];
vector <int> adjList[100];
priority_queue < pair<int, vector<int> >, vector < pair<int, vector<int> > >, greater < pair<int, vector<int> > > > pq;
int src, dst;

void greedy()
{
	while(!pq.empty())
	{
		pair<int, vector<int> > temp_all;
		temp_all = pq.top();
		int heu_val = temp_all.fi;
		vector<int> temp_list = temp_all.sc;
		pq.pop();
		int last_node = temp_list[temp_list.size()-1];
		printf("lastnode %d\n",last_node);
		if (last_node == dst) {
			printf("heuterakhir %d, jalan ",heu_val);
			for (int i=0;i<temp_list.size();i++){
				printf("%d-",temp_list[i]);
			}
			return;
		}
		for (int i=0;i<adjList[last_node].size();i++){
			int heunext = heu[adjList[last_node][i]]; //nilai heuristic nextnode
	    	int nextnode = adjList[last_node][i]; //anaknya berapa aja
	    	if (heunext < heu_val) {
	    		vector<int> temp_succ = temp_list;
	    		temp_succ.push_back(nextnode);
	    		pq.push(mp(heunext,temp_succ));
	    		printf("==heu %d nextnode %d\n",heunext,nextnode);
			}
		}
	}
	
	/*
	while (!q.empty()){
    	pair<pii,int> temp;
    	temp = q.top();
    	q.pop();
    	int curr_state = temp.fi.sc;
    	int curr_heu = temp.fi.fi;
    	int start_counter = temp.sc;
    	int curr_size;
    	for (int i=start_counter;i<adjList[curr_state].size();i++){
    		curr_size = adjList[curr_state].size();
    		int succ_state, succ_heu;
    		succ_state = adjList[curr_state][i];
    		if (succ_state == dst) {
    			printf("sampai di %d",succ_state);
    			printf("ketemuwut");
    			return 100;
			}
    		succ_heu = heu[succ_state];
    		
    		if (succ_heu < curr_heu) {
    			q.push(mp(mp(curr_heu,curr_state),start_counter+1));
    			q.push(mp(mp(succ_heu,succ_state),0));
    			printf("masuk heu %d sucstate %d\n",succ_heu,succ_state);
			
			}
			else
				q.push(mp(mp(succ_heu,succ_state),0));
		}
	}
	*/
}

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
    
    printf("Masukkan titik mula - mula :\n");
    scanf("%d",&src);					//node tersebut adalah parent dari dirinya sendiri
    printf("Masukkan titik akhir :\n");
    scanf("%d",&dst);
    
    int distnow = heu[src];
    vector<int> list;
    list.push_back(src);
    pq.push(mp(distnow,list));

/*   
   pair<int, vector<int> > wut;
   wut = pq.top();
   int heu_val = wut.first;
   vector<int> temp_list = wut.sc;
   printf("heuawal %d, jalan ",heu_val);
		for (int i=0;i<temp_list.size();i++){
			printf("%d-",temp_list[i]);
		}
 */ 
//    printf("nilai %d",greedy());
    greedy();
        return 0;
}
