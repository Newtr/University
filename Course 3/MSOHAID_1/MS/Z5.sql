WITH ���������������������� AS (
    SELECT *,
    ROW_NUMBER() OVER (PARTITION BY �������� ORDER BY ��������) AS �����������
    FROM ����������
)
DELETE FROM ����������������������
WHERE ����������� > 1;
