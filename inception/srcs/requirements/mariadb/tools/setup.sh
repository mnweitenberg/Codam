#!/bin/sh

echo " Create and set permissions for the MySQL data directory..."
mkdir -p /var/lib/mysql

echo " Create and set permissions for the MySQL socket directory..."
mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld

echo "Configure MariaDB..."
envsubst < "/tmp/init.sql" > "/var/lib/mysql/init.sql"
mysqld --user=mysql --bootstrap < "/var/lib/mysql/init.sql"
rm -f /var/lib/mysql/init.sql
echo "MariaDB set up."

echo "Start MariaDB in the foreground and redirect output to a log file..."
mysqld --user=mysql --console > /var/lib/mysql/sql.log
