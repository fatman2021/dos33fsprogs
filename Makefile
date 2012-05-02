CC = gcc
CFLAGS = -O2 -Wall
LFLAGS =

all:	dos33 asoft_detoken mkdos33fs make_b tokenize_asoft \
	dos33_text2ascii integer_detoken char2hex



asoft_detoken:		   asoft_detoken.o
			   $(CC) $(LFLAGS) -o asoft_detoken asoft_detoken.o

asoft_detoken.o:	   asoft_detoken.c
			   $(CC) $(CFLAGS) -c asoft_detoken.c
			   
integer_detoken:	   integer_detoken.o
			   $(CC) $(LFLAGS) -o integer_detoken integer_detoken.o

integer_detoken.o:	   integer_detoken.c
			   $(CC) $(CFLAGS) -c integer_detoken.c
			 
tokenize_asoft:		   tokenize_asoft.o
			   $(CC) $(LFLAGS) -o tokenize_asoft tokenize_asoft.o
			   
tokenize_asoft.o:	   tokenize_asoft.c
			   $(CC) $(CFLAGS) -c tokenize_asoft.c

char2hex:	char2hex.o
	$(CC) $(LFLAGS) -o char2hex char2hex.o

char2hex.o:	char2hex.c
	$(CC) $(CFLAGS) -c char2hex.c

dos33:	dos33.o
		$(CC) $(LFLAGS) -o dos33 dos33.o
		
dos33.o:	dos33.c dos33.h
		$(CC) $(CFLAGS) -c dos33.c

dos33_text2ascii:     dos33_text2ascii.o
		      $(CC) $(LFLGAS) -o dos33_text2ascii dos33_text2ascii.o
		      
dos33_text2ascii.o:   dos33_text2ascii.c
		      $(CC) $(CFLAGS) -c dos33_text2ascii.c

make_b:	make_b.o
		$(CC) $(LFLAGS) -o make_b make_b.o
		
make_b.o:	make_b.c
		$(CC) $(CFLAGS) -c make_b.c
		
		
mkdos33fs:	mkdos33fs.o
		$(CC) $(LFLAGS) -o mkdos33fs mkdos33fs.o
		
mkdos33fs.o:	mkdos33fs.c dos33.h
		$(CC) $(CFLAGS) -c mkdos33fs.c


install:	
		cp dos33 asoft_detoken mkdos33fs tokenize_asoft make_b dos33_text2ascii integer_detoken /usr/local/bin

clean:		
		rm -f *~ *.o asoft_detoken dos33 make_b mkdos33fs tokenize_asoft dos33_text2ascii integer_detoken char2hex
		cd tests && make clean
