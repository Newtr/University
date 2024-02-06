--Процедуры для таблицы ТРУДОВЫЕ ДОГОВОРЫ:
CREATE OR REPLACE PROCEDURE INSERT_ДОГОВОР (
    p_Дата_Начала DATE,
    p_Дата_Окончания DATE,
    p_Тип_Договора VARCHAR2
) AS
BEGIN
    INSERT INTO ТРУДОВЫЕ_ДОГОВОРЫ (ДАТА_НАЧАЛА_ДЕЙСТВИЯ_ДОГОВОРА, ДАТА_ОКОНЧАНИЯ_ДЕЙСТВИЯ_ДОГОВОРА, ТИП_ДОГОВОРА)
    VALUES (p_Дата_Начала, p_Дата_Окончания, p_Тип_Договора);
END INSERT_ДОГОВОР;
/

CREATE OR REPLACE PROCEDURE UPDATE_ДОГОВОР (
    p_ИД_Договора NUMBER,
    p_Дата_Начала DATE,
    p_Дата_Окончания DATE,
    p_Тип_Договора VARCHAR2
) AS
BEGIN
    UPDATE ТРУДОВЫЕ_ДОГОВОРЫ
    SET ДАТА_НАЧАЛА_ДЕЙСТВИЯ_ДОГОВОРА = p_Дата_Начала,
        ДАТА_ОКОНЧАНИЯ_ДЕЙСТВИЯ_ДОГОВОРА = p_Дата_Окончания,
        ТИП_ДОГОВОРА = p_Тип_Договора
    WHERE ИДЕНТИФИКАТОР_ДОГОВОРА = p_ИД_Договора;
END UPDATE_ДОГОВОР;
/

CREATE OR REPLACE PROCEDURE DELETE_ДОГОВОР (
    p_ИД_Договора NUMBER
) AS
BEGIN
    DELETE FROM ТРУДОВЫЕ_ДОГОВОРЫ WHERE ИДЕНТИФИКАТОР_ДОГОВОРА = p_ИД_Договора;
END DELETE_ДОГОВОР;
/

--Процедуры для таблицы СОТРУДНИКИ:
CREATE OR REPLACE PROCEDURE INSERT_СОТРУДНИК (
    p_ФИО VARCHAR2,
    p_Контракт NUMBER,
    p_Роль VARCHAR2,
    p_Дата_Рождения DATE,
    p_Пол VARCHAR2,
    p_Отдел VARCHAR2
) AS
BEGIN
    INSERT INTO СОТРУДНИКИ (ФИО_СОТРУДНИКА, КОНТРАКТ, РОЛЬ, ДАТА_РОЖДЕНИЯ, ПОЛ, ОТДЕЛ)
    VALUES (p_ФИО, p_Контракт, p_Роль, p_Дата_Рождения, p_Пол, p_Отдел);
END INSERT_СОТРУДНИК;
/

CREATE OR REPLACE PROCEDURE UPDATE_СОТРУДНИК (
    p_ИД_Сотрудника NUMBER,
    p_ФИО VARCHAR2,
    p_Контракт NUMBER,
    p_Роль VARCHAR2,
    p_Дата_Рождения DATE,
    p_Пол VARCHAR2,
    p_Отдел VARCHAR2
) AS
BEGIN
    UPDATE СОТРУДНИКИ
    SET ФИО_СОТРУДНИКА = p_ФИО,
        КОНТРАКТ = p_Контракт,
        РОЛЬ = p_Роль,
        ДАТА_РОЖДЕНИЯ = p_Дата_Рождения,
        ПОЛ = p_Пол,
        ОТДЕЛ = p_Отдел
    WHERE ИДЕНТИФИКАТОР_СОТРУДНИКА = p_ИД_Сотрудника;
END UPDATE_СОТРУДНИК;
/

CREATE OR REPLACE PROCEDURE DELETE_СОТРУДНИК (
    p_ИД_Сотрудника NUMBER
) AS
BEGIN
    DELETE FROM СОТРУДНИКИ WHERE ИДЕНТИФИКАТОР_СОТРУДНИКА = p_ИД_Сотрудника;
