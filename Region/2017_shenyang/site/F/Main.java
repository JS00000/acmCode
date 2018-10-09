import java.util.*;
import java.math.*;

public class Main
{
    public static void main(String[] args) {
        BigInteger f[] = new BigInteger[1005];//数组的用法和C#类似
        //二维数组BigInteger[][] f=new BigInteger[1005][1005];
        f[0]=BigInteger.valueOf(2);
        f[1]=BigInteger.valueOf(4);
        for(int i=2;i<=1000;i++)
            f[i]=f[i-1].multiply(BigInteger.valueOf(4)).subtract(f[i-2]);
        Scanner input = new Scanner(System.in);
        int t,k;
        BigInteger n;
        //用for(...;t--;)替代会报错，因为要求第二个表达式必须返回bool
        for(t=input.nextInt();t>0;t--) {
            n=input.nextBigInteger();
            for (k=1;k<=1000;k++) {
                if (n.compareTo(f[k]) <= 0) {
                    System.out.println(f[k]);
                    break;
                }
            }
        }
    }
}
