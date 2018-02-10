package swing;
import java.util.concurrent.TimeUnit;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;

import javax.swing.*;
import javax.swing.text.DefaultCaret;


public class Fenetre extends JFrame {
	private static final long serialVersionUID = 1L;
/* execution du programme*/
  public static void main(String[] args){

		//instanciation du client
    Client client = Client.init_client();

		//création de la fenetre principale
    JFrame fenetre = new JFrame();
    //Définit un titre pour notre fenêtre
    fenetre.setTitle("Set top Box");
    //Définit sa taille : 400 pixels de large et 100 pixels de haut
    fenetre.setSize(800, 600);
    //Nous demandons maintenant à notre objet de se positionner au centre
    fenetre.setLocationRelativeTo(null);
    //Termine le processus lorsqu'on clique sur la croix rouge
    fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//organisation de la fenetre
    fenetre.setLayout(new BorderLayout());

		// initialisation de la zone de texte
		JPanel container = new JPanel(); //contient le texte
    container.setLayout(new BorderLayout());
    JTextArea ta = new JTextArea("Historique:\n");
    JScrollPane sp = new JScrollPane(ta);
    ta.setEditable(false);
    sp.setPreferredSize(new Dimension(500,300));
		container.add(sp);

		//initialisation des boutons
		JPanel b_cont = new JPanel(); //contient les boutons en bas de la fenetre
    b_cont.setLayout(new FlowLayout(FlowLayout.CENTER));
    JButton b_exit = new JButton(new Exit_button("quitter", client));
    JButton b_jouer = new JButton(new Play_buton("jouer", client));
    JButton b_info = new JButton(new Info_buton("informations", client,ta));
    b_cont.add(b_jouer);
    b_cont.add(b_info);
    b_cont.add(b_exit);

		//initialisation du menu déroulant
    JMenuBar menuBar = new JMenuBar();
    JMenu act = new JMenu("actions");
    JMenuItem m_play = new JMenuItem(new Play_buton("jouer", client));
    JMenuItem m_info = new JMenuItem(new Info_buton("informations", client,ta));
    JMenuItem m_quit = new JMenuItem(new Exit_button("quitter", client));
    act.add(m_play);
    act.add(m_info);
    act.add(m_quit);
    menuBar.add(act);

		//initialisation de la barre d'outils
    JButton t_exit = new JButton(new Exit_button("quitter", client));
    JButton t_jouer = new JButton(new Play_buton("jouer", client));
    JButton t_info = new JButton(new Info_buton("informations", client,ta));
    JToolBar toolbar = new JToolBar();
    toolbar.add(t_jouer);
    toolbar.add(t_info);
    toolbar.add(t_exit);

    //initialisation des radios boutons pour choisir le média
    JPanel r_cont = new JPanel();
    JScrollPane scroll = new JScrollPane();
    ButtonGroup group = new ButtonGroup();
		/*méthode ne fonctionnant pas encore : devrait récuperer le nombre de média,
		pour l'instant les valeurs sont hardcodé...*/
    String tmp = client.send("size ");
		//permet de vérifier si on reçoit un message
    System.out.println("nombre de media ->"+tmp + "<-");
	    int nb_media = 8; //hardcode....
	    if(tmp.length()>1) nb_media = Integer.parseInt(tmp);
		//arrangement des boutons à la verticale
    r_cont.setLayout(new GridLayout(nb_media,1));
		//recupérer la liste des média, ne fonctionne pas non plus...........
    tmp = client.send("list");
    System.out.println("liste des media ->"+tmp + "<-");
    String names[] = {"Chat_mignon","boulangerie","hockey","rino","yamakasi","giraffe","fuji","chat"}; //hardcode .............................
    JRadioButton r_tab[] = new JRadioButton[nb_media];
    for (int i = 0; i <nb_media; i++) {
    	r_tab[i] = new JRadioButton(new Select(names[i]));
    }

    for (int i = 0; i <nb_media; i++) {
    	group.add(r_tab[i]);
    	r_cont.add(r_tab[i]);
    }
    scroll.setViewportView(r_cont);

		//ajout des composant à la fenêtre
    fenetre.setJMenuBar(menuBar);
    fenetre.add(toolbar, BorderLayout.NORTH);
    fenetre.add(container, BorderLayout.CENTER);
    fenetre.add(scroll	, BorderLayout.EAST);
    fenetre.add(b_cont, BorderLayout.SOUTH);
    //affichage de la fenetre
    fenetre.setVisible(true);


  }
}
