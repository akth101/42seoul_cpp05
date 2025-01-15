# cpp05
cpp의 exception에 대해 배우는 과제입니다.

---
목차
1. 과제를 통해 알게 된 것  
2. 평가 피드백
---

1-1) exception의 기본 사용법  
주로 아래와 같이 try catch문과 같이 사용됩니다.
~~~ c++
    try {
        if (숫자 < 0) {
            throw new Exception("음수는 처리할 수 없습니다");
        }
        // 정상적인 계산 진행
    } catch (Exception e) {
        // 오류 처리
    }
}
~~~

1-2) 왜 굳이 exception을 사용하는가?  
명확하고 직관적인 방식인 if-else 대신 왜 try-catch를 사용하는지 의문이었습니다. 그러나 비즈니스 로직과 에러 처리 로직을 명확히 구분할 수 있다는 장점이 있다는 것을 새로 알게 되었습니다.  

참고:
https://nx006.tistory.com/32

2. 평가 피드백
<img width="975" alt="image" src="https://github.com/user-attachments/assets/b7c25d78-06d6-41a1-87cc-2f2f7b4f6090" />


