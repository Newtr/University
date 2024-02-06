exec sp_configure 'show advanced options', 1;
exec sp_configure 'clr enabled',1;
exec sp_configure 'clr strict security', 0
reconfigure

-- ������ ���������� ������ � ������ ����������
EXEC sp_add_trusted_assembly 'Mama';

-- �������� ������
CREATE ASSEMBLY Mama
FROM 'D:\��������� ����\5.�������\10_Lab(RR)\Script\Vot_ono\Vot_ono\bin\Debug\Vot_ono.dll'
WITH PERMISSION_SET = SAFE; -- ����������� UNSAFE ������ ���� � ��� ���� ���������� ��������
GO


-- �������� �������� ���������
CREATE PROCEDURE SendEmailOnJobStatusChangeProc
    @jobStatus NVARCHAR(MAX)
AS EXTERNAL NAME Mama.[Mama_namespace.StoredProcedures].SendEmailOnJobStatusChange;
GO

-- �������� ������������� ������������� ����
CREATE TYPE Mama_type
EXTERNAL NAME Mama.[Mama_namespace.YourUserDefinedType];
GO

-- ������ ������������� �������� ���������
EXEC SendEmailOnJobStatusChangeProc @jobStatus = N'��������';

-- ������ ������������� ������������� ������������� ����
DECLARE @userDefinedValue YourUserDefinedType;
-- ����� ����� ������������ � �������� � ����� ������������ ������������� �����
