import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        while(T-- > 0){
            int N = Integer.parseInt(br.readLine().trim());
            int K = Integer.parseInt(br.readLine().trim());
            String S = br.readLine().trim();
            String result = getNextBeautifulString(N, K, S);
            out.println(result);
        }
        out.flush();
    }

    public static String getNextBeautifulString(int N, int K, String S){
        char[] s = S.toCharArray();
        for(int i = N -1; i >=0; i--){
            for(char ch = (char)(s[i] +1); ch < 'a' + K; ch++){
                if(isValid(s, i, ch)){
                    s[i] = ch;
                    boolean possible = true;
                    for(int j = i +1; j < N; j++){
                        boolean found = false;
                        for(char c = 'a'; c < 'a' + K; c++){
                            if(isValid(s, j, c)){
                                s[j] = c;
                                found = true;
                                break;
                            }
                        }
                        if(!found){
                            possible = false;
                            break;
                        }
                    }
                    if(possible){
                        return new String(s);
                    }
                }
            }
        }
        return "-1";
    }

    public static boolean isValid(char[] s, int pos, char ch){
        if(pos >=1 && s[pos -1] == ch){
            return false;
        }
        if(pos >=2 && s[pos -2] == ch){
            return false;
        }
        return true;
    }
}