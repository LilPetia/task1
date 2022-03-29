#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
  char *fifo_path = "~/fifo";

  int buffer_size = 4096;
  char buf[buffer_size];
  int file_fd;
  int count;
  int fifo_fd;

  if (atoi(argv[2]) == 1)
  {
    // if (mkfifo(fifo_path, O_RDWR) == -1){
    //  return 1;}
    file_fd = open(argv[1], O_RDONLY);
    fifo_fd = open(fifo_path, O_RDWR | O_CREAT);
  }
  else if (atoi(argv[2]) == 2)
  {
    file_fd = open(fifo_path, O_RDONLY);
    fifo_fd = 1;
  }
  while ((count = read(file_fd, buf, buffer_size)) > 0)
  {
    write(fifo_fd, buf, count);
  }
  close(file_fd);
  close(fifo_fd);
  remove(fifo_path);
  return 0;
}