END DELETE_СОТРУДНИК;
/

--Процедуры для таблицы КОМАНДА_РАЗРАБОТЧИКОВ:
CREATE OR REPLACE PROCEDURE INSERT_КОМАНДА (
    p_Название_Команды VARCHAR2,
    p_Сотрудники VARCHAR2,
    p_ИД_Продукта NUMBER
) AS
BEGIN
    INSERT INTO КОМАНДА_РАЗРАБОТЧИКОВ (НАЗВАНИЕ_КОМАНДЫ, СОТРУДНИКИ, ИДЕНТИФИКАТОР_ПРОДУКТА)
    VALUES (p_Название_Команды, p_Сотрудники, p_ИД_Продукта);
END INSERT_КОМАНДА;
/

CREATE OR REPLACE PROCEDURE UPDATE_КОМАНДА (
    p_ИД_Команды NUMBER,
    p_Название_Команды VARCHAR2,
    p_Сотрудники VARCHAR2,
    p_ИД_Продукта NUMBER
) AS
BEGIN
    UPDATE КОМАНДА_РАЗРАБОТЧИКОВ
    SET НАЗВАНИЕ_КОМАНДЫ = p_Название_Команды,
        СОТРУДНИКИ = p_Сотрудники,
        ИДЕНТИФИКАТОР_ПРОДУКТА = p_ИД_Продукта
    WHERE ИДЕНТИФИКАТОР_КОМАНДЫ = p_ИД_Команды;
END UPDATE_КОМАНДА;
/

CREATE OR REPLACE PROCEDURE DELETE_КОМАНДА (
    p_ИД_Команды NUMBER
) AS
BEGIN
    DELETE FROM КОМАНДА_РАЗРАБОТЧИКОВ WHERE ИДЕНТИФИКАТОР_КОМАНДЫ = p_ИД_Команды;
END DELETE_КОМАНДА;
/

--Процедуры для таблицы ОТДЕЛ:
CREATE OR REPLACE PROCEDURE INSERT_ОТДЕЛ (
    p_Наименование_Отдела VARCHAR2
) AS
BEGIN
    INSERT INTO ОТДЕЛЫ (НАИМЕНОВАНИЕ_ОТДЕЛА)
    VALUES (p_Наименование_Отдела);
END INSERT_ОТДЕЛ;
/

CREATE OR REPLACE PROCEDURE UPDATE_ОТДЕЛ (
    p_ИД_Отдела NUMBER,
    p_Наименование_Отдела VARCHAR2
) AS
BEGIN
    UPDATE ОТДЕЛЫ
    SET НАИМЕНОВАНИЕ_ОТДЕЛА = p_Наименование_Отдела
    WHERE ИДЕНТИФИКАТОР_ОТДЕЛА = p_ИД_Отдела;
END UPDATE_ОТДЕЛ;
/

CREATE OR REPLACE PROCEDURE DELETE_ОТДЕЛ (
    p_ИД_Отдела NUMBER
) AS
BEGIN
    DELETE FROM ОТДЕЛЫ WHERE ИДЕНТИФИКАТОР_ОТДЕЛА = p_ИД_Отдела;
END DELETE_ОТДЕЛ;
/

--Процедуры для таблицы СОБЕСЕДОВАНИЕ:
CREATE OR REPLACE PROCEDURE INSERT_СОБЕСЕДОВАНИЕ (
    p_ИД_Вакансии NUMBER,
    p_Имя_Кандидата VARCHAR2,
    p_Дата_Собеседования DATE,
    p_Результат_Собеседования VARCHAR2,
    p_Сотрудник NUMBER
) AS
BEGIN
    INSERT INTO СОБЕСЕДОВАНИЯ (ИДЕНТИФИКАТОР_ВАКАНСИИ, ИМЯ_КАНДИДАТА, ДАТА_СОБЕСЕДОВАНИЯ, РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ, СОТРУДНИК_ПРИНИМАВШИЙ_СОБЕСЕДОВАНИЕ)
    VALUES (p_ИД_Вакансии, p_Имя_Кандидата, p_Дата_Собеседования, p_Результат_Собеседования, p_Сотрудник);
