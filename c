#c语言变量的名字一定要形象，否则一无是处 ———— BinGostar



双引号里面的是字符串 而单引号里面的代表字符

指针初始化时，“=”的右操作数必须为内存中数据的地址，不可以是变量，也不可以直接用整型地址值(但是int*p=0;除外，该语句表示指针为空)。此时，*p是表示定义的是个指针变量，并没有间接取值的意思

Int *s=15; Int *s={2,3,5}; Int *s=a; 
以上这三种初始化方式都是错误的。

int a,*pa=&a;   #C语言定义，先定义指针pa，然后pa=&a（pa是地址，*pa是变量）

但是对于字符串 可以 char *a="dsadadad";  #字符串本身包含地址

printf("%s",a);   #正确   显示整个字符串
printf("%c",*a);  #正确   显示第一个字符  


int b,*a;
*a=b 或者 a=&b; ###指针pa已经定义完毕，*a=b 正确

int a[10]={...}  #定义时可以这么用

a[10]={....} #定以后，错误


事实上，数组a就是一个指针！！！  但是a是数组首元素的首地址，&a 是整个数组的首地址，虽然值相同，但是类型不同
例如：
int a[10];
printf("%p %p\n",a,&a);
0x7fff862bc210 0x7fff862bc210

int *p1[10]; 指针数组（先定义一个数组，p1,p1里有十个元素，并且每个元素是一个指针）


int (*p2)[10]; 数组指针（先定义一个指针，p2，p2指向一个10个int的数组）
int (*p2)[10] = new int[2][10];new了一个二维数组, 去掉最左边那一维[2], 剩下int[10], 所以返回的是一个指向int[10]这种一维数组的指针int (*)[10].  
int (*p3)[2][10] = new int[5][2][10];  new了一个三维数组, 去掉最左边那一维[5], 还有int[2][10], 所以返回的是一个指向二维数组int[2][10]这种类型的指针int (*)[2][10].


int a[10];
int* b;
int (*c)[10]; /*等价于 int c[][10] */
b=a;
c=&a;      /*c是数组指针，它代表整个数组，所以要有&a来赋值，&a他是数组a的指针代表*/
printf("%d %d",b[1],(*c)[1]);

int* a;
a=NULL; #空指针



定义一定大小的数组是，当对某一块内存没有赋值，那么这块内存的值是0

int a[]={1,2,3,4},*b=a;  #正常模式
printf("%d\n",*b);

char a[]="adsdss",*b=a;  #字符串陷阱 
printf("%s\n",b);        #虽然 b是指针，但是对于字符串来说，b此时就是个字符串！！！
printf("%c\n",*b)

void 代表无返回类型

%p 输出指针地址

&i[1] #表示i数组第二个元素的地址

‘’字符  “”字符串

int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}}；
printf("%d\n",**(a+1));

指针的sizeof，就是他地址的sizeof

数组空值问题
例如：
int a[10]={1,2};
a[3]   0       #在范围内没有定义的是0
a[14]  4142134  #在范围外的就是乱码了（地址）


二维数组申请空间
int** a,i;
a=(int**)malloc(999*sizeof(int)); #理解含义 (int**) 表示先为他申请空间
for (i = 0; i < 999; ++i)
{
	a[i]=(int*)malloc(1000*sizeof(int)); #理解含义 (int*) 表示再为他申请空间
}
a[123][124]=2323;

int* a;
野指针


指针历史悠久，单纯的指针除了地之外，不会带其他任何信息！！
例如：
int a[10];#静态数组  内存大小不能改变
int* b=a;
sizeof(a)  10
sizeof(b)  没有，b只是一个指针！！！！


getchar 和 putchar 会把\n也输出


EOF是end of file的缩写，表示"文字流"（stream）的结尾。这里的"文字流"，可以是文件（file），也可以是标准输入（stdin）。
EOF不是特殊字符，而是一个定义在头文件stdio.h的常量，一般等于-1。
#define EOF (-1)
除了表示文件结尾，EOF还可以表示标准输入的结尾。但是，标准输入与文件不一样，无法事先知道输入的长度，必须手动输入一个字符，表示到达EOF。

feof(fp);


