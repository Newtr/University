--������� �� ���������� ������
CREATE OR REPLACE PROCEDURE get_ticket_count(
  start_date IN DATE,
  end_date IN DATE,
  ticket_count OUT NUMBER
)
IS
BEGIN
  SELECT COUNT(*) INTO ticket_count
  FROM TICKETS
  WHERE START_TIME BETWEEN start_date AND end_date;
END;
--���������� ��������� ������� � ����������� �� ������
CREATE OR REPLACE PROCEDURE get_ticket_count_by_film(
  movie_name IN VARCHAR2,
  ticket_count OUT NUMBER
)
IS
BEGIN
  SELECT COUNT(*) INTO ticket_count
  FROM TICKETS
  WHERE FILM_NAME = movie_name;
END;

CREATE SEQUENCE ticket_sequence START WITH 1 INCREMENT BY 1;
--������� ������
CREATE OR REPLACE PROCEDURE buy_ticket(
  p_film_name VARCHAR2,
  p_hall_id NUMBER,
  p_client_id NUMBER,
  p_price NUMBER,
  p_start_time TIMESTAMP
) AS
  last_ticket_id NUMBER;
  new_ticket_id NUMBER;
BEGIN
  -- ��������� ���������� ID ������
  SELECT MAX(ID) INTO last_ticket_id FROM TICKETS;

  -- ������� ������ ������
  new_ticket_id := last_ticket_id + 1;
  INSERT INTO TICKETS (ID, FILM_NAME, HALL_ID, CLIENT_ID, PRICE, START_TIME)
  VALUES (new_ticket_id, p_film_name, p_hall_id, p_client_id, p_price, p_start_time);

  -- ������ ����������
  COMMIT;

  -- ����� ���������� � ��������� ������
  DBMS_OUTPUT.PUT_LINE('����� ������� ������. ID ������: ' || new_ticket_id);
EXCEPTION
  WHEN OTHERS THEN
    -- ��������� ������
    DBMS_OUTPUT.PUT_LINE('������ ��� ������� ������: ' || SQLERRM);
    ROLLBACK;
END;
--������� ������
CREATE OR REPLACE FUNCTION return_ticket(
  p_ticket_id NUMBER
) RETURN BOOLEAN AS
BEGIN
  -- �������� ������
  DELETE FROM TICKETS WHERE ID = p_ticket_id;

  -- ������ ����������
  COMMIT;

  -- ����������� �������� TRUE, ���� �������� ������ �������
  RETURN TRUE;
EXCEPTION
  WHEN OTHERS THEN
    -- ��������� ������
    DBMS_OUTPUT.PUT_LINE('������ ��� �������� ������: ' || SQLERRM);
    ROLLBACK;
    RETURN FALSE;
END;
--������� ������ � ��� ��������������
CREATE OR REPLACE PROCEDURE buy_ticket_with_extras(
  p_film_name VARCHAR2,
  p_hall_id NUMBER,
  p_client_id NUMBER,
  p_price NUMBER,
  p_start_time TIMESTAMP
) AS
  last_ticket_id NUMBER;
  new_ticket_id NUMBER;
  calculated_price NUMBER;
BEGIN
  -- ��������� ���������� ID ������
  SELECT MAX(ID) INTO last_ticket_id FROM TICKETS;

  -- ������� ������ ������
  new_ticket_id := last_ticket_id + 1;

  -- ������ ���� � ��������������� ������������� (�������� ����)
  calculated_price := p_price * 2;

  INSERT INTO TICKETS (ID, FILM_NAME, HALL_ID, CLIENT_ID, PRICE, START_TIME)
  VALUES (new_ticket_id, p_film_name, p_hall_id, p_client_id, calculated_price, p_start_time);

  -- ������ ����������
  COMMIT;

  -- �������� � �������������� �������������� ������������
  IF calculated_price > 0 THEN
    DBMS_OUTPUT.PUT_LINE('�� ������ ����� � ��������������� �������������.');
    DBMS_OUTPUT.PUT_LINE('��� ������� �����, � ����� ��� ������ ���������� ����� ����������.');
  END IF;
  
  -- ����� ���������� � ��������� ������
  DBMS_OUTPUT.PUT_LINE('����� ������� ������. ID ������: ' || new_ticket_id);
