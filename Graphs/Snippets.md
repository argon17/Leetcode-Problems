```
// Works like charm for exploring all four directions RDLU order
int dirs[] = {0, 1, 0, -1, 0};

// Validate coordinates
bool inside(int i, int j, int n, int m){
    return i>=0 && i<n && j>=0 && j<m;
}

// Easy coordinates storage in queue
queue<int> q;
q.push(i*m + j);
// For getting indices
int cur = q.front(); q.pop();
int i = cur / m, j = cur % m;

```

-   _BFS Traversal_ : Whenever pushing the node to the queue, mark it visited there only.
-   _DFS Traversal_ : Mark the node visited in first line of dfs function.
