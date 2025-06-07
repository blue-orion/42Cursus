FROM alpine:3.21

# Alpine 패키지 설치 (라이브러리와 빌드 툴)
RUN apk update && apk add --no-cache \
	curl	\
	php82-fpm	\
	php82-mysqli	\
	php82-openssl


# 워드프레스 다운로드
WORKDIR /var/www/html

RUN curl -O https://wordpress.org/latest.tar.gz \
    && tar -xzf latest.tar.gz \
    && cp -r wordpress/* . \
    && rm -rf wordpress latest.tar.gz

COPY ./conf/php-fpm.conf /etc/php82/php-fpm.d/www.conf

# wp-config 자동 생성 스크립트
COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

ENV MYSQL_DATABASE=wordpress \
    MYSQL_USER=wpuser \
    MYSQL_PASSWORD=wppassword

VOLUME ["/var/www/html"]

EXPOSE 9000

CMD ["php-fpm82", "-F"]

ENTRYPOINT ["/entrypoint.sh"]

