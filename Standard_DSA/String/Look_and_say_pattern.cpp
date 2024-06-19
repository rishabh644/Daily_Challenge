    string lookandsay(int n)
    {
        // Base case: if n is 1, the first term is 1
        if(n==1)
        return "1";

       // Initialize the first term

        string prev="1";
        int termNumber=1;


       // Generate terms until reaching the n-th term

        while(termNumber<n)
        {
            int length=prev.size();

            int count=1;

            string currentTerm="";

            // Build the next term by reading the previous term

            for(int i=1;i<length;i++)
            {
                if(prev[i]!=prev[i-1])
                {
                    currentTerm+=to_string(count)+prev[i-1];
                    count=1;
                }
                else{
                count++;
                }
            }


            // Append the last counted character and its count
            currentTerm+=to_string(count)+prev[length-1];


            // Update the previous term to the current term
            prev=currentTerm;

            // Increment the term number to process the next term
            termNumber+=1;
        }


        return prev;
    }