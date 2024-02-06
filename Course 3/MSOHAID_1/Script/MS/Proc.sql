-- Procedure for ВАКАНСИИ table
CREATE OR ALTER PROCEDURE DELETE_ВАКАНСИЯ (
    @ИД_Вакансии INT
)
AS
BEGIN
    DELETE FROM ВАКАНСИИ
    WHERE ИДЕНТИФИКАТОР_ВАКАНСИИ = @ИД_Вакансии;
END;
