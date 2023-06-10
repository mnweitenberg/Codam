# Use the official Debian Buster image as the base image
FROM debian:buster

# Set environment variable to avoid any prompts during package installation.
ENV DEBIAN_FRONTEND=noninteractive

# Install latest system updates
RUN apt update && apt upgrade -y

# Install required software
RUN apt install -y \
    mariadb-server \
    mariadb-client

# Initialize MariaDB database
RUN mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql

# Enable remote login for MariaDB, so we acces the DB from another URL or IP
# address than localhost
RUN sed -i "/^skip-networking/c\# skip-networking" /etc/mysql/my.cnf
RUN sed -i '/^bind-address/c\bind-address = 0.0.0.0' /etc/mysql/mariadb.conf.d/50-server.cnf

# Set up MariaDB and start in the foreground
COPY tools/setup.sh /tmp/setup.sh
COPY tools/init.sql /tmp/init.sql
CMD ["sh", "/tmp/setup.sh"]

# MariaDB is a free and open-source relational database management system (RDBMS) 
# that is widely used as a drop-in replacement for MySQL. It is designed to be a 
# community-driven alternative to MySQL, with a focus on simplicity, collaboration, 
# and compatibility with other database systems.

# MariaDB includes a number of additional features and improvements over MySQL, 
# including better performance, enhanced security, and support for new storage 
# engines and data types. 