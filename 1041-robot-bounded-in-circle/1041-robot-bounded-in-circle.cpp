class Solution {
public:
    bool isRobotBounded(string instructions) {
                //given
        char current_dir = 'N';
        //co-ordinate points
        int x = 0, y= 0;
        for(int i=0;i<instructions.size();i++){ 
            //Case1: If 'G' is in the instruction string
            if(instructions[i] == 'G'){
                y += current_dir =='N' ? 1 : 0;
				y += current_dir =='S' ? -1 : 0;
				x += current_dir == 'E' ? 1 : 0;
				x += current_dir == 'W' ? -1 : 0;
            }
            //case2: If we found 'directions'
            else{
                char incoming = instructions[i];
                if(current_dir == 'N'){
                    current_dir = incoming == 'L' ? 'W' : 'E';
                }
                else if(current_dir == 'W'){
                    current_dir = incoming == 'L' ? 'S' : 'N';
                }
                else if(current_dir == 'S'){
                    current_dir = incoming == 'L' ? 'E' : 'W';
                }
                else{
                    current_dir = incoming == 'L' ? 'N' : 'S';
                }
            } 
            
        }
        //if the robo is at origin or the current direction is not north than return true
        if((x==0 && y == 0)|| current_dir!='N')
            return true;
        
        return false;
        
    }
};