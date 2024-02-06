CREATE OR REPLACE PACKAGE ПакетZ8 AS
    -- Объявление функции
    FUNCTION СредняяЗарплатаZ5(Отдел IN VARCHAR2) RETURN NUMBER;
    FUNCTION ВозрастСотрудникаZ5(Дата_рождения IN DATE) RETURN NUMBER;
    
    -- Объявление процедуры
    PROCEDURE ДобавитьСотрудникаZ5(
        p_ИДЕНТИФИКАТОР_СОТРУДНИКА IN Сотрудники.ИДЕНТИФИКАТОР_СОТРУДНИКА%TYPE,
        p_ФИО_СОТРУДНИКА IN Сотрудники.ФИО_СОТРУДНИКА%TYPE,
        p_КОНТРАКТ IN Сотрудники.КОНТРАКТ%TYPE,
        p_РОЛЬ IN Сотрудники.РОЛЬ%TYPE,
        p_ДАТА_РОЖДЕНИЯ IN Сотрудники.ДАТА_РОЖДЕНИЯ%TYPE,
        p_ПОЛ IN Сотрудники.ПОЛ%TYPE,
        p_ОТДЕЛ IN Сотрудники.ОТДЕЛ%TYPE
    );
    PROCEDURE ПолучитьСотрудниковОтделаZ5(p_ОТДЕЛ IN Сотрудники.ОТДЕЛ%TYPE);
END ПакетZ8;
/

CREATE OR REPLACE PACKAGE BODY ПакетZ8 AS
    -- Реализация функций
    FUNCTION СредняяЗарплатаZ5(Отдел IN VARCHAR2) RETURN NUMBER IS
        Средняя_Зарплата NUMBER;
    BEGIN
        SELECT AVG(ЗАРАБОТНАЯ_ПЛАТА) INTO Средняя_Зарплата
        FROM Вакансии
        WHERE ОТДЕЛ = Отдел;
        
        RETURN Средняя_Зарплата;
    END СредняяЗарплатаZ5;
    
    FUNCTION ВозрастСотрудникаZ5(Дата_рождения IN DATE) RETURN NUMBER IS
        Возраст NUMBER;
    BEGIN
        Возраст := TRUNC(MONTHS_BETWEEN(SYSDATE, Дата_рождения) / 12);
        RETURN Возраст;
    END ВозрастСотрудникаZ5;
    
    -- Реализация процедур
    PROCEDURE ДобавитьСотрудникаZ5(
        p_ИДЕНТИФИКАТОР_СОТРУДНИКА IN Сотрудники.ИДЕНТИФИКАТОР_СОТРУДНИКА%TYPE,
        p_ФИО_СОТРУДНИКА IN Сотрудники.ФИО_СОТРУДНИКА%TYPE,
        p_КОНТРАКТ IN Сотрудники.КОНТРАКТ%TYPE,
        p_РОЛЬ IN Сотрудники.РОЛЬ%TYPE,
        p_ДАТА_РОЖДЕНИЯ IN Сотрудники.ДАТА_РОЖДЕНИЯ%TYPE,
        p_ПОЛ IN Сотрудники.ПОЛ%TYPE,
        p_ОТДЕЛ IN Сотрудники.ОТДЕЛ%TYPE
    ) IS
    BEGIN
        INSERT INTO Сотрудники (ИДЕНТИФИКАТОР_СОТРУДНИКА, ФИО_СОТРУДНИКА, КОНТРАКТ, РОЛЬ, ДАТА_РОЖДЕНИЯ, ПОЛ, ОТДЕЛ)
        VALUES (p_ИДЕНТИФИКАТОР_СОТРУДНИКА, p_ФИО_СОТРУДНИКА, p_КОНТРАКТ, p_РОЛЬ, p_ДАТА_РОЖДЕНИЯ, p_ПОЛ, p_ОТДЕЛ);
    EXCEPTION
        WHEN OTHERS THEN
            DBMS_OUTPUT.PUT_LINE('Ошибка: ' || SQLERRM);
    END ДобавитьСотрудникаZ5;
    
    PROCEDURE ПолучитьСотрудниковОтделаZ5(p_ОТДЕЛ IN Сотрудники.ОТДЕЛ%TYPE) IS
        CURSOR cur IS
            SELECT ФИО_СОТРУДНИКА
            FROM Сотрудники
            WHERE ОТДЕЛ = p_ОТДЕЛ;
        rec cur%ROWTYPE;
    BEGIN
        OPEN cur;
        LOOP
            FETCH cur INTO rec;
            EXIT WHEN cur%NOTFOUND;
            DBMS_OUTPUT.PUT_LINE(rec.ФИО_СОТРУДНИКА);
        END LOOP;
        CLOSE cur;
    EXCEPTION
        WHEN OTHERS THEN
            DBMS_OUTPUT.PUT_LINE('Ошибка: ' || SQLERRM);
    END ПолучитьСотрудниковОтделаZ5;
END ПакетZ8;
/
