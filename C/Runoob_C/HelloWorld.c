#include <stdio.h>
#include <string.h>
//#include <windows.h>//win下添加
#include <unistd.h>//使用sleep函数
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <locale.h>// 7.28.2019 15:30
#include <time.h>
#include <errno.h>// 7.28.2019 18:08
#include <assert.h>// 8.10.2019



//宏
#define PI	3.14159265
//extern int errno;

//声明
int sum(int, int);
void tLog(char *sInfo, ...);
int sum_stdarg(int num_args, ...);
void WriteFormated(FILE *stream, char *format, ...);
void functionA();
int cmpfunc(const void *a, const void *b);

int main(int argc, char *argv[])
{
	/******初识C****** 
	 *argc 为参数个数，argv 是字符串数组， 下标从 0 开始，第一个存放的是可执行程序的文件名字，然后依次存放传入的参数
	*/
	// int x;
	// printf("Exe: %s,\nArgc: %d,\nArgv[0]: %s,\n", argv[0], argc, argv[1]);
	// x = sum(3, 4);
	// printf("a+b=%d\n", x);
	
	/* ******循环****** */
	// int n[10];
	// int i,j;
	// for(i=0;i<10;)


	/* ******C标准库****** */
	/* ***01 <assert.h>*** */
		{
		/**
		 * 该头文件提供了一个名为assert的宏，可用于验证程序作出的假设，并在假设为驾驶输出诊断消息
		 * 已定义的宏assert指向另一个宏NDEBUG，宏NDEBUG不是<asssert.h>的一部分
		 * 如果在已引用<assert.h>的源文件中定义NDEBUG为宏名称，则assert宏的定义如下
		 * #define assert(ignore) ((void)0)
		 */
		/** 
		 * 01 void assert(int expression)
		 * 允许诊断信息被写入到标准错误文件中。换句话说，它允许在C程序中添加诊断
		 * espression -- 可以是变量或任何C表达式。为TRUE则不执行任何动作，
		 * 为false则在stderr上显示错误消息，并中止程序执行
		 * 
		 * 该宏不返回任何值
		*/

		// int a;
		// char str[50];

		// printf("Please input a number:");
		// scanf("%d", &a);
		// assert(a >= 10);
		// printf("The number is: %d\n", a);

		// printf("Please input a string:");
		// scanf("%s", &str);
		// assert(str != NULL);
		// printf("The string is: %s\n", str);

		/**
		 * 综合评价：
		 * 头文件<assert.h>中定义的【唯一】函数。实际上是一个宏，不是一个函数，可用于在C程序中添加诊断
		 * 通常用来判断程序中是否出现了明显【非法数据】
		 * 只在Debug版本中有效，如果编译为Release版则被忽略
		 * 
		 */
		}
	/* ***02 <ctype.h>*** */
	/* ***03 <errno.h>*** */
		{
		//该头文件定义了整数变量【errno】，它是通过【系统调用】设置的，在错误事件中的某些库函数表明了什么发生了错误
		//该宏扩展为类型为int的可更改左值，因此它可以被一个程序读取和修改。
		//程序启动时，errno设置为零，C标准库中的特定函数修改它的值为一些非零值以表示某些类型的错误。
		//也可以在适当的时候修改它的值或重置为零
		//errno.h头文件定义了一系列表示不同错误代码的宏，这些宏应扩展为类型为int的整数常量表达式
		/** 01 extern int errno
		 * 这是通过【系统调用】设置的宏，在错误事件中的某些库函数表明了【什么】发生了错误
		 */
		// FILE *fp;

		// fp = fopen("file.txt", "r");
		// if(fp==NULL){
		// 	fprintf(stderr, "Value of errno: %d\n", errno);
		// 	fprintf(stderr, "Error opening file: %s\n", strerror(errno));
		// }else{
		// 	fclose(fp);
		// }
		// for (int i = 0; i < 45;i++){
		// 	fprintf(stderr, "Value of errno: %d\n", i);
		// 	fprintf(stderr, "Error opening file: %s\n", strerror(i));
		// }

		/** 02 EDOM Domain Error
		 * 这个宏表示一个【域错误】
		 * 它在输入参数超出数学函数【定义域】时发生
		 * errno被设置为EDOM
		 */
		// double val;
		// errno = 0;
		// val = sqrt(-10);
		// if(errno==EDOM){
		// 	printf("Invalid value \n");
		// }else{
		// 	printf("Valid value \n");
		// }

		// errno = 0;
		// val = sqrt(10);
		// if(errno==EDOM){
		// 	printf("invalid value\n");
		// }else{
		// 	printf("valid value\n");
		// }
		

		/** 03 ERANGE Range Error
		 * 这个宏表示一个【范围错误】，它在输入参数超出数学函数【值域】时发生，errno 被设置为 ERANGE
		 */
		// double x;
		// double value;

		// x = 2.000000;
		// value = log(x);

		// if(errno==ERANGE){
		// 	printf("Log(%f) is out of range\n", x);
		// }else{
		// 	printf("Log(%f) = %f\n", x, value);
		// }

		// x = 1.000000;
		// value = log(x);

		// if(errno==ERANGE){
		// 	printf("Log(%f) is out of range\n", x);
		// }else{
		// 	printf("Log(%f) = %f\n", x, value);
		// }

		// x = 0.000000;
		// value = log(x);

		// if(errno==ERANGE){
		// 	printf("Log(%f) is out of range\n", x);
		// }else{
		// 	printf("Log(%f) = %f\n", x, value);
		// }
		}
	/* ***04 <float.h>*** */
	/* ***05 <limits.h>*** */
	/* ***06 <locale.h>*** */
		{
		//定义特定地域设置，如日期格式和货币符号。
		// typedef struct{
		// 	char *decimal_point;//用于非货币值的小数点字符
		// 	char *thousands_sep;//用于非货币值的千位分隔符
		// 	char *grouping;//一个表示非货币量中每组数字大小的字符串。每个字符代表一个整数值，每个整数指定当前组的位数。值为 0 意味着前一个值将应用于剩余的分组。
		// 	char *int_surr_symbol;//国际货币符号使用的字符串。前三个字符是由 ISO 4217:1987 指定的，第四个字符用于分隔货币符号和货币量
		// 	char *currency_symbol;//用于货币的本地符号
		// 	char *mon_decimal_point;//用于货币值的小数点字符
		// 	char *mon_thousands_point;//用于货币值的千位分隔符
		// 	char *mon_grouping;//一个表示货币值中每组数字大小的字符串。每个字符代表一个整数值，每个整数指定当前组的位数。值为 0 意味着前一个值将应用于剩余的分组
		// 	char *positive_sign;//用于正货币值的字符
		// 	char *negative_sige;//
		// 	char int_frac_digits;//国际货币值中小数点后要显示的位数
		// 	char frac_digits;//
		// 	char p_cs_precedes;//如果等于 1，则 currency_symbol 出现在正货币值之前。如果等于 0，则 currency_symbol 出现在正货币值之后
		// 	char p_sep_by_space;//如果等于 1，则 currency_symbol 和正货币值之间使用空格分隔。如果等于 0，则 currency_symbol 和正货币值之间不使用空格分隔
		// 	char n_cs_precedes;//
		// 	char n_sep_by_space;//
		// 	char p_sign_posn;//表示正货币值中正号的位置
		// 	char n_sign_posn;//
		// } lconv;
		/** 01 char *setlocale(int category,const char *local)
		 * 设置或读取地域化信息
		 * category -- 这是一个已命名常量，指定受区域设置影响的函数类别
		 * 		LC_ALL 包括下面所有选项
		 * 		LC_COLLATE 字符串比较。参见strcoll()
		 * 		LC_CTYPE 字符分类和转换。
		 * 		LC_MONETARY 货币格式。针对localeconv()
		 * 		LC_NUMERIC 小数点分隔符。正对localeconv()
		 * 		LC_TIME 日期和时间格式。针对strftime()
		 * 		LC_MESSAGES 系统响应
		 * locale -- 若为【NULL或空串""】则根据环境变量设置
		 */
		// time_t currtime;
		// struct tm *timer;
		// char buffer[80];

		// time(&currtime);
		// timer = localtime(&currtime);

		// printf("Locale is: %s\n", setlocale(LC_ALL, "en_US.UTF-8"));
		// strftime(buffer, 80, "%c", timer);
		// printf("Date is: %s\n", buffer);

		// printf("Locale is: %s\n", setlocale(LC_ALL, "zh_CN.UTF-8"));
		// strftime(buffer, 80, "%c", timer);
		// printf("Date is: %s\n", buffer);


		/** 02 struct lconv * localeeonv(void)
		 * 设置或读取地域化信息
		 */
		}
	/* ***07 <math.h>*** */
		{
			// math.h头文件定义了各种数学函数和一个库宏
			// 库中所有可用功能都带有double类型参数，且都返回double类型结果
			//库宏：HUGE_VAL
			
			/** O1 double acos(double x)
			 * x -- 介于【-1，+1】之间的浮点值
			 * 返回以弧度表示的x的反余弦【0，pi】
			 * 
			 */
			// double x = 0.9;
			// double ratio = 180.0 / PI;//弧度转角度的比例系数

			// double ret0 = acos(x) * ratio;
			// double ret1 = asin(x) * ratio;
			// printf("arccos(%lf) = %lf degree.\n", x, ret0);
			// printf("arcsin(%lf) = %f degree.\n", x, ret1);


			/** 02 double asin(double x)
			 * 返回以弧度表示的x的反正弦
			 */
			// 参见01
			/** 03 double atan(double x)
			 * 返回以弧度表示的x的反正切
			 */
			// double x = 1.0;
			// double ratio = 180.0 / PI;//弧度转角度的比例系数
			// double ret3 = atan(x) * ratio;
			// printf("arctan(%lf) = %lf degree.\n", x, ret3);
			/**04 double atan2(double y, double x)
			 * 返回以弧度表示的y/x的反正切。y和x的值的符号决定正确的象限
			 * 返回值【-pi，+pi】
			 */
			// double x = -7.0,y = 7.0;
			// double ratio = 180.0 / PI;//弧度转角度的比例系数
			// double ret4 = atan2(y,x) * ratio;
			// printf("atan(%lf/%lf) = %lf degree.\n", y, x, ret4);

			/**05 double cos(double x)
			 * 返回以弧度角x的反余弦
			 */
			/**06 double cosh(double x)
			 * 返回以弧度角的x的双曲余弦
			 */
			/**07 double sin(double x)
			 * 返回以弧度表示的x的正弦
			 */
			/**08 double sinh(double x)
			 * 返回以弧度表示的x的双曲正弦
			 */
			/**09 double tanh(double x)
			 * 返回以弧度表示的x的双曲正切
			 */
			/**10 double exp(double x)
			 * 返回指数函数值，即【e的x次方】
			 */
			/**11 double frexp(double x, int exponent)
			 * 将浮点数x分解成尾数和指数。
			 * 返回值是尾数，并将指数存入exponent中。所得值是【x = mantissa * 2^exponent】
			 */
			/**12 double ldexp(double x, int exponent)
			 * 返回【 x * 2^exponent]
			 */
			/**13 double log(double x)
			 * 返回【以e为底】的自然对数
			 */
			/**14 double log10(double x)
			 * 返回【以10为底】的常用对数
			 */
			/**15 double modf(double x, double *integer)
			 * 返回值为小数部分，并设置 integer 为整数部分
			 */
			/**16 double pow(double x，double y)
			 * 返回x的y次幂【 x^y 】
			 */
			/**17 double sqrt(double x)
			 * 返回 x 的平方根
			 */
			/**18 double ceil(double x)
			 * 返回大于或等于 x 的最小的整数值
			 */
			/**19 double fabs(double x)
			 * 返回 x 的绝对值
			 */
			/**20 double (double x, double y)
			 * 返回小于或等于 x 的最大的整数值
			 */
			/**21 fmod(double x, double y)
			 * 返回x除以y的余数
			 */
				
		}
	/* ***08 <setjmp.h>*** */
	/* ***09 <signal.h>*** */
	/* ***10 <stdarg.h>*** */
		{
			//定义了一个变量类型va_list和三个宏，这三个宏可以在参数个数未知时获取函数参数
			/**01 void va_start(va_list ap, last_arg)
			 * C库宏 va_start初始化ap变量，与va_arg和va_end宏合用
			 * ap用来存储参量列表
			 * last_arg是【最后一个】传递给函数的已知的【固定参数】，即省略号之前的参数
			 * 返回值为NA
			 */
			/**02 type va_arg(va_list ap;type)
			 * 该宏检索函数参数列表中类型为type的下一个参数
			 */
			/**03 void va_end(va_list ap)
			 * 该宏允许使用了va_start宏的带有可变参数的函数返回。若函数返回前未调用va_end，则结果为未定义
			 */
			// printf("The sum of 10,20,30 is %d.\n", sum_stdarg(3,10,20,30));
			// printf("The sum of 10,20,25,30 is %d.\n", sum_stdarg(4,10,20,25,30));
		}
	/* ***11 <stddef.h>*** */
	/* ***12 <stdio.h>*** */
		{
			/**01 int fclose(FILE *stream) 
					* 关闭流stream。刷新所有缓冲区
					*/
			// FILE *fp;
			// fp = fopen("file.txt", "w");
			// fprintf(fp, "%s", "这里是 runoob.com");
			// fclose(fp);

			/**02 void clearerr(FILE *stream)
					* 清除给定流stream的文件结束和错误标识符
					*/
			// FILE *fp;
			// char c;

			// fp = fopen("file.txt", "w");

			// c = fgetc(fp);//产生错误标识符，返回非零值给ferror()函数
			// if( ferror(fp) ){//执行
			// 	printf("Error 1 is happenning when reading \"file.txt\" \n");
			// }
			// clearerr(fp);
			// if( ferror(fp) ){//不执行
			// 	printf("Error 2 is happenning when reading \"file.txt\" \n");
			// }
			// fclose(fp);

			/**03 int feof(FILE *stream)
					* 测试给定流stream的文件结束标识符
					*/
			// FILE *fp;
			// int c;

			// fp = fopen("file.txt","r");
			// if(fp==NULL){//安全测试，保证健壮性
			// 	perror("Error is happenning when open file.txt!");
			// 	return (-1);
			// }
			// while(1){
			// 	c = fgetc(fp);
			// 	if(feof(fp)){//逐个字节输出，至文件末尾时，函数feof返回0
			// 		break;
			// 	}
			// 	printf("%c\n", c);
			// }
			// fclose(fp);

			/**04 int ferror(FILE *stream)
					* 测试给定流stream的错误标识符
					*/
			//示例参见 02

			/** 05 int fflush(FILE *stream)
			  * 刷新流 stream 的输出缓冲区
			  */
			// char buff[1024];

			// memset(buff, '\0', sizeof(buff));

			// fprintf(stdout, "Open buffer\n");
			// setvbuf(stdout, buff, _IOFBF, 1024);

			// fprintf(stdout, "This is runoob.com!\n");
			// fprintf(stdout, "Save the output in buff!\n");
			// fflush(stdout);//讲道理应该是清理标准输入流，并打印在屏幕上，但是MS的策略好像是直接冲洗

			// fprintf(stdout, "This will appear in programming!\n");
			// fprintf(stdout, "Sleep 5s!");

			// sleep(10);

			/**06 int fgetpos(FILE *stream, fpos_t *pos)
					* 获取流 stream 的当前文件位置，并把它写入到 pos
					*/
			// FILE *fp;
			// fpos_t position;

			// fp = fopen("file.txt", "w+");
			// fgetpos(fp, &position);
			// fputs("hello,bei!", fp);

			// fsetpos(fp, &position);//重置写指针到文件开头
			// fputs("This will override previous content.", fp);

			//输出文件内容
			// char c;
			// fsetpos(fp, &position);
			// while(1){
			// 	c = fgetc(fp);
			// 	if(feof(fp)){
			// 		break;
			// 	}
			// 	printf("%c", c);
			// }

			// fclose(fp);

			/**07 FILE *fopen(const char *filename, const char *mode)
							 * 用给定的模式 mode 打开 filename 所指向的文件
							*/

			/**08 size_t fread(void *ptr, size_t nmemb, FILE *stream)
					* 从给定流 stream 中读取数据到 ptr 所指向的数组中
					*/
			// FILE *fp;

			// fp = fopen("file.txt", "w+");
			// fprintf(fp, "%s %s %s %d", "We", "are", "in", 2019);

			// fclose(fp);

			/**09 FILE *freopen(const char *filename, const char *mode, FILE *stream)
					* 把一个新的文件名 filename 与给定的打开的流 stream 关联，同时关闭流中的旧文件
					*/
			// FILE *fp;
			// printf("Relocate to stdout!\n");
			// //与stdout关联，我们在标准输出中写的内容会被写入file.txt
			// fp = freopen("file.txt", "r+", stdout);

			// printf("No matter what I typing in stdout will appear to file.txt");

			// fclose(fp);

			/**10 int fseek(FILE *stream, long int offset, int whence)
							 * 设置流 stream 的文件位置为给定的offset，参数offset意味着从给定的whence位置查找的字节
							*/
			// FILE *fp;

			// fp = fopen("file.txt", "w+");
			// fputs("This is runoob.com!",fp);

			// fseek(fp, 8, SEEK_SET);
			// fputs("C Programming Language!", fp);

			// fclose(fp);

			/**11 int fsetpos(FILE *stream, const fpos_t *pos)
					 * 置流 stream 的文件位置为给定的位置，参数pos是由函数fgetpos 给定的位置
					*/
			//FILE *fp;
			// fpos_t position;

			// fp = fopen("file.txt", "w+");
			// fgetpos(fp, &position);
			// fputs("Hello World!", fp);

			// fsetpos(fp, &position);//重置位置指针到文件开头
			// fputs("Override!", fp);

			// fclose(fp);

			/**12 long int ftell(FILE *stream)
							 * 返回给定流 stream 的当前文件位置
							 * 返回位置标识符的当前值。发生错误返回-1L，全局变量errno被置为一个正值
							*/
			// FILE *fp;
			// int len;

			// fp = fopen("file.txt", "r");
			// if(fp==NULL){//robust检测
			// 	perror("Open ferror.");
			// 	return -1;
			// }
			// fseek(fp, 0, SEEK_END);

			// len = ftell(fp);//从0计数到位置标识符当前值，即为文件长度
			// fclose(fp);

			// printf("The size of \"file.txt\" is %d bytes.\n", len);

			/**13 size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
					* 把ptr所指向的‘数组’中的数据写入到给定流stream中
					* 返回数组元素总数，若与成员数目变量nmemb不同，则显示错误
					*/
			// FILE *fp;
			// char str[] = "This is ruooob.com";

			// fp = fopen("file.txt", "w");
			// fwrite(str, sizeof(str), 1, fp);

			// fclose(fp);

			/**14 int  remove(const char *fielname)
							 * 删除给定的文件名 filename，以便它不再被访问。
							 * 成功返回0；否则返回-1，且设置error
							*/
			// int ret;
			// FILE *fp;
			// char filename[] = "file.txt";

			// fp = fopen(filename, "w");

			// fprintf(fp, "%s", "这里是runoob.com");
			// fclose(fp);

			// ret = remove(filename);

			// if(ret==0)
			// 	printf("Success to remove file!");
			// else
			// 	printf("Error:can't remove file!");

			/*15 int rename(const char *old_filename, const char *new_filename)
							* 把 old_filename 所指向的文件名改为 new_filename
							* 成功返回0；否则返回-1，且设置error
							*/
			// int ret;
			// char oldname[] = "file.txt";
			// char newname[] = "newfile.txt";

			// ret = rename(oldname, newname);

			// if (ret==0){
			// 	printf("Success");
			// }else{
			// 	printf("Error");
			// }

			/**16 void rewind(FILE *stream)
							 * 设置文件位置为给定流stream的文件的“开头”,即回归起点
							*/

			/**17 void setbuf(FILE *stream, char *buffer)
							 * 定义流stream应如何缓冲。应该在文件被打开，但还未发生I/O操作之前调用一次
							*/
			// char buf[BUFSIZ];

			// setbuf(stdout, buf);
			// puts("This is runoob.");

			//fflush(stdout);

			/**18 int setvbuf(FILE *stream, char *buffer, int mode, size_t size)
					* 另一个定义流stream应如何缓冲
					* 成功返回0，否则返回非零值
					*/
			// char buff[1024];

			// memset(buff, '\0', sizeof(buff));

			// fprintf(stdout, "Toggle Full Buffer\n");
			// setvbuf(stdout, buff, _IOFBF, 1024);

			// fprintf(stdout, "This is runoob.com\n");
			// fprintf(stdout, "Save the output to buff\n");
			// fflush(stdout);

			// fprintf(stdout, "This will appear at programming\n");
			// fprintf(stdout, "Sleep 5 seconds\n");

			// sleep(5);

			/**19 FILE *tmpfile(void)
					* 以二进制更新模式（wb+）创建临时文件
					* 如果成功则返回一个临时文件的流指针，如果未创建，则返回NULL
					*/
			// FILE *fp;

			// fp = tmpfile();
			// printf("TempFile has been build\n");
			// sleep(5);
			// /* 你可以在这里使用临时文件 */
			// fclose(fp);

			/**20 char *tempnam(char *str)
							* 生成并返回一个有效的临时文件名，该文件名之前不存在
							*/


			/**21 int fprintf(FILE *stream, const char *format,...)
							* 发送格式化输出到标准输出stdout
							*/

			/**22 int printf(const char *format,...)
							 * 发送格式化输出到标准输出stdout
							 * 成功返回字符串总数，否则返回一个负数
							*/
			// int ch;

			// for (ch = 65; ch <= 100;ch++){
			// 	printf("ASCII value = %d, character = %c\n", ch, ch);
			// }

			// char str[20] = "www.runoob.com";
			// float flt = 10.234;
			// int num=150;
			// int *pnum = &num;
			// double dbl = 20.1234566;
			// printf("%s\n",str);
			// printf("%f\n",flt);
			// printf("%d\n",num);
			// printf("%lf\n",dbl);
			// printf("%o\n",num);
			// printf("%p\n",pnum);
			// printf("%x\n",num);

			/**23 int sprintf(char *str, const char *format,...)
				* 发送格式化输出到字符串
				*/
			// char str[80];
			// sprintf(str, "Pi = %f", PI);
			// puts(str);

			/**24 int vfprint(FILE *stream, const char *format, va_list arg)
				* 【使用参数列表】发送格式化输出到stream
				* format--字符串
				* arg--一个表示可变参数列表的对象。这应被<stdarg>中定义的va_start宏初始化
				* 成功则返回字符总数，否则返回一个负数
				*/
			// FILE *fp;

			// fp = fopen("file.txt", "w");

			// WriteFormated(fp, "This is just one argument %d \n", 10);
			// fclose(fp);

			/**25 int vprintf(const char *format, va_list arg)
				* 【使用参数列表】发送格式化输出到标准输出stdout
				*/

			/**26 int vsprintf(char *str, const char *format, va_list arg)
				* 【使用参数列表】发送格式化输出到字符串
				*/

			/**27  int fscanf(FILE *stream, const char *format,...)
				* 从流stream读取格式化输入
				*/
			// char str1[10], str2[10], str3[10];
			// int year;
			// FILE *fp;

			// fp = fopen("file.txt", "w+");
			// fputs("We are in 2014",fp);

			// rewind(fp);
			// fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);//从流stream读取格式化输入

			// printf("Read String1 |%s|\n", str1);
			// printf("Read String1 |%s|\n", str2);
			// printf("Read String1 |%s|\n", str3);
			// printf("Read String1 |%d|\n", year);

			// fclose(fp);

			/**28 int scanf(connst char *format,...)
				* 从标准输入stdin读取格式化输入
				*/

			/**29 int sscanf(connst char *str, connst char *format,...)
				* 从字符串读取格式化输入
				*/
			// int day;
			// int year;
			// char weekday[20], month[20], dtm[100];

			// strcpy(dtm, "Saturday July 27 2019");
			// sscanf(dtm, "%s %s %d %d", weekday, month, &day,&year );

			// printf("%s %d, %d = %s \n", month, day, year, weekday);


			/**30 int fgetc(FILE *stream)
				* 从指定的流stream获取下一个字符(一个无符号字符)，并把位置标识符往前移动
				* 该函数以无符号char强制转换为int的形式返回读取的字符，
				* 如果到达文件末尾或发生读错误，则返回EOF
				*/
			// FILE *fp;
			// int c;
			// fp = fopen("file.txt", "r");
			// if(fp==NULL){
			// 	perror("Error！");
			// 	return (-1);
			// }
			// do {
			// 	c=fgetc(fp);//从指定流中获取一个字符
			// 	if(feof(fp))
			// 		break;
			// 	printf("%c", c);
			// } while (1);

			// fclose(fp);

			/**31 int fgets(char *str, int n, FILE *stream)
				* 从指定的流stream读取一行，并把它存储在str所指向的字符串内。当读取(n-1)个字符时，或者读取到换行符时，或者到达文件末尾时停止，视情况而定
				* str--数组，存储了要读取的字符串
				* n--表示要读取的最大字符数（包括末尾空格）
				*/
			// FILE *fp;
			// char str[60];

			// fp = fopen("file.txt", "r");
			// if(fp==NULL){
			// 	perror("Error!");
			// 	return (-1);
			// }
			// if(fgets(str,60,fp)!=NULL){//从fp中读取60个字符存到数组str[]中
			// 	puts(str);
			// }
			// fclose(fp);


			/**32 int fputc(int char, FILE *stream)
				* 把参数char指定的字符(无符号)写入到指定的流stream中，并把位置标识符往前移动
				* char--待写入字符。该字符以对应的int值进行传递
				* 成功返回被写入字符，否则返回EOF，并设置错误标识符
				*/
			// FILE *fp;
			// int ch;

			// fp = fopen("file.txt", "w+");
			// for (ch = 33; ch <= 100;ch++){
			// 	fputc(ch, fp);
			// }
			// fclose(fp);

			/**33 char *fputs(const char* str,FILE *stream)
				* 把字符串写入到指定的流 stream 中，但不包括空字符
				* str--是一个数组，包含了要写入的以空字符终止的字符序列
				*/
			// FILE *fp;

			// fp = fopen("file.txt", "w+");

			// fputs("This is C language!",fp);
			// fclose(fp);

			/**34 int getc(FILE *stream)
				* 从指定的【流stream】获取下一个字符（一个无符号字符），并把位置标识符往前移动
				*/
			// char c;
			// printf("Please input a char: ");
			// c = getc(stdin);//这里将stdin看作单一文件
			// printf("The input char is: %c", putc(c, stdout));

			/**35 int getchar(void)
				* 从【标准输入stdin】获取一个字符（一个无符号字符）
				*/

			/**36 char *gets(char *str)
				* 从【标准输入stdin】读取【一行】，并把它存储在str所指向的字符数组中。
				* 当读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定
				*/
			// char str[60];
			// printf("Please input a string: ");
			// gets(str);//这里将stdin看作单一文件
			// printf("The input string is: %s", str);

			/**37 int putc(int char, FILE *stream)
				* 把参数 char 指定的字符（一个无符号字符）写入到指定的流 stream 中，并把位置标识符往前移动
				*/
			//参见34

			/**38 int putchar(int char)
				* 把参数 char 指定的字符（一个无符号字符）写入到标准输出 stdout 中
				*/
			//参见35

			/**39 int puts(const char *str)
				* 把一个字符串写入到标准输出 stdout，直到空字符，但不包括空字符。换行符会被追加到输出中
				*/

			/**40 int ungetc(int char, FILE *stream)
				* 把字符char推入指定的流stream中，以便它是下一个被读取到的字符
				* 成功则返回被推入字符，否则返回EOF，且流stream不变
				*/
			// FILE *fp;
			// int c;
			// char buffer[256];

			// fp = fopen("file.txt", "r");
			// if(fp == NULL){
			// 	perror("Error: Open file is failed.");
			// 	return (-1);
			// }
			// while(!feof(fp)){
			// 	c = getc(fp);
			// 	if(c == '!'){//把!替换为+
			// 		ungetc('+', fp);
			// 	}else{
			// 		ungetc(c, fp);
			// 	}
			// 	fgets(buffer, 255, fp);
			// 	fputs(buffer, stdout);
			// }

			/**41 perror(const char *str)
				* 把一个描述性错误消息输出到【标准错误stderr】。首先输出字符串 str，后跟一个冒号，然后是一个空格
				* str--C字符串，包含了一个自定义消息，将显示在原本的错误消息之前
				*/
			// FILE *fp;
			
			// rename("file.txt", "new_file.txt");//首先重命名文件

			// fp = fopen("file.txt", "r");//尝试打开旧名文件
			// if(fp == NULL){
			// 	perror("Error: ");
			// 	return (-1);
			// }
			// fclose(fp);
		}

	/* ***13 <stdlib.h>*** */
	{
		/** 定义了四个变量类型，一些宏和各种通用工具 */
		/**库变量 
		 * 01 size_t 这是无符号整数类型，它是sizeof关键字的结果
		 * 02 wchar_t 这是一个宽字符常量大小的整数类型
		 * 03 div_t 这是div函数返回的结构
		 * 04 ldiv_t 这是ldiv函数返回的结构
		*/
		/**库宏 
		 * 01 NULL 
		 * 02 EXIT_FAILURE 这是exit函数失败时要返回的最大值
		 * 03 EXIT_SUCCESS 这是exit函数成功时要返回的最大值
		 * 04 RAND_MAX 这是rand函数返回的最大值
		 * 05 MB_CUR_MAX 这个宏表示在多字节字符集中的最大字符数，不能大于MB_CUR_MAX
		 */
		/**01 doubel atof(const char *str)
		 * 把str转换成浮点数
		 * 函数返回值为转换后的双精度浮点数，如果没有执行有效的转换，则返回零(0.0,双精度型)
		 */
		// float val;
		// char str[20];

		// strcpy(str, "98993499");
		// val = atof(str);
		// printf("string.value=%s, float.value=%f\n", str, val);//转换成功

		// strcpy(str, "runoob");
		// val = atof(str);
		// printf("string.value=%s, float.value=%f\n", str, val);//转换失败

		/**02 int atoi(const char *str)
		 * 把str转换成int
		 * 该函数返回转换后的长整数，如果没有执行有效的转换，则返回零
		 */
		// int val;
		// char str[20];

		// strcpy(str, "98993499");
		// val = atoi(str);
		// printf("stringValue = %s, floatValue = %d\n", str, val);

		// strcpy(str, "runoob.com");
		// val = atoi(str);
		// printf("stringValue = %s, floatValue = %d\n", str, val);//转换失败
		/**03 long int atol(const char *str)
		 * 把str转换成long int
		 */
		//参见02

		/**04 double strtod(const char *str,chat **endptr)
		 * 把str转换成double
		 * str -- 要转换为双精度浮点数的字符串
		 * endptr -- 对类型为 char* 的对象的引用，其值设置为str中数值后的下一个字符
		 */
		// char str[30] = "2030300 This is a test";
		// char *ptr;
		// double ret;

		// ret = strtod(str, &ptr);//endptr指向数值后的下一个字符
		// printf("digitalVal = %lf\n", ret);
		// printf("strVal = |%s|", ptr);
		/**05 long int strtol(const char *str, char **endptr, int base)
		 * 把str依据给定的base转换成long int
		 * endptr -- 对类型为char*的对象的引用，其值由函数设置为str中数值后的下一个字符
		 * base -- 值必须介于2和36之间，或者是特殊值0
		 */
		// char str[30] = "2030300 This is a test";
		// char *ptr;
		// double ret;

		// ret = strtol(str, &ptr, 10);//endptr指向数值后的下一个字符
		// printf("digitalVal = %lf\n", ret);
		// printf("strVal = |%s|", ptr);

		/**06 unsigned long int strtoul(const char *str, char **endptr, int base)
		 * str -- 把str转换成unsigned long int
		 * endptr -- 要转换为无符号长整型的字符串
		 * base -- 基数，必须介于2和36之间，或者是特殊值0
		 * 返回值：若未执行有效转换，则返回零值
		 */
		// char str[30] = "2030300 This is test";
		// char *ptr;
		// long ret;

		// ret = strtoul(str, &ptr, 10);
		// printf("digitalVal = %lu\n", ret);
		// printf("strVal = |%s|", ptr);

		/**07 void *calloc(size_t nitems,size_t size)
		 * 分配所需的内存空间，并返回一个指向它的指针
		 * 【注意】calloc会设置分配的内存为零，而malloc不会
		 * nitems -- 要被分配的元素个数
		 * size -- 元素的大小
		 * 返回值：指向已分配空间的内存指针。如果失败则返回NULL
		 */
		// int i, n;
		// int *a;

		// printf("The number of input is: ");
		// scanf("%d", &n);

		// a = (int *)calloc(n, sizeof(int));
		// printf("Input %d numbers: \n", n);
		// for (i = 0; i < n;i++){
		// 	scanf("%d", &a[i]);
		// }

		// printf("The inputed numbers are: \n");
		// for (i = 0; i < n;i++){
		// 	printf("%d\n", a[i]);
		// }
		// free(a);

		/**08 void free(void *ptr)
		 * 释放之前调用calloc、malloc、或realloc所分配的内存空间
		 * 如果传递的是一个空指针，则不会执行任何动作
		 * 该函数无返回值
		 */
		// char *str;

		// /* 最初的内存分配 */
		// str = (char *)malloc(7);
		// strcpy(str, "runoob");
		// printf("String = %s, Address = %p\n", str, str);

		// /* 重新分配内存空间 */
		// str = (char *)realloc(str, 11);
		// strcat(str, ".com");
		// printf("String = %s, Address = %p\n", str, str);

		// /* 释放已分配内存 */
		// free(str);

		/**09 void *malloc(size_t size)
		 * 分配所需内存空间，并返回一个指向它的指针
		 * size -- 内存块的大小，以字节为单位
		 */
		// char *str;

		// /* 最初的内存分配 */
		// str = (char *)malloc(7);
		// strcpy(str, "runoob");
		// printf("String = %s, Address = %p\n", str, str);

		// /* 重新分配内存 */
		// str = (char *)realloc(str,11);
		// strcat(str, ".com");
		// printf("String = %s, Address = %p\n", str, str);

		// free(str);

		/**10 void *realloc(void *ptr, size_t size)
		 * 尝试重新调整之前调用malloc或calloc所分配的ptr所指向的内存块的大小
		 * ptr -- 指针指向一个要重新分配内存的内存块
		 * size -- 内存块的新的大小，以字节为单位
		 */
		// char *str;

		// /* 最初的内存分配 */
		// str = (char *)malloc(7);
		// strcpy(str, "runoob");
		// printf("String = %s, Address = %p\n", str, str);

		// /* 重新分配内存 */
		// str = (char *)realloc(str,11);
		// strcat(str, ".com");
		// printf("String = %s, Address = %p\n", str, str);

		/**11 void abort(void)
		 * 使一个异常程序中止,直接从调用的地方跳出
		 * 参数为空，且不返回任何值
		 */
		// FILE *fp;

		// printf("Starting nofile.txt\n");
		// fp = fopen("nofile.txt", "r");
		// if( fp==NULL){
		// 	printf("Terminate the process\n");
		// 	abort();
		// }
		// printf("Close the nofile.txt\n");
		// fclose(fp);

		/**12 int atexit(void(*func)(void)) 
		 * 当程序正常终止时，调用指定的函数func。
		 * 你可以在任何地方注册你的终止函数
		 * 如果终止函数成功注册，则该函数返回零，否则返回一个非零值
		 */
		// atexit(functionA);//注册终止函数
		// printf("Init main process\n");
		// printf("Quit main process\n");

		/**13 void exit(int status)
		 * 使程序正常终止
		 * 立即终止调用进程。任何属于该进程的打开的文件描述符都会被关闭
		 * 该进程的子进程由进程1继承，初始化，且会向父进程发送一个SIGCHLD信号
		 * status -- 返回给父进程的状态值
		 * 该函数无返回值
		 */
		// printf("The start of the process...\n");
		// printf("Quit the process...\n");
		// exit(0);

		// printf("The ending of the precess...\n");

		/**14 char*getenv(const char*name)
		 * 搜索name所指向的环境字符串，并返回相关的值给字符串
		 * name -- 包含被请求变量的C字符串
		 * 返回：一个以null结尾的字符串，给字符串未被请求环境变量的值。
		 * 		如果该环境变量不存在，则返回NULL
		 */
		// printf("PATH: %s\n", getenv("PATH"));
		// printf("HOME: %s\n", getenv("HOME"));
		// printf("ROOT: %s\n", getenv("ROOT"));

		/**15 int system(const char *command)
		 * 由cmd指定的命令名称传给要被命令处理器执行的主机环境，并在命令完成后返回
		 * cmd -- 包含被请求变量名称的C字符串
		 * 返回：如果发生错误，则返回-1，否则返回命令的状态
		 */
		// char cmd[50];

		// strcpy(cmd, "dir");
		// system(cmd);

		/**16 void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *,const void))
		 * 执行二分查找
		 * key -- 指向待查找元素的指针，类型转换为void*
		 * base -- 指向进行查找的数组的一个对象的指针，类型转换为void*
		 * nitems -- base所指向的数组中元素的个数。
		 * size -- 数组中每个元素的大小，以字节为单位
		 * compar -- 用来比较两个元素的函数
		 * 返回：成功则返回之相匹配元素的指针，否则返回空指针
		 */
		/* 使用bsearch()在数组中查找值32 */
		// int values[] = {5, 20, 29, 32, 63};
		// int *item;
		// int key = 32;

		// item = (int *)bsearch(&key, values, 5, sizeof(int), cmpfunc);
		// if(item!=NULL){
		// 	printf("Found item = %d\n", *item);
		// }else{
		// 	printf("Item = %d could not be found\n", *item);
		// }

		/**17 void qsort(void *base, size_t nitems, size_t size,int(*compar)(const void *, const void*))
		 * 数组排序
		 */
		/**18 int abs(int x)
		 * 返回 x 的绝对值
		 */
		/**19 div_t div(int numer, int denom)
		 * 分子除以分母
		 */
		/**20 long int labs(long int x)
		 * 返回x的绝对值
		 */
		/**21 ldiv_t ldiv(long int numer, long int denom)
		 * 分子除以分母
		 */
		/**22 int rand(void)
		 * 返回一个范围在0到RAND_MAX之间的伪随机数
		 */
		/**23 void srand(unsigned int seed)
		 * 该函数播种由函数rand使用的伪随机数发生器
		 */
		/**24 int mblen(const char *str, size_t n) 
		 * 返回参数str所指向的多字节字符的长度
		 */
		/**25 size_t mbstowcs(schar_t *pwcs,const char *str, size_t n)
		 * 把参数str所指向的多字节字符的字符串转换成参数pwcs所指向的数组
		 */
		/**26 int mbtowc(whcar_t *pwc, const char *str,size_t n)
		 * 检查参数str所指向的多字节字符
		 */
		/**27 size_t wcstombs(char*str,const wchar_t *pwcs,size_t n)
		 * 把数组pwcs中存储的编码转换为多字节字符，并把它们存储在字符串str中
		 */
		/**28 int wctomb(char *str, wchar_t wchar)
		 * 检查对应于参数wchar所给出的多字节字符的编码
		 */
	}
	/* ***14 <string.h>*** */
	{
		/** 定义了一个变量类型，一个宏，和各种操作字符数组的函数 */
		//库变量：size_t 无符号整数类型，是sizeof关键字的结果
		//库宏：NULL 空指针常量的值

		/**01 void *memchr(const void *str, int c,size_t n)
		 * 在参数str所指向的字符串的前n个字节中搜索第一次出现字符c(无符号字符)的位置
		 */
		// const char str[] = "http://www.runoob.com";
		// const char ch='.';
		// char *ret;

		// ret = (char *)memchr(str, ch, strlen(str));

		// printf("The char after |%c| is |%s|",ch,ret);
		/**02 int memcmp(const void *str, const void *str2, size_t n)
		 * 把str1和str2的前n个字节进行比较
		 */
		// char str1[15];
		// char str2[15];
		// int ret;

		// memcpy(str1, "abcdef", 6);
		// memcpy(str2,"ABCDEF", 6);

		// ret = memcmp(str1, str2, 5);

		// if(ret>0){
		// 	printf("str1 big than str2");
		// }else if(ret < 0){
		// 	printf("str1 less than str2");
		// }else{
		// 	printf("str1等于str2");
		// }

		/**03 void *memcpy(void *dest, const void *src, size_t n)
		 * 从src复制n个字符到dest
		 */
		// const char src[50] = "http://www.runoob.com";
		// char dest[50];

		// memcpy(dest, src, strlen(src) + 1);
		// printf("dest = %s", dest);

		/**04 void *memmove(void *str1,const void *str2,size_t n)
		 * 另一个用于从src复制n个字符到dest的函数
		 * 在重叠内存块方面，memmove()是比memcpy()更安全的方法。
		 * 如果目标区域和原区域有重叠的话，本函数能够保证源串在被覆盖之前将重叠区域的
		 * 字节拷贝到目标区域中，复制后原区域的内容会被更改。
		 * 如果目标区域和原区域没有重叠，则和memcpy()函数功能相同
		 */
		//不知为什么没编译过去
		// const char dest[] = "oldstring";
		// const char src[] = "newstring";

		// printf("Before memmove dest = %s, src = %s\n", dest, src);
		// memmove(dest, src, 9);
		// printf("After memmove dest = %s, src = %s\n", dest, src);

		/**05 void *memset()
		 * 复制字符c（一个无符号字符）到参数str所指向的字符串的前n个字符
		 */
		// char str[50];

		// strcpy(str, "This is string.h library function");
		// puts(str);

		// memset(str, '$', 7);
		// puts(str);

		/**06 char *strcat(char *dest, const char *src) 
		 *  把src所指向的的字符串追加到dest所指向的字符串的结尾
		 */
		// char src[50];
		// char dest[50];

		// strcpy(src, "This is source");
		// strcpy(dest, "This is destination");

		// strcat(dest, src);

		// printf("The last string is |%s|\n", dest);

		/**07 char *strncat(char *dest, const char *src, size_t n)
		 * 把src所指向的字符串追加到dest所指向的字符串的结尾,
		 * 直到n字符长度为止
		 */
		// char src[50];
		// char dest[50];

		// strcpy(src, "This is source");
		// strcpy(dest, "This is destination");

		// strncat(dest, src, 5);

		// printf("The last string is: |%s|", dest);

		/**08 char *strchr(const char *str,int c)
		 * 在参数str所指向的字符串中搜索第一次出现字符c的位置
		 */
		// const char str[] = "http://www.runoob.com";
		// const char ch = '.';
		// char *ret;

		// ret = strchr(str, ch);

		// printf("After the char |%c| is |%s|\n", ch, ret);

		/**09 int strcmp(const char *str1, const char *str2)
		 * 把str1所指向的字符串和str2所指向的字符串进行比较
		 * 返回值<0,则表示str1小于str2
		 */
		// char str1[15];
		// char str2[15];
		// int ret;

		// strcpy(str1, "abcdef");
		// strcpy(str2, "ABCDEF");

		// ret = strcmp(str1, str2);

		// if(ret<0){
		// 	printf("str1 less than str2");
		// }else if(ret > 0){
		// 	printf("str1 big than str2");
		// }else{
		// 	printf("str1 equals str2");
		// }

		/**10 int strncmp(const char *str1, const char *str2, size_t n)
		 * 把str1和str2进行比较，最多比较前n个字节
		 */
		/**11 int strcoll(const char *str1, const char *str2)
		 * 把str1和str2进行比较，结果取决于LC_COLLATE的位置设置
		 * 返回值<0,则表示str1小于str2
		 * >0,=0以此类推
		 */
		// char str1[15];
		// char str2[15];
		// int ret;

		// strcpy(str1, "abc");
		// strcpy(str2, "ABC");

		// ret = strcoll(str1, str2);

		// if(ret > 0){
		// 	printf("str1 big than str2");
		// }else if(ret < 0){
		// 	printf("str1 less than str2");
		// }else{
		// 	printf("str1 equals str2");
		// }

		/**12 char *strcpy(char *dest,  xonst char *src)
		 * 把src所指向的字符串复制到dest
		 * 【注意】如果目标数组dest 不够大，而源字符串的长度又太长
		 * 可能会造成缓存溢出的情况
		 */
		// char str1[]="Sample string";
		// char str2[40];
		// char str3[40];

		// strcpy(str2, str1);
		// strcpy(str3, "copy successful");
		// printf("str1:%s\nstr2:%s\nstr3:%s\n", str1, str2, str3);

		/**13 char *strncpy(char *dest, const char *src,size_t n)
		 * 把src所指向的字符串复制到dest，最多复制n个字符
		 */
		//参见12

		/**14 size_t strcspn(const char *str1, const char *str2)
		 * 检索字符串str1开头连续有几个字符都不含字符串str2中的字符
		 */
		// int len;
		// const char str1[] = "ABCDEF4960910";
		// const char str2[] = "013";

		// len = strcspn(str1, str2);

		// printf("The first match char is located in position: %d\n", len + 1);

		/**15 char *strerror(int errnum)
		 * 从内部数组中搜索错误号errnum，并返回一个指向错误消息字符串的指针
		 */
		// FILE *fp;

		// fp = fopen("file.txt", "r");
		// if(fp==NULL){
		// 	printf("Error:%s\n", strerror(errno));
		// }

		/**16 size_t strlen(const char *str)
		 * 计算字符串长度，包括空格，直到空结束字符，但不包括空结束字符
		 */
		// char str[50];
		// int len;

		// strcpy(str, "This is runoob.com");

		// len = strlen(str);
		// printf("The length of |%s| is |%d|\n", str, len);

		/**17 char *strpbrk(const char *str1, const char *str2)
		 * 检索字符串str1中第一个匹配字符串str2中字符的字符，不包含空结束字符
		 */
		// const char str1[] = "abcde2fghi3jk4l";
		// const char str2[] = "34";
		// char *ret;

		// ret = strpbrk(str1, str2);
		// if(ret){
		// 	printf("The first matching char is: %c\n", *ret);
		// }else{
		// 	printf("Not exsist");
		// }

		/**18 char *strrchr(const char *str, int c)
		 * 在参数str所指向的字符串中搜索【最后一次】出现字符c的地方
		 */
		// int len;
		// const char str[] = "https://www.runoob.com";
		// const char ch = '.';
		// char *ret;

		// ret = strrchr(str, ch);

		// printf("The string after the char |%c| is: |%s|\n", ch, ret);

		/**19 size_t strspn(const char *str1, const char *str2)
		 * 检索字符串str1中第一个不在字符串str2中出现的字符下标
		 * 可以用来检查初始段匹配长度
		 */
		// int len;
		// const char str1[] = "ABCDEFG019874";
		// const char str2[] = "ABCD";

		// len = strspn(str1, str2);
		// printf("The length of metching string is: %d\n", len);


		/**20 char *strrchr(const char *haystack, const char *needle)
		 * 在字符串haystack中查找第一次出现字符串needle的位置
		 * haystack--要被检索的c字符串
		 * needle--在haystack字符串内要搜索的小字符串
		 * 返回值：返回在haystack中第一次出现needle字符串的位置，如果未找到则返回NULL
		 */
		// const char haystack[20] = "RUNOOB";
		// const char needle[10] = "NOOB";
		// char *ret;

		// ret = strstr(haystack, needle);

		// printf("The substr is: %s\n", ret);

		/**21 char *strtok(char *str, const char *delim)
		 * 分解字符串str为一组字符串，delim为分隔符
		 */
		// char str[80] = "This is - www.runoob.com - website";
		// const char s[2] = "-";
		// char *token;

		// /* 获取第一个字符串 */
		// token = strtok(str, s);

		// /* 继续获取其他的子字符串 */
		// while(token!=NULL){
		// 	printf("%s\n", token);

		// 	token = strtok(NULL, s);
		// }

		/**22 size_t strxfrm(char *dest, conse char *src, size_t n)
		 * 根据程序当前的区域选项中的LC_COLLATE来转换字符串src的前n个字符，并把它们放置在字符串dest中
		 */
		// char dest[20];
		// char src[20];
		// int len;

		// strcpy(src, "W3C School");
		// len = strxfrm(dest, src, 20);

		// printf("The length of | %s | is: | %d |\n", dest, len);

	}
	/* ***15 <time.h>*** */
	//exit(0);
	return 0;
}

int sum(int a,int b){
	printf("Here are sum!\n");
	printf("a=%d, b=%d\n", a, b);
	return a + b;
}

int sum_stdarg(int num_args,...){
	int sum = 0;
	va_list ap;//ap是一个va_list参量列表类型的对象，用来存储通过va_arg获取额外参数时所必需的信息
	int i;

	va_start(ap, num_args);//标志获参开始，初始化ap变量

	for (i = 0; i < num_args;i++){//逐个获取参数
		sum += va_arg(ap, int);//va_arg依次获取参量列表ap中所存储的参数
	}

	va_end(ap);//标志获参结束

	return sum;
}

void WriteFormated(FILE *stream, char *format,...){
	va_list ap;//参数列表指针

	va_start(ap, format);
	vfprintf(stream, format, ap);
	va_end(ap);
}

void functionA(){
	printf("This is functionA\n");
}

int cmpfunc(const void *a,const void *b){
	return (*(int *)a - *(int *)b);
}