/* File status - stat.c */
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char*argv[])
{
struct stat file;
int n;
if (argc != 2)
{
	//Enter in this format : ./a.out <filename or path>
printf("Usage: ./a.out <filename>\n");
exit(-1);
}
if ((n = stat(argv[1], &file)) == -1)
{
perror(argv[1]);
exit(-1);
}
printf("User id : %d\n", file.st_uid);
printf("Group id : %d\n", file.st_gid);
printf("Block size : %d\n", file.st_blksize);
printf("Blocks allocated : %d\n", file.st_blocks);
printf("Inode no. : %d\n", file.st_ino);
printf("Last accessed : %s", ctime(&(file.st_atime)));
printf("Last modified : %s", ctime(&(file.st_mtime)));
printf("File size : %d bytes\n", file.st_size);
printf("No. of links : %d\n", file.st_nlink);
printf("Permissions : ");
printf( (S_ISDIR(file.st_mode)) ? "d" : "-");
printf( (file.st_mode & S_IRUSR) ? "r" : "-");
printf( (file.st_mode & S_IWUSR) ? "w" : "-");
printf( (file.st_mode & S_IXUSR) ? "x" : "-");
printf( (file.st_mode & S_IRGRP) ? "r" : "-");
printf( (file.st_mode & S_IWGRP) ? "w" : "-");
printf( (file.st_mode & S_IXGRP) ? "x" : "-");
printf( (file.st_mode & S_IROTH) ? "r" : "-");
printf( (file.st_mode & S_IWOTH) ? "w" : "-");
printf( (file.st_mode & S_IXOTH) ? "x" : "-");
printf("\n");

if(file.st_mode & S_IFREG)
	printf("File type : Regular\n");
if(file.st_mode & S_IFDIR)
	printf("File type : Directory");
}
