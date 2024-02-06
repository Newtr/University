-- Create an INSTEAD OF INSERT trigger
CREATE OR ALTER TRIGGER trg_CheckDataTypes_днцнбнп
ON рпсднбше_днцнбнпш
INSTEAD OF INSERT
AS
BEGIN
    -- Check data types before inserting
    IF EXISTS (
        SELECT *
        FROM inserted
        WHERE NOT (
            TRY_CAST(дюрю_мювюкю_деиярбхъ_днцнбнпю AS DATE) IS NOT NULL
            AND TRY_CAST(дюрю_нйнмвюмхъ_деиярбхъ_днцнбнпю AS DATE) IS NOT NULL
        )
    )
    BEGIN
        -- Invalid data types, print an error message or take other actions
        PRINT 'Invalid data types. Please check your input.';
    END
    ELSE
    BEGIN
        -- Valid data types, proceed with the insert
        INSERT INTO рпсднбше_днцнбнпш (дюрю_мювюкю_деиярбхъ_днцнбнпю, дюрю_нйнмвюмхъ_деиярбхъ_днцнбнпю, рхо_днцнбнпю)
        SELECT дюрю_мювюкю_деиярбхъ_днцнбнпю, дюрю_нйнмвюмхъ_деиярбхъ_днцнбнпю, рхо_днцнбнпю
        FROM inserted;
    END
END;


-- Call the INSERT_днцнбнп stored procedure without specifying ID
EXEC dbo.INSERT_днцнбнп
	@p_хДЕМРХТХЙЮРНП = '12',
    @p_дЮРЮ_мЮВЮКЮ = '2023-12-07', -- Replace with the actual start date
    @p_дЮРЮ_нЙНМВЮМХЪ = '2024-12-07', -- Replace with the actual end date
    @p_рХО_дНЦНБНПЮ = 'рХО_дНЦНБНПЮ'; -- Replace with the actual contract type

