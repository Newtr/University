-- ������� ��� �������� ��������
CREATE INDEX IDX_�������_����_������ ON ��������_��������(����_������_��������_��������);
CREATE INDEX IDX_�������_����_��������� ON ��������_��������(����_���������_��������_��������);

-- ������� ��� ����������
CREATE INDEX IDX_���������_�������� ON ����������(��������);
CREATE INDEX IDX_���������_���� ON ����������(����);
CREATE INDEX IDX_���������_����� ON ����������(�����);

-- ������� ��� ������� �������������
CREATE INDEX IDX_�������_���������� ON �������_�������������(����������);
CREATE INDEX IDX_�������_������� ON �������_�������������(�������������_��������);

-- ������� ��� �������������
CREATE INDEX IDX_�������������_�������� ON �������������(�������������_��������);
CREATE INDEX IDX_�������������_��������� ON �������������(���������_�����������_�������������);

-- ������� ��� ��������
CREATE INDEX IDX_��������_����� ON ��������(�����);
