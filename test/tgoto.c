#include <termcap.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char *term = getenv("TERM");  // TERM 환경 변수에서 터미널 유형 가져오기
    if (term == NULL) {
        fprintf(stderr, "TERM 환경 변수가 설정되어 있지 않습니다.\n");
        return 1;
    }

    char buffer[2048];  // 터미널 데이터베이스 내용을 저장할 버퍼
    if (tgetent(buffer, term) != 1) {
        fprintf(stderr, "터미널 '%s' 초기화에 실패했습니다.\n", term);
        return 1;
    }

    char *cm_str = tgetstr("cm", NULL);  // 커서 이동 문자열 가져오기
    if (cm_str == NULL) {
        fprintf(stderr, "커서 이동 문자열을 가져올 수 없습니다.\n");
        return 1;
    }

    char *cursor_move = tgoto(cm_str, 10, 5);  // 커서 위치 (10, 5)로 이동
    if (cursor_move != NULL) {
        // 커서 이동 문자열 출력
        printf("%s", cursor_move);
    } else {
        fprintf(stderr, "커서 이동 문자열 생성 실패\n");
    }

    return 0;
}

