#!/bin/sh

CONFIG_PATH=/var/www/html/wp-config.php

# # ✅ MariaDB가 연결될 때까지 대기
# echo "[INFO] Waiting for MariaDB to be ready..."
# while ! ping "${DB_HOST%%:*}"; do
# 	sleep 1
# done

# ✅ wp-config.php 생성
if [ ! -f "$CONFIG_PATH" ]; then
	echo "[INFO] Generating wp-config.php..."
	cat > "$CONFIG_PATH" <<EOF
<?php
define('DB_NAME', '${MYSQL_DATABASE}');
define('DB_USER', '${MYSQL_USER}');
define('DB_PASSWORD', '${MYSQL_PASSWORD}');
define('DB_HOST', '${DB_HOST}');
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');

define('AUTH_KEY',         '$(openssl rand -base64 32)');
define('SECURE_AUTH_KEY',  '$(openssl rand -base64 32)');
define('LOGGED_IN_KEY',    '$(openssl rand -base64 32)');
define('NONCE_KEY',        '$(openssl rand -base64 32)');
define('AUTH_SALT',        '$(openssl rand -base64 32)');
define('SECURE_AUTH_SALT', '$(openssl rand -base64 32)');
define('LOGGED_IN_SALT',   '$(openssl rand -base64 32)');
define('NONCE_SALT',       '$(openssl rand -base64 32)');

\$table_prefix = 'wp_';
define('WP_DEBUG', false);

if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');
require_once(ABSPATH . 'wp-settings.php');
EOF
fi

# ✅ php-fpm 실행
exec php-fpm82 -F

