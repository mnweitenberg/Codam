-- Apply initial privileges
FLUSH PRIVILEGES;

-- Drop database used for testing
DROP DATABASE test;
DELETE FROM mysql.db WHERE Db='test';

-- Delete anonymous MySQL user
DELETE FROM mysql.user WHERE User='';

-- Delete root user(s) where host is not local
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN('localhost', '127.0.0.1', '::1');

-- Set root password
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MARIADB_ROOT_PASSWORD';

-- Create WordPress database
CREATE DATABASE IF NOT EXISTS $WORDPRESS_DB_NAME CHARACTER SET utf8 COLLATE utf8_general_ci;

-- Create WordPress user, allow login on all hostnames (%)
CREATE USER '$WORDPRESS_DB_USER'@'%' IDENTIFIED BY '$WORDPRESS_DB_PASSWORD';
GRANT ALL PRIVILEGES ON $WORDPRESS_DB_NAME.* TO '$WORDPRESS_DB_USER'@'%';

-- Enable logging
SET GLOBAL general_log = 'ON';
SET GLOBAL slow_query_log = 'ON';

-- Apply new privileges
FLUSH PRIVILEGES;
