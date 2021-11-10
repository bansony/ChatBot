#
# Makefile for simple line editor
# Author: Alexander Borodin, <aborod@petrsu.ru>
#

# Compiler
CC = gcc

# Linker
LD = gcc

#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CFLAG= -c -Wall
CCOBJECTS= editor.c load.c m.c mcf.c rh.c save.c show.c shownum.c
LIGHT_OBJECTS= load.o m.o mcf.o rh.o save.o show.o shownum.o
PROGRAM_NAME=editor
PREFIX=/home/02/bankovsk/inf/
DIST_NAME=$(PROGRAM_NAME).tar
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

# Build debug version of the editor
debug: MFLAGS += debug
debug: CFLAGS += -Wall -Wextra -DDEBUG -g -O0
debug: editor

# Build release version of the editor
release: MFLAGS += release
release: CFLAGS += -DNDEBUG
release: editor

# List sources and target object files 
SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

# Build editor
editor: $(OBJECTS) text
	$(LD) $(LDFLAGS) -o editor $(OBJECTS) -L./text -ltext

# Build text processing library
.PHONY: text
text: 
	cd text && $(MAKE) $(MFLAGS)

# Compile editor
%.o: %.c text/text.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Clean phony target to remove binary files
#.PHONY: clean
#clean:
#	cd text && $(MAKE) $@
#	rm -rf *.o editor

#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=
.PHONY: run install uninstall dist distclean mostlyclean clean help 

#полная очистка проекта
clean:
	rm $(OBJECTS) $(PROGRAM_NAME)

#частичная очистка проекта
mostlyclean:
	rm -rf $(LIGHT_NAME) $(PROGRAM_NAME)

#тестовый запуск
run:
	./$(PROGRAM_NAME)

#копирование в директорию
install:
	install ./$(PROGRAM_NAME) $(PREFIX)

#удаление из директории
uninstall:
	rm -rf $(PREFIX)$(PROGRAM_NAME)

#считает количество строк в файлах
linecount:
	wc -l $(CCOBJECTS)

#создание документации
doc: 
	doxygen  Doxyfile

#установка дистрибутива
dist:
	tar -cvf $(DIST_NAME) $(OBJECTS)

#удаление дистрибутива
distclean:
	rm -rf  $(DIST_NAME)

#справка об использовании файла сборки
help: 
	echo -e "$$(grep -hE '^\S+:.*##' $(MAKEFILE_LIST) | sed -e 's/:.*##\s*/:/' -e 's/^\(.\+\):\(.*\)/\\x1b[36m\1\\x1b[m:\2/' | column -c2 -t -s :)"

# Everything below is an example

clean:       ## make clean - полная очистка проекта

mostlyclean:       ## make mostlyclean - частичная очистка проекта

run:	## make run - тестовый запуск      

install:       ## make install - копирование установленного проекта в директорию

uninstall:       ## make uninstall - удаление установленного проекта из директории

linecount:    ## make linecount - считает количество строк в файлах

doc:       ## make doc - создание документации

dist:       ## make dist - сборка дистрибутива проекта

distclean:       ## make distclean - удаление дистрибутива проекта


.SILENT: help

#Если прописана цель неправильно
.DEFAULT:
	@echo 'Цель не определена, используйте make help'
