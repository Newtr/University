exec sp_configure 'show advanced options', 1;
exec sp_configure 'clr enabled',1;
exec sp_configure 'clr strict security', 0
reconfigure

-- Пример добавления сборки в список доверенных
EXEC sp_add_trusted_assembly 'Mama';

-- Создание сборки
CREATE ASSEMBLY Mama
FROM 'D:\Документы БГТУ\5.МСХОИАД\10_Lab(RR)\Script\Vot_ono\Vot_ono\bin\Debug\Vot_ono.dll'
WITH PERMISSION_SET = SAFE; -- Используйте UNSAFE только если у вас есть доверенный источник
GO


-- Создание хранимой процедуры
CREATE PROCEDURE SendEmailOnJobStatusChangeProc
    @jobStatus NVARCHAR(MAX)
AS EXTERNAL NAME Mama.[Mama_namespace.StoredProcedures].SendEmailOnJobStatusChange;
GO

-- Создание определяемого пользователем типа
CREATE TYPE Mama_type
EXTERNAL NAME Mama.[Mama_namespace.YourUserDefinedType];
GO

-- Пример использования хранимой процедуры
EXEC SendEmailOnJobStatusChangeProc @jobStatus = N'изменено';

-- Пример использования определяемого пользователем типа
DECLARE @userDefinedValue YourUserDefinedType;
-- Здесь можно использовать и работать с вашим определяемым пользователем типом
