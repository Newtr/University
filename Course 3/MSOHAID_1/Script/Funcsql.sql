CREATE OR REPLACE FUNCTION GetContractIdByEmployeeName (
    p_FullName VARCHAR2
) RETURN NUMBER IS
    v_ContractId NUMBER;
BEGIN
    SELECT �.�������������_��������
    INTO v_ContractId
    FROM ��������_�������� �
    JOIN ���������� S ON �.�������������_�������� = S.�������������_����������
    WHERE S.���_���������� = p_FullName;

    RETURN v_ContractId;
END GetContractIdByEmployeeName;
/
--��������
DECLARE
    v_Result NUMBER;
BEGIN
    v_Result := GetContractIdByEmployeeName('������� ������ ��������'); --  ��� ����������
    DBMS_OUTPUT.PUT_LINE('������������� ��������� ��������: ' || v_Result);
END;
/


CREATE OR REPLACE FUNCTION GetTeamNameByProductId (
    p_ProductId NUMBER
) RETURN VARCHAR2 IS
    v_TeamName VARCHAR2(255);
BEGIN
    BEGIN
        SELECT �.��������_�������
        INTO v_TeamName
        FROM �������_������������� �
        JOIN ����������_��������_�������� V ON �.�������������_�������� = V.�������������_��������
        WHERE V.�������������_�������� = p_ProductId
        AND ROWNUM = 1; -- �������� ������ ���� ������
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            v_TeamName := NULL; -- ��� ������ �������� �� ���������
    END;

    RETURN v_TeamName;
END GetTeamNameByProductId;
/

--��������
DECLARE
    v_TeamName VARCHAR2(255);
BEGIN
    v_TeamName := GetTeamNameByProductId(2); -- ������������� ��������
    DBMS_OUTPUT.PUT_LINE('�������� �������: ' || v_TeamName);
END;
/

CREATE OR REPLACE FUNCTION GetEmployeesByDepartment (
    p_DepartmentName VARCHAR2
) RETURN VARCHAR2 IS
    v_EmployeeList VARCHAR2(4000);
BEGIN
    BEGIN
        SELECT LISTAGG(S.���_����������, ', ') WITHIN GROUP (ORDER BY S.���_����������)
        INTO v_EmployeeList
        FROM ���������� S
        WHERE S.����� = p_DepartmentName;
        
        IF v_EmployeeList IS NULL THEN
            v_EmployeeList := '��� ����������� � ��������� ������';
        END IF;
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            v_EmployeeList := '����� �� ������';
    END;

    RETURN v_EmployeeList;
END GetEmployeesByDepartment;
/

--��������
DECLARE
    v_EmployeeList VARCHAR2(4000);
BEGIN
    v_EmployeeList := GetEmployeesByDepartment('����� ����������'); -- �������� �� ����������� �������� ������
    DBMS_OUTPUT.PUT_LINE('���������� � ������: ' || v_EmployeeList);
END;
/