NAME = inception

DOCKER_COMPOSE = docker-compose -f srcs/docker-compose.yml
ENV_FILE = srcs/.env

.PHONY: all up down stop fclean re

all: up

up:
	@echo "\n[🔧] Building and starting containers..."
	$(DOCKER_COMPOSE) --env-file $(ENV_FILE) up --build -d

down:
	@echo "\n[🧹] Stopping containers..."
	$(DOCKER_COMPOSE) down

stop:
	@echo "\n[⏹️] Stopping containers (without removing)..."
	$(DOCKER_COMPOSE) stop

fclean: down
	@echo "\n[🔥] Removing volumes..."
	docker volume rm $(shell docker volume ls -qf "name=wordpress_data") 2>/dev/null || true
	docker volume rm $(shell docker volume ls -qf "name=mariadb_data") 2>/dev/null || true
	@echo "[✅] Cleanup complete."

re: fclean all

