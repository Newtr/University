WITH ���������������������� AS (
    SELECT *,
    ROW_NUMBER() OVER (ORDER BY ���_����������) AS �����������
    FROM ����������
)
SELECT *
FROM ����������������������
WHERE ����������� BETWEEN ((2 - 1) * 20 + 1) AND (2 * 20);
