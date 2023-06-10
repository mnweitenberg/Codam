# Use the official Debian Buster image as the base image
FROM debian:buster

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Install latest system updates
RUN apt update && apt upgrade -y

# Install required software
RUN apt install -y \
    nginx \
    openssl

# Copy Nginx configuration and set up domain name
COPY conf/nginx.conf /etc/nginx/sites-enabled/default

# Set up and start Nginx
WORKDIR /etc/nginx
COPY tools/setup.sh /tmp/setup.sh
CMD ["sh", "/tmp/setup.sh"]

# NGINX is a web server that can also be used as a reverse proxy, load balancer, 
# and HTTP cache. It is known for its high performance, stability, and low resource 
# consumption. NGINX is often used to handle server-side requests for web applications,
# and it can also be used to serve static content such as images and JavaScript 
# files. In addition to its web server capabilities, NGINX can be configured to 
# handle other types of network protocols, such as Secure Sockets Layer (SSL) and 
# Transport Layer Security (TLS). It is often used in conjunction with other 
# software, such as databases and content management systems, to build robust 
# and scalable web applications.
