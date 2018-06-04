#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#define TEST_HEADER printf("\n=============%s=============\n",__FUNCTION__)
//////////////////////////////////
//归并排序 递归版本
/////////////////////////////////
void _MergeArray(int arr[],int beg,int mid,int end,int* tmp)
{
    int cur1=beg;
    int cur2=mid;
    int tmp_index=beg;
    while(cur1<mid&&cur2<end)
    {
        if(arr[cur1]<arr[cur2])
        {
            tmp[tmp_index++]=arr[cur1++];
        }
        else
        {
            tmp[tmp_index++]=arr[cur2++];
        }
    }
    while(cur1<mid)
    {
        tmp[tmp_index++]=arr[cur1++];
    }
    while(cur2<end)
    {
        tmp[tmp_index++]=arr[cur2++];
    }
    memcpy(arr+beg,tmp+beg,sizeof(int)*(end-beg));
}
void _MergeSort(int arr[],int beg,int end,int *tmp)
{
    if(end-beg<=1)
    {
        return;
    }
    int mid=beg+(end-beg)/2;
    _MergeSort(arr,beg,mid,tmp);
    _MergeSort(arr,mid,end,tmp);
    _MergeArray(arr,beg,mid,end,tmp);

}
void MergeSort(int arr[],size_t size)
{
    if(arr==NULL||size<=0)
    {
        return;
    }
    int *tmp=(int*)malloc(sizeof(int)*size);
    _MergeSort(arr,0,size,tmp);
}
//////////////////////////////////
//归并排序 递归版本
/////////////////////////////////
void MergeSortByLoop(int arr[],size_t size)
{
    if(arr==NULL||size<=0)
    {
        return;
    }
    int *tmp=(int*)malloc(sizeof(int)*size);
    size_t gap=1;
    for(;gap<size;gap*=2)
    {
        size_t i=0;
        for(;i<size;i+=2*gap)
        {
            size_t beg=i;
            size_t mid=i+gap;
            size_t end=i+2*gap;
            if(mid>size)
            {
                mid=size;
            }
            if(end>size)
            {
                end=size;
            }
            _MergeArray(arr,beg,mid,end,tmp);
        }
    }
}
/////////////////////////////////
//测试代码
////////////////////////////////
void TestPrint(int arr[],int len)
{
    int i=0;
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void TestMergeSort()
{
    TEST_HEADER;
    int arr[]={1,2,3,4,9,8,7,5,6};
    size_t len=sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,len);
    TestPrint(arr,len);
}
void TestMergeSortByLoop()
{
    TEST_HEADER;
    int arr[]={1,2,3,4,9,8,7,5,6};
    size_t len=sizeof(arr)/sizeof(arr[0]);
    MergeSortByLoop(arr,len);
    TestPrint(arr,len);
}
int main()
{
    TestMergeSort();
    TestMergeSortByLoop();
    return 0;
}
