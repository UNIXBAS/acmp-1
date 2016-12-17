#include <bits/stdc++.h>

using namespace std;

int a[10], N;
long long d[20][20][1];

void array (long long t)
{
 int len = 0;
 while (t / 10ll)
 {
  a[len] = t % 10ll;
  t /= 10ll;
  len++;
 }
 N = len;
 reverse (a, a + len);
}

long long calc (int len, int s, short int sp)
{
 if (len == N) return s == 0;
 if (s < 0)    return 0;
 //Memorization
 if (d[len][s][sp] != -1)
  return d[len][s][sp];
 long long res = 0;
 if (sp)
  for (int i = 0; i < a[len]; i++)
   res += calc (len + 1, s - i, (i == a[len]));
 else
  for (int i = 0; i < 10; i++)
   res += calc (len + 1, s - i, false);
 d[len][s][sp] = res;
 return res;
}

long long func (long long l, long long r, int s)
{
 array (r);
 long long res = calc (0, s, 0);
 array (l - 1);
 res -= (calc (0, s, 0));
 return res;
}

int main ()
{
 memset (d, 255, sizeof d);
 
 return 0;
}
