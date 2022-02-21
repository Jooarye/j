@import "test.j";

// very unsafe function
fn stoi(str num) int {
  int result = 0;
  int idx;

  for idx = 0; idx < len(num); idx++ {
    result = result + pow(10, idx) * (num[idx] - 48);
  }

  ret result;
}

fn fib(int n) int {
  if n < 2 {
    ret 1;
  }

  ret fib(n - 1) + fib(n - 2);
}

fn main(int argc, str[] argv) int {
  if argc != 2 {
    prints("usage: prog <num>\n");
    ret 1;
  }

  int number = stoi(argv[1]);
  int result = fib(number);

  prints("result: ");
  printi(result);
  prints("\n");
  ret 0;
}