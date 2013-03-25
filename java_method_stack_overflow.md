java 方法栈溢出
===============

## Source

    public class Main {
    
      public static void main(String[] args) throws Throwable {
    		
    		try {
    			new Main().testMethodCallStackOverflow();
    		} catch (Throwable e) {
    			System.out.println(stackDeepth);
    			throw e;
    		}
    		
    	}
    	
    	public void testMethodCallStackOverflow() {
    		++stackDeepth;
    		testMethodCallStackOverflow();
    	}
    
    	private static int stackDeepth = 0;
    }

## Output

    16268
    Exception in thread "main" java.lang.StackOverflowError
      at Main.testMethodCallStackOverflow(Main.java:17)
    	at Main.testMethodCallStackOverflow(Main.java:17)
    	at Main.testMethodCallStackOverflow(Main.java:17)
    	at Main.testMethodCallStackOverflow(Main.java:17)
    	at Main.testMethodCallStackOverflow(Main.java:17)
    	at Main.testMethodCallStackOverflow(Main.java:17)
    	at Main.testMethodCallStackOverflow(Main.java:17)
    	at Main.testMethodCallStackOverflow(Main.java:17)
    	at Main.testMethodCallStackOverflow(Main.java:17)
    	at Main.testMethodCallStackOverflow(Main.java:17)
    	at Main.testMethodCallStackOverflow(Main.java:17)
    	at Main.testMethodCallStackOverflow(Main.java:17)
    	at Main.testMethodCallStackOverflow(Main.java:17)
    	at Main.testMethodCallStackOverflow(Main.java:17)
      ...    
