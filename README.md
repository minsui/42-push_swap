*This project has been created as part of the 42 curriculum by [mkim2].*

#  push_swap

---

## 📌 개요

**push_swap**은 두 개의 스택(`A`, `B`)과 제한된 연산만을 사용하여, 주어진 정수 목록을 **최소한의 명령어**로 오름차순 정렬하는 C 프로그램입니다.

알고리즘 설계, 복잡도 최적화, 이중 연결 리스트 조작 능력을 기르는 것이 핵심 목표입니다.

---

## 📁 파일 구조

```
push_swap/
├── push_swap.h       # 구조체 및 함수 프로토타입 선언
├── main.c            # 진입점, 스택 초기화 및 정렬 분기
├── parsing.c         # 입력값 유효성 검사 (숫자 여부, 중복 확인)
├── libft_utils.c     # ft_atoi, ft_error 유틸 함수
├── stack_utils.c     # 노드 생성 및 스택 삽입 함수
├── op_s.c            # swap 연산: sa, sb, ss
├── op_p.c            # push 연산: pa, pb
├── op_r.c            # rotate 연산: ra, rb, rr
├── op_rr.c           # reverse rotate 연산: rra, rrb, rrr
├── sort_small.c      # 소규모 정렬 (2 ~ 5개)
├── sort_utils.c      # 인덱싱 및 위치 탐색 유틸
├── sort_large.c      # 대규모 정렬 (100 ~ 500개)
└── split_fill.c      # 공백 구분 문자열 파싱 및 스택 삽입  
└── Makefile

```

---

## ⚙️ 빌드 방법

```bash
make        # push_swap 실행 파일 생성
make clean  # 오브젝트 파일(.o) 삭제
make fclean # 실행 파일 포함 모든 빌드 산출물 삭제
make re     # fclean 후 재빌드
```

---

## 🚀 실행 방법

```bash
# 기본 실행
./push_swap 3 1 4 1 5 9 2 6

# 결과 검증 (checker 사용 시)
ARG="3 1 4 1 5"; ./push_swap $ARG | ./checker_linux $ARG

# 명령어 수 확인
./push_swap 3 1 4 1 5 | wc -l
```

**오류 케이스 (에러 출력 후 종료)**
```bash
./push_swap 1 2 abc    # 숫자가 아닌 인자
./push_swap 1 2 2      # 중복 값
./push_swap 2147483648 # int 범위 초과
```

---

## 🔧 사용 가능한 연산

| 연산  | 설명 |
|-------|------|
| `sa`  | 스택 A의 상위 두 원소를 교환 |
| `sb`  | 스택 B의 상위 두 원소를 교환 |
| `ss`  | `sa`와 `sb`를 동시에 수행 |
| `pa`  | 스택 B의 최상단 원소를 A로 이동 |
| `pb`  | 스택 A의 최상단 원소를 B로 이동 |
| `ra`  | 스택 A를 위로 한 칸 회전 (최상단 → 최하단) |
| `rb`  | 스택 B를 위로 한 칸 회전 |
| `rr`  | `ra`와 `rb`를 동시에 수행 |
| `rra` | 스택 A를 아래로 한 칸 회전 (최하단 → 최상단) |
| `rrb` | 스택 B를 아래로 한 칸 회전 |
| `rrr` | `rra`와 `rrb`를 동시에 수행 |

---

## 🧠 알고리즘 설명

### 1. 소규모 정렬 (2 ~ 5개) — `sort_small.c`

**2개:** 상단 두 값을 비교하여 필요 시 `sa` 한 번으로 해결.

**3개 (`sort_three`):**  
상단(`top`), 중간(`mid`), 하단(`bot`) 세 값의 대소 관계에 따라 하드코딩된 최적 명령어 조합 사용.  
최대 2회 연산으로 정렬 완료.

**4 ~ 5개 (`sort_five`):**  
1. 최솟값을 찾아 최단 경로(`ra` 또는 `rra`)로 상단으로 이동
2. `pb`로 B 스택에 제거
3. A에 3개만 남을 때까지 반복
4. `sort_three`로 나머지 3개 정렬
5. `pa`로 B의 원소를 순서대로 복원

---

### 2. 대규모 정렬 (6개 이상) — `sort_large.c` / `sort_utils.c`

**모래시계(Hourglass) 알고리즘**

#### 단계 1. 인덱싱 (`index_stack`)
모든 노드에 상대적 크기 순위를 인덱스(`0` ~ `N-1`)로 부여.  
→ 실제 값 대신 인덱스로 비교하여 로직을 단순화.

#### 단계 2. A → B 이동 (`push_to_b`)
chunk 단위로 인덱스 범위를 나누어 B 스택으로 이동.

| 조건 | 동작 |
|------|------|
| `index <= i` (현재 chunk의 작은 값) | `pb` → B의 **상단**에 push (큰 값이 위로) |
| `index <= i + chunk` (현재 chunk의 큰 값) | `pb` 후 `rb` → B의 **하단**으로 이동 |
| 범위 밖 | `ra`로 다음 원소 확인 |

결과적으로 B는 **모래시계 형태**: 가운데 chunk 경계를 기준으로 큰 값이 위, 작은 값이 아래에 배치.

```
chunk 크기: 100개 → 15, 500개 → 30
```

#### 단계 3. B → A 이동 (`push_to_a`)
B에서 가장 큰 인덱스(`b->size - 1`)를 가진 노드를 찾아 최단 경로(`rb` 또는 `rrb`)로 상단에 올린 뒤 `pa`로 A에 삽입.  
→ 매 반복마다 정렬된 상태로 A에 쌓임.

---

## 🏗️ 자료구조

이중 연결 리스트(`Doubly Linked List`) 기반 스택 구현.

```c
typedef struct s_node {
    int     value;    // 실제 정수값
    int     index;    // 정렬 순위 (0 ~ N-1)
    t_node  *next;    // 다음 노드 (스택 하단 방향)
    t_node  *prev;    // 이전 노드 (스택 상단 방향)
} t_node;

typedef struct s_stack {
    t_node  *top;     // 스택 최상단 노드
    int     size;     // 현재 스택 크기
} t_stack;
```

---

## 🤖 AI 활용 고지

개발 과정에서 AI(Gemini)를 아래 목적으로 활용하였습니다.

- **에러 디버깅:** 이중 연결 리스트의 NULL 종단 처리 및 포인터 연결 무결성 검증, `stack->size` 중복 업데이트 논리 오류 식별 및 수정
- **알고리즘 최적화:** 데이터 크기별 최적 chunk 값 설정 및 rotate 연산 최소화 방안 검토
- **문서화:** README 작성 및 코드 가독성 향상을 위한 리팩토링

---

# 42-push_swap
