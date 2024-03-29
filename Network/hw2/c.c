#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

int sockfd; //伺服器socket
int filefd,G=0,IsMe=0; //G判斷遊戲是否啟動  //(le1=='O')IsMe=1，反之，用來判斷目前是圈還是叉
char* IP = "192.168.10.143";//服务器ip位置
short PORT = 10222; //服务器服务端口
typedef struct sockaddr SA;
char name[30];  //紀錄名字
char passwd[30]; //紀錄密碼
int oppofd;//sever消息
char opponame[100],x[9],le1='O',le2='X'; //len1是圈 len2是叉


void init(){
	/* create socket */
	sockfd = socket(PF_INET,SOCK_STREAM,0);
	
	// 創建socket的寫法，用INADDR_ANY，匹配任何客戶端請求。  
	struct sockaddr_in addr;                 
	addr.sin_family = PF_INET;
	addr.sin_port = htons(PORT);//具体的IP地址
	addr.sin_addr.s_addr=htonl(INADDR_ANY);//端口

	//無法連接
	if (connect(sockfd,(SA*)&addr,sizeof(addr)) == -1){
		perror("無法連接");
		exit(-1);
	}
	printf("[INFO] Client start Successfully !\n");
}

//贏的連線條件
int iswin(char le)
{
	if(x[0]==le&&x[1]==le&&x[2]==le)return 1;
	if(x[3]==le&&x[4]==le&&x[5]==le)return 1;
	if(x[6]==le&&x[7]==le&&x[8]==le)return 1;
	if(x[0]==le&&x[3]==le&&x[6]==le)return 1;
	if(x[1]==le&&x[4]==le&&x[7]==le)return 1;
	if(x[2]==le&&x[5]==le&&x[8]==le)return 1;
	if(x[0]==le&&x[4]==le&&x[8]==le)return 1;
	if(x[2]==le&&x[4]==le&&x[6]==le)return 1;
	return 0;
}

//打印結果
void print()
{
	printf("%c|%c|%c\n",x[0],x[1],x[2]);
	printf("------\n");
	printf("%c|%c|%c\n",x[3],x[4],x[5]);
	printf("------\n");
	printf("%c|%c|%c\n",x[6],x[7],x[8]);
}

