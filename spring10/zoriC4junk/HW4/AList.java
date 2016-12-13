/**
 * Abstract List Class Using the Visitor Pattern.
 * @author Zori Babroudi
 *
 */
public abstract class AList {

	  /**
     * Returns first object in the list.
     * @return the first object.
     */
	public abstract Object getFirst();

	/**
     * Gets everything after the first object of the list.
     * @return the "rest" of the list.
     */
	public abstract AList getRest();

	/**
     * The visitor file that contains the information for visitor classes.
     * @return the operation classes.
     */
	public abstract Object invite(IListVisitor v, Object input);

}
