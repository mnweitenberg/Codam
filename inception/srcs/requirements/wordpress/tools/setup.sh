#!/bin/sh

until mysqladmin ping -hmariadb --silent; do
    echo "Wait for MariaDB to be available..."
    sleep 1
done

echo "Download the latest version of Wordpress..."
wp core download --allow-root --force

echo "Configure Wordpress with database connection details..."
wp core config --dbhost="mariadb" --dbname="$WORDPRESS_DB_NAME" --dbuser="$WORDPRESS_DB_USER" --dbpass="$WORDPRESS_DB_PASSWORD" --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root --force

echo "Set appropriate permissions for wp-config.php..."
chmod -f 644 wp-config.php

echo "Install Wordpress with the provided information..."
wp core install --url="mweitenb.42.fr" --title="$WORDPRESS_NAME" --admin_name="$WORDPRESS_ADMIN_NAME" --admin_password="$WORDPRESS_ADMIN_PASSWORD" --admin_email="$WORDPRESS_ADMIN_MAIL" --skip-email --allow-root

echo "Creating Wordpress user $WP_USER_NAME..."
wp user create "$WORDPRESS_USER" "$WORDPRESS_USER_MAIL" --user_pass="$WORDPRESS_USER_PASSWORD" --role=author --allow-root

echo "Wordpress was successfully installed."

echo "Configure php-fpm to listen on port 9000..."
sed -i '/^listen /c\listen = 9000' /etc/php/7.3/fpm/pool.d/www.conf
cat /etc/php/7.3/fpm/pool.d/www.conf | grep "listen ="

# Start PHP-FPM process, which listens for CGI requests
# The -F option specifies that PHP-FPM should run in the foreground and not 
# daemonize (i.e., become a background process). This is useful for debugging 
# or running PHP-FPM in a containerized environment where there is no need for 
# PHP-FPM to run as a background process.
# When PHP-FPM is run with -F, it will log to the console and any errors or 
# warnings will be printed directly to the console, making it easier to 
# troubleshoot any issues. Without -F, PHP-FPM will run as a background process 
# and log to a file specified by the error_log directive in the php-fpm.conf 
# configuration file.
echo "Start PHP-FPM process..."
mkdir -p /run/php
/usr/sbin/php-fpm7.3 -F

