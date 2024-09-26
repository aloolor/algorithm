/*
在有序数组中找到>=num 的最左位置
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Code02_FindLeft
{
public:
    static void main()
    {
        int N = 100;
        int V = 1000;
        int testTime = 10;
        std::cout << "测试开始" << std::endl;
        for(int i = 0;i < testTime;i++)
        {
            int n = rand() % N;
            std::vector<int> arr = randomArray(n,V);
            std::sort(arr.begin(),arr.end());
            int num = rand() % V;
            if(right(arr,num) != findLeft(arr,num))
            {
                std::cout << "出错了" << std::endl;
            }
        }
        std::cout<<"测试结束"<<std::endl;

    }


    static std::vector<int> randomArray(int n,int v)
    {
        std::vector<int> arr(n);
        for(int i = 0;i < n;i++)
        {
            arr[i] = rand() % v + 1;
        }
        return arr;
    }


    static int right(const std::vector<int>& arr,int num)
    {
        for(int i = 0;i < arr.size();i++)
        {
            if(arr[i] >= num)
            {
                return i;
            }
        }
        return -1;
    }

    static int findLeft(const std::vector<int>& arr,int num)
    {
        int l = 0;
        int r = arr.size() - 1;
        int m = 0;
        int ans = -1;
        while(l <= r)
        {
            m = l + ((r - l) >> 1);
            if(arr[m] >= num){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1; 
            }
        }
        return ans;
    }
    
};

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Code02_FindLeft::main();
    return 0;
}