/**
 * \file
 * \author Sonya Bankovskaya <bankovskaasona37@gmail.com>
 * \copyright MIT-style license
 * \date 6.10.2021
 * \brief Cтроковый текстовый редактор
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

/**
*Обрабатывает введенную пользователем команду и вызывает соответсвующую функцию:
*/
int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    char *arg2;
    
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
            /** 1) Функция загрузка файла:
            \code
            load(txt, arg);
            \endcode
            */
                load(txt, arg);
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
        /** 2) Функция вывода текста на экран:
        \code
        show(txt);
        \endcode
        */
            show(txt);
            continue;
        }

	/*Выводим текст на экран с нумерацией*/
	if (strcmp(cmd,"shownum")==0) {
	/** 3) Функция вывода текста на экран с нумерацией:
	\code
	shownum(txt);
	\endcode
	*/
	    shownum(txt);
	    continue;
	}

        /* Загружаем содержимое файла, заданного параметром */
	if (strcmp(cmd, "save") == 0) {
	    if ((arg = strtok(NULL, " \n")) == NULL) {
		fprintf(stderr, "Usage: save filename\n");
	    } else {
	    /** 4) Функция загрузки содержимого файла:
	    \code
	    save(txt, arg);
	    \endcode
	    */
		save(txt, arg);
	    }
	    continue;
	}
	
	/*Перемещение курсора на один символ вправо*/
	if (strcmp(cmd,"mcf")==0) {
	    /** 5) Функция перемещения курсора на один символ вправо:
	    \code
	    mcf(txt);
	    \endcode
	    */
	    mcf(txt);
	    continue;
	}

	/*Удаление первой строки*/
	if (strcmp(cmd,"rh")==0) {
	/** 6) Функция удаления первой строки:
	\code
	rh(txt);
	\endcode
	*/
	    rh(txt);
	    continue;
	}
	
	/*Перемещение курсора*/
	if (strcmp (cmd,"m")==0) {
	    arg = strtok(NULL, " \n");
	    arg2 = strtok(NULL, " \n");
	    if (arg == NULL || arg2 == NULL)
		fprintf(stderr, "Usage: m, line, position\n");
	    else {
		    int num_str = atoi(arg);
		    int num_pos = atoi(arg2);
		    /** 7) Функция перемещения курсора:
		    \code
		    m(txt, num_str, num_pos);
		    \endcode
		    */
		    m(txt, num_str, num_pos);
	    }
		continue;
	}
	
	
        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    

    return 0;
}
}
