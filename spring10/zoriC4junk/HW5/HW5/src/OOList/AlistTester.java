package OOList;

import junit.framework.TestCase;

public class AlistTester extends TestCase {
	
	public void testFilter() {
		
		int i = 0;
		
		Alist l = EmptyList.Singleton;

		while (i < 10) {

			l = new NEList(new Integer(i), l);

			++i;

		}
		
		assertEquals("Filter, n = 5 (return smaller than 5)", "(0, 1, 2, 3, 4)", ((Alist) l.invite(Filter.Singleton, new FilterObject(5, EmptyList.Singleton))).invite(ToString.Singleton, null));
		
	}
}