FILE* fp
(fp=fopen("c:\\hzk16","rb")==NULL   /*打开文件失败*/
fclose(fq)
fgetc函数的功能是从指定的文件中读一个字符
ch=fgetc(fp)
fputc('a',fp)
fputc函数有一个返回值，如写入成功则返回写入的字符， 否则返回一个EOF
读字符串函数fgets函数的功能是从指定的文件中读一个字符串到字符数组中，函数调用的形式为： fgets(字符数组名，n，文件指针) ,返回值是字符数组的首地址
fputs函数的功能是向指定的文件写入一个字符串
fputs(“abcd“，fp)；

 fprintf(fp, "%d", buffer); 是将格式化的数据写入文件
fprintf(文件指针,格式字符串,输出表列);

fwrite(&buffer, sizeof(int), 1, fp);是以二进位方式写入文件
fwrite(数据，数据类型大小（字节数），写入数据的最大数量，文件指针);


fread将文件的磁盘内容直接读入。fscanf将文件的磁盘内容作为ASCII码转换成对应的字符，然后再读入

判断是否读到文件末尾 feof()


strcmp(a,b)  /*判断两个字符串是否相等*/

strcpy(char* des,const char* source)   /*赋值字符串source内容到des中*/

sizeof(char*)  /*char指针类型长度*/


申请多字符串数组内存
bamfilelist = (char**)malloc(sizeof(char*)*bamfiles); 
for (i=0;i<bamfiles;i++) bamfilelist[i] = (char*)malloc(1024);

char* a;
int b=(int)*a   /*将第一个字符转成ACSII*/

int=atoi（str）/*将str转换成int*/
 
float=atof(str) /*将str转换成float/

strlen(str)  /*字符串长度*/

sprintf(fastaindexfile,"%s.fai",fastafile);

内核启动的时候默认打开这三个I/O设备文件：标准输入文件stdin，标准输出文件stdout，标准错误输出文件stderr，分别得到文件描述符 0, 1, 2。

struct ！！！！！！！！！！！！！！！
typedef struct
{
}structure；
structure* x; /*创建结构指针，指针->structure*/
理解：此时x指针指向一个结构类structure

x=(struct*)malloc(sizeof(struct)*n); /*与二级指针区别，这不是二级指针，创建是struct指针类型的存储，每个大小是sizeof（struct），创建n个*/
非常重要，可以理解为创建n个指向structure的指针：point1，point2,point3...,其中可以看成structure* point1，structure* point2。。。
所以，&x[0]就是point1
	mlx* structure;
	structure=(mlx*)malloc(sizeof(mlx)*10);
	structure->a='a';
	printf("%p %c\n",structure,structure->a);
	(&structure[0])->a='b';
	printf("%p %c\n",&structure[0],structure->a);


exit(0) /*C语言退出*/

文件操作
open(file,'r')==NULL  /*等于NULL打开文件错误*/
(ch=getc(in))!=EOF     /*读取每一行错误或者读到结尾 类似于 fget(buffer,x,in)!=NULL*/
fclose(in)!=0      /*b不等于0 表示关闭错误*/
						
pow(m,n) //m的n次方

#include<stdlib.h>
srand((unsigned int)time(NULL));
rand()%1398101+0;



strcmp
C/C++函数，比较两个字符串
设这两个字符串为str1，str2，
若str1=str2，则返回零；
若str1<str2，则返回负数；
若str1>str2，则返回正数

atoi
把字符串转换成整型数
字符串转换成整型数

sizeof不能求得动态分配的内存的大小! 
char* x[10];  x为静态内存,可以用sizeof(x)
char* x=(char*)malloc(100)  x为动态内存，不能用sizeof(x)

时间：
#include<time.h>

int main()
{
    time_t timep;
   
    time(&timep); /*获取time_t类型当前时间*/   
    /*转换为常见的字符串：Fri Jan 11 17:04:08 2008*/
    printf("%s", ctime(&timep));
    return 0;
}

排序
qsort(flist,*fragments,sizeof(FRAGMENT),compare_fragments);


(int)(char -48)

结构体指针与结构体的区别：
struct type* x;  #指针定义完，必须要为他分配空间！！！！！！！！！！！！！！！
x=(struct type*)malloc(sizeof(struct type));
x->a=2;
printf("%i\n",x->a);
struct type y;
y.a=2;
printf("%i\n",y.a);




int abs(int i);                   // 处理int类型的取绝对值

double fabs(double i); //处理double类型的取绝对值

float fabsf(float i);           /处理float类型的取绝对值


register int x;
CPU有高速缓存，那个速度非常快，但很小，加这个后，这个变量的存放位置就在register高速缓存里。一般用于频繁修改的全局变量


传递数组是，最好把数组的长度传进去

随机数公式
s=RAND_MIN+(int)(rand()%(RAND_MAX_i-RAND_MIN+1));

指针作为参数传递进去的仅仅只是指针的值，而不是指针的地址，或者说只是指针的一份拷贝
例如：
void func(int *p2){
	注意此时p2代表的是a的数值，就是  p2 == p1 ;但是&p2 != &p1

	如果：
	p2=(int*)malloc(sizeof(int)*100);
	此时在&p2处申请了100个int内存，但是&p1还是个空指针

	
}

int main(){
	int *p1;
	int a=2;
	p1=&a;
	func(p1);
}


文件操作
#include<stdio.h>
FILE* fp;
fp=fopen(char* path,'r');
fp=fopen(char* path,'r+');
fp=fopen(char* path,'w');
fp=fopen(char* path,'w+');

判断打开是否正确
fp==NULL

判断文件结尾
!feof(fp)

char a[1024];
读取一行：
char* p
p=fgets(a,1024,fp)!=NULL;   #读取一行，遇见\n结束 然后在末尾加上\0
如果读取成功 返回指针，这个指针就是a的指针（p=a）

sscanf(line, "%d %d %d",&array[i * 3], &array[i * 3 + 1], &array[i * 3 + 2]);

输出：
fprintf(handle, "%d\t%d\t%d\n", x[i], y[i], counts[i]);

feof（检查文件流是否读到了文件尾）

fflush(fp)  /*清楚缓冲区*/


#----------
fseek（移动文件流的读写位置）
fseek(stream,5,SEEK_SET);
SEEK_SET从距文件开头offset位移量为新的读写位置；SEEK_CUR 以目前的读写位置往后增加offset个位移量；SEEK_END将读写位置指向文件尾后再增加offset个位移量
ftell（取得文件流的读取位置）
fread（）读的过程本身就是一个文件位置指针移动的过程
fwrite（将数据写至文件流）#用来读写数据
#----------

getchar()   /*缓存输入*/
getch()	    /*非缓存输入*/

    switch(day){
        case Mon: puts("Monday"); break;
        case Tues: puts("Tuesday"); break;
        case Wed: puts("Wednesday"); break;
        case Thurs: puts("Thursday"); break;
        case Fri: puts("Friday"); break;
        case Sat: puts("Saturday"); break;
        case Sun: puts("Sunday"); break;
        default: puts("Error!");
    }


char str[20];
memset(str, '\0', sizeof(str)-1);

char* a="dsdsadsad";
srtcpy(a,"dsada");   #错误 a就是个指针

char a[20]="dsdsadsad";
srtcpy(a,"dsada");   #正确
1）字符串操作
strcpy(p, p1) 复制字符串
strncpy(p, p1, n) 复制指定长度字符串
strcat(p, p1) 附加字符串
strncat(p, p1, n) 附加指定长度字符串
strlen(p) 取字符串长度
strcmp(p, p1) 比较字符串
strcasecmp忽略大小写比较字符串
strncmp(p, p1, n) 比较指定长度字符串
strchr(p, c) 在字符串中查找指定字符
strrchr(p, c) 在字符串中反向查找
strstr(p, p1) 查找字符串
strpbrk(p, p1) 以目标字符串的所有字符作为集合，在当前字符串查找该集合的任一元素
strspn(p, p1) 以目标字符串的所有字符作为集合，在当前字符串查找不属于该集合的任一元素的偏移
strcspn(p, p1) 以目标字符串的所有字符作为集合，在当前字符串查找属于该集合的任一元素的偏移 
* 具有指定长度的字符串处理函数在已处理的字符串之后填补零结尾符  

fp=fopen(infile,"r");正确
fp=fopen(infile,'r');错误

char* find
find=strchr(st,'\n') #查找换行符
*find='\0'

#include <time.h>

	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	printf("%s\n",asctime(timeinfo) );
     
你说的ULONG 应该是一个宏定义。
从字面意思应该对应的是C中的unsigned long这个类型

解压缩

char zipfile[20]="read.txt.gz";
gzFile gzfp;
gzfp=gzopen(zipfile,"r");
char line[1000];
while(gzgets(gzfp,line,1000)!=NULL){
	int len=strlen(line);
	printf("%s %d\n",line,len);

}
gzclose(gzfp);

注意！！！ 编译时 用 gcc test.c -lz


压缩
char* infile="output.txt";
FILE* fp=fopen(infile,"rb");
gzFile gzfp=gzopen("output.txt.gz","wb");
char inbuffer[200];
int n;
while((n=fread(inbuffer,sizeof(char),sizeof(inbuffer),fp))>0){
	printf("%d\n",n);
	gzwrite(gzfp,inbuffer,n);
}
fclose(fp);
gzclose(gzfp);
上面有问题！！！
fread指的从文件中的取数据
gzwrite应该这样用
gzwrite(gzfp,inbuffer,strlen(inbuffer))




assert((des != NULL) && (source != NULL));


被调用的函数，要写在调用函数之前
struct必须这样写！！！ 前后两个aa不能省！！
typedef struct aa{

}aa;

void a;
int* b=(int*)a;  /*将a转成类型为int的指针*/


char* a="abc";
a+=3;
if(!*a){ //此时 *a == '\0'
	puts("YES");
}

char* a="abcd";
char x;
while(x=*(a++)){
 putc(x);  // a b c d
}
while(x=*(++a)){
putc(x);  // b c d
}

void func(int** a){
	int* b;
	b=(int*)malloc(sizeof(int)*3);
	*a=b;
}

int main(){
	int* a;
	func(&a);
	a[2]=2;

}

静态编译与加载（align.h align.c main.c）
gcc -c align.c  //生成align.o
ar cr libalign.a align.o  //编译成静态库  注意 lib+库名  .a 表示静态库
gcc -o aaa  test.c -L. -lalign    //加载库

动态编译：
gcc -c -fPIC max.c
gcc -shared -o libmax.so max.o
（gcc align.c -shared -fPIC -o libalign.so ）
gcc -o aaa  test.c -L. -lalign


注意！！！！！！！！！！！！！！！
目前name.h头文件的变量建议放在name.c中！！！！

gcc/g++命令中关于库的参数:
    -shared： 该选项指定生成动态连接库；
    -fPIC：表示编译为位置独立(地址无关)的代码，不用此选项的话，编译后的代码是位置相关的，所以动态载入时，是通过代码拷贝的方式来满足不同进程的需要，而不能达到真正代码段共享的目的。
    -L：指定链接库的路径，-L. 表示要连接的库在当前目录中
    -ltest：指定链接库的名称为test，编译器查找动态连接库时有隐含的命名规则，即在给出的名字前面加上lib，后面加上.so来确定库的名称

    -Wl,-rpath: 记录以来so文件的路径信息。
    LD_LIBRARY_PATH：这个环境变量指示动态连接器可以装载动态库的路径。
     当然如果有root权限的话，可以修改/etc/ld.so.conf文件，然后调用 /sbin/ldconfig来达到同样的目的，

     不过如果没有root权限，那么只能采用修改LD_LIBRARY_PATH环境变量的方法了。 


struct x[10];
qsort(x,10,sizeof(struct),func);

int func(const void* a, const void* b){
	return((*(matrix*)a).score-(*(matrix*)b).score);
}

！！！！！！！不能改变字符串常量的值
char* a="dsada";
a[1]='W';  //错误

但是
char a[10]="dsadsada";
a[1]='w';  //可以

但是
char* a=(char*)malloc(sizeof(char)*10);
a[0]='a';   //可以！！！！
注意：此时指针a的这块内存 就是字符数组，如果a="dasdada";此时a的地址变了，它代表了僵硬的字符串！！！


char string[] = "A string\tof ,,tokens\nand some  more tokens";  
	char seps[]   = " ,\t\n";  
	char *token;  
	token = strtok( string, seps ); 
	while(token != NULL){
		puts(token);
		token=strtok(NULL,seps);
	}

!feof(gzfp)  判断文件末尾


注意！！！函数只返回 malloc申请内存的指针，不返回a[10]类型的指针，因为a是局部环境申请的！！！！！

char a[10]="dadsa";
a++;    //不可以

char* a="dsadsad";
a++;  //可以


C语言字符串没有切片！！！！！！
char a[10];
char b[10];
char c[10];
char* w[3]={a,b,c};  //可以
char** w={a,b,c};     //不行

#include <ctype.h>
isdigit(char)
若参数c 为阿拉伯数字，则返回非0，否则返回0。


注意！！！
char* a="dadadasd";
char b[20];
b=a;   //错误
char* b;
b=a;    //可以
总结：
对于a[n]这种变量，其实就是在栈中开拓出n个区域赋值给a, a不能赋给其他东西！！！！！


#include <unistd.h>
sleep(3);


查看缓冲区大小（字节）
printf("%d", BUFSIZ);

 int setvbuf(FILE * stream, char * buf, int type, unsigned size);
【参数】stream为文件流指针，buf为缓冲区首地址，type为缓冲区类型，size为缓冲区内字节的数量。
参数类型type说明如下：
    _IOFBF (满缓冲)：当缓冲区为空时，从流读入数据。或当缓冲区满时，向流写入数据。
    _IOLBF (行缓冲)：每次从流中读入一行数据或向流中写入—行数据。
    _IONBF (无缓冲)：直接从流中读入数据或直接向流中写入数据，而没有缓冲区。
【返回值】成功返回0，失败返回非0。
e.g.setvbuf(input, bufr, _IOFBF, 512)


void setbuf(FILE * stream, char * buf);
【参数】stream为文件流指针，buf为缓冲区的起始地址。


#--------匹配----------------

REG_EXTENDED 以功能更加强大的扩展正则表达式的方式进行匹配。
REG_ICASE 匹配字母时忽略大小写。
REG_NOSUB 不用存储匹配后的结果。
REG_NEWLINE 识别换行符，这样'$'就可以从行尾开始匹配，'^'就可以从行的开头开始匹配。


char* str="aaadsdasad";
regex_t reg;
char* pattern="^aaad";
regcomp(&reg,pattern,REG_EXTENDED|REG_ICASE);
regmatch_t pmatch[1];
int status;
status=regexec(&reg,str,1,pmatch,0);
printf("%d\n",status);
if (status == 0){
	printf("%d %d\n",pmatch[0].rm_so,pmatch[0].rm_eo);
}
regfree(&reg);
#---------------------------
#include <mach.h>
double ceil(double x);
 
double floor(double x);
 
double round(double x);

注意！！！
int a=ceil((float)17/3);



字符串中变量
sprintf(atcmd10,"AT^SISW=1,%d\r",9);
fprintf(out,...) !!

相除！！！
1.0*x/y     必须要1.0

计算运行时间
clock_t s,e;
s=clock()
...
e=clock()
printf("%.3f\n",(double)(e-s)/CLOCKS_PER_SEC);

void func(int ** a){
}

int a[3][4];
func(a);
错误!!!!
二维数组传参 不能用上面的方式！！ 虽然一维可以
而且 二维数组 不等于 二维指针

数组传参可以改变数组的内容  指针传参也可以改变他的的内容

int main(){
	char str[10];
	substr(str,3);
	puts(str);
	return(0);
}

数组是个比较死的东西
例如
char a[10];
char* b="dasda";
a=b   //错误！！！


char str[]="1234xyz";
char *str1=strstr(str,"34");
cout << str1 << endl;


gzopen* gzfp
char* line="dsadsadadd";
gzread(gzfp,line,100)

二维数组指针赋值；
    main(){
        int a[3][4]={0,1,2,3,4,5,6,7,8,9,10,11};
        int(*p)[4];
        int i,j;
        p=a;
        for(i=0;i<3;i++){
            for(j=0;j<4;j++) printf("%2d  ",*(*(p+i)+j));
            printf("\n");
        }
    }

一位数组传参
void func(char* a ){
	a[0]='2';
}



int main(){
	char a[4];
	func(a);
	puts(a);
	return(0);
}

二维数组传参
void func(char (*a)[5]){
}

int main(){
	char a[4][5];
	func(a);
	char (*b)[5];
	b=a;
	func(b);
	func(a);
}

没有unsigned float 


n*2   n << 1
n/2   n >> 1
n*(2^m)  n << m
2^n      2 << (n-1)


字符串数组
char* a[]={"dsad","gfdg","tyrtyryr"}; //必须这样定义
char b[10];
strcpy(b,a[1]);		//[]具有降级的作用  a表示二级指针， a[1]  表示 *（a+1）
strcpy(b,*(a+1));	//


指针申请空间不能放在外部！！！

获得当前路径；
#include <unistd.h>

getcwd(char* a,len);


遍历目录下的文件
#include <sys/types.h>   
#include <dirent.h>
DIR *dirptr = NULL; 
struct dirent* entry;
dirptr=opendir("./")
entry=readdir(dirptr)
closedir(dirptr)


子进程投递shell
char * argv[]={"sleep","4",};

    if(vfork() ==0)
    {
        execv("/bin/sleep",argv);
    }else{        
        printf("This is the parent process\n");
    }
	wait();

创建文件夹
#include <sys/stat.h> 
int mkdir(const char *path, mode_t mode); 
if (mkdir(dir,0755)<0){
	puts("wrong");
}	

返回0 表示成功， 返回 -1表示错误



判断文件 文件夹是否存在
#include <unistd.h>
int access(const char *pathname,int mode);

pathname:是文件名称
mode是我们要判断的属性.可以取以下值或者是他们的组合:
R_OK文件可以读
W_OK文件可以写
X_OK文件可以执行
F_OK文件存在.

当我们测试成功时,函数返回0,否则如果有一个条件不符时,返回-1. 


字符数组清零！！
char buf[10];
memset(buf,0,sizeof(buf));
注意memset不能放在函数外！！！！
#include <assert.h>
void assert( int expression );

多进程
pid_t pid;
	int status;
	if (fork()==0){
		printf("this is child : pid = %d\n",getpid());
		char* shell[]={"sleep","6",NULL};	
		execv("/bin/sleep",shell);
	}
	if (fork()==0){
		printf("this is child : pid = %d\n",getpid());
		char* shell[]={"sleep","12",NULL};	
		execv("/bin/sleep",shell);
	}
	int j=2;
	while (j>0){
		pid=wait(&status);
		if (pid>0){
			printf("job:%d status: %d\n",pid,status);
			j--;
		}
	}


strtok(a[X],","); //注意 第一个参数必须是a[X]


C语言on_exit()函数：设置程序正常结束前调用的函数


玄学多线程
多线程中不要关闭句柄！！！

#include <pthread.h>

pthread_t* my=(pthread_t*)malloc(sizeof(pthread_t)); //注意 定义多线程的时候必须此处给他地址！！！

pthread_t t_many[n_file];
	int cur_i;
	int cur_thread=0;
	int* ccur=(int*)malloc(sizeof(int)*n_file);
	for (cur_i=0;cur_i<n_file;cur_i++){
		*(ccur+cur_i)=cur_i;
		if (seq_type==2){
			if(pthread_create(&t_many[cur_i],NULL,(void*)split_func_pair,ccur+cur_i)){
				fprintf(stderr,"Create pthread error!\n");
			}
		}else{
			if(pthread_create(&t_many[cur_i],NULL,(void*)split_func_single,ccur+cur_i)){
				fprintf(stderr,"Create pthread error!\n");	
			}
		}

		cur_thread++;
		if (cur_thread == thread_num || cur_i == n_file - 1){
			int cur_j=0;
			while (cur_j < cur_thread){
				if (pthread_join(t_many[cur_i - cur_j],NULL)==0){
					cur_j++;
				}
			}
			cur_thread=0;
		}
	}
#-=------------------------------------------------------
进程共享内存
1、mmap保存到实际硬盘，实际存储并没有反映到主存上。优点：储存量可以很大（多于主存）（这里一个问题，需要高手解答,会不会太多拷贝到主存里面？？？）；缺点：进程间读取和写入速度要比主存的要慢。

2、shm保存到物理存储器（主存），实际的储存量直接反映到主存上。优点，进程间访问速度（读写）比磁盘要快；缺点，储存量不能非常大（多于主存）

使用上看：如果分配的存储量不大，那么使用shm；如果存储量大，那么使用shm。



size_t size=sizeof(i);
long long index,counter=0;

char* a="name\t13231 acntca\t dad\n";
char b[20];
int c;
char e[20];
char f[20];
sscanf(a,"%[a-z]%*[\t ]%d%*[\t ]%[a-z]%*[\t ]%[a-z]",b,&c,e,f);

//---------realloc 注意事项------------------------------
realloc有可能会新分配起始位点！！！！
典型事例
char** a=(char**)malloc(sizeof(char*));
*a=(char*)malloc(sizeof(char)*5);
strcpy(*a,"111");
printf("%p %p %s\n",a,*a,*a);
a=(char**)realloc(a,sizeof(char*)*200);
*(a+1)=(char*)malloc(sizeof(char)*5);	
strcpy(*(a+1),"222");
printf("%p %p %s %p %s\n",a,*a,*a,*(a+1),*(a+1));
a=(char**)realloc(a,sizeof(char*)*300);
*(a+2)=(char*)malloc(sizeof(char)*5);
strcpy(*(a+2),"333");
printf("%p %p %s %p %s %p %s\n",a,*a,*a,*(a+1),*(a+1),*(a+2),*(a+2));
a=(char**)realloc(a,sizeof(char*)*400);
*(a+3)=(char*)malloc(sizeof(char)*5);
strcpy(*(a+3),"444");
printf("%p %p %s %p %s %p %s %p %s\n",a,*a,*a,*(a+1),*(a+1),*(a+2),*(a+2),*(a+3),*(a+3));
printf("%p %p %p %p\n",a,*a,a+1,*(a+1));

0x1b63010 0x1b63030 111
0x1b63050 0x1b63030 111 0x1b63010 222
0x1b63050 0x1b63030 111 0x1b63010 222 0x1b639c0 333
0x1b639e0 0x1b63030 111 0x1b63010 222 0x1b639c0 333 0x1b63050 444
0x1b639e0 0x1b63030 0x1b639e8 0x1b63010
//-------------------------------------------------------
void temp=*vp1;  
变量是不能声明为void无类型的
不能将*用在无类型指针上，因为系统没有此地址指向对象大小的信息

#include <stdbool.h>
bool m = true;
bool n = false;

void revstr(char* s){
	char* h=s;
	char* t=s;
	char c;
	while(*t++){}
	t--;
	t--;
	while (h<t){
		c=*h;
		*h++=*t;
		*t--=c;
	}
}

memset函数按字节对内存块进行初始化，所以不能用它将int数组初始化为0和-1之外的其他值

编译器优化常用的方法有：将内存变量缓存到寄存器；调整指令顺序充分利用CPU指令流水线，常见的是重新排序读写指令
//----------------------------------------------------
int a[3][2];
	int* start=a[0];
	printf("a %p a[0][0] %p\n",a,a[0]);
	printf("a %p a[0][1] %p\n",a,a[0]+1);
	printf("a+1 %p a[1][0] %p\n",a+1,a[1]);
	printf("a+1 %p a[1][1] %p\n",a+1,a[1]+1);
	printf("a+2 %p a[2][0] %p\n",a+2,a[2]);
	printf("a+2 %p a[2][1] %p\n",a+2,a[2]+1);
	printf("%p %p %p %p %p %p \n",start,start+1,start+2,start+3,start+4,start+5);
	printf("%d\n", sizeof(a));


//----------------------------------------------------
 __LINE__        被编译文件的行数
（整型）
__FILE__  被编译文件的名字 （字符型）
__DATE__  编译日期 （字符型）
__TIME__  编译时间 （字符型）
__STDC__  如果编译器接受标准C，那么值为1. （整型） 


typedef 用来定义一个变量类型的别名。
static 不是变量类型。它定义存放方式
typedef unsigned int array64[64];
static array64 a;   // 这里可用 static

在C编译器下，结构体内不允许包含static变量。
C中struct只是类型声明，没有内存空间的分配，而static变量是需要分配内存的 !!!!
结构体是一种用户自定义类型，跟标准类型是一样的，只是由用户自己定义的罢了。类型是不能声明为Static的，只有变量才能声明为Static。因为类型只是一种抽象，不分配内存，具体的变量才能分配内存。而且Static变量是在编译的时候分配内存的。可以将结构体成员定义为Static。

说白了，结构体是类型，不占空间，

static用来定义变量，会分配空间．

把结构体声名放在一个头文件中让用到这个结构的文件包含这个头文件。
extern是指在其它文件声名的变量而不是结构体。

ulimit –s  查看堆可申请的大小


//----------------性能优化----------------------------
1、避免cache Miss（合理利用cache）
2、指令级并行（一般会自动分配，在编程的时候注意就行了？？？）
3、GCC中SIMD指令实现向量化计算（向量化指令）


矩阵处理blas库


//----------------------<termios.h>------------------------------
//https://github.com/mcandre/charm/tree/master/lib
/*
http://ubuntuforums.org/archive/index.php/t-225713.html
*/

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int getch(void);

int main()
{
 int x = ' ';
 int y = ' ';
 int z = ' ';

 printf("Press any key to continue...\n");
 x = getch();

 if (x == 27)
 {
  y = getch();
  z = getch();
  printf("Key code y is %d\n", y);
  printf("Key code z is %d\n", z);
 }
 printf("Key code x is %d\n", x);
 printf("The key you entered is: %c \n", x);

 if (x == 27 && y == 91)
 {
  switch (z)
  {
   case 65:
   printf("up arrow key pressed\n");
   break;

   case 66:
   printf("down arrow key pressed\n");
   break;

   case 67:
   printf("right arrow key pressed\n");
   break;

   case 68:
   printf("left arrow key pressed\n");
   break;
  }
 }

 return 0;
}

int getch(void)
{
 int ch;
 struct termios oldt;
 struct termios newt;
 tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
 newt = oldt; /* copy old settings to new settings */
 newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
 tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
 ch = getchar(); /* standard getchar call */
 tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
 return ch; /*return received char */
}

//------------------------sign.h-------------------------------------------------
void func(int sig){
	puts("dsadadad");
	exit(1);
}

int main(){
	signal(SIGINT,&func);
	while(1){
	}
	return(0);
}
//-------------------------readline/readline.h-----------------------------------------------------





//-----------------------------------------------------------------------------------
宏
#define MOCK_FUNC(funcName) \
     int funcName(void){printf("  Enter "#funcName"!\n"); return 0;}
 
MOCK_FUNC(ShowMeInfo);

strcasecmp（忽略大小写比较字符串）
相关函数 bcmp，memcmp，strcmp，strcoll，strncmp


__attribute__((noreturn))    表示没有返回值
__attribute__((unused))   表示该函数或变量可能不使用，这个属性可以避免编译器产生警告信息 
void __attribute__((noreturn)) handle_signal(int __attribute__((unused)) signal) {
;
  exit(0);
}
//-------------------------------------
term.c_cc[VMIN] = (cc_t) 1;  对于read函数读取一个就会进行下一步 当设为0时，表示不等待进行
tmp.c_cc[VERASE] = '\b'; 

//----动态对其内存分配
#include <malloc.h>
float* array=(float*)memalign(32,sizeof(float)*l);

//--------------指令级并行------------------------------------
编译：
gcc -Wall  -msse2 -msse3 -mavx -o a.out test.c

float* array=(float*)memalign(32,sizeof(float)*l);  数据对齐分配内存 malloc.h
int i;
for(i=0;i<l;i++){
	array[i]=(float)i;
}
__m256 b=_mm256_load_ps(array);
float* f=(float*)&b;
printf("%f\n",f[3]);

关键字__attribute__ 可以对变量 结构体（struct ）或共用体（union ）进行属性设置。大致有六个参数值可以被设定，即：aligned, packed, transparent_union, unused, deprecated 和 may_alias 。

//------------数据对齐----------------------------------------
变量的内存地址位于它长度的整数倍


void* a;
void* a_align;
int align;
a=malloc(size+align);
a_align=(void*)((int)((int*)a+align-1)&~(align-1)) ;
if (a == a_align){
	a_align=a+align;
}
此时 a_align就是对其的数组


size_t是标准C库中定义的，应为unsigned int，在64位系统中为 long unsigned int。


//-----------超级快----------------------------------------------------
double* a=(double*)memalign(32,sizeof(double)*1600000000);
int64_t i=0;
double* cur=a;
while(i<200000000){
	cur = a+i;
	*cur=(double)i;
	*(cur+1)=(double)i;
	*(cur+2)=(double)i;
	*(cur+3)=(double)i;
	*(cur+4)=(double)i;
	*(cur+5)=(double)i;
	*(cur+6)=(double)i;
	*(cur+7)=(double)i;
	i+=8;
}

gcc -O3 !!!!!!!!

//------------------------------------------------------------------------
void func(const double** x  )

func(x);  会出错！！！！！！！！！！！！

static 函数声明要写在.c文件里面

退出时调用函数
atexit (my_exit);
exit(0);

#pragma pack (2) /*指定按2字节对齐*/
__packed是进行一字节对齐
__packed struct STRUCT_TEST
{
char a;
int b;
char c;
} ;

DESTDIR=''  make install 安装目录

memchr


extern __declspec(dllexport)  
__declspec(dllexport)


pthread_create(&threads[0],NULL,(void*)func,&a);
	int d=pthread_join(threads[0],NULL);
创建线程后不要立马join 最好sleep（1）

//struct 妙用----------------------
struct a{...}a;

struct b{
	struct a a_;
	....
}b;

struct a* my;
(struct b)my;

//---------------------------------
pthread互斥量和条件变量互相用
到pthread_cond_wait (&cond,&mutex);/*等待*/。这里的线程二阻塞，不仅仅是等待cond变量发生改变，同时释放mutex锁 
mutex锁释放后，线程1终于获得了mutex锁，得已继续运行，当线程1的if（i%3==0）的条件满足后，通过pthread_cond_signal发送信号，告诉等待cond的变量的线程（这个情景中是线程二），cond条件变量已经发生了改变。

不过此时线程二并没有立即得到运行 ，因为线程二还在等待mutex锁的释放，所以线程一继续往下走，直到线程一释放mutex锁，线程二才能停止等待，打印语句，然后往下走通过pthread_mutex_unlock(&mutex)释放mutex锁，进入下一个循环。

#include  <unistd.h>
realpath（）绝对路径

Linux的read write 是非缓冲io，c标准库里的fread fwrite printf是缓冲io，非缓冲io每次操作都要与内核交互，缓冲io为了效率，在用户态有缓冲区。所以write会直接输出，printf不直接输出。printf是行缓冲，在遇到换行符，缓冲区满了，fflush刷新缓冲区，这三种情况下会输出到屏幕。你可以在printf后调用fflush这个函数试一试。

作者：张杨
链接：https://www.zhihu.com/question/27141314/answer/36350860
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//--mmap------------------------------

lseek()
        SEEK_SET 参数offset 即为新的读写位置.
        SEEK_CUR 以目前的读写位置往后增加offset 个位移量.
        SEEK_END 将读写位置指向文件尾后再增加offset 个位移量. 当whence 值为SEEK_CUR 或
        SEEK_END 时, 参数offet 允许负值的出现.

下列是教特别的使用方式:
1) 欲将读写位置移到文件开头时:lseek(int fildes, 0, SEEK_SET);
2) 欲将读写位置移到文件尾时:lseek(int fildes, 0, SEEK_END);
3) 想要取得目前文件位置时:lseek(int fildes, 0, SEEK_CUR);

