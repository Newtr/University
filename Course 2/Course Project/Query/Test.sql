SET SERVEROUTPUT ON SIZE UNLIMITED

alter session set "_ORACLE_SCRIPT"=true;

SELECT * FROM ALL_TABLES WHERE TABLE_NAME = 'HALLS';

SELECT * FROM HALLS;
SELECT * FROM ACTORS;
SELECT * FROM CLIENTS;
SELECT * FROM DIRECTORS;
SELECT * FROM TICKETS;
SELECT * FROM REVIEWS;
SELECT * FROM FILMS;

select user from dual;

BEGIN
    FILL_FILMS;
END;

DROP PROCEDURE POPULATE_DIRECTORS;
DELETE FROM ACTORS;


DROP TABLE HALLS CASCADE CONSTRAINTS;
DROP TABLE ACTORS CASCADE CONSTRAINTS;
DROP TABLE CLIENTS CASCADE CONSTRAINTS;
DROP TABLE DIRECTORS CASCADE CONSTRAINTS;
DROP TABLE TICKETS CASCADE CONSTRAINTS;
DROP TABLE REVIEWS CASCADE CONSTRAINTS;
DROP TABLE FILMS CASCADE CONSTRAINTS;

--������� �� ���������� ������
DECLARE
  total_tickets NUMBER;
BEGIN
  get_ticket_count(
    TO_DATE('2023-05-25', 'YYYY-MM-DD'), -- ������ ��������� ����
    TO_DATE('2023-05-26', 'YYYY-MM-DD'), -- ������ �������� ����
    total_tickets
  );
  
  DBMS_OUTPUT.PUT_LINE('���������� ��������� �������: ' || total_tickets);
END;
--���������� ��������� ������� � ����������� �� ������
DECLARE
  movie_tickets NUMBER;
BEGIN
  get_ticket_count_by_film('Fight Club', movie_tickets);
  
  DBMS_OUTPUT.PUT_LINE('���������� ��������� ������� ��� ������: ' || movie_tickets);
END;
--������� ������
BEGIN
  BUY_TICKET('Fight Club', 3, 7, 15, TO_TIMESTAMP('2023-05-26 23:30:00', 'YYYY-MM-DD HH24:MI:SS'));
END;
--������� ������
DECLARE
  is_successful BOOLEAN;
BEGIN
  is_successful := RETURN_TICKET(3);
  IF is_successful THEN
    DBMS_OUTPUT.PUT_LINE('����� ������� ���������.');
  ELSE
    DBMS_OUTPUT.PUT_LINE('������ ��� �������� ������.');
  END IF;
END;
--������� ������ � ���. ��������������
BEGIN
  BUY_TICKET_WITH_EXTRAS('Fight Club', 3, 9, 22, TO_TIMESTAMP('05.19.2023 17:30', 'MM.DD.YYYY HH24:MI'));
END;
--�������� �����
BEGIN
  ADD_REVIEW('Fight Club', 8, 5, '�����');
END;
--�������� ������
BEGIN
  DELETE_REVIEW('�����');
END;
--�������� �����
BEGIN
    ADD_FILM('Help me2', 'PLS help me', TO_DATE('2023-05-18', 'YYYY-MM-DD'), 
             120, 'PG-13', 'Jane Smith', 'Daniel Miller', 'Sophia Hernandez', 'Woody Allen', '2',
             8, 'Action', 'The_Godfather.jpg');
END;
--�������� ������
BEGIN
    DELETE_FILM('Help me');
END;

CREATE DIRECTORY my_dir AS 'D:\Photos';
GRANT READ, WRITE ON DIRECTORY my_dir TO sys;
--Actors to XML
BEGIN
  ACTORS_TO_XML;
END;
--XML to Actors
BEGIN
  XML_TO_ACTORS;
END;
--100000 Clients
BEGIN
  INSERT_100000_CLIENTS;
END;
