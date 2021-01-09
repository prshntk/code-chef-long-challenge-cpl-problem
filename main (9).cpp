/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool isS(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    bool subset[n + 1][sum + 1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
 
    // Fill the subset table in botton up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }
 
    return subset[n][sum];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int h[n];
        int sum=0;
        for(int i=0;i<n;i++)
        {
        cin>>h[i];
        sum+=h[i];
        }
        sort(h,h+n,greater<int>());
        if(sum<2*k)
        cout<<"-1"<<"\n";
        else if(sum==2*k)
        {
            if(isS(h,n,k)==1)
            cout<<n<<"\n";
            else cout<<"-1"<<"\n";
        }
        else 
        {
            int su=0;
            int i;
            for( i=0;i<n;i++)
            {
            su+=h[i];
            if(su>=2*k)
            break;
            }
            if(su==2*k)
            {
                if(isS(h,i,k)==1)
                cout<<i+1<<"\n";
                else
                {
                su+=h[i+1];
                i++;
                }
            }
            if(su>2*k)
            {
                int f=0;
                if((isS(h,i,k)==1)||(isS(h,i,(su/2))==1))
                {
                    f=1;
                cout<<i+1<<"\n";
                continue;
                
                }
                int m=h[0];
                int ni=0;
                for(int u=i;u>0;u--)
                {
                    if(m<k)
                    m+=h[u];
                    else 
                    ni+=h[u];
                }
                if(ni>=k)
                    {
                      f=1;
                      cout<<i+1<<"\n";
                      continue;
                    }
                i++;
                for(;i<n;i++)
                {
                    su+=h[i];
                    ni+=h[i];
                    if((isS(h,i,k)==1)||(isS(h,i,(su/2))==1))
                    {
                        f=1;
                        cout<<i+1<<"\n"; 
                        break;
                    }
                    if(ni>=k)
                    {
                      f=1;
                      cout<<i+1<<"\n"; 
                      break;  
                    }
                }
                if(!f)
                cout<<-1<<"\n";
            }
        }
        
    }

    return 0;
}
