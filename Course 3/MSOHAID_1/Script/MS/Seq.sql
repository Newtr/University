USE MSOHAID;
EXECUTE AS USER = 'Kaisa';
SELECT CURRENT_USER AS CurrentUser;

-- �������� ������������������ ��� �������� ��������
CREATE SEQUENCE SEQ_��
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- �������� ������������������ ��� ����������
CREATE SEQUENCE SEQ_���������
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- �������� ������������������ ��� ������� �������������
CREATE SEQUENCE SEQ_�������
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- �������� ������������������ ��� ����
CREATE SEQUENCE SEQ_����
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- �������� ������������������ ��� ������
CREATE SEQUENCE SEQ_�����
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- �������� ������������������ ��� �������������
CREATE SEQUENCE SEQ_�������������
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- �������� ������������������ ��� ��������
CREATE SEQUENCE SEQ_��������
START WITH 1
INCREMENT BY 1
NO CACHE
NO CYCLE;

-- ������� ��� ������������������, ��������� ������������� Kaisa
SELECT 
    schema_name(seq.schema_id) AS [SchemaName],
    seq.name AS [SequenceName]
FROM sys.sequences AS seq
JOIN sys.database_principals AS princ ON seq.principal_id = princ.principal_id
WHERE princ.name = 'Kaisa';