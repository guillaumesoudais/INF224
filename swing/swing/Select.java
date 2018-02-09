package swing;

import java.awt.event.ActionEvent;
import javax.swing.AbstractAction;

public class Select extends AbstractAction {
	private static final long serialVersionUID = 1L;
	private String name;
	public static String selected;
	
	public Select(String texte){
		super(texte);
		name = texte;
		
	}
	
	public String getName() {
		return name;
	}
	
	public void actionPerformed(ActionEvent e) {
		 selected = name;
		 } 
}
