struct Node {
    int maxVal;
    int count; 
    Node(int mv = INT_MIN, int c = 0) : maxVal(mv), count(c) {}
};

class MaxCountSegTree {
    int n;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        if(a.maxVal==b.maxVal) {
            return Node(a.maxVal, a.count + b.count);
        }
        if(a.count==b.count) {
            if(a.maxVal > b.maxVal) return b;
            return a;
        }
        if (a.maxVal > b.maxVal) return a;
        if (b.maxVal > a.maxVal) return b;
        return Node(a.maxVal, a.count + b.count);
    }

    void build(int idx, int l, int r, const vector<int> &arr) {
        if (l == r) {
            seg[idx] = Node(arr[l], 1);
            return;
        }
        int mid = (l + r) >> 1;
        build(2*idx, l, mid, arr);
        build(2*idx+1, mid+1, r, arr);
        seg[idx] = merge(seg[2*idx], seg[2*idx+1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            seg[idx] = Node(val, 1);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(2*idx, l, mid, pos, val);
        else update(2*idx+1, mid+1, r, pos, val);
        seg[idx] = merge(seg[2*idx], seg[2*idx+1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return Node(INT_MIN, 0);
        if (ql <= l && r <= qr) return seg[idx];
        int mid = (l + r) >> 1;
        Node left = query(2*idx, l, mid, ql, qr);
        Node right = query(2*idx+1, mid+1, r, ql, qr);
        return merge(left, right);
    }

public:
    MaxCountSegTree(const vector<int> &arr) {
        n = arr.size();
        seg.assign(4 * n + 5, Node());
        build(1, 0, n-1, arr);
    }

    pair<int,int> rangeQuery(int l, int r) {
        if (l > r || l < 0 || r >= n) return {INT_MIN, 0};
        Node res = query(1, 0, n-1, l, r);
        return {res.maxVal, res.count};
    }
};

class Solution
{
public:
    vector<int> subarrayMajority(vector<int> &nums, vector<vector<int>> &queries)
    {
        MaxCountSegTree st(nums);
        vector<int> result;

        for(int i=0;i<queries.size();i++) {
            auto [mx, cnt] = st.rangeQuery(queries[i][0], queries[i][1]);
            if (cnt >= queries[i][2]) {
                result.push_back(mx);
            }
            else {
                result.push_back(-1);   
            }
        }
        return result;
    }
};

    