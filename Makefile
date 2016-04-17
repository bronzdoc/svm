SRC_FILES = svm.c lib/stack.c
CC_FLAGS = -Wall -std=c11
CC = gcc

default:
	${CC} ${SRC_FILES} ${CC_FLAGS}  -o svm