EXCEPTION
  WHEN OTHERS THEN
    -- ��������� ������
    DBMS_OUTPUT.PUT_LINE('������ ��� ������� ������: ' || SQLERRM);
    ROLLBACK;
END;
--�������� �����
CREATE OR REPLACE PROCEDURE add_review(
  p_film_name VARCHAR2,
  p_client_id NUMBER,
  p_rating NUMBER,
  p_comment VARCHAR2
) AS
  film_count NUMBER;
BEGIN
  -- �������� ������������� ������
  SELECT COUNT(*) INTO film_count FROM TICKETS WHERE FILM_NAME = p_film_name;

  IF film_count = 0 THEN
    DBMS_OUTPUT.PUT_LINE('����� � ��������� ' || p_film_name || ' �� ������.');
    RETURN;
  END IF;

  -- ���������� ������
  INSERT INTO REVIEWS (FILM_NAME, CLIENT_ID, RATING, REVIEW_TEXT)
  VALUES (p_film_name, p_client_id, p_rating, p_comment);

  -- ������ ����������
  COMMIT;

  DBMS_OUTPUT.PUT_LINE('����� ������� ��������.');
EXCEPTION
  WHEN OTHERS THEN
    -- ��������� ������
    DBMS_OUTPUT.PUT_LINE('������ ��� ���������� ������: ' || SQLERRM);
    ROLLBACK;
END;
--�������� ������
CREATE OR REPLACE PROCEDURE delete_review(
  p_review_text VARCHAR2
) AS
  v_review_count NUMBER;
BEGIN
  -- �������� ������������� ������
  SELECT COUNT(*) INTO v_review_count FROM REVIEWS WHERE REVIEW_TEXT = p_review_text;

  IF v_review_count = 0 THEN
    DBMS_OUTPUT.PUT_LINE('����� � ������� "' || p_review_text || '" �� ������.');
    RETURN;
  END IF;

  -- �������� ������
  DELETE FROM REVIEWS WHERE REVIEW_TEXT = p_review_text;

  -- ������ ����������
  COMMIT;

  DBMS_OUTPUT.PUT_LINE('����� ������� ������.');
EXCEPTION
  WHEN OTHERS THEN
    -- ��������� ������
    DBMS_OUTPUT.PUT_LINE('������ ��� �������� ������: ' || SQLERRM);
    ROLLBACK;
END;
--�������� �����
CREATE OR REPLACE PROCEDURE ADD_FILM (
    p_film_name IN VARCHAR2,
    p_description IN VARCHAR2,
    p_release_date IN DATE,
    p_duration IN NUMBER,
    p_age_restriction IN VARCHAR2,
    p_actor_1 IN VARCHAR2,
    p_actor_2 IN VARCHAR2,
    p_actor_3 IN VARCHAR2,
    p_director IN VARCHAR2,
    p_review_text IN VARCHAR2,
    p_rating IN NUMBER,
    p_genre IN VARCHAR2,
    p_poster_path IN VARCHAR2
)
IS
    v_client_id NUMBER := NULL;
    v_review_text VARCHAR2(500) := p_review_text;
    v_film_name VARCHAR2(50) := p_film_name;
    v_poster BFILE;
BEGIN
    -- ��������� ����� � ������� REVIEWS
    INSERT INTO REVIEWS (FILM_NAME, CLIENT_ID, RATING, REVIEW_TEXT)
    VALUES (v_film_name, v_client_id, p_rating, v_review_text);

    -- ��������� ���������� � ������ � ������� FILMS
    INSERT INTO FILMS (TITLE, DESCRIPTION, RELEASE_DATE, DURATION, AGE_RESTRICTION,
                       FILM_ACTOR_1, FILM_ACTOR_2, FILM_ACTOR_3, FILM_DIRECTORS,
                       FILM_REVIEW, GENRE, POSTER)
    VALUES (p_film_name, p_description, p_release_date, p_duration, p_age_restriction,
            p_actor_1, p_actor_2, p_actor_3, p_director, v_review_text, p_genre,
            BFILENAME('D:\Photos', p_poster_path));
