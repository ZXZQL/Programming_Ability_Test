// A+B_for_Polynomials.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <cstdio>
#include <map>

using namespace std;

int main()
{
    std::map<int, float> poly;

    int testnum = 0;
    int exp = 0;
    float coe = 0.0;

    for (int i = 0; i < 2; ++i)
    {
        scanf("%d", &testnum);

        for (int j = 0; j < testnum; ++j)
        {
            scanf("%d %f", &exp, &coe);
            poly[exp] += coe;
        }
    }

    std::map<int, float>::reverse_iterator tmpiter = poly.rbegin();
    std::map<int, float>::reverse_iterator iter_begin = poly.rbegin();
    std::map<int, float>::reverse_iterator iter_end = poly.rend();

    // 系数是0的，需要判断，不计入项数
    int itemcount = 0;
    for (tmpiter = iter_begin; tmpiter != iter_end; ++tmpiter)
    {
        if (tmpiter->second != 0) ++itemcount;
    }

    printf("%d", itemcount);

    if (itemcount == 0)
    {
        return 0;
    }

    for (tmpiter = iter_begin; tmpiter != iter_end; ++tmpiter)
    {
        // 系数是0的不输出
        if (tmpiter->second == 0)
            continue;

        if (iter_end != tmpiter)
        {
            printf(" ");
        }

        printf("%d %0.1f", tmpiter->first, tmpiter->second);
    }

    return 0;
}

