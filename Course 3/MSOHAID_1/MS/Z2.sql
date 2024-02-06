SELECT 
    'Месяц' AS Период,
    MONTH(Дата_собеседования) AS Интервал,
    COUNT(*) AS Общее_количество_собеседований,
    SUM(CASE WHEN Результат_собеседования IN ('Прошел', 'Прошла') THEN 1 ELSE 0 END) AS Успешные_наймы
FROM Собеседования
GROUP BY MONTH(Дата_собеседования)

UNION ALL

SELECT 
    'Квартал',
    DATEPART(QUARTER, Дата_собеседования),
    COUNT(*),
    SUM(CASE WHEN Результат_собеседования IN ('Прошел', 'Прошла') THEN 1 ELSE 0 END)
FROM Собеседования
GROUP BY DATEPART(QUARTER, Дата_собеседования)

UNION ALL

SELECT 
    'Полугодие',
    CASE WHEN MONTH(Дата_собеседования) BETWEEN 1 AND 6 THEN 1 ELSE 2 END,
    COUNT(*),
    SUM(CASE WHEN Результат_собеседования IN ('Прошел', 'Прошла') THEN 1 ELSE 0 END)
FROM Собеседования
GROUP BY CASE WHEN MONTH(Дата_собеседования) BETWEEN 1 AND 6 THEN 1 ELSE 2 END

UNION ALL

SELECT 
    'Год',
    YEAR(Дата_собеседования),
    COUNT(*),
    SUM(CASE WHEN Результат_собеседования IN ('Прошел', 'Прошла') THEN 1 ELSE 0 END)
FROM Собеседования
GROUP BY YEAR(Дата_собеседования);
