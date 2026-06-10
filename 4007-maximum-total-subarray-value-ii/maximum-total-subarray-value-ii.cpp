class SegmentTree{
public:
    vector<int>mx,mn;
    SegmentTree(int n){
        mx.resize(4*n);
        mn.resize(4*n);
    }
    void Build(int idx,int s,int e,vector<int>& A){
        if(s==e){
            mx[idx]=A[s];
            mn[idx]=A[s];
            return;
        }
        int mid=(s+e)>>1;
        Build(idx*2+1,s,mid,A);
        Build(idx*2+2,mid+1,e,A);
        mx[idx]=max(mx[idx*2+1],mx[idx*2+2]);
        mn[idx]=min(mn[idx*2+1],mn[idx*2+2]);
    }
    int QueryMax(int idx,int s,int e,int ql,int qr){
        if(qr<s||e<ql)return INT_MIN;
        if(ql<=s&&e<=qr)return mx[idx];
        int mid=(s+e)>>1;
        return max(
            QueryMax(idx*2+1,s,mid,ql,qr),
            QueryMax(idx*2+2,mid+1,e,ql,qr)
        );
    }
    int QueryMin(int idx,int s,int e,int ql,int qr){
        if(qr<s||e<ql)return INT_MAX;
        if(ql<=s&&e<=qr)return mn[idx];
        int mid=(s+e)>>1;
        return min(
            QueryMin(idx*2+1,s,mid,ql,qr),
            QueryMin(idx*2+2,mid+1,e,ql,qr)
        );
    }
};
class Solution{
public:
    long long maxTotalValue(vector<int>& nums,int k){
        int n=nums.size();
        SegmentTree seg(n);
        seg.Build(0,0,n-1,nums);
        priority_queue<vector<int>> pq;
        for(int i=0;i<n;i++){
            int mx=seg.QueryMax(0,0,n-1,i,n-1);
            int mn=seg.QueryMin(0,0,n-1,i,n-1);
            pq.push({mx-mn,i,n-1});
        }
        long long ans=0;
        while(k--){
            auto temp=pq.top();
            pq.pop();
            ans+=temp[0];
            int l=temp[1];
            int r=temp[2];
            if(l<r){
                int mx=seg.QueryMax(0,0,n-1,l,r-1);
                int mn=seg.QueryMin(0,0,n-1,l,r-1);
                pq.push({mx-mn,l,r-1});
            }
        }
        return ans;
    }
};