/**
 * text.h -- внешний интерфейс библиотеки для работы с текстом
 *
 * Copyright (c) 2020, Sonya Bankpvskaya <bankovskaasona37@gmail.com>   
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef TEXT_H
#define TEXT_H

#define MAXLINE 255

/**
 * Абстрактный тип текстовых объектов
 */
typedef struct _list *text;

/**
 * Абстрактный тип курсора
 */
typedef struct _crsr *cursor;


/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text();

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, const char *contents);


/**
 * Обрабатывает текст, применяя заданную функцию к каждой строке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text txt,
    void (*process)(int index, char *contents, int cursor_position, void *data),
    void *data
);

/**Перемещение курсора*/
void process_m(text txt, int num_str,int  num_pos);

/*Перемещение курсора на один символ*/
void process_mcf(
    text txt,
    void (*process)(int index, char *contents, int cursor, void *data),
        void *data
);

/*Удаление первой строки*/
void process_rh(
    text txt,
    void (*process)(int index, char *contents, int cursor, void *data),
            void *data
    );

/**
 * Удаляет весь текст
 * 
 * @param txt текст
 * @returns none
 */
void remove_all(text txt);

#endif
