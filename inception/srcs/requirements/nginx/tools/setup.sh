#!/bin/sh

# Disable Nginx daemon mode
# Disabling the Nginx daemon mode makes it run in the foreground rather than as a 
# background process. In a Docker container, it is often preferable to run the main 
# process in the foreground to keep the container alive. If the main process runs 
# as a daemon (background process), the container might exit immediately after 
# starting, as the foreground process would finish quickly.

# By setting daemon off; in the Nginx configuration file, you ensure that Nginx 
# runs in the foreground and keeps the container running. The container will 
# continue to run as long as Nginx is running. If Nginx encounters a fatal error 
# or stops, the container will also stop, making it easier to manage and monitor 
# the container's lifecycle.

# It is a common practice to run the main process in the foreground in Docker 
# containers, as it provides better integration with Docker's process management 
# features.
echo "Disable nginx daemon..."
if ! grep -Fxq "daemon off;" /etc/nginx/nginx.conf; then
    echo "daemon off;" >> /etc/nginx/nginx.conf
fi

# Generate SSL certificate if not already present using the OpenSSL 
# command line tool, with a validity period of 365 days and a key length of 4096 
# bits. The -subj option specifies the subject of the certificate (in this case, 
# the Common Name is set to mweitenb.42.fr).
echo "Generate SSL certificate..."
mkdir -p /etc/nginx/ssl
if [ ! -f "/etc/nginx/ssl/server.key" ] || [ ! -f "/etc/nginx/ssl/server.pem" ]; then
    openssl req -newkey rsa:4096 -x509 -days 365 -nodes \
        -keyout /etc/nginx/ssl/server.key -out /etc/nginx/ssl/server.pem \
        -subj "/C=NL/ST=Noord-Holland/L=Amsterdam/O=Codam/OU=Students/CN=mweitenb.42.fr}"
fi

echo "Starting Nginx in the foreground..."
exec nginx
