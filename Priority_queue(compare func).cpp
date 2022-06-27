class dijikstra{
  
  public  :
  int distance;
 
  int child;
  
  dijikstra(int dis,int v){
    distance=dis;
    
    child=v;
  }
};

struct compare {
  bool operator()(dijikstra* &a ,dijikstra* &b)
    return a->distance>b->distance;
  
};

void solve(vector<vector<int>>node)
{
  priority_queue<dijikstr*,vector<dijikstr*>,greater<dijikstra*>>pq;
  
  dijikstra* node=new dijistra(0,0);
  
  pq.push(node);
  
  while(!pq.empty()){
    int cur_dis=pq.top().distance;
    int cur_node=pq.top().child;
    
    if(vis[node]==true)continue;
    vis[node]=true;
    
    for(int index=0;index<node[cur_node].size();index++){
      dijikstra* cur_node=new dijikstr(cur_dis+(node[cur_node][index]),node);
      pq.push(cur_node);
      
    }
    
  }
  
  
  
}
