-- Create an INSTEAD OF INSERT trigger
CREATE OR ALTER TRIGGER trg_CheckDataTypes_�������
ON ��������_��������
INSTEAD OF INSERT
AS
BEGIN
    -- Check data types before inserting
    IF EXISTS (
        SELECT *
        FROM inserted
        WHERE NOT (
            TRY_CAST(����_������_��������_�������� AS DATE) IS NOT NULL
            AND TRY_CAST(����_���������_��������_�������� AS DATE) IS NOT NULL
        )
    )
    BEGIN
        -- Invalid data types, print an error message or take other actions
        PRINT 'Invalid data types. Please check your input.';
    END
    ELSE
    BEGIN
        -- Valid data types, proceed with the insert
        INSERT INTO ��������_�������� (����_������_��������_��������, ����_���������_��������_��������, ���_��������)
        SELECT ����_������_��������_��������, ����_���������_��������_��������, ���_��������
        FROM inserted;
    END
END;


-- Call the INSERT_������� stored procedure without specifying ID
EXEC dbo.INSERT_�������
	@p_������������� = '12',
    @p_����_������ = '2023-12-07', -- Replace with the actual start date
    @p_����_��������� = '2024-12-07', -- Replace with the actual end date
    @p_���_�������� = '���_��������'; -- Replace with the actual contract type

