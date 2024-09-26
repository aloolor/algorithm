/*
在有序数组中，找到是否存在一个数，二分搜索法
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Code01_FindNumber{
public:
    static void main()
    {
        int N = 100;
        int V = 1000;
        int testTime = 10;//测试次数
        std::cout << "测试开始" << std::endl;
        for(int i = 0;i < testTime;i++){
            int n = rand() % N;
            std::vector<int> arr = randomArray(n,V);
            std::sort(arr.begin(),arr.end());
            int num = rand() % V;
            if(right(arr,num) != exist(arr,num)){
                std::cout << "出错了" << std::endl;
            }

        }
        std::cout << "测试结束" << std::endl;
    }

    //生成随机数组 n为数组最大长度，v为数值最大范围
    static std::vector<int> randomArray(int n,int v){
        std::vector<int> arr(n);
        for(int i = 0;i < n;i++){
            arr[i] = rand() % v + 1;
        }
        return arr;
    }

    //验证数组中的每个值是否相同
    static bool right(const std::vector<int>& sortedArr,int num)
    {
        for(int cur : sortedArr)
        {
            if(cur == num)
            {
                return true;
            }
        }
        return false;
    }


    //arr有序递增才可以用这个方法，二分搜索是否存在这个数
    static bool exist(const std::vector<int>& arr,int num)
    {
        if(arr.empty()){
            return false;
        }
        int l = 0;
        int r = arr.size() - 1;
        int m = 0;
        while(l <= r)
        {
            m = l + (r - l) / 2;//防止溢出的找中点方法
            if(arr[m] == num)
            {
                return true;
            }else if(arr[m] < num)
            {
                l = m + 1;
            }else
            {
                r = m - 1;
            }
        }
        return false;
    }

};

int main()
{
    srand(static_cast<unsigned int>(time(0)));//初始化随机种子
    Code01_FindNumber::main();
    return 0;
}