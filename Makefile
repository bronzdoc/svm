SRC_FILES = main.c lib/stack.c lib/svm.c
CC_FLAGS = -Wall -std=c11
CC = gcc

default:
	${CC} ${SRC_FILES} ${CC_FLAGS} -o svm
