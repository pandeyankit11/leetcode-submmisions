class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;

        int m=flowerbed.size();
        if(m==1){
            if(flowerbed[0]==1) return false;
            else return true;
        }
        if(m==2 && n==2) return false;
        if(m==2 && n==1){
            if(flowerbed[0]==0 && flowerbed[1]==0)
            return true;
            else return false;
        }
        if(flowerbed[0]==0 && flowerbed[1]==0){
            flowerbed[0]=1;
            n--;
        }
        if(flowerbed[m-1]==0 && flowerbed[m-2]==0){
            flowerbed[m-1]=1;
            n--;
        }

        for(int i=1;i<flowerbed.size()-1;i++){
          if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
            flowerbed[i]=1;
            n--;
          }
       }

     return n<=0;
    }
};
