import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FilterInputStream;
import java.io.IOException;
import java.io.InputStream;


public class LowerCaseInputStream extends FilterInputStream{
	
	public LowerCaseInputStream (InputStream in) {
		super(in);
	}
	
	public int read() throws IOException {
		int c = super.read();
		return (c == -1 ? c : Character.toLowerCase((char) c));
	}
	
	public int read(byte[] b, int offset, int len) throws IOException {
		int result = super.read(b, offset, len);
		for (int i = offset; i < offset + result; i++) {
			b[i] = (byte)Character.toLowerCase((char)b[i]);
		}
		return result;
	}
	
	/*public static void main (String[] args) {
		int c;
		try {
			InputStream in = new LowerCaseInputStream(new BufferedInputStream(new FileInputStream("/home/wbmc74/code/DesignPattern/DesignPattern/bin/test.txt")));
			
			while ((c = in.read()) >= 0) {
				System.out.print((char)c);
				
			}
			
			in.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	} */

}
