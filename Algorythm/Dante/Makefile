##
## EPITECH PROJECT, 2023
## Semester_2
## File description:
## Makefile
##

all:
		@$(MAKE) -C ./solver/
		@$(MAKE) -C ./generator/

clean:
		@rm -f $(OBJ)
		@$(MAKE) clean -C solver/
		@$(MAKE) clean -C generator/

fclean: clean
		@$(MAKE) fclean -C solver/
		@$(MAKE) fclean -C generator/

re:		fclean all
