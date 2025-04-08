##
## EPITECH PROJECT, 2024
## Semester_3
## File description:
## Makefile
##

SRC =	strlen.asm	\
		strchr.asm	\
		strrchr.asm	\
		strcmp.asm	\
		strncmp.asm	\
		strcasecmp.asm	\
		strstr.asm	\
		memset.asm	\
		memcpy.asm

OBJ =	$(SRC:.asm=.o)

NAME	= 	libasm.so

CFLAGS	=	-fPIC -shared

ASMFLAGS	=	-f elf64

all: $(NAME)

$(NAME): $(OBJ)
	ld $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.asm
	nasm $(ASMFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all 
