#include <iostream>
#include <vector>
using namespace std;

// ================= 代码实现开始 =================
const int N = 100005;
/* 请在这里定义你需要的全局变量 */

//二叉树节点
struct node {
    int val,l,r;
} t[N];

int root,cnt;  //root：二叉树根节点，cnt:整个二叉树大小

//在以x为根的树中插入一个数字v
int insert(int v,int x){
    if (x == 0){  //第一个空格
        x = ++cnt;
        t[x].val = v;
        t[x].l = 0;
        t[x].r = 0; //初始化root节点
        return x;
    }
    
    //递归插入左右子树
    if (v < t[x].val) //第二个空格
        t[x].l = insert(v,t[x].l);
    else
        t[x].r = insert(v,t[x].r);
    return x;
}

//求以x为根的二叉树的前序遍历
//x为当前节点
//ans；存储结果的数组
void dlr(int x,vector<int> &ans){
    if (x){        //第三个空格，递归终止条件
        ans.push_back(t[x].val);
        dlr(t[x].l,ans);
        dlr(t[x].r,ans);
    }
}

void lrd(int x,vector<int> &ans){
    if (x){        //第四个空格
        lrd(t[x].l,ans);
        lrd(t[x].r,ans);
        ans.push_back(t[x].val);
    }
}

void ldr(int x,vector<int> &ans){
    if (x){        //中序遍历
        ldr(t[x].l,ans);
        ans.push_back(t[x].val);
        ldr(t[x].r,ans);
    }
}
// 给定一个1到n的排列，依次插入到二叉树中，返回前序遍历和后序遍历
// n：如题意
// sequence：给定的排列，大小为n
// 返回值：将要输出的元素依次加入到返回值中
vector<int> getAnswer(int n, vector<int> sequence) {
    /* 请在这里设计你的算法 */
    root = cnt =0; //初始化
    
    for (int i = 0, p = int(sequence.size()); i< p; ++i)    //int 数据转换防止警告
        {
            root = insert(sequence[i],root);  // root 是否是根节点的标志
//            printf("--%d--", root);
        }

    vector<int> ans; //返回值,ans：存储结果的数组
    dlr(root,ans); //前序遍历
    lrd(root,ans); //后序遍历
    ldr(root,ans); //中序遍历
    
    return ans;
}

// ================= 代码实现结束 =================

int main() {
    int n;
    printf("The number of node：");
    scanf("%d", &n);
    vector<int> sequence;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sequence.push_back(x);
    }
    vector<int> ans = getAnswer(n, sequence);
    printf("前序：");
    for (int i = 0; i < n; ++i)
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    printf("后序：");
    for (int i = 0; i < n; ++i)
        printf("%d%c", ans[n + i], " \n"[i == n - 1]);
    printf("中序：");
    for (int i = 0; i < n; ++i)
        printf("%d%c", ans[2*n + i], " \n"[i == n - 1]);
    return 0;
}
