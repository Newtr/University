--TASK 1
SELECT * FROM sqlite_master;

SELECT * FROM SALESREPS WHERE EMPL_NUM = 120;
SELECT * FROM ORDERS WHERE ORDER_NUM = 124456;




SELECT * FROM OFFICES;

CREATE TRIGGER insert_into_view_trigger INSTEAD OF INSERT ON EMP_OFFICES_VIEW
FOR EACH ROW
BEGIN
    INSERT INTO SALESREPS (EMPL_NUM, NAME, AGE, REP_OFFICE, TITLE, HIRE_DATE, MANAGER, QUOTA, SALES) 
    VALUES (NEW.EMPL_NUM, NEW.NAME, NEW.AGE, NEW.REP_OFFICE, NEW.TITLE, NEW.HIRE_DATE, NEW.MANAGER, NEW.QUOTA, NEW.SALES);
    
    INSERT INTO OFFICES (OFFICE, CITY, REGION, MGR, TARGET, SALES) 
    VALUES (NEW.OFFICE, NEW.CITY, NEW.REGION, NEW.MGR, NEW.TARGET, NEW.SALES);
END;


--TASK 2.1
CREATE VIEW CustomersWithHighOrders AS
SELECT C.* 
FROM CUSTOMERS C
JOIN ORDERS O ON C.CUST_NUM = O.CUST
WHERE O.AMOUNT > 1000;

CREATE TRIGGER audit_trigger AFTER UPDATE ON SALESREPS
FOR EACH ROW
BEGIN
    INSERT INTO AUDIT (EMPL_NUM, NAME, AGE, REP_OFFICE, TITLE, HIRE_DATE, MGR, QUOTA, SALES, CHANGE_DATE) 
    VALUES (OLD.EMPL_NUM, OLD.NAME, OLD.AGE, OLD.REP_OFFICE, OLD.TITLE, OLD.HIRE_DATE, OLD.MGR, OLD.QUOTA, OLD.SALES, datetime('now'));
END;

--TASK 2.2
CREATE VIEW EmployeesAndOffices AS
SELECT S.*, O.*
FROM SALESREPS S
JOIN OFFICES O ON S.REP_OFFICE = O.OFFICE;

--TASK 2.3
CREATE VIEW Orders2008 AS
SELECT * 
FROM ORDERS 
WHERE strftime('%Y', ORDER_DATE) = '2008';

--TASK 2.4
CREATE VIEW EmployeesWithoutOrders AS
SELECT S.*
FROM SALESREPS S
LEFT JOIN ORDERS O ON S.EMPL_NUM = O.REP
WHERE O.ORDER_NUM IS NULL;

--TASK 2.5
CREATE VIEW PopularProducts AS
SELECT P.*, COUNT(*) as OrderCount
FROM PRODUCTS P
JOIN ORDERS O ON P.MFR_ID = O.MFR AND P.PRODUCT_ID = O.PRODUCT
GROUP BY P.MFR_ID, P.PRODUCT_ID
ORDER BY OrderCount DESC;

--TASK 3
CREATE TEMP TABLE TempTable AS SELECT * FROM PRODUCTS;

INSERT INTO TempTable SELECT * FROM PRODUCTS;

SELECT * FROM TempTable;

--TASK 4
CREATE TEMP VIEW TempView AS SELECT * FROM PRODUCTS;

SELECT * FROM TempView;

--TASK 5
----------------------

--TASK 3.14. Индекс на столбце AMOUNT в таблице ORDERS может улучшить этот запрос.
EXPLAIN QUERY PLAN SELECT DISTINCT REP, AMOUNT FROM ORDERS WHERE AMOUNT > 10000;

CREATE INDEX idx_orders_amount ON ORDERS (AMOUNT);
DROP INDEX idx_orders_amount;

----------------------

--TASK 3.16. Индекс на столбце PRICE в таблице PRODUCTS может улучшить этот запрос.
EXPLAIN QUERY PLAN SELECT MFR_ID, PRODUCT_ID, DESCRIPTION, MAX(PRICE) FROM PRODUCTS GROUP BY MFR_ID;

CREATE INDEX idx_products_price ON PRODUCTS (PRICE);
DROP INDEX idx_products_price;

----------------------

--TASK 3.19. Индекс на столбце AGE в таблице SALESREPS может улучшить этот запрос.
EXPLAIN QUERY PLAN SELECT * FROM SALESREPS S1 WHERE EXISTS (SELECT * FROM SALESREPS S2 WHERE S1.AGE = S2.AGE AND S1.EMPL_NUM <> S2.EMPL_NUM);

CREATE INDEX idx_salesreps_age ON SALESREPS (AGE);
DROP INDEX idx_salesreps_age;

----------------------

--TASK 3.20 Индекс на столбце PRICE в таблице PRODUCTS может улучшить этот запрос.
EXPLAIN QUERY PLAN SELECT P.DESCRIPTION FROM PRODUCTS P JOIN ORDERS O ON P.PRODUCT_ID = O.PRODUCT JOIN CUSTOMERS C ON O.CUST = C.CUST_NUM WHERE C.COMPANY = 'First Corp.';

