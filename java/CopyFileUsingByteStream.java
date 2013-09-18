import java.io.*;

public class CopyFileUsingByteStream {
    public static void main (String[] args)
    {
        FileInputStream fis = null;
        FileOutputStream fos = null;

        if (args.length != 2)
        {
            System.out.println("");
            System.exit(0);
        }

        try{
            fis = new FileInputStream(new File(args[0]));

            File file = new File(args[1]);
            if(file.exists())
            {
                System.out.println("exists");
                return;
            }
            else    fos = new FileOutputStream(args[1]);

            System.out.println("The file" + args[0] + "has" + fis.available() + "bytes");

            int r;
            while((r=fis.read()) != -1){
                fos.write((byte)r);
            }
            }
            finally {
                try{
                    if (fis != null) fis.close();
                    if (fos != null) fos.close();
                }

                catch (IOException ex)
                {
                    System.out.println(ex);
                }

            }
        
    }
}
