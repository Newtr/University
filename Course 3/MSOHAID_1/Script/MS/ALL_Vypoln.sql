--������������������
SELECT NEXT VALUE FOR SEQ_�����;
SELECT NEXT VALUE FOR SEQ_����;

--�������
SELECT 
    i.name AS IndexName,
    OBJECT_NAME(ic.OBJECT_ID) AS TableName,
    COL_NAME(ic.OBJECT_ID,ic.column_id) AS ColumnName
FROM 
    sys.indexes AS i
    INNER JOIN sys.index_columns AS ic ON  i.OBJECT_ID = ic.OBJECT_ID
    AND i.index_id = ic.index_id
WHERE 
    OBJECT_NAME(ic.OBJECT_ID) = '����������' -- ��� �������
ORDER BY 
    i.name, ic.key_ordinal;

--���������
EXECUTE DELETE_��������� @p_��_���������� = 37;
EXECUTE UPDATE_��������� @p_��_���������� = 36, @p_��� = '������ �������� ��������', @p_�������� = 8, @p_���� = �����������, @p_����_�������� = '1992-10-15', @p_��� = '�����', @p_����� = '����� ����������';

--�������
SELECT dbo.GetContractIdByEmployeeName('���������� ����� ��������');
SELECT dbo.GetTeamNameByProductId(1);
SELECT dbo.GetEmployeesByDepartment('����� ����������');


