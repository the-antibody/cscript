# csc
CC = gcc
FILES = main.c file.c includes.c interpreter.c
OUT = csc
DEST = /usr/bin

build:
	$(CC) $(FILES) -o $(OUT)

install:
	make build
	cp -f $(OUT) $(DEST)/$(OUT)
	echo Successfully installed csc.

uninstall:
	rm -f $(DEST)/$(OUT)
	echo Successfully uninstalled csc.