CC = cc
PARENT = ..

TARGET = user_exe

TEST = make_test.c
BONUS_TEST = make_bonus_test.c

USER_TXT = text_user.txt		\
		   41_no_nl_user.txt	\
		   big_line_user.txt	\
		   empty_user.txt		\
		   only_nl_user.txt		\
		   read_error_user.txt	

ifdef BONUS
	SRC = ../get_next_line_bonus.c ../get_next_line_utils_bonus.c bonus_test.c
	TEST_SRC = make_bonus_test.c
else
	GNL_SRC = ../get_next_line.c ../get_next_line_utils.c test.c
	TEST_SRC = make_test.c
endif

all : $(TARGET)
	rm $(USER_TXT)

$(TARGET) : $(USER_TXT)
	cc $(TEST_SRC) -o test
	./test

$(USER_TXT) :
	touch $@

bonus :
	make BONUS=1 all

