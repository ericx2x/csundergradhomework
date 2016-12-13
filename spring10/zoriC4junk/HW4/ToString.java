/**
 * ToString visitor operation class.
 * 
 * @author Zori Babroudi
 * 
 */
public class ToString implements IListVisitor {

	/**
	 * Singleton constructor for the ToString class.
	 */
	public static final ToString Singleton = new ToString();

	private ToString() {
	}

	/**
	 * @return Empty String of objects.
	 */
	public Object visitEmptyList(EmptyList host, Object input) {
		return new String("(" + host.invite(new ToStringHelper(), null));
	}

	/**
	 * @return String of the objects in the list.
	 */
	public Object visitNEList(NEList host, Object input) {

		return new String("(" + host.invite(new ToStringHelper(), null));
	}

}

/**
 * ToString Helper Class
 * 
 * @author Zori Babroudi
 * 
 */
class ToStringHelper implements IListVisitor {

	public Object visitEmptyList(EmptyList host, Object input) {
		return new String(")");
	}

	public Object visitNEList(NEList host, Object input) {

		Object first = host.getFirst();
		AList rest = host.getRest();

		String temp = "";

		if ((Integer) host.invite(Length.Singleton, null) > 1)
			temp = ", ";

		return new String(first + temp + rest.invite(this, null));
	}

}
