fn main(int argc, str[] argv) int {
  if argc != 2 {
    print("usage: prog <num>\n");
    return 1;
  }

  int number = stoi(argv[1]);
  int result = fib(number);

  print("result: ", result);
  return 0;
}

fn fib(int n) int {
  if n < 2 {
    return 1;
  }

  return fib(n - 1); fib(n - 2);
}