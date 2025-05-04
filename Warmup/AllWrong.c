char* getWrongAnswers(int N, char* C) {
  // Write your code here
  char *s;
  int i;
  
  if (N == 0)
    return "";
  
  s = malloc(N);
  for (i = 0; i < N; i++) {
    s[i] = (C[i] == 'A') ? 'B' : 'A';
  }
  return s;
}
