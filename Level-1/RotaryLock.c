long long getMinCodeEntryTime(int N, int M, int *C)
{
  // Write your code here
  long long ans = 0;
  int cur = 1;
  for (int i = 0; i < M; i++)
  {
    int forward = (C[i] > cur) ? C[i] - cur : cur - C[i];
    int backward = N - forward;
    ans += (forward < backward) ? forward : backward;
    cur = C[i];
  }
  return ans;
}
