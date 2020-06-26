#include <iostream>
//#include <string>
using namespace std;

// ================= 代码实现开始 =================
const int N=100005;
/* 请在这里定义你需要的全局变量 */
string  Stack[N];
int n,top;

// 压入栈顶
// name：被压入的人的姓名
void push(string name) {
    /* 请在这里设计你的算法 */
    Stack[++top]=name;
}

// 弹出栈顶
// 返回值：被弹出人的姓名
string pop() {
    /* 请在这里设计你的算法 */
    return Stack[top--];
}

// 询问栈中某个位置上的人的姓名（栈底位置为1，向栈顶方向的位置依次递增）

// 返回值：pos位置上人的姓名
string query(int pos) {
    /* 请在这里设计你的算法 */
    return Stack[pos];
    
}

// ================= 代码实现结束 =================

int main() {
    printf("Please input the number of the stack: ");
    scanf("%d", &n);
    char name[20];
    for (; n--; ) {
        int op;
        printf("1: push, 2: pop, 3: query \n");
        scanf("%d", &op);
        if (op == 1) {
            printf("Please input the name: ");
            scanf("%s", name);
            push(name);
        } else if (op == 2) {
            printf("name: %s\n",pop().c_str());
        } else {
            int pos;
            scanf("%d", &pos);
            printf("name: %s\n", query(pos).c_str());
        }
    }
    return 0;
}
