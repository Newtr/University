DECLARE
   -- ��������� ��� t1 (����������_obj)
   TYPE t1_collection IS TABLE OF ����������_obj%ROWTYPE INDEX BY PLS_INTEGER;

   -- ��������� ��� t2 (�������������_obj)
   TYPE t2_collection IS TABLE OF �������������_obj%ROWTYPE INDEX BY PLS_INTEGER;

   -- ��������� K1 (�� ������ t1)
   k1_collection t1_collection;

   -- ��������� K2 (��������� � K1, �� ������ t2)
   k2_collection t2_collection;

   -- ��������� ��� ������
   i PLS_INTEGER;
   j PLS_INTEGER;

BEGIN
   -- a. ������� ��������� K1 �� ������ t1
   SELECT *
   BULK COLLECT INTO k1_collection
   FROM ����������_obj t1;

   -- ��� ������� �������� K1 ������� ��������� ��������� K2 �� ������ t2
   FOR i IN 1..k1_collection.COUNT LOOP
      SELECT *
      BULK COLLECT INTO k2_collection
      FROM �������������_obj t2
      WHERE t2.�������������_�������� = k1_collection(i).��������;

      -- b. �������� ��� ����� ��������� K1 ��������� K2 ������������
      IF k2_collection.COUNT > 0 THEN
         DBMS_OUTPUT.PUT_LINE('��������� K1 � K2 ������������ ��� �������� ' || k1_collection(i).�������������_����������);
      END IF;

      -- c. ��������, �������� �� ������ ��������� K1 �����-�� ������������ �������
      FOR j IN 1..k1_collection.COUNT LOOP
         IF k1_collection(j).�������������_���������� = k1_collection(i).�������������_���������� THEN
            DBMS_OUTPUT.PUT_LINE('������� ������������ � ��������� K1: ' || k1_collection(i).�������������_����������);
         END IF;
      END LOOP;

      -- d. ����� ������ ��������� K1
      IF k2_collection.COUNT = 0 THEN
         DBMS_OUTPUT.PUT_LINE('��������� K1 ����� ��� �������� ' || k1_collection(i).�������������_����������);
      END IF;

      -- e. ��� ���� ��������� ��������� K1 �������� �� �������� K2
      IF i < k1_collection.COUNT THEN
         -- �������� �������� ����� ����� ���������� K1
         k1_collection(i).�������� := k1_collection(i+1).��������;
         k1_collection(i+1).�������� := k1_collection(i).��������;
      END IF;
   END LOOP;
END;
/
