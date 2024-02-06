-- Создание типа данных для "Сотрудники"
CREATE OR REPLACE TYPE t_Сотрудник AS OBJECT (
    ИДЕНТИФИКАТОР_СОТРУДНИКА NUMBER,
    ФИО_СОТРУДНИКА VARCHAR2(100),
    КОНТРАКТ NUMBER,
    РОЛЬ VARCHAR2(100),
    ДАТА_РОЖДЕНИЯ DATE,
    ПОЛ CHAR(255),
    ОТДЕЛ VARCHAR2(100),
    -- Дополнительный конструктор
    CONSTRUCTOR FUNCTION t_Сотрудник(SELF IN OUT NOCOPY t_Сотрудник, ФИО_СОТРУДНИКА VARCHAR2, РОЛЬ VARCHAR2, ОТДЕЛ VARCHAR2) RETURN SELF AS RESULT,
    -- Метод сравнения типа MAP
    MAP MEMBER FUNCTION get_id RETURN NUMBER,
    -- Метод экземпляра функцию
    MEMBER FUNCTION get_full_info RETURN VARCHAR2,
    -- Метод экземпляра процедуру
    MEMBER PROCEDURE print_details (self IN OUT NOCOPY t_Сотрудник),
    --Детерминированная функция
    MEMBER FUNCTION get_role RETURN VARCHAR2 DETERMINISTIC
);
/

CREATE OR REPLACE TYPE BODY t_Сотрудник AS
    -- Реализация дополнительного конструктора
    CONSTRUCTOR FUNCTION t_Сотрудник(SELF IN OUT NOCOPY t_Сотрудник, ФИО_СОТРУДНИКА VARCHAR2, РОЛЬ VARCHAR2, ОТДЕЛ VARCHAR2) RETURN SELF AS RESULT IS
    BEGIN
        SELF.ФИО_СОТРУДНИКА := ФИО_СОТРУДНИКА;
        SELF.РОЛЬ := РОЛЬ;
        SELF.ОТДЕЛ := ОТДЕЛ;
        RETURN;
    END;
    -- Реализация метода сравнения типа MAP
    MAP MEMBER FUNCTION get_id RETURN NUMBER IS
    BEGIN
        RETURN ИДЕНТИФИКАТОР_СОТРУДНИКА;
    END;
    -- Реализация метода экземпляра функцию
    MEMBER FUNCTION get_full_info RETURN VARCHAR2 IS
    BEGIN
        RETURN ФИО_СОТРУДНИКА || ' (' || РОЛЬ || ', ' || ОТДЕЛ || ')';
    END;
    -- Реализация метода экземпляра процедуру
    MEMBER PROCEDURE print_details IS
    BEGIN
        DBMS_OUTPUT.PUT_LINE('ФИО: ' || ФИО_СОТРУДНИКА);
        DBMS_OUTPUT.PUT_LINE('Роль: ' || РОЛЬ);
        DBMS_OUTPUT.PUT_LINE('Отдел: ' || ОТДЕЛ);
    END;
    --Реализация детерминированной функции
    MEMBER FUNCTION get_role RETURN VARCHAR2 DETERMINISTIC IS
    BEGIN
        RETURN Роль; -- Замените на вашу логику
    END;
END;
/

-- Создание типа данных для "Собеседования"
CREATE OR REPLACE TYPE t_Собеседование AS OBJECT (
    ИДЕНТИФИКАТОР_СОБЕСЕДОВАНИЯ NUMBER,
    ИДЕНТИФИКАТОР_ВАКАНСИИ NUMBER,
    ИМЯ_КАНДИДАТА VARCHAR2(100),
    ДАТА_СОБЕСЕДОВАНИЯ DATE,
    РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ VARCHAR2(100),
    СОТРУДНИК_ПРИНИМАВШИЙ_СОБЕСЕДОВАНИЕ VARCHAR2(100),
    -- Дополнительный конструктор
    CONSTRUCTOR FUNCTION t_Собеседование(SELF IN OUT NOCOPY t_Собеседование, ИМЯ_КАНДИДАТА VARCHAR2, ДАТА_СОБЕСЕДОВАНИЯ DATE, РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ VARCHAR2) RETURN SELF AS RESULT,
    -- Метод сравнения типа MAP
    MAP MEMBER FUNCTION get_id RETURN NUMBER,
    -- Метод экземпляра функцию
    MEMBER FUNCTION get_full_info RETURN VARCHAR2,
    -- Метод экземпляра процедуру
    MEMBER PROCEDURE print_details (self IN OUT NOCOPY t_Собеседование)
);
/

CREATE OR REPLACE TYPE BODY t_Собеседование AS
    -- Реализация дополнительного конструктора
    CONSTRUCTOR FUNCTION t_Собеседование(SELF IN OUT NOCOPY t_Собеседование, ИМЯ_КАНДИДАТА VARCHAR2, ДАТА_СОБЕСЕДОВАНИЯ DATE, РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ VARCHAR2) RETURN SELF AS RESULT IS
    BEGIN
        SELF.ИМЯ_КАНДИДАТА := ИМЯ_КАНДИДАТА;
        SELF.ДАТА_СОБЕСЕДОВАНИЯ := ДАТА_СОБЕСЕДОВАНИЯ;
        SELF.РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ := РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ;
        RETURN;
    END;
    -- Реализация метода сравнения типа MAP
    MAP MEMBER FUNCTION get_id RETURN NUMBER IS
    BEGIN
        RETURN ИДЕНТИФИКАТОР_СОБЕСЕДОВАНИЯ;
    END;
    -- Реализация метода экземпляра функцию
    MEMBER FUNCTION get_full_info RETURN VARCHAR2 IS
    BEGIN
        RETURN ИМЯ_КАНДИДАТА || ' (' || TO_CHAR(ДАТА_СОБЕСЕДОВАНИЯ, 'DD-MM-YYYY') || ', ' || РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ || ')';
    END;
    -- Реализация метода экземпляра процедуру
    MEMBER PROCEDURE print_details IS
    BEGIN
        DBMS_OUTPUT.PUT_LINE('Имя кандидата: ' || ИМЯ_КАНДИДАТА);
        DBMS_OUTPUT.PUT_LINE('Дата собеседования: ' || TO_CHAR(ДАТА_СОБЕСЕДОВАНИЯ, 'DD-MM-YYYY'));
        DBMS_OUTPUT.PUT_LINE('Результат собеседования: ' || РЕЗУЛЬТАТ_СОБЕСЕДОВАНИЯ);
    END;
END;
/

