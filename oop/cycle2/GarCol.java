public class GarCol{
	public void finalize(){
		System.out.println("garbage collected");
	}
	public static void main(String[] args) {
		GarCol a = new GarCol();
		GarCol b = new GarCol(); 
		a = null;
		b = null;
		System.gc();
	}
}