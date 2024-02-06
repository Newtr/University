WITH СотрудникиРанжирование AS (
    SELECT *,
    ROW_NUMBER() OVER (ORDER BY ФИО_Сотрудника) AS НомерСтроки
    FROM Сотрудники
)
SELECT *
FROM СотрудникиРанжирование
WHERE НомерСтроки BETWEEN ((2 - 1) * 20 + 1) AND (2 * 20);
