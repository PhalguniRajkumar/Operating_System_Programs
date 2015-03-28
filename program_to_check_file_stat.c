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
printf( (S_ISDIR(file.st_mode)) ? "d" : "-");//checks if it is a file or directory
printf( (file.st_mode & S_IRUSR) ? "r" : "-");//checks if owner can read or not
printf( (file.st_mode & S_IWUSR) ? "w" : "-");//checks if owner can write or not
printf( (file.st_mode & S_IXUSR) ? "x" : "-");//checks if owner can execute or not
printf( (file.st_mode & S_IRGRP) ? "r" : "-");//checks if users in the same group as owner can read or not
printf( (file.st_mode & S_IWGRP) ? "w" : "-");//checks if users in the same group as owner can write or not
printf( (file.st_mode & S_IXGRP) ? "x" : "-");//checks if users in the same group as owner can execute or not
printf( (file.st_mode & S_IROTH) ? "r" : "-");//checks if users in the other groups as owner can read or not
printf( (file.st_mode & S_IWOTH) ? "w" : "-");//checks if users in the other groups as owner can write or not
printf( (file.st_mode & S_IXOTH) ? "x" : "-");//checks if users in the other groups as owner can execute or not
printf("\n");

if(file.st_mode & S_IFREG)
	printf("File type : Regular\n");
if(file.st_mode & S_IFDIR)
	printf("File type : Directory");
}
