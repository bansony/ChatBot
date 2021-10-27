/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2020, Tikkoeva Anastasia <tikkoeva@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

/**
 * Сохраняет содержимое указанного файла
 */
void save(text txt, char *filename);

/**
 * Выводит содержимое указанного файла
 * в верхнем регистре
 */
void to_upper(text txt);

/**
 * Перемещает курсор в заданную позицию
 */
void m(text txt, int num_str, int num_pos);

/**
 * Перемещает курсор в начало строки
 */
  void mlb( text txt);

/**
 * Удаляет первую пустую строку
 */
void r1e(text txt);

#endif
