USE MSOHAID;

-- Создание пользователя
CREATE LOGIN UserTest WITH PASSWORD = 'UserTest';
GO

-- Присвоение пользователю роли администратора
ALTER SERVER ROLE sysadmin ADD MEMBER UserTest;
GO

SELECT CURRENT_USER AS CurrentUser;

EXECUTE AS USER = 'Kaisa';

REVERT;



-- Вывести привилегии для пользователя Kaisa
SELECT 
    princ.name AS [UserName],
    perm.permission_name AS [Permission],
    perm.state_desc AS [State]
FROM sys.database_principals AS princ
JOIN sys.database_permissions AS perm ON princ.principal_id = perm.grantee_principal_id
WHERE princ.name = 'Kaisa';

GRANT ALTER ANY SCHEMA TO Kaisa;
GRANT CREATE TABLE TO Kaisa;
GRANT CREATE PROCEDURE TO Kaisa;

	GRANT SELECT, INSERT, UPDATE, DELETE TO Kaisa;

	GRANT EXECUTE TO Kaisa;

