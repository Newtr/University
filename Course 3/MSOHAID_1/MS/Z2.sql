SELECT 
    '�����' AS ������,
    MONTH(����_�������������) AS ��������,
    COUNT(*) AS �����_����������_�������������,
    SUM(CASE WHEN ���������_������������� IN ('������', '������') THEN 1 ELSE 0 END) AS ��������_�����
FROM �������������
GROUP BY MONTH(����_�������������)

UNION ALL

SELECT 
    '�������',
    DATEPART(QUARTER, ����_�������������),
    COUNT(*),
    SUM(CASE WHEN ���������_������������� IN ('������', '������') THEN 1 ELSE 0 END)
FROM �������������
GROUP BY DATEPART(QUARTER, ����_�������������)

UNION ALL

SELECT 
    '���������',
    CASE WHEN MONTH(����_�������������) BETWEEN 1 AND 6 THEN 1 ELSE 2 END,
    COUNT(*),
    SUM(CASE WHEN ���������_������������� IN ('������', '������') THEN 1 ELSE 0 END)
FROM �������������
GROUP BY CASE WHEN MONTH(����_�������������) BETWEEN 1 AND 6 THEN 1 ELSE 2 END

UNION ALL

SELECT 
    '���',
    YEAR(����_�������������),
    COUNT(*),
    SUM(CASE WHEN ���������_������������� IN ('������', '������') THEN 1 ELSE 0 END)
FROM �������������
GROUP BY YEAR(����_�������������);
