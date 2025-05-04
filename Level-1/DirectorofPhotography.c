int getArtisticPhotographCount(int N, char *C, int X, int Y)
{
  // Write your code here
  int result = 0;
  int *prefixPSum = (int *)malloc((N + 1) * sizeof(int));
  int *prefixBSum = (int *)malloc((N + 1) * sizeof(int));

  memset(prefixPSum, 0, (N+1) * sizeof(int));
  memset(prefixBSum, 0, (N+1) * sizeof(int));
  
  for (int i = 0; i < N; i++)
  {
    if (C[i] == 'P')
    {
      prefixPSum[i + 1] = prefixPSum[i] + 1;
    }
    else
    {
      prefixPSum[i + 1] = prefixPSum[i];
    }
    if (C[i] == 'B')
    {
      prefixBSum[i + 1] = prefixBSum[i] + 1;
    }
    else
    {
      prefixBSum[i + 1] = prefixBSum[i];
    }
  }

  int leftWindowStart;
  int leftWindowEnd;
  int rightWindowStart;
  int rightWindowEnd;

  for (int i = 0; i < N; i++)
  {
    if (C[i] == 'A')
    {
      leftWindowStart = i - Y;
      if (leftWindowStart < 0)
        leftWindowStart = 0;
      leftWindowEnd = i - X + 1;
      if (leftWindowEnd < 0)
        leftWindowEnd = 0;

      rightWindowStart = i + X;
      if (rightWindowStart > N)
        rightWindowStart = N;
      rightWindowEnd = i + Y + 1;
      if (rightWindowEnd > N)
        rightWindowEnd = N;

      int leftPs = prefixPSum[leftWindowEnd] - prefixPSum[leftWindowStart];
      int rightBs = prefixBSum[rightWindowEnd] - prefixBSum[rightWindowStart];
      result += leftPs * rightBs;

      int rightPs = prefixPSum[rightWindowEnd] - prefixPSum[rightWindowStart];
      int leftBs = prefixBSum[leftWindowEnd] - prefixBSum[leftWindowStart];
      result += leftBs * rightPs;
    }
  }

  free(prefixPSum);
  free(prefixBSum);

  return result;
}