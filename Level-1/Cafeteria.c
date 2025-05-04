// Write any include statements here
int cmpfunc(const void *a, const void *b)
{
  if (*(long long *)a - *(long long *)b < 0)
    return -1;
  if (*(long long *)a - *(long long *)b > 0)
    return 1;
  return 0;
}

long long getMaxAdditionalDinersCount(long long N, long long K, int M, long long *S)
{
  // Write your code here

  // sort S
  qsort(S, M, sizeof(long long), cmpfunc);

  // Initialize variables
  long long extraSpace = 0;    // Tracks the number of required additional diners
  long long firstOpenSeat = 1; // Tracks the first available seat

  // Iterate through each existing diner's seat position
  for (int i = 0; i < M; i++)
  {
    // Calculate the number of available seats to the left of the current diner
    long long openSeats = S[i] - K - firstOpenSeat;
    // If there are any available seats to the left of the current diner,
    // calculate the number of required additional diners and add it to the total
    if (openSeats > 0)
    {
      extraSpace += ceil((double)openSeats / (K + 1));
    }
    // Update the first available seat to the right of the current diner
    firstOpenSeat = S[i] + K + 1;
  }

  // Calculate the number of available seats to the right of the last diner
  long long openSeats = N + 1 - firstOpenSeat;
  // If there are any available seats to the right of the last diner,
  // calculate the number of required additional diners and add it to the total
  if (openSeats > 0)
  {
    extraSpace += ceil((double)openSeats / (K + 1));
  }

  // Return the total number of required additional diners
  return extraSpace;
}
