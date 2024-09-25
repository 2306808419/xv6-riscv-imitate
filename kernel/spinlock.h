//互斥锁
struct spinlock{
    
    uint locked; //该自旋锁是否被持有

    //用于debugging
    char *name;//锁的名称
    struct cpu *cpu;//持有这把锁的cpu的名称

}