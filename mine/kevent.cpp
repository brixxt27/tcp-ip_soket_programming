#include <sys/event.h>
#include <iostream>
#include <fstream>

int	main()
{
  const int kq = kqueue();
  struct kevent change_list;

  const char* path = "./test.txt";
  std::ifstream ifs(path);

  if (ifs.is_open() == false) {
    std::cout << "File open is fail!" << std::endl;
    std::exit(1);
  }

  EV_SET()

  kevent(kq, )
}