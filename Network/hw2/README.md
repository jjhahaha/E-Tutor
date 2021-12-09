hw2


### 程式流程
#### Server端
先設好socket後，每當有client要連線就創造一個新thread去處理它，並把client的sockfd放到fd陣列中。
和client端連線成功後會先要求client端登入，若登入成功並開始不段監聽client的要求。

(1)如果收到ls便列出所有的在線名單的帳號和對應的fd。

(2)若收到@fd，即表示想和哪個client發起對戰，server會發出CONNECT訊號去詢問被邀請的client端，若client端同意，回傳AGREE訊號，雙方建立連線開始遊戲。

(3)若收到#(0~8)代表想把圈圈叉叉下在哪個位置，server端會直接傳給對手的client端。

(4) 當成公聊訊息，傳給所有連線的client

#### Client端
先設好socket後連上server，要求使用者輸入帳密登入，成功後使用者便進入遊戲間。
client不停等著使用著的輸入和server傳來訊息。
遊戲開始後，提醒玩家到誰下，並每一輪都印出棋盤，不斷確認是否有分出輸贏或是平手。
##### 使用者輸入處理
(1)ls => 列出在線名單(除自己外)

(2)bye => 登出

(3)@fd => 發出邀請並建立連線

(4)#(0~8) => 下棋(要確認遊戲開始並且是輪到自己下時才能使用，否則會被擋掉)

(5)其餘=>在公頻上發出訊息
##### Server傳訊處理
(1)CONNECT => 輸出詢問是否想和某某某一起玩遊戲

(2)AGREE => 對方答應一起玩遊戲，正式開啟遊戲

(3)server-req-name ? => 登入

(4)#(0~8) => 對手要把棋下在哪裡

(5)其餘 => 直接印出來


#####參考

https://www.youtube.com/watch?v=QVZcMx3jtG8&t=3070s

https://www.bilibili.com/video/BV1Eb411v7iT/
