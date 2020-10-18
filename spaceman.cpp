#include<bits/stdc++.h>
using namespace std;


double time_to_live(vector<double> &inp)
{
    double nums[inp.size() + 2];
    int n = 1;

    for (double x : inp)
    {if (x > 0)
     nums[n++] = x;
    }
    nums[0] = nums[n++] = 0;


    double dp[n][n] = {};
    for (int k = 2; k < n; ++k)
       {
        for (int left = 0; left < n - k; ++left)
        {   int right = left + k;
            for (int i = left + 1; i < right; ++i)
            dp[left][right] = max(dp[left][right], nums[left]/2.0 + nums[i] + nums[right]/2 + dp[left][i] + dp[i][right]);
        }
       }

    return dp[0][n - 1];
}

int main()
{
  //freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  int number_spaceships; cin>>number_spaceships;
  vector<double> inp;
  for(int i=1; i<=number_spaceships; i++)
  { double d; cin>>d;
    inp.push_back(d);
  }

  cout<<time_to_live(inp);

  return 0;
}