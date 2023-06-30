##
## EPITECH PROJECT, 2023
## B-SYN-200-NAN-2-1-automakefile-tibaud.le-maout
## File description:
## Makefile
##

SRC=	./main.c	\
		./calc.c	\

OBJ=	$(SRC:.c=.o)

EXEC=	fakeProj

CC=	clang

CFLAGS=	-I ./$(HEADER_DIR) -ftest-coverage -O2

LIB=	-L ./librarys

HEADER_DIR=	include

INCLUDE=	-I ./$(HEADER_DIR)	\
			./$(HEADER_DIR)/calc/calc.h	\
			./$(HEADER_DIR)/fakeProj.h	\

LDFlAGS=

BCK_DIR=	backup

ZIP=	tar

ZIPFLAGS=	-cvvf

UNZIP=	tar

UNZIPFLAGS=	-xvf

all: $(EXEC)

$(EXEC): $(OBJ)
		ar rc ./librarys/libmy.a $(OBJ)
		$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXEC) $(SRC) $(LIB)

clean:
		rm -f $(OBJ)
		rm -f *.gcno

fclean: clean
		rm -f ./librarys/libmy.a
		rm -f $(EXEC)

archive: fclean
		$(ZIP) $(ZIPFLAGS) $(BCK_DIR)/archive ./
		@echo "archive file generated"
		@./version.sh "add"

revert:
		$(UNZIP) $(UNZIPFLAGS) $(BCK_DIR)/archive*
		@./version.sh "rev"

num:
		@cat Version

delete:
		rm -f $(BCK_DIR)/archive

re:	fclean all
