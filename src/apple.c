#include <stdio.h>

int n;
int k;
int A[100000];

int isMidEnough(int x){
  int requiredBag = 0;

  for(int i=0; i < n; i++){
    //printf("%d ", A[i]);
    if(A[i]%x == 0){
      requiredBag += A[i] / x;
    }else{
      requiredBag += A[i] / x + 1;
    }
  }
  //printf("min : %d, required : %d, bagN : %d\n", x, requiredBag, k);
  
  /*探索中の要素を最小としたときに必要なバッグの数が指定の数より小さい
     <=> バッグはもっと多くて良い
     <=> バッグに入る小さい量はもっと少なくて良い。
     <=> 要件を満たす最小のりんごの数は今より前の位置にある。
  */
  
  return requiredBag <= k;
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;

  while(ub - lb > 1){
    
    int mid = (ub + lb) / 2;

    if(isMidEnough(mid)){
      ub = mid;
    }else{
      lb = mid;
    }

  }

  printf("%d\n", ub);
  return 0;
}
