-- Procedure for �������� table
CREATE OR ALTER PROCEDURE DELETE_�������� (
    @��_�������� INT
)
AS
BEGIN
    DELETE FROM ��������
    WHERE �������������_�������� = @��_��������;
END;
