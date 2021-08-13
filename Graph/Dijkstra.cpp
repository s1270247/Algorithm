typedef long long ll;
#define repin(i,start,end) for(ll i=start,i<end;i++)
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using PI=pair<int,int>;
using vPI=vector<PI>;
constexpr int INF=(1<<30)-1;
constexpr ll LLINF=(1LL<<60)-1;

struct edge{int to,cost;};

void Dijkstra(vector<vector<edge>>&g,vi& d,int s){
  priority_queue<PI,vPI,greater<PI>> que;
  d.at(s)=0;
  que.push(PI(0,s));

  while(!que.empty()){
    PI p=que.top(); que.pop();
    int v=p.second;
    
    if(d.at(v)<p.first) continue;
    
    repin(i,0,g.at(v).size()){
      edge e=g.at(v).at(i);
      if(d.at(e.to)>d.at(v)+e.cost){
	d.at(e.to)=d.at(v)+e.cost;
	que.push(PI(d.at(e.to),e.to));
      }
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int v; cin>>v;
  vector<vector<edge>> g(v);
  repin(i,0,v){
    while(1){
      int a,b; cin>>a>>b; if(a==-1||b==-1) break;
      g.at(i).push_back({a-1,b});
      g.at(a-1).push_back({(int)i,b});
      cout<<a<<" "<<b<<endl;
    }
  }
  
  int s; cin>>s;
  vi d(v,INF);
  Dijkstra(g,d,s-1);


  cout<<d.at(v-1)<<endl;
  return 0;
}
