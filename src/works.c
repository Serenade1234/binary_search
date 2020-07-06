#include <stdio.h>

int n;
int k;
int A[100000];


int p(m){
  return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  _sum = 0;
  for(int i=0; i<n; i++) _sum += A[i];

  lb = 0;
  ub = _sum; //???????????

  while(ub - lb > 1){
    
    int mid = (ub + lb) / 2;

    if(p(mid)){
      ub = mid;
    }else{
      lb = mid;
    }

  }

  return 0;
}
