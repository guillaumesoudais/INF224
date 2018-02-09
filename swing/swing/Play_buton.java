package swing;

import javax.swing.*;
import java.awt.event.*; 

public class Play_buton extends AbstractAction {
	private Client cl;
	private static final long serialVersionUID = 1L;
	public Play_buton(String texte, Client c){
		super(texte);
		cl = c;
	}
	 
	public void actionPerformed(ActionEvent e) {
		cl.send("play "+Select.selected);
		 }  
}