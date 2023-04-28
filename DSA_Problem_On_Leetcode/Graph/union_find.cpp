//union and find code/implementation:- Disjoint set
vector<int> parent;
vector<int> rank;

int find(int i, vector<int> &parent) {
    if(i == parent[i]) {
        return i;
    }

    return parent[i] = find(parent[i], parent);
}

void union(int x, int y, vector<int> &parent, vector<int> &rank) {
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

    if(x_parent == y_parent) return;

    if(rank[x_parent] > rank[y_parent]) {
        //x_parent ko leader bana do
        parent[y_parent] = x_parent;
    } else if(rank[x_parent] < rank[y_parent]) {
        //y_parent ko leader bana do
        parent[x_parent] = y_parent;
    } else {
        //kisi ko bhi leader bana do and rank incremented by one
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}