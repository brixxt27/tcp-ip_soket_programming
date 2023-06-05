#include <iostream>
#include <dirent.h>

int main() {
    const char* dirname = "."; // 디렉토리 이름
    int cnt = 0;

    DIR* dir = opendir(dirname); // 디렉토리 열기
    if (dir == NULL) {
        std::cerr << "Failed to open directory." << std::endl;
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) { // 디렉토리 내용 읽기
        std::cout << entry->d_name << std::endl; // 파일 또는 디렉토리 이름 출력
        cnt++;
    }

    closedir(dir); // 디렉토리 닫기

    std::cout << "The number of call " << cnt << std::endl;

    return 0;
}
