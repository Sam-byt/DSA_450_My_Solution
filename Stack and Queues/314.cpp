int Solution::braces(string A) {

    stack<char>s; 
    for(auto i: A)
    {
        if(i == '(' || i == '+' ||  i == '-' ||  i == '*' ||  i == '/' )s.push(i);
        else{
            if(i == ')')
            {
                bool isRedundant = true;

                while(s.top()!='(')
                {
                    char temp = s.top();
                    if(temp == '+' ||  temp == '-' ||  temp == '*' ||  temp == '/')
                        isRedundant = false;
                    s.pop();
                }

                if(isRedundant)return true;

                s.pop();


            } 
        }
    }

    return false;

}
