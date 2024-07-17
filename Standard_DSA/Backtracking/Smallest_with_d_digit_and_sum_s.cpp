// Given two integers s and d. The task is to find the smallest number
// such that the sum of its digits is s and the number of digits in the number are d.
// Return a string that is the smallest possible number.
// If it is not possible then return -1.

bool getstring(int i,int d,int& s,string& ans)
    {
        if(i==d)
        {
            if(s==0)
            return true;
            else
            return false;
        }

        int v;
        if(i==0)
        {
            v=1;
        }
        else
        {
            v=0;
        }

        while(v<=9)
        {
            if(s>=v)
            {
                ans.push_back('0'+v);
                s-=v;
                if(getstring(i+1,d,s,ans))
                return true;

                s+=v;
                ans.pop_back();

            }
            else
            {
                break;
            }

            v+=1;

        }

        return false;
    }

    string smallestNumber(int s, int d)
    {
        // code here

        int i=0;

        string ans;

        bool isPossible=getstring(i,d,s,ans);

        if(isPossible)
        return ans;
        else
        return "-1";
    }
};
//////////////////------------///////////
string smallestNumber(int s, int d)
    {
        // code here
        if (s > 9 * d) {
        return "-1";
    }

    string result(d, '0'); // Initialize a string of length d with '0'

    // Iterate over each digit position
    for (int i = d - 1; i >= 0; --i) {
        // Calculate the digit value for the current position
        if (s > 9) {
            result[i] = '9';
            s -= 9;
        } else {
            result[i] = '0' + s;
            s = 0;
        }
    }

    // If the first digit is '0', it means we need to adjust the leading digit
    if (result[0] == '0') {
        result[0] = '1'; // Make the leading digit '1'
        for (int i = 1; i < d; ++i) {
            if (result[i] != '0') {
                result[i] -= 1; // Adjust the subsequent digit
                break;
            }
        }
    }

    return result;
    }