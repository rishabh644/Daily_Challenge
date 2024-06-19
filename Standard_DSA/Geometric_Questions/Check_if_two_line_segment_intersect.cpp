class Solution {
  public:

    long long cross_product(int v1[],int v2[])
    {
        return (1ll*v1[0]*v2[1]-1ll*v2[0]*v1[1]);
    }


    long long direction(int p1[],int q1[],int p2[])
    {
        int q1_p1[]={q1[0]-p1[0],q1[1]-p1[1]};

        int p2_p1[]={p2[0]-p1[0],p2[1]-p1[1]};

        return cross_product(q1_p1,p2_p1);

    }

    bool on_segment(int p1[],int p2[],int p3[])
    {
        if( ( min(p1[0],p2[0])<=p3[0]  && p3[0]<=max(p1[0],p2[0]) )
           && ( min(p1[1],p2[1])<=p3[1]  && p3[1]<=max(p1[1],p2[1])) )
        return true;
        else
        return false;
    }


    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        // code here

        long long d1=direction(p1,q1,p2);
        long long d2=direction(p1,q1,q2);

        long long d3=direction(p2,q2,p1);
        long long d4=direction(p2,q2,q1);

        if(( (d1>0 && d2<0) || (d1<0 && d2>0) ) && ( (d3>0 && d4<0) || ( d3<0 && d4>0) ))
        {
            return "true";
        }
        else if (d1==0 && on_segment(p1,q1,p2))
        return "true";
        else if(d2==0 && on_segment(p1,q1,q2))
        return "true";
        else if(d3==0 && on_segment(p2,q2,p1))
        return "true";
        else if(d4==0 && on_segment(p2,q2,q1))
        return "true";
        else
        return "false";


    }
};