//輸的條件
int isfair()
{
	int i;
	for(i=0;i<9;i++)
	{
		if(x[i]==' ')return 0;
	}
	return 1;
}
void start(){ //開始通信

	char buf2[100] = {};
	while(1){
		recv(sockfd,buf2,sizeof(buf2),0); //讀取資料
		if (strcmp(buf2,"authenticate") == 0){
			send(sockfd,name,strlen(name),0);  //send()會回傳傳輸的總大小值
			break;
		}
	}
	pthread_t id;//啟動一個線程，用來接收服務器消息
	void* recv_thread(void*);
	pthread_create(&id,0,recv_thread,0);
	char *ptr;
	ptr=strstr(name,":");
	*ptr='\0';
	int f=1;
	while(1){//不斷發送數據
		char buf[100] = {};
		fgets(buf, sizeof(buf), stdin);
		if(G==1&&IsMe==1&&f==1) 
		{
			print();
			printf("Please enter #(0-8)\n");
			f=0;
		}
		if(G==1)f=0;
		char *ptr = strstr(buf, "\n");
		*ptr = '\0';
		char msg[131] = {};
		if (strcmp(buf,"bye") == 0){    //退出聊天室
			memset(buf2,0,sizeof(buf2));
			sprintf(buf2,"[INFO] %s 退出了聊天室",name);
			send(sockfd,buf2,strlen(buf2),0);
			break;
		}
		if (strcmp(buf,"ls") == 0){ //打印在線名單(除自己外)
			memset(buf2,0,sizeof(buf2));
			sprintf(buf2,"ls");
			send(sockfd,buf2,strlen(buf2),0);
		}
		else if(buf[0]=='@')//指定對手
		{
			sprintf(msg,"%s",buf);
			send(sockfd,msg,strlen(msg),0);
		}
		else if(buf[0]=='#') //
		{
			if(G==0)printf("Game is end or not start.\n");
			else if(IsMe==0)printf("Is not your part.Please wait your opponent.\n");
			else{
				int n=atoi(&buf[1]);
				if(x[n]!=' '||n>9||n<0)//輸入了重複的數字或不在範圍
				{
					printf("Please enter another number.#(0-8)\n");
				}
				else
				{
					x[n]=le1;
					printf("----------\n");
					print();
					if(iswin(le1))//le1贏了
					{
						printf("[INFO]You win!\n\n");
						G=0;
					}
					else if(isfair())
					{
						printf("[INFO]Fair\n\n");
						G=0;
					}
					else printf("\nWait for your opponent....\n");
					IsMe=0;
					sprintf(msg,"#%d %d",n,oppofd); //給sever消息
					send(sockfd,msg,strlen(msg),0);
				}
			}
		}
		else if(strcmp(buf,"yes")==0) //同意對戰
		{
			printf("[INFO]connect sucessful\n");
			sprintf(buf,"AGREE %d",oppofd);//給sever消息
			send(sockfd,buf,strlen(buf),0);
			printf("[INFO]Game Start!\n");
			int i;
			for(i=0;i<9;i++)x[i]=' ';//全空
			le1='O';le2='X';
			G=1;
			if(le1=='O')IsMe=1;
			else IsMe=0;
			if(IsMe)printf("Press Enter to continue...\n");//輸入enter繼續
			else printf("Wait for your opponent....\n");//等待的人的界面
		}
		else if(buf[0]=='#')
		{
			x[atoi(&buf[1])]=le2;
			if(iswin(le2))//le2贏了
			{
				printf("You lose!\n\n\n\n");
				G=0;
			}
			else if(isfair())
			{
				printf("Fair!\n\n\n\n");
				G=0;
			}
			IsMe=1;;
		}
		else if(strcmp(buf,"print")==0) //輸出目前對戰的九宮格情況
		{
			print();
		}
		else if(buf[0]!='\0'){
			sprintf(msg,"[%s] : %s",name,buf);//聊天輸出，聊天室功能
			send(sockfd,msg,strlen(msg),0);
		}
	}
	close(sockfd);
}

void* recv_thread(void* p){ 
	char *ptr,*qtr;
	while(1){
		char buf[100] = {};
		if (recv(sockfd,buf,sizeof(buf),0) <= 0){ //連接失敗
			return;
		}
		if (strcmp(buf,"authenticate") == 0){ //認證通過
			send(sockfd,name,strlen(name),0);
		}
		else if(strncmp(buf,"CONNECT ",8)==0)
		{
			ptr=strstr(buf," ");
			ptr++;
			qtr=strstr(ptr," ");
			*qtr='\0';
			strcpy(opponame,ptr);
			qtr++;
			oppofd=atoi(qtr);
			printf("[INFO]Do you agree to start a new game with [%s] ?\n",opponame);
		}
		else if(strncmp(buf,"AGREE ",6)==0)//邀請通過
		{
			ptr=strstr(buf," ");
			ptr++;
			qtr=strstr(ptr," ");
			*qtr='\0';
			strcpy(opponame,ptr);
			qtr++;
			oppofd=atoi(qtr);
			printf("[INFO]%s agree with you.\n",opponame);
			printf("[INFO]Game Start!\n");
			int i;
			for(i=0;i<9;i++)x[i]=' ';
			le1='X';le2='O';
			G=1;
			if(le1=='O')IsMe=1;
			else IsMe=0;
			if(IsMe)printf("Press Enter to continue...\n");
			else printf("Wait for your opponent....\n");
		}
		else if(buf[0]=='#')
		{
			x[atoi(&buf[1])]=le2;
			if(iswin(le2))
			{
				printf("[INFO]nYou lose!\n\n");
				G=0;
			}
			else if(isfair())
			{
				printf("[INFO]yFair!\n\n");
			}
			else{
				IsMe=1;
				print();
				printf("Please enter #(0-8)\n");
			}
		}
		else{
			printf("%s\n",buf);
		}
	}
}

int main(){
	init();
	printf("[INFO] 請輸入帳號 :");
	scanf("%s",name);
	printf("[INFO] 請輸入密碼 :");
	scanf("%s",passwd);
	strcat(name,":");
	strcat(name,passwd);
	strcat(name,"@");
	start();
	return 0;
}

