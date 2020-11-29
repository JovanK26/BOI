#include <bits/stdc++.h>

using namespace std;
int n,m,r,c;
int mat[20][20];
int sum[20];
bool check2(int x,int med)
{
    vector<int> temp;
    temp.push_back(0);
    for(int i=0;i<n;i++)
    {
        if(x&(1<<i))
        {
            temp.push_back(i);
        }
    }
    temp.push_back(n);
    for(int i=0;i<n;i++)
    {
        sum[i]=0;
    }
    int br=0;
    for(int j=0;j<m;j++)
    {
        int ind=0;
        int maks=0;
        for(int i=0;i<n;i++)
        {
            if(i>=temp[ind+1])ind++;
            sum[ind]+=mat[i][j];
            maks=max(maks,sum[ind]);
        }
        if(maks>med)
        {
            br++;
            ind=0;
            for(int i=0;i<n;i++)
            {
               sum[i]=0;
            }
            for(int i=0;i<n;i++)
            {
              if(i>=temp[ind+1])ind++;
              sum[ind]+=mat[i][j];
              if(sum[ind]>med)return 0;
            }
        }
    }
    return (br<=c);
}
bool check1(int med)
{
    for(int i=0;i<(1<<n);i++)
    {
        if(i&1)continue;
        if(__builtin_popcount(i)!=r)continue;
        if(check2(i,med))return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n  >> m >> r >> c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat[i][j];
        }
    }
    int l=0;
    int r=1000000000;
    int med;
    while(l<=r)
    {
        med=(l+r)/2;
        if(check1(med))
        {
            r=med-1;
        }
        else
        {
            l=med+1;
        }
    }
    cout << r+1;
    return 0;
}
