class Solution {
public:
    string interpret(string command) {
        string str= "";
        for(int i=0;i<command.length();){
            if(command[i]=='G'){
                str=str+'G';
                i++;
            }
            else if(command[i]=='(' && command[i+1]==')')
            {
                str= str+ 'o';
                i=i+2;
            }
            else if(command[i]=='(' && command[i+1]=='a')
            {
                str=str+"al";
                i=i+4;
            }
        }
        return str;
    }
};