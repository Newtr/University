CREATE OR REPLACE FUNCTION ���������������Z5(����� IN VARCHAR2) RETURN NUMBER IS
    �������_�������� NUMBER;
BEGIN
    SELECT AVG(����������_�����) INTO �������_��������
    FROM ��������
    WHERE ����� = �����;
    
    RETURN �������_��������;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('������: ' || SQLERRM);
        RETURN NULL;
END;
/


CREATE OR REPLACE FUNCTION �����������������Z5(����_�������� IN DATE) RETURN NUMBER IS
    ������� NUMBER;
BEGIN
    ������� := TRUNC(MONTHS_BETWEEN(SYSDATE, ����_��������) / 12);
    RETURN �������;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('������: ' || SQLERRM);
        RETURN NULL;
END;
/

SELECT ���������������Z5('����� ����������') FROM dual;
SELECT �����������������Z5(TO_DATE('1990-01-01', 'YYYY-MM-DD')) FROM dual;

