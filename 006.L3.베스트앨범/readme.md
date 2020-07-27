https://programmers.co.kr/learn/courses/30/lessons/42579

---- map 사용법 ----

- map의 value로 정렬하기는 어렵다 (vector로 복사해서 정렬함)
- map의 key는 변경이 어렵다 (삭제하고 새로 insert)
- map의 value 참조: iterator->second
- multimap은 insert로만 삽입 ("m1.[key] = value" 불가)

---- tuple 사용법 ----

- tuple 참조: get<<i>i>(tuple)



```c++
1. genre의 누적 plays -> (key, value) = (genre, palys)인 map 생성

2. 가장 큰 plays -> 생성한 map을 plays(map의 value)로 정렬
   정렬하기 위해 map을 vector로 복사하기: copy( m1.begin(),
                                            m1.end(),
                                            back_inserter<>(v1) )

3. i를 find하기 위해 {genre, plays, i}를 담은 multimap을 plays로 정렬
   정렬을 위해 vector<tuple> 먼저 생성
   plays로 정렬 한 vector를 (key, value) = (genre, {plays, i})인 map으로 복사

4. 가장 큰 plays의 genre(key)를 multimap(key)에서 find
```

