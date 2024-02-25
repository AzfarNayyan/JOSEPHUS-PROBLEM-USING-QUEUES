//DS ASSIGNMENT NUMBER 03
//AZFAR NAYYAN
//22L-7886 BSE-3C

//QUEUES

//JOSEPHUS PROBLEM.

#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Graphics/Color.hpp>
#include<string>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;


template<class T>
class Queue
{
	struct Node
	{
		T data;
		Node* next;
	public:
		Node()
		{
			next = NULL;
		}
		Node(T const e)
		{
			next = NULL;
			data = e;
		}
	};

	Node* Front;
	Node* Rear;
	int s;

public:
	Queue()
	{
		Front = NULL;
		Rear = NULL;
		s = 0;
	}
	Queue(T const e)
	{
		Front = new Node(e);
		s = 1;
		Rear = Front;
	}
	bool IsEmpty()
	{
		if (s == 0) return true;
		else return false;
	}
	int getSize()
	{
		return s;
	}
	void enqueue(T const e)
	{
		if (IsEmpty() == true)
		{
			Front = new Node(e);
			s = 1;
			Rear = Front;
			return;
		}

		Node* temp = new Node(e);
		Rear->next = temp;
		Rear = Rear->next;
		s++;
	}
	void dequeue()
	{
		if (IsEmpty() == true)
		{
			cout << "EMPTY QUEUE !! NOTING TO DEQUEUE!!" << endl;
			return;
		}

		Node* temp = Front;
		Front = Front->next;
		s--;
		delete temp;
	}
	void Top(T& e)
	{
		if (IsEmpty() == true)
		{
			cout << "EMPTY QUEUE !!" << endl;
			return;
		}

		e = Front->data;
	}
	void printQueue()
	{
		cout << "THE QUEUE IS: ";
		if (IsEmpty() == true) {
			cout << "Empty Queue :) (merizindagikitarah). " << endl;
			return;
		}

		Node* current = Front;
		int i = 0;
		while (i < s) {
			cout << current->data;
			if (i != s - 1)cout << "-";
			current = current->next;
			i++;
		}
		cout << " :)" << endl;
	}
};

void getInput(int& n, int& k, RenderWindow& window)
{

	Font font;
	if (!font.loadFromFile("Dosis.ttf")) {
		cout << "Failed to load font" << endl;
		return;
	}

	RectangleShape bar(Vector2f(1000, 60));
	bar.setPosition(0, 5);
	Color mahoganyColor(135, 169, 107);   //135, 169, 107  //192, 64, 0
	bar.setFillColor(mahoganyColor);

	RectangleShape area(Vector2f(1000, 540));
	area.setPosition(0, 70);
	Color c(255, 253, 230, 130);
	area.setFillColor(c);

	Text t("JOSEPHUS  PROBLEM.", font, 40);
	t.setPosition(250, 10);
	t.setFillColor(Color::Black);

	Text N("N: ", font, 38);
	N.setFillColor(Color::Black);
	N.setPosition(150, 250);
	RectangleShape NBOX(Vector2f(180, 40));
	NBOX.setFillColor(Color::White);
	NBOX.setOutlineColor(Color::Black);
	NBOX.setOutlineThickness(4);
	NBOX.setPosition(200, 254);

	Text K("K: ", font, 38);
	K.setFillColor(Color::Black);
	K.setPosition(600, 250);
	RectangleShape KBOX(Vector2f(180, 40));
	KBOX.setFillColor(Color::White);
	KBOX.setOutlineColor(Color::Black);
	KBOX.setOutlineThickness(4);
	KBOX.setPosition(654, 254);

	Text E("ENTER", font, 28);
	E.setFillColor(Color::Black);
	E.setPosition(784, 505);
	RectangleShape EBOX(Vector2f(180, 40));
	EBOX.setFillColor(mahoganyColor);
	EBOX.setOutlineColor(Color::Black);
	EBOX.setOutlineThickness(4);
	EBOX.setPosition(754, 504);

	string NTextString = "";
	Text NText("", font, 20);
	NText.setFillColor(Color::Black);
	NText.setPosition(N.getPosition().x + 55.f, N.getPosition().y +10.f);
	bool NT = false;

	string KTextString = "";
	Text KText("", font, 20);
	KText.setFillColor(Color::Black);
	KText.setPosition(K.getPosition().x + 58.f, K.getPosition().y + 10.f);
	bool KT = false;


	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					Vector2f mousePos = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
					if (NBOX.getGlobalBounds().contains(mousePos))
					{
						NT = true;
						KT = false;
					}
					if (KBOX.getGlobalBounds().contains(mousePos))
					{
						NT = false;
						KT = true;
					}
					if (EBOX.getGlobalBounds().contains(mousePos))
					{
						int temp_n = stoi(NTextString);
						int temp_k = stoi(KTextString);

						if (temp_n <= 0) continue;
						if (temp_k < 0) continue;
						if (temp_k >= temp_n) continue;

						n = temp_n;
						k = temp_k;
						return;
					}
				}
			}

			if (NT == true && event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (NTextString.size() > 0)
					{
						NTextString.erase(NTextString.size() - 1, 1);
						NText.setString(NTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					NText.setString(NTextString);
				}
				else if (event.text.unicode < 128)
				{
					NTextString += static_cast<char>(event.text.unicode);
					NText.setString(NTextString);
				}
			}
			if (KT == true && event.type == Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (KTextString.size() > 0)
					{
						KTextString.erase(KTextString.size() - 1, 1);
						KText.setString(KTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					KText.setString(KTextString);
				}
				else if (event.text.unicode < 128)
				{
					KTextString += static_cast<char>(event.text.unicode);
					KText.setString(KTextString);
				}
			}
		}



		Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		if (EBOX.getGlobalBounds().contains(mousePos)) {
			EBOX.setOutlineColor(Color::Red);
			E.setFillColor(Color::Red);
		}
		else {
			EBOX.setOutlineColor(Color::Black);
			E.setFillColor(Color::Black);
		}


		window.clear();
		window.draw(bar);
		window.draw(area);
		window.draw(t);
		window.draw(N);
		window.draw(NBOX);
		window.draw(K);
		window.draw(KBOX);
		window.draw(EBOX);
		window.draw(E);
		window.draw(NText);
		window.draw(KText);
		window.display();
	}

}

