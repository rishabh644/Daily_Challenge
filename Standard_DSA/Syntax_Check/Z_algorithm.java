import java.util.ArrayList;
import java.util.List;

public class Z_algorithm {


private int[] calculateZ(char input[])
{
    int Z[] = new int[input.length];

    int left = 0;
    int right = 0;


    for (int k = 1; k < input.length; k++) {

        if (k > right) {


                       }




    }

    return z;

}


public List<Integer> matchPattern(char text[],char pattern[])
{

}

public static void main(String args[])
{
    String text = "aaabcxyzaaaabczabbaaaaaaaaaac";

    String pattern = "aaabc";

    Z_algorithm zAlgorithm = new Z_algorithm();

    List<Integer> result = zAlgorithm.matchPattern(text.toCharArray(), pattern.toCharArray());



    result.forEach(System.out::println);


}





}
