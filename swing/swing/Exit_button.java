package swing;

import javax.swing.*;
import java.awt.event.*; 

public class Exit_button extends AbstractAction {
	private Client cl;
	private static final long serialVersionUID = 1L;
	public Exit_button(String texte, Client c){
		super(texte);
		cl = c;
	}
	 
	public void actionPerformed(ActionEvent e) {
		cl.send("quit");
		 System.exit(0);
		 } 
}
