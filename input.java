import java.io.*;
public class input{
	public static void main(String[] args){
		Scanner inp = new Scanner(new File("/home/ashraf/Downloads/array.txt"));
		while(input.hasNextLine()){
    	Scanner colReader = new Scanner(input.nextLine());
    	ArrayList col = new ArrayList();
    		while(colReader.hasNextInt())
    		{
        		col.add(colReader.nextInt());
    		}
    		a.add(col);
		}
	}
}