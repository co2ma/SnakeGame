# Snake Game with Ncurses

C++ 언어와 ncurses 라이브러리를 이용하여 터미널 환경에서 실행되는 스네이크 게임

객체지향 프로그래밍(OOP) 원칙을 적용하여 게임의 각 요소(Snake, Map, Item, Gate)를 모듈화하여 구현

## 1.1. 프로젝트 명

**[Console-based Snake Game Project]**
- C++과 ncurses를 활용한 CLI 스네이크 게임 구현

## 1.2. 프로젝트 기간

* **전체 일정**: 2023년 5월~6월
* **주요 마일스톤**:
    * 환경 설정 및 ncurses 라이브러리 연동
    * 맵 데이터 로드 및 화면 출력 구현
    * 스네이크 이동 및 입력 처리 로직 개발
    * 아이템(Growth/Poison) 및 게이트(Gate) 시스템 추가
    * 점수 계산 및 게임 종료(Game Over) 조건 완성

## 1.3. 프로젝트 컨셉

* **Retro 스타일**: GUI가 아닌 터미널(CLI) 환경에서의 게임 구현
* **Logic 중심**: 자료구조(예: Deque, Vector)를 활용한 스네이크의 몸체 관리 및 충돌 판정 로직 최적화
* **확장성**: CMake 빌드 시스템을 활용하여 다양한 환경에서 빌드 가능하도록 구성

## 2.1. 기획의도 및 요구사항 분석

* **기획의도**:
    * C++ 클래스 구조를 이해하고 객체 간의 상호작용 설계 역량 강화
    * ncurses 라이브러리를 통한 실시간 키보드 입력 처리 및 화면 갱신 학습
* **요구사항**:
    * 스네이크는 벽이나 자신의 몸에 부딪히면 게임 오버 처리
    * 일정 시간마다 아이템(성장/감소)이 무작위 위치에 생성
    * 두 개의 게이트를 통과하면 반대편 게이트로 이동하는 워프 기능 구현
    * 실시간으로 현재 점수, 획득 아이템 수, 통과한 게이트 수를 표시

## 2.2. 시나리오 설정

1. **게임 시작**: 터미널에서 프로그램 실행 시 기본 맵과 스네이크가 초기 위치에 등장
2. **플레이**: 방향키를 이용해 스네이크를 조종하며 아이템을 획득하여 몸길이를 늘림
3. **게이트 등장**: 특정 조건 만족 시 벽의 일부가 게이트로 변하며 전략적 이동 가능
4. **게임 종료**: 스네이크의 길이가 최소 길이 미만이 되거나 충돌 발생 시 종료 메시지 출력

## 2.3. 주요 기능

* **Snake Control**: 방향키를 이용한 4방향 이동 및 실시간 속도 제어
* **Item System**: 
    * `Growth Item`: 몸길이 1 증가
    * `Poison Item`: 몸길이 1 감소 (최소 길이 미만 시 사망)
* **Gate System**: 맵 외곽 벽에 생성되는 포털로, 진입 방향에 따른 탈출 방향 계산 로직 적용
* **Score Board**: 현재 길이 / 최대 길이, 획득한 아이템 수, 사용한 게이트 수 실시간 갱신 출력

## 3.1. 개발환경

* **OS**: windows 11 (ncurses 지원 환경)
* **Language**: C++
* **Build Tool**: CMake, Makefile
* **Developer Tools**: VS Code (Visual Studio Code)
* **Version Control**: GitHub

## 3.2. 사용한 API

* **ncurses API**:
    * `initscr()`, `endwin()`: 윈도우 초기화 및 종료
    * `keypad()`: 특수 키(방향키) 입력 활성화
    * `getch()`, `nodelay()`: 비동기 입력 처리
    * `wrefresh()`, `mvwprintw()`: 특정 윈도우 영역 갱신 및 문자열 출력

## 3.3. 필요한 라이브러리

* **ncurses**: 터미널 제어를 위한 필수 라이브러리
    * 설치 예시 (Ubuntu): `sudo apt-get install libncurses5-dev libncursesw5-dev`
* **Standard Template Library (STL)**: `vector`, `deque`, `algorithm` 등 사용

## 4. 화면설계 및 기능 구현

* **Game Screen**: 맵 데이터 기반으로 렌더링되는 메인 게임 창
* **Score Window**: 게임 창 우측 또는 하단에 배치되어 실시간 상태 정보를 표시하는 별도 윈도우
* **Logic Flow**:
    1. `main.cpp`에서 전체 게임 루프 관리
    2. `Map` 클래스에서 2차원 배열 형태의 맵 데이터 관리
    3. `Snake` 클래스에서 좌표 기반 몸체 업데이트 및 충돌 체크
    4. `Game` 클래스에서 전체적인 규칙 및 스테이지 전환 관리