--Этот индекс уже создан для запроса 3.16

----------------------

--TASK 3.24. Индексы на столбцах REP_OFFICE в таблице SALESREPS и AMOUNT в таблице ORDERS могут улучшить этот запрос.
EXPLAIN QUERY PLAN SELECT S.REP_OFFICE, SUM(O.AMOUNT) 
FROM ORDERS O
JOIN SALESREPS S ON O.REP = S.EMPL_NUM
GROUP BY S.REP_OFFICE 
ORDER BY SUM(O.AMOUNT) DESC;

CREATE INDEX idx_salesreps_rep_office ON SALESREPS (REP_OFFICE);
-- Индекс на AMOUNT уже был создан для запроса 3.14

DROP INDEX idx_salesreps_rep_office;

----------------------

--TASK 3.35. Индексы на столбцах CUST и ORDER_DATE в таблице ORDERS могут улучшить этот запрос.

EXPLAIN QUERY PLAN SELECT C.* FROM CUSTOMERS C WHERE EXISTS (SELECT * FROM ORDERS WHERE CUST = C.CUST_NUM AND strftime('%Y', ORDER_DATE) = '2007') AND EXISTS (SELECT * FROM ORDERS WHERE CUST = C.CUST_NUM AND strftime('%Y', ORDER_DATE) = '2008');

CREATE INDEX idx_orders_cust ON ORDERS (CUST);
CREATE INDEX idx_orders_order_date ON ORDERS (ORDER_DATE);

DROP INDEX idx_orders_cust;
DROP INDEX idx_orders_order_date;

--TASK 6
CREATE TABLE AUDIT (
    EMPL_NUM INTEGER,
    NAME TEXT,
    AGE INTEGER,
    REP_OFFICE INTEGER,
    TITLE TEXT,
    HIRE_DATE TEXT,
    MGR INTEGER,
    QUOTA REAL,
    SALES REAL,
    CHANGE_DATE TEXT
);

SELECT * FROM AUDIT;

UPDATE SALESREPS SET NAME = 'TEST6' WHERE TITLE = 'TEST';

CREATE TRIGGER audit_trigger AFTER UPDATE ON SALESREPS
FOR EACH ROW
BEGIN
    INSERT INTO AUDIT (EMPL_NUM, NAME, AGE, REP_OFFICE, TITLE, HIRE_DATE, MGR, QUOTA, SALES, CHANGE_DATE) 
    VALUES (OLD.EMPL_NUM, OLD.NAME, OLD.AGE, OLD.REP_OFFICE, OLD.TITLE, OLD.HIRE_DATE, OLD.MANAGER, OLD.QUOTA, OLD.SALES, datetime('now'));
END;

--TASK 7
CREATE TRIGGER empls_offices_trigger INSTEAD OF INSERT ON EmployeesAndOffices
BEGIN

INSERT INTO OFFICES (OFFICE, CITY, REGION, MGR, TARGET, SALES)
  SELECT 23, NEW.CITY, NEW.REGION, 106, 888888, 777777;
  
  INSERT INTO SALESREPS (EMPL_NUM, NAME, AGE, REP_OFFICE, TITLE, HIRE_DATE, MANAGER, QUOTA, SALES)
  SELECT 199, NEW.NAME, 35, 23, 'Sales Rep', date('now'), 106, 200000, 188000;
END;

INSERT INTO EmployeesAndOffices (NAME, CITY, REGION)
VALUES ('Nikita', 'Minsk', 'Eastern');
select * from OFFICES; 
select * from SALESREPS;
select * from EmployeesAndOffices;
--TASK 8
begin EXCLUSIVE TRANSACTION;
select sum(ORDERS.AMOUNT) from ORDERS where REP = 110;
insert into ORDERS values(113039,'2008-01-30',2107,110,'ACI','4100Z',9,22500.00);
select sum(ORDERS.AMOUNT) from ORDERS where REP = 110;
commit;

--TASK 9
BEGIN TRANSACTION A;
	INSERT INTO SALESREPS VALUES (120,'Nikita Ilyin',49,22,'Sales Rep','2006-11-14',108,300000.00,186042.00);
	BEGIN TRANSACTION B;
		INSERT INTO ORDERS VALUES (124456, '2008-01-30', 2108, 120, 'ACI', '4100Z', 10, 23500.00);
	COMMIT TRANSACTION B;
COMMIT TRANSACTION A;

--TASK 10
BEGIN TRANSACTION;
SAVEPOINT A;
	INSERT INTO SALESREPS VALUES (120,'Nikita Ilyin',49,22,'Sales Rep','2006-11-14',108,300000.00,186042.00);
RELEASE SAVEPOINT A;

SAVEPOINT B;
	INSERT INTO ORDERS VALUES (124456, '2008-01-30', 2108, 120, 'ACI', '4100Z', 10, 23500.00);
	ROLLBACK TO B;
ROLLBACK TRANSACTION;
COMMIT TRANSACTION;

SELECT * FROM ORDERS WHERE ORDER_NUM = 124456;
SELECT * FROM SALESREPS WHERE EMPL_NUM = 120;