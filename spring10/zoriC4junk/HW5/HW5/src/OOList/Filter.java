package OOList;
/**
 * Filter visitor operation class.
 * 
 * @author Zori Babroudi
 * 
 */
public class Filter implements IListVisitor {

	/**
	 * Singleton constructor for the Filter class.
	 */
	public static final Filter Singleton = new Filter();

	private Filter() {
	}

	/**
	 * @return Throw Exception.
	 */
	public Object visitEmptyList(EmptyList host, Object input) {
		throw new IllegalArgumentException ("List has no data!");
	}

	/**
	 * @return Return a new List of all the numbers less than n.
	 */
	public Object visitNEList(NEList host, Object input) {

		return host.invite(new FilterHelper(), input);
	}

}

/**
 * Filter Helper Class
 * 
 * @author Zori Babroudi
 * 
 */
class FilterHelper implements IListVisitor {

	public Object visitEmptyList(EmptyList host, Object input) {
		FilterObject n = (FilterObject) input;
		return (Alist) n.L;
	}

	public Object visitNEList(NEList host, Object input) {

		FilterObject n = (FilterObject) input;
		
		if ((Integer)host.getFirst() < n.n)
			n.L = new NEList ((Integer) host.getFirst(), n.L);
		
		return host.getRest().invite(this, n);
		
	}

}

