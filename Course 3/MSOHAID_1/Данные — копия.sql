SELECT * FROM "����������_��������_��������";

SELECT * FROM "����";
SELECT * FROM "������";
SELECT * FROM "��������";
SELECT * FROM "��������_��������";
SELECT * FROM "����������";
SELECT * FROM "�������������";
SELECT * FROM "�������_�������������";

SELECT * FROM "�����";
SELECT * FROM "�����";
SELECT * FROM "����������";
SELECT * FROM "���������_�����������_��������";

SELECT * FROM "�������_���������";
SELECT * FROM "������_�����������";
SELECT * FROM "��������_������������";
SELECT * FROM "������_����_�����������";

SELECT * FROM "������";
SELECT * FROM "���������";
SELECT * FROM "���������_���������";
SELECT * FROM "��������";
SELECT * FROM "�������";
SELECT * FROM "�������";
SELECT * FROM "�������";
SELECT * FROM "��������_�������_�_��������";

DELETE FROM "���������_���������";

-- ���������� ������� "����������_��������_��������"
INSERT ALL
INTO ����������_��������_�������� (�������������_��������, �������������_����) VALUES (1, 1)
INTO ����������_��������_�������� (�������������_��������, �������������_����) VALUES (2, 2)
INTO ����������_��������_�������� (�������������_��������, �������������_����) VALUES (3, 3)
INTO ����������_��������_�������� (�������������_��������, �������������_����) VALUES (4, 4)
SELECT * FROM dual;

-- ���������� ������� "����"
INSERT ALL
INTO ���� (�������������_����, ��������_����) VALUES (1, '�������������')
INTO ���� (�������������_����, ��������_����) VALUES (2, '��������')
INTO ���� (�������������_����, ��������_����) VALUES (3, '�����������')
INTO ���� (�������������_����, ��������_����) VALUES (4, '��������')
INTO ���� (�������������_����, ��������_����) VALUES (5, '�����������')
INTO ���� (�������������_����, ��������_����) VALUES (6, '��������')
SELECT * FROM dual;

-- ���������� ������� "������"
INSERT ALL
INTO ������ (�������������_������, ������������_������) VALUES (1, '����� ����������')
INTO ������ (�������������_������, ������������_������) VALUES (2, '����� �������')
INTO ������ (�������������_������, ������������_������) VALUES (3, '����� ������������')
INTO ������ (�������������_������, ������������_������) VALUES (4, '����� ����������')
INTO ������ (�������������_������, ������������_������) VALUES (5, '����� �������')
SELECT * FROM dual;

-- ���������� ������� "��������"
INSERT ALL
INTO �������� (�������������_��������, ���������, �����, ��������_��������, ����������_�����, ������_��������) VALUES (1, '�����������', '����� ����������', '��������� ������� �����������', 60000.00, '�������')
INTO �������� (�������������_��������, ���������, �����, ��������_��������, ����������_�����, ������_��������) VALUES (2, '��������', '����� �������', '���� ������������ ���������', 55000.00, '�������')
INTO �������� (�������������_��������, ���������, �����, ��������_��������, ����������_�����, ������_��������) VALUES (3, '�����������', '����� ������������', '�������� ��� ������������', 50000.00, '�������')
INTO �������� (�������������_��������, ���������, �����, ��������_��������, ����������_�����, ������_��������) VALUES (4, '����������', '����� ����������', '��������� ����������', 55000.00, '�������')
INTO �������� (�������������_��������, ���������, �����, ��������_��������, ����������_�����, ������_��������) VALUES (5, '��������', '����� �������', '����� ���������', 58000.00, '�������')
INTO �������� (�������������_��������, ���������, �����, ��������_��������, ����������_�����, ������_��������) VALUES (6, '��������', '����� ����������', '�������� ��� ���������', 60000.00, '�������')
SELECT * FROM dual;

