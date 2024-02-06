-- ��������� ��� ���������� DML-��������
CREATE OR REPLACE PROCEDURE ������������������Z3(
    p_�������������_���������� IN ����������.�������������_����������%TYPE,
    p_���_���������� IN ����������.���_����������%TYPE,
    p_�������� IN ����������.��������%TYPE,
    p_���� IN ����������.����%TYPE,
    p_����_�������� IN ����������.����_��������%TYPE,
    p_��� IN ����������.���%TYPE,
    p_����� IN ����������.�����%TYPE
) AS
BEGIN
    INSERT INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����)
    VALUES (p_�������������_����������, p_���_����������, p_��������, p_����, p_����_��������, p_���, p_�����);
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('������: ' || SQLERRM);
END;
/

-- ��������� ��� ��������� ��������������� ������
CREATE OR REPLACE PROCEDURE �������������������������Z3(p_����� IN ����������.�����%TYPE) AS
    CURSOR cur IS
        SELECT ���_����������
        FROM ����������
        WHERE ����� = p_�����;
    rec cur%ROWTYPE;
BEGIN
    OPEN cur;
    LOOP
        FETCH cur INTO rec;
        EXIT WHEN cur%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE(rec.���_����������);
    END LOOP;
    CLOSE cur;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('������: ' || SQLERRM);
END;
/

-- ����� ��������� ������������������Z3
DECLARE
    p_�������������_���������� NUMBER;
    p_���_���������� VARCHAR2(100);
    p_�������� NUMBER;
    p_���� VARCHAR2(100);
    p_����_�������� DATE;
    p_��� VARCHAR2(100);
    p_����� VARCHAR2(100);
BEGIN
    p_�������������_���������� := 37; -- �������� �� ��������������� ��������
    p_���_���������� := 'Z3 Z3 Z3'; -- �������� �� ��������������� ��������
    p_�������� := 1; -- �������� �� ��������������� ��������
    p_���� := '�����������'; -- �������� �� ��������������� ��������
    p_����_�������� := TO_DATE('1990-01-01', 'YYYY-MM-DD'); -- �������� �� ��������������� ��������
    p_��� := '�������'; -- �������� �� ��������������� ��������
    p_����� := '����� ����������'; -- �������� �� ��������������� ��������
    ������������������Z3(p_�������������_����������, p_���_����������, p_��������, p_����, p_����_��������, p_���, p_�����);
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('������: ' || SQLERRM);
END;
/

-- ����� ��������� �������������������������
DECLARE
    p_����� VARCHAR2(100);
BEGIN
    p_����� := '����� ����������'; -- �������� �� ��������������� ��������
    �������������������������Z3(p_�����);
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('������: ' || SQLERRM);
END;
/
