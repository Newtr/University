-- �������� ���������
CREATE OR REPLACE PROCEDURE ������������������������� (����� IN VARCHAR2) AS
BEGIN
    FOR rec IN (SELECT ���_���������� FROM ���������� WHERE ����� = �������������������������.�����) LOOP
        DBMS_OUTPUT.PUT_LINE(rec.���_����������);
    END LOOP;
END;
/

-- ����� ���������
EXEC �������������������������('����� ����������');

-- �������� �������
CREATE OR REPLACE FUNCTION �������������������������������(��������� IN VARCHAR2) RETURN NUMBER IS
    ���������� NUMBER;
BEGIN
    SELECT COUNT(*) INTO ����������
    FROM �������������
    WHERE ���������_�����������_������������� = �������������������������������.���������;
    
    RETURN ����������;
END;
/

-- ����� �������
SELECT �������������������������������('������ ���� ��������') AS ����������_������������� FROM dual;
