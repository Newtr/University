--WORKS!
CREATE OR REPLACE PROCEDURE FILL_HALLS AS
BEGIN
  FOR i IN 1..10 LOOP
    INSERT INTO HALLS (HALL_NUMBER, SEATS_COUNT)
    VALUES (i, ROUND(DBMS_RANDOM.VALUE(50, 200))); -- Random seat count between 50 and 200
  END LOOP;
  COMMIT;
END;

--WORKS!
CREATE OR REPLACE PROCEDURE FILL_ACTORS AS
  -- Array of actor names
  TYPE actor_name_array IS TABLE OF VARCHAR2(50);
  actor_names actor_name_array := actor_name_array(
    'Ryan Gosling', 'Brad Pitt', 'Leonardo DiCaprio', 'Tom Hanks', 'Robert Downey Jr.',
    'Chris Hemsworth', 'Dwayne Johnson', 'Johnny Depp', 'Emma Stone', 'Jennifer Lawrence'
  );
BEGIN
  FOR i IN 1..10 LOOP
    INSERT INTO ACTORS (NAME, BIRTH_DATE)
    VALUES (actor_names(i), TRUNC(SYSDATE - DBMS_RANDOM.VALUE(8000, 25000))); -- Random birth date between 22 and 68 years ago
  END LOOP;
  COMMIT;
END;

--WORKS!
CREATE OR REPLACE PROCEDURE FILL_CLIENTS AS
    names_arr    SYS.ODCIVARCHAR2LIST := SYS.ODCIVARCHAR2LIST(
                                            'Roman Tyshkevich',
                                            'Nikita Pashkevich',
                                            'Grisha Poolkan',
                                            'Hecarim Tyrek',
                                            'Evgeni Teriik',
                                            'Lokart Hiryytk',
                                            'Nukim Havenovich',
                                            'Liker Zimniij',
                                            'Waserman Novuuh',
                                            'Konavis Scott'
                                            -- Add more names here
                                        );
    phone_prefix VARCHAR2(4) := '+375';
    id_counter   NUMBER       := 1;

BEGIN
    FOR i IN 1..10 LOOP
        INSERT INTO CLIENTS (ID, NAME, EMAIL, PHONE)
        VALUES (
            id_counter,
            names_arr(DBMS_RANDOM.VALUE(1, names_arr.COUNT)),
            DBMS_RANDOM.STRING('U', DBMS_RANDOM.VALUE(5, 20)) || '@example.com',
            phone_prefix || TRUNC(DBMS_RANDOM.VALUE(100000000, 999999999))
        );
        
        id_counter := id_counter + 1;
    END LOOP;

    COMMIT;
    DBMS_OUTPUT.PUT_LINE('Table CLIENTS filled with random values successfully.');

EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
        ROLLBACK;

END;

--WORKS!
CREATE OR REPLACE PROCEDURE FILL_DIRECTORS AS
  -- Array of actor names
  TYPE director_name_array IS TABLE OF VARCHAR2(50);
  director_names director_name_array := director_name_array(
                                            'Jane Doe',
                                            'Michael Johnson',
                                            'Emily Davis',
                                            'Christopher Wilson',
                                            'Olivia Thompson',
                                            'Daniel Martinez',
                                            'Sophia Anderson',
                                            'David Garcia',
                                            'Isabella Clark',
                                            'Matthew Lopez',
                                            'Mia Lewis',
                                            'Andrew Taylor',
                                            'Ava Hall',
                                            'James Brown',
                                            'Abigail White',
                                            'Joseph Lee',
                                            'Charlotte King',
                                            'Benjamin Adams',
                                            'Grace Moore'
  );
BEGIN
  FOR i IN 1..10 LOOP
    INSERT INTO DIRECTORS (NAME, BIRTH_DATE)
    VALUES (director_names(i), TRUNC(SYSDATE - DBMS_RANDOM.VALUE(8000, 25000))); -- Random birth date between 22 and 68 years ago
  END LOOP;
  COMMIT;
END;

--WORKS!
CREATE OR REPLACE PROCEDURE FILL_TICKETS AS
    film_names_arr  SYS.ODCIVARCHAR2LIST := SYS.ODCIVARCHAR2LIST(
'The Shawshank Redemption',
'Pulp Fiction',
'Inception',
'The Godfather',
'Forrest Gump',
'The Dark Knight',
'Fight Club',
'Goodfellas',
'The Lord of the Rings: The Fellowship of the Ring',
'The Lion King',
'Schindlers List',
'Interstellar',
'Gladiator',
'The Avengers',
'Star Wars: Episode V - The Empire Strikes Back',
'The Matrix',
'Resident Evil',
'Jurassic Park',
'Titanic',
'Casablanca'
                                                -- Add more film names here
                                            );
    id_counter      NUMBER := 1;

