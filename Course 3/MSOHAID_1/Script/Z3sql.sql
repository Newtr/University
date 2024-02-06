--Преобразование коллекции в новую коллекцию
-- Создаем новый тип для коллекции K3
CREATE TYPE t3_type AS OBJECT (
    ИДЕНТИФИКАТОР_СОТРУДНИКА NUMBER,
    ФИО_СОТРУДНИКА VARCHAR2(100),
    КОНТРАКТ NUMBER
);
CREATE TYPE t1_type AS OBJECT (
    ИДЕНТИФИКАТОР_СОТРУДНИКА NUMBER,
    ФИО_СОТРУДНИКА VARCHAR2(100),
    КОНТРАКТ NUMBER
);

DECLARE 
    -- Коллекция K1 на основе типа t1_type
    TYPE k1_collection IS TABLE OF t1_type;
    k1_col k1_collection;
   
    -- Коллекция K3 на основе нового типа
    TYPE k3_collection IS TABLE OF t3_type;
    k3_col k3_collection;
BEGIN
    -- Заполняем коллекцию K1 данными из таблицы Сотрудники_obj
    SELECT t1_type(ИДЕНТИФИКАТОР_СОТРУДНИКА, ФИО_СОТРУДНИКА, КОНТРАКТ)
    BULK COLLECT INTO k1_col
    FROM Сотрудники_obj;

    -- Инициализируем коллекцию K3
    k3_col := k3_collection();

    -- Заполняем коллекцию K3 данными из K1
    FOR i IN 1..k1_col.COUNT LOOP
        k3_col.EXTEND; -- Увеличиваем размер коллекции
        k3_col(i) := t3_type(
            k1_col(i).ИДЕНТИФИКАТОР_СОТРУДНИКА,
            k1_col(i).ФИО_СОТРУДНИКА,
            k1_col(i).КОНТРАКТ
        );

        -- Выводим данные из коллекции K3
        DBMS_OUTPUT.PUT_LINE('K3 элемент ' || i || ':');
        DBMS_OUTPUT.PUT_LINE('ИДЕНТИФИКАТОР_СОТРУДНИКА: ' || k3_col(i).ИДЕНТИФИКАТОР_СОТРУДНИКА);
        DBMS_OUTPUT.PUT_LINE('ФИО_СОТРУДНИКА: ' || k3_col(i).ФИО_СОТРУДНИКА);
        DBMS_OUTPUT.PUT_LINE('КОНТРАКТ: ' || k3_col(i).КОНТРАКТ);
        DBMS_OUTPUT.PUT_LINE('------------------------');
    END LOOP;
END;
/


--Преобразование коллекции в реляционные данные
-- 1) Создаем временную таблицу для хранения данных из таблицы Собеседования_obj
CREATE GLOBAL TEMPORARY TABLE temp_table (
    ИДЕНТИФИКАТОР_СОБЕСЕДОВАНИЯ NUMBER,
    ИДЕНТИФИКАТОР_ВАКАНСИИ NUMBER,
    ИМЯ_КАНДИДАТА VARCHAR2(255),
    ДАТА_СОБЕСЕДОВАНИЯ DATE,
    РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ VARCHAR2(255),
    СОТРУДНИК_ПРИНИМАВШИЙ_СОБЕСЕДОВАНИЕ VARCHAR2(255)
) ON COMMIT PRESERVE ROWS;

    -- 1) Определение типа для коллекции
    CREATE TYPE t2_type AS OBJECT (
        ИДЕНТИФИКАТОР_СОБЕСЕДОВАНИЯ NUMBER,
        ИДЕНТИФИКАТОР_ВАКАНСИИ NUMBER,
        ИМЯ_КАНДИДАТА VARCHAR2(255),
        ДАТА_СОБЕСЕДОВАНИЯ DATE,
        РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ VARCHAR2(255),
        СОТРУДНИК_ПРИНИМАВШИЙ_СОБЕСЕДОВАНИЕ VARCHAR2(255)
    );
    
DECLARE

    -- 2) Объявление переменной коллекции
    TYPE interview_collection IS TABLE OF t2_type INDEX BY PLS_INTEGER;

    -- 3) Объявление переменной коллекции
    interview_data interview_collection;

BEGIN
    -- 4) Заполнение коллекции данными из таблицы Собеседования_obj
    SELECT t2_type(
            ИДЕНТИФИКАТОР_СОБЕСЕДОВАНИЯ,
            ИДЕНТИФИКАТОР_ВАКАНСИИ,
            ИМЯ_КАНДИДАТА,
            ДАТА_СОБЕСЕДОВАНИЯ,
            РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ,
            СОТРУДНИК_ПРИНИМАВШИЙ_СОБЕСЕДОВАНИЕ
        )
    BULK COLLECT INTO interview_data
    FROM Собеседования_obj;

    -- 5) Перенос данных из коллекции в таблицу
    FOR i IN 1..interview_data.COUNT LOOP
        INSERT INTO temp_table VALUES (
            interview_data(i).ИДЕНТИФИКАТОР_СОБЕСЕДОВАНИЯ,
            interview_data(i).ИДЕНТИФИКАТОР_ВАКАНСИИ,
            interview_data(i).ИМЯ_КАНДИДАТА,
            interview_data(i).ДАТА_СОБЕСЕДОВАНИЯ,
            interview_data(i).РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ,
            interview_data(i).СОТРУДНИК_ПРИНИМАВШИЙ_СОБЕСЕДОВАНИЕ
        );
    END LOOP;

    -- 6) Выполнение SELECT, который возвращает все данные из временной таблицы
    FOR temp_rec IN (SELECT * FROM temp_table) LOOP
        DBMS_OUTPUT.PUT_LINE('ИДЕНТИФИКАТОР_СОБЕСЕДОВАНИЯ: ' || temp_rec.ИДЕНТИФИКАТОР_СОБЕСЕДОВАНИЯ);
        DBMS_OUTPUT.PUT_LINE('ИДЕНТИФИКАТОР_ВАКАНСИИ: ' || temp_rec.ИДЕНТИФИКАТОР_ВАКАНСИИ);
        DBMS_OUTPUT.PUT_LINE('ИМЯ_КАНДИДАТА: ' || temp_rec.ИМЯ_КАНДИДАТА);
        DBMS_OUTPUT.PUT_LINE('ДАТА_СОБЕСЕДОВАНИЯ: ' || TO_CHAR(temp_rec.ДАТА_СОБЕСЕДОВАНИЯ, 'DD-MON-YYYY HH24:MI:SS'));
        DBMS_OUTPUT.PUT_LINE('РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ: ' || temp_rec.РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ);
        DBMS_OUTPUT.PUT_LINE('СОТРУДНИК_ПРИНИМАВШИЙ_СОБЕСЕДОВАНИЕ: ' || temp_rec.СОТРУДНИК_ПРИНИМАВШИЙ_СОБЕСЕДОВАНИЕ);
        DBMS_OUTPUT.PUT_LINE('------------------------');
    END LOOP;

    -- 7) Удаление временной таблицы после использования
    EXECUTE IMMEDIATE 'TRUNCATE TABLE temp_table';

END;
/


--Оператор BULK COLLECT INTO используется для эффективного передачи данных из результата запроса SQL в коллекцию в рамках одной операции. 
--Это особенно полезно, когда вы имеете дело с большим объемом данных, так как это позволяет уменьшить количество обращений 
--между базой данных и средой выполнения PL/SQL, 
--что в свою очередь может повысить производительность вашего кода.