CREATE OR REPLACE FUNCTION СредняяЗарплатаZ5(Отдел IN VARCHAR2) RETURN NUMBER IS
    Средняя_Зарплата NUMBER;
BEGIN
    SELECT AVG(ЗАРАБОТНАЯ_ПЛАТА) INTO Средняя_Зарплата
    FROM Вакансии
    WHERE ОТДЕЛ = Отдел;
    
    RETURN Средняя_Зарплата;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Ошибка: ' || SQLERRM);
        RETURN NULL;
END;
/


CREATE OR REPLACE FUNCTION ВозрастСотрудникаZ5(Дата_рождения IN DATE) RETURN NUMBER IS
    Возраст NUMBER;
BEGIN
    Возраст := TRUNC(MONTHS_BETWEEN(SYSDATE, Дата_рождения) / 12);
    RETURN Возраст;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Ошибка: ' || SQLERRM);
        RETURN NULL;
END;
/

SELECT СредняяЗарплатаZ5('Отдел разработки') FROM dual;
SELECT ВозрастСотрудникаZ5(TO_DATE('1990-01-01', 'YYYY-MM-DD')) FROM dual;