void SolveJosephusProblem(int N, int K)
{
	Queue<int> myQueue;

	for (int i = 1; i <= N; i++)
	{
		myQueue.enqueue(i);
	}

	int top = 0;

	cout << "THE ELEMINATION SEQUENCE IS: " << endl;
	while (!myQueue.IsEmpty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			int data;
			myQueue.Top(data);
			myQueue.dequeue();
			myQueue.enqueue(data);
		}

		myQueue.Top(top);
		myQueue.dequeue();
		cout << top << " ";
	}
	cout << endl;
	cout << top << " th is the SURVIVOUR." << endl;
}

void JosephusUI(int n, int k, RenderWindow& window)
{
	CircleShape circle(450 / 2);
	circle.setFillColor(Color::Transparent);
	circle.setOutlineColor(Color::Black);
	circle.setOutlineThickness(2);
	circle.setPosition(70, 115);

	RectangleShape  bar(Vector2f(1000, 55));
	Color c(135, 169, 107);
	bar.setFillColor(c);
	bar.setPosition(0, 5);

	RectangleShape  area(Vector2f(1000, 540));
	Color c1(255, 253, 230, 130);
	area.setFillColor(c1);
	area.setPosition(0, 65);

	Font font;
	if (!font.loadFromFile("Dosis.ttf")) {
		cout << "Failed to load font" << endl;
		return;
	}

	Text t("JOSEPHUS  PROBLEM.", font, 40);
	t.setPosition(250, 10);
	t.setFillColor(Color::Black);

	String temp = to_string(n);
	String temp1 = to_string(k);

	Text K("K: " + temp1, font, 32);
	K.setFillColor(Color::Black);
	K.setPosition(780, 500);

	Text N("N: " + temp, font, 32);
	N.setFillColor(Color::Black);
	N.setPosition(780, 450);

	float angleStep = 360.0f / n;

	CircleShape* people = new CircleShape[n];
	Text* numbers = new Text[n];
	for (int i = 0; i < n; i++)
	{
		float angle = i * angleStep;
		float x = 450 / 2 + (450 / 2 - 20) * cos(angle * 3.14159265 / 180);
		float y = 450 / 2 + (450 / 2 - 20) * sin(angle * 3.14159265 / 180);

		float x1 = 520 / 2 + (520 / 2 - 20) * cos(angle * 3.14159265 / 180);
		float y1 = 520 / 2 + (520 / 2 - 20) * sin(angle * 3.14159265 / 180);

		people[i].setRadius(6);
		people[i].setFillColor(Color::Green);
		people[i].setPosition(x + 65, y + 110);

		String t = to_string(i + 1);

		numbers[i].setString(t);
		numbers[i].setFont(font);
		numbers[i].setFillColor(Color::Black);
		numbers[i].setCharacterSize(15);
		numbers[i].setPosition(x1 + 30, y1 + 70);
	}

	Queue<int> myQueue;

	for (int i = 1; i <= n; i++)
	{
		myQueue.enqueue(i);
	}

	int top = 0;

	while (window.isOpen())
	{
		
		if (myQueue.IsEmpty() == false) 
		{
			for (int i = 0; i < k - 1; i++)
			{
				int data;
				myQueue.Top(data);
				myQueue.dequeue();
				myQueue.enqueue(data);
			}

			myQueue.Top(top);
			myQueue.dequeue();

			if (myQueue.IsEmpty() == false) people[top - 1].setFillColor(Color::Red);
			sleep(seconds(1));
		}
		
		
		window.clear();
		window.draw(bar);
		window.draw(area);
		window.draw(t);
		window.draw(circle);
		window.draw(K);
		window.draw(N);
		for (int i = 0; i < n; i++) {
			window.draw(people[i]);
			window.draw(numbers[i]);
		}
		window.display(); 
	}
}

int main()
{
	RenderWindow window(VideoMode(1000, 600), "Josephus Problem ! ");

	int n = 0;
	int k = 0;

	getInput(n, k, window);

	SolveJosephusProblem(n, k);

	JosephusUI(n, k, window);

	//JOSEPHUS PROB

	system("pause>0");
	return 0;
}