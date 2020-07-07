#include <stdio.h>

int n;
int k;
int A[100000];


int isKEnoughLong(int thisLong){
  
  int spearSum = 0;
  for(int i=0; i<n; i++) spearSum += A[i] / thisLong;

  //printf("produce:%d, need:%d\n", spearSum, k);
  /*作られる槍が必要量より少ない <=> 一本あたりはもっと小さくて良い*/
  return spearSum < k;
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000001; //絶対にこの長さ以上を作れることは無い。

  while(ub - lb > 1){
    
    int mid = (ub + lb) / 2;
    //printf("%d < %d < %d\n", lb, mid, ub);
    if(isKEnoughLong(mid)){
      ub = mid;
    }else{
      lb = mid;
    }

  }

  printf("%d\n", lb);

  return 0;
}
