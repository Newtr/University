-- ��������� CLR � ��������� ���������� ������������
EXEC sp_configure 'show advanced options', 1;
EXEC sp_configure 'clr enabled', 1;
EXEC sp_configure 'clr strict security', 0;
RECONFIGURE;

-- �������� ���������
CREATE PROCEDURE dbo.CalculateAverageWithoutMinMax
    @values NVARCHAR(MAX),
    @result FLOAT OUTPUT
AS EXTERNAL NAME YourAssemblyName.[YourNamespace.StoredProcedures].CalculateAverageWithoutMinMax;

-- ���������� ���������
DECLARE @result FLOAT;
EXEC dbo.CalculateAverageWithoutMinMax
    @values = '1,2,3,4,5,5',
    @result = @result OUTPUT;
SELECT @result AS Result;

-- ����� �������
DECLARE @result FLOAT;
SELECT @result = dbo.CalculateAverageWithoutMinMax('1,2,3,4,5,10,10');
SELECT @result AS Result;

-- �������� �������
CREATE TABLE PassportTable
(
    ID INT PRIMARY KEY,
    Passport PassportData
);

-- �������� �������
DROP TABLE PassportTable;

-- ������� ������
INSERT INTO PassportTable (ID, PassportData) VALUES (2, 'AB 999999');

-- �������� ������
SELECT * FROM PassportTable;
