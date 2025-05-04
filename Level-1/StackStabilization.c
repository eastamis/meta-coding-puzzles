int getMinimumDeflatedDiscCount(int N, int *R)
{
  // Write your code here
  int ans = 0;

  for (int i = N - 1; i > 0; i--)
  {
    if (R[i] < (i + 1))
      return -1;

    if (R[i - 1] >= R[i])
    {
      ans++;
      R[i - 1] = R[i] - 1;
    }
  }

  return ans;
}
