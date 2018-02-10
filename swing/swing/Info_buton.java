
package swing;

import javax.swing.*;
import java.awt.event.*;
import javax.swing.text.DefaultCaret;

//recupere les informations sur les média
public class Info_buton extends AbstractAction {
	private static Client cl;
	private JTextArea ta;
	private final long serialVersionUID = 1L;
	public Info_buton(String texte, Client c, JTextArea t){
		super(texte);
		cl =c;
		ta = t;
	}
	/* recupère les informations sur le média sélectionné, les affiche et descend
	le scroll pane.*/ 
	public void actionPerformed(ActionEvent e) {
		String s = cl.send("look "+Select.selected);
		s = s.replaceAll("@", "\n");
		ta.append(s+"\n");
		ta.setCaretPosition(ta.getDocument().getLength());
		}
}
