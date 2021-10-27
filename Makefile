CC = gcc
LD = gcc
CFLAGS = -c -Wall
CCOBJECTS = editor.c load.c m.c mlb.c save.c show.c showupper.c
LIGHT_OBJECTS = load.o m.o mlb.o save.o show.o showupper.o
PROGRAM_NAME = editor
PREFIX = /home/02/tikkoeva/bin/
DIST_NAME = $(PROGRAM_NAME).tar

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

.PHONY: run install uninstall dist distclean mostlyclean clean help

clean:
	rm $(OBJECTS) $(PROGRAM_NAME)

mostlyclean:
	rm -rf $(LIGHT_OBJECTS) $(PROGRAM_NAME)

run:
	./$(PROGRAM_NAME)

install:
	install ./$(PROGRAM_NAME) $(PREFIX)

uninstall:
	rm -rf $(PREFIX)$(PROGRAM_NAME)

linecount:
	wc -l $(CCOBJECTS)

doc:  ## создание докумениации
	doxygen Doxyfile
dist: ## сборка дистрибутива
	tar -cvf $(DIST_NAME) $(OBJECTS)

distclean:
	rm -rf $(DIST_NAME)

help: ## This help message
	echo -e "$$(grep -hE '^\S+:.*##' $(MAKEFILE_LIST) | sed -e 's/:.*##\s*/:/' -e 's/^\(.\+\):\(.*\)/\\x1b[36m\1\\x1b[m:\2/' | column -c2 -t -s :)"

# Everything below is an example

target00:       ## make clean and make mostlyclean- полная очистка проекта и частичная очистка проекта
	@echo does nothing

target01:       ## make linecount - считает кол-во строк в файлах
	@echo does something

target02:       ## make run - тестовый запуск
target02: target00 target01
	@echo does even more

target03:       ## make install and make uninstall - копирование в директорию и удаление
	@echo does something

target04:       ## make dist and make distclean - установка дистрибутива и удаление
	@echo does something	

.SILENT: help

.DEFAULT:
	@echo 'Цель не найдена, используйте make help'