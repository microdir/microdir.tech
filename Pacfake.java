import java.util.Scanner;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.ObjectInputStream;

public class Pacfake {

	//ATRIBUIÇÃO DE UM ARQUIVO TXT Á UMA VARIÁVEL FILE
	//private static File arquivo = new File("mapa.txt");
	private static File arquivo = new File("mapa2.txt");

	public static class Mapa {
		//ATRIBUI O RETURN DA FUNÇÃO QUE LÊ O ARQUIVO DE MAPA
		char[][] matriz = lerMapa();
		
		int linha;
		int coluna;
	}

	//NOVA FUNÇÃO PARA LEITURA DO TXT QUE CONTÉM O MAPA
	public static char[][] lerMapa(){
		try { 
		
			ObjectInputStream saida = new ObjectInputStream(new FileInputStream(arquivo));
			return (char[][]) saida.readObject();
		 
		} catch (FileNotFoundException e) { 
			// Não faz nada 
			return null;
		} catch (Exception e) { 
			return null;
		} 
	}

	public static void main(String[] args){
		moveHeroi();
	}

	static Mapa mapa = new Mapa();
	static int pilula = 0;

	public static void exibirMapa(){
		for(int i = 0; i < mapa.matriz.length; i++){
			for(int j = 0; j < mapa.matriz[0].length; j++){
				System.out.print(mapa.matriz[i][j]);
			}
			System.out.println("");
		}
	}

	public static void encontrarPosicao(){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 10; j++){
				if(mapa.matriz[i][j] == '@'){
					mapa.linha = i;
					mapa.coluna = j;
				}
			}
		}	
	}

	public static boolean ehParede(char c){
		if(c == '|' || c == '-'){
			return true;
		} else {
			return false;
		}
	}

	public static boolean ehPilula(char c){
		if(c == 'P'){
			return true;
		} else {
			return false;
		}
	}

	public static void limpaTela(){
		for(int i = 0; i < 20; i++){
			System.out.println("");
		}
	}

	public static void explodePilula(int l, int c, int qtd){
		if(qtd == 0){
			return;
		} else if(ehParede(mapa.matriz[l][c+1])){
			return;
		} else {
			mapa.matriz[l][c+1] = '.';
			explodePilula(l, c+1, qtd-1);
		}
	}

	public static void moveHeroi(){
		Scanner leitor = new Scanner(System.in);

		while (true) {
			exibirMapa();
			encontrarPosicao();
			System.out.print("Pílulas: "+pilula+"\n");
			System.out.print("Mova o herói\n"
				+ "w: cima\n"
				+ "s: baixo\n"
				+ "a: esquerda\n"
				+ "d: direita\n"
				+ "q: sair\n");

			char opcao = leitor.nextLine().charAt(0);

			if(opcao == 'w'){
				if(ehPilula(mapa.matriz[mapa.linha - 1][mapa.coluna])){
					pilula++;
				}
				if(!ehParede(mapa.matriz[mapa.linha - 1][mapa.coluna])){
					mapa.matriz[mapa.linha][mapa.coluna] = '.';
					mapa.matriz[mapa.linha - 1][mapa.coluna] = '@';
				}

			} else if(opcao == 's'){
				if(ehPilula(mapa.matriz[mapa.linha + 1][mapa.coluna])){
					pilula++;
				}
				if(!ehParede(mapa.matriz[mapa.linha + 1][mapa.coluna])){
					mapa.matriz[mapa.linha][mapa.coluna] = '.';
					mapa.matriz[mapa.linha + 1][mapa.coluna] = '@';
				}

			} else if(opcao == 'a'){
				if(ehPilula(mapa.matriz[mapa.linha][mapa.coluna - 1])){
					pilula++;
				}

				if(!ehParede(mapa.matriz[mapa.linha][mapa.coluna - 1])){
					mapa.matriz[mapa.linha][mapa.coluna] = '.';
					mapa.matriz[mapa.linha][mapa.coluna - 1] = '@';
				}

			} else if(opcao == 'd'){
				if(ehPilula(mapa.matriz[mapa.linha][mapa.coluna + 1])){
					pilula++;
				}
				if(!ehParede(mapa.matriz[mapa.linha][mapa.coluna + 1])){
					mapa.matriz[mapa.linha][mapa.coluna] = '.';
					mapa.matriz[mapa.linha][mapa.coluna + 1] = '@';
				}

			} else if(opcao == 'b'){
				if(pilula != 0){
					explodePilula(mapa.linha, mapa.coluna, 3);
					pilula--;
				}

			} else if(opcao == 'q'){
				break;
			}
			limpaTela();
		}
	}
}
