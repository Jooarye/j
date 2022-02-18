// very unsafe function
fn stoi(str num) int {
  int result = 0;
  int idx;

  for idx = 0; idx < len(num); idx++ {
    result = result + pow(10, idx) * (num[idx] - 48);
  }

  return result;
}