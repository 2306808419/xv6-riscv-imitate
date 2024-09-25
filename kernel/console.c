#include "spinlock.h"
#include "riscv.h"
struct {
  struct spinlock lock;
  
  // 输入
#define INPUT_BUF_SIZE 128
  char buf[INPUT_BUF_SIZE];
  uint r;  // Read index
  uint w;  // Write index
  uint e;  // Edit index
} cons;
int consolewrite(int user_src,uint64 src,int n){
    int i;

    for(int i=0;i<n;++i){
        char c;
        //使用either_copyin函数尝试从用户空间读取一个字节。这里，src+i是用户空间缓冲区的当前偏移量，1表示读取的字节数。如果读取失败（返回-1），则跳出循环。
        if(
            either_copyin(&c,user_src,src+i,1)==-1)
            break;
            uartputc(c);
    }
}

void
consoleinit(void)
{
    initlock(&cons.lock,"cons");

    uartinit();

    //连接读和写的系统调用
    //
   // devsw[CONSOLE].read = consoleread;
    devsw[CONSOLE].write = consolewrite;
}