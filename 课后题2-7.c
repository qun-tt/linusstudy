#include "ch02. h"
#define BUF_SIZE 8
int main (void)
{
	FILE *fd;
	int fgets_ yes;
	struct iobuf{
		char buf[BUF_ SIZE] ;
		char others[BUF_ SIZE] ;
	}buffer;
	memset (&buffer, '\0' ,sizeof (struct iobuf) ) ;
	do {
	fgets_ yes = y_ or_ n_ ques("Should we read by fgets() ?") ;
	fprintf (stdout, "please enter a line\n") ;
	if(fgets_ yes) {
		fgets (buffer.buf, BUF_ SIZE, stdin) ;
		fprintf (stdout, "fgets() get string \"号s\"\n", buffer.buf) ;
		while (buffer. buf [strlen (buffer.buf)-1] != '\n'){ 
		fgets (buffer.buf, BUF_ SIZE ，stdin) ;
		fprintf (stdout, "fgets() get string \"&s\"\n", buffer .buf) ;
		} else {
			gets (buffer .buf) ;
			fprintf (stdout, "gets() get string \"号s\"\n" ,buffer .buf) ;
			fprintf (stdout, "buffer.others is \"号s\"\n", buffer .others) ;
		} while (y_ or_ n_ ques ("continue?")) ;
		exit (0) ;
}