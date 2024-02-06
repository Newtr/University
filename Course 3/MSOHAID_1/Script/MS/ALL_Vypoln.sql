--Посдедовательности
SELECT NEXT VALUE FOR SEQ_Отдел;
SELECT NEXT VALUE FOR SEQ_Роль;

--Индексы
SELECT 
    i.name AS IndexName,
    OBJECT_NAME(ic.OBJECT_ID) AS TableName,
    COL_NAME(ic.OBJECT_ID,ic.column_id) AS ColumnName
FROM 
    sys.indexes AS i
    INNER JOIN sys.index_columns AS ic ON  i.OBJECT_ID = ic.OBJECT_ID
    AND i.index_id = ic.index_id
WHERE 
    OBJECT_NAME(ic.OBJECT_ID) = 'Сотрудники' -- имя таблицы
ORDER BY 
    i.name, ic.key_ordinal;

--Процедуры
EXECUTE DELETE_СОТРУДНИК @p_ИД_Сотрудника = 37;
EXECUTE UPDATE_СОТРУДНИК @p_ИД_Сотрудника = 36, @p_ФИО = 'Виктор Петрович Некрасов', @p_Контракт = 8, @p_Роль = Разработчик, @p_Дата_Рождения = '1992-10-15', @p_Пол = 'Мужик', @p_Отдел = 'Отдел разработки';

--Функции
SELECT dbo.GetContractIdByEmployeeName('Григорьева Мария Павловна');
SELECT dbo.GetTeamNameByProductId(1);
SELECT dbo.GetEmployeesByDepartment('Отдел Разработки');


