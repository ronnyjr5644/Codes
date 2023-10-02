class Solution {
public:
    bool winnerOfGame(string colors) {
       
        int n=colors.size();
        int A=0;
        int B=0;
        for(int i=0;i<n-2;i++){
            if(colors[i]==colors[i+1] && colors[i+1]==colors[i+2] && colors[i]=='A'){
                A++;
            }
            if(colors[i]==colors[i+1] && colors[i+1]==colors[i+2] && colors[i]=='B'){
                B++;
            }
        }
        if(B>=A){
            return false;
        }
        return true;
    }
};