class Hello extends Thread{
	public void run(){
		stop();
		System.out.println("hello");
	}
	public static void main(String[] args) {
	System.out.println("NAME-> JATIN GOYAL");
	System.out.println("ROLL NO -> 43113302718");
	Hello hello = new Hello();
	hello.start();
	//hello.stop(); // Display the string.
	}
}