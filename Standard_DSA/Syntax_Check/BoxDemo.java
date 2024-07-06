class Box {
    double width;
    double height;
    double depth;

    // display volume of a box

    void volume() {

        System.out.print("Volume is ");
        System.out.println(width * height * depth);

  }


}

class BoxDemo {

 public static void main(String args[])
{

    Box mybox1 = new Box();
    Box mybox2 = new Box();


    // assign values to mybox's instance variables

    mybox1.width = 10;
    mybox1.height = 20;
    mybox1.depth = 15;

    mybox2.width = 12;
    mybox2.height = 6;
    mybox2.depth = 7;


  mybox1.volume();
  mybox2.volume();



}


}