#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    double f[n];
    for(int i=0;i<n;i++)
    {
        cin >> f[i];
    }
    sort(f,f+n);
    int l,r,m;
    long long rez=0;
    for(int i=1;i<n;i++)
    {
        l=0;
        r=i;
        while(l<r)
        {
            m=(l+r)/2;
            if(f[m]>=0.9*f[i])
            {
                r=m;
            }
            else
            {
                l=m+1;
            }
        }
        rez+=i-r;
    }
    cout << rez;
    return 0;
}
