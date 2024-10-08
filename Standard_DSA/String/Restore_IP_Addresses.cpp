
// A valid IP address consists of exactly four integer
//seperated by single dots. Each integer is between 0 and 255
// and cannot have leading zeros.


// * For example,"0.1.2.201" and "192.168.1.1" are
// valid IP addresss, but "0.011.255.245","192.168.1.312"
// and "192.168@1.1" are invalid IP addresses

// Given a string S containing only digits,
// return all possible valid IP addresses that can be formed
// by inserting dots into s. You are not allowed
// to reorder or remove any digits in s. You may return the valid
// IP addresses in any order.

    vector<string> restoreIpAddresses(string s) {

        vector<string>ret;

        string ans;

        for(int a=1;a<=3;a++)
        {
            for(int b=1;b<=3;b++)
            {
                for(int c=1;c<=3;c++)
                {
                    for(int d=1;d<=3;d++)
                    {

                        if((a+b+c+d)==s.size()){

                            int A=stoi(s.substr(0,a));
                            int B=stoi(s.substr(a,b));
                            int C=stoi(s.substr(a+b,c));
                            int D=stoi(s.substr(a+b+c,d));

                            if(A<=255 && B<=255 && C<=255 && D<=255)
                            {
                                 if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
                        ret.push_back(ans);

                            }

                                                }

                    }
                }
            }
        }


        return ret;


    }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    void backtrack(string &s,int start,int segment,string currentIP,vector<string>&result)
    {
         // Base case: if we've placed 4 segments and used all characters in s

         if(segment==4 && start==s.size())
         {
            result.push_back(currentIP);
            return;
         }

         if(segment==4 || start==s.size())
         {
            return;
         }
         // Try segments of length 1,2 and 3

         for(int len=1;len<=3;++len)
         {

            // Ensure we don't go past the end of the string

            if( ( start+len )> s.size() )
            break;

            string part=s.substr(start,len);

            int value=stoi(part);

            //Check if the segments is valid (0<= value <=255 and no leading zeros)

            if( value>255 || (len>1 && s[start]=='0'))
            {
                break;
            }

            // Append the segment to the current IP address

            string newIP=currentIP+part+(segment<3?".":"");

            // Recurse to place the next segment

            backtrack(s,start+len,segment+1,newIP,result);

         }



    }
    vector<string> restoreIpAddresses(string s) {

        vector<string>result;

        if(s.size()>=4 && s.size()<=12){

            backtrack(s,0,0,"",result);
        }

        return result;

    }