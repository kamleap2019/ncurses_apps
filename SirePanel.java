import java.awt.*;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class SirePanel extends JPanel {

    final static int PADDING = 20;
    final static int MIN_SIZE = 2;

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D)g;
        int x = PADDING;
        int y = this.getHeight() - PADDING;
        int l = this.getWidth() - PADDING*2;
        drawSirepinski(g2, x, y, l);
    }

    int i=0;
    public void drawSirepinski(Graphics2D g, int x, int y, int l) {
        if ( l <= MIN_SIZE ) {
            return;
        }
        else {
            drawTriangle(g, x, y, l);
            drawSirepinski(g, x, y, l/2);
            drawSirepinski(g, x+l/2, y, l/2);
            drawSirepinski(g, x+l/4, y-getTriangleHeight(l/2), l/2);
        }
    }

    private void drawTriangle(Graphics2D g, int x, int y, int l) {
        int h = getTriangleHeight(l);
        g.drawLine(x, y, x+l, y);
        g.drawLine(x, y, x+l/2, y-h);
        g.drawLine(x+l, y, x+l/2, y-h);
    }

    private int getTriangleHeight(int l) {
        return (int)(Math.sqrt(3)*l/2);

    }

    // private double getLineLength(int x1, int y1, int x2, int y2) {
    //     return Math.sqrt( (x2 -x1)*(x2-x1) + (y2-y1)*(y2-y1) );
    // }

    public static void main(String[] args) {
        System.out.println("Bismillah");

        JFrame f = new JFrame();
        SirePanel sp = new SirePanel();
        f.add(sp);
        f.setSize(800, 800);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}