/*******************************************************************************************************************************
*Copyright (C) Arti Mede medeaa15.comp@coep.ac.in
*
*This program is a free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public Licence as *published by the Free Software Foundation; either version 2.1 of the Licence, or (at your option ) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY *or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public Licence for more details.
*
*You should have recieved a copy of the GNU Lesser General Public Licence along with this program; if not write to the Free Software *Foundation, INC., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
********************************************************************************************************************************/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<ctype.h>

int nlines(int, char **);
int tenlines(int, char **);
int bbytes(int, char **);
int verbose(int, char **);
int quite(int, char **);
int version();
int help();

int main(int argc, char *argv[]) {
	int choice, temp;
	/* use switch to choose funtions*/
	printf("Enter choice\n");
	printf("1. Print n number of lines\n");
	printf("2. Print 10 number of lines\n");
	printf("3. Print n number of bytes\n");
	printf("4. Verbose\n");
	printf("5. Quite\n");
	printf("6. Version\n");
	printf("7. Help\n");
	scanf("%d", &choice);
	switch(choice) {
		case 1:
			temp = nlines(argc, argv);
			break;
		case 2:
			temp = tenlines(argc, argv);
			break;
		case 3:
			temp = bbytes(argc, argv);
			break;
		case 4:
			temp = verbose(argc, argv);
			break;
		case 5:
			temp = quite(argc, argv);
			break;
		case 6:
			temp = version();
			break;
		case 7:
			temp = help();
			break;
	}
	
return 0;
}

int nlines(int argc, char *argv[]) {	//Print n number of lines
	int fd, i;
	char ch;
	int n;
	printf("Enter number of lines to be printed\n");
	scanf("%d",&n);
	for(i = 1; i < argc; i++) {
		fd = open(argv[i], O_RDONLY);
		if(fd == -1) {
			perror("open failed:");
			return errno;
		}
		int count = 0;
		while(read(fd, &ch, 1) && count < n) {
			putchar(ch);
			if(ch == '\n')
				count ++;
		}
	printf("\n");
	printf("\n");
	}
	close(fd);
return 0;
}

int tenlines(int argc, char *argv[]) {	//Print 10 lines of given file
	int fd =0;
	char ch =0;
	int i;
	for(i = 1; i < argc; i++) {
		fd = open(argv[i],O_RDONLY);
		if(fd == -1) {
			perror("open failed:");
			return errno;
		}
		int count = 0;
		while(read(fd, &ch, 1) && count < 10) {
			putchar(ch);
			if(ch == '\n')
				count++;
			}
	printf("\n");
	printf("\n");
	}
	close(fd);
return 0;
}

int bbytes(int argc, char *argv[]) {	//Prints b number of bytes
	int fd, i, j, b;
	char ch;
	printf("Enter number of bytes to be printed\n");
	scanf("%d", &b);
	for(i = 1; i < argc; i++) {
		fd = open(argv[i], O_RDONLY);
		if(fd == -1) {
			perror("open failed:");
			return errno;
		}
		int j = 0;
		while(read(fd, &ch, 1) && j<b) {
			putchar(ch);
			j++;
		}
	printf("\n");
	printf("\n");
	}
return 0;
}

int verbose(int argc, char *argv[]) {	//Print 10 lines of given file with filename as header
	int fd =0;
	char ch =0;
	int i;
	for(i = 1; i < argc; i++) {
		fd = open(argv[i],O_RDONLY);
		if(fd == -1) {
			perror("open failed:");
			return errno;
		}
		int count = 0;
		printf("==> %s <==",argv[i]);
		printf("\n");
		while(read(fd, &ch, 1) && count < 10) {
			putchar(ch);
			if(ch == '\n')
			count++;
		}
	printf("\n");
	printf("\n");
	}
	close(fd);
return 0;
}

int quite(int argc, char *argv[]) {	//Print 10 lines of given file without filename as header
	int fd =0;
	char ch =0;
	int i;
	for(i = 1; i < argc; i++) {
		fd = open(argv[i],O_RDONLY);
		if(fd == -1) {
			perror("open failed:");
			return errno;
		}
		int count = 0;
		while(read(fd, &ch, 1) && count < 10) {
			putchar(ch);
			if(ch == '\n')
			count++;
		}
	printf("\n");
	printf("\n");
	}
	close(fd);
return 0;
}

int version() {
	printf("head (GNU coreutils) 8.25");
	printf("Copyright (C) 2016 Free Software Foundation, Inc.");
	printf("License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.");
	printf("This is free software: you are free to change and redistribute it.");
	printf("There is NO WARRANTY, to the extent permitted by law.");
	printf("\n");
	printf("Written by David MacKenzie and Jim Meyering.");

return 0;
}

int help() {
	printf("Print the first 10 lines of each FILE to standard output.\n");

	printf("With more than one FILE, precede each with a header giving the file name.\n");

	printf("With no FILE, or when FILE is -, read standard input.\n");

	printf("Mandatory arguments to long options are mandatory for short options too.\n");

	printf("nlines		prints the first N number of lines;\n");

	printf("tenlines	print the first ten lines instead of first 10;\n");

	printf("bbytes		prints the first B bytes of each file;\n");

	printf("verbose		prints the first 10 lines with headers giving file names\n");

	printf("quite		prints the first ten lines without giving file names\n");
	
	printf("help		display this help and exit\n");

	printf("exit\n");

	printf("GNU coreutils online help: <http://www.gnu.org/software/coreutils/>\n");
	printf("Full documentation at: <http://www.gnu.org/software/coreutils/head>\n");
	printf("or available locally via: info '(coreutils) head invocation'\n");
	return 0;
}
