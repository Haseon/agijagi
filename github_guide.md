## 깃헙에 과제물 올리기

1. github에 가입한다
2. create repository로 agijagi 생성
3. git 설치
4. cmd.exe 혹은 Git Bash를 켜서 명령어 실행 시작
5. git config --global user.name "자기 유저네임"으로 유저네임 설정. (따옴표 쓰기)
6. git config --global user.email "깃헙에서 사용하는 이메일주소"로 이메일주소 설정
7. "git clone https://github.com/(자기 깃헙 username)/agijagi"를 입력해서 해당 페이지 내용을 클로닝하기
8. "cd agijagi"로 agijagi 폴더로 들어가고 "mkdir FizzBuzz"를 입력해서 agijagi (master)에 FizzBuzz 폴더를 생성합니다. 
9. FizzBuzz 폴더에 자신이 작성한 코드를 넣기. (커맨드라인에 익숙하지 않다면 파일탐색기에서 드래그로 끌어서 넣어도 되고, 또는 move(cmd.exe의 경우)/mv(bash의 경우) 명령어를 입력해서 옮기면 됩니다. move(또는 mv) [원래주소\파일이름] [옮길 위치의 주소\파일이름] 같은 식으로 입력하면 되는데 잘 안 되시면 도와드릴게여)
10. "git add FizzBuzz"로 FizzBuzz 폴더를 프로젝트에 추가합니다. 혹은 git add . 라고 .를 쓰면 전부 자동으로 추가되니 이 방법도 좋습니다.
11. "git commit" 또는 git commit -m "메시지 내용"으로 이 내용을 커밋합니다. (버전 관리 시스템에서 변화가 기록되는 중간 저장 같은 느낌)
12.  "git push origin master"라고 해서 master의 내용을 origin(아까 그 온라인 사이트)로 집어넣습니다. 이때 로그인창이 뜨면 로그인합니다. 
13. 자신의 깃헙 페이지를 들어가보면 코드가 올라와있는 걸 확인할 수 있습니다.

## 과제 제출 방법

과제물을 깃헙에 업데이트할 때마다 매번 링크를 올릴 순 없으니 참여자들은 본인의 깃헙 아기자기 저장소 주소를 댓글로 올려주시기 바랍니다. 앞으로는 매번 링크를 올리지 마시고 제출했다고 언급만 해주시면 될 것 같습니다. 
