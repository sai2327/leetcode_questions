class Solution{
public:
	long long maxSumTrionic(vector<int>&a){
		int n=a.size();
		int i=1,c=0,s=-1;
		long long sum=0,ans=LLONG_MIN;
		while(i<n){
			if(a[i]==a[i-1]){
				s=-1;
			}
			else if(s==-1){
				if(a[i]>a[i-1]){
					sum=a[i]+a[i-1];
					s=0;
				}
			}
			else if(s==0){
				if(a[i]>a[i-1]){
					sum=max(sum+a[i],1LL*a[i]+a[i-1]);
				}
				else{
					s=1;
					sum+=a[i];
				}
			}
			else if(s==1){
				if(a[i]<a[i-1]){
					sum+=a[i];
				}
				else{
					s=2;
					sum+=a[i];
					ans=max(ans,sum);
					c=i;
				}
			}
			else{
				if(a[i]>a[i-1]){
					sum+=a[i];
					ans=max(ans,sum);
				}
				else{
					i=c;
					s=-1;
					continue;
				}
			}
			i++;
		}
		return ans;
	}
};
