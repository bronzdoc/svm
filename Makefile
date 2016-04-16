SRC_FILES = svm.c
CC_FLAGS = -Wall -std=c99
CC = gcc

default:
	${CC} ${SRC_FILES} ${CC_FLAGS} -o svm
