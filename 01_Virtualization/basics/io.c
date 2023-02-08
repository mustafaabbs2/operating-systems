#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    //O_WRONLY is for writing only
    //O_CREAT is for creating a file if it does not exist
    //O_TRUNC is for truncating the file if it already exists
    //S_IRUSR is for read permission for the owner
    //S_IWUSR is for write permission for the owner


    assert(fd >= 0);
    //this is a sanity check to make sure that the file descriptor is valid

    char buffer[20];
    
    sprintf(buffer, "hello world\n");
    
    int rc = write(fd, buffer, strlen(buffer));
    
    assert(rc == (strlen(buffer)));
    
    fsync(fd);
    //fsync is used to make sure that the file is written to the disk

    close(fd);
    return 0;
}