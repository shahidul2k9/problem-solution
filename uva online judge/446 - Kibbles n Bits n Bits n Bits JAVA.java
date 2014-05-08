import java.util.Scanner;
public class Main {
    public static void main(String args[]){
        String str;
        String f = new String("");
        String s = new String("");
        int t,incex,sp,l,fn,sn,i,ct =0;
        char ch;
        Scanner sc  = new Scanner (System.in);
        t = sc.nextInt();
        str = sc.nextLine();
        while(ct<t){
            str = sc.nextLine();
            sp = str.indexOf(' ');
            l = str.length();
            f = str.substring(0, sp);
            s = str.substring(sp+3, l);
            fn = Integer.parseInt(f, 16);
            sn = Integer.parseInt(s, 16);
            f = Integer.toBinaryString(fn);
            s = Integer.toBinaryString(sn);
            for(i =0;i<13-f.length();i++)
                System.out.print(0);
            if(str.charAt(sp+1)=='+')
            System.out.print(f+" + ");
            else
                System.out.print(f+" - ");
            for(i =0;i<13-s.length();i++)
                System.out.print(0);
            System.out.print(s);
            if(str.charAt(sp+1)=='+')
            System.out.println(" = "+(fn+sn));
            else 
                System.out.println(" = "+(fn-sn));
            ct = ct+1;
        }
        
        
    }
    
    
}
