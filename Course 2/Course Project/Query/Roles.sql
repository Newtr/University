-- Создание роли 'Administrator'
CREATE ROLE Administrator;

-- Предоставление привилегий для выполнения процедур
GRANT EXECUTE ON FILL_HALLS TO Administrator;
GRANT EXECUTE ON FILL_ACTORS TO Administrator;
GRANT EXECUTE ON FILL_CLIENTS TO Administrator;
GRANT EXECUTE ON FILL_DIRECTORS TO Administrator;
GRANT EXECUTE ON FILL_TICKETS TO Administrator;
GRANT EXECUTE ON FILL_REVIEWS TO Administrator;
GRANT EXECUTE ON FILL_FILMS TO Administrator;
GRANT EXECUTE ON get_ticket_count TO Administrator;
GRANT EXECUTE ON get_ticket_count_by_film TO Administrator;
GRANT EXECUTE ON buy_ticket TO Administrator;
GRANT EXECUTE ON buy_ticket_with_extras TO Administrator;
GRANT EXECUTE ON add_review TO Administrator;
GRANT EXECUTE ON ADD_FILM TO Administrator;
GRANT EXECUTE ON delete_review TO Administrator;
GRANT EXECUTE ON DELETE_FILM TO Administrator;
GRANT EXECUTE ON ACTORS_TO_XML TO Administrator;
GRANT EXECUTE ON XML_TO_ACTORS TO Administrator;
GRANT EXECUTE ON INSERT_100000_CLIENTS TO Administrator;
GRANT SELECT ANY TABLE TO Administrator;
GRANT CREATE SESSION TO Administrator;
GRANT CREATE TABLE TO Administrator;
CREATE USER Cinema_Administrator IDENTIFIED BY password;
GRANT Administrator TO Cinema_Administrator;

GRANT SELECT ANY TABLE TO CINEMA_ADMINISTRATOR;

-- Создание роли 'Client'
CREATE ROLE Client;

-- Предоставление привилегий для выполнения процедур
GRANT EXECUTE ON buy_ticket TO Client;
GRANT EXECUTE ON buy_ticket_with_extras TO Client;
GRANT EXECUTE ON add_review TO Client;
GRANT CREATE SESSION TO Client;

-- Создание пользователя Cinema_Client
CREATE USER Cinema_Client IDENTIFIED BY password;

-- Выдача роли Client пользователю Cinema_Client
GRANT Client TO Cinema_Client;