ftruncate()

函数功能：改变文件大小

相关函数：open、truncate
表头文件：#include <unistd.h>
函数原型：int ftruncate(int fd, off_t  length)
函数说明：ftruncate()会将参数fd指定的文件大小改为参数length指定的大小。参数fd为已打开的文件描述词，而且必须是以写入模式打开的文件。如果原来的文件件大小比参数length大，则超过的部分会被删去
返 回  值：0、-1

参考UNIX 高级环境编程 14.9节，需要先设置文件的长度， 再调用mmap才不会出现总线错误

#include <stdio.h>     
 #include <unistd.h>   
 
main()   
 {   
      char buf[80];   
      getcwd(buf,sizeof(buf));   //当前路径
      printf("current working directory: %s\n", buf);   
 }  

//-----sizoeof返回值是unsigned int-------
int array[]={1,2,3,4,5,6,7,8};
int x = -1;
if (x <= sizeof(array)/sizeof(array[0])-2){   //此时编译器会把x转为unsigned int  （超级大）
	puts("dsdada");
}

真确做法是：x <= (int)(sizeof(array)/sizeof(array[0]))-2

//---------------------------------------
switch(a){
	case 1://必须是常量
	case 2:
	default:...
}
//------------------

当我们考虑函数的时候，我们不需要加上一个取地址符&。简而言之，函数名就是它的地址
void func();
func函数名就是地址

