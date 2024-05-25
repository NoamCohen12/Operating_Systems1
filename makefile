.PHONY: question_1 question_2 question_3 question_4 question_5 question_6

all: question_1 question_2 question_3 question_4 question_5 question_6

question_1:
	make -C question_1

question_2:
	make -C question_2

question_3:
	make -C question_3

question_4:
	make -C question_4

question_5:
	make -C question_5

question_6:
	make -C question_6

clean:
	make -C question_1 clean
	make -C question_2 clean
	make -C question_3 clean
	make -C question_4 clean
	make -C question_5 clean
	make -C question_6 clean





