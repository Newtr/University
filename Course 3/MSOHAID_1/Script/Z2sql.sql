DECLARE
   -- Коллекция для t1 (Сотрудники_obj)
   TYPE t1_collection IS TABLE OF Сотрудники_obj%ROWTYPE INDEX BY PLS_INTEGER;

   -- Коллекция для t2 (Собеседования_obj)
   TYPE t2_collection IS TABLE OF Собеседования_obj%ROWTYPE INDEX BY PLS_INTEGER;

   -- Коллекция K1 (на основе t1)
   k1_collection t1_collection;

   -- Коллекция K2 (вложенная в K1, на основе t2)
   k2_collection t2_collection;

   -- Итераторы для циклов
   i PLS_INTEGER;
   j PLS_INTEGER;

BEGIN
   -- a. Создать коллекцию K1 на основе t1
   SELECT *
   BULK COLLECT INTO k1_collection
   FROM Сотрудники_obj t1;

   -- Для каждого элемента K1 создать вложенную коллекцию K2 на основе t2
   FOR i IN 1..k1_collection.COUNT LOOP
      SELECT *
      BULK COLLECT INTO k2_collection
      FROM Собеседования_obj t2
      WHERE t2.ИДЕНТИФИКАТОР_ВАКАНСИИ = k1_collection(i).КОНТРАКТ;

      -- b. Выяснить для каких коллекций K1 коллекции K2 пересекаются
      IF k2_collection.COUNT > 0 THEN
         DBMS_OUTPUT.PUT_LINE('Коллекции K1 и K2 пересекаются для элемента ' || k1_collection(i).ИДЕНТИФИКАТОР_СОТРУДНИКА);
      END IF;

      -- c. Выяснить, является ли членом коллекции K1 какой-то произвольный элемент
      FOR j IN 1..k1_collection.COUNT LOOP
         IF k1_collection(j).ИДЕНТИФИКАТОР_СОТРУДНИКА = k1_collection(i).ИДЕНТИФИКАТОР_СОТРУДНИКА THEN
            DBMS_OUTPUT.PUT_LINE('Элемент присутствует в коллекции K1: ' || k1_collection(i).ИДЕНТИФИКАТОР_СОТРУДНИКА);
         END IF;
      END LOOP;

      -- d. Найти пустые коллекции K1
      IF k2_collection.COUNT = 0 THEN
         DBMS_OUTPUT.PUT_LINE('Коллекция K1 пуста для элемента ' || k1_collection(i).ИДЕНТИФИКАТОР_СОТРУДНИКА);
      END IF;

      -- e. Для двух элементов коллекции K1 обменять их атрибуты K2
      IF i < k1_collection.COUNT THEN
         -- Обменять атрибуты между двумя элементами K1
         k1_collection(i).КОНТРАКТ := k1_collection(i+1).КОНТРАКТ;
         k1_collection(i+1).КОНТРАКТ := k1_collection(i).КОНТРАКТ;
      END IF;
   END LOOP;
END;
/
