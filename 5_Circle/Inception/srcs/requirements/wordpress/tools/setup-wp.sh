#!/bin/sh

WP_PATH=/var/www/html

# wp-config.php가 이미 존재하면 무시
if [ -f "$WP_PATH/wp-config.php" ]; then
    echo "[INFO] wp-config.php already exists. Skipping setup."
    exit 0
fi

echo "[INFO] Creating wp-config.php..."

cat > "$WP_PATH/wp-config.php" <<EOF
<?php
define( 'DB_NAME',     'wordpress' );
define( 'DB_USER',     'wpuser' );
define( 'DB_PASSWORD', 'wppassword' );
define( 'DB_HOST',     'mariadb:3306' );
define( 'DB_CHARSET',  'utf8' );
define( 'DB_COLLATE',  '' );

define( 'AUTH_KEY',         '$(openssl rand -base64 32)' );
define( 'SECURE_AUTH_KEY',  '$(openssl rand -base64 32)' );
define( 'LOGGED_IN_KEY',    '$(openssl rand -base64 32)' );
define( 'NONCE_KEY',        '$(openssl rand -base64 32)' );
define( 'AUTH_SALT',        '$(openssl rand -base64 32)' );
define( 'SECURE_AUTH_SALT', '$(openssl rand -base64 32)' );
define( 'LOGGED_IN_SALT',   '$(openssl rand -base64 32)' );
define( 'NONCE_SALT',       '$(openssl rand -base64 32)' );

\$table_prefix = 'wp_';
define( 'WP_DEBUG', false );
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}
require_once ABSPATH . 'wp-settings.php';
EOF

echo "[INFO] wp-config.php created successful