END INSERT_СОБЕСЕДОВАНИЕ;
/

CREATE OR REPLACE PROCEDURE UPDATE_СОБЕСЕДОВАНИЕ (
    p_ИД_Собеседования NUMBER,
    p_ИД_Вакансии NUMBER,
    p_Имя_Кандидата VARCHAR2,
    p_Дата_Собеседования DATE,
    p_Результат_Собеседования VARCHAR2,
    p_Сотрудник NUMBER
) AS
BEGIN
    UPDATE СОБЕСЕДОВАНИЯ
    SET ИДЕНТИФИКАТОР_ВАКАНСИИ = p_ИД_Вакансии,
        ИМЯ_КАНДИДАТА = p_Имя_Кандидата,
        ДАТА_СОБЕСЕДОВАНИЯ = p_Дата_Собеседования,
        РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ = p_Результат_Собеседования,
        СОТРУДНИК_ПРИНИМАВШИЙ_СОБЕСЕДОВАНИЕ = p_Сотрудник
    WHERE ИДЕНТИФИКАТОР_СОБЕСЕДОВАНИЯ = p_ИД_Собеседования;
END UPDATE_СОБЕСЕДОВАНИЕ;
/

CREATE OR REPLACE PROCEDURE DELETE_СОБЕСЕДОВАНИЕ (
    p_ИД_Собеседования NUMBER
) AS
BEGIN
    DELETE FROM СОБЕСЕДОВАНИЯ WHERE ИДЕНТИФИКАТОР_СОБЕСЕДОВАНИЯ = p_ИД_Собеседования;
END DELETE_СОБЕСЕДОВАНИЕ;
/

--Процедуры для таблицы ВАКАНСИЯ:
CREATE OR REPLACE PROCEDURE INSERT_ВАКАНСИЯ (
    p_Должность VARCHAR2,
    p_Отдел VARCHAR2,
    p_Описание_Вакансии VARCHAR2,
    p_Заработная_Плата FLOAT,
    p_Статус_Вакансии VARCHAR2
) AS
BEGIN
    INSERT INTO ВАКАНСИИ (ДОЛЖНОСТЬ, ОТДЕЛ, ОПИСАНИЕ_ВАКАНСИИ, ЗАРАБОТНАЯ_ПЛАТА, СТАТУС_ВАКАНСИИ)
    VALUES (p_Должность, p_Отдел, p_Описание_Вакансии, p_Заработная_Плата, p_Статус_Вакансии);
END INSERT_ВАКАНСИЯ;
/

CREATE OR REPLACE PROCEDURE UPDATE_ВАКАНСИЯ (
    p_ИД_Вакансии NUMBER,
    p_Должность VARCHAR2,
    p_Отдел VARCHAR2,
    p_Описание_Вакансии VARCHAR2,
    p_Заработная_Плата FLOAT,
    p_Статус_Вакансии VARCHAR2
) AS
BEGIN
    UPDATE ВАКАНСИИ
    SET ДОЛЖНОСТЬ = p_Должность,
        ОТДЕЛ = p_Отдел,
        ОПИСАНИЕ_ВАКАНСИИ = p_Описание_Вакансии,
        ЗАРАБОТНАЯ_ПЛАТА = p_Заработная_Плата,
        СТАТУС_ВАКАНСИИ = p_Статус_Вакансии
    WHERE ИДЕНТИФИКАТОР_ВАКАНСИИ = p_ИД_Вакансии;
END UPDATE_ВАКАНСИЯ;
/

CREATE OR REPLACE PROCEDURE DELETE_ВАКАНСИЯ (
    p_ИД_Вакансии NUMBER
) AS
BEGIN
    DELETE FROM ВАКАНСИИ WHERE ИДЕНТИФИКАТОР_ВАКАНСИИ = p_ИД_Вакансии;
END DELETE_ВАКАНСИЯ;
/
