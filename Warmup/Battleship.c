double getHitProbability(int R, int C, int** G) {
  // Write your code here
  double total_cell = R * C;
  double num_ship = 0.0;
  double result = 0.0;
  int r, c;
  
  for (r = 0; r < R; r++) {
    for (c = 0; c < C; c++) {
      if (G[r][c] == 1)
        num_ship += 1;
    }    
  }
  
  result = num_ship / total_cell;
  return result;
}