atoi
atof
atol


//非局部跳转------------------------------
1 #include <stdio.h>
 2 #include <setjmp.h>
 3 
 4 jmp_buf jump_buffer;
 5 
 6 void func(void)
 7 {
 8          printf("Before calling longjmp\n");
 9          longjmp(jump_buffer, 1);
10          printf("After calling longjmp\n");
12 void func1(void)
13 {
14          printf("Before calling func\n");
15          func();
16          printf("After calling func\n");
17 }
18 int main()
19 {
20          if (setjmp(jump_buffer) == 0){
21                    printf("first calling set_jmp\n");
22                    func1();
23          }else {
24                    printf("second calling set_jmp\n");
25          }
26          return 0;
27 }
通过上面这个简单例子的运行结果可以看出。main函数运行的setjmp()宏调用，将当前程序点的系统状态信息保存到全局变量jump_buffer中，然后返回结果0。于是，代码打印出字符串"first calling set_jmp"，然后调用函数func1()。在函数func1中，先打印字符串"Before calling func"，然后去调用函数func()。现在程序控制流转到func函数中，函数func先打印字符串“Before calling longjmp"，然后调用函数longjmp。这时候关键点到了！！！longjmp函数将main函数中setjmp()宏调用设置在全局变量jump_buffer中的系统状态信息恢复到系统的相应寄存器中，导致程序的控制流跳转到了main函数中setjmp()宏调用所在的程序点，此时相当于第二次进行setjmp()宏调用，并且此时的setjmp()宏调用的返回不再是0，而是传递给函数调用longjmp()的第二个参数1。于是程序控制流转到main函数中if语句的else部分执行，打印字符串“second calling set_jmp“。最后，执行main函数中的语句“reture 0;”返回，程序运行结束退出。
setjmp/longjmp最大的用途是错误恢复
//----------------------------------------
char a[]="dasdsadsa";  不是常量，被放在栈上,可以改变 a[1]='W';
char* a="dsadasda";常量并把它放到程序的常量区

//---------------------------------------
int* a=(int*)malloc(sizeof(int)*10);
free(a+4);  //错误！！！！！！！！
//---------------------------------------
extern char *strchr(char *str,char character)   查找子串
//---------------------------------------
单模式匹配	BM > KMP
多模式匹配	Wu-Manber > AC 
//---------pthread.h------------------------------

pthread_cleanup_push/pop   
不论是可预见的线程终止还是异常终止，都会存在资源释放的问题，在不考虑因运行出错而退出的前提下，如何保证线程终止时能顺利的释放掉自己所占用的资源，特别是锁资源，就是一个必须考虑解决的问题。
void pthread_cleanup_push(void (*rtn)(void*),void *arg);
要执行的线程函数
void pthread_cleanup_pop(int execute);
1）当前线程调用pthread_exit
2）其他线程对本线程pthread_cancel()时才调用rtn清理函数。
3）execute 1 线程函数退出会执行rtn清理函数

###pigz 最大感言
先投递的线程一定比后投递的进程快！！！ 运用好这点，就可利用顺序法则。
pigz 线程间通信写的太好了，永生受用。

int pthread_once(pthread_once_t *once_control, void (*init_routine) (void))；
功能：本函数使用初值为PTHREAD_ONCE_INIT的once_control变量保证init_routine()函数在本进程执行序列中仅执行一次。
 
在多线程编程环境下，尽管pthread_once()调用会出现在多个线程中，init_routine()函数仅执行一次，究竟在哪个线程中执行是不定的，是由内核调度来决定。


创建一个类型为pthread_key_t类型的变量。

调用pthread_key_create()来创建该变量。该函数有两个参数，第一个参数就是上面声明的pthread_key_t变量，第二个参数是一个清理函数，用来在线程释放该线程存储的时候被调用。该函数指针可以设成 NULL，这样系统将调用默认的清理函数。该函数成功返回0.其他任何返回值都表示出现了错误。

当线程中需要存储特殊值的时候，可以调用 pthread_setspcific() 。该函数有两个参数，第一个为前面声明的pthread_key_t变量，第二个为void*变量，这样你可以存储任何类型的值。

如果需要取出所存储的值，调用pthread_getspecific()。该函数的参数为前面提到的pthread_key_t变量，该函数返回void *类型的值。下面是前面提到的函数的原型：

int pthread_once(pthread_once_t *once_control, void (*init_routine) (void))；
功能：本函数使用初值为PTHREAD_ONCE_INIT的once_control变量保证init_routine()函数在本进程执行序列中仅执行一次。
//------------------------------------------------
void func(char (*out1)[1024], char (*out2)[1024]){
	puts(out1[0]);
	puts(out2[0]);
}

int main(int argc, char** argv){
	
	char a[4][1024]={"abcd","efgh","ijkl","mnop"};
	char b[4][1024]={"abcd","efgh","ijkl","mnop"};
	func(a,b);

	return(1);
}


void func(char* out1[4], char* out2[4]){
	puts(out1[0]);
	puts(out2[0]);
}


int main(int argc, char** argv){
	
	char* a[4]={"abcdaaa","efgh","ijkl","mnop"};
	char* b[4]={"abcdaaa","efgh","ijkl","mnop"};
	func(a,b);

	return(1);
}


二维数组指针赋值
char a[4][1024]={"abcdaaa","efgh","ijkl","mnop"};
char (*x)[1024] = a;


//--------------------------------------------------
fd = fileno(fp);    /*文件指针转换为文件描述符*/  
fp = fdopen(fd, "r");       /*文件描述符转换为文件指针*/  


//--------------=-----------------------------------
#include <stdarg.h>
local int complain(char *fmt, ...) {
    va_list ap;

    if (g.verbosity > 0) {
        fprintf(stderr, "%s: ", g.prog);
        va_start(ap, fmt);
        vfprintf(stderr, fmt, ap);
        va_end(ap);
        putc('\n', stderr);
        fflush(stderr);
    }
    g.ret = 1;
    return 0;
}
//----数组与指针-------------------------------------
char* b = NUL;
char a[]="aaa";
a=b //错误 数组名（指针）为只读，不能对一个已经定义的数组

char* a="aaaa";
a[2]='s';  //错误 指针中的元素为只读！
//----再话 const-------------------------------------
const int a=1;
int* b=(int*)&a;
*b=10;
当开启优化是-O2,当编译器看到这里的num被const修饰， 从语义上讲这里的num是不期望被改变（不改变）的，
那优化的时候就可以把num的值存放到寄存器（以提高访问的效率） 中。
所以，要用volatile
volatile const int a = 1;
int* b = (int*)&a;
*b=10;
此时，开启优化就没问题！！！

定义函数指针
typedef void (*FP) (int, const std::string&);
//---缓冲---------------------------------------------
cout << unitbuf; // 这样的话 设置 cout 接下来的操作都进行一次刷新缓冲区
cout << nounitbuf; //这里则让cout回到正常的缓冲方式
//-----int a[][] int (*a)[]
int a[10][5] = int (*a)[5]





