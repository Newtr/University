SELECT 
    '������� ���������� �������������' AS ���_�������,
    AVG(����������) AS ��������
FROM (
    SELECT COUNT(*) AS ����������
    FROM �������������
    GROUP BY ���������_�����������_�������������
) AS SubQuery

UNION ALL

SELECT 
    '��������� ���������� ������������� � ������������ ���������� ����',
    AVG(����������)
FROM (
    SELECT ����������.����, COUNT(*) AS ����������
    FROM �������������
    INNER JOIN ���������� ON �������������.���������_�����������_������������� = ����������.���_����������
    GROUP BY ����������.����, ����������.���_����������
) AS SubQuery

UNION ALL

SELECT 
    '��������� ���������� ������������� � ������������ ����� �� ������',
    AVG(����������)
FROM (
    SELECT ����������.�����, COUNT(*) AS ����������
    FROM �������������
    INNER JOIN ���������� ON �������������.���������_�����������_������������� = ����������.���_����������
    GROUP BY ����������.�����, ����������.���_����������
) AS SubQuery
