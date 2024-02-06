--�������������� ��������� � ����� ���������
-- ������� ����� ��� ��� ��������� K3
CREATE TYPE t3_type AS OBJECT (
    �������������_���������� NUMBER,
    ���_���������� VARCHAR2(100),
    �������� NUMBER
);
CREATE TYPE t1_type AS OBJECT (
    �������������_���������� NUMBER,
    ���_���������� VARCHAR2(100),
    �������� NUMBER
);

DECLARE 
    -- ��������� K1 �� ������ ���� t1_type
    TYPE k1_collection IS TABLE OF t1_type;
    k1_col k1_collection;
   
    -- ��������� K3 �� ������ ������ ����
    TYPE k3_collection IS TABLE OF t3_type;
    k3_col k3_collection;
BEGIN
    -- ��������� ��������� K1 ������� �� ������� ����������_obj
    SELECT t1_type(�������������_����������, ���_����������, ��������)
    BULK COLLECT INTO k1_col
    FROM ����������_obj;

    -- �������������� ��������� K3
    k3_col := k3_collection();

    -- ��������� ��������� K3 ������� �� K1
    FOR i IN 1..k1_col.COUNT LOOP
        k3_col.EXTEND; -- ����������� ������ ���������
        k3_col(i) := t3_type(
            k1_col(i).�������������_����������,
            k1_col(i).���_����������,
            k1_col(i).��������
        );

        -- ������� ������ �� ��������� K3
        DBMS_OUTPUT.PUT_LINE('K3 ������� ' || i || ':');
        DBMS_OUTPUT.PUT_LINE('�������������_����������: ' || k3_col(i).�������������_����������);
        DBMS_OUTPUT.PUT_LINE('���_����������: ' || k3_col(i).���_����������);
        DBMS_OUTPUT.PUT_LINE('��������: ' || k3_col(i).��������);
        DBMS_OUTPUT.PUT_LINE('------------------------');
    END LOOP;
END;
/


--�������������� ��������� � ����������� ������
-- 1) ������� ��������� ������� ��� �������� ������ �� ������� �������������_obj
CREATE GLOBAL TEMPORARY TABLE temp_table (
    �������������_������������� NUMBER,
    �������������_�������� NUMBER,
    ���_��������� VARCHAR2(255),
    ����_������������� DATE,
    ���������_������������� VARCHAR2(255),
    ���������_�����������_������������� VARCHAR2(255)
) ON COMMIT PRESERVE ROWS;

    -- 1) ����������� ���� ��� ���������
    CREATE TYPE t2_type AS OBJECT (
        �������������_������������� NUMBER,
        �������������_�������� NUMBER,
        ���_��������� VARCHAR2(255),
        ����_������������� DATE,
        ���������_������������� VARCHAR2(255),
        ���������_�����������_������������� VARCHAR2(255)
    );
    
DECLARE

    -- 2) ���������� ���������� ���������
    TYPE interview_collection IS TABLE OF t2_type INDEX BY PLS_INTEGER;

    -- 3) ���������� ���������� ���������
    interview_data interview_collection;

BEGIN
    -- 4) ���������� ��������� ������� �� ������� �������������_obj
    SELECT t2_type(
            �������������_�������������,
            �������������_��������,
            ���_���������,
            ����_�������������,
            ���������_�������������,
            ���������_�����������_�������������
        )
    BULK COLLECT INTO interview_data
    FROM �������������_obj;

    -- 5) ������� ������ �� ��������� � �������
    FOR i IN 1..interview_data.COUNT LOOP
        INSERT INTO temp_table VALUES (
            interview_data(i).�������������_�������������,
            interview_data(i).�������������_��������,
            interview_data(i).���_���������,
            interview_data(i).����_�������������,
            interview_data(i).���������_�������������,
            interview_data(i).���������_�����������_�������������
        );
    END LOOP;

    -- 6) ���������� SELECT, ������� ���������� ��� ������ �� ��������� �������
    FOR temp_rec IN (SELECT * FROM temp_table) LOOP
        DBMS_OUTPUT.PUT_LINE('�������������_�������������: ' || temp_rec.�������������_�������������);
        DBMS_OUTPUT.PUT_LINE('�������������_��������: ' || temp_rec.�������������_��������);
        DBMS_OUTPUT.PUT_LINE('���_���������: ' || temp_rec.���_���������);
        DBMS_OUTPUT.PUT_LINE('����_�������������: ' || TO_CHAR(temp_rec.����_�������������, 'DD-MON-YYYY HH24:MI:SS'));
        DBMS_OUTPUT.PUT_LINE('���������_�������������: ' || temp_rec.���������_�������������);
        DBMS_OUTPUT.PUT_LINE('���������_�����������_�������������: ' || temp_rec.���������_�����������_�������������);
        DBMS_OUTPUT.PUT_LINE('------------------------');
    END LOOP;

    -- 7) �������� ��������� ������� ����� �������������
    EXECUTE IMMEDIATE 'TRUNCATE TABLE temp_table';

END;
/


--�������� BULK COLLECT INTO ������������ ��� ������������ �������� ������ �� ���������� ������� SQL � ��������� � ������ ����� ��������. 
--��� �������� �������, ����� �� ������ ���� � ������� ������� ������, ��� ��� ��� ��������� ��������� ���������� ��������� 
--����� ����� ������ � ������ ���������� PL/SQL, 
--��� � ���� ������� ����� �������� ������������������ ������ ����.