END;
--�������� ������
CREATE OR REPLACE PROCEDURE DELETE_FILM (
    p_film_name IN VARCHAR2
)
IS
BEGIN

UPDATE FILMS SET FILM_REVIEW = NULL WHERE TITLE = p_film_name;

    -- ������� ����� ��������� � ������� �� ������� REVIEWS
    DELETE FROM REVIEWS WHERE FILM_NAME = p_film_name;

    -- ������� ����� �� ������� FILMS
    DELETE FROM FILMS WHERE TITLE = p_film_name;

    COMMIT;
EXCEPTION
    WHEN OTHERS THEN
        -- ������������ ������, ���� ���������
        ROLLBACK;
        RAISE;
END;
--Actors to XML
CREATE OR REPLACE PROCEDURE ACTORS_TO_XML
IS
    xml_data CLOB;
    file_handle UTL_FILE.FILE_TYPE;
    file_path VARCHAR2(100) := 'D:\Photos\Actors_info.xml';
BEGIN
    SELECT DBMS_XMLGEN.GETXML('SELECT * FROM ACTORS') INTO xml_data FROM DUAL;

    -- ��������� ���� ��� ������
    file_handle := UTL_FILE.FOPEN('MY_DIR', 'Actors_info.xml', 'W');

    -- ���������� XML-������ � ����
    UTL_FILE.PUT_RAW(file_handle, UTL_RAW.CAST_TO_RAW(xml_data));

    -- ��������� ����
    UTL_FILE.FCLOSE(file_handle);

    DBMS_OUTPUT.PUT_LINE('XML ���� ������� ������: ' || file_path);
EXCEPTION
    WHEN OTHERS THEN
        -- ������������ ������, ���� ���������
        DBMS_OUTPUT.PUT_LINE('������ ��� �������� XML �����: ' || SQLERRM);
        RAISE;
END;
--XML to ACTORS
CREATE OR REPLACE PROCEDURE XML_TO_ACTORS AS
  -- ���� � XML �����
  xml_path VARCHAR2(100) := 'Actors_info.xml';
  
  -- XMLType ���������� ��� ������ XML �����
  xml_data XMLType;
  
BEGIN
  -- ������ XML ����� � ���������� xml_data
  xml_data := XMLType(BFILENAME('MY_DIR', xml_path), NLS_CHARSET_ID('UTF8'));

  -- ���������� ������� ACTORS �� XML ������
  INSERT INTO ACTORS (NAME, BIRTH_DATE)
  SELECT
    extractvalue(value(p), '/ROW/NAME') AS NAME,
    to_date(extractvalue(value(p), '/ROW/BIRTH_DATE'), 'DD-MM-YYYY') AS BIRTH_DATE
  FROM
    TABLE(xmlsequence(xml_data.extract('/ROWSET/ROW'))) p;

  COMMIT;
  
  DBMS_OUTPUT.PUT_LINE('XML data successfully loaded into ACTORS table.');
EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('Error occurred: ' || SQLERRM);
    ROLLBACK;
END;
--100000 Clients
CREATE OR REPLACE PROCEDURE INSERT_100000_CLIENTS AS
  v_phone_prefix VARCHAR2(4) := '+375'; -- ������� ����������� ������
  v_phone_length NUMBER := 9; -- ����� ������ �������� ��� ��������
  v_phone_number VARCHAR2(20);
BEGIN
  FOR i IN 16..100000 LOOP
    v_phone_number := v_phone_prefix || LPAD(TRUNC(DBMS_RANDOM.VALUE(0, POWER(10, v_phone_length))), v_phone_length, '0');
    
    INSERT INTO CLIENTS (ID, NAME, EMAIL, PHONE)
    VALUES (i, 'Client ' || i, 'client' || i || '@example.com', v_phone_number);
  END LOOP;
  
  COMMIT;
  DBMS_OUTPUT.PUT_LINE('100000 clients successfully inserted into CLIENTS table.');
EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('Error occurred: ' || SQLERRM);
    ROLLBACK;
END;