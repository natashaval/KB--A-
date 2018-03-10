/*
	TUGAS KECERDASAN BUATAN E
	PROGRAM SEARCHING DENGAN ALGORITMA A*
	05111640000108	Zahrah Ayu Afifah Febriani
	05111640000183	Natasha Valentina Santoso
*/

#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

#define fi first
#define sc second
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;


int n, minCost = 0, dst, total = 0, parent[1000], path[100], idx = 0, heu[100];
vector<pii> adjList[100];		//simpan dari a->(dist,b) dan b->(dist,a)
queue <pii> q;	//simpan (jarak, nextNode)
bool inMST [1000] = {false};	//track nodes yg termasuk dalam MST

int adjMatrix [1000][1000];		//buat adjacency matrix nya
void matrix()
{
	printf("Apakah mau cek Adjacency Matrix nya? 1[YES] / 2[NO]: ");
	int pilih;
	int jum;
	scanf("%d",&pilih);
	if (pilih==1){
		printf("Menampilkan Adjacency Matrix!\n");
		printf("Masukkan jumlah node: ");
		scanf("%d",&jum);
		for (int i=0;i<=jum;i++){
			for (int j=0;j<=jum;j++){
				printf("%d ",adjMatrix[i][j]);
//				if (j==0) printf(" ");
			}
			printf("\n");
//			if (i==0) printf("\n");
		}
	}
	printf("\n");
}

int Astar(int p)
{
    pii temp;
    int minCost = 0, node, nextNode, weightNext;

	while (!q.empty())
	{
		temp = q.front();		//pilih edge dg minimum weight
		q.pop();
		node = temp.second;
		printf("Saat ini hitung hasil node %d\t",node);

		if (inMST[node])
		{
			printf("Node %d sudah pernah disimpan hasilnya\n",node);
			continue;	//sudah pernah disimpan nilai node
		}
        if(node == p) minCost = 0;
        else minCost += temp.fi;
		path[idx++] = node;					//simpan node yang dilalui
		printf("Cost sementara = %d\n",minCost);
		inMST [node] = true;

        sort(adjList[node].begin(), adjList[node].end());
        nextNode = adjList [node][0].sc;
        if (inMST[nextNode]==false)	//jika nextnode belum dilewati
        {
            printf("Node %d masuk pq; weight %d\n",nextNode,adjList [node][0].fi);
            inMST [nextNode] = true;
        }
		printf("\n");

		if(nextNode==dst) return minCost;
		else minCost -= heu[node];
	}
}

int main()
{
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

    printf("Masukkan graph-nya <dari> <ke> <jarak>:\n");
    for(int i=0;i<edge;i++){
        scanf("%d %d %d",&u,&v,&weight);
        q.push(mp(weight,v));			//input format <dari> <ke> <jarak>
        adjList[u].push_back(make_pair (weight + heu[u],v));		//node u terkoneksi pada node v
        adjList[v].push_back(make_pair (weight + heu[v],u));		//node v terkoneksi pada node u (karena undirected graph)

        adjMatrix [u][v] = adjMatrix [v][u] = weight;
        adjMatrix [0][u] = u; adjMatrix [u][0] = u;
        adjMatrix [0][v] = v; adjMatrix [v][0] = v;
	}

	matrix();

    int src;
    printf("Masukkan titik mula - mula :\n");
    scanf("%d",&src);					//node tersebut adalah parent dari dirinya sendiri
    printf("Masukkan titik akhir :\n");
    scanf("%d",&dst);
    printf("\nPanjang rute dengan A * search adalah %d",Astar(src));
    printf("\nRute yang dilalui adalah ");					//print path yang dilewati
    for(int i=0; i<idx; i++) printf(" - %d",path[i]);
    printf("\n");
    return 0;
}

//source https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
