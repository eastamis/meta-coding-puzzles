int get_digits(long long x)
{
  int d = 0;
  while (x)
  {
    d++;
    x /= 10;
  }
  return d;
}

void uniformIntegersFactory(int digits, long long *uniform)
{
  long long base_num = 1;
  while (--digits)
  {
    base_num *= 10;
    base_num += 1;
  }
  uniform[0] = base_num;
  for (int i = 1; i < 9; i++)
  {
    uniform[i] = uniform[i - 1] + base_num;
  }
}

int getUniformIntegerCountInInterval(long long A, long long B)
{
  // Write your code here

  int ans = 0;
  int digitA = get_digits(A);
  int digitB = get_digits(B);
  long long uniArray[9];

  while (digitA <= digitB)
  {
    uniformIntegersFactory(digitA, uniArray);
    for (int i = 0; i < 9; i++)
    {
      if (A <= uniArray[i] && uniArray[i] <= B)
        ans++;
    }
    digitA++;
  }

  return ans;
}
