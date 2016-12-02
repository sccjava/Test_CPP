// basic file operations
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int readFile(const char* path, char *buff, int size)
{
	int readed = 0;
	int len;
	ifstream file(path);

	if(!file.is_open())
	{
		printf("open file failed, path=%s\n", path);
		return -1;
	}

	file.seekg(0, file.end);
	len = file.tellg();
	file.seekg(0, file.beg);

	if(len > size)
	{
		printf("buff size is not enough, size=%d, len=%d\n", size, len);
		file.close();
		return -1;
	}

	while(!file.eof())
	{
		file.read(buff + readed, size - readed);
		readed += file.gcount();
	}
	file.close();
	return readed;

}

#define MAX_BUFF_SIZE 600000
int main () {
  string path = "/Users/sunnysun/tmp/log.txt";
  char *buff = (char*)malloc(MAX_BUFF_SIZE);

  int len = readFile(path.c_str(), buff, MAX_BUFF_SIZE);
  printf("filename=%s, len=%d\n", strrchr(path.c_str(), '/'), len);
  return 0;
}