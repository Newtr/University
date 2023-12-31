DROP CLUSTER ABC;
--TASK 2
CREATE GLOBAL TEMPORARY TABLE temp_table (
    id NUMBER,
    data VARCHAR2(100)
) ON COMMIT DELETE ROWS;

INSERT INTO temp_table VALUES (1, 'Temp data');

SELECT * FROM temp_table;
COMMIT;

--TASK 3
CREATE SEQUENCE s1 START WITH 1000 INCREMENT BY 10 NOMINVALUE NOMAXVALUE NOCYCLE NOCACHE NOORDER;
SELECT s1.NEXTVAL FROM dual;
SELECT s1.CURRVAL FROM dual;

--TASK 4
CREATE SEQUENCE s2 START WITH 10 INCREMENT BY 10 MAXVALUE 100 NOCYCLE;
DROP SEQUENCE s2;
SELECT s2.NEXTVAL FROM dual;

SELECT * FROM USER_SEQUENCES;

--TASK 5
CREATE SEQUENCE s3 START WITH 10 INCREMENT BY -10 MINVALUE -100 MAXVALUE 10 NOCYCLE ORDER;
SELECT s3.NEXTVAL FROM dual;

--TASK 6
CREATE SEQUENCE s4 START WITH 1 INCREMENT BY 1 MINVALUE 1 MAXVALUE 10 CYCLE CACHE 5 NOORDER;
SELECT s4.NEXTVAL FROM dual;

--TASK 7
SELECT sequence_name FROM all_sequences WHERE sequence_owner = 'SYS';

SELECT privilege FROM dba_sys_privs WHERE grantee = 'SYS';

GRANT CREATE DATABASE LINK, CREATE PUBLIC DATABASE LINK, DROP PUBLIC DATABASE LINK TO SYS;

GRANT CREATE CLUSTER TO SYS;
GRANT CREATE MATERIALIZED VIEW TO SYS;
 

--TASK 8
create table T1 (
        N1 NUMBER(20),
        N2 NUMBER(20),
        N3 NUMBER(20),
        N4 NUMBER(20))
        cache storage(buffer_pool keep);
        
BEGIN
    FOR i IN 1..7 LOOP
        INSERT INTO T1 (N1, N2, N3, N4) VALUES (S1.NEXTVAL, S2.NEXTVAL, S3.NEXTVAL, S4.NEXTVAL);
    END LOOP;
COMMIT;
END;
/

SELECT * FROM T1;

--TASK 9
CREATE CLUSTER ABC (
    X NUMBER(10),
    V VARCHAR2(12)
) SIZE 200 HASHKEYS 10000;

--TASK 10
CREATE TABLE A (
    XA NUMBER(10),
    VA VARCHAR2(12),
    EXTRA_COLUMN VARCHAR2(50)
) CLUSTER ABC (XA, VA);

--TASK 11
CREATE TABLE B (
    XB NUMBER(10),
    VB VARCHAR2(12),
    EXTRA_COLUMN VARCHAR2(50)
) CLUSTER ABC (XB, VB);

--TASK 12
CREATE TABLE C (
    XC NUMBER(10),
    VC VARCHAR2(12),
    EXTRA_COLUMN VARCHAR2(50)
) CLUSTER ABC (XC, VC);

--TASK 13
SELECT * FROM USER_TABLES WHERE TABLE_NAME IN ('T1', 'A', 'B', 'C');
SELECT * FROM USER_CLUSTERS WHERE CLUSTER_NAME = 'ABC';
SELECT * FROM USER_CLUSTERS;

--TASK 14
CREATE SYNONYM my_c_syn_2 FOR SYS.A;
SELECT * FROM my_c_syn_2;

--TASK 15
CREATE PUBLIC SYNONYM public_b_syn_2 FOR SYS.B;
SELECT * FROM public_b_syn_2;

--TASK 16
CREATE TABLE A1 (
    id NUMBER PRIMARY KEY,
    data VARCHAR2(100)
);

INSERT INTO A1 VALUES (2, 'Data for table A');
INSERT INTO A1 VALUES (3, 'Data for table A');
INSERT INTO A1 VALUES (4, 'Data for table A');
INSERT INTO A1 VALUES (5, 'Data for table A');


CREATE TABLE B1 (
    id NUMBER,
    a_id NUMBER REFERENCES A1(id),
    data VARCHAR2(100)
);

INSERT INTO B1 VALUES (2, 1, 'Data for table B');
INSERT INTO B1 VALUES (3, 1, 'Data for table B');
INSERT INTO B1 VALUES (4, 1, 'Data for table B');
INSERT INTO B1 VALUES (6, 5, 'Data for table B');


SELECT A1.id, A1.data, B1.data
FROM A1
INNER JOIN B1 ON A1.id = B1.a_id;

SELECT * FROM A1;
SELECT * FROM B1;


CREATE VIEW V1 AS
SELECT A1.id, A1.data as data_a1, B1.data as data_b1
FROM A1
INNER JOIN B1 ON A1.id = B1.a_id;


SELECT * FROM V1;

--TASK 17
CREATE MATERIALIZED VIEW MV_INSCORE
REFRESH COMPLETE ON DEMAND
NEXT SYSDATE + NUMTODSINTERVAL(2, 'MINUTE')
AS SELECT A1.id, A1.data as a1_data, B1.data as b1_data
FROM A1
INNER JOIN B1 ON A1.id = B1.a_id;

CREATE MATERIALIZED VIEW MV_INS
    BUILD IMMEDIATE
    REFRESH COMPLETE
    NEXT SYSDATE + (2/1440)
    AS
        SELECT A1.id, A1.data as a1_data, B1.data as b1_data
        FROM A1
        INNER JOIN B1 ON A1.id = B1.a_id;

SELECT * FROM MV_INS;


EXECUTE DBMS_MVIEW.REFRESH('MV_INSCORE');

SELECT * FROM MV_INSCORE;

DROP MATERIALIZED VIEW MV_INSCORE;
SELECT * FROM MV_INSCORE;
GRANT CREATE PUBLIC DATABASE LINK TO INSCORE;

--TASK 18
CREATE DATABASE LINK D_LINK4
CONNECT TO SYS IDENTIFIED BY 23349110
USING '(DESCRIPTION=
(ADDRESS=(PROTOCOL=TCP)(HOST=)(PORT=1522))
(CONNECT_DATA=(SERVICE_NAME=XE)))';

SELECT * FROM T1234;

DROP DATABASE LINK D_LINK4;

CREATE DATABASE LINK D_LINK4
CONNECT TO U1234 IDENTIFIED BY pass
USING '(DESCRIPTION=
(ADDRESS=(PROTOCOL=TCP)(HOST=192.168.137.1)(PORT=1521))
(CONNECT_DATA=(SERVICE_NAME=XEPDB1)))';

SELECT * FROM SYS.T1234@D_LINK4;

CREATE TABLE T1234@D_LINK4;

INSERT INTO 
select * from T1@D_LINK4;
COMMIT;
insert into SYS.T1234@D_LINK4 values ( 21);
COMMIT;

DROP TABLE temp_table;
DROP SEQUENCE s1;
DROP SEQUENCE s2;
DROP SEQUENCE s3;