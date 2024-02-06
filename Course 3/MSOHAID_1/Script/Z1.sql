-- Создание процедуры
CREATE OR REPLACE PROCEDURE ПолучитьСотрудниковОтдела (Отдел IN VARCHAR2) AS
BEGIN
    FOR rec IN (SELECT ФИО_Сотрудника FROM Сотрудники WHERE Отдел = ПолучитьСотрудниковОтдела.Отдел) LOOP
        DBMS_OUTPUT.PUT_LINE(rec.ФИО_Сотрудника);
    END LOOP;
END;
/

-- Вызов процедуры
EXEC ПолучитьСотрудниковОтдела('Отдел разработки');

-- Создание функции
CREATE OR REPLACE FUNCTION ПолучитьКоличествоСобеседований(Сотрудник IN VARCHAR2) RETURN NUMBER IS
    Количество NUMBER;
BEGIN
    SELECT COUNT(*) INTO Количество
    FROM Собеседования
    WHERE Сотрудник_принимавший_собеседование = ПолучитьКоличествоСобеседований.Сотрудник;
    
    RETURN Количество;
END;
/

-- Вызов функции
SELECT ПолучитьКоличествоСобеседований('Иванов Иван Иванович') AS Количество_собеседований FROM dual;
