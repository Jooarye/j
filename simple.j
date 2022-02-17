fn main(int argc, str[] argv) int {
  if argc != 2 {
    print("usage: test <name>\n");
  } else {
    print("Yay, hello ", argv[1], ", how are you?\n");
  }

  return 0;
}