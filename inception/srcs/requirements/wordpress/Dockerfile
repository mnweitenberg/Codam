# Use the official Debian Buster image as the base image
FROM debian:buster

# Set environment variable to avoid any prompts during package installation.
ENV DEBIAN_FRONTEND=noninteractive

# Install latest system updates
RUN apt update && apt upgrade -y

# Install required software
RUN apt install -y \
    mariadb-client \
    php \
    php-bcmath \
    php-curl \
    php-imagick \
    php-intl \
    php-json \
    php-mbstring \
    php-mysql \
    php-xml \
    php-zip \
    php-fpm \
    curl \
    unzip

# Download wp-cli (Wordpress Command Line Interface)
RUN curl -L https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -o /usr/local/bin/wp && \
    chmod +x /usr/local/bin/wp && \
    wp --info

# Set up and run wordpress
WORKDIR /var/www/html
COPY tools/setup.sh /tmp/setup.sh
CMD ["sh", "/tmp/setup.sh"]

# WordPress is a content management system (CMS) based on PHP and MySQL. It is 
# an open-source platform that is widely used for building websites, blogs, and 
# applications. With WordPress, users can easily create and manage their own 
# websites without the need for advanced technical skills. It is known for its 
# simplicity and flexibility, making it a popular choice for both beginners and 
# experienced developers. WordPress has a large community of users and developers 
# who contribute to the platform, which has led to the development of a wide range 
# of themes, plugins, and other tools that can be used to extend the functionality 
# of WordPress websites.