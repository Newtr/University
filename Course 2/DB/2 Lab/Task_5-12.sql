CREATE ROLE RL_TRACORE;
GRANT CREATE SESSION,
      CREATE TABLE,
      CREATE VIEW,
      CREATE PROCEDURE
      TO RL_TRACORE;

SELECT * FROM DBA_ROLES WHERE ROLE = 'RL_TRACORE';
SELECT * FROM DBA_SYS_PRIVS WHERE GRANTEE = 'RL_TRACORE';

CREATE PROFILE PF_TRACORE LIMIT
    PASSWORD_LIFE_TIME 180
    SESSIONS_PER_USER 3
    FAILED_LOGIN_ATTEMPTS 7
    PASSWORD_LOCK_TIME 1
    PASSWORD_REUSE_TIME 10
    PASSWORD_GRACE_TIME DEFAULT
    CONNECT_TIME 180
    IDLE_TIME 30;
    
SELECT DISTINCT PROFILE FROM DBA_PROFILES;
SELECT * FROM DBA_PROFILES WHERE PROFILE = 'PF_TRACORE';
SELECT * FROM DBA_PROFILES WHERE PROFILE = 'DEFAULT';

CREATE USER TRACORE 
    IDENTIFIED BY pass
    DEFAULT TABLESPACE TS_TRA
    TEMPORARY TABLESPACE TS_TRA_TEMP
    PROFILE PF_TRACORE
    ACCOUNT UNLOCK
    PASSWORD EXPIRE;
GRANT RL_TRACORE TO TRACORE;