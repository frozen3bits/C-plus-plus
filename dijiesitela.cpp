 #include<iostream>
 #include<queue>
 using namespace std;
 
 int main(){
	int n,m,c;
	int a,b;
	queue<int>q;
	cin>>n>>m>>c;
	int** matrix = new int*[n];
	for(int i=0;i<n;i++){
		matrix[i] = new int[n];
		for(int j=0;j<n;j++){
			matrix[i][j] = -1;
		}
	}
	for(int i=0;i<n;i++){
		matrix[i][i] = 0;
	}
	for(int i=0;i<m;i++){
		cin>>a>>b;
		matrix[a-1][b-1] = 1;
		matrix[b-1][a-1] = 1;
	}
	int* dist = new int[n];
	for(int i=0;i<n;i++){
		dist[i] = matrix[c-1][i];
		if(dist[i] == 1){
			q.push(i);
		}
	}

	while(q.empty()==false) {
		int x = q.front();
		q.pop();
		for(int i=0;i<n;i++){
			if(x==c-1){
				continue;
			}
			if(dist[i]==-1 && matrix[i][x] == 1 || matrix[i][x] == 1 && dist[i] > dist[x] + 1){
				dist[i] = dist[x] + 1;
				q.push(i);
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<dist[i]<<endl;
	}
}
