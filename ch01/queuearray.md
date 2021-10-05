# 队列ADT数组实现
定义结构体，包含
+ 容量 capacity
+ 元素多少 Size
+ 队头 Front
+ 队尾 Rear
+ 元素数组指针 *Array
- - -
##### 注意初始化时，Front=1,Rear=0
这是因为新入队一个元素时，Rear++
