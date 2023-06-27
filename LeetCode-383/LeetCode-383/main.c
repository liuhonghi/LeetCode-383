//
//  main.c
//  LeetCode-383
//
//  Created by HiLau on 2023/6/27.
//

#include <stdio.h>
#include <stdbool.h>

//leetcode刷题 - 383 赎金信



bool canConstruct(char * ransomNote, char * magazine){
    int r=strlen(ransomNote);
    int m=strlen(magazine);
    if(r>m){
//判断两个字符串长度
        return false;
    }
    int ans[26]={0};
//创建额外数组
    for(int i=0;i<r;i++){
        ans[ransomNote[i]-'a']++;
        ans[magazine[i]-'a']--;
//1遍历，ransomNote的元素下标++
//magezine的元素下标--
    }
    if(m>r){
//判断magazine是否长于ransomNote
        for(int i=r;i<m;i++){
//继续遍历，注意是从r开始
            ans[magazine[i]-'a']--;
        }
    }
    for(int i=0;i<26;i++){
        if(ans[i]>0)
//只要大于0就return false,可以是负数，因为magezine可以长于ransomNote
        return false;
    }
    return true;
}

int main() {
    char ransomNote[] = "aabbcc";
    char magazine[] = "abcabc";

    bool result = canConstruct(ransomNote, magazine);

    if (result) {
        printf("可以构建\n");
    } else {
        printf("无法构建\n");
    }

    return 0;
}
