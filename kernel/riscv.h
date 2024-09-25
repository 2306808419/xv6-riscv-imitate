static inline uint64
r_tp()
{
    uint64 x;

    //volatile表示阻止编译器进行指令重排序
    //%0是一个占位符，后续被替换成了tp寄存器
    //tp是RISC-V架构中的一个特殊寄存器，通常用于存储线程的指针（thread pointer），类似于xv6操作系统中提到的用途
    //tp寄存器通常用于保存当前核心的hartid（硬件线程ID）
    //"=r" 表示输出应该被放置在一个通用寄存器中，并且这个寄存器是只读的（输出约束）
    asm volatile("mv %0,tp":"=r"=(x));
    return x;
}