BEGIN
    FOR i IN 1..20 LOOP
        DECLARE
            hall_id_val     NUMBER;
            client_id_val   NUMBER;
        BEGIN
            SELECT HALL_NUMBER
            INTO hall_id_val
            FROM HALLS
            ORDER BY DBMS_RANDOM.VALUE
            FETCH FIRST ROW ONLY;
            
            SELECT ID
            INTO client_id_val
            FROM CLIENTS
            ORDER BY DBMS_RANDOM.VALUE
            FETCH FIRST ROW ONLY;
        
            INSERT INTO TICKETS (ID, FILM_NAME, HALL_ID, CLIENT_ID, PRICE, START_TIME)
            VALUES (
                id_counter,
                film_names_arr(DBMS_RANDOM.VALUE(1, film_names_arr.COUNT)),
                hall_id_val,
                client_id_val,
                ROUND(DBMS_RANDOM.VALUE(5, 20)), -- Random price between 5 to 20
                SYSTIMESTAMP - INTERVAL '1' HOUR * DBMS_RANDOM.VALUE(1, 48) -- Start time within the past 48 hours
            );
            
            id_counter := id_counter + 1;
        EXCEPTION
            WHEN NO_DATA_FOUND THEN
                DBMS_OUTPUT.PUT_LINE('Error: No data found in HALLS or CLIENTS table.');
        END;
    END LOOP;

    COMMIT;
    DBMS_OUTPUT.PUT_LINE('Table TICKETS filled with random values successfully.');

EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
        ROLLBACK;

END;
--WORKS
CREATE OR REPLACE PROCEDURE FILL_REVIEWS
IS
    var_client_id NUMBER;
    var_rating NUMBER;
    var_review_text VARCHAR2(500);
BEGIN
    FOR film IN (
        SELECT FILM_NAME FROM (
            SELECT 'The Shawshank Redemption' AS FILM_NAME FROM DUAL
            UNION ALL
            SELECT 'Pulp Fiction' FROM DUAL
            UNION ALL
            SELECT 'Inception' FROM DUAL
            UNION ALL
            SELECT 'The Godfather' FROM DUAL
            UNION ALL
            SELECT 'Forrest Gump' FROM DUAL
            UNION ALL
            SELECT 'The Dark Knight' FROM DUAL
            UNION ALL
            SELECT 'Fight Club' FROM DUAL
            UNION ALL
            SELECT 'Goodfellas' FROM DUAL
            UNION ALL
            SELECT 'The Lord of the Rings: The Fellowship of the Ring' FROM DUAL
            UNION ALL
            SELECT 'The Lion King' FROM DUAL
            UNION ALL
            SELECT 'Schindlers List' FROM DUAL
            UNION ALL
            SELECT 'Interstellar' FROM DUAL
            UNION ALL
            SELECT 'Gladiator' FROM DUAL
            UNION ALL
            SELECT 'The Avengers' FROM DUAL
            UNION ALL
            SELECT 'Star Wars: Episode V - The Empire Strikes Back' FROM DUAL
            UNION ALL
            SELECT 'The Matrix' FROM DUAL
            UNION ALL
            SELECT 'Resident Evil' FROM DUAL
            UNION ALL
            SELECT 'Jurassic Park' FROM DUAL
            UNION ALL
            SELECT 'Titanic' FROM DUAL
            UNION ALL
            SELECT 'Casablanca' FROM DUAL
        )
    )
    LOOP
        -- Select a random client ID
        SELECT ID
        INTO   var_client_id
        FROM   (SELECT ID FROM CLIENTS ORDER BY DBMS_RANDOM.RANDOM) WHERE ROWNUM = 1;
        
        -- Generate a random rating between 1 and 10
        var_rating := FLOOR(DBMS_RANDOM.VALUE(1, 11));
        
        -- Create the review text
        var_review_text := 'Review text for film ' || film.FILM_NAME;
        
        -- Insert the review into the Reviews table
        INSERT INTO REVIEWS (FILM_NAME, CLIENT_ID, RATING, REVIEW_TEXT)
        VALUES (film.FILM_NAME, var_client_id, var_rating, var_review_text);
    END LOOP;
    COMMIT; -- Commit the changes
END;

-- Создание процедуры для заполнения таблицы FILMS
CREATE OR REPLACE PROCEDURE FILL_FILMS_TABLE IS
BEGIN
  -- Вставка записей для каждого фильма
  INSERT INTO FILMS (TITLE, DESCRIPTION, RELEASE_DATE, DURATION, AGE_RESTRICTION, FILM_ACTOR_1, FILM_ACTOR_2, FILM_ACTOR_3, FILM_DIRECTORS, FILM_REVIEW, GENRE, POSTER)
  VALUES ('The Shawshank Redemption', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('Pulp Fiction', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('Inception', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('The Godfather', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('Forrest Gump', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('The Dark Knight', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('Fight Club', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('Goodfellas', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('The Lord of the Rings: The Fellowship of the Ring', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('The Lion King', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('Schindlers List', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('Interstellar', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('Gladiator', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('The Avengers', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('Star Wars: Episode V - The Empire Strikes Back', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('The Matrix', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('Resident Evil', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('Jurassic Park', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('Titanic', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  VALUES ('Casablanca', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, EMPTY_BLOB());
  COMMIT;
END;






