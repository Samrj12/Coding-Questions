import java.lang.Number;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
public class x{
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("austin");
        list.add("dallas");
        list.add("houston");
        System.out.println(solve(list, 2));
    }
    public static String solve(List<String> list, int m)
    {
        BigInteger res = BigInteger.ZERO;
        for(int i=0;i<list.size();i++)
        {
            BigInteger temp = BigInteger.ONE;
            for(int j=0;j<list.get(i).length();j++)
            {
                int x = list.get(i).charAt(j);
                temp = temp.multiply((new BigInteger(Integer.toString(x))).pow(m));
            }
            res.add(temp);
        }
        return (res.mod(BigInteger.TWO) == BigInteger.ZERO) ? "EVEN":"ODD";
    }
}