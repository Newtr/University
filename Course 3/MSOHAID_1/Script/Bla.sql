USE MSOHAID;

exec sp_configure 'clr enabled',1
reconfigure;
exec sp_configure 'show advanced options', 1
reconfigure;
exec sp_configure 'clr strict security', 0
reconfigure;

alter database MSOHAID set trustworthy on;

EXEC dbo.AverageEmployeesPerDepartment


EXEC dbo.SendEmailOnVacancyStatusChange;

GO
CREATE TABLE ProductTable
(
    ID INT PRIMARY KEY,
    Product ProductIdentifier
);
DROP TABLE ProductTable;

DROP PROCEDURE SendEmailOnVacancyStatusChange;

DROP FUNCTION dbo.AverageEmployeesPerDepartment

INSERT INTO ProductTable (ID, Product) VALUES (2, 'AB 999999');

SELECT * FROM ProductTable;
