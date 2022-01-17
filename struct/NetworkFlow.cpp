struct NetworkFlow {
  struct Edge {
    int to;
    int cap;
    int rev;

    Edge(int to, int cap) : to(to), cap(cap), rev(-1) {}
  };
  int src, sink;
  int N;
  vector<int> level;
  vector<int> work;
  vector<vector<Edge>> G;

  NetworkFlow(int N, int src, int sink) {
    this->N = N;
    this->src = src;
    this->sink = sink;
    G.resize(N);
    level.resize(N);
    work.resize(N);
  }

  void addEdge(int from, int to, int cap) {
    G[from].emplace_back(to, cap);
    G[to].emplace_back(from, 0);
    G[from].back().rev = G[to].size() - 1;
    G[to].back().rev = G[from].size() - 1;
  }

  bool bfs() {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    q.push(src);
    level[src] = 0;
    while (!q.empty()) {
      int here = q.front();
      q.pop();
      for (int i = 0; i < G[here].size(); ++i) {
        int there = G[here][i].to;
        if (level[there] == -1 && G[here][i].cap > 0) {
          level[there] = level[here] + 1;
          q.push(there);
        }
      }
    }
    return level[sink] != -1;
  }

  int dfs(int here, int flow = 0x7fffffff) {
    if (here == sink)
      return flow;

    for (int &i = work[here]; i < G[here].size(); ++i) {
      int there = G[here][i].to;

      if (level[there] == level[here] + 1 && G[here][i].cap > 0) {
        int ret = dfs(there, min(flow, G[here][i].cap));
        if (ret > 0) {
          G[here][i].cap -= ret;
          G[there][G[here][i].rev].cap += ret;

          return ret;
        }
      }
    }

    return 0;
  }

  int getMaximumFlow() {
    int ret = 0;
    while (bfs()) {
      while (true) {
        int flow = dfs(src);
        if (flow == 0)
          break;
        ret += flow;
      }
    }
    return ret;
  }
};