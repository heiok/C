//
//  main.c
//  student
//
//  Created by Heiok on 2019/12/21.
//  Copyright © 2019 Heiok.com. All rights reserved.
//

# include <stdio.h>
# include <stdlib.h>
struct Student
{
    char name[100];
    int age;
    float score;
};

int main(void)
{
    int len;
    printf("请输入要录入的学生个数： ");
    //printf("len = ");
    scanf("%d",&len);
  
    //学生信息录入
    int i;
    struct Student * pArr;
    pArr = (struct Student *)malloc(sizeof(struct Student)*len);
    
    for (i=0; i<len; ++i)
    {
        printf("请输入第%d个学生的信息：\n",i+1);
        printf("学生姓名：");
        scanf("%s",(pArr+i)->name);
        printf("学生年龄：");
        scanf("%d",&(pArr+i)->age);
        printf("学生分数：");
        scanf("%f",&(pArr+i)->score);
        printf("\n");
    }
    
    //学生信息排序(按成绩）
    int j;
    struct Student t;
    for (i=0; i<len; ++i)
    {
        for (j=0; j<len-i-1; ++j)
        {
            if (pArr[j].score > pArr[j+1].score)
            {
                t = pArr[j];
                pArr[j] = pArr[j+1];
                pArr[j+1] = t;
            }
        }
    }
    
    //学生信息输出
    for (i=0; i<len; ++i)
    {
        printf("学生成绩由低到高结果");
        printf("第%d个学生的信息是：\n",i+1);
        printf("姓名：%s ",(pArr+i)->name);
        printf("年龄：%d ",(pArr+i)->age);
        printf("分数：%f ",(pArr+i)->score);
        printf("\n");
    }
    
    free(pArr);
    
    return 0;
}
