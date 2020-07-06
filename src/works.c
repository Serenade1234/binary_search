#include <stdio.h>

int n;
int k;
int A[100000];


int p(int x){
  int sum = 0, hand = 1;
  for(int i=0; i<n; i++){

    if(x >= A[i]){

      if(x >= sum + A[i]){
        sum += A[i];

      }else{
        hand++;
        sum = A[i];
      }

    }else{
      return 0;
    }
  }
  /*探索中の時間にあわせると人があまる
    <=> 時間はもっと削れる*/
  return k >= hand;
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  int _sum = 0;
  for(int i=0; i<n; i++) _sum += A[i];

  lb = 0;
  ub = _sum;

  while(ub - lb > 1){
    
    int mid = (ub + lb) / 2;

    if(p(mid)){
      ub = mid;
    }else{
      lb = mid;
    }

  }

  printf("%d\n", ub);

  return 0;
}
