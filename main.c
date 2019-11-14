#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int main(){
  struct stat x;
  if (0 > stat("example.txt", &x)) {
		printf("Error Getting Data From File: %s\n", strerror(errno));
		return 0;
	}
  printf("-----Description of example.txt-----\n");
  printf("File size: %ld\n", x.st_size);
	printf("File Permissions: %d\n", x.st_mode);
	time_t prev = x.st_atime;
	printf("Recently accessed: %s\n", ctime(&prev));
	return 0;
}
