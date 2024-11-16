#include <bits/stdc++.h>
using namespace std;
struct sj
{
	double l,r;
};
struct sj f[100001];
bool cmp(struct sj a,struct sj b)
{
	return a.l<b.l;
}
int main()
{
	double x0,y0,k;
	double x,y,r;
	double x1,x2;
	int wz=0;
	cin>>x0>>y0>>k;
	for(int i=0;i<k;i++)
	{
		cin>>x>>y>>r;
		x=x-x0;
		y=y-y0;
		if(abs(y)<r)
		{
			x1=x-sqrt(r*r-y*y);
			x2=x+sqrt(r*r-y*y);
			if(x2<=0)
			{
				continue;
			}
			else if(x1<=0)
			{
				f[wz].l=0;
				f[wz].r=x2;
				wz++;
			}
			else
			{
				f[wz].l=x1;
				f[wz].r=x2;
				wz++;
			}
		}
	}
	sort(f,f+wz,cmp);
	double zb,yb;
	double ans=0;
	zb=f[0].l;
	yb=f[0].r;
	for(int i=1;i<wz;i++)
	{
		if(f[i].l<yb) yb=max(yb,f[i].r);
		else if(f[i].l>=yb)
		{
			ans=ans+yb-zb;
			zb=f[i].l;
			yb=f[i].r;
		}
	}
	ans+=yb-zb;
	printf("%lf",ans);
}