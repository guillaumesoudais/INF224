package swing;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;

import javax.swing.*;


public class Fenetre extends JFrame {
	private static final long serialVersionUID = 1L;

  public static void main(String[] args){

    JFrame fenetre = new JFrame();

    //Définit un titre pour notre fenêtre
    fenetre.setTitle("Set top Box");
    //Définit sa taille : 400 pixels de large et 100 pixels de haut
    fenetre.setSize(800, 600);
    //Nous demandons maintenant à notre objet de se positionner au centre
    fenetre.setLocationRelativeTo(null);
    //Termine le processus lorsqu'on clique sur la croix rouge
    fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    Client client = Client.init_client();

    fenetre.setLayout(new BorderLayout());
    JPanel container = new JPanel();
    container.setLayout(new BorderLayout());
    JPanel b_cont = new JPanel();
    b_cont.setLayout(new FlowLayout(FlowLayout.CENTER));

    JTextArea ta = new JTextArea("Historique:\n");
    ta.setEditable(false);
    JScrollPane sp = new JScrollPane(ta);
    sp.setPreferredSize(new Dimension(500,300));

    JButton b_exit = new JButton(new Exit_button("quitter", client));
    JButton b_jouer = new JButton(new Play_buton("jouer", client));
    JButton b_info = new JButton(new Info_buton("informations", client,ta));

    JButton t_exit = new JButton(new Exit_button("quitter", client));
    JButton t_jouer = new JButton(new Play_buton("jouer", client));
    JButton t_info = new JButton(new Info_buton("informations", client,ta));


    b_cont.add(b_jouer);
    b_cont.add(b_info);
    b_cont.add(b_exit);

    JMenuBar menuBar = new JMenuBar();
    JMenu act = new JMenu("actions");
    JMenuItem m_play = new JMenuItem(new Play_buton("jouer", client));
    JMenuItem m_info = new JMenuItem(new Info_buton("informations", client,ta));
    JMenuItem m_quit = new JMenuItem(new Exit_button("quitter", client));

    act.add(m_play);
    act.add(m_info);
    act.add(m_quit);
    menuBar.add(act);

    JToolBar toolbar = new JToolBar();
    toolbar.add(t_jouer);
    toolbar.add(t_info);
    toolbar.add(t_exit);



    container.add(sp);

    // selectionneur de media
    JPanel r_cont = new JPanel();

    ButtonGroup group = new ButtonGroup();
    String tmp = client.send("size");
    int nb_media = 8;
    if(tmp.length()>1)
    nb_media = Integer.parseInt(tmp);
    r_cont.setLayout(new GridLayout(nb_media,1));
    tmp = client.send("list");
    System.err.println(tmp);
    String names[] = {"Chat_mignon","boulangerie","hockey","rino","yamakasi","giraffe","fuji","chat"};
    JRadioButton r_tab[] = new JRadioButton[nb_media];
    for (int i = 0; i <nb_media; i++) {
    	r_tab[i] = new JRadioButton(new Select(names[i]));
    }

    for (int i = 0; i <nb_media; i++) {
    	group.add(r_tab[i]);
    	r_cont.add(r_tab[i]);
    }



    fenetre.setJMenuBar(menuBar);
    fenetre.add(toolbar, BorderLayout.NORTH);
    fenetre.add(container, BorderLayout.CENTER);
    fenetre.add(r_cont, BorderLayout.EAST);
    fenetre.add(b_cont, BorderLayout.SOUTH);
    //Et enfin, la rendre visible


    fenetre.setVisible(true);
  }
}
