#include <iostream>
#include <bitset>
#include <climits>

using namespace std;

//打印32位的二进制数 
// &（按位与运算）操作是针对二进制位进行的，操作对象不一定需要相同的具体值，只要是整数都可以进行按位与操作。
void printBinary(int num)
{
	for(int i = 31;i >= 0;i--){
		cout << (( num & (1 << i)) == 0 ? '0' : '1');
	}
	cout<<endl;
}

bool returnTrue()
{
	cout << "进入了returnTurn函数" << endl;
	return true;
}

bool returnFalse()
{
	cout << "进入了returnFalse函数" << endl;
	return false;
}

int main()
{
	//非负数
	int a = 78;
	cout << a << endl;
	printBinary(a);
	cout << "====a====" << endl;
	
	//负数
	int b = -6;
	cout << b << endl;
	printBinary(b);
	cout << "====b====" << endl;
	
	//直接写二进制的形式定义变量
	int c = 0b1001110;
	cout << c << endl;
	printBinary(c);
	cout << "====c====" << endl;
	
	//直接写十六进制的形式定义变量
	int d = 0x4e;
	cout << d << endl;
	printBinary(d);
	cout << "====d====" << endl;
	
	//取反~,相反数
	cout << a << endl;
	printBinary(a);
	printBinary(~a);
	int e = ~a + 1;
	cout << e << endl;
	printBinary(e);
	cout << "====e====" << endl;
	
	//int的最小值，取相反数，绝对值都是自己
	int f = INT_MIN;
	cout << f << endl;
	printBinary(f);
	cout << -f << endl;
	printBinary(-f);
	cout << (~f + 1) << endl;
	printBinary(~f + 1);
	cout << "====f====" << endl;
	
	// | & ^
	int g = 0b0001010;
	int h = 0b0001100;
	printBinary(g | h) ;
	printBinary(g & h);
	printBinary(g ^ h);
	cout << "====g,h====" << endl;
	
	//测试逻辑运算符
	//位运算符和逻辑运算符不同，逻辑运算符
	// 可以这么写 : int num = 3231 | 6434;
	// 可以这么写 : int num = 3231 & 6434;
	// 不能这么写 : int num = 3231 || 6434;
	// 不能这么写 : int num = 3231 && 6434;
	// 因为 ||、&& 是 逻辑或、逻辑与，只能连接boolean类型
	// 不仅如此，|、& 连接的两侧一定都会计算
	// 而 ||、&& 有穿透性的特点 
	cout << "test1测试开始" << endl;
	bool test1 = returnTrue() | returnFalse();
	cout << "test1结果：" << test1 <<endl;
	
	cout << "test2测试开始" << endl;
	bool test2 = returnTrue() || returnFalse();
	cout << "test2结果：" << test2 <<endl;
	
	cout << "test3测试开始" << endl;
	bool test3 = returnTrue() & returnFalse();
	cout << "test3结果：" << test3 <<endl;
	
	cout << "test4测试开始" << endl;
	bool test4 = returnTrue() && returnFalse();
	cout << "test4结果：" << test4 <<endl;
	
	cout << "===|,&,||,&&====" << endl;
	
	
	//在c++中右移是算数右移（带符号右移），逻辑右移需要使用无符号数来模拟 
	// <<
	int i = 0b0011010;
	printBinary(i);
	printBinary(i << 1);
	printBinary(i << 2);
	printBinary(i << 3);
	cout << "====i << ====" << endl;
	
	//非负数>>和>>>效果一样
	    printBinary(i);
    printBinary(i >> 2);
    printBinary(static_cast<unsigned int>(i) >> 2); // 使用无符号数来模拟>>>效果
    cout << "===i >> >>>===" << endl;

    // 负数 >> 和 >>> 效果不同
    int j = 0b11110000000000000000000000000000;
    printBinary(j);
    printBinary(j >> 2);
    printBinary(static_cast<unsigned int>(j) >> 2); // 使用无符号数来模拟>>>效果
    cout << "===j >> >>>===" << endl;
	 
	// 位移运算测试
    int k = 10;
    cout << k << endl;
    cout << (k << 1) << endl;
    cout << (k << 2) << endl;
    cout << (k << 3) << endl;
    cout << (k >> 1) << endl;
    cout << (k >> 2) << endl;
    cout << (k >> 3) << endl;
    cout << "===k===" << endl;

    return 0;		 
}