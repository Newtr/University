CREATE OR REPLACE FUNCTION GetContractIdByEmployeeName (
    p_FullName VARCHAR2
) RETURN NUMBER IS
    v_ContractId NUMBER;
BEGIN
    SELECT Т.ИДЕНТИФИКАТОР_ДОГОВОРА
    INTO v_ContractId
    FROM ТРУДОВЫЕ_ДОГОВОРЫ Т
    JOIN СОТРУДНИКИ S ON т.идентификатор_договора = S.ИДЕНТИФИКАТОР_СОТРУДНИКА
    WHERE S.ФИО_СОТРУДНИКА = p_FullName;

    RETURN v_ContractId;
END GetContractIdByEmployeeName;
/
--ПРОВЕРКА
DECLARE
    v_Result NUMBER;
BEGIN
    v_Result := GetContractIdByEmployeeName('Павлова Лариса Ивановна'); --  ФИО сотрудника
    DBMS_OUTPUT.PUT_LINE('Идентификатор трудового договора: ' || v_Result);
END;
/


CREATE OR REPLACE FUNCTION GetTeamNameByProductId (
    p_ProductId NUMBER
) RETURN VARCHAR2 IS
    v_TeamName VARCHAR2(255);
BEGIN
    BEGIN
        SELECT К.НАЗВАНИЕ_КОМАНДЫ
        INTO v_TeamName
        FROM КОМАНДА_РАЗРАБОТЧИКОВ К
        JOIN РАЗРАБОТКА_ИГРОВОГО_ПРОДУКТА V ON К.ИДЕНТИФИКАТОР_ПРОДУКТА = V.ИДЕНТИФИКАТОР_ПРОДУКТА
        WHERE V.ИДЕНТИФИКАТОР_ПРОДУКТА = p_ProductId
        AND ROWNUM = 1; -- Получаем только одну запись
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            v_TeamName := NULL; -- или другое значение по умолчанию
    END;

    RETURN v_TeamName;
END GetTeamNameByProductId;
/

--ПРОВЕРКА
DECLARE
    v_TeamName VARCHAR2(255);
BEGIN
    v_TeamName := GetTeamNameByProductId(2); -- идентификатор продукта
    DBMS_OUTPUT.PUT_LINE('Название команды: ' || v_TeamName);
END;
/

CREATE OR REPLACE FUNCTION GetEmployeesByDepartment (
    p_DepartmentName VARCHAR2
) RETURN VARCHAR2 IS
    v_EmployeeList VARCHAR2(4000);
BEGIN
    BEGIN
        SELECT LISTAGG(S.ФИО_СОТРУДНИКА, ', ') WITHIN GROUP (ORDER BY S.ФИО_СОТРУДНИКА)
        INTO v_EmployeeList
        FROM СОТРУДНИКИ S
        WHERE S.ОТДЕЛ = p_DepartmentName;
        
        IF v_EmployeeList IS NULL THEN
            v_EmployeeList := 'Нет сотрудников в указанном отделе';
        END IF;
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            v_EmployeeList := 'Отдел не найден';
    END;

    RETURN v_EmployeeList;
END GetEmployeesByDepartment;
/

--ПРОВЕРКА
DECLARE
    v_EmployeeList VARCHAR2(4000);
BEGIN
    v_EmployeeList := GetEmployeesByDepartment('Отдел разработки'); -- Замените на фактическое название отдела
    DBMS_OUTPUT.PUT_LINE('Сотрудники в отделе: ' || v_EmployeeList);
END;
/