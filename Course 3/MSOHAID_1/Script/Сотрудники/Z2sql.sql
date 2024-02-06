-- �������� ���� ������ ��� "����������"
CREATE OR REPLACE TYPE t_��������� AS OBJECT (
    �������������_���������� NUMBER,
    ���_���������� VARCHAR2(100),
    �������� NUMBER,
    ���� VARCHAR2(100),
    ����_�������� DATE,
    ��� CHAR(255),
    ����� VARCHAR2(100),
    -- �������������� �����������
    CONSTRUCTOR FUNCTION t_���������(SELF IN OUT NOCOPY t_���������, ���_���������� VARCHAR2, ���� VARCHAR2, ����� VARCHAR2) RETURN SELF AS RESULT,
    -- ����� ��������� ���� MAP
    MAP MEMBER FUNCTION get_id RETURN NUMBER,
    -- ����� ���������� �������
    MEMBER FUNCTION get_full_info RETURN VARCHAR2,
    -- ����� ���������� ���������
    MEMBER PROCEDURE print_details (self IN OUT NOCOPY t_���������),
    --����������������� �������
    MEMBER FUNCTION get_role RETURN VARCHAR2 DETERMINISTIC
);
/

CREATE OR REPLACE TYPE BODY t_��������� AS
    -- ���������� ��������������� ������������
    CONSTRUCTOR FUNCTION t_���������(SELF IN OUT NOCOPY t_���������, ���_���������� VARCHAR2, ���� VARCHAR2, ����� VARCHAR2) RETURN SELF AS RESULT IS
    BEGIN
        SELF.���_���������� := ���_����������;
        SELF.���� := ����;
        SELF.����� := �����;
        RETURN;
    END;
    -- ���������� ������ ��������� ���� MAP
    MAP MEMBER FUNCTION get_id RETURN NUMBER IS
    BEGIN
        RETURN �������������_����������;
    END;
    -- ���������� ������ ���������� �������
    MEMBER FUNCTION get_full_info RETURN VARCHAR2 IS
    BEGIN
        RETURN ���_���������� || ' (' || ���� || ', ' || ����� || ')';
    END;
    -- ���������� ������ ���������� ���������
    MEMBER PROCEDURE print_details IS
    BEGIN
        DBMS_OUTPUT.PUT_LINE('���: ' || ���_����������);
        DBMS_OUTPUT.PUT_LINE('����: ' || ����);
        DBMS_OUTPUT.PUT_LINE('�����: ' || �����);
    END;
    --���������� ����������������� �������
    MEMBER FUNCTION get_role RETURN VARCHAR2 DETERMINISTIC IS
    BEGIN
        RETURN ����; -- �������� �� ���� ������
    END;
END;
/

-- �������� ���� ������ ��� "�������������"
CREATE OR REPLACE TYPE t_������������� AS OBJECT (
    �������������_������������� NUMBER,
    �������������_�������� NUMBER,
    ���_��������� VARCHAR2(100),
    ����_������������� DATE,
    ���������_������������� VARCHAR2(100),
    ���������_�����������_������������� VARCHAR2(100),
    -- �������������� �����������
    CONSTRUCTOR FUNCTION t_�������������(SELF IN OUT NOCOPY t_�������������, ���_��������� VARCHAR2, ����_������������� DATE, ���������_������������� VARCHAR2) RETURN SELF AS RESULT,
    -- ����� ��������� ���� MAP
    MAP MEMBER FUNCTION get_id RETURN NUMBER,
    -- ����� ���������� �������
    MEMBER FUNCTION get_full_info RETURN VARCHAR2,
    -- ����� ���������� ���������
    MEMBER PROCEDURE print_details (self IN OUT NOCOPY t_�������������)
);
/

CREATE OR REPLACE TYPE BODY t_������������� AS
    -- ���������� ��������������� ������������
    CONSTRUCTOR FUNCTION t_�������������(SELF IN OUT NOCOPY t_�������������, ���_��������� VARCHAR2, ����_������������� DATE, ���������_������������� VARCHAR2) RETURN SELF AS RESULT IS
    BEGIN
        SELF.���_��������� := ���_���������;
        SELF.����_������������� := ����_�������������;
        SELF.���������_������������� := ���������_�������������;
        RETURN;
    END;
    -- ���������� ������ ��������� ���� MAP
    MAP MEMBER FUNCTION get_id RETURN NUMBER IS
    BEGIN
        RETURN �������������_�������������;
    END;
    -- ���������� ������ ���������� �������
    MEMBER FUNCTION get_full_info RETURN VARCHAR2 IS
    BEGIN
        RETURN ���_��������� || ' (' || TO_CHAR(����_�������������, 'DD-MM-YYYY') || ', ' || ���������_������������� || ')';
    END;
    -- ���������� ������ ���������� ���������
    MEMBER PROCEDURE print_details IS
    BEGIN
        DBMS_OUTPUT.PUT_LINE('��� ���������: ' || ���_���������);
        DBMS_OUTPUT.PUT_LINE('���� �������������: ' || TO_CHAR(����_�������������, 'DD-MM-YYYY'));
        DBMS_OUTPUT.PUT_LINE('��������� �������������: ' || ���������_�������������);
    END;
END;
/

