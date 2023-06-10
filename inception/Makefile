# VARIABLES
NAME = inception
DOCKER_COMPOSE = ./srcs/docker-compose.yml
HOSTS_ENTRY = "127.0.0.1 mweitenb.42.fr"
DATA_PATH = $(HOME)/data

# TARGETS
all: $(NAME)
$(NAME): up

up:
#	Add the domain to /etc/hosts if it does not exist
	sudo chmod a+w /etc/hosts && grep -q $(HOSTS_ENTRY) /etc/hosts || \
	sudo echo $(HOSTS_ENTRY) >> /etc/hosts

#	Create and set permissions for the necessary directories
	sudo mkdir -p $(DATA_PATH)/db && sudo chmod 777 $(DATA_PATH)/db
	sudo mkdir -p $(DATA_PATH)/www && sudo chmod 777 $(DATA_PATH)/www

#	Start and build the containers
	sudo docker-compose -f $(DOCKER_COMPOSE) up --build

down:
	sudo docker-compose -f $(DOCKER_COMPOSE) down

# Remove containers, images, and volumes
prune:
#	Stop and remove containers, networks, and volumes defined in the docker-compose.yml file
	sudo docker-compose -f $(DOCKER_COMPOSE) down --rmi all -v
#	Remove all stopped containers, unused networks, dangling images, build cache, and unused volumes
	sudo docker system prune --force --volumes

# Clean up the environment and remove data
clean: prune
#	Remove the domain from /etc/hosts
	sudo sed -i '/$(HOSTS_ENTRY)/d' /etc/hosts

#	Remove data directories
	sudo rm -rf "$(DATA_PATH)"

re: clean all

.PHONY: all $(NAME) clean re up down prune
