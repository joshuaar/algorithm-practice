class strings {
  public static void main(String[] args){
    String s = "Hello 1 2 3 4 18 23";
    System.out.println(s.charAt(5));
    s = s.replaceAll(" ","%20");
    System.out.println(s);
  }

}
