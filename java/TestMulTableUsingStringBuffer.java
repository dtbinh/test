public class TestMulTableUsingStringBuffer {
    public static void main(String[] args) {
        StringBuffer strBuf = new StringBuffer();
        long startTime = System.currentTimeMillis();
        strBuf.append("...."+'\n');
        strBuf.append("aaaaaa"+'\n');
        
        for (int i=1;i<=9;i++) {
            strBuf.append(i + "|");
            for (int j=1;j<=9;j++) {
                if (i*j < 10)
                  strBuf.append("  "+ i*j);
                else
                  strBuf.append(" "+i*j );
            }
            strBuf.append(" " + '\n');
        }
        System.out.println(strBuf);
        long endTime = System.currentTimeMillis();
        System.out.println("Elapsed time is" + (endTime - startTime)+
                    "milliseconds");

    }

}