-- ���������� ������� "�������� ��������"
INSERT ALL
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (1, TO_DATE('2023-01-01', 'YYYY-MM-DD'), TO_DATE('2023-12-31', 'YYYY-MM-DD'), '����������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (2, TO_DATE('2023-02-15', 'YYYY-MM-DD'), TO_DATE('2023-11-30', 'YYYY-MM-DD'), '���������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (3, TO_DATE('2023-03-10', 'YYYY-MM-DD'), TO_DATE('2023-12-15', 'YYYY-MM-DD'), '����������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (4, TO_DATE('2023-04-20', 'YYYY-MM-DD'), TO_DATE('2023-09-30', 'YYYY-MM-DD'), '���������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (5, TO_DATE('2023-05-15', 'YYYY-MM-DD'), TO_DATE('2023-10-31', 'YYYY-MM-DD'), '����������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (6, TO_DATE('2023-06-10', 'YYYY-MM-DD'), TO_DATE('2023-12-31', 'YYYY-MM-DD'), '����������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (7, TO_DATE('2023-07-15', 'YYYY-MM-DD'), TO_DATE('2023-11-30', 'YYYY-MM-DD'), '���������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (8, TO_DATE('2023-08-10', 'YYYY-MM-DD'), TO_DATE('2023-12-15', 'YYYY-MM-DD'), '����������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (9, TO_DATE('2023-09-20', 'YYYY-MM-DD'), TO_DATE('2023-10-31', 'YYYY-MM-DD'), '���������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (10, TO_DATE('2023-10-01', 'YYYY-MM-DD'), TO_DATE('2023-12-31', 'YYYY-MM-DD'), '����������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (11, TO_DATE('2023-11-15', 'YYYY-MM-DD'), TO_DATE('2023-11-30', 'YYYY-MM-DD'), '���������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (12, TO_DATE('2023-12-10', 'YYYY-MM-DD'), TO_DATE('2023-12-15', 'YYYY-MM-DD'), '����������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (13, TO_DATE('2023-01-20', 'YYYY-MM-DD'), TO_DATE('2023-01-31', 'YYYY-MM-DD'), '���������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (14, TO_DATE('2023-02-10', 'YYYY-MM-DD'), TO_DATE('2023-02-15', 'YYYY-MM-DD'), '����������')
INTO ��������_�������� (�������������_��������, ����_������_��������_��������, ����_���������_��������_��������, ���_��������) VALUES (15, TO_DATE('2023-03-01', 'YYYY-MM-DD'), TO_DATE('2023-03-31', 'YYYY-MM-DD'), '���������')
SELECT * FROM dual;

-- ���������� ������� "����������"
INSERT ALL
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (1, '������ ���� ��������', 1, '�����������', TO_DATE('1990-05-15', 'YYYY-MM-DD'), '�������', '����� ����������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (2, '������� ���� ���������', 2, '��������', TO_DATE('1985-12-10', 'YYYY-MM-DD'), '�������', '����� �������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (3, '������� �������� �������������', 3, '�����������', TO_DATE('1992-08-20', 'YYYY-MM-DD'), '�������', '����� ������������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (4, '��������� ����� ����������', 4, '��������', TO_DATE('1988-03-05', 'YYYY-MM-DD'), '�������', '����� ����������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (5, '������� ����� ����������', 5, '��������', TO_DATE('1991-07-25', 'YYYY-MM-DD'), '�������', '����� �������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (6, '���������� ����� ��������', 6, '�����������', TO_DATE('1989-02-18', 'YYYY-MM-DD'), '�������', '����� ����������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (7, '������� ������� ������������', 7, '��������', TO_DATE('1987-11-30', 'YYYY-MM-DD'), '�������', '����� �������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (8, '�������� ����� ��������', 8, '�����������', TO_DATE('1993-09-15', 'YYYY-MM-DD'), '�������', '����� ������������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (9, '����� ������ ����������', 9, '��������', TO_DATE('1990-04-12', 'YYYY-MM-DD'), '�������', '����� ����������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (10, '������ ������ ���������', 10, '��������', TO_DATE('1988-06-28', 'YYYY-MM-DD'), '�������', '����� �������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (11, '������� ������ ��������', 11, '�����������', TO_DATE('1992-03-22', 'YYYY-MM-DD'), '�������', '����� ����������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (12, '������ ����� �������������', 12, '��������', TO_DATE('1991-08-08', 'YYYY-MM-DD'), '�������', '����� �������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (13, '��������� ��������� ���������', 13, '�����������', TO_DATE('1989-05-17', 'YYYY-MM-DD'), '�������', '����� ������������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (14, '����� ����� ��������', 14, '��������', TO_DATE('1987-11-10', 'YYYY-MM-DD'), '�������', '����� ����������')
INTO ���������� (�������������_����������, ���_����������, ��������, ����, ����_��������, ���, �����) VALUES (15, '������ ��������� ���������', 15, '��������', TO_DATE('1993-02-25', 'YYYY-MM-DD'), '�������', '����� �������')
SELECT * FROM dual;

-- ���������� ������� "�������������"
INSERT ALL
INTO ������������� (�������������_�������������, �������������_��������, ���_���������, ����_�������������, ���������_�������������, ���������_�����������_�������������) VALUES (1, 1, '������ ���� ���������', TO_DATE('2023-01-15', 'YYYY-MM-DD'), '������', '������ ���� ��������')
INTO ������������� (�������������_�������������, �������������_��������, ���_���������, ����_�������������, ���������_�������������, ���������_�����������_�������������) VALUES (2, 2, '������� ����� ������������', TO_DATE('2023-01-20', 'YYYY-MM-DD'), '������', '������� ���� ���������')
INTO ������������� (�������������_�������������, �������������_��������, ���_���������, ����_�������������, ���������_�������������, ���������_�����������_�������������) VALUES (3, 3, '������� ���� ��������', TO_DATE('2023-02-05', 'YYYY-MM-DD'), '������', '������� �������� �������������')
INTO ������������� (�������������_�������������, �������������_��������, ���_���������, ����_�������������, ���������_�������������, ���������_�����������_�������������) VALUES (4, 4, '��������� ��������� ���������', TO_DATE('2023-02-10', 'YYYY-MM-DD'), '������', '��������� ����� ����������')
INTO ������������� (�������������_�������������, �������������_��������, ���_���������, ����_�������������, ���������_�������������, ���������_�����������_�������������) VALUES (5, 5, '��������� ����� ����������', TO_DATE('2023-02-15', 'YYYY-MM-DD'), '�� ������', '���������� ����� ��������')
INTO ������������� (�������������_�������������, �������������_��������, ���_���������, ����_�������������, ���������_�������������, ���������_�����������_�������������) VALUES (6, 6, '�������� ���� ������������', TO_DATE('2023-02-20', 'YYYY-MM-DD'), '������', '������� ������� ������������')
SELECT * FROM dual;

INSERT ALL
INTO �������_������������� (�������������_�������, ��������_�������, ����������, �������������_��������) VALUES (1, '������� 1', '�������� ����� ��������', 1)
INTO �������_������������� (�������������_�������, ��������_�������, ����������, �������������_��������) VALUES (2, '������� 1', '����� ����� ��������', 1)
INTO �������_������������� (�������������_�������, ��������_�������, ����������, �������������_��������) VALUES (3, '������� 1', '������� ������ ��������', 1)
INTO �������_������������� (�������������_�������, ��������_�������, ����������, �������������_��������) VALUES (4, '������� 1', '������ ����� �������������', 1)
INTO �������_������������� (�������������_�������, ��������_�������, ����������, �������������_��������) VALUES (5, '������� 1', '��������� ����� ����������', 1)
INTO �������_������������� (�������������_�������, ��������_�������, ����������, �������������_��������) VALUES (6, '������� 1', '������� �������� �������������', 1)
INTO �������_������������� (�������������_�������, ��������_�������, ����������, �������������_��������) VALUES (7, '������� 2', '������ ���� ��������', 2)
INTO �������_������������� (�������������_�������, ��������_�������, ����������, �������������_��������) VALUES (8, '������� 2', '������� ���� ���������', 2)
INTO �������_������������� (�������������_�������, ��������_�������, ����������, �������������_��������) VALUES (9, '������� 2', '���������� ����� ��������', 2)
INTO �������_������������� (�������������_�������, ��������_�������, ����������, �������������_��������) VALUES (10, '������� 2', '����� ������ ����������', 2)
INTO �������_������������� (�������������_�������, ��������_�������, ����������, �������������_��������) VALUES (11, '������� 2', '������ ������ ���������', 2)
INTO �������_������������� (�������������_�������, ��������_�������, ����������, �������������_��������) VALUES (12, '������� 2', '��������� ��������� ���������', 2)
SELECT * FROM dual;

-- ���������� ������� "�����"
INSERT ALL
INTO ����� (�������������_�����, ������������_�����, ������, ��������������, ����������_�������) VALUES (1, '�����������', '������� ������', '�����, ��������', '+375-17-123-45-67')
INTO ����� (�������������_�����, ������������_�����, ������, ��������������, ����������_�������) VALUES (2, '���-��������', '���� � ������', '�����, ��������', '+375-17-987-65-43')
INTO ����� (�������������_�����, ������������_�����, ������, ��������������, ����������_�������) VALUES (3, '�����-����', '���� �� ���������', '������, ��������', '+375-152-123-456')
INTO ����� (�������������_�����, ������������_�����, ������, ��������������, ����������_�������) VALUES (4, '��������������', '������ � ������', '�������, ��������', '+375-222-987-654')
INTO ����� (�������������_�����, ������������_�����, ������, ��������������, ����������_�������) VALUES (5, '���������', '���� �� �������', '�����, ��������', '+375-162-123-789')
INTO ����� (�������������_�����, ������������_�����, ������, ��������������, ����������_�������) VALUES (6, '��� ����', '������ � ������', '�������, ��������', '+375-212-987-123')
INTO ����� (�������������_�����, ������������_�����, ������, ��������������, ����������_�������) VALUES (7, '����������', '������� ����', '������, ��������', '+375-232-123-987')
INTO ����� (�������������_�����, ������������_�����, ������, ��������������, ����������_�������) VALUES (8, '��� ����', '���� � ������', '�����, ��������', '+375-17-987-23-45')
SELECT * FROM dual;

-- ���������� ������� "�����"
INSERT ALL
INTO ����� (�������������_�����, ������������_�����, ���_�����, ������_�����, �������������_���������, ����) VALUES (1, '�������� ����', '�������', 10000.50, '������ ���� ��������', '�����������')
INTO ����� (�������������_�����, ������������_�����, ���_�����, ������_�����, �������������_���������, ����) VALUES (2, '�������������� ���� 1 ������', '��������������', 5000.75, '������� ���� ���������', '���-��������')
INTO ����� (�������������_�����, ������������_�����, ���_�����, ������_�����, �������������_���������, ����) VALUES (3, '���������� ���� 1 ������', '�������', 25000.25, '������� ����� ����������', '�����-����')
INTO ����� (�������������_�����, ������������_�����, ���_�����, ������_�����, �������������_���������, ����) VALUES (4, '������� ����', '�������', 7500.00, '����� ������ ����������', '��������������')
INTO ����� (�������������_�����, ������������_�����, ���_�����, ������_�����, �������������_���������, ����) VALUES (5, '�������������� ���� 2 ������', '��������������', 1000.50, '������ ����� �������������', '���������')
INTO ����� (�������������_�����, ������������_�����, ���_�����, ������_�����, �������������_���������, ����) VALUES (6, '���������� ���� 2 ������', '�������', 15000.75, '������� ������� ������������', '��� ����')
SELECT * FROM dual;

-- ���������� ������� "����������"
INSERT ALL
INTO ���������� (�������������_����������, ����_����������, ���_����������, �����_����������, ��������_����������, ����_����������_����������, ������������_�����) VALUES (1, TO_DATE('2023-10-15', 'yyyy-mm-dd'), '�������', 100.50, '������ �� ������', '�����������', '�������� ����')
INTO ���������� (�������������_����������, ����_����������, ���_����������, �����_����������, ��������_����������, ����_����������_����������, ������������_�����) VALUES (2, TO_DATE('2023-10-16', 'yyyy-mm-dd'), '��������', 50.25, '������� ���������', '���-��������', '�������������� ���� 1 ������')
INTO ���������� (�������������_����������, ����_����������, ���_����������, �����_����������, ��������_����������, ����_����������_����������, ������������_�����) VALUES (3, TO_DATE('2023-10-17', 'yyyy-mm-dd'), '����������', 200.75, '������� �� ������������', '�����-����', '���������� ���� 1 ������')
INTO ���������� (�������������_����������, ����_����������, ���_����������, �����_����������, ��������_����������, ����_����������_����������, ������������_�����) VALUES (4, TO_DATE('2023-10-18', 'yyyy-mm-dd'), '�������', 300.00, '��������� �����', '��������������', '������� ����')
INTO ���������� (�������������_����������, ����_����������, ���_����������, �����_����������, ��������_����������, ����_����������_����������, ������������_�����) VALUES (5, TO_DATE('2023-10-19', 'yyyy-mm-dd'), '��������', 150.50, '������� �����������', '���������', '�������������� ���� 2 ������')
SELECT * FROM dual;

-- ���������� ������� "��������� ����������� ��������"
INSERT ALL
INTO ���������_�����������_�������� (����_��������, ����������, ����������_�_��������, �������������_��������) VALUES (TO_DATE('2023-10-15', 'yyyy-mm-dd'), 1, '�������� �������� ��� �������� �', 1)
INTO ���������_�����������_�������� (����_��������, ����������, ����������_�_��������, �������������_��������) VALUES (TO_DATE('2023-10-16', 'yyyy-mm-dd'), 2, '�������� �������� ��� �������� �', 2)
INTO ���������_�����������_�������� (����_��������, ����������, ����������_�_��������, �������������_��������) VALUES (TO_DATE('2023-10-17', 'yyyy-mm-dd'), 3, '�������� �������� ��� �������� �', 3)
INTO ���������_�����������_�������� (����_��������, ����������, ����������_�_��������, �������������_��������) VALUES (TO_DATE('2023-10-18', 'yyyy-mm-dd'), 4, '�������� �������� ��� �������� �', 4)
INTO ���������_�����������_�������� (����_��������, ����������, ����������_�_��������, �������������_��������) VALUES (TO_DATE('2023-10-19', 'yyyy-mm-dd'), 5, '�������� �������� ��� �������� �', 2)
SELECT * FROM dual;

-- ���������� ������� "������� ���������"
INSERT ALL
INTO �������_��������� (�������������_�������_���������, ��������_�������_���������, ��������_�������_���������) VALUES (1, '����', '������� ��������� - ���� �� 6 �� 12 ���')
INTO �������_��������� (�������������_�������_���������, ��������_�������_���������, ��������_�������_���������) VALUES (2, '���������', '������� ��������� - ��������� �� 13 �� 17 ���')
INTO �������_��������� (�������������_�������_���������, ��������_�������_���������, ��������_�������_���������) VALUES (3, '��������', '������� ��������� - �������� �� 18 ��� � ������')
INTO �������_��������� (�������������_�������_���������, ��������_�������_���������, ��������_�������_���������) VALUES (4, '�������', '������� ��������� - �������� �������� � ������������ �����������')
INTO �������_��������� (�������������_�������_���������, ��������_�������_���������, ��������_�������_���������) VALUES (5, '����������', '������� ��������� - �������� ���������� � �������� ���������� ����������')
INTO �������_��������� (�������������_�������_���������, ��������_�������_���������, ��������_�������_���������) VALUES (6, '���������', '������� ��������� - ��������� � �������� ������')
SELECT * FROM dual;

-- ���������� ������� "������ �����������"
INSERT ALL
INTO ������_����������� (�������������_������_�����������, ��������_������_�����������, ��������_������_�����������, ������_������_�����������, ���������_������������_������������) VALUES (1, '���������� ����', '����������� ����� ���������� ���������� ����', TO_DATE('2023-10-15', 'yyyy-mm-dd'), '������ ���� ��������')
INTO ������_����������� (�������������_������_�����������, ��������_������_�����������, ��������_������_�����������, ������_������_�����������, ���������_������������_������������) VALUES (2, '������������� �������', '����������� ����� ������������� ��������� ������', TO_DATE('2023-10-16', 'yyyy-mm-dd'), '������� ���� ���������')
INTO ������_����������� (�������������_������_�����������, ��������_������_�����������, ��������_������_�����������, ������_������_�����������, ���������_������������_������������) VALUES (3, '��������� �������', '����������� ����� ��������� ������� � ����������� �������', TO_DATE('2023-10-17', 'yyyy-mm-dd'), '������� ����� ����������')
INTO ������_����������� (�������������_������_�����������, ��������_������_�����������, ��������_������_�����������, ������_������_�����������, ���������_������������_������������) VALUES (4, '�������� ���', '����������� ����� �������� ��� � ������', TO_DATE('2023-10-18', 'yyyy-mm-dd'), '����� ������ ����������')
INTO ������_����������� (�������������_������_�����������, ��������_������_�����������, ��������_������_�����������, ������_������_�����������, ���������_������������_������������) VALUES (5, '����������� ���������', '����������� ����� ����������� ��������� � ��������������', TO_DATE('2023-10-19', 'yyyy-mm-dd'), '������ ����� �������������')
INTO ������_����������� (�������������_������_�����������, ��������_������_�����������, ��������_������_�����������, ������_������_�����������, ���������_������������_������������) VALUES (6, 'Email ���������', '����������� ����� email �������� � ������������� ������', TO_DATE('2023-10-19', 'yyyy-mm-dd'), '������� ������� ������������')
INTO ������_����������� (�������������_������_�����������, ��������_������_�����������, ��������_������_�����������, ������_������_�����������, ���������_������������_������������) VALUES (7, '��������-�������', '����������� ����� ������� � ����������� ���������� � ���������', TO_DATE('2023-10-15', 'yyyy-mm-dd'), '������� �������� �������������')
SELECT * FROM dual;

-- ���������� ������� "�������� ������������"
INSERT ALL
INTO ��������_������������ (�������������_���������_������������, ����_���������_������������, ������_���������_������������, ����_����������_���������_������������, ���������_���������_������) VALUES(1, '���� 1', '������ 1', TO_DATE('2023-11-08', 'YYYY-MM-DD'), '������ ���� ��������')
INTO ��������_������������ (�������������_���������_������������, ����_���������_������������, ������_���������_������������, ����_����������_���������_������������, ���������_���������_������) VALUES(2, '���� 2', '������ 2', TO_DATE('2023-11-09', 'YYYY-MM-DD'), '������� ���� ���������')
INTO ��������_������������ (�������������_���������_������������, ����_���������_������������, ������_���������_������������, ����_����������_���������_������������, ���������_���������_������) VALUES(3, '���� 3', '������ 3', TO_DATE('2023-11-10', 'YYYY-MM-DD'), '������� �������� �������������')
INTO ��������_������������ (�������������_���������_������������, ����_���������_������������, ������_���������_������������, ����_����������_���������_������������, ���������_���������_������) VALUES(4, '���� 4', '������ 4', TO_DATE('2023-11-11', 'YYYY-MM-DD'), '��������� ����� ����������')
INTO ��������_������������ (�������������_���������_������������, ����_���������_������������, ������_���������_������������, ����_����������_���������_������������, ���������_���������_������) VALUES(5, '���� 5', '������ 5', TO_DATE('2023-11-12', 'YYYY-MM-DD'), '������� ����� ����������')
SELECT * FROM dual;

--���������� ������� "������ ���� �����������"
INSERT ALL
INTO ������_����_�����������(�������������_������, ��������_������, ��������_������, �������������_�������_���������, �������������_������_�����������, ������_�����, �������������_���������, �������������_��������) VALUES(1, '������� ��������', '����������� � �������������� �������� ����', 1, 1, 1, '������ ���� ��������', 1)
INTO ������_����_�����������(�������������_������, ��������_������, ��������_������, �������������_�������_���������, �������������_������_�����������, ������_�����, �������������_���������, �������������_��������) VALUES(2, '��������� �������', '����������� � ��������� ������� ���� � YouTube', 2, 2, 2, '������� ���� ���������', 2)
INTO ������_����_�����������(�������������_������, ��������_������, ��������_������, �������������_�������_���������, �������������_������_�����������, ������_�����, �������������_���������, �������������_��������) VALUES(3, '������������ ����-������������', '������������ ����-������������ ���� � ������������� ��������������', 3, 3, 3, '������� �������� �������������', 3)
INTO ������_����_�����������(�������������_������, ��������_������, ��������_������, �������������_�������_���������, �������������_������_�����������, ������_�����, �������������_���������, �������������_��������) VALUES(4, '�������� ������', '�������� ������ �� ����-�������� � �������� ����', 4, 4, 4, '��������� ����� ����������', 4)
SELECT * FROM dual;

--���������� ������� "������"
INSERT ALL
INTO ������(ID, ���, �������, ����) VALUES(1, '������', 10, 500)
INTO ������(ID, ���, �������, ����) VALUES(2, '�������_��������', 12, 700)
INTO ������(ID, ���, �������, ����) VALUES(3, '����2007', 8, 300)
INTO ������(ID, ���, �������, ����) VALUES(4, '������_�������', 11, 600)
INTO ������(ID, ���, �������, ����) VALUES(5, '��������_���������', 9, 400)
SELECT * FROM dual;

--���������� ������� "���������"
INSERT ALL 
INTO ���������(ID, ���, ��������_���������, ��������) VALUES(1, '���', '������', '������ � ��������������� �������� �� �������')
INTO ���������(ID, ���, ��������_���������, ��������) VALUES(2, '�����', '������', '�������� � ����������� �������� � �������')
INTO ���������(ID, ���, ��������_���������, ��������) VALUES(3, '������', '������', '������ � �������� ��������-�������')
INTO ���������(ID, ���, ��������_���������, ��������) VALUES(4, '����', '������', '�������������� � ���������� ���������� ���������')
INTO ���������(ID, ���, ��������_���������, ��������) VALUES(5, '������', '�������_��������', '�������� � ������������� �����������-����������')
INTO ���������(ID, ���, ��������_���������, ��������) VALUES(6, '���', '����2007', '����� � �������������� ��������� �����')
INTO ���������(ID, ���, ��������_���������, ��������) VALUES(7, '���', '������_�������', '������� � ����������� ���������-��������')
INTO ���������(ID, ���, ��������_���������, ��������) VALUES(8, '�������', '��������_���������', '����� � ������������ ���������-������������')
SELECT * FROM dual;

-- ���������� ������� "��������� ���������"
INSERT ALL
INTO ���������_��������� (ID, ��������, ��������, ����������) VALUES (1, '���', '��� � ������', 20)
INTO ���������_��������� (ID, ��������, ��������, ����������) VALUES (2, '�����', '���������', 2)
INTO ���������_��������� (ID, ��������, ��������, ����������) VALUES (3, '������', '�������', 10)
INTO ���������_��������� (ID, ��������, ��������, ����������) VALUES (4, '����', '���������� ������', 5)
INTO ���������_��������� (ID, ��������, ��������, ����������) VALUES (5, '������', '����������', 3)
INTO ���������_��������� (ID, ��������, ��������, ����������) VALUES (6, '���', '���������� ��������', 1)
INTO ���������_��������� (ID, ��������, ��������, ����������) VALUES (7, '���', '���', 1)
INTO ���������_��������� (ID, ��������, ��������, ����������) VALUES (8, '�������', '����������� ��������', 1)
INTO ���������_��������� (ID, ��������, ��������, ����������) VALUES (9, '�������', '�������-������', 4)
SELECT * FROM dual;

-- ���������� ������� "��������"
INSERT ALL
INTO �������� (ID, ��������, ��������, ���������, ����) VALUES (1, '�������� 1', '�������� �������� 1', '���������1', 1)
INTO �������� (ID, ��������, ��������, ���������, ����) VALUES (2, '�������� 2', '�������� �������� 2', '���������2', 2)
INTO �������� (ID, ��������, ��������, ���������, ����) VALUES (3, '�������� 3', '�������� �������� 3', '���������3', 3)
INTO �������� (ID, ��������, ��������, ���������, ����) VALUES (4, '�������� 4', '�������� �������� 4', '���������4', 4)
SELECT * FROM dual;

-- ���������� ������� "��������"
INSERT ALL
INTO �������� (ID, ��������, ��������, ���������, ����) VALUES (1, '����������� � ������������', '��������� ����������� � ������ ��������������, ������ ������������ �����', '������ ���� ��������', 1)
INTO �������� (ID, ��������, ��������, ���������, ����) VALUES (2, '���� ��������', '������ ������� � �������� � �������� � ������� ������', '������� ���� ���������', 2)
INTO �������� (ID, ��������, ��������, ���������, ����) VALUES (3, '��� ��������', '����������� ���� � ����� ����� �������� ��������� � �������������', '������� �������� �������������', 3)
INTO �������� (ID, ��������, ��������, ���������, ����) VALUES (4, '� ������ �� �����������', '���������� ����� � ������ �����������, ������ ��������� ���������', '��������� ����� ����������', 4)
SELECT * FROM dual;

-- ���������� ������� "�������"
INSERT ALL
INTO ������� (ID, ��������, ��������, �����������) VALUES (1, '������ ���', '������ � ������� ���, ������ ���������� � �������', '������� ����� ����������')
INTO ������� (ID, ��������, ��������, �����������) VALUES (2, '������� �������', '���������� �������, ��� ������ ����� �� �������', '���������� ����� ��������')
INTO ������� (ID, ��������, ��������, �����������) VALUES (3, '������� ������', '�������� � ������� ������, � ������� ������� ������� ��������', '������� ������� ������������')
INTO ������� (ID, ��������, ��������, �����������) VALUES (4, '�����-�������', '����������� �����, ����������� ������� � ����������', '�������� ����� ��������')
INTO ������� (ID, ��������, ��������, �����������) VALUES (5, '������� �����', '������� ������� �����������, ������ ���������� � ����������', '����� ������ ����������')
INTO ������� (ID, ��������, ��������, �����������) VALUES (6, '��������� ��������', '������� ��������, ������ ����������� � ��������� �������', '���������� ����� ��������')
SELECT * FROM dual;

-- ���������� ������� "�������"
INSERT ALL
INTO ������� (ID, �������, ��������, ��������, �����������) VALUES (1, '������ ���', '��������� �����', '������ ���� �������� �������� ���, �������� ������� ��������', '������� ������� ������������')
INTO ������� (ID, �������, ��������, ��������, �����������) VALUES (2, '������� �������', '�������� ����', '�� ��������� ����������� ������� �������� ����, ������� ���� ��������', '������� ����� ����������')
INTO ������� (ID, �������, ��������, ��������, �����������) VALUES (3, '������� ������', '����������� �������� �������', '������� ������ ������������ � ������� ������, ���������� ����', '���������� ����� ��������')
INTO ������� (ID, �������, ��������, ��������, �����������) VALUES (4, '�����-�������', '�������� ��������', '�������� ������� ������� ������ �������� ���������� �����', '�������� ����� ��������')
INTO ������� (ID, �������, ��������, ��������, �����������) VALUES (5, '������� �����', '��������� ���������', '� ������ ���������� �������������� ���������, ������������ �������� ��������� �����������', '����� ������ ����������')
INTO ������� (ID, �������, ��������, ��������, �����������) VALUES (6, '��������� ��������', '�������� ���������', '�������������� �������� ��������� �������� �������� ���� �����', '���������� ����� ��������')
INTO ������� (ID, �������, ��������, ��������, �����������) VALUES (7, '������ ���', '������� � �������', '������� � �������, ������������ ������, �� �� ������� ����', '������� ������� ������������')
INTO ������� (ID, �������, ��������, ��������, �����������) VALUES (8, '������� �������', '����� � �������', '�������� ������������� ������ � ����� ������ ������� �������', '������� ����� ����������')
SELECT * FROM dual;

-- ���������� ������� "�������"
INSERT ALL
INTO ������� (ID, ��������, ��������, �������, ��������, �������) VALUES (1, '������������ ������� ����', '�������� ������� ���� � ������ ����', '����� �������� ��������������', '����������� � ������������', '������ ���')
INTO ������� (ID, ��������, ��������, �������, ��������, �������) VALUES (2, '�������� �������� � �������', '������ ��������, �������� � ������� �������� ����', '����� ������', '����������� � ������������', '������� �������')
INTO ������� (ID, ��������, ��������, �������, ��������, �������) VALUES (3, '����� ������� ����������', '����������� � ������ �������������� ���������� � ������� ������', '������ ������������', '����������� � ������������', '������� �����')
INTO ������� (ID, ��������, ��������, �������, ��������, �������) VALUES (4, '�������� ���������� ���������', '���������� ������ �� ��������� ���������', '��� ���������� ����', '���� ��������', '��������� ��������')
INTO ������� (ID, ��������, ��������, �������, ��������, �������) VALUES (5, '������ ��������� ������', '���������� ��� ������� ������� ������-��������', '������ ���������� �����', '��� ��������', '�����-�������')
INTO ������� (ID, ��������, ��������, �������, ��������, �������) VALUES (6, '������������ ���� ������', '������������ � ������������ ������������� ������ � ������� �������', '���� ���������', '� ������ �� �����������', '������� �������')
INTO ������� (ID, ��������, ��������, �������, ��������, �������) VALUES (7, '������� ������', '���������� ������������ ������� ������', '�������� ��������� �������', '� ������ �� �����������', '������ ���')
SELECT * FROM dual;

-- ���������� ������� "�������� � ��������"
INSERT ALL
INTO ��������_�������_�_�������� (ID, �����, �������, ���������) VALUES (1, '������', '������������ ������� ����', '��')
INTO ��������_�������_�_�������� (ID, �����, �������, ���������) VALUES (2, '�������_��������', '�������� �������� � �������', '���')
INTO ��������_�������_�_�������� (ID, �����, �������, ���������) VALUES (3, '����2007', '����� ������� ����������', '��')
INTO ��������_�������_�_�������� (ID, �����, �������, ���������) VALUES (4, '����2007', '�������� ���������� ���������', '���')
INTO ��������_�������_�_�������� (ID, �����, �������, ���������) VALUES (5, '������_�������', '������ ��������� ������', '��')
INTO ��������_�������_�_�������� (ID, �����, �������, ���������) VALUES (6, '��������_���������', '������������ ���� ������', '���')
INTO ��������_�������_�_�������� (ID, �����, �������, ���������) VALUES (7, '��������_���������', '������� ������', '��')
SELECT * FROM dual;