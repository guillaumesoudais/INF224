
package swing;

import javax.swing.*;
import java.awt.event.*; 

public class Info_buton extends AbstractAction {
	private Client cl;
	private JTextArea ta;
	private static final long serialVersionUID = 1L;
	public Info_buton(String texte, Client c, JTextArea t){
		super(texte);
		cl =c;
		ta = t;
	}
	 
	public void actionPerformed(ActionEvent e) {
		String s = cl.send("look "+Select.selected);
		s = s.replaceAll("@", "\n");
		ta.append(s+"\n");
		 }  
}