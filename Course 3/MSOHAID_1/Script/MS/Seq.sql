USE MSOHAID;
EXECUTE AS USER = 'Kaisa';
SELECT CURRENT_USER AS CurrentUser;

-- Создание последовательности для ТРУДОВЫЕ ДОГОВОРЫ
CREATE SEQUENCE SEQ_ТД
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- Создание последовательности для СОТРУДНИКИ
CREATE SEQUENCE SEQ_СОТРУДНИК
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- Создание последовательности для КОМАНДА РАЗРАБОТЧИКОВ
CREATE SEQUENCE SEQ_КОМАНДА
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- Создание последовательности для РОЛИ
CREATE SEQUENCE SEQ_РОЛЬ
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- Создание последовательности для ОТДЕЛЫ
CREATE SEQUENCE SEQ_ОТДЕЛ
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- Создание последовательности для СОБЕСЕДОВАНИЯ
CREATE SEQUENCE SEQ_СОБЕСЕДОВАНИЕ
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- Создание последовательности для ВАКАНСИИ
CREATE SEQUENCE SEQ_ВАКАНСИЯ
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- Вывести все последовательности, созданные пользователем Kaisa
SELECT 
    schema_name(seq.schema_id) AS [SchemaName],
    seq.name AS [SequenceName]
FROM sys.sequences AS seq
JOIN sys.database_principals AS princ ON seq.principal_id = princ.principal_id
WHERE princ.name = 'Kaisa';