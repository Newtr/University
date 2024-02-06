--��������� ��� ������� �������� ��������:
CREATE OR REPLACE PROCEDURE INSERT_������� (
    p_����_������ DATE,
    p_����_��������� DATE,
    p_���_�������� VARCHAR2
) AS
BEGIN
    INSERT INTO ��������_�������� (����_������_��������_��������, ����_���������_��������_��������, ���_��������)
    VALUES (p_����_������, p_����_���������, p_���_��������);
END INSERT_�������;
/

CREATE OR REPLACE PROCEDURE UPDATE_������� (
    p_��_�������� NUMBER,
    p_����_������ DATE,
    p_����_��������� DATE,
    p_���_�������� VARCHAR2
) AS
BEGIN
    UPDATE ��������_��������
    SET ����_������_��������_�������� = p_����_������,
        ����_���������_��������_�������� = p_����_���������,
        ���_�������� = p_���_��������
    WHERE �������������_�������� = p_��_��������;
END UPDATE_�������;
/

CREATE OR REPLACE PROCEDURE DELETE_������� (
    p_��_�������� NUMBER
) AS
BEGIN
    DELETE FROM ��������_�������� WHERE �������������_�������� = p_��_��������;
END DELETE_�������;
/

--��������� ��� ������� ����������:
CREATE OR REPLACE PROCEDURE INSERT_��������� (
    p_��� VARCHAR2,
    p_�������� NUMBER,
    p_���� VARCHAR2,
    p_����_�������� DATE,
    p_��� VARCHAR2,
    p_����� VARCHAR2
) AS
BEGIN
    INSERT INTO ���������� (���_����������, ��������, ����, ����_��������, ���, �����)
    VALUES (p_���, p_��������, p_����, p_����_��������, p_���, p_�����);
END INSERT_���������;
/

CREATE OR REPLACE PROCEDURE UPDATE_��������� (
    p_��_���������� NUMBER,
    p_��� VARCHAR2,
    p_�������� NUMBER,
    p_���� VARCHAR2,
    p_����_�������� DATE,
    p_��� VARCHAR2,
    p_����� VARCHAR2
) AS
BEGIN
    UPDATE ����������
    SET ���_���������� = p_���,
        �������� = p_��������,
        ���� = p_����,
        ����_�������� = p_����_��������,
        ��� = p_���,
        ����� = p_�����
    WHERE �������������_���������� = p_��_����������;
END UPDATE_���������;
/

CREATE OR REPLACE PROCEDURE DELETE_��������� (
    p_��_���������� NUMBER
) AS
BEGIN
    DELETE FROM ���������� WHERE �������������_���������� = p_��_����������;
END DELETE_���������;
/

--��������� ��� ������� �������_�������������:
CREATE OR REPLACE PROCEDURE INSERT_������� (
    p_��������_������� VARCHAR2,
    p_���������� VARCHAR2,
    p_��_�������� NUMBER
) AS
BEGIN
    INSERT INTO �������_������������� (��������_�������, ����������, �������������_��������)
    VALUES (p_��������_�������, p_����������, p_��_��������);
END INSERT_�������;
/

CREATE OR REPLACE PROCEDURE UPDATE_������� (
    p_��_������� NUMBER,
    p_��������_������� VARCHAR2,
    p_���������� VARCHAR2,
    p_��_�������� NUMBER
) AS
BEGIN
    UPDATE �������_�������������
    SET ��������_������� = p_��������_�������,
        ���������� = p_����������,
        �������������_�������� = p_��_��������
    WHERE �������������_������� = p_��_�������;
END UPDATE_�������;
/

CREATE OR REPLACE PROCEDURE DELETE_������� (
    p_��_������� NUMBER
) AS
BEGIN
    DELETE FROM �������_������������� WHERE �������������_������� = p_��_�������;
END DELETE_�������;
/

--��������� ��� ������� �����:
CREATE OR REPLACE PROCEDURE INSERT_����� (
    p_������������_������ VARCHAR2
) AS
BEGIN
    INSERT INTO ������ (������������_������)
    VALUES (p_������������_������);
END INSERT_�����;
/

CREATE OR REPLACE PROCEDURE UPDATE_����� (
    p_��_������ NUMBER,
    p_������������_������ VARCHAR2
) AS
BEGIN
    UPDATE ������
    SET ������������_������ = p_������������_������
    WHERE �������������_������ = p_��_������;
END UPDATE_�����;
/

CREATE OR REPLACE PROCEDURE DELETE_����� (
    p_��_������ NUMBER
) AS
BEGIN
    DELETE FROM ������ WHERE �������������_������ = p_��_������;
END DELETE_�����;
/

--��������� ��� ������� �������������:
CREATE OR REPLACE PROCEDURE INSERT_������������� (
    p_��_�������� NUMBER,
    p_���_��������� VARCHAR2,
    p_����_������������� DATE,
    p_���������_������������� VARCHAR2,
    p_��������� NUMBER
) AS
BEGIN
    INSERT INTO ������������� (�������������_��������, ���_���������, ����_�������������, ���������_�������������, ���������_�����������_�������������)
    VALUES (p_��_��������, p_���_���������, p_����_�������������, p_���������_�������������, p_���������);
END INSERT_�������������;
/

CREATE OR REPLACE PROCEDURE UPDATE_������������� (
    p_��_������������� NUMBER,
    p_��_�������� NUMBER,
    p_���_��������� VARCHAR2,
    p_����_������������� DATE,
    p_���������_������������� VARCHAR2,
    p_��������� NUMBER
) AS
BEGIN
    UPDATE �������������
    SET �������������_�������� = p_��_��������,
        ���_��������� = p_���_���������,
        ����_������������� = p_����_�������������,
        ���������_������������� = p_���������_�������������,
        ���������_�����������_������������� = p_���������
    WHERE �������������_������������� = p_��_�������������;
END UPDATE_�������������;
/

CREATE OR REPLACE PROCEDURE DELETE_������������� (
    p_��_������������� NUMBER
) AS
BEGIN
    DELETE FROM ������������� WHERE �������������_������������� = p_��_�������������;
END DELETE_�������������;
/

--��������� ��� ������� ��������:
CREATE OR REPLACE PROCEDURE INSERT_�������� (
    p_��������� VARCHAR2,
    p_����� VARCHAR2,
    p_��������_�������� VARCHAR2,
    p_����������_����� FLOAT,
    p_������_�������� VARCHAR2
) AS
BEGIN
    INSERT INTO �������� (���������, �����, ��������_��������, ����������_�����, ������_��������)
    VALUES (p_���������, p_�����, p_��������_��������, p_����������_�����, p_������_��������);
END INSERT_��������;
/

CREATE OR REPLACE PROCEDURE UPDATE_�������� (
    p_��_�������� NUMBER,
    p_��������� VARCHAR2,
    p_����� VARCHAR2,
    p_��������_�������� VARCHAR2,
    p_����������_����� FLOAT,
    p_������_�������� VARCHAR2
) AS
BEGIN
    UPDATE ��������
    SET ��������� = p_���������,
        ����� = p_�����,
        ��������_�������� = p_��������_��������,
        ����������_����� = p_����������_�����,
        ������_�������� = p_������_��������
    WHERE �������������_�������� = p_��_��������;
END UPDATE_��������;
/

CREATE OR REPLACE PROCEDURE DELETE_�������� (
    p_��_�������� NUMBER
) AS
BEGIN
    DELETE FROM �������� WHERE �������������_�������� = p_��_��������;
END DELETE_��������;
/
