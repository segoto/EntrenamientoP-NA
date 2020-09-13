import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
class Comparador implements Comparator<String[]>{
  @Override
  public int compare(String[] o1, String[] o2) {
    int a = Integer.parseInt(o1[1]);
    int b= Integer.parseInt(o2[1]);
    if(a==b){
      return o1[0].compareToIgnoreCase(o2[0]);
    }
    return Integer.parseInt(o2[1])-Integer.parseInt(o1[1]);
  }
}
class Main {
  public static void main(String[] args) {
    try{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String line = br.readLine();
      int i=1;
      while(!line.equals("")){
        int test = Integer.parseInt(line);
        ArrayList<String[]> arrList = new ArrayList<>();
        for(int m=0; m<test; ++m){
          line = br.readLine();
          String[] values = line.split(";");
          String name = values[0];
          int value = 0;
          for(int j=1;j<values.length;++j){
            String[] moreValues = values[j].split(" ");
            for(int k=0; k<moreValues.length; ++k){
              if(moreValues[k].equals("1") && k != moreValues.length-1){
                value++;
              }
              else if(moreValues[k].equals("1")){
                value+=2;
              }
            }
          }
          String[] arr = new String[2];
          arr[0]=name;
          arr[1]=""+value;
          arrList.add(arr);
        }
        Comparador c = new Comparador();
        arrList.sort(c);
        System.out.println("Case "+i+":");
        for(String[] arreglo: arrList){
          System.out.println(arreglo[0]+" "+arreglo[1]);
        }
        i++;
        line = br.readLine();
      }
    }
    catch(Exception e){
      e.printStackTrace();
    }
  }
}
