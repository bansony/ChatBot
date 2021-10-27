/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2020, Tikkoeva Anastasia <tikkoeva@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    char *arg2;
    char *arg3;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

		if (strcmp(cmd, "m") == 0) {
	    if ((arg2 = strtok(NULL, " \n")) == NULL) {
		fprintf(stderr, "Usage: line number\n");
	    }
	    else {
		if ((arg3 = strtok(NULL, " \n")) == NULL) {
		    fprintf(stderr, "Usage: cursor number\n");
		}
		else {
		    int num_str = atoi(arg2);
		    int num_pos = atoi(arg3);

		    m(txt, num_str, num_pos);
		}
		continue;
	    }
	}

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }

	 /* Выводим текст */
        if (strcmp(cmd, "showupper") == 0) {
            to_upper(txt);
            continue;
        }

	/* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }

	/* Перемещает курсор в начало строки */
	if (strcmp(cmd, "mlb") == 0) {
	    mlb(txt);
	    continue;
	}
	
	/* Удаляет первую пустую строку */
	if (strcmp(cmd, "r1e") == 0) {
	    r1e(txt);
	    continue;
	}
		
	/* Если команда не известна */
    fprintf(stderr, "Unknown command: %s\n", cmd);
  

    return 0;
    }
}
