#include <iostream>
#include <vector>
using namespace std;

// ================= 代码实现开始 =================

typedef long long ll;
/* 请在这里定义你需要的全局变量 */
const int Mod =1000003;  //哈希表的模数
vector<ll> table[Mod];

int Hash(ll x){        //这是一个哈希函数
    return x % Mod;
}

// 执行操作时会调用这个函数
// op：对应该次操作的 op（具体请见题目描述）
// x：对应该次操作的 x（具体请见题目描述）
// 返回值：如果输出为"Succeeded"，则这个函数返回 1，否则返回 0
bool check(int op, ll x) {
    /* 请在这里设计你的算法 */
    int h = Hash(x);  //求出x的哈希值

    vector<ll>::iterator ptr = table[h].end();
    for (vector<ll>::iterator it = table[h].begin();it != table[h].end(); ++it)
    if(*(it) == x){  //第一个空格
        ptr = it;
        break;
    }
    if(op == 1){
        if(ptr == table[h].end()){  //第二个空格
            table[h].push_back(x); //第三个空格
        return 1;
    }
    return 0;
    }else {
        if(ptr != table[h].end()){  //第四个空格
        *ptr = table[h].back();
        table[h].pop_back(); //第五个空格
        return 1;
        }
    return 0;
    }
}

// ================= 代码实现结束 =================

int main() {
    int Q, op;
    ll x;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%lld", &op, &x);
        puts(check(op, x) ? "Succeeded" : "Failed");
    }
    return 0;
}
