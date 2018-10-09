import java.math.BigDecimal;
import java.util.Scanner;

public class T1001 {
    public static void main(String[] args) {

        Scanner sca = new Scanner(System.in);

        BigDecimal R,sum;
        BigDecimal x1,x2,x3,y1,y2,y3,X,Y,dis;
        BigDecimal a1, a2, b1, b2, c1, c2, d, cx, cy;

        int T;
        T = sca.nextInt();
        while( T-- > 0 ){
            x1 = sca.nextBigDecimal();
            y1 = sca.nextBigDecimal();
            x2 = sca.nextBigDecimal();
            y2 = sca.nextBigDecimal();
            x3 = sca.nextBigDecimal();
            y3 = sca.nextBigDecimal();
            X = sca.nextBigDecimal();
            Y = sca.nextBigDecimal();

            a1 = x2.subtract(x1);
            b1 = y2.subtract(y1);
            c1 = a1.multiply(a1).add(b1.multiply(b1)).divide(new BigDecimal(2));

            a2 = x3.subtract(x1);
            b2 = y3.subtract(y1);
            c2 = a2.multiply(a2).add(b2.multiply(b2)).divide(new BigDecimal(2));

            d = a1.multiply(b2).subtract(a2.multiply(b1));

            cx = x1.add(c1.multiply(b2).subtract(c2.multiply(b1)).divide(d));
            cy = y1.add(a1.multiply(c2).subtract(a2.multiply(c1)).divide(d));

            R = ((x1.subtract(cx)).pow(2)).add((y1.subtract(cy)).pow(2));
            dis = ((X.subtract(cx)).pow(2)).add((Y.subtract(cy)).pow(2));

            if (dis.compareTo(R)>0){
                System.out.println("Accepted");
            }else{
                System.out.println("Rejected");
            }
        }
    }
}
