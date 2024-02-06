CREATE OR REPLACE PACKAGE �����Z8 AS
    -- ���������� �������
    FUNCTION ���������������Z5(����� IN VARCHAR2) RETURN NUMBER;
    FUNCTION �����������������Z5(����_�������� IN DATE) RETURN NUMBER;
    
    -- ���������� ���������
    PROCEDURE ������������������Z5(
        p_�������������_���������� IN ����������.�������������_����������%TYPE,
        p_���_���������� IN ����������.���_����������%TYPE,
        p_�������� IN ����������.��������%TYPE,
        p_���� IN ����������.����%TYPE,
        p_����_�������� IN ����������.����_��������%TYPE,
        p_��� IN ����������.���%TYPE,
        p_����� IN ����������.�����%TYPE
    );
    PROCEDURE �������������������������Z5(p_����� IN ����������.�����%TYPE);
END �����Z8;
/

CREATE OR REPLACE PACKAGE BODY �����Z8 AS
    -- ���������� �������
    FUNCTION ���������������Z5(����� IN VARCHAR2) RETURN NUMBER IS
        �������_�������� NUMBER;
    BEGIN
        SELECT AVG(����������_�����) INTO �������_��������
        FROM ��������
        WHERE ����� = �����;
        
        RETURN �������_��������;
    END ���������������Z5;
    
    FUNCTION �����������������Z5(����_�������� IN DATE) RETURN NUMBER IS
        ������� NUMBER;
    BEGIN
        ������� := TRUNC(MONTHS_BETWEEN(SYSDATE, ����_��������) / 12);
        RETURN �������;
    END �����������������Z5;
    
    -- ���������� ��������
    PROCEDURE ������������������Z5(
        p_�������������_���������� IN ����������.�������������_����������%TYPE,
        p_���_���������� IN ����������.���_����������%TYPE,
        p_�������� IN ����������.��������%TYPE,
        p_���� IN ����������.����%TYPE,
        p_����_�������� IN ����������.����_��������%TYPE,
        p_��� IN ����������.���%TYPE,
        p_����� IN ����������.�����%TYPE
    ) IS
    BEGIN
        INSERT INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����)
        VALUES (p_�������������_����������, p_���_����������, p_��������, p_����, p_����_��������, p_���, p_�����);
    EXCEPTION
        WHEN OTHERS THEN
            DBMS_OUTPUT.PUT_LINE('������: ' || SQLERRM);
    END ������������������Z5;
    
    PROCEDURE �������������������������Z5(p_����� IN ����������.�����%TYPE) IS
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
    END �������������������������Z5;
END �����Z8;
/
