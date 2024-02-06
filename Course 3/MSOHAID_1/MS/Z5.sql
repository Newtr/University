WITH СотрудникиРанжирование AS (
    SELECT *,
    ROW_NUMBER() OVER (PARTITION BY Контракт ORDER BY Контракт) AS НомерСтроки
    FROM Сотрудники
)
DELETE FROM СотрудникиРанжирование
WHERE НомерСтроки > 1;
