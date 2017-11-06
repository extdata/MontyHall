#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;

void colocar_premio( int & );
void escolher_porta( int & );
int verificar_acerto( int, int );

int main()

{
	cout << "Algoritmo de Monty Hall!\n\n";
	cout << "Executar um loop para verificar e mostrar as chances de acerto do premio!\n\n";
	
	srand( ( int ) time( 0 ) );
	int putprize, choosedoor;
	double percentualdeacerto;
	const int NITER = 1000;
	int a;
		
	for ( int i = 1; i < NITER; i++ )
	{
		colocar_premio( putprize );
		
		//cout << "O premio esta em: " << putprize << '\n';
		
		escolher_porta( choosedoor );
		
		//cout << "A porta escolhida eh: " << choosedoor << '\n';
		
		verificar_acerto( putprize, choosedoor );
		
		// cin >> a;
		
	}
	
	percentualdeacerto = double( verificar_acerto( putprize, choosedoor ))/double(NITER + 1);
	
	cout << "Porcentagem de acerto: " << percentualdeacerto;
	
}


void colocar_premio( int & putprize)
{
	
	putprize = rand() % 3 + 1;
	
}

void escolher_porta( int & choosedoor)
{
	
	choosedoor = rand() % 3 + 1;
	
}

int verificar_acerto( int putprize, int choosedoor )
{
	static int verifyscore = 0;
	
	if (putprize != choosedoor)
		verifyscore++;
		
	return verifyscore;	
}