
// crt_fopen_s.c
// This program opens two files. It uses
// fclose to close the first file and
// _fcloseall to close all remaining files.


#include <stdio.h>
#include <pch.h>

FILE *stream, *stream2;

int main(void)
{
	errno_t err;

	// Open for read (will fail if file "crt_fopen_s.c" does not exist)
	err = fopen_s(&stream, "kismet_data.txt", "r");
	if (err == 0)
	{
		printf("The file opened\n");
	}
	else
	{
		printf("The file did not open\n");
	}

	// Open for write 
	err = fopen_s(&stream2, "MAC_data", "w+");
	if (err == 0)
	{
		printf("The data file was opened\n");
	}
	else
	{
		printf("The data file was not opened\n");
	}









	// Close stream if it is not NULL 
	if (stream)
	{
		err = fclose(stream);
		if (err == 0)
		{
			printf("The file was closed\n");
		}
		else
		{
			printf("The file was not closed\n");
		}
	}

	// All other files are closed:
	int numclosed = _fcloseall();
	printf("Number of files closed by _fcloseall: %u\n", numclosed);
}