#define ODD 0
#define EVEN 1
int getMinProblemCount(int N, int *S)
{
  // Write your code here
  int point_values[2] = {0, 0}; // number of "Odd", "Even" score

  for (int i = 0; i < N; i++)
  {
    int divider = S[i] / 2;
    if (point_values[EVEN] < divider)
      point_values[EVEN] = divider;
    if (S[i] % 2 == 1)
      point_values[ODD] = 1;
  }

  return point_values[ODD] + point_values[EVEN];
}
