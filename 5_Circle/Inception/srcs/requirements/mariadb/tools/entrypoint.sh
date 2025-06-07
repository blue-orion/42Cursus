#!/bin/sh

# ✅ 초기화 필요 시 시스템 테이블 생성
if [ ! -d /var/lib/mysql/mysql ]; then
    echo "[INFO] Initializing MariaDB data directory..."
    mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql

    echo "[INFO] Starting temporary MariaDB to run init.sql..."
    mysqld_safe --skip-networking &
    sleep 5

    echo "[INFO] Creating init.sql..."
    mysql --protocol=socket -u root <<EOF
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\` CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    mysqladmin -u root shutdown
    sleep 2
fi

# ✅ 퍼미션 정리
chown -R mysql:mysql /var/lib/mysql

# ✅ 포그라운드로 진짜 MariaDB 실행
exec mysqld_safe

