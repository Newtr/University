SELECT 
    �����,
    DATEPART(MONTH, ����_�������������) AS �����,
    COUNT(*) AS ����������_�������������
FROM 
    �������������
INNER JOIN 
    ���������� ON �������������.���������_�����������_������������� = ����������.���_����������
WHERE 
    ����_������������� >= DATEADD(MONTH, -6, GETDATE())
GROUP BY 
    �����,
    DATEPART(MONTH, ����_�������������);