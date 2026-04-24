class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int sum = 0 ,  d = 0 ;
        for(int i = 0 ; i<moves.size() ; i++){
            if(moves[i]=='L'){
                sum+=-1;
            }
            else if(moves[i]=='R'){
                sum+=1;
            }
            else{
                d++;
            }
        }
        if(sum<0){
            return abs(sum)+d;
        }
        if(sum>0){
            return sum+d;
        }
        return d ;
    }
};